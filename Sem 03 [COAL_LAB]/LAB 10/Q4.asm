INCLUDE Irvine32.inc

.data
msgInput BYTE "Enter a number: ",0
resultMsg BYTE "Square is: ",0

.code
main PROC
    Call LocalSquare
    exit
main ENDP

LocalSquare PROC
    ENTER 4, 0           ; allocate 4 bytes for local variable
    mov edx, OFFSET msgInput
    call WriteString
    call ReadInt
    
    ; Store in local variable
    mov [ebp - 4], eax
    
    ; Calculate and display square
    mul eax
    mov edx, OFFSET resultMsg
    call WriteString
    call WriteDec
    call Crlf
    
    LEAVE                ; deallocate local variable
    ret
LocalSquare ENDP
END main
