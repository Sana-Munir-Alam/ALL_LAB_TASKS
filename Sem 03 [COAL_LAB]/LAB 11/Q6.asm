INCLUDE Irvine32.inc

.data
target BYTE "AAEBDCFBBC",0
freqTable DWORD 256 DUP(0)

.code
main PROC
    mov esi,OFFSET target
    mov edi,OFFSET freqTable
    call Get_frequencies
    call Display_Frequencies
    exit
main ENDP

Get_frequencies PROC
   
    mov ecx,256              ; Clear frequency table
    mov eax,0
    cld
    rep stosd
    
    mov esi,OFFSET target        ; Count frequencies
    mov edi,OFFSET freqTable
    cld
    
    count_chars:
        lodsb                   ; load byte into AL
        cmp al,0                ; check for null terminator
        je done_counting
    
        movzx ebx,al            ; zero extend to 32 bits
        shl ebx,2               ; multiply by 4 (DWORD size)
        inc DWORD PTR [edi+ebx] ; increment frequency count
        jmp count_chars

    done_counting:
        ret
Get_frequencies ENDP

Display_Frequencies PROC
    mov esi,OFFSET freqTable
    mov ecx,0               ; character code
    
display_loop:
    mov eax,[esi]           ; get frequency
    cmp eax,0               ; check if non-zero
    je skip_display
    
    ; Display character:frequency
    mov eax,ecx             ; character code
    call WriteChar
    mov al,':'
    call WriteChar
    mov eax,[esi]           ; frequency count
    call WriteDec
    mov al,' '
    call WriteChar

skip_display:
    add esi,4               ; next DWORD
    inc ecx                 ; next character code
    cmp ecx,256
    jb display_loop
    
    call Crlf
    ret
Display_Frequencies ENDP
END main
