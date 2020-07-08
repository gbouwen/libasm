; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    _ft_strcmp.s                                       :+:    :+:             ;
;                                                      +:+                     ;
;    By: gbouwen <marvin@codam.nl>                    +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/07/02 14:33:54 by gbouwen       #+#    #+#                  ;
;    Updated: 2020/07/02 14:33:56 by gbouwen       ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

global	_ft_strcmp

_ft_strcmp:
	mov	rax, 0				; initialize rax (return variable)
	mov	rcx, 0				; initialize rcx (counter)
	jmp	_compare			; jump to _compare label

_compare:
	mov	dl, byte[rdi + rcx]	; move the character of s1 in dl
	mov	dh, byte[rsi + rcx]	; move the character of s2 in dh
	cmp	dl, 0				; check if string is at terminating character
	je	_return				; if the string is at terminating character, return
	cmp dl, dh				; compare the characters of s1 with s2
	je _increment			; if equal, jump to increment label
	jmp	_return				; if the characters are different, return

_increment:
	inc	rcx					; increment counter (rcx) by 1
	jmp	_compare			; jump to _compare label

_return:
	cmp dl, dh				; compare the characters of s1 and s2
	jg	_return_positive	; if dl > dh, jump to _return_positive label
	jl	_return_negative	; if dl < dh, jump to _return_negative label
	ret						; return rax (0)

_return_positive:
	mov	rax, 1				; set rax to 1
	ret						; return rax (1)

_return_negative:
	mov	rax, -1				; set rax to -1
	ret						; return rax (-1)
