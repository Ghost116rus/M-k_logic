#include "Calculate.h"

int k = 3;
int n = 1;
int _size = pow(k, n);
std::stack <int*> _stack;



using namespace std;

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
    string input; cout << "¬ведите функцию: ";
    getline(cin, input);



    analyze(input);



    int* temp = _stack.top();

    cout << endl;
    for (size_t i = 0; i < _size; i++)
    {
        cout << temp[i] << endl;
    }
}