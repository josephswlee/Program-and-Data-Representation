; Joseph Lee (Sangwoo)
; sl5nj
; prelab 8

; mathlib.s
;
; Purpose : This file contains the implementation of the function
;           product and power.
;
; Parameter 1 (in rdi) is the starting address of a sequence of 64-bit longs
; Parameter 2 (in rsi) is the number of integers in the sequence
; Return value is a long that is the sum of the integers in the sequence
;
;
;	Personal notes [Register usage]
;		order of registers : rdi, rsi, rdx, rcx, r8, r9  <- fixed order
;		return register : rax <- fixed and only register 		
;		callee register : r10, r11
;
;	Jumps
;		jmp -> just jump, je -> jump if equal, jne -> jump if not equal		
;		jg -> if greater, jge -> if greater or equal, jl -> if less
;		jle -> if less or equal
;
	global product
	global power

	section .text

product:
	; prologue - before calling function
	;initialize
	xor rax, rax 	; zero out return value; rax is fixed
	;sanity check
	cmp rsi, 0 		; check condition if (y > 0) 
	jg productLoop 	; if greater than 0 send to loop ; sanity check
	jle productDone	; if (y <= 0) just end it

productLoop:
	cmp rsi, 0 		; check if (y <= 0)
	jle productDone 	; if so end it
	add rax, rdi 	; add rdi to the return register 
	dec rsi 	; decrement y
	jmp productLoop 	; jump back to the loop

productDone:
	; epilogue
	ret

;-------------------------------------------------------------------------

power:
	; prologue
	;initialize
	xor rax, rax 	; zero out return value; rax is fixed
	cmp rsi, 0 		; check if (y > 0)
	jg powerRecursion 	; if they are greater than 0 jump to recursion 
	jle powerBase	; if they are less or greater than 0 then jump to powerBase

powerRecursion:
	dec rsi 	; decrement y
	push rsi 	; push rsi in
	call power 	; call power
	pop rsi 	; pop rsi back
	mov rsi, rax 	
	call product 	; call product to multiply
	ret 	; return rax

powerBase:
	mov rax, 1
	ret
