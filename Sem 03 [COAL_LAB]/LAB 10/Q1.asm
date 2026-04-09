INCLUDE Irvine32.inc

.data
Num1 DWORD 5
Num2 DWORD 7
Num3 DWORD 3

.code
main PROC
    push Num3       ; Storing Variables
    push Num2
    push Num1
    call ThreeProd  ; Calling Procedure
    add esp, 12     ; Clear Stack
    
    exit
main ENDP

ThreeProd PROC
    push ebp            ; Storing EBP
    mov ebp, esp
    
    mov eax, [ebp + 8]   ; first parameter (+8 due to EBP and Return Address occuping initial space)
    mov ebx, [ebp + 12]  ; second parameter
    mul ebx              ; eax = Num1 * Num2
    mov ebx, [ebp + 16]  ; third parameter
    mul ebx              ; eax = (Num1 * Num2) * Num3
    
    call WriteDec
    pop ebp              ; Remove EBP
    ret
ThreeProd ENDP
END main
