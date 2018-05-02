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

    ;덧셈
    mov ebx, DWORD[a]
    mov ecx, DWORD[b]
    add ebx, ecx

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
;별로 마음에는 안들지만 아직 퓨어 ASM은 모르겠다.
;고치고 보니 예제 복붙이네 ㅁㄴㅇㄹ
