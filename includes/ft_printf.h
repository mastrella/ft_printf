/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmastrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 06:47:28 by mmastrel          #+#    #+#             */
/*   Updated: 2017/04/20 04:37:04 by mmastrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>

typedef struct	s_format
{
	int			num;
	int			zero;
	int			neg;
	int			plus;
	int			space;
	int			hh;
	int			h;
	int			l;
	int			ll;
	int			j;
	int			z;
	int			width;
	int			width_arg;
	int			width_value;
	int			prec;
	int			prec_arg;
	int			prec_value;
}				t_format;

int				ft_printf(const char *format, ...);
int				prepare_n_print(va_list *ap, const char *format, int ret);
int				prepare_format(t_format *flags);
int				observe_format(const char *format, t_format *flags,
					va_list *ap);
int				observe_flags(const char *format, t_format *flags,
					va_list *ap, int moved);
int				observe_length(const char *format, t_format *flags,
					va_list *ap, int moved);
int				check_h(const char *format, t_format *flags, int moved);
int				check_l(const char *format, t_format *flags, int moved);
int				observe_prec(const char *format, t_format *flags,
					va_list *ap, int moved);
int				get_prec(const char *format, t_format *flags,
					va_list *ap, int moved);
int				observe_width(const char *format, t_format *flags,
					va_list *ap, int moved);
int				invocate_args(const char *format, va_list *ap,
					t_format flags, int ret);
int				print_c(int character, t_format flags, int ret);
int				print_s(char *s, t_format flags, int ret);
int				print_p(void *pointer, t_format flags, int ret);
int				print_num(const char *format, va_list *ap,
					t_format flags, int ret);
void			print_n(int *written, int ret);
int				print_percent(t_format flags, int ret);
char			*int_to_a(const char *format, va_list *ap,
					t_format flags, char *arg);
char			*uint_to_a(const char *format, va_list *ap,
					t_format flags, char *arg);
char			*octal_to_a(va_list *ap, t_format flags, char *arg);
char			*hexlow_to_a(va_list *ap, t_format flags, char *arg);
char			*hexup_to_a(va_list *ap, t_format flags, char *arg);
char			*binary_to_a(va_list *ap, t_format flags, char *arg);
char			*ft_itoa_base(intmax_t curr_arg, int base, int upper);
char			*ft_uitoa_base(uintmax_t curr_arg, int base, int upper);
int				ft_ilength(intmax_t n, int base);
int				ft_uilength(uintmax_t n, int base);
int				handle_num(char *curr_arg, t_format flags,
					const char *format, int ret);
int				print_padding(t_format flags, int size, int ret, int right);
int				print_hash(const char *format, int ret);
void			ft_bzero(void *s, size_t n);
void			ft_putchar(char c);
void			ft_putstr(const char *str);
int				ft_putstrn(char *s, int n);
int				ft_strlen(const char *str);
int				ft_atoi(const char *str);
char			*ft_witos(wint_t c);
char			*ft_strnew(size_t size);
char			*ft_strcpy(char *dst, const char *src);
void			*ft_memalloc(size_t size);
void			*ft_memset(void *b, int c, size_t len);

# define NORMAL    "\033[0m"
# define LIGHT     "\033[1m"
# define BLACK     "\033[30m"
# define RED       "\033[31m"
# define GREEN     "\033[32m"
# define YELLOW    "\033[33m"
# define BLUE      "\033[34m"
# define MAGENTA   "\033[35m"
# define CYAN      "\033[36m"
# define WHITE     "\033[37m"
# define BG_BLACK  "\033[40m"
# define BG_RED    "\033[41m"
# define BG_GREEN  "\033[42m"
# define BG_YELLOW "\033[43m"
# define BG_BLUE   "\033[44m"
# define BG_VIOLET "\033[45m"
# define BG_CYAN   "\033[46m"
# define BG_WHITE  "\033[47m"
# define CHECK_HASH (flags.num == 1 && (curr_arg[0] != '0' || CH2
# define CH2		((*format == 'o' || *format == 'O') && curr_arg[0] == CH3
# define CH3		'0' && flags.prec == 1 && flags.prec_value == 0)))
# define MOVE_NEG   (curr_arg[0] == '-' ? curr_arg++ : curr_arg)
# define RIGHT_JUST zero_just = 1; RJ2
# define RJ2 ret = print_pre(curr_arg, flags, format, ret); MOVE_NEG
# define PRINT 	while (flags.prec_value > size) size += write(1, "0", 1); P2
# define P2 if (curr_arg[0] != '0' || flags.prec != 1 || P3
# define P3 flags.prec_value != 0) ft_putstr(curr_arg)

#endif
