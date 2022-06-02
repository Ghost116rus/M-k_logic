#include "Additional_func.h"
#include "Header.h"

extern int k;
extern int n;
extern int _size;
extern std::stack <int*> _stack;

bool TryParse(std::string str, int& a)
{
    try
    {
        a = std::stoi(str);
        return true;
    }
    catch (const std::exception& nothing)
    {
        return false;
    }
}

