/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:36:27 by aska              #+#    #+#             */
/*   Updated: 2025/01/30 17:40:21 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printf_fd(int fd, const char *format, ...)
{
	int		len;
	int		i;
	va_list	pointer;

	len = 0;
	i = 0;
	va_start(pointer, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 's')
				len += ft_putstr_fd(va_arg(pointer, char *), fd);
			else if (format[i] == 'd')
				len += ft_putnbr_fd(va_arg(pointer, int), fd);
			else if (format[i] == 'c')
				len += ft_putchar_fd(va_arg(pointer, int), 1);
		}
		else
			len += write(fd, &format[i], 1);
		i++;
	}
	va_end(pointer);
	return (len);
}

size_t	ft_puttab(char **tab)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	while (tab[i])
	{
		len += ft_putstr(tab[i]);
		len += ft_putchar('\n');
		i++;
	}
	return (len);
}
