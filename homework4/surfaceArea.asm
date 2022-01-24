extern SPHERE
extern TETRAHEDRON
extern PARALLELEPIPED

global SurfaceAreaSphere
SurfaceAreaSphere:
section .data
    pi   dq  3.141592 ;число пи
    four dq  4.0
section .text
push rbp
mov rbp, rsp

    mov eax, [rdi]
    cvtsi2sd xmm3, eax
    movsd xmm0, xmm3
    mulsd xmm0, xmm0 ;возведение в квадрат
    mulsd xmm0, [pi]
    mulsd xmm0, [four]
leave
ret

global SurfaceAreaTetrahedron
SurfaceAreaTetrahedron:
section .data
    sqrtthree  dq  1.7320508  ;корень из трех
section .text
push rbp
mov rbp, rsp

    mov eax, [rdi]
    cvtsi2sd xmm3, eax
    movsd xmm0, xmm3
    mulsd xmm0, xmm0 ;возведение в квадрат
    mulsd xmm0, [sqrtthree]    
leave
ret

global SurfaceAreaParallelepiped
SurfaceAreaParallelepiped:
section .data
    two  dq  2.0
    sum  dq  0.0    
section .text
push rbp
mov rbp, rsp
    ;произведение первой стороны
    mov eax, [rdi]
    movsd xmm0, [sum]
    cvtsi2sd xmm3, eax
    mov eax, [rdi + 4]
    cvtsi2sd xmm2, eax
    mulsd xmm3, xmm2
    addsd xmm0, xmm3
    ;произведение второй стороны
    mov eax, [rdi]
    cvtsi2sd xmm3, eax
    mov eax, [rdi + 8]
    cvtsi2sd xmm2, eax
    mulsd xmm3, xmm2
    addsd xmm0, xmm3
    ;произведение третьей стороны
    mov eax, [rdi + 8]
    cvtsi2sd xmm3, eax
    mov eax, [rdi + 4]
    cvtsi2sd xmm2, eax
    mulsd xmm3, xmm2
    addsd xmm0, xmm3
    ;сложение сторон    
    mulsd xmm0, [two]        
leave
ret

global SurfaceAreaShape
SurfaceAreaShape:
section .text
push rbp
mov rbp, rsp

    mov eax, [rdi]
    ;сравнение первого щначения для определения вида фигуры
    cmp eax, [SPHERE]
    je .sphereSurfaceArea
    cmp eax, [TETRAHEDRON]
    je .tetrahedronSurfaceArea
    cmp eax, [PARALLELEPIPED]
    je .parallelepipedSurfaceArea
    xor eax, eax
    cvtsi2sd    xmm0, eax
    jmp     .return
    ;вычисление площади поверхности фигуры
.sphereSurfaceArea:
    add     rdi, 4
    call SurfaceAreaSphere
    jmp .return

.tetrahedronSurfaceArea:
    add     rdi, 4
    call SurfaceAreaTetrahedron
    jmp .return

.parallelepipedSurfaceArea:
    add     rdi, 4
    call SurfaceAreaParallelepiped
    jmp .return
    
.return:
leave
ret

global AverageSurfaceAreaContainer
AverageSurfaceAreaContainer:
section .text
push rbp
mov rbp, rsp

    ; В rdi адрес начала контейнера
    mov rbx, rsi            ; число фигур
    xor rcx, rcx            ; счетчик фигур
    movsd xmm1, [sum]      ; перенос накопителя суммы в регистр 1
.loop:
    cmp rcx, rbx            ; проверка на окончание цикла
    jge .return             ; Перебрали все фигуры

    mov r10, rdi            ; сохранение начала фигуры
    call SurfaceAreaShape   ; Получение  площаи поверхности первой фигуры
    addsd xmm1, xmm0        ; накопление суммы
    inc rcx                 ; индекс следующей фигуры
    add r10, 20             ; адрес следующей фигуры
    mov rdi, r10            ; восстановление для передачи параметра
    jmp .loop
.return:
    movsd xmm0, xmm1
    cvtsi2sd xmm1, rbx
    ;деление суммы площадей на количество фигур
    divsd xmm0, xmm1
leave
ret


global LessThanAverageSurfaceAreaContainer
LessThanAverageSurfaceAreaContainer:
section .text
push rbp
mov rbp, rsp

    ; В rdi адрес начала контейнера
    mov rbx, rsi            ; число фигур
    xor rcx, rcx            ; счетчик фигур        
    mov r11, rdi
    movsd xmm1, xmm0        ;Переносим в xmm1 среднюю площадь    
    xor r12, r12    
.loop:
    cmp rcx, rbx            ; проверка на окончание цикла
    jge .return             ; Перебрали все фигуры

    mov r10, rdi
    call SurfaceAreaShape
    comisd xmm0, xmm1       ;Сравниваем пощпдь данной фигуры со средней
    ja .deleteShape
    inc r12
    mov rsi, r11
    mov rdi, [r10]
    mov [rsi], rdi
    mov rdi, [r10+4]
    mov [rsi+4], rdi
    mov rdi, [r10+8]
    mov [rsi+8], rdi
    mov rdi, [r10+12]
    mov [rsi+12], rdi
    mov rdi, [r10+16]
    mov [rsi+16], rdi

    add r11, 20             ;Указываем на арес следующей будущей фигуры

.deleteShape:
    inc rcx
    add r10, 20
    mov rdi, r10
    jmp .loop

.return:
    mov rax, r12            ;Переносим в rax количество оставшихся фигур
leave
ret