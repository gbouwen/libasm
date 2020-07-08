; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    _ft_write.s                                        :+:    :+:             ;
;                                                      +:+                     ;
;    By: gbouwen <marvin@codam.nl>                    +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/07/02 14:34:49 by gbouwen       #+#    #+#                  ;
;    Updated: 2020/07/02 14:34:49 by gbouwen       ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

global	_ft_write

extern	___error

_ft_write:
	mov		rax, 0x2000004	; put the number for system call write in rax (return variable)
	syscall					; call the write() system call
	jc		_handle_error	; jump to _handle_error label if carry flag is set
	ret						; return rax

_handle_error:
	mov		rdi, rax		; set errno in rdi
	push	rdi				; push value of rdi on stack
	call	___error		; get memory address of errno in rax
	pop		rdi				; pop value of rdi off stack
	mov		[rax], rdi		; set errno in rax
	mov		rax, -1			; set rax to -1
	ret						; return rax
