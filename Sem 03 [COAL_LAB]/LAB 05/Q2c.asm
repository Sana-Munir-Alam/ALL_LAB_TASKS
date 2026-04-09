INCLUDE Irvine32.inc

.data
myByte BYTE 12h
myWord WORD 1234h
myDword DWORD 12345678h

.code
main PROC
    
    mov bx, TYPE myByte   ; BX = 1 (BYTE is 1 byte)
    call DumpRegs
    call Crlf
    mov bx, TYPE myWord   ; BX = 2 (WORD is 2 bytes)
    call DumpRegs
    call Crlf
    mov bx, TYPE myDword  ; BX = 4 (DWORD is 4 bytes)
    call DumpRegs
    
    exit
main ENDP
END main
