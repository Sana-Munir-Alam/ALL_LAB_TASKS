INCLUDE Irvine32.inc

.data
A WORD 0FF10h      ; Variable A
B WORD 0E10Bh      ; Variable B
msg1 BYTE "Before swap - A: ", 0
msg2 BYTE ", B: ", 0
msg3 BYTE "After swap - A: ", 0

.code
main PROC

    mov edx, OFFSET msg1    ; Store Before Swap Message
    call WriteString        ; Print the Message
    mov ax, A               ; AX = A
    movzx eax, ax           ; Storing the Original AX Value to be Printed through EAX
    call WriteHex           ; Printing EAX value
    
    mov edx, OFFSET msg2    ; Store Before Swap Message
    call WriteString        ; Print the Message
    mov ax, B               ; AX = B
    movzx eax, ax           ; Storing the Original AX Value to be Printed through EAX
    call WriteHex           ; Printing EAX value
    call Crlf
    
    ; Swap the actual variables
    mov ax, A               ; Sore A in AX
    xchg ax, B              ; Exchange A and B now AX = B and B = A value
    mov A, ax               ; A = B value
    
    mov edx, OFFSET msg3    ; Store Before Swap Message
    call WriteString        ; Print the Message
    mov ax, A               ; AX = A
    movzx eax, ax           ; Storing the Original AX Value to be Printed through EAX
    call WriteHex           ; Printing EAX = A value
    
    mov edx, OFFSET msg2    ; Store Before Swap Message
    call WriteString        ; Print the Message
    mov ax, B               ; AX = B
    movzx eax, ax           ; Storing the Original AX Value to be Printed through EAX
    call WriteHex           ; Printing EAX = B value
    call Crlf

    exit
main ENDP
END main
