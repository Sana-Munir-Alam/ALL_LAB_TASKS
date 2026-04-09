INCLUDE Irvine32.inc

.data
; ecx = 101011010110b + 3Ah – 64o + ebx – ecx + 5
; FOR RIGHT HAND SIDE ecx I am assuming it as EDX for a moment
counter DD ?
Var1 DWORD 101011010110b
Var2 DWORD 3Ah
Var3 DWORD 64o
Var4 DWORD 27o		; Assuming Value for ebx register
Var5 DWORD 0110b	; Assuming Value for edx register
Var6 DWORD 5

.code
main PROC

mov ebx, Var4	; Storing 27o in ebx
mov edx, Var5	; Storing 0110b in edx

mov ecx, Var1	; ecx = [101011010110b]
add ecx, Var2	; ecx = [101011010110b] + 3Ah
sub ecx, Var3	; ecx = [101011010110b + 3Ah] - 64o
add ecx, ebx	; ecx = [101011010110b + 3Ah - 64o] + 27o
sub ecx, edx	; ecx = [101011010110b + 3Ah - 64o + 27o] - 0110b
add ecx, Var6	; ecx = [101011010110b + 3Ah - 64o + 27o - 0110b] + 5

; Storing the calculated value in eax register for it to be printed
mov eax, ecx
call WriteInt

exit
main ENDP
END main
