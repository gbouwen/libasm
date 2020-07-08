; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    _ft_strcpy.s                                       :+:    :+:             ;
;                                                      +:+                     ;
;    By: gbouwen <marvin@codam.nl>                    +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/07/02 14:33:18 by gbouwen       #+#    #+#                  ;
;    Updated: 2020/07/02 14:33:20 by gbouwen       ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

global	_ft_strcpy

_ft_strcpy:
	mov	rax, 0					; initialize rax (return variable)
	mov	rcx, 0					; initialize rcx (counter)
	jmp _copy					; jump to _copy label

_copy:
	mov	dl, byte[rsi + rcx]		; move the first character of src in dh
	mov	byte[rdi + rcx], dl		; move the first character of src in rdi
	cmp	dl, 0					; check if src is at the end
	jne	_increment				; if src is not at the end, jump to _increment
	jmp _return					; jump to _return label

_increment:
	inc	rcx						; increment counter (rcx by 1)
	jmp	_copy					; jump to _copy label

_return:
	mov rax, rdi				; move the rdi register to rax
	ret							; return rax
