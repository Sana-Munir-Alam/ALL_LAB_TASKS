INCLUDE Irvine32.inc

.data
    prompt BYTE "Enter number for factorial: ",0
    resultMsg BYTE "Factorial is: ",0
    timeMsg1 BYTE "Recursive time (ms): ",0
    timeMsg2 BYTE "Iterative time (ms): ",0
    n DWORD 12

.code
main PROC
    mov edx, OFFSET prompt
    call WriteString
    call ReadInt
    mov n, eax
    
    call GetMSeconds        ; Test recursive factorial with timing
    push eax
    push n
    call FactRecursive
    add esp, 4              ; Clean Stack
    
    call GetMSeconds
    pop ebx
    sub eax, ebx
    
    mov edx, OFFSET timeMsg1
    call WriteString
    call WriteDec
    call Crlf
    
    
    call GetMSeconds        ; Test iterative factorial with timing
    push eax
    push n
    call FactIterative
    add esp, 4
    
    call GetMSeconds
    pop ebx
    sub eax, ebx
    
    mov edx, OFFSET timeMsg2
    call WriteString
    call WriteDec
    exit
main ENDP

FactRecursive PROC
    push ebp
    mov ebp, esp
    mov eax, [ebp + 8]
    
    cmp eax, 1      ; Base Case
    jle base_case
    
    dec eax         ; Recursive Case
    push eax
    call FactRecursive
    add esp, 4
    
    mov ebx, [ebp + 8]
    mul ebx
    jmp done
    
    base_case:
        mov eax, 1
    done:
        pop ebp
        ret
FactRecursive ENDP

FactIterative PROC
    push ebp
    mov ebp, esp
    mov ecx, [ebp + 8]   ; n
    mov eax, 1           ; result
    
    cmp ecx, 0
    je done
    
    fact_loop:
        mul ecx
        loop fact_loop
    done:
        pop ebp
        call WriteDec
        call Crlf
        ret
FactIterative ENDP
END main
