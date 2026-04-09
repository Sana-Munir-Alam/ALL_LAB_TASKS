INCLUDE Irvine32.inc

.data
msgPrompt   BYTE "Enter number ", 0
msgColon    BYTE ": ", 0
msgPushing  BYTE " [Pushing to stack]", 0
msgPopping  BYTE " [Popping from stack: ", 0
msgReverse  BYTE "Reversed order: ", 0
space       BYTE " ", 0
newline     BYTE 0Dh, 0Ah, 0
closingBracket BYTE "]", 0

currentNum  DWORD 1                    ; Counter for input numbers

.code
main PROC
    mov ecx, 5                         ; Loop counter for 5 numbers
    call Crlf                          ; New line
    mov edx, OFFSET msgPrompt          ; Display input prompt
    call WriteString                          
    
    PushPhase:
        mov edx, OFFSET msgPrompt          ; Display input prompt
        call WriteString
        mov eax, currentNum            ; Show current number
        call WriteDec                  
        mov edx, OFFSET msgColon       ; Display colon
        call WriteString               
        call ReadInt                   ; Read integer input
        
        push eax                       ; Push value to stack
        mov edx, OFFSET msgPushing     ; Show push operation
        call WriteString               
        call Crlf                      
        
        inc currentNum                 ; Increment counter
        loop PushPhase                 ; Repeat for all numbers
    
    call Crlf
    mov edx, OFFSET msgReverse         ; Display reverse message
    call WriteString                   
    call Crlf                          
    
    mov ecx, 5                         ; Reset loop counter
    PopPhase:
        pop eax                        ; Pop value from stack
        call WriteInt                  ; Display popped value
        mov edx, OFFSET msgPopping     ; Show pop operation
        call WriteString               
        call Crlf                      
        loop PopPhase                  ; Repeat for all numbers
    
    exit                               ; Exit program
main ENDP
END main
