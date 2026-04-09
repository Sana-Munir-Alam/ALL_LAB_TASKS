INCLUDE Irvine32.inc

.data
msgInput BYTE "Enter number for factorial: ",0
msgResult BYTE "Factorial is: ",0
n DWORD 5

.code
main PROC
    mov edx, OFFSET msgInput
    call WriteString
    call ReadInt
    
    push eax
    call Fact
    add esp, 4
    
    mov edx, OFFSET msgResult
    call WriteString
    call WriteDec
    exit
main ENDP

Fact PROC
    push ebp
    mov ebp, esp
    mov eax, [ebp + 8]   ; get n
    
    cmp eax, 1           ; Base case: if n <= 1, return 1
    jle base_case
    
    ; Recursive case: n * fact(n-1)
    dec eax
    push eax
    call Fact
    add esp, 4
    
    mov ebx, [ebp + 8]   ; get original n
    mul ebx              ; eax = n * fact(n-1)
    jmp done
    
    base_case:
        mov eax, 1
    done:
        pop ebp
        ret
Fact ENDP
END main
