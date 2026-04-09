INCLUDE Irvine32.inc

.data
NumStudents = 5		; Row Size for 2D Array
NumSubjects = 3		; Colunm Size for 2D Array

; Declaring 2D Array with 5 Rows, and 3 Colunms (English, Urdu Math)
MarksArray WORD 90, 85, 98, 82, 76, 93, 45, 67, 39, 82, 85, 85,18, 11, 54
msgStudent BYTE "Student"

.code
main PROC
mov ebx, 0

StudentLoop:
	; PRINTING WHICH STUDENT WE ARE ON
	mov edx, OFFSET msgStudent
	call WriteString
	mov eax, ebx
	inc eax
	call WriteDec
	mov al, ':'
	Call WriteChar
	mov al, ' '
	Call WriteChar
	
	mov ecx, NumSubjects		; ECX will run inner loop counter for 3 elements
	mov esi, OFFSET MarksArray	; ESI Points to start of Array (0,0)

	mov eax, ebx							; EBX = Student Index initially 0
	mov edx, NumSubjects * TYPE MarksArray	; EDX = Size of One Row (3-2 = 6 bytes)
	mul edx;								; EAX = EAX * EDX (StudentIndex * RowSize)
	add esi, eax							; ESI now points to the Current Students's Row

SubjectLoop:
	movsx eax, WORD PTR [esi]	; Get Current Marks
	call WriteDec				; Printing Marks as Unsigned Decimal
	mov al, ' '					; Storing a space character inside AL register
	call WriteChar				; Printing space after each value

	add esi, TYPE MarksArray	; Move to the next subject in the same row (add 2 bytes for that)
	loop SubjectLoop			; Loop 3 times until ecx = 0

	call Crlf					; Line Break
	inc ebx						; Move to next Student
	cmp ebx, NumStudents		; Check if
	jl StudentLoop

exit
main ENDP
END main
