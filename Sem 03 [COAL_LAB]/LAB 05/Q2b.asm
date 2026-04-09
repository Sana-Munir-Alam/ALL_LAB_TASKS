INCLUDE Irvine32.inc

.data
myByte BYTE 12h
myWord WORD 1234h
myDword DWORD 12345678h

.code
main PROC
    
    ; Address = Data Value =>    0 = 78    1 = 56      2 = 34      3 = 12     
    mov AX, WORD PTR [myDword + 2]  ; AX = [myDword + 2] which is 1234h (Little Endian Method)
    movzx eax, AX   ; Using movzx so that only myDword value is shown in eax and not random value in extra space
    call DumpRegs
    
    exit
main ENDP
END main
