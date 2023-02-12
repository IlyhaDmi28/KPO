#include <iostream>
#include <stack>

#include "CheckFun.h"

using namespace std;

bool PolishNotation(char *str) 
{
    stack<char> operators;
    string PolishNotation;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!IsNumber(str[i]) && !IsOperator(str[i]) && str[i] != ' ') return false;
    }

    for (int i = 0; str[i] != '\0'; i++)
    {   
        if(IsNumber(str[i]) || str[i] == ' ') PolishNotation.push_back(str[i]);
        else if (IsOperator(str[i])) 
        {
            if (str[i] == '(') operators.push(str[i]);
            else if (str[i] == ')')
            {
                while (operators.top() != '(')
                {
                    PolishNotation.push_back(operators.top());
                    PolishNotation.push_back(' ');

                    operators.pop();
                }

                operators.pop();
            }
            else if (operators.empty() || operators.top() == '(') operators.push(str[i]);
            else if(GetPriority(str[i]) > GetPriority(operators.top())) operators.push(str[i]);
            else {
                while (!operators.empty() && GetPriority(str[i]) <= GetPriority(operators.top()))
                {
                    PolishNotation.push_back(operators.top());
                    PolishNotation.push_back(' ');

                    operators.pop();
                }

                operators.push(str[i]);
            }
        }
    }

    while (!operators.empty())
    {
        PolishNotation.push_back(operators.top());
        PolishNotation.push_back(' ');

        operators.pop();
    }

    cout << PolishNotation << endl;
    return true;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    char expression[] = "(12 + 39) / (5 - 13)";
    if (PolishNotation(expression)) cout << "\nПреобразование прошло успешно!";
    else cout << "Преобразование не удалось!";
}
