INCLUDE Irvine32.inc

.data
msg BYTE "Sana Munir Alam, 24K-0573!", 0

.code
main PROC

mov edx, OFFSET msg
call WriteString

exit
main ENDP
END main
