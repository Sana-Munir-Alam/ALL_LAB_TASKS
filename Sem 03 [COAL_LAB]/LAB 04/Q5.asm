INCLUDE Irvine32.inc

; SYMBOLIC CONSTANT
x = 12h
y = 14h
z = 5h
w = 10h

.data
; EQUATION => EDX = (x+y) - (z+w)
FinalResult DWORD ?

.code
main PROC

	mov eax, x
	mov ebx, y
	add eax, ebx	; EAX = EAX + EBX	=> EAX = x+y

	mov ecx, z
	mov edx, w
	add ecx, edx	; ECX = ECX + EDX	=> ECX = z+w

	sub eax, ecx	; EAX = EAX - ECX	=> EAX = (x+y) - (z+w)
	mov edx, eax
	mov FinalResult, eax
	Call WriteHex
exit
main ENDP
END main
