INCLUDE Irvine32.inc

.data
num1 SDWORD 1000h	; 32-bit Signed Integer initialised with 1000h
num2 SDWORD ?		; 32-but signed integer, uninitialised

msgNum1 BYTE "Number 1 : "
msgNum2 BYTE "Number 2 "

.code
main PROC

mov edx, OFFSET msgNum1	; Storing Number 1 message in EDX
call WriteString		; Prinitng out Number 1 text on terminal
call Crlf
mov eax, num1		; Storing Num1 value into Eax register 
call WriteHex		; Printing the Value

mov al, ' '			; Adding a space character
call WriteChar		; Printing the space
mov al, ':'			; Adding a : character
call WriteChar		; Printing the :
mov al, ' '			; Adding a space character
call WriteChar		; Printing the space

mov eax, num2		; Storing Num2 value into Eax register 
call WriteHex		; Printing the Value

exit
main ENDP
END main
