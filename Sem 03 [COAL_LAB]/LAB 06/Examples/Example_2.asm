INCLUDE Irvine32.inc

.data

.code
main PROC
    
    mov eax, 10     ; EAX = 10
    call WriteDec   ; Display
    call Crlf

    jmp Target      ; JUMP to the Label "Target"
    
    mov eax, 20     ; this instruction is skipped
    call WriteDec
    call Crlf

    Target:
        mov eax, 30     ; EAX = 30
        call WriteDec   ; Display the Value

    exit
main ENDP
END main
