// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
// https://leetcode.com/problems/count-good-meals/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
typedef long long ll;
int countPairs(vector<int>& deliciousness) {
    int n = deliciousness.size();
    long long int count = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[deliciousness[i]]++;
    sort(deliciousness.begin(), deliciousness.end(), greater<int>());
    deliciousness.erase(unique(deliciousness.begin(), deliciousness.end()), deliciousness.end());
    n = deliciousness.size();
    for (int i = 0; i < n; i++) {
        int cur = 1;
        unsigned long long int m1;
        for (; cur < deliciousness[i]; cur <<= 1) {}
        for (; cur - deliciousness[i] <= deliciousness[i]; cur <<= 1) {
            if (mp[cur - deliciousness[i]]) {
                if (cur - deliciousness[i] == deliciousness[i]) {
                    m1 = mp[deliciousness[i]];
                    m1 *= (mp[deliciousness[i]] - 1);
                    count += m1 / 2;
                    continue;
                }
                count += mp[cur - deliciousness[i]] * mp[deliciousness[i]];
            }
        }
    }
    return count % (1000000000 + 7);
}

int main()
{
    //vector<int> a{};
    vector<int> a { 149,107,1,63,0,1,6867,1325,5611,2581,39,89,46,18,12,20,22,234 };
   // a.insert(a.begin(), 100000, 32);
    std::cout << countPairs(a) << endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
