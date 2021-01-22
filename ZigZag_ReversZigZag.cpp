// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<string>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows == 0) {
            return std::string();
        }
        else if (numRows == 1 || numRows == -1) {
            return s;
        }
        int inListPoz = numRows-1, rowItr = 1, startPoz = 0, initialRowSize = s.size();
        if (numRows < 0) {
            numRows *= -1;
            startPoz = numRows-1;
            inListPoz = startPoz;
            rowItr = -1;
        }
        std::string finalRow;
        finalRow.resize(initialRowSize);
        int i = 0;
        for (int inRowShift[2]{ 2 * startPoz ,  2 * (numRows - startPoz - 1)}; 0 <= startPoz && startPoz < numRows; startPoz += rowItr, inRowShift[0] = 2 * startPoz, inRowShift[1] = 2 * inListPoz - inRowShift[0]) {
            //std::cout << startPoz << " " << inRowShift[1] << " " << inRowShift[0] << std::endl;
            
            int j = 1, inRowItr = startPoz;
            while (inRowItr < initialRowSize) {
                if (inRowShift[j % 2] != 0) {
                    finalRow[i] = s[inRowItr];
                    inRowItr += inRowShift[j % 2];
                    i++;
                }
                j++;
            }

        }
        return finalRow;
    }
};

int main()
{
    Solution a;
    std::string s;
    s.resize(1000);
    s = "012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789";
    for (int itr = -6; itr < 7; itr++) {
        a.convert(s, itr);
        //std::cout << a.convert(s, itr) << std::endl;
    }
    return 0;
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
