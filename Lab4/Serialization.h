#pragma once
#define BOOL "0x01"
#define SHORT "0x02"
#define TRUE "0x0001"
#define FALSE "0x0000"

struct MyData
{
	string Type;
	string Value;
};

void ReadFile();