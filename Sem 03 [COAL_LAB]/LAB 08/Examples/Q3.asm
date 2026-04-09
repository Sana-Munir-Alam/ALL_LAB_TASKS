INCLUDE Irvine32.inc

.data
    versionHistory DW 101,102,103,104,105
    rollbackHistory DW 5 DUP(?)
    msg1 DB "Version History (Latest Last): ",0
    msg2 DB "Roll Back Order (After using puush and pop): ",0
    space DB " ",0

.code
main PROC

        mov edx,OFFSET msg1
        call WriteString
        call Crlf
        mov ecx , LENGTHOF versionHistory
        mov esi,OFFSET versionHistory

        display_original:
            movzx eax,WORD PTR [esi]
            call WriteDec
            mov edx,OFFSET space
            call WriteString
            add esi,TYPE versionHistory
            loop display_original

        call Crlf
        mov ecx , LENGTHOF versionHistory
        mov esi,OFFSET versionHistory

        push_versions:
            mov ax,[esi]
            push ax
            add esi,TYPE versionHistory
            loop push_versions

        mov ecx , LENGTHOF rollbackHistory
        mov edi,OFFSET rollbackHistory

        pop_versions:
            pop ax
            mov [edi],ax
            add edi,TYPE rollbackHistory
            loop pop_versions

        mov ecx , LENGTHOF rollbackHistory
        mov esi,OFFSET rollbackHistory
        mov edx,OFFSET msg2
        call WriteString
        call Crlf

        display_rollback:
            movzx eax,WORD PTR [esi]
            call WriteDec
            mov edx,OFFSET space
            call WriteString
            add esi,TYPE rollbackHistory
            loop display_rollback
    exit

main ENDP
END main
