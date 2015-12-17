; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isalpha.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: mwilk <marvin@42.fr>                       +;+  +:+       +;+         ;
;                                                 +;+;+;+;+;+   +;+            ;
;    Created: 2015/05/16 20:51:13 by mwilk             ;+;    ;+;              ;
;    Updated: 2015/05/20 13:44:58 by mwilk            ;;;   ;;;;;;;;.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_isalpha
section .text

_ft_isalpha:
		cmp rdi, 65
		jl ret_false
		cmp rdi, 91
		jl ret_true
		cmp rdi, 97
		jl ret_false
		cmp rdi, 123
		jl ret_true
		jg ret_false
ret_false:
		mov rax, 0
		ret

ret_true:
		mov rax, 1
		ret
