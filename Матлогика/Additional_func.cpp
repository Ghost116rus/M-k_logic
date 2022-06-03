#include "Additional_func.h"
#include "Header.h"
#include <iomanip>

extern int g_k;
extern int g_n;
extern int g_size;
extern std::stack <int*> g_stack;

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

int getValue(int condition, const char* string)
{
    while (true)													// цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        int a;
        std::cin >> a;

        if (std::cin.fail())										// если предыдущее извлечение оказалось неудачным,
        {
            std::cout << "Ошибка! Пожалуйста, повторите ввод! \n";
            std::cin.clear();										// то возвращаем cin в 'обычный' режим работы
            std::cin.ignore(32767, '\n');							// и удаляем значения предыдущего ввода из входного буфера
            std::cout << string;
        }
        else // если всё хорошо и выполнятся условия, то возвращаем a
        {
            switch (condition)
            {
            case 15:
                if ((a > 0) && (a < 100)) { return a; }

                std::cout << "Вы должны ввести натуральное число, меньше 100!\n Повторите ввод: ";
                std::cin.ignore(32767, '\n');						// и удаляем значения предыдущего ввода из входного буфера
                continue;

            case 16:												// На будущее

                if ((a == 0) || (a == 1)) { return a; }

                std::cout << "Вы должны ввести либо 0, либо 1\n";
                std::cin.ignore(32767, '\n');						// и удаляем значения предыдущего ввода из входного буфера
                continue;

            case 17:

                if ((a > 0) && (a < 3)) { return a; }

                std::cout << "Вы должны ввести либо 1, либо 2! Повторите ввод: ";
                std::cin.ignore(32767, '\n');						// и удаляем значения предыдущего ввода из входного буфера
                continue;

            default:
                return a;
            }

        }

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
    int* result = g_stack.top();
    int temp = expression.size() % 2;
    int width1 = (expression.size() + temp) / 2;
    int width2 = (expression.size() - temp) / 2;

    std::cout << "\n Результат работы программы:\n";
    if (g_n == 1) 
    { 
        std::cout << "| X |  " << expression << "  |\n";
        for (size_t i = 0; i < g_size; i++)
        {
            std::cout << "| " << i << " |  " << std::setw(width1) << result[i] << std::setw(width2) << "" << "  |\n";
        }

    }
    else if (g_n == 2) 
    {
        std::cout << "| X | Y |  " << expression << "  |\n";
        for (size_t i = 0; i < g_size; i++)
        {
            std::cout << "| " << i / g_k << " | " << i % g_k << " |  " << std::setw(width1) << result[i] << std::setw(width2) << "" << "  |\n";
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
