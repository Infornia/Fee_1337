# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_puts.s                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwilk <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/16 20:51:13 by mwilk             #+#    #+#              #
#    Updated: 2015/05/22 17:06:46 by mwilk            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



%define STDOUT 1
%define WRITE 0x2000004

global _ft_puts

section .data
		endl:
					db		0x0a

section .text
		extern _ft_strlen

_ft_puts:
		cmp			rdi, 0
		je			NULL

		mov			rsi, rdi
		call	_ft_strlen

		mov			rdi, STDOUT
		mov			rdx, rax
		mov		rax, WRITE
		syscall

		lea			rsi, [rel endl]
		mov			rdx, 1
		mov		rax, WRITE
		syscall
		jmp			ret_

NULL:
		mov			rdi, 1
		lea			rsi, [rel msg.string]
		mov			rdx, 6
		mov		rax, WRITE
		syscall

		mov			rdx, 1
		lea			rsi, [rel endl]
		mov		rax, WRITE
		syscall

ret_:
		mov		rax, 10
		ret

msg:
	.string db "(null)"
