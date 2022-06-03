#include "Calculate.h"

int k = 5;
int n = 1;
int _size;
std::stack <int*> _stack;

using namespace std;

bool check(string str)
{
    if (str == "") { std::cout << "������� ������ ������!\n"; return false; }

    int open_backets = 0; int close_backet = 0;
    bool alert = false; int temp = -1;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] == '(') { open_backets++; }
        else if (str[i] == ')') { alert = false; close_backet++; }
        else if (TryParse(str[i])) { alert = true; }
        else if (str[i] == '*') { alert = false; }
        else if (str[i] == 'x' || str[i] == 'y' || str[i] == '-') { if (alert) { std::cout << "����� ����� �������� ���� '*' ��� ')'\n"; return false; } }
        else { std::cout << "������ ������������ ������!\n"; return false; }
    }
    if (open_backets != close_backet) { std::cout << "��������� ������ ������� �������� � �������\n"; return false; }
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
    cout << "��� ������ ������ ������� 1, ���� ������ ����� - 0\n �������: ";
    user_opinion = getValue(16, "��� ������ ������ ������� 1, ���� ������ ����� - 0\n");

    while (user_opinion)
    {
        cout << "������� ����� k: ";
        k = getValue(15, "������� ����� k: ");

        cout << "������� ����� n (1 ��� 2): ";
        n = getValue(15, "������� ����� k: ");

        _size = pow(k, n);

        std::cin.ignore(32767, '\n');
        string input; cout << "������� �������: ";
        getline(cin, input);

        if (input == "exit") { break; }

        clean_from_space(input);

        if (!check(input)) { std::cout << "��������� ����!\n���� ����� �����������, ��� ������ ����� ������� �������� \"exit\"\n"; continue; }

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
            std::cout << "\n��������� ������ �����������!\n";
        }

        cout << "��� ����������� ������ ������� 1, ���� ������ ����� - 0\n �������: ";
        user_opinion = getValue(16, "��� ������ ������ ������� 1, ���� ������ ����� - 0\n");
    }



}