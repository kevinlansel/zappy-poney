#ifndef		TMP
# define	TMP

#define		SIZE_PTR_FUNC	14

typedef struct	s_conf
{
  int		time_repop[MAX];
  int		max_repop[MAX];
}		t_conf;

typedef struct	s_ptr_func_parse
{
  char		*str;
  int		off;
}		t_ptr_func_parse;

#endif
