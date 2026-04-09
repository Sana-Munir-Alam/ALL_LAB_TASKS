INCLUDE Irvine32.inc

.data
msgInitial  BYTE "Starting value: EAX = 10", 0
msgLoop     BYTE "After subtraction: EAX = ", 0
msgFinal    BYTE "Loop ended. Final value of EAX = ", 0
msgCondition BYTE " (Condition: EAX >= 0)", 0
newline     BYTE 0Dh, 0Ah, 0
dash        BYTE " -> ", 0

.code
main PROC
    mov eax, 10                 ; Initialize EAX = 10
    mov edx, OFFSET msgInitial  ; Display starting message
    call WriteString
    call Crlf
    call Crlf
    
    ; =============================================
    ; WHILE LOOP SIMULATION
    ; while (eax >= 0) {
    ;     eax = eax - 3;
    ; }
    ; =============================================
    
    WhileLoop:
        sub eax, 3                 ; Subtract 3 from EAX
        mov edx, OFFSET msgLoop    ; Display current value after subtraction
        call WriteString
        call WriteInt
        mov edx, OFFSET msgCondition
        call WriteString
        call Crlf
    
        cmp eax, 0                  ; Check loop condition: while (eax >= 0)
        jge WhileLoop               ; Jump back to WhileLoop if eax >= 0
      
    call Crlf
    mov edx, OFFSET msgFinal    ; Display final result
    call WriteString
    call WriteInt
    call Crlf
    
    exit
main ENDP
END main
