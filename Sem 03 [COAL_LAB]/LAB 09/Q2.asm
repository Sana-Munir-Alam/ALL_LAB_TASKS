INCLUDE Irvine32.inc

.data
Marks DWORD 45, 78, 90, 32, 60, 49, 85      ; Array
msgPass BYTE "Passed Students = ", 0
msgFail BYTE "Failed Students = ", 0
msgComma BYTE ", ", 0
PassQty DWORD 0
FailQty DWORD 0

.code
main PROC
    
    mov ecx, 7
    mov esi, OFFSET Marks
    PrintArrayLoop:
        mov eax, [esi]
        call WriteInt
        mov edx, OFFSET msgComma
        call WriteString
        add esi, 4
        loop PrintArrayLoop
    Call Crlf

    Call CountStudents
        
exit
main ENDP

CountStudents PROC
    mov ecx, 7  ; Set Loop counter to 7
    mov esi, OFFSET Marks

    CountLoop:
        mov eax, [esi]          ; Load Marks in EAX
        cmp eax, 50
        jl FailCount            ; If Marks < 50 jump to fail counter

        PassCount:              ; If marks was >= 50 than this will run
            inc PassQty
            jmp LoopContinue    ; Jump to next loop

        FailCount:
            inc FailQty
            jmp LoopContinue

        LoopContinue:
            add esi, 4
            loop CountLoop      ; Will loop back until ECX is decremented to 0

        
        mov edx, OFFSET msgPass ; Load Pass message
        call WriteString
        mov eax, PassQty
        call WriteDec
        call Crlf

        mov edx, OFFSET msgFail ; Load Fail message
        call WriteString
        mov eax, FailQty
        call WriteDec
        call Crlf

        ret
CountStudents ENDP
END main
