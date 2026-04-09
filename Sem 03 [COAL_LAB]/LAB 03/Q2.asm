INCLUDE Irvine32.inc

.data
; NOTE: String is always stored in Byte and moved in EDX REGISTER ALWAYS
Message BYTE "Name and Department", 0	; A String and Null Terminator

.code
main PROC

mov edx, OFFSET Message	; Storing the String in EDX OFFSET provides the starting 
						; memory location where the STRING is stored till it 
						; finds NULL TERMINATOR
call WriteString		; Printing Message on Terminal

exit
main ENDP
END main
