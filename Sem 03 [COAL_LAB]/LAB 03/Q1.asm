INCLUDE Irvine32.inc

.data
Snum SDWORD -100	;	A signed BYTE variable snum initialized with -100.
Unum DWORD	200		;	An unsigned BYTE variable unum initialized with 200.
Holder DWORD ?		;	An uninitialized BYTE variable holder.

.code
main PROC

mov Holder, 0Ah		; Setting  value in Holder Variable
mov eax, Snum		; Storing SNUM value in EAX will give FFFFFF9C
mov ebx, Unum		; Storing UNUM value in EBX will give 000000C8
mov ecx, Holder		; Storing HOLDER value in ECX

call DumpRegs		; Display registers

exit
main ENDP
END main
