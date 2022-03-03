#include <iostream>
#include <fstream>        // для файловых потоков
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>   // для getche()
#include <locale>
using namespace std;

enum itsaWord { NO, YES, DOT};     // NO=0, YES=1 DOT=2
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "russian");
    itsaWord isWord = NO;        // isWord равно YES, когда
    // вводится слово, и NO, когда вводятся пробелы
    char ch = 'a';                 // считывание символа с клавиатуры
    int wordcount = 0;           // число слов
    int sentenceCount = 0;              //число предложений
    cout << "Введите предложение: \n";

    ifstream infile;
    infile.open("1.txt");
    if (!infile)           // проверить на наличие ошибок
    {
        cout << "Error Open \n";
    }
    infile.get(ch);
    do {
        ch = _getche();             // ввод символа
        if (ch == ' ' || ch == '\r')  // если введен пробел,
        {
            if (isWord == YES)      // а до этого вводилось слово,
            {                        // значит, слово закончилось
                wordcount++;           // учет слова
                isWord = NO;           // сброс флага
            }
        }                          // в противном случае
        else                       // ввод слова продолжается
            if (ch == '.' || ch == '!' || ch == '?')//конец предложения
            {
                if (isWord == YES || isWord == NO)//если еще не было конца пердложения
                {
                    isWord = DOT;
                    sentenceCount++;
                }                
            }
            else                                        //все остальные случаи, помимо точек и пробелов - слова
                if(isWord == NO || isWord==DOT)        // если начался ввод слова,
                   isWord = YES;              // то устанавливаем флаг
    } while (ch != '\r');     // выход по нажатию Enter
    cout << "\n---Число слов: " << wordcount << "---\n"<<"---Число предложений:"<<sentenceCount << "---\n";
    return 0;
}

