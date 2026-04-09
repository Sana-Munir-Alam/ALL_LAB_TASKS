INCLUDE Irvine32.inc

.data
count DWORD 5

.code
main PROC
    
    mov eax, 0
    mov ebx, 0
    mov ecx, 3 
    L1:
        inc eax             ; Increase EAX Value
        mov edx, ecx        ; Preserve OuterLoop Counter Value
        call DumpRegs       ; Display Result
        mov ecx, 2          ; Set Loop COunter For InnerLoop
        L2:
            inc ebx         ; Increase EBX Value
            call DumpRegs   ; Dispaly Result
            loop L2         ; Loop until ECX is 0
        
        mov ecx, edx        ; Reset the OuterLoop counter
        loop L1             ; loop the outerloop
    
    call DumpRegs

    exit
main ENDP
END main
