; Joseph Lee (Sangwoo)
; sl5nj
; CS 2150 Lab 9 - Post-Lab
; binarySearch.s

; Purpose : This file contains the implementation of the function
;           binary search 
;			return = mid [int]
; 			x = target
;	

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

;	Parameters
; 		--------------------------------------------------
; 		rdi = array, rsi = left, rdx = right, rcx = target
;		--------------------------------------------------

	global binarySearch
	section .text

binarySearch:
	xor rax, rax 				; zero out return register 
	xor r10, r10 				; zero out r10 using it for mid

	cmp rsi, rdx 				; if (low <= high)
	jg notFound 				; if low > high then target not found jump to _notFound

	push rdx 					; store right
	add rdx, rsi 				; right + left
	shr rdx, 1 					; (right + left)/2
	mov r10, rdx 				; r10 = mid 

	mov ebx, [rdi+4*r10] 		; ebx = a[mid]
	cmp ebx, ecx 				; if(a[mid] < target)

	jl addMid 					; jump to set left = mid + 1
	jg minMid  					; if (a[mid] > target) jump to _minMid 
	je searchDone 				; if a[mid] == target jump to _searchDone

addMid:
	mov rsi, r10 				; mov mid to left left = mid 
	add rsi, 1 					; left = mid + 1
	pop rdx						; pop right
	jmp binarySearch 			; jump back to _binarySearch

minMid:
	pop rdx 					; pop right
	mov rdx, r10 				; mov mid to right right = mid 
	sub rdx, 1					; right = mid - 1
	jmp binarySearch			; jump back to _binarySearch

notFound:
	mov rax, -1; 				; mov -1 into rax 
	ret 						; return -1 (not found)

searchDone:
	pop rdx 					; pop right
	mov rax, r10 				; mov index mid into rax
	ret 						; return index 