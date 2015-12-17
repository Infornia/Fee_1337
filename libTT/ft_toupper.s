; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_toupper.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: mwilk <marvin@42.fr>                       +;+  +:+       +;+         ;
;                                                 +;+;+;+;+;+   +;+            ;
;    Created: 2015/05/16 20:51:13 by mwilk             ;+;    ;+;              ;
;    Updated: 2015/05/20 13:44:58 by mwilk            ;;;   ;;;;;;;;.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_toupper
section .text

_ft_toupper:
		mov	rax, rdi
		cmp rdi, 97
		jl ret_
		cmp rdi, 122
		jg ret_
		sub	rax, 32
		ret

ret_:
		ret
