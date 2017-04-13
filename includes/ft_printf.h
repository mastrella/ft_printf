/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmastrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 06:47:28 by mmastrel          #+#    #+#             */
/*   Updated: 2017/03/20 01:04:13 by mmastrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <wchar.h>

/*  needed for vprintf  */
/*
typedef struct	s_ret
{
	int		amt_written;
	char	*string;
	int		location;
}				t_ret;
*/

/*  flag manager  */
typedef struct  s_format
{
  int num;
  int zero;
  int neg;
  int plus;
  int space;
  int hh;
  int h;
  int l;
  int ll;
  int j;
  int z;
  int width;
  int width_arg;
  int width_value;
  int precision;
  int precision_arg;
  int precision_value;
}     t_format;

/*  run function  */
int		ft_printf(const char *format, ...);
int		prepare_n_print(va_list *ap, const char *format, int ret);

/*  check for flags  */
void	prepare_format(t_format *flags);
int		observe_format(const char *format, t_format *flags, va_list *ap);
int		observe_flags(const char *format, t_format *flags, va_list *ap, int move);
int		observe_length(const char *format, t_format *flags, va_list *ap, int move);
int		observe_prec_width(const char *format, t_format *flags, int i, va_list *ap, int move);

/*  print arguments  */
int		invocate_args(const char *format, va_list *ap, t_format flags, int ret);
int		print_c(int character, t_format flags, int ret);
int		print_s(char *s, t_format flags, int ret);
int		print_p(void *pointer, t_format flags, int ret);
int		print_num(const char *format, va_list *ap, t_format flags, int ret);
void  print_n(int *written, int ret);
int		print_percent(t_format flags, int ret);


/*  print numbers  */
char  *ft_itoa_base(intmax_t curr_arg, int base, int upper);
char  *ft_uitoa_base(uintmax_t curr_arg, int base, int upper);
int   ft_ilength(intmax_t n, int base);
int   ft_uilength(uintmax_t n, int base);
int		handle_num(char *curr_arg, t_format flags, const char *format, int ret);
int   print_padding(t_format flags, int size, int ret, int right);
int	print_hash(const char *format, int ret);

/*  library functions  */
void	ft_bzero(void *s, size_t n);
void	ft_putchar(char c);
void	ft_putstr(const char *str);
int		ft_putstrn(char *s, int n);
int		ft_strlen(const char *str);
int		ft_atoi(const char *str);
char	*ft_witos(wint_t c);
char	*ft_strnew(size_t size);
char	*ft_strcpy(char *dst, const char *src);
void	*ft_memalloc(size_t size);
void	*ft_memset(void *b, int c, size_t len);

#endif
