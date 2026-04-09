INCLUDE Irvine32.inc

.data
Str1 BYTE "Hello World",0
Str2 BYTE "Hello World",0
Str3 BYTE "Hello Earth",0
Str4 BYTE "Hello",0

equalMsg BYTE "Strings are equal",0
notEqualMsg BYTE "Strings are not equal",0

.code
main PROC
    ; Test case 1: Compare identical strings
    mov esi, OFFSET Str1    ; ESI = first string
    mov edi, OFFSET Str2    ; EDI = second string
    call IsCompare
    call DisplayResult
    
    ; Test case 2: Compare different strings
    mov esi, OFFSET Str1    ; ESI = first string
    mov edi, OFFSET Str3    ; EDI = second string
    call IsCompare
    call DisplayResult
    
    ; Test case 3: Compare strings of different lengths
    mov esi, OFFSET Str1    ; ESI = first string
    mov edi, OFFSET Str4    ; EDI = second string
    call IsCompare
    call DisplayResult
    
    exit
main ENDP

IsCompare PROC
    push esi                ; Save registers
    push edi
    push ecx
    cld                     ; Clear direction flag (forward)
    
    ; Compare strings until null terminator is found
    compare_loop:
        cmpsb                   ; Compare [ESI] with [EDI] and increment both
        jne strings_not_equal   ; If characters differ, strings not equal
    
        ; Check if we reached null terminator in first string
        cmp BYTE PTR [esi-1], 0 ; Check the character we just compared
        jne compare_loop        ; Continue if not null terminator
    
        cmp al, al              ;; Strings are equal Set ZF = 1
        jmp done

    strings_not_equal:
        ; ZF is already 0 from the failed comparison

    done:
        pop ecx                 ; Restore registers
        pop edi
        pop esi
        ret
IsCompare ENDP

DisplayResult PROC
    jnz not_equal
    mov edx, OFFSET equalMsg
    call WriteString
    call Crlf
    ret
not_equal:
    mov edx, OFFSET notEqualMsg
    call WriteString
    call Crlf
    ret
DisplayResult ENDP
END main
