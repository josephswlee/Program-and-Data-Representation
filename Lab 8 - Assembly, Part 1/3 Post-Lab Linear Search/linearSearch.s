; Joseph Lee (Sangwoo)
; sl5nj
; 28 Oct 2020
; University of Virginia
; CS 2150 Post-Lab 8
; Fall 2020
; linearSearch.s	

;	Personal notes [Register usage]
;		order of registers : rdi, rsi, rdx, rcx, r8, r9  <- fixed order
;		return register : rax <- fixed and only register 		
;		callee register : r10, r11
;
;	Jumps
;		jmp -> just jump, je -> jump if equal, jne -> jump if not equal		
;		jg -> if greater, jge -> if greater or equal, jl -> if less
;		jle -> if less or equal

; 	Task: implement linearSearch 
; 		- scan through an array iteratively until it finds the target 
;		  element or reaches the end of the array
;
;	Param 1: a pointer to an int array -> rdi
; 	Param 2: size of the array [int] -> rsi
;	Param 3: target element to find in the array [int] -> rdx
;
; 	return type of the function is int, index into the array that 
; 	the target was found, or -1 if it was not found

 	global linearSearch
 	
 	section .text

linearSearch:
	;initialize
	xor	rax, rax				; zero out the return register
	xor	r10, r10				; zero out the counter i

searchLoop:
	cmp r10, rsi 				; if (i >= n)
	jge baseCase 	 			; jump to searchDone 
	;push rdi 					; store &a[]  		; not necessary 
	;push rsi 					; store n 	  		; not necessary
	mov ecx, DWORD[rdi+4*r10] 	; ecx = a[i] b/c 32 bits
	;mov edx, rdx  				; this is wrong becuase moving 8 bytes register into 4 bytes register
	cmp edx, ecx		 		; comprare a[i] with x [edx = first 4 bytes of rdx] 
	je searchDone 				; if a[i] == x return 
	inc r10						; i++
	jmp searchLoop				; loop back
	;pop rsi 					; n restored  		; not necessary
	;pop rdi 					; &a[] restored 	;not necessary

baseCase:
	mov rax, -1 				; set rax to -1
	ret 						; return base case -1 

searchDone:
	mov rax, r10				; store i into rax
	ret 						; return rax