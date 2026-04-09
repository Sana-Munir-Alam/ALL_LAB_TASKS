INCLUDE Irvine32.inc

.data
; 25 , 47 , 88 , 64 , 120h ,and 27o. ADD THEM
; SUBTRACT THE TOTAL FROM 0Ah
counter DD ?
Var1 DWORD 25
Var2 DWORD 47
Var3 DWORD 88
Var4 DWORD 64
Var5 DWORD 120h
Var6 DWORD 27o
Var7 DWORD 0Ah

.code
main PROC

mov eax, Var1
mov ebx, Var2

add eax, ebx ;  25 + 47
add eax, Var3 ;  [25 + 47] + 88
add eax, Var4 ;  [25 + 47 + 88] + 64
add eax, Var5 ;  [25 + 47 + 88 + 64] + 120h
add eax, Var6 ;  [25 + 47 + 88 + 64 + 120h] + 27o
sub eax, Var7 ;  [25 + 47 + 88 + 64 + 120h + 27o] - oAh
mov counter, eax
call WriteInt

exit
main ENDP
END main
