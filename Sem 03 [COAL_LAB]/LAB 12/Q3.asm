INCLUDE Irvine32.inc

.data
    Msgstr         BYTE "ASSEMBLY", 0          ; null-terminated string to reverse
    lengthStr      DWORD ?                     ; will store string length
    msg         BYTE "Reversed string: ", 0

.code
main PROC
    ; Calculate string length first
    mov esi, OFFSET Msgstr                    ; ESI points to the start of the string
    mov ecx, 0                             ; Initialize length counter
    
calculate_length:
    mov al, [esi]                          ; Load current character
    cmp al, 0                              ; Check for null terminator
    je length_calculated                   ; If null, we're done
    inc ecx                                ; Increment length counter
    inc esi                                ; Move to next character
    jmp calculate_length

length_calculated:
    mov lengthStr, ecx                        ; Store the calculated length
    
    ; Set up pointers for reversal
    mov esi, OFFSET Msgstr                    ; ESI = start pointer (i)
    mov edi, esi                           ; EDI = end pointer (length - i - 1)
    add edi, ecx
    dec edi                                ; EDI now points to last character
    
    ; Calculate loop counter (length / 2)
    mov eax, ecx
    mov ebx, 2
    xor edx, edx
    div ebx                                ; EAX = length / 2
    mov ecx, eax                           ; ECX = loop counter

    ; Reverse the string by swapping characters
reverse_loop:
    cmp ecx, 0                             ; Check if we've done all swaps
    je reversal_complete                   ; If yes, exit loop
    
    ; Swap characters at esi and edi
    mov al, [esi]                          ; AL = str[i]
    mov bl, [edi]                          ; BL = str[length-i-1]
    
    mov [esi], bl                          ; str[i] = BL
    mov [edi], al                          ; str[length-i-1] = AL
    
    ; Move pointers
    inc esi                                ; Move start pointer forward
    dec edi                                ; Move end pointer backward
    
    ; Decrement loop counter
    dec ecx
    jmp reverse_loop

reversal_complete:
    ; Display the result message
    mov edx, OFFSET msg                    ; "Reversed string: "
    call WriteString
    
    ; Display the reversed string
    mov edx, OFFSET Msgstr
    call WriteString
    call Crlf

exit_program:
    exit
main ENDP
END main
