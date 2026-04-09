INCLUDE Irvine32.inc

.data
; 95 – 31 + 240 – 125.
counter DD ?
Var1 DWORD 95
Var2 DWORD 31
Var3 DWORD 240
Var4 DWORD 125

.code
main PROC

mov eax, Var1
mov ebx, Var2

sub eax, ebx ;  95 - 31
add eax, Var3 ;  [95 - 31] + 240
add eax, Var4 ;  [95 - 31 + 240] - 125
mov counter, eax
call WriteInt

exit
main ENDP
END main
