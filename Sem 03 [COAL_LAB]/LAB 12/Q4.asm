INCLUDE Irvine32.inc

.data
    arr     DWORD 1, 2, 3                 ; Row 0
            DWORD 4, 5, 6                 ; Row 1  
            DWORD 7, 8, 9                 ; Row 2
    rows    = 3                           ; Number of rows
    cols    = 3                           ; Number of columns
    sum     DWORD 0                       ; Sum of all elements
    msg     BYTE "Sum of all elements: ", 0

.code
main PROC
    ; Initialize sum and pointers
    mov sum, 0                            ; Initialize sum to 0
    mov esi, OFFSET arr                   ; ESI points to array start
    
    ; Outer loop for rows (i = 0 to 2)
    mov ecx, rows                         ; ECX = row counter (3 rows)
    mov ebx, 0                            ; EBX = row index (i)

outer_loop:
    ; Save outer loop counter
    push ecx
    
    ; Inner loop for columns (j = 0 to 2)
    mov ecx, cols                         ; ECX = column counter (3 columns)
    mov edi, 0                            ; EDI = column index (j)

inner_loop:
    ; Calculate array offset: (i * cols + j) * 4 (since DWORD = 4 bytes)
    mov eax, ebx                          ; EAX = row index (i)
    imul eax, cols                        ; EAX = i * cols
    add eax, edi                          ; EAX = i * cols + j
    imul eax, 4                           ; EAX = (i * cols + j) * 4 (byte offset)
    
    ; Add array element to sum
    mov edx, [esi + eax]                  ; EDX = arr[i][j]
    add sum, edx                          ; sum += arr[i][j]
    
    ; Next column
    inc edi                               ; j++
    dec ecx                               ; Decrement inner loop counter
    jnz inner_loop                        ; Continue inner loop if ECX != 0
    
    ; Next row
    inc ebx                               ; i++
    pop ecx                               ; Restore outer loop counter
    dec ecx                               ; Decrement outer loop counter
    jnz outer_loop                        ; Continue outer loop if ECX != 0

    ; Display the result
    mov edx, OFFSET msg                   ; "Sum of all elements: "
    call WriteString
    
    mov eax, sum                          ; Load sum into EAX for display
    call WriteInt                         ; Display the sum
    call Crlf

exit_program:
    exit
main ENDP
END main
