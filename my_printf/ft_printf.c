

#include "ft_printf.h"

void	ft_init(t_pf *pf, t_flg *flg)
{
	pf->ret = 0;
	pf->x = 0;
	pf->none = 0;
	flg->align = 0;
	flg->before = 0;
	flg->after = -1;
	flg->zero = 0;
	flg->f_ast = 0;
	flg->s_ast = 0;
	flg->ast = 0;
	flg->minus = 0;
	flg->dot = 0;
}

int     ft_printf(const char *str, ...)
{
    va_list     args;
     t_pf		pf;
	 t_flg		flg;
    int         ret;

    ret = 0;
    ft_init(&pf, &flg);
    va_start(args, str);
    while(str[pf.x])
    {
         if(str[pf.x] == '%')
         {
            pf = ft_flags((char *)str + pf.x + 1, args, flg, pf);
            ret = ret + pf.ret;
         }
        else 
            ret = ret + ft_putchar(str[pf.x]);
            pf.x++;
    }
    return (ret);
}