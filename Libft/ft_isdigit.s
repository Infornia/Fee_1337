; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isdigit.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: mwilk <marvin@42.fr>                       +;+  +:+       +;+         ;
;                                                 +;+;+;+;+;+   +;+            ;
;    Created: 2015/05/16 20:51:13 by mwilk             ;+;    ;+;              ;
;    Updated: 2015/05/20 13:44:58 by mwilk            ;;;   ;;;;;;;;.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_isdigit
section .text

_ft_isdigit:
		cmp rdi, 48
		jl ret_false
		cmp rdi, 57
		jle ret_true
		jg ret_false
ret_false:
		mov rax, 0
		ret

ret_true:
		mov rax, 1
		ret
