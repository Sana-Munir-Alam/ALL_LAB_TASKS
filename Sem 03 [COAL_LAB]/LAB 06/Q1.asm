INCLUDE Irvine32.inc

.data
msgFirst BYTE "Welcome", 0
msgSecond BYTE "You should not see this line", 0
msgThird BYTE "Goodbye", 0

.code
main PROC
    
    mov edx, OFFSET msgFirst    ; Store the First Message to be printed in EDX
    call WriteString
    call Crlf

    ; Unconditional jump to skip the second message
    jmp JumpSkippedMessage
    
    ; This code will be skipped for Second Message
    mov edx, OFFSET msgSecond
    call WriteString
    call Crlf
    
    JumpSkippedMessage:
        mov edx, OFFSET msgThird    ; Store the Third Message to be printed in EDX
        call WriteString
        call Crlf

    exit
main ENDP
END main
