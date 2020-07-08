; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    _ft_strlen.s                                       :+:    :+:             ;
;                                                      +:+                     ;
;    By: gbouwen <marvin@codam.nl>                    +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/07/02 14:32:25 by gbouwen       #+#    #+#                  ;
;    Updated: 2020/07/02 14:32:25 by gbouwen       ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

global	_ft_strlen

_ft_strlen:
	mov	rax, 0				; initialize rax (return variable)
	jmp _compare			; jump to _compare label

_compare:
	cmp	byte[rdi + rax], 0	; check if string is at terminating character (0)
	je	_return				; if string is at terminating character, jump to _return label
	inc rax					; if string is not at the end, increment counter (rax) by 1
	jmp _compare			; jump back to the beginning of this label

_return:
	ret						; return the value of rax
