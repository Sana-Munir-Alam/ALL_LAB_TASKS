INCLUDE Irvine32.inc

.data
Array1 DWORD 2, 4, 6, 8, 10
Array2 DWORD 1, 4, 6, 9, 10
arraySize = LENGTHOF Array1

matchCount DWORD 0
msg1 BYTE "Array1: ",0
msg2 BYTE "Array2: ",0
msg3 BYTE "Number of matching elements: ",0
space BYTE " ",0

.code
main PROC
    mov EDX, OFFSET msg1        ; Display Array1
    call WriteString
    mov ESI, OFFSET Array1
    mov ECX, arraySize
    call DisplayArray
    call Crlf

    mov EDX, OFFSET msg2        ; Display Array2
    call WriteString
    mov ESI, OFFSET Array2
    mov ECX, arraySize
    call DisplayArray
    call Crlf

    ; Compare arrays and count matches
    mov ESI, OFFSET Array1      ; Pointer to Array1
    mov EDI, OFFSET Array2      ; Pointer to Array2
    mov ECX, arraySize          ; Loop counter
    mov EBX, 0                  ; Match counter

    CompareLoop:
        mov EAX, [ESI]              ; Load element from Array1
        mov EDX, [EDI]              ; Load element from Array2
    
        cmp EAX, EDX                ; Compare elements
        jne SkipIncrement           ; If not equal, skip increment
        inc EBX                     ; Elements match - increment counter

        SkipIncrement:
            add ESI, TYPE Array1        ; Move to next element in Array1
            add EDI, TYPE Array2        ; Move to next element in Array2
            loop CompareLoop

        mov matchCount, EBX         ; Store and display result
        mov EDX, OFFSET msg3
        call WriteString
        mov EAX, matchCount
        call WriteDec
    exit
main ENDP

DisplayArray PROC
DisplayLoop:
    mov EAX, [ESI]
    call WriteDec
    mov EDX, OFFSET space
    call WriteString
    add ESI, TYPE Array1
    loop DisplayLoop
    ret
DisplayArray ENDP
END main
