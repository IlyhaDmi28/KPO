.586
.MODEL flat, stdcall

includelib kernel32.lib

ExitProcess PROTO : DWORD

getmin		PROTO : DWORD, : DWORD
getmax		PROTO : DWORD, : DWORD

.STACK 4096

.CONST

.DATA
array    DD  88d, 22d, 99d, 700d, 67d, 10d, 7d, 45d, 56d, 77d
arrCount EQU 10

min      DD  ?
max      DD  ?

.CODE

main PROC
START:
		INVOKE getmin, offset array, arrCount

		mov min, EAX

		INVOKE getmax, offset array, arrCount

		mov max, EAX

	push 0
	call ExitProcess

main ENDP

end main

getmin PROC Pointer: DWORD, Count: DWORD

	mov ESI, Pointer

	mov EAX, [ESI]

	mov ECX, 0

	.WHILE ECX < Count
		
		mov EBX, [ESI + (ECX * 4)]
		
		.IF EBX < EAX
			mov EAX, EBX
		.ENDIF

		inc ECX

	.ENDW

	ret

getmin ENDP

getmax PROC Pointer: DWORD, Count: DWORD

	mov ESI, Pointer

	mov EAX, [ESI]

	mov ECX, 0

	.WHILE ECX < Count
		
		mov EBX, [ESI + (ECX * 4)]
		
		.IF EBX > EAX
			mov EAX, EBX
		.ENDIF

		inc ECX

	.ENDW

	ret

getmax ENDP