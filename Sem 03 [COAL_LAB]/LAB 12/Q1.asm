INCLUDE Irvine32.inc

.data
    Msgstr     BYTE "ASSEMBLY", 0          ; null-terminated string to search
    target  BYTE 'E'                    ; character to find
    found   BYTE 0                      ; flag to indicate if character exists
    msg1    BYTE "Character found!", 0
    msg2    BYTE "Character not found!", 0

.code
main PROC
    ; Initialize variables
    mov found, 0                        ; Set found flag to 0 (false)
    mov esi, OFFSET Msgstr                 ; ESI points to the start of the string
    mov al, target                      ; AL contains the target character

    ; Loop through string until null terminator is found
search_loop:
    mov bl, [esi]                       ; Load current character into BL
    cmp bl, 0                           ; Check for null terminator
    je end_search                       ; If null terminator, end loop
    
    cmp bl, al                          ; Compare current char with target
    jne next_char                       ; If not equal, check next character
    
    ; Character found
    mov found, 1                        ; Set found flag to 1 (true)
    jmp end_search                      ; Exit loop immediately

next_char:
    inc esi                             ; Move to next character in string
    jmp search_loop                     ; Continue looping

end_search:
    ; Display result based on found flag
    cmp found, 1                        ; Check if character was found
    jne not_found                       ; Jump if not found
    
    ; Character found message
    mov edx, OFFSET msg1
    call WriteString
    call Crlf
    jmp exit_program

not_found:
    ; Character not found message
    mov edx, OFFSET msg2
    call WriteString
    call Crlf

exit_program:
    exit
main ENDP
END main
