INCLUDE Irvine32.inc

.data
    InputPrompt BYTE "Enter a number: ",0
    ESPMsg BYTE "ESP: ",0
    ArmstrongMsg BYTE " is an Armstrong number",0
    NotArmstrongMsg BYTE " is not an Armstrong number",0
    MultiplyMsg BYTE " * ",0
    EqualsMsg BYTE " = ",0
    PlusMsg BYTE " + ",0
    TotalMsg BYTE "Total sum: ",0
    
    number DWORD ?
    digitCount DWORD 0
    sum DWORD 0

.code
main PROC
    call TakeInput          ; Start the program by taking input
    exit
main ENDP

ShowESP PROC
    mov edx, OFFSET ESPMsg ; Display "ESP: " message
    call WriteString
    mov eax, esp           ; Get current stack pointer value
    call WriteHex          ; Display ESP value in hexadecimal
    call Crlf
    ret
ShowESP ENDP

TakeInput PROC
    call ShowESP           ; Show initial ESP value
    
    mov edx, OFFSET InputPrompt ; Ask user for input
    call WriteString
    call ReadInt           ; Read integer input
    mov number, eax        ; Store input in variable
    
    call ShowESP           ; Show ESP after input
    
    push number            ; Push number to stack as parameter
    call Armstrong         ; Call Armstrong checking procedure
    add esp, 4             ; Clean stack (remove parameter)
    
    call ShowESP           ; Show ESP before returning
    ret
TakeInput ENDP

Display PROC
    push ebp
    mov ebp, esp
    push eax
    push edx
    
    call ShowESP           ; Show ESP at Display entry
    
    mov eax, [ebp+12]      ; Get the original number from stack
    mov edx, [ebp+8]       ; Get result flag (1=Armstrong, 0=Not)
    
    call WriteDec          ; Display the number
    cmp edx, 1             ; Check if it's Armstrong
    jne ShowNotMsg
    
    mov edx, OFFSET ArmstrongMsg    ; Display Armstrong message
    call WriteString
    jmp DisplayDone
    
ShowNotMsg:
    mov edx, OFFSET NotArmstrongMsg ; Display Not Armstrong message
    call WriteString

DisplayDone:
    call Crlf
    pop edx
    pop eax
    pop ebp
    ret
Display ENDP

Armstrong PROC
    push ebp
    mov ebp, esp
    pushad                 ; Save all registers
    
    call ShowESP           ; Show ESP at Armstrong entry
    
    mov eax, [ebp+8]       ; Get number from stack parameter
    mov ebx, eax           ; Save original number in EBX
    mov digitCount, 0      ; Initialize digit counter
    
    ; Phase 1: Extract digits and push to stack
    mov ecx, 0             ; ECX will count digits
ExtractDigits:
    cmp eax, 0             ; Check if number is zero
    je DigitsExtracted     ; If zero, all digits extracted
    
    mov edx, 0             ; Clear EDX for division
    mov esi, 10            ; Divisor = 10
    div esi                ; EAX = quotient, EDX = remainder (digit)
    push edx               ; Push digit to stack
    inc ecx                ; Increase digit count
    jmp ExtractDigits      ; Continue extracting digits

DigitsExtracted:
    mov digitCount, ecx    ; Save total digit count
    
    ; Display digit extraction info
    call Crlf
    mov eax, ebx           ; Get original number
    call WriteDec          ; Display original number
    mov edx, OFFSET EqualsMsg
    call WriteString
    
    ; Phase 2: Calculate sum of digits^digitCount
    mov sum, 0             ; Initialize sum to zero
    mov esi, ecx           ; ESI = loop counter (digit count)
    
CalculateSum:
    cmp esi, 0             ; Check if all digits processed
    je SumCalculated       ; If yes, jump to sum comparison
    pop eax                ; Get digit from stack
    push esi               ; Save loop counter
    
    ; Calculate digit^digitCount
    mov ebx, eax           ; EBX = digit (base)
    mov ecx, digitCount    ; ECX = power (number of digits)
    mov edi, eax           ; EDI = running product (start with digit)
    
    call WriteDec          ; Display current digit
    mov edx, OFFSET MultiplyMsg
    call WriteString
    
PowerCalculation:
    dec ecx                ; Decrement power counter
    cmp ecx, 0             ; Check if reached power limit
    jle PowerDone          ; If yes, power calculation done
    
    mov eax, edi           ; Get current product
    mul ebx                ; Multiply by digit: EAX = EAX * digit
    mov edi, eax           ; Store new product
    
    ; Display multiplication chain
    mov eax, ebx           ; Display digit being multiplied
    call WriteDec
    cmp ecx, 1             ; Check if last multiplication
    jle NoMultiplySign     ; If yes, don't show multiply sign
    mov edx, OFFSET MultiplyMsg
    call WriteString
NoMultiplySign:
    jmp PowerCalculation   ; Continue power calculation

PowerDone:
    mov edx, OFFSET EqualsMsg ; Display equals sign
    call WriteString
    mov eax, edi           ; Get final power result
    call WriteDec          ; Display power result
    
    add sum, edi           ; Add this digit's power to total sum
    
    pop esi                ; Restore loop counter
    dec esi                ; Decrement digit counter
    cmp esi, 0             ; Check if last digit
    jle NoPlusSign         ; If yes, don't show plus sign
    mov edx, OFFSET PlusMsg ; Display plus sign
    call WriteString

NoPlusSign:
    jmp CalculateSum       ; Process next digit

SumCalculated:
    ; Display total sum calculation
    call Crlf
    mov edx, OFFSET TotalMsg
    call WriteString
    mov eax, sum           ; Get total sum
    call WriteDec          ; Display total sum
    call Crlf
    
    ; Compare sum with original number
    mov eax, [ebp+8]       ; Get original number from stack
    cmp eax, sum           ; Compare with calculated sum
    jne NotArmstrong       ; If not equal, not Armstrong
    
    ; It's an Armstrong number - call Display with flag 1
    push eax               ; Push original number
    push 1                 ; Push Armstrong flag (1 = true)
    call Display           ; Call Display procedure
    add esp, 8             ; Clean stack
    jmp ArmstrongDone
    
NotArmstrong:
    ; Not an Armstrong number - call Display with flag 0
    mov eax, [ebp+8]       ; Get original number
    push eax               ; Push original number
    push 0                 ; Push Armstrong flag (0 = false)
    call Display           ; Call Display procedure
    add esp, 8             ; Clean stack

ArmstrongDone:
    call ShowESP           ; Show ESP before exiting Armstrong
    popad                  ; Restore all registers
    pop ebp
    ret
Armstrong ENDP
END main
