; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strnew.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: mwilk <marvin@42.fr>                       +;+  +:+       +;+         ;
;                                                 +;+;+;+;+;+   +;+            ;
;    Created: 2015/05/31 20:47:13 by mwilk             ;+;    ;+;              ;
;    Updated: 2015/05/31 20:47:13 by mwilk            ;;;   ;;;;;;;;.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_strnew

section .text
		extern _ft_memalloc

_ft_strnew:
		push	rdi
		inc		rdi
		call	_ft_memalloc
		cmp		rax, 0
		pop		rdi
		ret
