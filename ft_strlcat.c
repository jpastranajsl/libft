/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpastran <jpastran@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:30:36 by jpastran          #+#    #+#             */
/*   Updated: 2024/02/01 18:33:16 by jpastran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	res;

	i = 0;
	j = 0;
	if (!dst && dstsize == 0)
		return (0);
	while (dst[i] && i < dstsize)
		i++;
	j = ft_strlen(src);
	if (dstsize > i)
		res = i + j;
	else
		res = dstsize + j;
	j = 0;
	while (dstsize != 0 && src[j] && i < dstsize - 1)
		dst[i++] = src[j++];
	if (dstsize > i)
		dst[i] = '\0';
	return (res);
}
