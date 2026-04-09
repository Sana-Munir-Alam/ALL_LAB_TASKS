INCLUDE Irvine32.inc

.data
Var1 SBYTE -50
Var2 BYTE 200

.code
main PROC
	movzx eax, Var2		; Moving Var2 into a 32 bit register
	movsx ebx, Var1		; Moving Var1 into a 32 bit register

	call DumpRegs
exit
main ENDP
END main
