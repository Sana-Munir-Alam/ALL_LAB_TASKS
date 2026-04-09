INCLUDE Irvine32.inc

.data

.code
main PROC
    
    ; -------- Case 1: Equal --------
    mov eax, 10     ; EAX = 10d [First Value]
    mov ebx, 10     ; EBX = 10d [Second Value]
    cmp eax, ebx    ; EAX - EBX = 0
    call DumpRegs   ; ZF = 1 (as result is 0)
    call Crlf

    ; -------- Case 2: Greater -------- 
    mov eax, 15     ; EAX = 15d [First Value]
    mov ebx, 10     ; EBX = 10d [Second Value]
    cmp eax, ebx    ; EAX - EBX = 5,    eax > ebx call     
    call DumpRegs   ; CF = 0 (no borrow as EAX value is big), ZF = 0 (non -zero result), SF = 0 (MSB is 0)

    ; -------- Case 3: Less --------
    mov eax, 5      ; EAX = 5d [First Value]
    mov ebx, 10     ; EBX = 10d [Second Value]
    cmp eax, ebx    ; EAX - EBX = -5,   eax < ebx call
    call DumpRegs   ; CF = 1 (borrow as EAX value is small), ZF = 0 (non -zero result), SF = 1 (MSB is 1)

    exit
main ENDP
END main
