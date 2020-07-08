; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    _ft_atoi_base.s                                    :+:    :+:             ;
;                                                      +:+                     ;
;    By: gbouwen <marvin@codam.nl>                    +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/07/03 11:05:00 by gbouwen       #+#    #+#                  ;
;    Updated: 2020/07/03 11:05:00 by gbouwen       ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

global	_ft_atoi_base
extern	_ft_strlen

_ft_atoi_base:
	mov		rax, 0					; initialize rax (return variable)
	mov		rcx, 0					; initialize rcx (counter)
	cmp		byte[rdi + rcx], 0		; check if rdi is not an empty string
	je		_str_empty				; if equal, jump to _str_empty
	cmp		byte[rsi + rcx], 0		; check if base is not an empty string
	je		_str_empty				; if equal, jmp to _str_empty
	push	rdi						; push value of rdi (str) to stack
	push	rsi						; push value of rsi (base) to stack
	mov		rdi, rsi				; move rsi (base) to rdi so _ft_strlen can use it
	call	_ft_strlen				; get strlen of base
	cmp		rax, 1					; check if rax (base) == 1
	je		_base_1					; if equal, jump to base_1
	pop		rsi						; pop base back into rsi
	pop		rdi						; pop str back into rdi
	jmp		_check_string_base		; jump to _check_base label

_str_empty:
	mov	rax, 123					; REMOVE THIS WHEN SUBMITTING
	ret								; return rax

_base_1:
	pop		rsi						; pop base off stack
	pop		rdi						; pop str off stack
	mov		rax, 111				; set rax to 0 --- FIX THIS WHEN SUBMITTING
	ret								; return rax

_check_string_base:
	mov		rdx, 0					; initialize rdx (counter for base)
	mov		r8b, byte[rdi + rcx]	; move character of str to r8b
	mov		r9b, byte[rsi + rdx]	; move character of base to r9b
	cmp		r8b, r9b				; compare char of string with char of base
	jne		_loop_string_base		; if not equal, jump to _loop_base_base label
	inc		rcx						; increment rcx (counter for string)
	jmp		_check_string_base		; jump to _check_base label

_loop_string_base:
	cmp		byte[rsi + rdx], 0		; check if base is at the end
	je		_err_base				; if equal, jump to _err_base label
	inc		rdx						; increment rdx (base counter)
	mov		r8b, byte[rdi + rcx]	; move character of str to r8b
	mov		r9b, byte[rsi + rdx]	; move character of base to r9b
	cmp		r8b, r9b				; compare char of string with char of base
	jne		_loop_string_base		; if not equal, jump back to beginning of this label
	cmp		byte[rdi + rcx], 0		; check if string is at the end
	je		_skip_spaces			; jump to _skip_spaces label
	inc		rcx						; increment rcx (string counter)
	jmp		_check_string_base		; jump to _check_base label

_err_base:
	mov		rax, 77					; set rax to 0 --- FIX THIS WHEN SUBMITTING
	ret								; return rax

_skip_spaces:
	mov		rcx, 0
	cmp		byte[rdi + rcx], ' '	; check if char is a space
	je		_loop_spaces			; if equal, jump to _loop_spaces label
	jmp		_ret

_loop_spaces:
	inc		rcx						; increase rcx (counter)
	jmp		_skip_spaces			; jump back to _skip_spaces label

_ret:
	mov		rax, 5
	ret
