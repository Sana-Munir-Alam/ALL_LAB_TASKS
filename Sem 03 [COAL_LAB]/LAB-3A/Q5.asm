INCLUDE Irvine32.inc

.data
; An Array of 3 words (16-bit integer) with Initia; Value
Var1 WORD 1234h, 0A3EFh, 87FAh	;	Initialized Array of 3 elements

.code
main PROC
mov ecx, LENGTHOF Var1		; Setting Loop Counter to No.of Elements
mov esi, OFFSET Var1			; ESI points to the start of Array

mov ebx, 0

PrintArrayLoop:
	movzx eax, WORD PTR [esi]	; Move the byte value pointed by ESI into EAX register
	call WriteHex				; Print the value in the array
	mov al, ' '					; Storing a space character inside AL register
	call WriteChar				; Printing space after each value

	add esi, TYPE Var1			; Move to next element (adding 2 bytes, as DWORD occupies 2 space)

	loop PrintArrayLoop			; Repeat Until ecx is 0

exit
main ENDP
END main
