INCLUDE Irvine32.inc

.data
; ecx = 101011010110b + 3Ah – 64o + ebx – ecx + 5
Var1 DWORD 101011010110b
Var2 DWORD 3Ah
Var3 DWORD 64o
Var4 DWORD 27o		; Assuming Value for ebx register
Var5 DWORD 5

.code
main PROC

mov ebx, Var4	; Storing 27o in ebx

mov ecx, Var1	; ecx = [101011010110b]
add ecx, Var2	; ecx = [101011010110b] + 3Ah
sub ecx, Var3	; ecx = [101011010110b + 3Ah] - 64o
add ecx, ebx	; ecx = [101011010110b + 3Ah - 64o] + 27o
sub ecx, ecx	; ecx = [101011010110b + 3Ah - 64o + 27o] - [101011010110b + 3Ah - 64o + 27o]
add ecx, Var5	; ecx = [101011010110b + 3Ah - 64o + 27o - ECX] + 5

; Storing the calculated value in eax register for it to be printed
mov eax, ecx
call WriteInt

exit
main ENDP
END main
