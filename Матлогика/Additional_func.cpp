#include "Additional_func.h"
#include "Header.h"
#include <iomanip>

extern int k;
extern int n;
extern int _size;
extern std::stack <int*> _stack;

bool TryParse(char ch)
{
    try
    {
        std::string temp;
        temp += ch;
        std::stoi(temp);
        return true;
    }
    catch (const std::exception& nothing)
    {
        return false;
    }
}

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

void print_Hat()
{
    std::cout << "Работу выполнил Калеев Д.А, группа 4211\n"
        << "g = 11, n = 8.\n"
        << "Функия одного аргумента - (g + n - 1)(mod 6) + 1 = 1 ~ -x    - Унарное отрицание\n"
        << "Функция двух аргументов - (g + n - 1)(mod 7) + 1 = 5 ~ x * y - Произведение по модулю k\n"
        << "Стандартная форма представления - (g + n - 1)(mod 3) + 1 = 1 ~ Первая форма (аналог СДНФ)\n"
        << "\n\n Ввод функции: -x ~ Унарное отрицание, x*y ~ Произведение по модулю k\n\n";
}

void print_Res(std::string expression)
{
    int* result = _stack.top();
    int temp = expression.size() % 2;
    int width1 = (expression.size() + temp) / 2;
    int width2 = (expression.size() - temp) / 2;
    if (n == 1) 
    { 
        std::cout << "| X |  " << expression << "  |\n";
        for (size_t i = 0; i < _size; i++)
        {
            std::cout << "| " << i << " |  " << std::setw(width1) << result[i] << std::setw(width2) << "" << "  |\n";
        }

    }
    else if (n == 2) 
    {
        std::cout << "| X | Y |  " << expression << "  |\n";
        for (size_t i = 0; i < _size; i++)
        {
            std::cout << "| " << i / k << " | " << i % k << " |  " << std::setw(width1) << result[i] << std::setw(width2) << "" << "  |\n";
        }

    }
}

void clean_from_space(std::string& str)
{
    int index_start = str.find(' ');

    while (index_start != -1 )
    {
        str.erase(index_start, 1);
        index_start = str.find(' ');
    }


}
