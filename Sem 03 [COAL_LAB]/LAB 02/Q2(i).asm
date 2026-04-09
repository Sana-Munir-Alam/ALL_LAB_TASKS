INCLUDE Irvine32.inc

.data
; edx = eax + 3 + ebx – ecx + 12h – 45o + 89d
counter DD ?
Var1 DWORD 0Ah	; Assuming Value for eax register
Var2 DWORD 3
Var3 DWORD 12o	; Assuming Value for ebx register
Var4 DWORD 110b	; Assuming Value for ecx register
Var5 DWORD 12h
Var6 DWORD 45o
Var7 DWORD 89

.code
main PROC

mov eax, Var1	; Storing 0Ah in eax
mov ebx, Var3	; Storing 12o in ebx
mov ecx, Var4	; Storing 110b in ecx

mov edx, eax	; edx = [0Ah]
add edx, Var2	; edx = [0Ah] + 3
add edx, ebx	; edx = [0Ah + 3] + 12o
sub edx, ecx	; edx = [0Ah + 3 + 12o] - 110b
add edx, Var5	; edx = [0Ah + 3 + 12o - 110b] + 12h
sub edx, Var6	; edx = [0Ah + 3 + 12o - 110b + 12h] - 45o
add edx, Var7	; edx = [0Ah + 3 + 12o - 110b + 12h - 45o] + 89

; Storing the calculated value in register eax for it to be printed
mov eax, edx
mov counter, eax
call WriteInt

exit
main ENDP
END main
