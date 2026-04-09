INCLUDE Irvine32.inc

.data
; 101110 (binary) + 50Ah (hex) + 67d (decimal) + 1010001 (binary) + F (hex).
counter DD ?
Var1 DWORD 101110b
Var2 DWORD 50Ah
Var3 DWORD 67
Var4 DWORD 1010001b
Var5 DWORD 0Fh

.code
main PROC

mov eax, Var1
mov ebx, Var2

add eax, ebx ;  [101110 + 50A]
add eax, Var3 ;  [101110 + 50A] + 67
add eax, Var4 ;  [101110 + 50A + 67] + 1010001
add eax, Var5 ;  [101110 + 50A + 67 + 1010001] + F
mov counter, eax
call WriteInt

exit
main ENDP
END main
