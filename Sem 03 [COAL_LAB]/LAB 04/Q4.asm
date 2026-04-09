INCLUDE Irvine32.inc

.data
; EQUATION => valC = valA + valB - 5
valA SBYTE -15
valB BYTE 25
valC WORD ?

.code
main PROC
	movsx ax, valA	; AX = valA
	movzx bx, valB	; BX = valB
	add ax, bx		; AX = AX + BX
	sub ax, 5		; AX = AX - 5
	mov valC, ax	; valC = AX	=> valC = valA + valB - 5
	movsx eax, ax

	call WriteDec
exit
main ENDP
END main
