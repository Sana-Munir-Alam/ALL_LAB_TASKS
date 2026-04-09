INCLUDE Irvine32.inc

.data
; 11010110b – 9C4h + 220 + 18 + 1011110b – D + 12.
counter DD ?
Var1 DWORD 11010110b
Var2 DWORD 9C4h
Var3 DWORD 220
Var4 DWORD 18
Var5 DWORD 1011110b
Var6 DWORD 0Dh
Var7 DWORD 12


.code
main PROC

mov eax, Var1
mov ebx, Var2

sub eax, ebx ;  11010110b – 9C4h
add eax, Var3 ;  [11010110b – 9C4h] + 220
add eax, Var4 ;  [11010110b – 9C4h + 220] + 18
add eax, Var5 ;  [11010110b – 9C4h + 220 + 18] + 1011110b
sub eax, Var6 ;  [11010110b – 9C4h + 220 + 18 + 1011110] - D
add eax, Var7 ;  [11010110b – 9C4h + 220 + 18 + 1011110b – D] + 12
mov counter, eax
call WriteInt

exit
main ENDP
END main
