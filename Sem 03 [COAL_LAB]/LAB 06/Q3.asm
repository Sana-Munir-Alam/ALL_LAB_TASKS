INCLUDE Irvine32.inc

.data
msgStar BYTE "*", 0
Rows DWORD 5    ; Number of Rows For this Pattern

.code
main PROC
    
    mov ecx, Rows               ; Set OuterLoop to run 5 times (as we have 5 rows of Stars)
    mov ebx, 1                  ; No.of Stars to print in Current row (starts from 1)

    OuterLoop:
        mov Rows, ecx           ; Preseve OuterLoop Counter which has deccremented when Loop runs
        mov ecx, ebx            ; Set inner loop counter = number of stars for the respective rows
        
        InnerLoop:
            mov edx, OFFSET msgStar
            call WriteString
            loop InnerLoop      ; Automatically Loop Back to Innerloop while ECX decrements by 1

        call Crlf               ; New line after each row
        inc ebx                 ; Increase star count for next row
        mov ecx, Rows           ; Restore outer loop counter from temporary variable
        loop OuterLoop

    exit
main ENDP
END main
