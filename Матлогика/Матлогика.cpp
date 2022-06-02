// Матлогика.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int k = 3;
int n = 2;
int _size = pow(k,n);

stack <int*> _stack;

void unary_negation(int* table)
{
    for (size_t i = 0; i < k; i++)
    {

    }
}

void calculate(string analytic_form)
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
        calculate(new_form);

        index_start = analytic_form.find('(');
    }

    int index_multiplacation = -1;
    index_multiplacation = analytic_form.find('*');
    
    if (index_multiplacation != -1)
    {
        string front_part = analytic_form.substr(0, index_multiplacation);
        string end_part = analytic_form.substr(index_multiplacation + 1, analytic_form.size() - index_multiplacation - 1);
        analytic_form = "*";
        if (front_part != "") { calculate(front_part); }
        if (end_part != "") { calculate(end_part); }

    }

    int index_negotioation = -1;
    index_negotioation = analytic_form.find('-');

    if (index_negotioation != -1)
    {
        string end_part = analytic_form.substr(index_negotioation + 1, analytic_form.size() - index_negotioation - 1);
        analytic_form = "-";
        if (end_part != "") { calculate(end_part); }
    }


    if (analytic_form[0] == 'x')
    {
        int* arr = new int[_size];
        for (size_t i = 0; i < _size; i++)
        {
            arr[i] = i / k;
        }
        _stack.push(arr);
    }
    else if (analytic_form[0] == 'y')
    {
        int* arr = new int[_size];
        for (size_t i = 0; i < _size; i++)
        {
            arr[i] = i % k;
        }
        _stack.push(arr);
    }


}


int main()
{
    setlocale(LC_ALL, "ru");

   

    string input;
    getline(cin, input);

    calculate(input);



}
// (hello(was is was)(do))(maybe)
// hello dear (really (i print it there (and don't think about) and ((wow)))) (hello)
// -((-x)*((x*(-y))*x)*(-1))