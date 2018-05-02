extern scanf
extern printf

section .data
    input: db "%d %d", 0
    output: db "%d", 10, 0

    a: times 4 db 0
    b: times 4 db 0

section .text
    global main

main:
    lea esp, [esp-12]

    ;a, b 입력
    mov dword[esp], input
    mov dword[esp+4], a
    mov dword[esp+8], b
    call scanf

    ;첫째 줄에 A+B, 둘째 줄에 A-B, 셋째 줄에 A*B, 넷째 줄에 A/B, 다섯째 줄에 A%B

    mov edi, dword[a]
    mov esi, dword[b]

    ;a+b
    mov eax, edi
    add eax, esi
    ;출력
    mov dword[esp], output
    mov dword[esp+4], eax
    call printf

    ;a-b
    mov eax, edi
    sub eax, esi
    ;출력
    mov dword[esp], output
    mov dword[esp+4], eax
    call printf

    ;a*b
    mov eax, edi
    imul esi
    ;출력
    mov dword[esp], output
    mov dword[esp+4], eax
    call printf

    ;a/b
    mov eax, edi
    cdq
    idiv esi
    ;몫 출력
    mov dword[esp], output
    mov dword[esp+4], eax
    call printf

    mov eax, edi
    cdq
    idiv esi
    ;나머지 출력
    mov dword[esp], output
    mov dword[esp+4], edx
    call printf

    ;종료
    add esp, 12
    mov eax, 0
    ret
