INCLUDE Irvine32.inc

.data
; 111b – 12 + 1F3h – 745o.
counter DD ?
Var1 DWORD 111b
Var2 DWORD 12
Var3 DWORD 1F3h
Var4 DWORD 745o

.code
main PROC

mov eax, Var1
mov ebx, Var2

sub eax, ebx ;  [111b - 12]
add eax, Var3 ;  [111b - 12] + 1F3h
sub eax, Var4 ;  [111b - 12 + 1F3h] – 745o
mov counter, eax
call WriteInt

exit
main ENDP
END main
