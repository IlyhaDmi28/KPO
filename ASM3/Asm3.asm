.586P
.MODEL FLAT, STDCALL
includelib kernel32.lib

ExitProcess PROTO : DWORD

.STACK 4096

.CONST

.DATA

myBytes BYTE 10h, 20h, 30h, 40h
myWords WORD 8Ah, 3Bh, 44h, 5Fh, 99h
myDoubles DWORD 1, 2, 3, 4, 5, 6
myPointer DWORD myDoubles

myArray DW 13, 12, 27, 0, 34, 62, 91

.CODE

main PROC
START:

		mov EAX, 0
		mov EBX, 0
		mov ESI, OFFSET myWords
		mov AH, [ESI + 4]
		mov BX, [ESI + 2]
		
		mov EAX, 0
		mov ESI, OFFSET myArray
		
		mov EBX, 1
		mov ECX, 7
metka:
		add AX, [ESI]
		mov DX, 1

		.IF DX == 0
			mov EBX, 0
		.ENDIF
		add ESI, 2
		LOOP metka

		push - 1
		call ExitProcess
main ENDP

end main