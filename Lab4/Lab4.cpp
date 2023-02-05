#include "stdfax.h"

int main()
{
    setlocale(LC_ALL, "RUS");
    try 
    {
        ReadFile();
        cout << "Сериализация прошла успешно!" << endl;
    }
    catch (const char* ex)
    {
        cout << ex;
    }
}
