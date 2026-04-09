INCLUDE Irvine32.inc

.data
var1 DWORD 5
var2 DWORD 6
msg BYTE "The sum of the two numbers is: ", 0

.code
main PROC

	call AddTwo
	mov edx, OFFSET msg
	call WriteString
	call WriteDec
	call Crlf
	exit

main ENDP

AddTwo PROC
	mov eax, var1
	add eax, var2
	ret
AddTwo ENDP
END main
