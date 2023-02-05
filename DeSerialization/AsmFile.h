#pragma once
#define ASM1 ".586P\n\
.MODEL FLAT, STDCALL\n\
includelib kernel32.lib\n\
\n\
ExitProcess PROTO : DWORD\n\
MessageBoxA PROTO : DWORD, : DWORD, : DWORD, : DWORD\n\
\n\
.STACK 4096\n\
\n\
.CONST\n\
\n\
.DATA\n\
\n\
MB_OK	EQU 0\n\
STRF    BYTE \" \", 0\n\
STR1	BYTE \"Переменная bool: \", 0\n\
STR2	BYTE \"Литерал:     \", 0\n\ "

#define ASM2 "\n\
HW		DB ? \n\
STROFF1 EQU 16\n\
STROFF2 EQU 9\n\
\n\
.CODE\n\
\n\
main PROC\n\
START :\n\
mov ESI, OFFSET STR1\n\
add ESI, STROFF1\n\
mov AL, VarBool\n\
add AL, 30h\n\
mov BYTE ptr[ESI], AL\n\
\n\
invoke MessageBoxA, MB_OK, offset STR1, offset STRF, HW\n\
\n\
mov ESI, 0\n\
\n\
MOV ECX, 0\n\
MOV EAX, 0\n\
\n\
.WHILE ECX < Numb\n\
	MOV ESI, OFFSET STR2\n\
	ADD ESI, STROFF2\n\
	ADD ESI, ECX\n\
\n\
	MOV EDI, OFFSET NumbLiteral\n\
	ADD EDI, ECX\n\
\n\
	MOV DL, BYTE PTR[EDI]\n\
\n\
	MOV[ESI], DL\n\
\n\
	INC ECX\n\
	.ENDW\n\
\n\
	invoke MessageBoxA, MB_OK, offset STR2, offset STRF, HW\n\
\n\
	push - 1\n\
	call ExitProcess\n\
\n\
	main ENDP\n\
	end main"