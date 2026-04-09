INCLUDE Irvine32.inc

.data
num1 DWORD ?
num2 DWORD ?
product DWORD 0

msg1 BYTE "First number = ",0
msg2 BYTE "Second number = ",0
msg3 BYTE "Product = ",0

.code
main PROC
    
    mov EDX, OFFSET msg1        ; Display first number
    call WriteString
    call ReadInt
    mov  num1, EAX

    mov EDX, OFFSET msg2        ; Display second number
    call WriteString
    call ReadInt
    mov  num2, EAX

    call ShiftMultiply          ;  Call multiplication procedure

    mov EDX, OFFSET msg3        ; Display result
    call WriteString
    mov EAX, product
    call WriteDec
    call Crlf

    exit
main ENDP

; Procedure to multiply two numbers using shift and add method
ShiftMultiply PROC
    mov EAX, 0              ; Initialize product to 0
    mov EBX, num1           ; EBX = multiplicand
    mov ECX, num2           ; ECX = multiplier
    mov EDX, 0              ; EDX will be our shifted multiplicand

MultiplyLoop:
    ; Check if the least significant bit of multiplier is 1
    test ECX, 1             ; Test LSB of multiplier
    jz SkipAdd              ; If zero, skip addition
    
    ; If LSB is 1, add shifted multiplicand to product
    add EAX, EBX            ; Add current multiplicand to product

SkipAdd:
    shl EBX, 1              ; Shift multiplicand left (multiply by 2)  EBX = EBX * 2
    shr ECX, 1              ; Shift multiplier right (divide by 2) ECX = ECX / 2
    jnz MultiplyLoop        ; Continue until multiplier becomes zero
    mov product, EAX        ; Store result
    ret
ShiftMultiply ENDP
END main
