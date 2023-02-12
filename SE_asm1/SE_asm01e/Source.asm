.586
.MODEL flat, stdcall

includelib kernel32.lib
includelib ucrt.lib

system		PROTO C : DWORD

ExitProcess		 PROTO : DWORD
SetConsoleTitleA PROTO : DWORD
GetStdHandle	 PROTO : DWORD

WriteConsoleA	 PROTO : DWORD, : DWORD, : DWORD, : DWORD, : DWORD

SetConsoleOutputCP PROTO : DWORD
SetConsoleCP	   PROTO : DWORD

getmin		PROTO : DWORD, : DWORD
getmax		PROTO : DWORD, : DWORD
intToChar			PROTO : DWORD, : DWORD, : DWORD

.STACK 4096

.CONST
endl	 EQU  0ah
str_endl BYTE endl,0

.DATA
array    DD  88, 22, 99, 693, 67, 10, 7, 45, 56, 77
arrCount EQU 10

min      DD  ?
max      DD  ?
Sum		 DWORD ?

ConsoleTitle	BYTE "My result", 0
message			BYTE "getmin + getmax = ", 0

HW				=($ - message)
messageSize		DWORD ?

Sum_SubStr		BYTE 5 dup(0)
SubStrSize		EQU  5

ConsoleHandle	DWORD 0h

.CODE

main PROC
START:
		mov messageSize, HW

		INVOKE getmin, offset array, arrCount

		mov min, EAX

		INVOKE getmax, offset array, arrCount

		mov max, EAX

		mov EAX, 0
		mov EAX, min
		add EAX, max

		mov Sum, EAX

		INVOKE intToChar, Sum, offset Sum_SubStr, SubStrSize

		INVOKE SetConsoleTitleA, offset ConsoleTitle

		INVOKE GetStdHandle, -11

		mov ConsoleHandle, EAX

		INVOKE WriteConsoleA, ConsoleHandle, offset message, messageSize, 0, 0
		INVOKE WriteConsoleA, ConsoleHandle, offset Sum_SubStr, SubStrSize, 0, 0

		

	push 0
	call ExitProcess

main ENDP

end main