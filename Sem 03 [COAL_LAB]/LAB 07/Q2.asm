INCLUDE Irvine32.inc

.data
num1 SDWORD ?
num2 SDWORD ?
num3 SDWORD ?
largestUnsigned SDWORD ?
largestSigned SDWORD ?

msgInput1    BYTE "Enter first number: ", 0
msgInput2    BYTE "Enter second number: ", 0
msgInput3    BYTE "Enter third number: ", 0
msgUnsigned  BYTE "Largest (Unsigned) = ", 0
msgSigned    BYTE "Largest (Signed) = ", 0
newline      BYTE 0Dh, 0Ah, 0

.code
main PROC
    ; Get three numbers from user
    mov edx, OFFSET msgInput1
    call WriteString
    call ReadInt
    mov num1, eax
    
    mov edx, OFFSET msgInput2
    call WriteString
    call ReadInt
    mov num2, eax
    
    mov edx, OFFSET msgInput3
    call WriteString
    call ReadInt
    mov num3, eax
    call Crlf
    
    ; =============================================
    ; FIND LARGEST USING UNSIGNED COMPARISON (JA, JB)
    ; =============================================
    
    mov eax, num1        ; Assume num1 is largest initially
    cmp eax, num2        ; Compare num1 and num2 (unsigned)
    jae UnsignedCheck1   ; Jump if num1 >= num2 (unsigned)
    mov eax, num2        ; If num2 > num1, make num2 the largest
    
    UnsignedCheck1:
        cmp eax, num3        ; Compare current largest with num3 (unsigned)
        jae UnsignedDone     ; Jump if current largest >= num3 (unsigned)
        mov eax, num3        ; If num3 > current largest, make num3 the largest
    
    UnsignedDone:
        mov largestUnsigned, eax  ; Store unsigned result
    
    ; =============================================
    ; FIND LARGEST USING SIGNED COMPARISON (JG, JL)
    ; =============================================
    
    mov eax, num1        ; Assume num1 is largest initially
    cmp eax, num2        ; Compare num1 and num2 (signed)
    jge SignedCheck1     ; Jump if num1 >= num2 (signed)
    mov eax, num2        ; If num2 > num1, make num2 the largest
    
    SignedCheck1:
        cmp eax, num3        ; Compare current largest with num3 (signed)
        jge SignedDone       ; Jump if current largest >= num3 (signed)
        mov eax, num3        ; If num3 > current largest, make num3 the largest
    
    SignedDone:
        mov largestSigned, eax    ; Store signed result

    mov edx, OFFSET msgUnsigned   ; Display unsigned result
    call WriteString
    mov eax, largestUnsigned
    call WriteInt
    call Crlf
    
    mov edx, OFFSET msgSigned      ; Display signed result  
    call WriteString
    mov eax, largestSigned
    call WriteInt
    call Crlf
    
    exit
main ENDP
END main
