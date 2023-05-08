 // OOPLab4T.cpp : Цей файл містить є шаблоном для 
// виконання лаб. роботи №4. 
// Він містинь функцію "main" з якої починається та закінчується виконання програми.
//


#include <iostream>
using namespace std;
// Ваші файли загловки 
//
#include "task1.h"
void menutask1() 
{
    VectorLong vector1(3, 1), vector2(3, 2), vector3(3, 3);
    vector1 = (++(-(vector2 + vector3)) % 3);
    vector1.Print();
}
int main()
{
    std::cout << " Lab #4  task chain  !\n";
    //  Код виконання завдань
    //  Головне меню завдань
    //  Функції та класи можуть знаходитись в інших файлах проекту

    int choose = 0;
    do
    {

        cout << "Choose task: " << endl;
        cin >> choose;
        system("cls");

        switch (choose)
        {
        case 1:
            system("cls");
            menutask1();
            break;
        case 2:
            system("cls");
            break;
        default:
            system("cls");
            break;
        }
    } while (choose != 0);
  
}