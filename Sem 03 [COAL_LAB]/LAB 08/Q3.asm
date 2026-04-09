INCLUDE Irvine32.inc

.data
prompt      BYTE "Enter numbers: ", 0
largestMsg  BYTE "Largest number: ", 0
smallestMsg BYTE "Smallest number: ", 0
space       BYTE " ", 0

.code
main PROC
    mov edx, OFFSET prompt  
    call WriteString
    mov ecx, 5             ; Read 5 numbers and push to stack
    
    read_loop:
        call ReadInt           ; Read number into EAX
        push eax               ; Push to stack
        loop read_loop
    
    ; Initialize min/max with first popped value
    pop eax                ; Pop first number
    mov ebx, eax           ; EBX = max
    mov esi, eax           ; ESI = min
   
    mov ecx, 4              ; Check remaining 4 numbers from stack
    check_loop:
        pop eax                ; Pop next number
        cmp eax, ebx           ; Compare with current max
        jle check_min          ; JMP if small
        mov ebx, eax           ; Update max
        jmp next_num

        check_min:
            cmp eax, esi
            jge next_num
            mov esi, eax           ; Update min
    
        next_num:
            loop check_loop
    
    mov edx, OFFSET largestMsg      ; Display results
    call WriteString
    mov eax, ebx
    call WriteInt
    call Crlf
    
    mov edx, OFFSET smallestMsg
    call WriteString
    mov eax, esi
    call WriteInt
    call Crlf
    
    exit
main ENDP
END main
