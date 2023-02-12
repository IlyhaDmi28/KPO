extern "C" int __stdcall getmin(int* Pointer, int count) {
	int min = Pointer[0];
	for (int i = 0; i < count; i++)
	{
		if (Pointer[i] < min) min = Pointer[i];
	}
	return min;
}

extern "C" int __stdcall getmax(int* Pointer, int count) {
	int min = Pointer[0];
	for (int i = 0; i < count; i++)
	{
		if (Pointer[i] > min) min = Pointer[i];
	}
	return min;
}

extern "C" void __stdcall intToChar(int Number, char* SubString, int SubStrCount) {
	int offset = SubStrCount - 1;
	int ost;
	while (Number > 0)
	{
		ost = Number % 10;
		Number /= 10;

		SubString[offset] = ost + 0x30;

		offset--;
	}
}
