INCLUDE Irvine32.inc

.data
bArray BYTE 10 DUP (0)	;	An array of 10 bytes, all initialised to 0

.code
main PROC

mov ecx, LENGTHOF bArray		; Setting Loop Counter to No.of Elements
mov esi, OFFSET bArray			; ESI points to the start of Array

mov ebx, 0

PrintArrayLoop:
	movzx eax, BYTE PTR [esi]	; Move the byte value pointed by ESI into EAX register
	call WriteDec				; Print the value in the array
	mov al, ' '					; Storing a space character inside AL register
	call WriteChar				; Printing space after each value

	inc esi						; Move to next element
	call DumpRegs

	loop PrintArrayLoop			; Repeat Until ecx is 0

exit
main ENDP
END main
