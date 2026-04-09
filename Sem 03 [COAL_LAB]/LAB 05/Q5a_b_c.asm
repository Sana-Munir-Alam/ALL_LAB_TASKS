INCLUDE Irvine32.inc

.data
arrayD DWORD 1000h, 2000h, 3000h, 4000h
msgSecond BYTE "Part a: 2nd element (index 1): ", 0
msgLast BYTE "Part b: Last element (index 3): ", 0
msgRole BYTE "Part c: TYPE arrayD returns: ", 0

.code
main PROC
    ; Part (a): Load 2nd element into EAX
    mov edx, OFFSET msgSecond
    call WriteString
    mov esi, 1                          ; Index = 1 (2nd element)
    mov eax, arrayD[esi * TYPE arrayD]  ; EAX = 2000h
    call WriteHex                       ; Display the value
    call Crlf

    ; Part (b): Load last element into EBX  
    mov edx, OFFSET msgLast
    call WriteString
    mov esi, 3                          ; Index = 3 (last element)
    mov ebx, arrayD[esi * TYPE arrayD]  ; EBX = 4000h
    mov eax, ebx                        ; Move to EAX for display
    call WriteHex                       ; Display the value
    call Crlf

    ; Part (c): Demonstrate the role of TYPE operator
    mov edx, OFFSET msgRole
    call WriteString
    
    mov eax, TYPE arrayD                ; Get the size returned by TYPE operator
    call WriteDec                       ; Display the size (4)
    call Crlf
    
    ; Demonstrate what happens with different indices
    call Crlf
    mov edx, OFFSET msgSecond
    call WriteString
    call Crlf
    
    ; Show all elements using indexed addressing
    mov ecx, 4                          ; Loop counter for 4 elements
    mov esi, 0                          ; Start with index 0
DisplayArray:
    mov eax, arrayD[esi * TYPE arrayD]  ; Get element at current index
    call WriteHex                       ; Display the value
    call Crlf
    inc esi                             ; Move to next index
    loop DisplayArray

    exit
main ENDP
END main
