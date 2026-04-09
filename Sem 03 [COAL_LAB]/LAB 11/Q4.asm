INCLUDE Irvine32.inc

.data
originalStr BYTE "Hello World",0
reversedStr BYTE SIZEOF originalStr DUP(?)

.code
main PROC
    mov esi,OFFSET originalStr
    mov edi,OFFSET reversedStr
    call Str_Reverse
    
    ; Display results
    mov edx,OFFSET originalStr
    call WriteString
    call Crlf
    
    mov edx,OFFSET reversedStr
    call WriteString
    call Crlf
    
    exit
main ENDP

Str_Reverse PROC
    ; ESI = source, EDI = destination
    push esi                ; save original ESI
    mov ecx,0               ; Find length of string
    find_length:
        cmp BYTE PTR [esi],0    ; Null terminator comparison
        je found_end
        inc ecx
        inc esi
        jmp find_length

    found_end:
        pop esi                 ; restore original ESI
        push ecx                ; save length
    
    ; Set EDI to end of destination
    add edi,ecx
    mov BYTE PTR [edi],0    ; add null terminator
    dec edi                 ; point to last character position
    cld                     ; direction = forward for LODSB
    
reverse_loop:
    lodsb                   ; load [ESI] into AL, increment ESI
    mov [edi],al            ; store AL at [EDI]
    dec edi                 ; move destination backwards
    loop reverse_loop
    
    pop ecx                 ; restore length
    ret
Str_Reverse ENDP
END main
