INCLUDE Irvine32.inc

.data
; SIMPLIFYING THE EQUATION
; ebx = { (a+b) - (a-b) + c} + d
; ebx = { (2*b) + c} + d

a DWORD 10h
b DWORD 12h
VarC DWORD 20h
d DWORD 25h

.code
main PROC

; Calculating eax = (a+b)
mov eax, a	; ebx = 10h
add eax, b	; ebx = [10h] + 12h

; Calculating ebx = (a-b)
mov ebx, a	; ebx = 10h
sub ebx, b	; ebx = [10h] - 12h

; Calculating ebx = { (a+b) - (a-b) }
sub eax, ebx	; eax = [10h + 12h] - [10h - 12h]
mov ebx, eax	; Storing result back to ebx register

; Calculating ebx = ebx + c + d
add ebx, VarC	; ebx = { [10h + 12h] - [10h - 12h] } + 20h
add ebx, d	; ebx = { [10h + 12h] - [10h - 12h] + 20h } + 25h

call DumpRegs	; The final output for Register EBX should be 69h

exit
main ENDP
END main
