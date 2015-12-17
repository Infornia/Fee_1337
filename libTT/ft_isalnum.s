; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isalnum.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: mwilk <marvin@42.fr>                       +;+  +:+       +;+         ;
;                                                 +;+;+;+;+;+   +;+            ;
;    Created: 2015/05/16 20:51:13 by mwilk             ;+;    ;+;              ;
;    Updated: 2015/05/20 13:44:58 by mwilk            ;;;   ;;;;;;;;.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_isalnum
section .text
	extern _ft_isdigit
	extern _ft_isalpha

_ft_isalnum:
		call	_ft_isalpha
		cmp rax, 1
		je	ret_true

		call	_ft_isdigit
		cmp rax, 1
		je	ret_true
		jmp	ret_false

ret_false:
		mov rax, 0
		ret

ret_true:
		mov rax, 1
		ret
