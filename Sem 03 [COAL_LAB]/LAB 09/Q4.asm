INCLUDE Irvine32.inc

.data
originalValue BYTE 10110110b
encryptedValue BYTE 0

msg1 BYTE "Original Value = ",0
msg2 BYTE "Encrypted Value = ",0
msg3 BYTE "b",0

.code
main PROC
    
    mov EDX, OFFSET msg1        ; Display original value
    call WriteString
    
    mov AL, originalValue
    call DisplayBinaryByte
    mov EDX, OFFSET msg3
    call WriteString
    call Crlf

    call EncryptData            ; Perform encryption operations
    mov EDX, OFFSET msg2        ; Display encrypted value
    call WriteString
    
    mov AL, encryptedValue
    call DisplayBinaryByte
    mov EDX, OFFSET msg3
    call WriteString
    exit
main ENDP

; Procedure to perform encryption
EncryptData PROC
    mov AL, originalValue   ; Load original value
    rol AL, 2               ; STEP 1: Rotate left 2 positions
    shr AL, 1               ; STEP 2: Shift right 1 position
    mov encryptedValue, AL  ; Store result
    ret
EncryptData ENDP

; Procedure to display a byte in binary format
DisplayBinaryByte PROC
    mov ECX, 8              ; 8 bits to display
    movzx EBX, AL           ; Save the byte
    DisplayBitLoop:
        shl BL, 1           ; Shift leftmost bit into CF
        jc DisplayOne       ; Display the bit (0 or 1)
  
        mov AL, '0'         ; Display '0'
        call WriteChar
        jmp NextBit

    DisplayOne:
        mov AL, '1'         ; Display '1'
        call WriteChar
    NextBit:
        loop DisplayBitLoop
        ret
DisplayBinaryByte ENDP
END main
