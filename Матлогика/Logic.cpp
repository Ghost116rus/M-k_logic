#include "Logic.h"
#include  "Header.h"

extern int k;
extern int n;
extern int _size;
extern std::stack <int*> _stack;

int unary_negation(int x)
{
    return x > 0 ? k - x : 0;
}

int multiplicate(int x, int y)
{
    return x * y % k;
}