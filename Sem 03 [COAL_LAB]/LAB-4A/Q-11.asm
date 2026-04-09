INCLUDE Irvine32.inc

.data
Val1 BYTE 10h
Val2 WORD 8000h
Val3 DWORD 0FFFFh
Val4 WORD 7FFFh

msg1 BYTE "After Incrementing Val2:          ", 0
msg2 BYTE "After Subtracting Val3 from EAX:  ", 0
msg3 BYTE "After Subtracting Val4 from Val2: ", 0
msg4 BYTE "Value of BL after moving Val1:    ", 0
.code
main PROC

    mov edx, OFFSET msg1    ; Store Incrementing Val2 Message
    call WriteString        ; Print the Message
    INC Val2                ; Incrementing Val2
    movzx eax, Val2         ; EAX = Val2
    call WriteHex           ; Printing EAX value
    call Crlf

    mov edx, OFFSET msg2    ; Store Subtraction Message
    call WriteString        ; Print the Message
    mov ebx, Val3           ; EBX = Val3
    sub eax, ebx            ; EAX = EAX - EBX   => EAX = Val2 - Val3
    call WriteHex           ; Printing EAX value
    call Crlf
    
    mov edx, OFFSET msg3    ; Store Subtraction Message
    call WriteString        ; Print the Message
    movzx eax, Val2         ; EAX = Val2
    movzx ebx, Val4         ; EBX = Val4
    sub eax, ebx            ; EAX = EAX - EBX   => EAX = Val2 - Val4
    call WriteHex           ; Printing EAX value
    call Crlf
    
    mov edx, OFFSET msg4    ; Store Val1 in BL register Message
    call WriteString        ; Print the Message
    mov bl, Val1            ; BL = Val1
    movzx eax, bl           ; Storing the Original BL Value to be Printed through EAX
    call WriteHex           ; Printing EAX = Val1 value
    call Crlf

    exit
main ENDP
END main
