INCLUDE Irvine32.inc

.data
uArray WORD 20 DUP (5)	; Array of 20 unsigned Words all initialised by the value 5

.code
main PROC

mov ecx, LENGTHOF uArray	; Setting Loop Counter to No.of Elements
mov esi, OFFSET uArray		; ESI points to the first value in the array
mov ebx, 0

uArrayLoop:
	movzx eax, WORD PTR [esi]	; Move the value pointed by ESI to EAX register
	call WriteDec				; Print the cuurent value
	mov al, ' '					; Storing a space character isnide AL register
	call WriteChar				; Printing the Space Character

	add esi, TYPE uArray		; Move to next element (adding 2 bytes, ad WORD occupies 2 bytes)
	loop uArrayLoop				; Repeat until ECS is 0

exit
main ENDP
END main
