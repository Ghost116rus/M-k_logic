#include "Logic.h"
#include  "Header.h"

extern int g_k;
extern int g_n;
extern int g_size;
extern std::stack <int*> g_stack;

int unary_negation(int x)
{
    return x > 0 ? g_k - x : 0;
}

int multiplicate(int x, int y)
{
    return x * y % g_k;
}