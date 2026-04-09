INCLUDE Irvine32.inc

; SYMBOLIC CONSTANT
PI = 3      ; Declaring a PI constant

.data
msg1 BYTE "PI * 4 =: ", 0

.code
main PROC
    
    mov eax, PI         ; Storing Constant in EAX
    imul eax, 4         ; EAX = EAX * 4

    mov edx, OFFSET msg1
    call WriteString        ; Display the message Product of PI * 4
    call WriteDec           ; Print Value
    call Crlf               ; Print New Line
    
    exit
main ENDP
END main
