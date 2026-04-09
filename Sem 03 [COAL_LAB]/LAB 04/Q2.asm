INCLUDE Irvine32.inc

.data
	num1 BYTE 25		; Initialized Variable with decimal Value 25
	num2 WORD 1200h		; Initialised Variable with hexa value 1200
	num3 DWORD ?		; Uninitialised Variable

.code
main PROC

	mov AL, num1		; Storing 1 BYTE value in a 1 BYTE register
	mov AX, num2		; Storing 2 BYTE Value in a 2 BYTE register AX = AH:AL
	movzx eax, AX
	mov num3, eax
	call WriteHex

exit
main ENDP
END main
