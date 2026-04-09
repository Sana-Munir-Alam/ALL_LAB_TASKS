INCLUDE Irvine32.inc

.data
; ebx = 6F1h – eax + 92d + 47o – 11011001b + 6Ch
counter DD ?
Var1 DWORD 6F1h
Var2 DWORD 1010b	; Assuming Value for eax register
Var3 DWORD 92
Var4 DWORD 47o
Var5 DWORD 11011001b
Var6 DWORD 6Ch

.code
main PROC

mov eax, Var2	; Storing 1010b in eax

mov ebx, Var1	; ebx = [6F1h]
sub ebx, eax	; ebx = [6F1h] - 1010b
add ebx, Var3	; ebx = [6F1h - 1010b] + 92
add ebx, Var4	; ebx = [6F1h - 1010b + 92] + 47o
sub ebx, Var5	; ebx = [6F1h - 1010b + 92 + 47o] - 11011001b
add ebx, Var6	; ebx = [6F1h - 1010b + 92 + 47o - 11011001b] + 6Ch

; Storing the calculated value in eax register for it to be printed
mov eax, ebx
call WriteInt

exit
main ENDP
END main
