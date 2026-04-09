INCLUDE Irvine32.inc

.data
Marks1 DWORD 45     ; Subject 1 Marks
MARKS2 DWORD 35     ; Subject 2 Marks
Total DWORD ?       ; Variable to store the total of the two marks
Difference DWORD ?  ; Variable to store the difference between the two marks

msgTotal BYTE "Total: ", 0
msgDifference BYTE "Difference: ", 0

.code
main PROC
    
    ; ========== Calculating Difference in Marks ==========
    mov eax, Marks1             ; EAX = Marks1          => EAX = 45
    mov ebx, Marks2             ; EBX = Marks2          => EBX = 35
    add eax, ebx                ; EAX = EAX + EBX       => EAX = 45 + 35 = 80
    mov Total, eax              ; storing Total in total variable
    
    mov edx, OFFSET msgTotal
    call WriteString            ; Print Total text message
    call WriteDec               ; Printing Total
    call Crlf                   ; Printing New Line

    ; ========== Calculating Difference in Marks ==========
    mov eax, Marks1             ; EAX = Marks1          => EAX = 45
    sub eax, ebx                ; EAX = EAX - EBX       => EAX = 45 - 35 = 10
    mov Difference, eax

    mov edx, OFFSET msgDifference
    call WriteString            ; Print Difference text message
    call WriteDec               ; Printing Difference
    call Crlf  

exit
main ENDP
END main
