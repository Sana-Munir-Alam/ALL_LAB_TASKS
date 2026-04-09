INCLUDE Irvine32.inc

.data
    msg1 DB "Original flags saved on stack",0
    msg2 DB "Flags restored from stack",0

.code

    main PROC
        mov eax,5
        sub eax,5
        pushfd
        mov edx,OFFSET msg1
        call WriteString
        call Crlf

        mov eax,10
        add eax,1
        popfd

        mov edx,OFFSET msg2
        call WriteString
        call Crlf
        call DumpRegs

    exit

main ENDP
END main
