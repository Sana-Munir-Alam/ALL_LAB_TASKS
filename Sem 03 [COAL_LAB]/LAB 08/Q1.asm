INCLUDE Irvine32.inc

.data
; Messages
msgPrompt    BYTE "Enter number ", 0
msgColon     BYTE ": ", 0
msgPositive  BYTE "Positive numbers: ", 0
msgNegative  BYTE "Negative numbers: ", 0
msgZeros     BYTE "Zeros: ", 0
newline      BYTE 0Dh, 0Ah, 0

; Counters
positiveCount DWORD 0
negativeCount DWORD 0
zeroCount     DWORD 0

; Temporary variables
currentNum   DWORD 1    ; For displaying current input number

.code
main PROC
    mov ecx, 5          ; Loop counter for 5 numbers
    
InputLoop:
    ; Display prompt with current number
    mov edx, OFFSET msgPrompt
    call WriteString
    mov eax, currentNum
    call WriteDec
    mov edx, OFFSET msgColon
    call WriteString
    
    ; Read number from user
    call ReadInt
    
    ; Classify the number and update counters
    call ClassifyNumber
    
    ; Move to next number
    inc currentNum
    loop InputLoop
    
    ; Display results
    call DisplayResults
    
    exit

; Procedure to classify number and update counters
ClassifyNumber PROC
    cmp eax, 0
    jg IsPositive       ; Jump if number > 0
    jl IsNegative       ; Jump if number < 0
    
    ; If we get here, number is zero
    inc zeroCount
    jmp ClassificationDone
    
IsPositive:
    inc positiveCount
    jmp ClassificationDone
    
IsNegative:
    inc negativeCount
    
ClassificationDone:
    ret
ClassifyNumber ENDP

; Procedure to display final results
DisplayResults PROC
    call Crlf
    call Crlf
    
    ; Display positive count
    mov edx, OFFSET msgPositive
    call WriteString
    mov eax, positiveCount
    call WriteDec
    call Crlf
    
    ; Display negative count
    mov edx, OFFSET msgNegative
    call WriteString
    mov eax, negativeCount
    call WriteDec
    call Crlf
    
    ; Display zero count
    mov edx, OFFSET msgZeros
    call WriteString
    mov eax, zeroCount
    call WriteDec
    call Crlf
    
    ret
DisplayResults ENDP

END main
