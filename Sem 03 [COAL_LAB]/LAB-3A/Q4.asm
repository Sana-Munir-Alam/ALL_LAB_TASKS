INCLUDE Irvine32.inc

.data
dArray DWORD 30 DUP (?)	;	Uninitialized Array of 30 DoubleWords

.code
main PROC
mov ecx, LENGTHOF dArray		; Setting Loop Counter to No.of Elements
mov esi, OFFSET dArray			; ESI points to the start of Array

mov ebx, 0

PrintArrayLoop:
	mov eax, DWORD PTR [esi]	; Move the byte value pointed by ESI into EAX register
	call WriteHex				; Print the value in the array
	mov al, ' '					; Storing a space character inside AL register
	call WriteChar				; Printing space after each value

	add esi, TYPE dArray		; Move to next element (adding 4 bytes, as DWORD occupies 4 space)
	;call DumpRegs

	loop PrintArrayLoop			; Repeat Until ecx is 0

exit
main ENDP
END main
