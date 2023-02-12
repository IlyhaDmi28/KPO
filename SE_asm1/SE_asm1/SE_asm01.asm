.586P
.MODEL FLAT, STDCALL
includelib kernel32.lib
includelib msvcrt.lib
includelib ucrt.lib

ExitProcess			PROTO : DWORD


getmin				PROTO : DWORD, : DWORD
getmax				PROTO : DWORD, : DWORD

.STACK 4096

.CONST

.DATA

array    DD  88, 22, 99, 693, 67, 10, 7, 45, 56, 77
arrCount EQU 10

min      DD  ?
max      DD  ?


.CODE

main PROC

	INVOKE getmin, offset array, arrCount

	mov min, EAX

	INVOKE getmax, offset array, arrCount

	mov max, EAX

	push - 1
	call ExitProcess

main ENDP

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
	
end main
