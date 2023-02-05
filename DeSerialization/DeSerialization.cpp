#include "stdfax.h"

int main()
{
    setlocale(LC_ALL, "RUS");
    try
    {
        ReadFile();
        cout << "Десериализация прошла успешно!" << endl;
    }
    catch (const char* ex)
    {
        cout << ex;
    }
}
