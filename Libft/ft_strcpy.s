; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcpy.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: mwilk <marvin@42.fr>                       +;+  +:+       +;+         ;
;                                                 +;+;+;+;+;+   +;+            ;
;    Created: 2015/06/01 18:04:30 by mwilk             ;+;    ;+;              ;
;    Updated: 2015/06/01 18:04:30 by mwilk            ;;;   ;;;;;;;;.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_strcpy
section .text
	extern _ft_strlen

_ft_strcpy:
		mov			r8, rdi

_loop:
		mov			cl, [rsi]
		mov			[rdi], cl
		cmp			cl, 0
		jz			_ret
		inc			rdi
		inc			rsi
		jmp			_loop

_ret:
		mov			rax, r8
		ret
