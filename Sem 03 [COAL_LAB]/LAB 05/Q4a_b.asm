INCLUDE Irvine32.inc

.data
arrayB BYTE 11h, 22h, 33h
arrayW WORD 4444h, 5555h, 6666h
msgByte BYTE "Part a: Displaying Values: ", 0
msgWord BYTE "Part b: Displaying Values: ", 0
.code
main PROC
    
    ; Part (a): Read arrayB (BYTE array). Doing this STep By Step
    mov edx, OFFSET msgByte
    call WriteString
    call Crlf
    mov esi, OFFSET arrayB    ; Reset ESI to start of array
    mov ecx, 3                ; Loop counter = 3 elements
    ReadByteArray:
        
        mov al, [esi]             ; Read current byte element
        movzx eax, al
        call WriteHex             ; DisplayResult
        call Crlf
        inc esi                   ; Move to next byte
        loop ReadByteArray

    ; Part (b): Read arrayW (WORD array). Doing this using loop
    call Crlf
    mov edx, OFFSET msgWordB
    call WriteString
    call Crlf
    mov esi, OFFSET arrayW    ; Reset ESI to start of array
    mov ecx, 3                ; Loop counter = 3 elements
    ReadWordArray:
        mov ax, [esi]             ; Read current word element
        movzx eax, ax
        call WriteHex
        call Crlf
        add esi, 2                ; Move to next word (2 bytes forward)
        loop ReadWordArray        ; Automatically Decreases ECX by 1, and ends when ECX has reached 0
    
    exit
main ENDP
END main
