#include "Save_set.h"
#include "Additional_func.h"
#include <string>
#include <vector>
#include <stack>

extern int g_k;
extern int g_n;
extern int g_size;
extern std::stack <int*> g_stack;


using namespace std;

void input_set(string str, vector<int>& arr)
{
    int number;
    string temp;
    int index_start = str.find(' ');
    while (index_start != -1)
    {
        temp = str.substr(0, index_start);
        str.erase(0, index_start+1);

        if (TryParse(temp, number))
        {
            if (number > g_k - 1) { throw std::exception("В множестве найдено число больше k-1\n"); }
            arr.push_back(number);
        }

        index_start = str.find(' ');
        number = 500;
    }
    if (TryParse(str, number))
    {
        if (number > g_k - 1) { throw std::exception("В множестве найдено число больше k-1\n"); }
        arr.push_back(number);
    }
}


void save_set(bool& save)
{
    std::cout << "Введите через пробел множество: ";
    string str; getline(cin, str);

    vector<int> my_set;

    try
    {
        input_set(str, my_set);
        int* res_table = g_stack.top();
        
        int index;
        string temporary;

        if (g_n == 2)
        {
            int iterator = 0;
            int** new_arr = new int* [g_k];

            for (size_t i = 0; i < g_k; i++)
            {
                new_arr[i] = new int[g_k];
                for (size_t j = 0; j < g_k; j++)
                {
                    new_arr[i][j] = res_table[iterator++];
                }
            }

            for (size_t i = 0; i < my_set.size(); i++)
            {
                for (size_t j = 0; j < my_set.size(); j++)
                {
                    temporary = to_string(new_arr[my_set[i]][my_set[j]]);
                    index = str.find(temporary);
                    if (index == -1) { cout << "Функция не сохраняет данное множество!"; return; save = false; }
                }
            }

            for (size_t j = 0; j < g_k; j++)
            {
                delete[] new_arr[j];
            }
            delete[] new_arr;
        }
        else
        {
            for (size_t i = 0; i < my_set.size(); i++)
            {
                temporary = to_string(res_table[my_set[i]]);
                index = str.find(temporary);
                if (index == -1) { cout << "Функция не сохраняет данное множество!"; return; save = false; }
            }
        }
        cout << "Функция сохраняет данное множество!\n"; save = true;
    }
    catch (const std::exception& m1)
    {
        cout << m1.what() << endl;
    }




}