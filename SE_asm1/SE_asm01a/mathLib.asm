.586
.MODEL flat, stdcall

.CODE

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

intToChar PROC Number: DWORD, SubString: DWORD, SubStrSize: DWORD

	mov EAX, Number
	mov EDX, 0
	mov EBX, 10
	mov ECX, SubStrSize
	dec ECX

	mov ESI, SubString

	.WHILE EAX > 0
		
		div EBX

		add EDX, 30h
		mov [ESI + ECX], DL

		mov EDX, 0

		dec ECX
	.ENDW

	ret
intToChar ENDP

end
