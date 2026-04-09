INCLUDE Irvine32.inc

; SYMBOLIC CONSTANTS
MAX = 100
MIN EQU 10

.data
Var1 DWORD MAX	; Initialising Var1 with constant MAX
Var2 DWORD MIN	; Initialising Var2 with constant MIN
FinalResult DWORD ?

.code
main PROC
	mov eax, Var1	; EAX = Var1	=> EAX = 100
	mov ebx, Var2	; EBX = Var2	=> EBX = 10
	add eax, ebx	; EAX = EAX + EBX
	mov FinalResult, eax

	call WriteInt
exit
main ENDP
END main
