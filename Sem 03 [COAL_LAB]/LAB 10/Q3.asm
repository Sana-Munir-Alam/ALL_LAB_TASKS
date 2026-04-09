INCLUDE Irvine32.inc

.data
array DWORD 45, 12, 67, 89, 34, 23, 90, 11, 56, 78, 2, 45, 99, 3, 67, 88, 15, 42, 76, 31
arraySize = 20
minMsg BYTE "Minimum value: ",0
maxMsg BYTE "Maximum value: ",0

.code
main PROC
    push OFFSET array
    push arraySize
    call MinMaxArray
    add esp, 8
    exit
main ENDP

MinMaxArray PROC
    push ebp
    mov ebp, esp
    pushad
    mov esi, [ebp + 12]  ; array address
    mov ecx, [ebp + 8]   ; array size
    mov eax, [esi]       ; initialize min with first element
    mov ebx, [esi]       ; initialize max with first element
    add esi, 4
    dec ecx
    
FindLoop:
    mov edx, [esi]
    cmp edx, eax
    jge CheckMax
    mov eax, edx         ; new minimum
    jmp NextElement
    CheckMax:
        cmp edx, ebx
        jle NextElement
        mov ebx, edx         ; new maximum
    NextElement:
        add esi, 4
        loop FindLoop
   
    mov edx, OFFSET minMsg
    call WriteString
    call WriteDec
    call Crlf
    
    mov edx, OFFSET maxMsg
    mov eax, ebx
    call WriteString
    call WriteDec
    
    popad
    pop ebp
    ret
MinMaxArray ENDP
END main
