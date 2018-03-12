section .data
    input: db "%d %d", 0
    output: db "%d", 10, 0

    a: times 4 db 0
    b: times 4 db 0

section .text
    global main
    extern scanf
    extern printf

main:
    ;입력
    push ebx
    push ecx

    push b
    push a
    push input
    call scanf
    add esp, 12

    ;뺄셈
    mov ebx, DWORD[a]
    mov ecx, DWORD[b]
    sbb ebx, ecx

    ;출력
    push ebx
    push output
    call printf

    ;종료
    add esp, 8
    pop ecx
    pop ebx
    mov eax, 0
    ret
;날로 먹자
