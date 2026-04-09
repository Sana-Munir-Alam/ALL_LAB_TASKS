INCLUDE Irvine32.inc

.data

.code
main PROC
    
    mov ecx, 11     ; Set Counter Loop to Run 11 times as Value 15 is inclusive
    mov eax, 5      ; Store the First value to be Printed
    Print:
        call WriteInt   ; Print the Value
        call Crlf
        inc eax         ; Move to the next Value that is EAX = EAX + 1
        loop Print      ; Automatically Loops back to "Print" and decreases ECX by 1
        
    exit
main ENDP
END main
