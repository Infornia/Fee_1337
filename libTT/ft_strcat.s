; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcat.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: mwilk <marvin@42.fr>                       +;+  +:+       +;+         ;
;                                                 +;+;+;+;+;+   +;+            ;
;    Created: 2015/05/20 13:12:39 by mwilk             ;+;    ;+;              ;
;    Updated: 2015/05/20 13:59:43 by mwilk            ;;;   ;;;;;;;;.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_strcat
section .text

_ft_strcat:
		push	rbx
		push	rcx
		mov				rbx, rdi
		mov				rcx, rsi

reach_end:
		cmp				byte [rbx], 0
		je				copy
		inc				rbx
		jmp				reach_end

copy:
		cmp				byte [rcx], 0
		je				ret_
		mov				rax, [rcx]
		mov				[rbx], al
		inc				rcx
		inc				rbx
		jmp				copy

ret_:
		mov				byte [rbx], 0
		mov				rax, rdi
		pop				rcx
		pop				rbx
		ret
