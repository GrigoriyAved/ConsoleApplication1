/******************************************************************************
Аведикян Григорий Петрович
КТбо1-2
Лабораторная работа №4 «Файлы данных»
Вариант № 4
Задание: Написать   программу,   которая   во   вводимом   с   клавиатуры  тексте  выберет  слова,  количество  букв  «м»  в  которых будет максимально, и выведет  их на экран. 
*******************************************************************************/

#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    ofstream fout;
    ifstream fin;
    const int N = 1000;
    const int M = 53;
    int count = 0;
    char str[N];
    char letter[M] = "QqWwEeRrTtYyUuIiOoPpAaSsDdFfGgHhJjKkLlZzXxCcVvBbNnMm";
    char wordwithM[N];
    char buffer[N];
    int countM = 1;
    int countMword = 0;
    int n = 0;
    int i = 0;
    int t = 0;




    fin.open("1.txt");
    fout.open("2.txt");

    if (!fout.is_open())
    {
        cout << "Ошибка вывода файла";
        return 0;
    }

    if (!fin.is_open()) {
        cout << "Ошибка чтения файла";
        return 0;
    }

    char ch;
    for (count; fin.get(ch); count++)
    {
        str[count] = ch;

    }
    for (i; i < count; i++)
    {
        bool f = (find(begin(letter), end(letter), str[i]) != end(letter));
        if (f)
        {
            break;
        }
    }
    for (i; i < count; i++)
    {
        n = i;

        for (n; find(begin(letter), end(letter), str[n]) != end(letter) && n <= count; n++)
        {
            if (str[n] == 'm' || str[n] == 'M')
            {
                countMword++;
            }

        }
        if (countM == countMword)
        {
            for (i; i < n; i++)
            {
                wordwithM[t] = str[i];
                t++;
            }
            wordwithM[t] = ';';
            t++;


        }
        if (countM < countMword)
        {
            for (int p = 0; p <= t; p++)
            {
                wordwithM[p] = ' ';
            }
            t = 0;
            for (i; i < n; i++)
            {
                wordwithM[t] = str[i];
                t++;
            }
            countM = countMword;
            wordwithM[t] = ';';
            t++;
        }

        i = n;
        countMword = 0;
    }

    for (int p = 0; p <= t; p++)
    {
        fout << wordwithM[p];
    }

    fin.close();
    fout.close();

    return 0;
}
