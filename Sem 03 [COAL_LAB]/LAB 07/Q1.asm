INCLUDE Irvine32.inc

.data
    msgOriginal BYTE "Original values:", 0
    msgAnd      BYTE "After AND (Clear odd bits):", 0
    msgOr       BYTE "After OR (Set even bits):", 0
    msgXor      BYTE "After XOR (Toggle bits):", 0
    msgBitOn    BYTE "Bit 0 is ON", 0
    msgBitOff   BYTE "Bit 0 is OFF", 0
    msgAL       BYTE "Processing AL:", 0
    msgBL       BYTE "Processing BL:", 0
    msgCL       BYTE "Processing CL:", 0
    msgIAL  BYTE "Al = ", 0
    msgIBL  BYTE "Bl = ", 0
    msgICL  BYTE "Cl = ", 0

.code
main PROC
    ; Step 1: Store three 8-bit values in AL, BL, CL
    mov al, 0A3h     ; 10100011b
    mov bl, 5Ch      ; 01011100b
    mov cl, 9Fh      ; 10011111b

    ; Display original binary values
    call Crlf
    mov edx, OFFSET msgOriginal
    call WriteString
    call Crlf

    movzx eax, al
    mov edx, OFFSET msgIAL
    call WriteString
    call WriteBin
    call Crlf

    mov edx, OFFSET msgIBL
    call WriteString
    movzx eax, bl
    call WriteBin
    call Crlf

    mov edx, OFFSET msgICL
    call WriteString
    movzx eax, cl
    call WriteBin
    call Crlf

    ; Process each register separately
    call Crlf
    mov edx, OFFSET msgAL
    call WriteString
    call Crlf
    mov al, 0A3h
    call ProcessRegister

    call Crlf
    mov edx, OFFSET msgBL
    call WriteString
    call Crlf
    mov al, 5Ch       ; move BL original value into AL
    call ProcessRegister

    call Crlf
    mov edx, OFFSET msgCL
    call WriteString
    call Crlf
    mov al, 9Fh       ; move CL original value into AL
    call ProcessRegister

    exit
main ENDP

; ----------------------------------------
; Subroutine: ProcessRegister
; Applies AND, OR, XOR on AL and displays
; final bit 0 test result.
; ----------------------------------------
ProcessRegister PROC
    ; Step 1: AND with 55h
    and al, 55h
    mov edx, OFFSET msgAnd
    call WriteString
    call Crlf
    movzx eax, al
    call WriteBin
    call Crlf

    ; Step 2: OR with 55h
    or al, 55h
    mov edx, OFFSET msgOr
    call WriteString
    call Crlf
    movzx eax, al
    call WriteBin
    call Crlf

    ; Step 3: XOR with FFh
    xor al, 0FFh
    mov edx, OFFSET msgXor
    call WriteString
    call Crlf
    movzx eax, al
    call WriteBin
    call Crlf

    ; Step 4: TEST for bit 0
    test al, 1
    jz BitOff

BitOn:
    mov edx, OFFSET msgBitOn
    call WriteString
    call Crlf
    ret

BitOff:
    mov edx, OFFSET msgBitOff
    call WriteString
    call Crlf
    ret
ProcessRegister ENDP

END main
