INCLUDE Irvine32.inc

.data
Var1 BYTE 200 DUP ("NUCES")	;	A string variable containing the word NUCES

.code
main PROC

mov edx, OFFSET Var1	; EDX points to the start of String
call WriteString		; Print the entire string

exit
main ENDP
END main
