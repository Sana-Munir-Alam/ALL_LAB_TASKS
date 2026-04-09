INCLUDE Irvine32.inc

.data
PromptMsg BYTE "Enter a number: ",0
PrimeMsg BYTE " is prime",0
NotPrimeMsg BYTE " is not prime",0
AllPrimeMsg BYTE "All numbers are prime. Finding largest prime...",0
NotAllPrimeMsg BYTE "Not all numbers are prime.",0
LargestPrimeMsg BYTE "Largest prime number is: ",0
NumbersArray DWORD 4 DUP(?)
IsPrimeArray BYTE 4 DUP(0)

.code
Main PROC
    mov ecx, 4
    mov esi, OFFSET NumbersArray
    InputLoop:
        mov edx, OFFSET PromptMsg
        call WriteString
        call ReadInt
        mov [esi], eax
        add esi, 4
        loop InputLoop
    call Crlf

    ; Check if each number is prime
    mov ecx, 4
    mov esi, OFFSET NumbersArray
    mov edi, OFFSET IsPrimeArray
    mov ebx, 0  ; Count of prime numbers

    CheckPrimeLoop:
        push [esi]          ; Push number to check
        call CheckPrime
        add esp, 4
    
        mov [edi], al       ; Store result (1=prime, 0=not prime)
        cmp al, 1
        jne NotPrimeDisplay
    
        ; Display prime message
        mov eax, [esi]
        call WriteDec
        mov edx, OFFSET PrimeMsg
        call WriteString
        call Crlf
        inc ebx
        jmp ContinueLoop
    
    NotPrimeDisplay:
        ; Display not prime message
        mov eax, [esi]
        call WriteDec
        mov edx, OFFSET NotPrimeMsg
        call WriteString
        call Crlf
    
    ContinueLoop:
        add esi, 4
        inc edi
        loop CheckPrimeLoop
    call Crlf

    ; Check if all numbers are prime
    cmp ebx, 4
    jne NotAllPrime
    
    ; All numbers are prime - find largest
    mov edx, OFFSET AllPrimeMsg
    call WriteString
    call Crlf
    
    push OFFSET NumbersArray
    call LargestPrime
    add esp, 4
    jmp ExitProgram
    
NotAllPrime:
    mov edx, OFFSET NotAllPrimeMsg
    call WriteString
    call Crlf

ExitProgram:
    INVOKE ExitProcess, 0
Main ENDP

; CheckPrime Procedure
CheckPrime PROC
    push ebp
    mov ebp, esp
    push ebx
    push ecx
    push edx
    
    mov eax, [ebp + 8]  ; Get the number
    cmp eax, 2
    jl NotPrime         ; Numbers less than 2 are not prime
    je IsPrime          ; 2 is prime
    
    ; Check if even (except 2)
    test eax, 1
    jz NotPrime
    
    ; Check divisors from 3 to sqrt(n)
    mov ebx, 3          ; Start divisor
    mov ecx, eax        ; Store original number
    
PrimeTestLoop:
    mov eax, ecx        ; Restore original number
    xor edx, edx
    div ebx
    cmp edx, 0
    je NotPrime         ; Found a divisor
    
    ; Check if we've tested enough divisors
    mov eax, ebx
    mul ebx
    cmp eax, ecx
    jg IsPrime          ; No divisors found
    
    add ebx, 2          ; Next odd divisor
    jmp PrimeTestLoop

IsPrime:
    mov al, 1
    jmp CheckPrimeDone

NotPrime:
    mov al, 0

CheckPrimeDone:
    pop edx
    pop ecx
    pop ebx
    pop ebp
    ret
CheckPrime ENDP

; LargestPrime Procedure
LargestPrime PROC
    push ebp
    mov ebp, esp
    push esi
    push ecx
    
    mov esi, [ebp + 8]  ; Array address
    mov eax, [esi]      ; Assume first is largest
    mov ecx, 3          ; Check remaining 3 numbers
    
FindLargestLoop:
    add esi, 4
    mov ebx, [esi]
    cmp ebx, eax
    jle ContinueSearch
    mov eax, ebx        ; New largest found
    ContinueSearch:
        loop FindLargestLoop
    
    mov edx, OFFSET LargestPrimeMsg
    call WriteString
    call WriteDec
    call Crlf
    
    pop ecx
    pop esi
    pop ebp
    ret
LargestPrime ENDP
END Main
