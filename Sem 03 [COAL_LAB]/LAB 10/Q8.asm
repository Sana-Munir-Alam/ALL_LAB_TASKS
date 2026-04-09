INCLUDE Irvine32.inc

.data
Array DWORD 45, 12, 67, 89, 34, 23, 90, 11, 56, 78
ArraySize DWORD 10
UnsortedMsg BYTE "Unsorted array: ",0
SortedMsg BYTE "Sorted array: ",0
Space BYTE " ",0

.code
main PROC
    mov edx, OFFSET UnsortedMsg     ; Display unsorted array
    call WriteString
    push OFFSET Array
    push ArraySize
    call DisplayArray
    add esp, 8
    call Crlf

    ; Sort the array
    push OFFSET Array
    push ArraySize
    call BubbleSort
    add esp, 8

    mov edx, OFFSET SortedMsg       ; Display sorted array
    call WriteString
    push OFFSET Array
    push ArraySize
    call DisplayArray
    add esp, 8
    call Crlf
    exit
main ENDP

; BubbleSort Procedur
BubbleSort PROC
    push ebp
    mov ebp, esp
    pushad
    
    mov esi, [ebp + 12] ; Array address
    mov ecx, [ebp + 8]  ; Array size
    dec ecx             ; Outer loop counter (n-1)
    
    mov ebx, 0          ; swapped flag

OuterLoop:
    mov ebx, 0          ; Reset swapped flag
    mov edx, ecx        ; Save outer counter
    mov ecx, [ebp + 8]  ; Reset inner counter
    dec ecx             ; Inner loop counter (n-1)
    mov esi, [ebp + 12] ; Reset array pointer
    
    InnerLoop:
        mov eax, [esi]      ; Current element
        mov edi, [esi + 4]  ; Next element
        cmp eax, edi
        jle NoSwap
    
        mov [esi], edi      ; Swap elements
        mov [esi + 4], eax
        mov ebx, 1          ; Set swapped flag
    
        NoSwap:
            add esi, 4          ; Move to next element
            loop InnerLoop
    
        mov ecx, edx        ; Restore outer counter
        cmp ebx, 0          ; Check if any swaps occurred
        je SortDone         ; If no swaps, array is sorted
        loop OuterLoop

SortDone:
    popad
    pop ebp
    ret
BubbleSort ENDP

; DisplayArray Procedure
DisplayArray PROC
    push ebp
    mov ebp, esp
    push esi
    push ecx
    
    mov esi, [ebp + 12] ; Array address
    mov ecx, [ebp + 8]  ; Array size
    
DisplayLoop:
    mov eax, [esi]
    call WriteDec
    mov edx, OFFSET Space
    call WriteString
    add esi, 4
    loop DisplayLoop
    
    pop ecx
    pop esi
    pop ebp
    ret
DisplayArray ENDP

END Main
