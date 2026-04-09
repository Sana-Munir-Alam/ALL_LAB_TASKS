INCLUDE Irvine32.inc

.data
; EQUATION => -(Xval + Yval - Zval)
Xval DWORD 25
Yval DWORD 15
Zval DWORD 40
Rval SDWORD ?

.code
main PROC
	mov eax, Xval	; EAX = Xval	=> EAX = 25
	mov ebx, Yval	; EBX = Yval	=> EBX = 15
	mov ecx, Zval	; ECX = Zval	=> ECX = 40

	add eax, ebx	; EAX = EAX + EBX	=> EAX = 25 + 15
	sub eax, Zval	; EAX = EAX - ECX	=> EAX = 40 - 40
	NEG eax;		; -(Xval + Yval - Zval)
	mov Rval, eax

	call WriteHex
exit
main ENDP
END main
