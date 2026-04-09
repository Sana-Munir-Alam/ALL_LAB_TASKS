INCLUDE Irvine32.inc

.data
myByte BYTE 12h
myWord WORD 1234h
myDword DWORD 12345678h

.code
main PROC

    mov ESI, OFFSET myByte  ; Stores the Address of myByte
    call DumpRegs           ; ESI = 005F6000
    call Crlf

    mov ESI, OFFSET myWord  ; Stores the Address of myWord
    call DumpRegs           ; ESI = 005F6001    (as Byte has taken 1 space, Word starts from 2nd position)
    call Crlf

    mov ESI, OFFSET myDword ; Stores the Address of myDword
    call DumpRegs           ; ESI = 005F6003    (as Word has taken 2 space, DWord starts from 3rd position)
    
    exit
main ENDP
END main
