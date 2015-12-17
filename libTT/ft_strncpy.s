; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strncpy.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: mwilk <marvin@42.fr>                       +;+  +:+       +;+         ;
;                                                 +;+;+;+;+;+   +;+            ;
;    Created: 2015/06/01 18:14:38 by mwilk             ;+;    ;+;              ;
;    Updated: 2015/06/01 18:14:38 by mwilk            ;;;   ;;;;;;;;.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_strncpy

section .text

_ft_strncpy:
		xor		al, al

		mov		rcx, rdx
		push	rdi
		cld
		rep		movsb
		pop		rax
		ret
