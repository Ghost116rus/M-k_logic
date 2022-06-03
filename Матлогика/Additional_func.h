#pragma once
#include <iostream>

bool TryParse(char ch);
bool TryParse(std::string str, int& a);

int getValue(int condition, const char* string);
void print_Hat();
void print_Res(std::string expression);
void clean_from_space(std::string& str);