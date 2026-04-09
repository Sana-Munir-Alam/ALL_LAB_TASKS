INCLUDE Irvine32.inc

.data
Value BYTE 10
msg1 BYTE "Value: ", 0
msg2 BYTE "After 3 Increments: ", 0
msg3 BYTE "After 2 Decrements: ", 0

.code
main PROC
    
    mov edx, OFFSET msg1
    call WriteString        ; Display initial Value
    movzx eax, Value        ; Moving Value to EAX to be printed
    call WriteDec
    call Crlf               ; Print New Line
    
    mov al, Value
    inc al                  ; Increment 3 times
    inc al
    inc al
    mov Value, al
    
    mov edx, OFFSET msg2
    call WriteString        ; Display 3 Times INCREMNETED Value
    movzx eax, Value        ; Moving Value to EAX to be printed
    call WriteDec
    call Crlf               ; Print New Line
    
    mov al, Value
    dec al                  ; Decrement 2 times
    dec al
    mov Value, al
    
    mov edx, OFFSET msg3
    call WriteString        ; Display 2 Times Decremented Value
    movzx eax, Value        ; Moving Value to EAX to be printed
    call WriteDec
    call Crlf               ; Print New Line
    
    mov edx, OFFSET msg1
    call WriteString        ; Display Final Value
    movzx eax, Value        ; Moving Value to EAX to be printed
    call WriteDec
    call Crlf               ; Print New Line
    
    exit
main ENDP
END main
