#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_flg
{
	int		before;
	int		align;
	int		zero;
	int		after;
	int		f_ast;
	int		s_ast;
	int		ast;
	int		minus;
	int		dot;
}				t_flg;

typedef struct	s_pf
{
	int		x;
	int		ret;
	int		none;
}				t_pf;

int				ft_printf(const char *str, ...);
int				ft_putchar(char c);
t_pf			ft_flags(char *str, va_list args, t_flg flg, t_pf pf);
int				ft_nb_len(long n);
char			*ft_strchr(char *s, int c);
int				check_args(char *s, va_list args, t_flg flg, t_pf *pf);
int				write_char(char c, t_flg flg);
int				write_str(char *s, t_flg flg);
unsigned int	ft_strlen(const char *str);
int				ft_putstr(char *s);
int				ft_putnbr(long n);
int				write_nbr(long num, t_flg flg);
int				write_unsigned(long n, t_flg flg);
int				ft_hex_len(unsigned int num);
int				ft_print_hex(unsigned int num, int ascii);
int				write_hex(unsigned int num, int ascii, t_flg flg);
int				ft_ptr_len(long num);
int				write_ptr(unsigned long ptr, t_flg flg);
int				ft_print_ptr(long num);

#endif
