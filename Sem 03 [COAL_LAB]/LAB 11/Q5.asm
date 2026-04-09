INCLUDE Irvine32.inc

.data
array DWORD 1,2,3,4,5,6,7,8,9,10
multiplier DWORD 10

.code
main PROC

    mov esi,OFFSET array    ; source index
    mov edi,esi             ; destination index
    mov ecx,LENGTHOF array  ; loop counter
    cld                     ; direction = forward
    
L1:
    lodsd                   ; load [ESI] into EAX
    mul multiplier          ; multiply by a value
    stosd                   ; store EAX into [EDI]
    loop L1
    
    ; Display the array
    mov esi,OFFSET array
    mov ecx,LENGTHOF array

Display:
    lodsd
    call WriteDec
    mov al,' '
    call WriteChar
    loop display
    call Crlf
    
    exit
main ENDP

END main
