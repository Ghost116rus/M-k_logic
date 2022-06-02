// Матлогика.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <string>
#include <vector>

using namespace std;

int k = -1;

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
    if (analytic_form != "")
    {
        std::cout << analytic_form << std::endl;
    }


}
// (hello(was is was)(do))(maybe)
// hello dear (really (i print it there (and don't think about) and ((wow)))) (hello)

int main()
{
    setlocale(LC_ALL, "ru");

   

    string input;
    getline(cin, input);

    calculate(input);



}
