; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isupper.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: mwilk <marvin@42.fr>                       +;+  +:+       +;+         ;
;                                                 +;+;+;+;+;+   +;+            ;
;    Created: 2015/05/16 20:51:13 by mwilk             ;+;    ;+;              ;
;    Updated: 2015/05/20 13:44:58 by mwilk            ;;;   ;;;;;;;;.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_isupper
section .text

_ft_isupper:
		cmp	rdi, 65
		jl		ret_false
		cmp	rdi, 90
		jg		ret_false
		jmp		ret_true

ret_false:
		mov	rax, 0
		ret

ret_true:
		mov	rax, 1
		ret
