#include "Calculate.h"

extern int k;
extern int n;
extern int _size;
extern std::stack <int*> _stack;

void unary_negation_func()
{
    int* result = _stack.top();
    _stack.pop();

    for (size_t i = 0; i < _size; i++)
    {
        result[i] = unary_negation(result[i]);
    }

    _stack.push(result);
}



void multiplicate_func()
{
    int* res_table1 = _stack.top();
    _stack.pop();

    int* res_table2 = _stack.top();
    _stack.pop();

    int* result = new int[_size];

    for (size_t i = 0; i < _size; i++)
    {
        result[i] = multiplicate(res_table1[i], res_table2[i]);
    }
    delete res_table1; delete res_table2;

    _stack.push(result);
}


void calculate(std::string symbol)
{
    if (symbol[0] == '*')
    {
        multiplicate_func();
    }
    else if (symbol[0] == '-')
    {
        unary_negation_func();
    }
    else
    {
        int* arr = nullptr;
        if (symbol[0] == 'x')
        {
            arr = new int[_size];
            for (size_t i = 0; i < _size; i++)
            {
                arr[i] = i / (_size / k);
            }
        }
        else if (symbol[0] == 'y')
        {
            arr = new int[_size];
            for (size_t i = 0; i < _size; i++)
            {
                arr[i] = i % k;
            }

        }
        int temp = 0;
        if (TryParse(symbol, temp))
        {
            arr = new int[_size];
            for (size_t i = 0; i < _size; i++)
            {
                arr[i] = temp;
            }
        }
        if (arr) { _stack.push(arr); }

    }

}