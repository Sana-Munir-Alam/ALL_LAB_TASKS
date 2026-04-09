INCLUDE Irvine32.inc

.data
validCount DWORD 0    ; Counter for valid non-zero numbers

msgPrompt   BYTE "Enter a number (0 to stop): ", 0
msgResult   BYTE "Total valid (non-zero) numbers entered: ", 0
msgMaxInput BYTE " (Maximum 5 numbers)", 0
newline     BYTE 0Dh, 0Ah, 0

.code
main PROC
    mov ecx, 5                      ; Set maximum loop counter to 5
    InputLoop:
        mov edx, OFFSET msgPrompt
        call WriteString            ; Display prompt
        call ReadInt                ; Read number from user
    
        cmp eax, 0                  ; Check if number is zero
        je EndLoop                  ; If zero, exit loop immediately
        inc validCount              ; If non-zero, increment valid count
    
        ; Continue loop (LOOPNZ decrements ECX and loops if ECX != 0 and ZF = 0)
        loopnz InputLoop
    
    EndLoop:
        ; Display results
        call Crlf
        mov edx, OFFSET msgResult
        call WriteString
        mov eax, validCount
        call WriteDec
        mov edx, OFFSET msgMaxInput
        call WriteString
        call Crlf
    
    exit
main ENDP
END main
