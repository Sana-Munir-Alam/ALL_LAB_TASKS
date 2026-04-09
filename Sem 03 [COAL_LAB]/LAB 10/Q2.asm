INCLUDE Irvine32.inc

.data
msg1 BYTE "Enter first number: ",0
msg2 BYTE "Enter second number: ",0
gcdResult BYTE "GCD is: ",0
espMsg BYTE "ESP: ",0

.code
main PROC
    call TakeInput
    exit
main ENDP

TakeInput PROC
    ; Display ESP before procedure calls
    mov edx, OFFSET espMsg
    call WriteString
    mov eax, esp
    call WriteHex
    call Crlf
    
    ; First number Input
    mov edx, OFFSET msg1
    call WriteString
    call ReadInt
    push eax                    ; Store in Stack
    
    ; Second Number Input
    mov edx, OFFSET msg2
    call WriteString
    call ReadInt
    push eax                    ; Store in Stack
    
    ; Display ESP before GCD call
    mov edx, OFFSET espMsg
    call WriteString
    mov eax, esp
    call WriteHex
    call Crlf
    
    call GCD                    ; Calling Procedure
    ret
TakeInput ENDP

GCD PROC
    mov edx, OFFSET espMsg
    call WriteString
    mov eax, esp
    call WriteHex
    call Crlf
    
    push ebp
    mov ebp, esp
    
    mov edx, OFFSET espMsg
    call WriteString
    mov eax, esp
    call WriteHex
    call Crlf
    
    mov eax, [ebp + 12]         ; first number
    mov ebx, [ebp + 8]          ; second number
    
    
    test eax, eax               ; Ensure positive numbers
    jns check_second
    neg eax
    check_second:
        test ebx, ebx
        jns GCDLoop
        neg ebx
    
    GCDLoop:
        cmp ebx, 0
        je GCD_Done
        xor edx, edx
        div ebx
        mov eax, ebx
        mov ebx, edx
        jmp GCDLoop
    
    GCD_Done:
        push eax
        mov edx, OFFSET espMsg      ; Display ESP before Display call
        call WriteString
        mov eax, esp
        call WriteHex
        call Crlf
        pop eax
    
        call Display
        pop ebp
        ret 8                       ; GCD cleans its own parameters
GCD ENDP

Display PROC
    push eax                    ; Save result
    mov edx, OFFSET espMsg
    call WriteString
    mov eax, esp
    call WriteHex
    call Crlf
    pop eax                     ; Restore result
    
    mov edx, OFFSET gcdResult
    call WriteString
    call WriteDec
    call Crlf
    ret
Display ENDP
END main
