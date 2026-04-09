INCLUDE Irvine32.inc

.code
main PROC

mov eax, 30000h  ; EAX = 30000h
add eax, 60000h  ; EAX = [30000h] + 60000h
sub eax, 10000h  ; EAX = [30000h + 60000h] - 10000h

call WriteHex    ; Printing Result in hexa decimal form

exit
main ENDP
END main
