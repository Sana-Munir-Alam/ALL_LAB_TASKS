INCLUDE Irvine32.inc

.data
prompt      BYTE "Enter a number: ", 0
resultMsg   BYTE "Factorial: ", 0

.code
main PROC
    mov edx, OFFSET prompt       ; Get input from user prompt
    call WriteString
    call ReadInt                 ; Read number into EAX
    
    cmp eax, 0                  ; Validate input (factorial defined for n >= 0)
    jl done                     ; If negative, exit
    je zero_case                ; If zero, handle specially
    
    ; Push parameters for recursive factorial
    push eax                    ; Push n onto stack
    call Factorial              ; Call factorial function
    add esp, 4                  ; Clean stack
    jmp display_result
    
    zero_case:
        mov eax, 1                  ; 0! = 1
    
    display_result:
        mov edx, OFFSET resultMsg
        call WriteString
        call WriteDec               ; Display result
    done:
        exit
main ENDP

; Factorial procedure (uses stack for recursion)
; Input: [ebp+8] = n
; Output: EAX = n!
Factorial PROC
    push ebp
    mov ebp, esp
    mov eax, [ebp+8]           ; Get n from stack
    
    cmp eax, 1                 ; Base case: if n == 1, return 1
    jle base_case
    
    ; Recursive case: n * factorial(n-1)
    dec eax                    ; n-1
    push eax                   ; Push n-1 as parameter
    call Factorial             ; Recursive call
    add esp, 4                 ; Clean stack
    
    ; Multiply result by n
    mov ebx, [ebp+8]           ; Get original n
    mul ebx                    ; EAX = EAX * EBX (result * n)
    jmp done_factorial
    
    base_case:
        mov eax, 1                 ; Return 1 for base case
    
    done_factorial:
        pop ebp
        ret
Factorial ENDP
END main
