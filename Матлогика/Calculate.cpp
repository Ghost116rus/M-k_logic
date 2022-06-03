#include "Calculate.h"

extern int g_k;
extern int g_n;
extern int g_size;
extern std::stack <int*> g_stack;

void unary_negation_func()
{
    int* result = g_stack.top();
    g_stack.pop();

    for (size_t i = 0; i < g_size; i++)
    {
        result[i] = unary_negation(result[i]);
    }

    g_stack.push(result);
}


void multiplicate_func()
{
    int* res_table1 = g_stack.top();
    g_stack.pop();

    int* res_table2 = g_stack.top();
    g_stack.pop();

    int* result = new int[g_size];

    for (size_t i = 0; i < g_size; i++)
    {
        result[i] = multiplicate(res_table1[i], res_table2[i]);
    }
    delete res_table1; delete res_table2;

    g_stack.push(result);
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
            arr = new int[g_size];
            for (size_t i = 0; i < g_size; i++)
            {
                arr[i] = i / (g_size / g_k);
            }
        }
        else if (symbol[0] == 'y')
        {
            arr = new int[g_size];
            for (size_t i = 0; i < g_size; i++)
            {
                arr[i] = i % g_k;
            }

        }
        int temp = 0;
        if (TryParse(symbol, temp))
        {
            if (temp > g_k - 1)
            {
                std::cout << "Найдено число больше k-1\n";
                throw std::exception();
            }
            else
            {
                arr = new int[g_size];
                for (size_t i = 0; i < g_size; i++)
                {
                    arr[i] = temp;
                }
            }

        }
        if (arr) { g_stack.push(arr); }

    }

}

void make_first_form()
{
    int* res_table1 = g_stack.top();
    bool printed = false;

    std::cout << "Первая форма, аналог СДНФ: ";

    if (g_n == 1)
    {
        for (size_t i = 0; i < g_k; i++)
        {
            if (res_table1[i] != 0)
            {   
                if (printed) { std::cout << " & "; }

                if (res_table1[i] != g_k - 1)
                {
                    std::cout << res_table1[i] << "&";
                }
                std::cout << "J_" << i << "(x)";
                printed = true;
            }
        }
    }
    else
    {
        int iterator = 0;
        for (size_t i = 0; i < g_k; i++)
        {
            for (size_t j = 0; j < g_k; j++)
            {
                if (res_table1[iterator] != 0)
                {
                    if (printed) { std::cout << " & "; }
                    if (res_table1[iterator] != g_k - 1)
                    {
                        std::cout << res_table1[iterator] << "&";
                    }
                    std::cout << "J_" << i << "(x)&" << "J_" << j << "(y)";
                    printed = true;
                }
                iterator++;
            }
        }
    }

    if (!printed) { std::cout << "В таблице все нули!\n"; }
    std::cout << std::endl;
}