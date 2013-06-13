/*
** parse_conf.c for  in /home/lund/Projets/zappy-poney/serveur
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Mon Jun 10 21:53:42 2013 florian dewulf
** Last update Thu Jun 13 16:00:35 2013 florian dewulf
*/

#include		<stdio.h>
#include		<string.h>
#include		<unistd.h>
#include		"serveur.h"

static void		defaultconfig(t_conf *config)
{
  config->time_repop[NOURRITURE] = 6;
  config->time_repop[LINEMATE] = 7;
  config->time_repop[DERAUMERE] = 7;
  config->time_repop[SIBUR] = 8;
  config->time_repop[MENDIANE] = 8;
  config->time_repop[PHIRAS] = 9;
  config->time_repop[THYSTAME] = 9;
  config->max_repop[NOURRITURE] = 12;
  config->max_repop[LINEMATE] = 12;
  config->max_repop[DERAUMERE] = 10;
  config->max_repop[SIBUR] = 8;
  config->max_repop[MENDIANE] = 6;
  config->max_repop[PHIRAS] = 4;
  config->max_repop[THYSTAME] = 2;
}

static t_ptr_func_parse	*init_ptr_func_pop()
{
  t_ptr_func_parse	*ptr;

  ptr = xmalloc(SIZE_PTR_FUNC * sizeof(t_ptr_func_parse));
  ptr[0].str = strdup("PopNourriture:");
  ptr[0].off = NOURRITURE;
  ptr[1].str = strdup("PopLinemate:");
  ptr[1].off = LINEMATE;
  ptr[2].str = strdup("PopDeraumere:");
  ptr[2].off = DERAUMERE;
  ptr[3].str = strdup("PopSibur:");
  ptr[3].off = SIBUR;
  ptr[4].str = strdup("PopMendiane:");
  ptr[4].off = MENDIANE;
  ptr[5].str = strdup("PopPhiras:");
  ptr[5].off = PHIRAS;
  ptr[6].str = strdup("PopThystame:");
  ptr[6].off = THYSTAME;
  return (ptr);
}

static void		init_ptr_func_max(t_ptr_func_parse *ptr)
{
  ptr[7].str = strdup("MaxNourriture:");
  ptr[7].off = NOURRITURE;
  ptr[8].str = strdup("MaxLinemate:");
  ptr[8].off = LINEMATE;
  ptr[9].str = strdup("MaxDeraumere:");
  ptr[9].off = DERAUMERE;
  ptr[10].str = strdup("MaxSibur:");
  ptr[10].off = SIBUR;
  ptr[11].str = strdup("MaxMendiane:");
  ptr[11].off = MENDIANE;
  ptr[12].str = strdup("MaxPhiras:");
  ptr[12].off = PHIRAS;
  ptr[13].str = strdup("MaxThystame:");
  ptr[13].off = THYSTAME;
}

static void		fileconfig(t_conf *config, FILE *file)
{
  char			buff[1024];
  t_ptr_func_parse	*ptr;
  int			i;

  ptr = init_ptr_func_pop();
  init_ptr_func_max(ptr);
  while (fgets(buff, 1023, file) != NULL)
    {
      i = 0;
      while (i < 14 && strncmp(ptr[i].str, buff, strlen(ptr[i].str)) != 0)
	i++;
      if (i != 14 && strncmp(buff, "Max", 3) == 0)
	config->max_repop[ptr[i].off] = atoi(&(buff[strlen(ptr[i].str)]));
      else if (i != 14)
	config->time_repop[ptr[i].off] = atoi(&(buff[strlen(ptr[i].str)]));
    }
  i = 0;
  while (i < 14)
    {
      free(ptr[i].str);
      i++;
    }
  free(ptr);
}

t_conf			*parseconf(t_map **map)
{
  FILE			*file;
  t_conf		*config;

  config = xmalloc(sizeof(t_conf));
  defaultconfig(config);
  if (access(".conf", R_OK | F_OK) != -1)
    {
      file = fopen(".conf", "r");
      if (file != NULL)
	{
	  fileconfig(config, file);
	  fclose(file);
	}
    }
  init_map(map, config);
  return config;
}

/*
int	main()
{
  t_conf	*conf;
  t_map		**map;

  map = NULL;
  conf = parseconf(map);
  printf("Pop Nourriture : %d\nPop Linemate : %d\nPop Deraumere : %d\nPop Sibur : %d\nPop Mendiane : %d\nPop Phiras : %d\nPop Thystame : %d\n", conf->time_repop[NOURRITURE], conf->time_repop[LINEMATE], conf->time_repop[DERAUMERE], conf->time_repop[SIBUR], conf->time_repop[MENDIANE], conf->time_repop[PHIRAS], conf->time_repop[THYSTAME]);
  printf("Max Nourriture : %d\nMax Linemate : %d\nMax Deraumere : %d\nMax Sibur : %d\nMax Mendiane : %d\nMax Phiras : %d\nMax Thystame : %d\n", conf->max_repop[NOURRITURE], conf->max_repop[LINEMATE], conf->max_repop[DERAUMERE], conf->max_repop[SIBUR], conf->max_repop[MENDIANE], conf->max_repop[PHIRAS], conf->max_repop[THYSTAME]);
}
*/
