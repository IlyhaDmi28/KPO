#pragma once
bool IsOperator(char oper) 
{
	return oper == '(' || oper == ')' || oper == '+' || oper == '-' || oper == '/' || oper == '*';
}

bool IsNumber(char numb) 
{
	return numb == '0' || numb == '1' || numb == '2' || numb == '3' || numb == '4' || numb == '5' || numb == '6' || numb == '7' ||
		numb == '8' || numb == '9';
}

short GetPriority(char oper) 
{
	switch (oper)
	{
	case '(':
		return 1;
	case ')':
		return 1;
	case '+':
		return 2;
	case '-':
		return 2;
	case '*':
		return 3;
	case '/':
		return 3;
	default:
		return 0;
	}
}