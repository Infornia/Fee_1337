; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_putchar.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: mwilk <marvin@42.fr>                       +;+  +:+       +;+         ;
;                                                 +;+;+;+;+;+   +;+            ;
;    Created: 2015/05/31 21:11:44 by mwilk             ;+;    ;+;              ;
;    Updated: 2015/05/31 21:11:44 by mwilk            ;;;   ;;;;;;;;.fr        ;
;                                                                              ;
; **************************************************************************** ;

%define WRITE	0x2000004

section .bss
		char	resb	1

section .text
		global _ft_putchar

_ft_putchar:
		enter	0, 0
		lea		rsi, [rel char]
		mov		byte[rsi], dil
		mov		rax, WRITE
		mov		rdx, 1
		mov		rdi, 1
		syscall
		leave
		ret


