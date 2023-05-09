 // OOPLab4T.cpp : Цей файл містить є шаблоном для 
// виконання лаб. роботи №4. 
// Він містинь функцію "main" з якої починається та закінчується виконання програми.
//


#include <iostream>
using namespace std;
// Ваші файли загловки 
//
#include "task1.h"
#include "task2.h"

void menutask1() 
{
    VectorLong vector1(3, 1), vector2(3, 2), vector3(3, 3);
    vector1 = (++(-(vector2 + vector3)) % 3);
    vector1.Print();
}
void menutask2()
{
    EData data;
    string post;
    string PIB;
    int choose = 0;
    do
    {

        cout << "Choose task: " << endl;
        cout << "1. Add info" << endl;
        cout << "2. Index mail" << endl;
        cout << "3. Print all info" << endl;
        cout << "0. Exit" << endl;
        cin >> choose;
        system("cls");

        if (choose == 1)
        {
            system("cls");
            cout << "Size: " << data.getSize() + 1 << endl;
            cout << "Code error: " << data.getCodeError() << endl;
            cout << "Input info(post, PIB):" << endl;
            cout << "Input mail:";
            cin >> post;
            cout << "Input PIB:";
            cin >> PIB;
            data.AddPerson(post, PIB);
            cout << endl;
        }
        else if (choose == 2)
        {
            system("cls");
            cout << "Input mail:";
            cin >> post;
            pair<string, string>pers = data[post];
            cout << pers.first << "\t" << pers.second << endl;
            cout << "Code error: " << data.getCodeError() << endl;
        }
        else if (choose == 3)
        {
            system("cls");
            cout << data;
        }
   } while (choose != 0);

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
            menutask2();
            break;
        default:
            system("cls");
            break;
        }
    } while (choose != 0);
  
}


