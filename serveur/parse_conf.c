/*
** parse_conf.c for  in /home/lund/Projets/zappy-poney/serveur
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Mon Jun 10 21:53:42 2013 florian dewulf
** Last update Tue Jun 11 16:30:12 2013 florian dewulf
*/

#include	"tmp.h"

void		defaultconfig(t_conf *conf)
{
  config->max_nour = ;
  config->max_line = ;
  config->max_derau = ;
  config->max_sibur = ;
  config->max_mend = ;
  config->max_phiras = ;
  config->max_thyst = ;
  config->time_repop__nour = ;
  config->time_repop__line = ;
  config->time_repop__derau = ;
  config->time_repop__sibur = ;
  config->time_repop__mend = ;
  config->time_repop__phiras = ;
  config->time_repop__thyst = ;
}

void		fileconfig(t_conf *config, FILE *file)
{
  char		buffer[1024];
  int		binary;

  binary = 0;
  while (fgets(buffer, 1024, file) == NULL)
    {
      //à transformer en ptr sur func en envoyant binary en pointeur pour le modif
      if (strncmp(buffer, "PopNourriture:", 14) == 0)
	{
	  config-> = atoi(strdup(&(buffer[14])));
	  binary |= 1;
	}
      else if (strncmp(buffer, "PopLinemate:", 12) == 0)
	{
	  config-> = atoi(strdup(&(buffer[12])));
	  binary |= 2;
	}
      else if (strncmp(buffer, "PopDeraumere:", 13) == 0)
	{
	  config-> = atoi(strdup(&(buffer[13])));
	  binary |= 4;
	}
      else if (strncmp(buffer, "PopSibur:", 9) == 0)
	{
	  config-> = atoi(strdup(&(buffer[9])));
	  binary |= 8;
	}
      else if (strncmp(buffer, "PopMendiane:", 12) == 0)
	{
	  config-> = atoi(strdup(&(buffer[12])));
	  binary |= 16;
	}
      else if (strncmp(buffer, "PopPhiras:", 10) == 0)
	{
	  config-> = atoi(strdup(&(buffer[10])));
	  binary |= 32;
	}
      else if (strncmp(buffer, "PopThystame:", 12) == 0)
	{
	  config-> = atoi(strdup(&(buffer[12])));
	  binary |= 64;
	}
      else
	{
	  defaultconfig(config);
	  return;
	}
    }
  if (binary == 127)
    defaultconfig(config);
}

void		parsefile(t_conf *config)
{
  FILE		*file;

  file = fopen(".conf", "r");
  if (file == NULL)
    {
      defaultconfig(config);
      return;
    }
  fileconfig(config, file);
  fclose(file);
}

void		parseconf(t_map **map)
{
  t_conf	*config;

  if (access(R_OK | F_OK) == -1)
    defaultconfig(config);
  else
    parsefile(config);
}


