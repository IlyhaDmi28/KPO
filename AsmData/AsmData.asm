.586P
.MODEL FLAT, STDCALL
includelib kernel32.lib

ExitProcess PROTO : DWORD
MessageBoxA PROTO : DWORD, : DWORD, : DWORD, : DWORD

.STACK 4096

.CONST

.DATA

MB_OK	EQU 0
STRF    BYTE " ", 0
STR1	BYTE "Переменная bool: ", 0
STR2	BYTE "Литерал:     ", 0
 VarBool BYTE 0
NumbLiteral BYTE "4533", 0
Numb EQU 7
HW		DB ? 
STROFF1 EQU 16
STROFF2 EQU 9

.CODE

main PROC
START :
mov ESI, OFFSET STR1
add ESI, STROFF1
mov AL, VarBool
add AL, 30h
mov BYTE ptr[ESI], AL

invoke MessageBoxA, MB_OK, offset STR1, offset STRF, HW

mov ESI, 0

MOV ECX, 0
MOV EAX, 0

.WHILE 0
	MOV ESI, OFFSET STR2
	ADD ESI, STROFF2
	ADD ESI, ECX

	MOV EDI, OFFSET NumbLiteral
	ADD EDI, ECX

	MOV DL, BYTE PTR[EDI]

	MOV[ESI], DL

	INC ECX
	.ENDW

	invoke MessageBoxA, MB_OK, offset STR2, offset STRF, HW

	push - 1
	call ExitProcess

	main ENDP
	end main