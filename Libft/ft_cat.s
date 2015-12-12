; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_cat.s                                           :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: mwilk <marvin@42.fr>                       +;+  +:+       +;+         ;
;                                                 +;+;+;+;+;+   +;+            ;
;    Created: 2015/05/29 20:41:15 by mwilk             ;+;    ;+;              ;
;    Updated: 2015/05/29 20:41:15 by mwilk            ;;;   ;;;;;;;;.fr        ;
;                                                                              ;
; **************************************************************************** ;

%define WRITE	0x2000004
%define READ	0x2000003

section .bss
		buff resb 1024
		buff_size equ $-buff

section .text
		global _ft_cat

_ft_cat:
		while:
			push rdi
			lea rsi, [rel buff]
			mov rdx, buff_size
			mov rax, READ
			syscall
			jc end
			cmp rax, 0
			jle end
			mov rdi, 1
			mov rdx, rax
			mov rax, WRITE
			syscall
			pop rdi
		jmp while

end:
		pop rdi
		ret
