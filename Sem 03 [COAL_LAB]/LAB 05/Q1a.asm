INCLUDE Irvine32.inc

.data

.code
main PROC
    mov AL, 7Fh
    sub AL, 1h      ; AL = AL + 1   => AL = 7F + 1 = 0111 1111 + 0000 0001 = 1000 0000
    call DumpRegs   ; ZF = 0 (non-zero answer), SF = 1 (MSB is 1) , CF = 0 (No carry), AF = 1, OF = 0 (1 XOR 0 = 1)
    
    exit
main ENDP
END main
