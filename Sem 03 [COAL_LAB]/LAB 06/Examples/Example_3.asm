INCLUDE Irvine32.inc

.data
count DWORD 5

.code
main PROC
    
    mov ecx, count      ; Set loop counter to 5
    mov eax, 1          ; starting number
    L1:
        call WriteInt   ; print value of eax
        call Crlf       ; New Line
        inc eax         ; increment number
        loop L1         ; decrement ECX and jump if not zero

    exit
main ENDP
END main
