; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strchr.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: mwilk <marvin@42.fr>                       +;+  +:+       +;+         ;
;                                                 +;+;+;+;+;+   +;+            ;
;    Created: 2015/05/31 18:03:46 by mwilk             ;+;    ;+;              ;
;    Updated: 2015/05/31 18:03:46 by mwilk            ;;;   ;;;;;;;;.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_strchr

_ft_strchr:
		cmp [rdi], sil
		je		true_
		cmp [rdi], byte 0
		je		false_
		inc rdi
		jmp _ft_strchr

true_:
	mov		rax, rdi
	ret

false_:
	mov		rax, 0
	ret
