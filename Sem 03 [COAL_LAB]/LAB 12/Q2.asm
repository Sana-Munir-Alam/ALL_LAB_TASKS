INCLUDE Irvine32.inc

.data
    Msgstr     BYTE "PROGRAMMING", 0       ; null-terminated string
    target  BYTE 'G'                    ; character to count
    count   DWORD 0                     ; counter for occurrences
    msg     BYTE "Character '", 0
    msg2    BYTE "' occurs ", 0
    msg3    BYTE " times", 0

.code
main PROC
    ; Initialize counter
    mov count, 0                        ; Set count to 0
    mov esi, OFFSET Msgstr                 ; ESI points to the start of the string
    mov al, target                      ; AL contains the target character

    ; Loop through string until null terminator is found
count_loop:
    mov bl, [esi]                       ; Load current character into BL
    cmp bl, 0                           ; Check for null terminator
    je end_count                        ; If null terminator, end loop
    
    cmp bl, al                          ; Compare current char with target
    jne next_char_count                 ; If not equal, check next character
    
    ; Character matches - increment count
    inc count                           ; Increase the occurrence counter

next_char_count:
    inc esi                             ; Move to next character in string
    jmp count_loop                      ; Continue looping

end_count:
    ; Display the result message
    mov edx, OFFSET msg                 ; "Character '"
    call WriteString
    
    ; Display the target character
    mov al, target
    call WriteChar
    
    ; Display middle part of message
    mov edx, OFFSET msg2                ; "' occurs "
    call WriteString
    
    ; Display the count
    mov eax, count
    call WriteDec
    
    ; Display the end of message
    mov edx, OFFSET msg3                ; " times"
    call WriteString
    call Crlf

exit_program:
    exit
main ENDP
END main
