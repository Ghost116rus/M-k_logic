#pragma once
#include <iostream>

bool TryParse(char ch);
bool TryParse(std::string str, int& a);

void print_Res(std::string expression);
void clean_from_space(std::string& str);