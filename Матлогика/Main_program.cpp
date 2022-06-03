#include "Calculate.h"

int k = 5;
int n = 1;
int _size;
std::stack <int*> _stack;

using namespace std;

bool check(string str)
{
    if (str == "") { std::cout << "Введена пустая строка!\n"; return false; }

    int open_backets = 0; int close_backet = 0;
    bool alert = false; int temp = -1;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] == '(') { open_backets++; }
        else if (str[i] == ')') { alert = false; close_backet++; }
        else if (TryParse(str[i])) { alert = true; }
        else if (str[i] == '*') { alert = false; }
        else if (str[i] == 'x' || str[i] == 'y' || str[i] == '-') { if (alert) { std::cout << "После числа возможно лишь '*' или ')'\n"; return false; } }
        else { std::cout << "Найден неопознанный символ!\n"; return false; }
    }
    if (open_backets != close_backet) { std::cout << "Первичный осмотр показал проблему в скобках\n"; return false; }
}


void analyze(string analytic_form)
{
    int index_start = -1; int index_end = -1;

    index_start = analytic_form.find('(');

    while (index_start != -1)
    {
        int count_open_bracket = 1;
        index_end = index_start;
        while (count_open_bracket != 0)
        {
            index_end++;
            if (analytic_form[index_end] == '(') { count_open_bracket++; }
            else if (analytic_form[index_end] == ')') { count_open_bracket--; }
        }

        string new_form = analytic_form.substr(index_start + 1, index_end - index_start - 1);
        analytic_form.erase(index_start, index_end - index_start + 1);
        analyze(new_form);

        index_start = analytic_form.find('(');
    }

    int index_multiplacation = -1;
    index_multiplacation = analytic_form.find('*');

    if (index_multiplacation != -1)
    {
        string front_part = analytic_form.substr(0, index_multiplacation);
        string end_part = analytic_form.substr(index_multiplacation + 1, analytic_form.size() - index_multiplacation - 1);
        analytic_form = "*";
        if (front_part != "") { analyze(front_part); }
        if (end_part != "") { analyze(end_part); }

    }

    int index_negotioation = -1;
    index_negotioation = analytic_form.find('-');

    if (index_negotioation != -1)
    {
        string end_part = analytic_form.substr(index_negotioation + 1, analytic_form.size() - index_negotioation - 1);
        analytic_form = "-";
        if (end_part != "") { analyze(end_part); }
    }

    calculate(analytic_form);
}


void m_logic_programm()
{
    print_Hat();
    int user_opinion = -1;
    cout << "Для начала работы нажмите 1, если хотите выйти - 0\n Введите: ";
    user_opinion = getValue(16, "Для начала работы нажмите 1, если хотите выйти - 0\n");

    while (user_opinion)
    {
        cout << "Введите число k: ";
        k = getValue(15, "Введите число k: ");

        cout << "Введите число n (1 или 2): ";
        n = getValue(15, "Введите число k: ");

        _size = pow(k, n);

        std::cin.ignore(32767, '\n');
        string input; cout << "Введите функцию: ";
        getline(cin, input);

        if (input == "exit") { break; }

        clean_from_space(input);

        if (!check(input)) { std::cout << "Неудачный ввод!\nЦикл будет перезапущен, для выхода вводе функции напишите \"exit\"\n"; continue; }

        try
        {
            analyze(input);
            print_Res(input);
            int* result = _stack.top();
            _stack.pop();
            delete result;
        }
        catch (const std::exception&)
        {
            std::cout << "\nВведенные данные некорректны!\n";
        }

        cout << "Для продолжения работы нажмите 1, если хотите выйти - 0\n Введите: ";
        user_opinion = getValue(16, "Для начала работы нажмите 1, если хотите выйти - 0\n");
    }



}