INCLUDE Irvine32.inc

.data
num1 WORD 1234h
num2 WORD 5678h

.code
main PROC
	mov AX, num1	; AX = num1
	mov BX, num2	; BX = num2
	XCHG AX, BX		; Now AX= 5678h and BX = 1234h
	
	mov num1, AX	; Storing exchnaged value back in the variable
	mov num2, BX	; Storing exchnaged value back in the variable

	movzx eax, num1	; Moving to register to be printed
	movzx ebx, num2	; Moving to register to be printed

	call DumpRegs
exit
main ENDP
END main
