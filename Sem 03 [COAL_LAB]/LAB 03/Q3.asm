INCLUDE Irvine32.inc

.data
Num1 DWORD 500	;	Declare a variable named num1 initialized with 500.
Num2 DWORD 200	;	Declare another variable named num2 initialized with 200.

.code
main PROC

mov eax, Num1	; Moving Num1 variable to EAX register
mov ebx, Num2	; Moving Num2 variable to EBX register
add eax, ebx	; EAX = EAX + EBX	=> EAX = Num1 + Num2	=> EAX = 500 + 200

call WriteInt	; Printing EAX Value [Answer is to be 700]

exit
main ENDP
END main
