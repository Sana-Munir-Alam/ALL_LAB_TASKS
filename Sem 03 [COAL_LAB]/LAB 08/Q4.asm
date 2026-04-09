INCLUDE Irvine32.inc

.data
msgPrompt BYTE "Enter a word: ", 0
msgVowels BYTE "Vowels: ", 0
msgCons   BYTE "Consonants: ", 0
newline  BYTE 0Dh, 0Ah, 0
vowels DWORD 0
cons   DWORD 0
buffer BYTE 50 DUP(0)

.code
main PROC
    mov edx, OFFSET msgPrompt
    call WriteString
    mov edx, OFFSET buffer
    mov ecx, SIZEOF buffer
    call ReadString
    
    mov esi, edx        ; Push all characters onto stack
    mov ecx, eax
    PushLoop:
        movzx ebx, BYTE PTR [esi]
        push ebx
        inc esi
        loop PushLoop

    mov ecx, eax
    PopLoop:
            pop ebx
            cmp bl, 'a'     ; Convert to uppercase
            jl CheckChar
            sub bl, 32
        CheckChar:
            cmp bl, 'A'     ; Check if letter (checks A to Z range)
            jl Skip
            cmp bl, 'Z'
            jg Skip

            cmp bl, 'A'     ; Check vowel
            je Vowel
            cmp bl, 'E'
            je Vowel
            cmp bl, 'I'
            je Vowel
            cmp bl, 'O'
            je Vowel
            cmp bl, 'U'
            je Vowel

            inc cons        ; IF NOT VOWEL Must be consonant
            jmp Skip
        Vowel:
            inc vowels
        Skip:
            loop PopLoop
    
    call Crlf
    mov edx, OFFSET msgVowels
    call WriteString
    mov eax, vowels
    call WriteDec
    call Crlf
    mov edx, OFFSET msgCons
    call WriteString
    mov eax, cons
    call WriteDec
    call Crlf
    
    exit
main ENDP
END main
