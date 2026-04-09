INCLUDE Irvine32.inc

.data
DayTemp WORD 30     ; Day Temperature
NightTemp WORD 18   ; Night Temperature
Difference WORD ?   ; Changed to WORD since difference will be small

msgDayTemp BYTE "Day Temperature: ", 0
msgNightTemp BYTE "Night Temperature: ", 0
msgDifference BYTE "Temperature Difference: ", 0
msgInc BYTE "Incremented Night Temperature: ", 0

.code
main PROC
    
    mov edx, OFFSET msgDayTemp      ; Display Day Temperature
    call WriteString
    movzx eax, DayTemp              ; Storing Day Temp in EAX to be printed
    call WriteDec
    call Crlf                       ; Print New Line

    mov edx, OFFSET msgNightTemp    ; Display Night Temperature
    call WriteString
    movzx eax, NightTemp            ; Storing Night Temp in EAX to be printed
    call WriteDec
    call Crlf                       ; Print New Line

    mov ax, DayTemp                 ; AX = DayTemp          => AX = 30
    sub ax, NightTemp               ; AX = AX - NightTemp   => AX = 30 - 18
    mov Difference, ax
    
    mov edx, OFFSET msgDifference   ; Display Temperature Difference
    call WriteString
    movzx eax, Difference           ; Storing Temp Difference in EAX to be printed
    call WriteDec
    call Crlf                       ; Print New Line

    mov ax, NightTemp
    add ax, 2                       ; Incrementing Night temp by 2
    mov NightTemp, ax
    
    mov edx, OFFSET msgInc          ; Display incremented temperature
    call WriteString
    movzx eax, NightTemp            ; Storing Incremented Night Temp in EAX to be printed
    call WriteDec
    call Crlf                       ; Print New Line

    exit
main ENDP
END main
