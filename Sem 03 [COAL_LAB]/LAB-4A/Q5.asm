INCLUDE Irvine32.inc

.data
VarSigned SBYTE -10
VarUnsigned BYTE 10
Result1 SWORD ?
Result2 WORD ?
msg1 BYTE "Original signed byte: ", 0
msg2 BYTE "After MOVSX (sign-extended): ", 0
msg3 BYTE "Original unsigned byte: ", 0
msg4 BYTE "After MOVZX (zero-extended): ", 0

.code
main PROC
    
    movsx ax, VarSigned     ; Sign extension with MOVSX to WORD size
    mov Result1, ax
    movzx ax, VarUnsigned   ; Zero extension with MOVZX to WORD size
    mov Result2, ax
    
    mov edx, OFFSET msg1    
    call WriteString        ; Display Original Signed Var
    movsx eax, VarSigned    ; Sign extension with MOVSX to DWORD size in order to print
    call WriteHex
    call Crlf               ; Print new line
    
    mov edx, OFFSET msg2    
    call WriteString        ; Display the Extended Signed Var using Result 1
    movsx eax, Result1      ; Sign extension with MOVSX to DWORD size in order to print
    call WriteHex
    call Crlf               ; Print new line
    
    mov edx, OFFSET msg3
    call WriteString        ; Display Original Signed Var
    movzx eax, VarUnsigned  ; Sign extension with MOVSX to DWORD size in order to print
    call WriteHex
    call Crlf               ; Print new line
    
    mov edx, OFFSET msg4
    call WriteString        ; Display the Extended Unsigned Var using Result 2
    movzx eax, Result2      ; Sign extension with MOVSX to DWORD size in order to print
    call WriteHex
    call Crlf               ; Print new line
    
    exit
main ENDP
END main
