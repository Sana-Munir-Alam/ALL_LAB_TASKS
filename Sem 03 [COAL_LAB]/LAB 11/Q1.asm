INCLUDE Irvine32.inc

.data
Str1 BYTE '127&j~3#^&*#*#45^',0
foundMsg BYTE "Character found at index(0 starting index): ",0
notFoundMsg BYTE "Character not found",0

.code
main PROC
    call Scan_String
    exit
main ENDP

Scan_String PROC
    mov edi, OFFSET Str1    ; EDI points to the string
    mov al, '#'             ; Character to search for
    mov ecx, LENGTHOF Str1  ; Maximum search count
    cld                     ; Clear direction flag (forward)
    
    repne scasb             ; Repeat while not equal
    jnz not_found           ; Jump if character not found
    
    ; Character found - calculate index
    dec edi                 ; Back up EDI to point to found character
    mov eax, edi            ; Calculate index
    sub eax, OFFSET Str1
    
    ; Display result
    mov edx, OFFSET foundMsg
    call WriteString
    call WriteDec
    call Crlf
    ret

not_found:
    mov edx, OFFSET notFoundMsg
    call WriteString
    call Crlf
    ret
Scan_String ENDP

END main
