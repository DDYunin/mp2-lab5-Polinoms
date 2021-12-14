#include <iostream>
#include "TList.h"
#include "Monom.h"
#include "Polinom.h"
#include "Store.h"

extern bool fileIsExist;

using namespace std;

void PrintMenu();
void RulesWritePolinoms();
bool UseWritePolinomsInFileAuto();
bool WritePolinomInFile();
int ReadDataForPolinom(int _number);

int main() {
    setlocale(LC_ALL, "Rus");
    bool isWork = true;
    int counter = 0;
    bool downloadauto = false;
    StorePolinoms stp;
    try {
        while (isWork)
        {
            PrintMenu();
            cout << "Выберете один из пунктов меню: ";
            int menuChoice;
            cin >> menuChoice;
            if ((menuChoice < 0) || (menuChoice > 6))
                throw "Выбран недопустимый пункт меню";
            system("cls");
            if (menuChoice == 1)
            {
                string sp1, sp2, sp3;
                int number1, number2;
                cout << "\tВыбран пункт 1) Найти сумму полиномов\n";
                RulesWritePolinoms();
                switch (ReadDataForPolinom(counter))
                {
                case 1:
                    cout << "\tВведите первый полином: ";
                    cin >> sp1;
                    cout << "\n\tВведите второй полином: ";
                    cin >> sp2;
                    break;
                case 2:
                    PrintPolinomsFromFile();
                    cout << "\tВведите номер сохранённого полинома: ";
                    cin >> number1;
                    sp1 = ReadPolinomFromFile(number1);
                    cout << "\n\tВведите номер сохранённого полинома: ";
                    cin >> number2;
                    sp2 = ReadPolinomFromFile(number2);
                    break;
                case 3:
                    cout << "Всего в хранилище имеются " << stp.Size() << " полиномов\n";
                    stp.Print();
                    cout << "\tВведите номер сохранённого полинома: ";
                    cin >> number1;
                    sp1 = stp.GetPolinom(number1);
                    cout << "\n\tВведите номер сохранённого полинома: ";
                    cin >> number2;
                    sp2 = stp.GetPolinom(number2);
                    break;
                }
                Polinom pl1(sp1);
                Polinom pl2(sp2);
                Polinom pl3;
                pl3 = pl2 + pl1;
                cout << "Проверка:\n";
                cout << "1) ";
                pl1.Print();
                cout << "2) ";
                pl2.Print();
                cout << "3) ";
                pl3.Print();
                system("pause");
                if (counter > 1) {
                    if (!downloadauto) {
                        if (UseWritePolinomsInFileAuto())
                            downloadauto = true;
                    }
                }
                if (!downloadauto) {
                    if (WritePolinomInFile()) {
                        WritePolinomInFile(pl1);
                        WritePolinomInFile(pl2);
                        WritePolinomInFile(pl3);
                    }
                }
                else
                {
                    WritePolinomInFile(pl1);
                    WritePolinomInFile(pl2);
                    WritePolinomInFile(pl3);
                }
                sp3 = pl3.ToString();
                stp.PushPolinom(sp1);
                stp.PushPolinom(sp2);
                stp.PushPolinom(sp3);
            }
            else if (menuChoice == 2)
            {
                cout << "\tВыбран пункт 2) Найти произведение полиномов\n";
                RulesWritePolinoms();
                string sp1, sp2, sp3;
                int number1, number2;
                switch (ReadDataForPolinom(counter))
                {
                case 1:
                    cout << "\tВведите первый полином: ";
                    cin >> sp1;
                    cout << "\n\tВведите второй полином: ";
                    cin >> sp2;
                    break;
                case 2:
                    PrintPolinomsFromFile();
                    cout << "\tВведите номер сохранённого полинома: ";
                    cin >> number1;
                    sp1 = ReadPolinomFromFile(number1);
                    cout << "\n\tВведите номер сохранённого полинома: ";
                    cin >> number2;
                    sp2 = ReadPolinomFromFile(number2);
                    break;
                case 3:
                    cout << "Всего в хранилище имеются " << stp.Size() << " полиномов\n";
                    stp.Print();
                    cout << "\tВведите номер сохранённого полинома: ";
                    cin >> number1;
                    sp1 = stp.GetPolinom(number1);
                    cout << "\n\tВведите номер сохранённого полинома: ";
                    cin >> number2;
                    sp2 = stp.GetPolinom(number2);
                    break;
                }
                Polinom pl1(sp1);
                Polinom pl2(sp2);
                Polinom pl3;
                pl3 = pl2 * pl1;
                cout << "Проверка:\n";
                cout << "1) ";
                pl1.Print();
                cout << "2) ";
                pl2.Print();
                cout << "3) ";
                pl3.Print();
                system("pause");
                if (counter > 1) {
                    if (!downloadauto) {
                        if (UseWritePolinomsInFileAuto())
                            downloadauto = true;
                    }
                }
                if (!downloadauto) {
                    if (WritePolinomInFile()) {
                        WritePolinomInFile(pl1);
                        WritePolinomInFile(pl2);
                        WritePolinomInFile(pl3);
                    }
                }
                else
                {
                    WritePolinomInFile(pl1);
                    WritePolinomInFile(pl2);
                    WritePolinomInFile(pl3);
                }
                sp3 = pl3.ToString();
                stp.PushPolinom(sp1);
                stp.PushPolinom(sp2);
                stp.PushPolinom(sp3);
            }
            else if (menuChoice == 3)
            {
                cout << "\tВыбран пункт 3) Найти значение полинома в точке\n";
                RulesWritePolinoms();
                string sp1, sp2;
                int number1;
                switch (ReadDataForPolinom(counter))
                {
                case 1:
                    cout << "\tВведите первый полином: ";
                    cin >> sp1;
                    break;
                case 2:
                    PrintPolinomsFromFile();
                    cout << "\tВведите номер сохранённого полинома: ";
                    cin >> number1;
                    sp1 = ReadPolinomFromFile(number1);
                    break;
                case 3:
                    cout << "Всего в хранилище имеются " << stp.Size() << " полиномов\n";
                    stp.Print();
                    cout << "\tВведите номер сохранённого полинома: ";
                    cin >> number1;
                    sp1 = stp.GetPolinom(number1);
                    break;
                }
                Polinom pl1(sp1);
                double valuex, valuey, valuez;
                double itog;
                cout << "\tВведите координату точки X: ";
                cin >> valuex;
                cout << "\n\tВведите координату точки Y: ";
                cin >> valuey;
                cout << "\n\tВведите координату точки Z: ";
                cin >> valuez;
                itog = pl1.CalculateInPoint(valuex, valuey, valuez);
                cout << "\nПроверка:\n";
                cout << "Полином: ";
                pl1.Print();
                cout << "Координаты точки: X(" << valuex << "), Y(" << valuey <<"), Z(" << valuez <<")\n";
                cout << "Значение: " << itog << endl;
                system("pause");
                if (counter > 1) {
                    if (!downloadauto) {
                        if (UseWritePolinomsInFileAuto())
                            downloadauto = true;
                    }
                }
                if (!downloadauto) {
                    if (WritePolinomInFile())
                        WritePolinomInFile(pl1);
                }
                else
                    WritePolinomInFile(pl1);
                stp.PushPolinom(sp1);
            }
            else if (menuChoice == 4)
            {
            cout << "\tВыбран пункт 4) Найти производную полинома\n";
            RulesWritePolinoms();
            string sp1, sp3;
            int number1;
            switch (ReadDataForPolinom(counter))
            {
            case 1:
                cout << "\tВведите первый полином: ";
                cin >> sp1;
                break;
            case 2:
                PrintPolinomsFromFile();
                cout << "\tВведите номер сохранённого полинома: ";
                cin >> number1;
                sp1 = ReadPolinomFromFile(number1);
                break;
            case 3:
                cout << "Всего в хранилище имеются " << stp.Size() << " полиномов\n";
                stp.Print();
                cout << "\tВведите номер сохранённого полинома: ";
                cin >> number1;
                sp1 = stp.GetPolinom(number1);
                break;
            }
            Polinom pl1(sp1);
            Polinom pl3;
            char coordpol;
            cout << "Введите переменную по которой хотите взять производную (x или y или z): ";
            cin >> coordpol;
            pl3 = pl1.TakeDerivative(coordpol);
            cout << "\nПроверка:\n";
            cout << "1) ";
            pl1.Print();
            cout << "2) ";
            pl3.Print();
            system("pause");
            if (counter > 1) {
                if (!downloadauto) {
                    if (UseWritePolinomsInFileAuto())
                        downloadauto = true;
                }
            }
            if (!downloadauto) {
                if (WritePolinomInFile()) {
                    WritePolinomInFile(pl1);
                    WritePolinomInFile(pl3);
                }
            }
            else
            {
                WritePolinomInFile(pl1);
                WritePolinomInFile(pl3);
            }
            sp3 = pl3.ToString();
            stp.PushPolinom(sp1);
            stp.PushPolinom(sp3);
            }
            else if (menuChoice == 5)
            {
            cout << "\tВыбран пункт 5) Найти первообразную полинома\n";
            RulesWritePolinoms();
            string sp1, sp2;
            int number1;
            switch (ReadDataForPolinom(counter))
            {
            case 1:
                cout << "\tВведите первый полином: ";
                cin >> sp1;
                break;
            case 2:
                PrintPolinomsFromFile();
                cout << "\tВведите номер сохранённого полинома: ";
                cin >> number1;
                sp1 = ReadPolinomFromFile(number1);
                break;
            case 3:
                cout << "Всего в хранилище имеются " << stp.Size() << " полиномов\n";
                stp.Print();
                cout << "\tВведите номер сохранённого полинома: ";
                cin >> number1;
                sp1 = stp.GetPolinom(number1);
                break;
            }
            Polinom pl1(sp1);
            Polinom pl3;
            char coordpol;
            cout << "Введите переменную по которой хотите взять производную (x или y или z): ";
            cin >> coordpol;
            pl3 = pl1.TakeIntegral(coordpol);
            cout << "Проверка:\n";
            cout << "1) ";
            pl1.Print();
            cout << "2) ";
            pl3.Print();
            system("pause");
            if (counter > 1) {
                if (!downloadauto) {
                    if (UseWritePolinomsInFileAuto())
                        downloadauto = true;
                }
            }
            if (!downloadauto) {
                if (WritePolinomInFile()) {
                    WritePolinomInFile(pl1);
                    WritePolinomInFile(pl3);
                }
            }
            else
            {
                WritePolinomInFile(pl1);
                WritePolinomInFile(pl3);
            }
            sp2 = pl3.ToString();
            stp.PushPolinom(sp1);
            stp.PushPolinom(sp2);
            }
            else if (menuChoice == 6)
            {
            cout << "\tВыбран пункт 6) Найти определённый интеграл\n";
            RulesWritePolinoms();
            string sp1, sp2;
            int number1;
            switch (ReadDataForPolinom(counter))
            {
            case 1:
                cout << "\tВведите первый полином: ";
                cin >> sp1;
                break;
            case 2:
                PrintPolinomsFromFile();
                cout << "\tВведите номер сохранённого полинома: ";
                cin >> number1;
                sp1 = ReadPolinomFromFile(number1);
                break;
            case 3:
                cout << "Всего в хранилище имеются " << stp.Size() << " полиномов\n";
                stp.Print();
                cout << "\tВведите номер сохранённого полинома: ";
                cin >> number1;
                sp1 = stp.GetPolinom(number1);
                break;
            }
            Polinom pl1(sp1);
            double itog;
            char coordpol;
            cout << "Введите переменную по которой хотите взять производную (x или y или z): ";
            cin >> coordpol;
            double value1x, value1y, value1z;
            double value2x, value2y, value2z;
            cout << "\tВведите координату первой точки X: ";
            cin >> value1x;
            cout << "\n\tВведите координату первой точки Y: ";
            cin >> value1y;
            cout << "\n\tВведите координату первой точки Z: ";
            cin >> value1z;
            cout << "\tВведите координату второй точки X: ";
            cin >> value2x;
            cout << "\n\tВведите координату второй точки Y: ";
            cin >> value2y;
            cout << "\n\tВведите координату второй точки Z: ";
            cin >> value2z;
            itog = pl1.TakeAndCalculateDefiniteIntegral(coordpol, value1x, value1y, value1z, value2x, value2y, value2z);
            cout << "Проверка:\n";
            cout << "Полином: ";
            pl1.Print();
            cout << "Координаты первой точки: X(" << value1x << "), Y(" << value1y << "), Z(" << value1z << ")\n";
            cout << "Координаты второй точки: X(" << value2x << "), Y(" << value2y << "), Z(" << value2z << ")\n";
            cout << "Значение: " << itog;
            system("pause");
            if (counter > 1) {
                if (!downloadauto) {
                    if (UseWritePolinomsInFileAuto())
                        downloadauto = true;
                }
            }
            if (!downloadauto) {
                if (WritePolinomInFile()) {
                    WritePolinomInFile(pl1);
                }
            }
            else
                WritePolinomInFile(pl1);
            stp.PushPolinom(sp1);
            }
            else
                isWork = false;
            system("cls");
            counter++;
        }
    }
    catch (const char* s) {
        cout << "Возникла ошибка! " <<  s << endl;
    }
    return 0;
}

void PrintMenu() 
{
    cout << "\n\t\tДОСТУПНЫЕ ОПЕРАЦИИ\n";
    cout << "\t1) Найти сумму полиномов \n";
    cout << "\t2) Найти произведение полиномов \n";
    cout << "\t3) Вычислить значение полинома в точке \n";
    cout << "\t4) Найти производную от полинома \n";
    cout << "\t5) Найти первообразную полинома \n";
    cout << "\t6) Найти определённый интеграл \n";
    cout << "\t0) Завершение работы программы \n\n";
}

void RulesWritePolinoms() 
{
    cout << "\n\t\tОСНОВНЫЕ ПРАВИЛА ЗАДАНИЯ ПОЛИНОМОВ\n";
    cout << "\t1) Весь полином задаётся в виде последовательности без пробелов\n";
    cout << "\t2) Обязательно вводить коэффициент и степень полинома (и единицу тоже)\n";
    cout << "\t3) Сначала вводиться коэффициент, если число не целое, то в качестве разделителя используется запятая\n";
    cout << "\t4) Вводите полином в лексикографическом порядке по убыванию\n";
    cout << "\t Пример: 5,6x5y2z1-84x5+8y2-9,2\n\n";
}

bool UseWritePolinomsInFileAuto() 
{
    int choice;
    cout << "\n\tХотите ли чтобы полиномы записывались автоматически и вам не требовалось нажимать соответствующую клавишу?\n";
    cout << "\t1) Да\n";
    cout << "\t0) Нет\n";
    cin >> choice;
    if (choice == 1)
        return true;
    return false;
}

bool WritePolinomInFile()
{
    int choice;
    cout << "\n\tХотите сохранить введённые вами данные?\n";
    cout << "\t1) Да\n";
    cout << "\t0) Нет\n";
    cin >> choice;
    if (choice == 1)
        return true;
    return false;
}

int ReadDataForPolinom(int _number) 
{
    int choice;
    cout << "\n\tКаким образом вы хотите задать полином?\n";
    cout << "\t1) Вручную\n";
    if (_number > 1) {
        cout << "\t2) Из файла\n";
        cout << "\t3) Из хранилища\n";
    }
    cin >> choice;
    return choice;
}
