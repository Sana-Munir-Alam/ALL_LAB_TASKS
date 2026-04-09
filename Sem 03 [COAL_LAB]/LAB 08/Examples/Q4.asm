INCLUDE Irvine32.inc

.data
multp DWORD 2
msg BYTE "Hello Fastian! The product of the three integer is: ", 0

.code

main PROC
	
	mov eax, 1
	mov ecx, 3
	PushLoop:
		push multp
		add multp,2
		loop PushLoop
	
	mov ecx, 3
	MultiplyLoop:
		pop ebx
		mul ebx
		loop MultiplyLoop

	mov edx, OFFSET msg
	call WriteString
	call WriteDec
	call Crlf

	exit
main ENDP
END main
