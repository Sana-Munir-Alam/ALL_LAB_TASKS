INCLUDE Irvine32.inc

COUNT = 5		; Symbolic Constant Defination
LIMIT EQU 10	; Symbolic Constant Defination

.data
Result DWORD ?

.code
main PROC

	mov AX, COUNT	; Initialise AX with COUNT
	add AX, LIMIT	; ax = ax + limit
	INC AX			; Increments AX register by 1
	movzx eax, AX
	mov Result, eax

	Call WriteDec
exit
main ENDP
END main
