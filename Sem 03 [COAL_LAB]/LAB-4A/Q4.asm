INCLUDE Irvine32.inc

.data
Inventory WORD 50
Bought WORD 7
Restock WORD 15

msgInventory BYTE "Inventory: ", 0
msgSale BYTE "Inventory After Sale: ", 0
msgRestock BYTE "Inventory After Restock ", 0

.code
main PROC
    
    mov edx, OFFSET msgInventory    ; Storing Initial Inventory messgae in EDX
    call WriteString                ; Displaying Initial Inventory message
    movzx eax, Inventory            ; Storing Inventory in EAX to be printed
    call WriteDec
    call Crlf                       ; Print New Line

    mov edx, OFFSET msgSale         ; Storing After Sale Inventory messgae in EDX
    call WriteString                ; Displaying Message
    movzx ebx, Bought               ; EBX = Bought
    sub eax, ebx                    ; EAX = EAX - EBX
    call WriteDec
    call Crlf                       ; Print New Line

    mov edx, OFFSET msgRestock      ; Storing Restock Inventory messgae in EDX
    call WriteString                ; Displaying Message
    movzx ebx, Restock              ; EBX = Restock
    add eax, ebx                    ; EAX = EAX + EBX
    call WriteDec
    call Crlf                       ; Print New Line

    exit
main ENDP
END main
