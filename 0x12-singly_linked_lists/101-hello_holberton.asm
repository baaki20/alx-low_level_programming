section .data
	format db 'Hello, Holberton!\n', 0

section .text
	global main

main:
	; prepare arguments for printf
	mov rdi, format
	xor esi, esi

	; call printf
	mov eax, 0
	call printf

	; return 0 from main
	mov eax, 0
	ret

