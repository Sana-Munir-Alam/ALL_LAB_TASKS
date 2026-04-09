INCLUDE Irvine32.inc

.data
sensorReadings DWORD 12, 25, 30, 40, 18, 22, 27, 35, 20, 15
arraySize = LENGTHOF sensorReadings

sumReadings DWORD 0
averageReading DWORD 0
aboveAverage DWORD 0
belowAverage DWORD 0
scaledAverage DWORD 0
encryptedResult DWORD 0

msg1 BYTE "Sensor readings: ",0
msg2 BYTE "Sum of readings = ",0
msg3 BYTE "Average reading = ",0
msg4 BYTE "Readings above average = ",0
msg5 BYTE "Readings below average = ",0
msg6 BYTE "Scaled average (SHL) = ",0
msg7 BYTE "Encrypted result (ROR) = ",0
msg8 BYTE "b",0
space BYTE " ",0

.code
main PROC
    
    mov EDX, OFFSET msg1            ; Display sensor readings
    call WriteString
    mov ESI, OFFSET sensorReadings
    mov ECX, arraySize
    call DisplayArray
    call Crlf

   
    call CalculateSumAverage        ; Call procedure to calculate sum and average=
    call CountAboveBelow            ; Call procedure to count readings above/below average
    call ScaleAndEncrypt            ; Call procedure to perform scaling and encryption

    mov EDX, OFFSET msg2            ; Display all results
    call WriteString
    mov EAX, sumReadings
    call WriteDec
    call Crlf

    mov EDX, OFFSET msg3
    call WriteString
    mov EAX, averageReading
    call WriteDec
    call Crlf

    mov EDX, OFFSET msg4
    call WriteString
    mov EAX, aboveAverage
    call WriteDec
    call Crlf

    mov EDX, OFFSET msg5
    call WriteString
    mov EAX, belowAverage
    call WriteDec
    call Crlf

    mov EDX, OFFSET msg6
    call WriteString
    mov EAX, scaledAverage
    call WriteDec
    call Crlf

    mov EDX, OFFSET msg7
    call WriteString
    mov EAX, encryptedResult
    call DisplayBinaryByte
    mov EDX, OFFSET msg8
    call WriteString
    call Crlf

    exit
main ENDP

; Procedure to calculate sum and average of readings
CalculateSumAverage PROC
    mov ESI, OFFSET sensorReadings
    mov ECX, arraySize
    mov EAX, 0                  ; Initialize sum

    SumLoop:
        add EAX, [ESI]               ; Add current reading to sum
        add ESI, TYPE sensorReadings ; Move to next element
        loop SumLoop
        mov sumReadings, EAX        ; Store sum

        ; Calculate average using DIV
        mov EDX, 0                  ; Clear EDX for division
        mov EBX, arraySize
        div EBX                     ; EAX = sum / arraySize
        mov averageReading, EAX     ; Store average
    ret
CalculateSumAverage ENDP

; Procedure to count readings above and below average
CountAboveBelow PROC
    mov ESI, OFFSET sensorReadings
    mov ECX, arraySize
    mov EBX, 0                  ; Above average counter
    mov EDX, 0                  ; Below average counter
    mov EAX, averageReading     ; Load average for comparison

    CountLoop:
        mov EDI, [ESI]              ; Load current reading
        cmp EDI, EAX                ; Compare with average
        jg Above                    ; If reading > average
        jl Below                    ; If reading < average
        jmp NextReading             ; If equal, skip both counters

        Above:
            inc EBX
            jmp NextReading
        Below:
            inc EDX
        NextReading:
            add ESI, TYPE sensorReadings
            loop CountLoop

    mov aboveAverage, EBX
    mov belowAverage, EDX
    ret
CountAboveBelow ENDP

; Procedure to perform scaling and encryption
ScaleAndEncrypt PROC
    mov EAX, averageReading
    shl EAX, 1                  ; Step 1: Scale by shifting left (multiply by 2)
    mov scaledAverage, EAX
    ror AL, 1                  ; ; Step 2: Encrypt by rotating right 1 position
    mov encryptedResult, EAX
    ret
ScaleAndEncrypt ENDP

; Procedure to display array elements
DisplayArray PROC
    DisplayLoop:
        mov EAX, [ESI]
        call WriteDec
        mov EDX, OFFSET space
        call WriteString
        add ESI, TYPE sensorReadings
        loop DisplayLoop
        ret
DisplayArray ENDP

; Procedure to display a byte in binary format
DisplayBinaryByte PROC
    mov ECX, 8              ; 8 bits to display
    mov EBX, EAX            ; Save the value

    DisplayBitLoop:
        shl BL, 1           ; Shift leftmost bit into CF
        jc DisplayOne       ; Display the bit (0 or 1)
        mov AL, '0'         ; Display '0'
        call WriteChar
        jmp NextBit

    DisplayOne:
        mov AL, '1'         ; Display '1'
        call WriteChar

    NextBit:
        loop DisplayBitLoop
        ret
DisplayBinaryByte ENDP
END main
