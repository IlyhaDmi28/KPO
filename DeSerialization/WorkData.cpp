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
    char* j;
    long long IntNum = strtol(ArrNumb, &j, 16);
    if (IntNum > 0x7FFF && IntNum <= 0xFFFF) { return (short)IntNum; }
    if (IntNum > INT16_MAX || IntNum < INT16_MIN) throw "Ошибка! Размер литерала превышает 2 байта";
    return IntNum;
}

void OutASM()
{
    ofstream fout("D:\\KPO\\Laba4\\AsmData\\AsmData.asm");
    if (Variable.Value == "0x0001") fout << ASM1 << "VarBool BYTE 1\nNumbLiteral BYTE \"" << LiteralToNumb(Literal.Value) << "\", 0\nNumb EQU " << Literal.Value.size() + 1 << ASM2;
    if (Variable.Value == "0x0000") fout << ASM1 << "VarBool BYTE 0\nNumbLiteral BYTE \"" << LiteralToNumb(Literal.Value) << "\", 0\nNumb EQU " << Literal.Value.size() + 1 << ASM2;

}

void OutData()
{
    if (Variable.Type != "0x01" || Literal.Type != "0x02") throw "Ошибка! Некорректоно указан тип данных";
    if (Variable.Value != "0x0001" && Variable.Value != "0x0000") throw "Ошибка! Значение типа bool может быть только true или false";
    ofstream fout("D:\\KPO\\Laba4\\AsmData\\MyData.txt");
    if (Variable.Type == "0x01" && Variable.Value == "0x0001") fout << "bool" << ' ' << "true";
    if (Variable.Type == "0x01" && Variable.Value == "0x0000") fout << "bool" << ' ' << "false";
    fout << '\n';
    if (Literal.Type == "0x02") fout << LiteralToNumb(Literal.Value);
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
    while (source_data[i] != ' ')
    {
        i++;
    }
    i++;
    while (source_data[i] != '\n')
    {
        Literal.Value.push_back(source_data[i]);
        i++;
    }

    Literal.Type = "0x02";
    OutData();
}

void ReadFile()
{
    ifstream fin("D:\\KPO\\Laba4\\AsmData\\SerializationData.txt");
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

