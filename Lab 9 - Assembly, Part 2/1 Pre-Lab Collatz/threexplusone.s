; Joseph Lee (Sangwoo)
; sl5nj
; CS 2150 Lab 9 - Pre-Lab
; threexinput.s

; Purpose : This file contains the implementation of the function
;           collatz conjecture
;			if odd: 3x + 1
; 			if even: x/2
;	rdi = x

;	Personal notes [Register usage]
;		six registers for parameter passing
;		order of registers : rdi, rsi, rdx, rcx, r8, r9  <- fixed order
;		return register : rax <- fixed and only register 		
;		callee register : r10, r11
;		six registers may not be modified by a subroutine callee : 
;		rbx, rbp, r12-r15
;		top of the stack : rsp

;	Jumps
;		jmp -> just jump, je -> jump if equal, jne -> jump if not equal		
;		jg -> if greater, jge -> if greater or equal, jl -> if less
;		jle -> if less or equal, jz -> if zero, jnz -> if not eqaul zero

; Optimization 

; 1. used lea instead of multiply 3 then add 1 and did times 2 instead of times 3 (got it from TA)
; 2. I used less subroutine
; 3. used test instruction with jz/jnz to test odd or even

	global threexplusone
	section .text

threexplusone:
	xor rax, rax 			; set return value to 0 

	cmp rdi, 1 				; check if (x == 1)
	je completed 			; if rdi == 1 end it  

	test rdi, 1 			; check if the number is odd or even with lowest bit/ got it from one of TA
	jz even 				; if the lowest bit == 0 its even 
	jnz odd 				; if ! 0 its odd

odd:
	lea rdi, [2*rdi+rdi+1] 	; 2 * x + x + 1 : same as 3 * rdi + 1 but faster
	call threexplusone 		; recurse 
	inc rax 				; increment count by 1
	jmp completed

even:
	shr rdi, 1 				; x/2
	call threexplusone 		; recurse 
	add rax, 1				; increment count by 1
	jmp completed

completed:
	ret 					; return 