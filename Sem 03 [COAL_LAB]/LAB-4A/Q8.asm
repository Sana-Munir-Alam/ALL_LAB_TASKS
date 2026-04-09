INCLUDE Irvine32.inc

.data
msg1 BYTE "Before swap - AX: ", 0
msg2 BYTE ", BX: ", 0
msg3 BYTE "After swap - AX: ", 0

.code
main PROC
    
    mov ax, 10      ; Initialize Register AX = 10
    mov bx, 20      ; Initialize Register BX = 20
    
    mov edx, OFFSET msg1    ; Store Before Swap Message
    call WriteString        ; Print the Message
    movzx eax, ax           ; Storing the Original AX Value to be Printed through EAX
    call WriteDec           ; Printing AX value

    mov edx, OFFSET msg2    ; Store Before Swap Message
    call WriteString        ; Print the Message
    movzx eax, bx           ; Storing the Original BX Value to be Printed through EAX
    call WriteDec           ; Printing EAX value
    call Crlf               ; Print New Line
    
    xchg ax, bx             ; Swap using XCHG
    
    mov edx, OFFSET msg3    ; Store After Swap Message of AX register
    call WriteString        ; Print the Message
    movzx eax, ax           ; Storing the Swapped AX Value to be Printed through EAX
    call WriteDec           ; Printing EAX value

    mov edx, OFFSET msg2    ; Store After Swap Message of BX register
    call WriteString        ; Print the Message
    movzx eax, bx           ; Storing the Swapped BX Value to be Printed through EAX
    call WriteDec           ; Printing EAX value
    call Crlf               ; Print New Line
    
    exit
main ENDP
END main
