#include <iostream>
#include <string>
#include "Header.h"

using namespace std;

int main()
{
    setlocale(LC_ALL,"Russian");
    string pass="";
    int choise=0;
    cout << "Введите пароль: " << endl;
    getline(cin, pass);
    if (pass != "3244") { cout << "\nНеверный пароль" ;
    exit(0); }
    cout << "Добро пожаловать!\n";
    while (1){
        cout << "Введите номер для выбора метода шифрования: \n1)Шифр Вижинера \n2)Шифр Цезаря \n3)Квадрат Полибия \n4)Шифр Атбаш \n5)Шифр Гронсфельда \nЧтобы выйти из программы, введите 0\n";
        cin >> choise;
        int status;
        switch (choise) {
        case 0: {
            cout << "\nSee you next time!";
            exit(0);
        }
        case 1: {
            cout << "Выберите операцию: \n1)Зашифровать \n2)Расшифровать \n";
            cin >> status;
            viginer(status);
            break;
        }
        case 2: {
            cout << "Выберите операцию: \n1)Зашифровать \n2)Расшифровать \n";
            cin >> status;
            caesar(status);
            break;
        }
        case 3: {
            cout << "Выберите операцию: \n1)Зашифровать \n2)Расшифровать \n";
            cin >> status;
            polibia(status);
            break;
        }
        case 4: {
            cout << "Выберите операцию: \n1)Зашифровать \n2)Расшифровать \n";
            cin >> status;
            atbash(status);
            break;
        }
        case 5: {
            cout << "Выберите операцию: \n1)Зашифровать \n2)Расшифровать \n";
            cin >> status;
            gronsfeld(status);
            break;
        }
        default: {cout << "Нет такого шифра, попробуйте еще раз\n"; }
        }
    }
}