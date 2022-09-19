/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyoo <junyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:17:34 by junyoo            #+#    #+#             */
/*   Updated: 2022/09/19 14:51:23 by junyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_printf(const char *format, ...)
{
	va_list	ap;// 가변인자 포인터 선언
	int		ret_len;	// 총 출력 길이 저장할 변수 선언
	
	va_start(ap, format);
	while( /* format[i] 가 '\0'만날때까지  */)
	{
		// 구조체 초기화
		if (/* format[i] 가 '%' 만났다면 */)
		{
			while (/* format[i] 가 type 만날때까지 */)
				// 구조체에 각 플래그 할당!
			if (/* 현재 인덱스에서 format[i] 가 type인가??  */)
				// 출력모듈로 이동
		}
		else /* format[i] 가 '%' 안만났다면 */
		{
			// 그냥 char 출력 && 출력 길이 + 1
		}	
	}
	va_end (ap);
	return (ret_len);
}
