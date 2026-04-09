INCLUDE Irvine32.inc

.data
	; Rval = Xval * (Yval - Zval);
	Rval SDWORD ?
	Xval SDWORD 26
	Yval SDWORD 30
	Zval SDWORD 40

.code
main PROC
	mov eax, Xval			; EAX = Xval
	mov ebx, Yval			; EBX = Yval
	mov ecx, Zval			; ECX = Zval
	sub ebx , ecx			; EBX = Yval -Zval
	imul ebx				; EAX = EAX * EBX
	call WriteInt			; EAX = 26 * (30-40) = -260

exit
main ENDP
END main
