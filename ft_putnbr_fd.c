/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpastran <jpastran@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:54:52 by jimenapastr       #+#    #+#             */
/*   Updated: 2024/02/01 18:32:00 by jpastran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	m;

	if (n < 0)
	{
		m = -n;
		write (fd, "-", 1);
	}
	else
		m = n;
	if (m >= 10)
	{
		ft_putnbr_fd(m / 10, fd);
		ft_putnbr_fd(m % 10, fd);
	}
	if (m < 10)
	{
		m += '0';
		write (fd, &m, 1);
	}
}
