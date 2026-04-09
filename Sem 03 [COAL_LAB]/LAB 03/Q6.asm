INCLUDE Irvine32.inc

.data
Marks BYTE 8 DUP(5)  ; 8 bytes, all equal to 5
Word BYTE 5 DUP(?)   ; Reserve 5 words (2bytes each) uninitialized

.code
main PROC

exit
main ENDP
END main
