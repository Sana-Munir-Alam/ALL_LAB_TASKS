INCLUDE Irvine32.inc

.data
msgVar BYTE 100 DUP (?)											; Uninitialised String variable of 100 bytes
msgString BYTE "COMPUTER ORGANIZATION & ASSEMBLY LANGAUAGE", 0	; Our Message  null terminated string that is to be stored

.code
main PROC

mov esi, OFFSET msgString		; ESI points to the start of our Message String
mov edi, OFFSET msgVar			; EDI points to the start of Destination where we will store our message
mov ecx, LENGTHOF msgString		; ECX holds the number of bytes to be copied into destination

cld								; This clears the Direction Flag, so that movsb increments the ESI and EDI pointers
rep movsb						; Repeat copying single point from where ESI points to where EDI points

mov edx, OFFSET msgVar			; EDX now points to the copied string
call WriteString				; Printing the entire Copied String

exit
main ENDP
END main
