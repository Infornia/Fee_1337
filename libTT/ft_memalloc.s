; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_memalloc.s                                      :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: mwilk <marvin@42.fr>                       +;+  +:+       +;+         ;
;                                                 +;+;+;+;+;+   +;+            ;
;    Created: 2015/05/31 18:57:17 by mwilk             ;+;    ;+;              ;
;    Updated: 2015/05/31 18:57:24 by mwilk            ;;;   ;;;;;;;;.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_memalloc

section .text
		extern _ft_bzero
		extern _malloc

_ft_memalloc:
		push rdi
		call	_malloc
		cmp		rax, 0
		je		ret_
		mov	rdi, rax
		pop	rsi
		call _ft_bzero
		ret


ret_:
		mov rax, 0
		ret



