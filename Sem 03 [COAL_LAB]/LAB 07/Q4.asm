INCLUDE Irvine32.inc

.data
a SDWORD ?
b SDWORD ?
msgPrompt   BYTE "Enter two numbers (a,b): ", 0
msgTrue     BYTE "Condition True", 0
msgFalse    BYTE "Condition False", 0
newline     BYTE 0Dh, 0Ah, 0

.code
main PROC
    
    mov edx, OFFSET msgPrompt
    call WriteString            ; Display prompt
    call ReadInt                ; Read first number (a)
    mov a, eax
    call ReadInt                ; Read second number (b)
    mov b, eax                  
    
    ; Implement the condition: if (a > b && a < 100)
    mov eax, a
    cmp eax, b            ; Check first condition: a > b (signed comparison)
    jle ConditionFalse    ; Jump if a <= b (signed)
    
    ; First condition passed, now check second condition: a < 100
    cmp eax, 100
    jge ConditionFalse          ; Jump if a >= 100 (signed)
    
    mov edx, OFFSET msgTrue     ; Both conditions are TRUE
    call WriteString
    call Crlf
    jmp EndProgram              ; Exit
    
    ConditionFalse:
        ; Either a <= b OR a >= 100
        mov edx, OFFSET msgFalse
        call WriteString
        call Crlf
    
    EndProgram:
        exit
main ENDP
END main
