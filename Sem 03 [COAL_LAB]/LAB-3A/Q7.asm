INCLUDE Irvine32.inc

.data
SalesArray SDWORD 12000, -500, 850, 1750, 2500, 1800, 2200	; The Sale Values are for Sun, Mon, Tue, Wed, Thu, Fri, Sat
msgDay BYTE "Day "											; Will indicate which day we currently on (1-7)

.code
main PROC

mov ecx, LENGTHOF SalesArray	; ecx contians the number of elements inside an array
mov esi, OFFSET SalesArray		; ESI points to the first value in the array
mov ebx, 0

SalesLoop:
	; PRINTING WHICH DAY WE ARE ON
	mov edx, OFFSET msgDay
	call WriteString
	mov eax, ebx
	inc eax
	call WriteDec
	mov al, ':'
	Call WriteChar
	mov al, ' '
	Call WriteChar
	
	mov eax, [esi]				; Get Current Sales Value
	call WriteInt				; Display Day Sales Value
	add esi, TYPE SalesArray	; ESI now points to the next sales's value

	inc ebx
	call Crlf
	loop SalesLoop

exit
main ENDP
END main
