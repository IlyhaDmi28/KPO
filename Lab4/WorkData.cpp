#include "stdfax.h"

MyData Variable;
MyData Literal;

int LiteralToNumb(string StrNumb)
{
    char ArrNumb[255];
    for (int i = 0; StrNumb[i] != '\0'; i++)
    {
        ArrNumb[i] = StrNumb[i];
    }
    long long IntNum = atoi(ArrNumb);
    if (IntNum > INT16_MAX || IntNum < INT16_MIN) throw "Ошибка! Размер литерала превышает 2 байта";
    return IntNum;
}

void OutASM()
{
    ofstream fout("D:\\KPO\\Laba4\\AsmData\\AsmData.asm");
    if (Variable.Value == "true") fout << ASM1 << "VarBool BYTE 1\nNumbLiteral BYTE \"" << Literal.Value  <<"\", 0\nNumb EQU " << Literal.Value.size() + 1 << ASM2;
    if (Variable.Value == "false") fout << ASM1 << "VarBool BYTE 0\nNumbLiteral BYTE \"" << Literal.Value << "\", 0\nNumb EQU " << Literal.Value.size() + 1 << ASM2;

}

void OutData()
{
    if (Variable.Type != "bool" || Literal.Type != "short") throw "Ошибка! Некорректоно указан тип данных";
    if (Variable.Value != "true" && Variable.Value != "false") throw "Ошибка! Значение типа bool может быть только true или false";
    ofstream fout("D:\\KPO\\Laba4\\AsmData\\SerializationData.txt");
    if (Variable.Type == "bool" && Variable.Value == "true") fout << BOOL << ' ' << TRUE;
    if (Variable.Type == "bool" && Variable.Value == "false") fout << BOOL << ' ' << FALSE;
    fout << '\n';
    if (Literal.Value[0] == '-') fout << SHORT << ' ' << "0x" << hex << LiteralToNumb(Literal.Value) - 0xFFFF0000;
    else fout << SHORT << ' ' << "0x" << hex << LiteralToNumb(Literal.Value);
    OutASM();
}

void ReadData(string source_data)
{
    int i = 0;
    while (source_data[i] != ' ')
    {
        Variable.Type.push_back(source_data[i]);
        i++;
    }
    i++;
    while (source_data[i] != '\n')
    {
        Variable.Value.push_back(source_data[i]);
        i++;
    }
    i++;
    Literal.Value = "";
    while (source_data[i] != '\n')
    {
        Literal.Value.push_back(source_data[i]);
        i++;
    }

    Literal.Type = "short";
    OutData();
}

void ReadFile() 
{
    ifstream fin("D:\\KPO\\Laba4\\AsmData\\MyData.txt");
    if (!fin.is_open()) throw "Ошибка! Не удалось найти файл";
    string source_data;
    while (!fin.eof())
    {
        string str;
        getline(fin, str);
        source_data = source_data + str + '\n';
    }
    ReadData(source_data);
}