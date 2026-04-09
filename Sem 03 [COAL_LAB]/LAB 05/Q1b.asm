INCLUDE Irvine32.inc

.data

.code
main PROC
    mov AL, 7Fh
    sub AL, 80h      ; AL = AL - 80h   => AL = 7F - (80h)
    call DumpRegs    ; ZF = 0 (non-zero answer), SF = 1 (MSB is 1) , CF = 1 (Borrow), AF = 0, OF = 0 (1 XOR 1 = 0)
    
    exit
main ENDP
END main
