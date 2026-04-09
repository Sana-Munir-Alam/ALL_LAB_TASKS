INCLUDE Irvine32.inc

.code
main PROC

mov ebx, 90			; EBX = 90
add ebx, 5Ah		; EBX = 90 + 5Ah
add ebx, 01011010b	; EBX = 90 + 5Ah + 01011010b
add ebx, 66			; EBX = 90 + 5Ah + 01011010b + 66	=> B = 66

call DumpRegs		; Display registers [EBX should show 150H which is 336 decimal]

exit
main ENDP
END main
