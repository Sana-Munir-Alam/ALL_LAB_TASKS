INCLUDE Irvine32.inc

.data
Str1 BYTE '127&j~3#^&*#*#45^',0
foundMsg BYTE "Character found at index(0 starting index): ",0
notFoundMsg BYTE "Character not found",0

.code
main PROC
    ; Pass arguments and call the procedure
    mov esi, OFFSET Str1    ; ESI = string offset (argument 1)
    mov al, '#'             ; AL = character to search (argument 2)
    call Scan_String        ; Recieves ESI and AL as arguments
    
    exit
main ENDP

Scan_String PROC
    mov edi, esi            ; EDI points to the string (from ESI argument)
    mov ecx, LENGTHOF Str1  ; Maximum search count
    cld                     ; Clear direction flag (forward)
    
    repne scasb             ; Repeat while not equal
    jnz not_found           ; Jump if character not found
    
    ; Character found - calculate index
    dec edi                 ; Back up EDI to point to found character
    mov eax, edi            ; Calculate index
    sub eax, esi            ; Subtract original string offset (from ESI)
    
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
