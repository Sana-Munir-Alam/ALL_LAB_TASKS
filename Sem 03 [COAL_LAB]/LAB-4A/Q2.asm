INCLUDE Irvine32.inc

.data
Balance WORD 5000       ; Inital Amount in Customer Account
Deposit WORD 1200       ; Amount he dposits in his Account
Withdraw WORD 2000      ; Amount he withdraws

msgBalance BYTE "Current Balance: $", 0
msgDeposit BYTE "Balance After Deposited Amount: $", 0
msgWithdraw BYTE "Balance After Amount Withdrawn: $", 0

.code
main PROC
    
    ; ========== Printing Balance after each Bank operation ==========
    movzx eax, Balance            ; EAX = Balance         => EAX = 5000
    mov edx, OFFSET msgBalance
    call WriteString            ; Print Current Balance Text Message
    call WriteDec               ; Printing Balance
    call Crlf                   ; Printing New Line

    mov ax, Balance
    mov bx, Deposit             ; BX = Deposit       => BX = 1200
    add ax, bx                  ; AX = AX + BX       => AX = 5000 + 1200
    mov Balance, ax             ; Updating Balance
    
    mov edx, OFFSET msgDeposit
    call WriteString            ; Print Balance Text Message After Deposit
    movzx eax, Balance
    call WriteDec               ; Printing Balance
    call Crlf                   ; Printing New Line
    
    mov cx, Withdraw            ; CX = Withdraw      => CX = 2000
    sub ax, cx                  ; AX = AX - CX       => AX = (5000 + 1200) - 2000
    mov Balance, ax             ; Updating Balance
    
    mov edx, OFFSET msgWithdraw
    call WriteString            ; Print Balance Text Message After Deposit
    movzx eax, Balance
    call WriteDec               ; Printing Balance
    call Crlf 

exit
main ENDP
END main
