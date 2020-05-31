/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 21:35:37 by btrifle           #+#    #+#             */
/*   Updated: 2020/05/31 13:11:41 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdarg.h>
# define BUFF_SIZE 32

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_arr
{
	int				fd;
	char			*rest;
	struct s_arr	*next;
}					t_arr;

typedef struct		s_s
{
	char			s;
	char			s1;
	char			s2;
	int				zero;
	int				point;
	int				numb;
	int				decim;
	int				plus;
	int				minus;
	int				backsp;
	char			sign;
	int				hash;
}					t_s;

typedef	unsigned char	t_uchar;
typedef unsigned int	t_uint;
typedef unsigned long	t_ulong;

typedef union
{
	double			dbl;
	struct {
		long		mantissa: 52;
		t_uint		exponent: 11;
		t_uchar		sign: 1;
	}				parts;
}					t_double;

typedef	union
{
	long double		l_dbl;
	struct {
		long		mantissa: 64;
		t_uint		exponent: 15;
		t_uchar		sign: 1;
	}				parts;
}					t_long_dbl;

typedef struct		s_long
{
	t_uint			*whole;
	t_uint			*decimal;
	t_ulong			flag;
}					t_long;

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,\
					size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_cut_backspaces(const char *s);
int					ft_atoi(const char *str);
long long			ft_atol(const char *str);
char				*ft_atoi_pointer(const char *str, int *n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *s));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
int					ft_putchar(char c);
int					ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_first_decimal(int n);
char				*ft_strndup(const char *s, size_t n);
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstnew_gnl(int buff_size, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char				**trim(char *s, char ch);
int					get_next_line(const int fd, char **line);
/*
** arithm.c
*/
t_uint				*add_arithmetics(t_uint *a, t_uint *b);
t_uint				*set_arithmetic_zeros(int n);
t_uint				*add_arithmetics_minus(t_uint *a, t_uint *b);
/*
** check_inf_nan1.c
*/
int					put_inf(t_s *sp);
int					put_dlng_inf(t_s *sp);
void				ft_put_nan(t_s *sp);
int					check_double_inf(double a, t_s *sp);
int					check_dlng_inf(t_long_dbl *num_dbl, t_s *sp);
/*
** check_inf_nan2.c
*/
int					ft_negative_double_inf(void);
/*
** functions1.c
*/
void				ft_put_zeros_backsp(t_s *sp);
int					ft_putchar_c(char c, t_s *sp);
size_t				ft_strlen(const char *s);
/*
** functions3.c
*/
int					digits_in_base(long value, int base);
int					digits_in_base_unsigned(t_ulong u_value, int base);
int					ft_putnbr_positive(int n);
int					ft_putlong(long n);
/*
** functions4.c
*/
void				free_letters_s(char *letters, char *s);
int					ft_itoa_base_unsigned(t_ulong u_value, int base, \
													int lett_type);
/*
** print_double.c
*/
void				print_memory(t_uint *s);
int					print_double_whole_part(t_uint *s);
int					print_double_decimal_part(t_uint *s, int n);
void				print_binary_t_uint(t_uint num, int dig);
void				print_binary_t_ulong(t_ulong num, int dig);
/*
** process_sp1.c
*/
void				clear_spec(t_s *sp);
void				handle_lhl(char *p, t_s *sp);
char				*find_spec(char *p, t_s *sp);
void				set_zero(char *p, char *s, t_s *sp);
/*
** process_sp2.c
*/
void				set_plus(char *p, char *s, t_s *sp);
void				set_minus(char *p, char *s, t_s *sp);
void				set_backsp(char *p, char *s, t_s *sp);
char				*set_point(char *p, char *s, t_s *sp);
void				set_numb(char *p, char *s, t_s *sp);
/*
** process_sp3.c
*/
void				set_decimal(char *p, t_s *sp);
void				set_hash(char *p, char *s, t_s *sp);
char				*parse_sier(char *p, t_s *sp);
int					process_x_o(t_s *sp);
int					process_integers(t_s *sp);
/*
** process_sp4.c
*/
int					process_specifier_double(t_s *sp);
int					process_specifier(t_s *sp, va_list ap);
char				*process_specifier_s1_s2(char *s, char sp2);
int					process_specifier_main(t_s *sp, char *p, va_list ap);
/*
** process_sp5.c
*/
int					ft_printf(char *fmt, ...);
/*
** put_d1.c
*/
void				ft_put_n_chars(char c, int n);
void				ft_put_long(long num);
int					ft_put_int_min(int k, t_s *sp);
void				ft_put_int_min_ze_nmi(int k);
int					ft_put_int_min_with_point(t_s *sp);
/*
** put_d2.c
*/
int					ft_put_int_min_with_spec(t_s *sp);
int					ft_put_d_without_numb_point(long num, t_s *sp);
void				ft_put_d_pl_si_mi(long num, int k, int l, t_s *sp);
void				ft_put_d_pl_nsi_ze(long num, int k, int l, t_s *sp);
void				ft_put_d_pl_nsi(long num, int k, int l, t_s *sp);
/*
** put_d3.c
*/
void				ft_put_d_npl_nsi_mi_ba(long num, int *k, int l, t_s *sp);
void				ft_put_d_npl_nsi_ze(long num, int k, int l, t_s *sp);
void				ft_put_d_npl_nsi_mi(long num, int k, int l, t_s *sp);
void				ft_put_d_si_mi(long num, int k, int l);
void				ft_put_si_ze(long num, int k, int l, t_s *sp);
/*
** put_d4.c
*/
void				ft_put_int_min_minus(t_s *sp, int k, int l);
int					ft_put_si_ba(long num, int k, int l);
void				ft_put_else(long num, int k, int l, t_s *sp);
int					ft_put_npl_nsi_ba(long num, int k, int l, t_s *sp);
int					ft_put_npl_nsi_ze_ba(long num, int k, int l, t_s *sp);
/*
** put_d5.c
*/
long				ft_cast_num(long num, t_s *sp);
int					ft_put_d_if_specif1(long num, t_s *sp, int k, int l);
int					ft_put_d_if_specif2(long num, t_s *sp, int k, int l);
int					ft_put_d_with_numb_point(long num, t_s *sp, int dig);
int					ft_put_d(long num, t_s *sp);
/*
** put_double1.c
*/
void				normalize(t_uint *a, t_uint *s, int i);
t_long				*create_long_whole_pre(t_double *num_union_f);
t_long				*create_long_whole(t_double *num_union_f);
t_uint				*ft_temp_b_floats(t_double *num_union_f, t_uint n);
t_long				*create_long(double x, int d);
/*
** put_double2.c
*/
void				free_long_arithm(t_long *lng);
int					put_double_new(double x, t_s *sp);
int					ft_put_f_double(double a, t_s *sp);
int					ft_memory_float(double a);
int					ft_memory_ldbl(long double a);
/*
** put_ee1.c
*/
void				ft_put_sign(t_s *sp);
void				ft_put_exp(t_s *sp, int dig);
int					ft_put_exp_value(int exp_);
void				normalize_sci(t_uint *s, int d);
t_uint				*create_one_array_e(t_long *lng);
/*
** put_ee2.c
*/
int					ft_find_exp(t_long *lng);
void				ft_fill_in_one_arr_e(t_uint *arr, t_long *lng, int j);
int					ft_put_value_in_e(t_uint *arr, t_s *sp, int j);
int					ft_put_e_zero(t_s *sp);
int					ft_put_sci(double x, t_s *sp);
/*
** put_ee3.c
*/
int					ft_dig_db(double a);
int					ft_get_k_for_e(double x, t_s *sp);
int					ft_put_whole_sci(double x, t_s *sp);
/*
** put_f1.c
*/
int					ft_put_double_help_pl_nsi(double a, t_s *sp);
int					ft_put_double_set_k(t_s *sp, int dig);
void				ft_put_double_help_pl_mi(double a, t_s *sp, int k);
void				ft_put_double_help_pl_nsi_ze(double a, t_s *sp, int k);
void				ft_put_double_help_pl_nsi2(double a, t_s *sp, int k);
/*
** put_f2.c
*/
void				ft_put_double_help_npl_nsi_mi_ba(double a, t_s *sp, int k);
void				ft_put_double_help_npl_mi(double a, t_s *sp, int k);
void				ft_put_double_help_npl_nsi_ba(double a, t_s *sp, int k);
void				ft_put_double_help_si_ze(double a, t_s *sp, int k);
/*
** put_f3.c
*/
void				ft_put_double_help_si_ba(double a, t_s *sp, int k);
void				ft_put_double_help_else(double a, t_s *sp, int k);
void				process_sp_for_double(double a, t_s *sp, int k);
int					ft_put_whole_double(double a, t_s *sp);
/*
** put_o_u_x1.c
*/
void				ft_put_prelimenaries(t_s *sp);
int					ft_put_o_x_if_u(t_s *sp);
int					ft_put_integer_u(t_ulong u_value, t_s *sp);
int					ft_dig_x_o(t_ulong num, t_s *sp);
void				ft_put_x_o_l_k(t_s *sp, int l, int k);
/*
** put_o_u_x2.c
*/
int					ft_put_x_o_num(t_ulong num, t_s *sp, int k, int dig);
t_ulong				ft_cast_num_t_ulong(t_ulong num, t_s *sp);
void				ft_put_x_o_process_dig(t_ulong num, t_s *sp, \
												int *addr_dig);
int					ft_put_x_o(t_ulong num, t_s *sp);
/*
** put_long_e.c
*/
int					ft_put_sci_ldbl(long double x, t_s *sp);
int					ft_dig_long(long double a);
int					ft_get_k_for_e_ldbl(long double x, t_s *sp);
int					ft_put_whole_sci_ldbl(long double x, t_s *sp);
/*
** put_long_dbl1.c
*/
t_long				*ft_create_long_pre(t_long_dbl *num_dbl);
t_long				*ft_create_long_whole(t_long_dbl *num_dbl);
int					ft_create_n_temp(t_uint exp_, int d, t_uint z);
t_uint				*ft_create_b_temp(t_uint exp_, t_uint n);
void				ft_create_long_decimal(t_long *lng2, t_long_dbl \
												*num_dbl, int d);
/*
** put_long_dbl2.c
*/
int					ft_put_long_only(t_long_dbl *num_dbl, t_s *sp);
int					ft_dig_ldbl(long double a);
void				ft_put_from_specif_ldbl_minus(t_long_dbl *num_dbl, \
												t_s *sp, int k);
void				ft_put_from_specif_ldbl(t_long_dbl *num_dbl, t_s *sp, \
												int k);
int					ft_get_k_for_ldbl(t_s *sp, int dig);
/*
** put_long_dbl3.c
*/
int					ft_put_long_double(long double x, t_s *sp);
/*
** put_p.c
*/
int					ft_put_p_zero(t_s *sp);
int					ft_put_p_minus(long num, int l, int k);
int					ft_put_p(long num, t_s *sp);
/*
** put_strings1.c
*/
int					ft_put_percentage(t_s *sp);
int					ft_put_null(t_s *sp);
int					ft_get_l_strings(t_s *sp, int n);
int					ft_get_k_strings(t_s *sp, int l, int n);
void				ft_put_str_k_l(t_s *sp, char *str, int k, int l);
/*
** put_strings2.c
*/
int					ft_put_string(char *str, t_s *sp);
/*
** two.c
*/
t_uint				*raise_to_power_2(t_uint *s);
t_uint				*power_of_2(t_uint pow, int n);
int					ft_divide_by_2_i(t_uint *s);
t_uint				*divide_by_2(t_uint *s);
t_uint				*divide_by_minus_2(t_uint *s, t_uint n);
#endif
