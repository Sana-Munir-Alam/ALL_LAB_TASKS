INCLUDE Irvine32.inc

.data
arr1 BYTE 10,20,30,40
arr2 WORD 100h,200h,300h
arr3 DWORD 5 DUP(0)
partA BYTE "Q3a) Using LENGTHOF:", 0
partB BYTE "Q3b) Using SIZEOF:", 0

.code
main PROC
    
    ;(a) LENGTH OF
    mov edx, OFFSET partA
    call WriteString
    mov ax, LENGTHOF arr1  ; AX = 4
    mov bx, LENGTHOF arr2  ; BX = 3
    mov cx, LENGTHOF arr3  ; CX = 5
    call DumpRegs
    call Crlf

    ;(b) SIZEOF results:
    mov edx, OFFSET partb
    call WriteString
    mov ax, SIZEOF arr1   ; AX = 4
    mov bx, SIZEOF arr2   ; BX = 6
    mov cx, SIZEOF arr3   ; CX = 20D which is 14h
    call DumpRegs
    
    exit
main ENDP
END main
