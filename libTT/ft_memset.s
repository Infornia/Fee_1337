; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_memset.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: mwilk <marvin@42.fr>                       +;+  +:+       +;+         ;
;                                                 +;+;+;+;+;+   +;+            ;
;    Created: 2015/05/22 18:32:04 by mwilk             ;+;    ;+;              ;
;    Updated: 2015/05/22 18:32:04 by mwilk            ;;;   ;;;;;;;;.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_memset

;		push	rcx
;		mov			rcx, 0
;
;while:
;		cmp			rdi, 0
;		je			_ret
;		cmp			rcx, rdx
;		je			_ret
;		mov			rdi, rsi
;		inc			rcx
;		inc			rax
;		jmp			while
;
;_ret:
;		mov			rax, rdi
;		pop		rcx
;		ret
section .text

_ft_memset:
		push	rdi
		mov			rax, rsi
		mov			rcx, rdx
		rep			stosb
		pop			rax
		ret
