INCLUDE Irvine32.inc

; SYMBOLIC CONSTANT
SecondsInDay EQU 60 * 60 * 24       ; Seconds * Miuntes * No.of Hour

.data
msg1 BYTE "Seconds in 24 Hrs = ", 0

.code
main PROC

    mov eax, SecondsInDay   ; EAX = SecondsInDay     => EAX = 60 * 60 * 24

    mov edx, OFFSET msg1    ; Store Time Message
    call WriteString        ; Print the Message
    call WriteDec           ; Printing AX value

    exit
main ENDP
END main
