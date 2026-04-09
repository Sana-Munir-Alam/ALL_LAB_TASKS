INCLUDE Irvine32.inc

.data
; eax = 4C2h – ebx + 72o + 55d – 11101011b + 180
counter DD ?
Var1 DWORD 4C2h
Var2 DWORD 20		; Assuming Value for ebx register
Var3 DWORD 72o 
Var4 DWORD 55
Var5 DWORD 11101011b
Var6 DWORD 180

.code
main PROC

mov ebx, Var2	; Storing 20 in ebx

mov eax, Var1	; eax = [4C2h]
sub eax, ebx	; eax = [4C2h] - 20
add eax, Var3	; eax = [4C2h - 20] + 72o
add eax, Var4	; eax = [4C2h - 20 + 72o] + 55
sub eax, Var5	; eax = [4C2h - 20 + 72o + 55] - 11101011b
add eax, Var6	; eax = 4C2h - 20 + 72o + 55 - 11101011b] + 180

mov counter, eax
call WriteInt

exit
main ENDP
END main
