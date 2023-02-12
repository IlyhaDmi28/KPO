#include <iostream>

extern "C" {
    int __stdcall getmin(int* Pointer, int Count);
    int __stdcall getmax(int* Pointer, int Count);
}


using namespace std;

int main()
{
    int ArrSize = 10;
    int* Arr = new int[ArrSize] { 12, 24, 52, 12, 7, 21, 693, 52, 14, 30 };

    int min = getmin(Arr, ArrSize);
    int max = getmax(Arr, ArrSize);

    int sum = min + max;

    cout << "getmin + getmax = " << sum;
}
