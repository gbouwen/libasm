; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    _ft_strdup.s                                       :+:    :+:             ;
;                                                      +:+                     ;
;    By: gbouwen <marvin@codam.nl>                    +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/07/02 16:23:28 by gbouwen       #+#    #+#                  ;
;    Updated: 2020/07/02 16:23:39 by gbouwen       ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

global	_ft_strdup

extern	___error
extern	_malloc
extern	_ft_strlen
extern	_ft_strcpy

_ft_strdup:
	push	rdi				; push rdi (the string you want to duplicate) to stack
	call	_ft_strlen		; call ft_strlen(), len is now in rax
	mov		rdi, rax		; move value of rax to rdi
	call	_malloc			; call malloc, it uses rdi as its first argument
	cmp 	rax, 0			; check if malloc succeeded
	je		_malloc_fail	; if rax is equal to 0, jump to _malloc_fail label
	mov		rdi, rax		; move malloced string from rax to rdi
	pop		rsi				; pop the string you want to duplicate into rsi
	call	_ft_strcpy		; copy the string with ft_strcpy(), result is in rax
	ret						; return rax

_malloc_fail:
	pop		rdi				; pop previous value of rdi, so stack will be empty
	call 	___error		; get memory address of errno in rax
	mov		rdi, 12			; set rdi to ENOMEM (12)
	mov		[rax], rdi		; set value of rdi into rax
	mov		rax, 0			; set rax to 0
	ret						; return rax
