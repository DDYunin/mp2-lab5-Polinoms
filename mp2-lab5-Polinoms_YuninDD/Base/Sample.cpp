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
            cout << "�������� ���� �� ������� ����: ";
            int menuChoice;
            cin >> menuChoice;
            if ((menuChoice < 0) || (menuChoice > 6))
                throw "������ ������������ ����� ����";
            system("cls");
            if (menuChoice == 1)
            {
                string sp1, sp2, sp3;
                int number1, number2;
                cout << "\t������ ����� 1) ����� ����� ���������\n";
                RulesWritePolinoms();
                switch (ReadDataForPolinom(counter))
                {
                case 1:
                    cout << "\t������� ������ �������: ";
                    cin >> sp1;
                    cout << "\n\t������� ������ �������: ";
                    cin >> sp2;
                    break;
                case 2:
                    PrintPolinomsFromFile();
                    cout << "\t������� ����� ����������� ��������: ";
                    cin >> number1;
                    sp1 = ReadPolinomFromFile(number1);
                    cout << "\n\t������� ����� ����������� ��������: ";
                    cin >> number2;
                    sp2 = ReadPolinomFromFile(number2);
                    break;
                case 3:
                    cout << "����� � ��������� ������� " << stp.Size() << " ���������\n";
                    stp.Print();
                    cout << "\t������� ����� ����������� ��������: ";
                    cin >> number1;
                    sp1 = stp.GetPolinom(number1);
                    cout << "\n\t������� ����� ����������� ��������: ";
                    cin >> number2;
                    sp2 = stp.GetPolinom(number2);
                    break;
                }
                Polinom pl1(sp1);
                Polinom pl2(sp2);
                Polinom pl3;
                pl3 = pl2 + pl1;
                cout << "��������:\n";
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
                cout << "\t������ ����� 2) ����� ������������ ���������\n";
                RulesWritePolinoms();
                string sp1, sp2, sp3;
                int number1, number2;
                switch (ReadDataForPolinom(counter))
                {
                case 1:
                    cout << "\t������� ������ �������: ";
                    cin >> sp1;
                    cout << "\n\t������� ������ �������: ";
                    cin >> sp2;
                    break;
                case 2:
                    PrintPolinomsFromFile();
                    cout << "\t������� ����� ����������� ��������: ";
                    cin >> number1;
                    sp1 = ReadPolinomFromFile(number1);
                    cout << "\n\t������� ����� ����������� ��������: ";
                    cin >> number2;
                    sp2 = ReadPolinomFromFile(number2);
                    break;
                case 3:
                    cout << "����� � ��������� ������� " << stp.Size() << " ���������\n";
                    stp.Print();
                    cout << "\t������� ����� ����������� ��������: ";
                    cin >> number1;
                    sp1 = stp.GetPolinom(number1);
                    cout << "\n\t������� ����� ����������� ��������: ";
                    cin >> number2;
                    sp2 = stp.GetPolinom(number2);
                    break;
                }
                Polinom pl1(sp1);
                Polinom pl2(sp2);
                Polinom pl3;
                pl3 = pl2 * pl1;
                cout << "��������:\n";
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
                cout << "\t������ ����� 3) ����� �������� �������� � �����\n";
                RulesWritePolinoms();
                string sp1, sp2;
                int number1;
                switch (ReadDataForPolinom(counter))
                {
                case 1:
                    cout << "\t������� ������ �������: ";
                    cin >> sp1;
                    break;
                case 2:
                    PrintPolinomsFromFile();
                    cout << "\t������� ����� ����������� ��������: ";
                    cin >> number1;
                    sp1 = ReadPolinomFromFile(number1);
                    break;
                case 3:
                    cout << "����� � ��������� ������� " << stp.Size() << " ���������\n";
                    stp.Print();
                    cout << "\t������� ����� ����������� ��������: ";
                    cin >> number1;
                    sp1 = stp.GetPolinom(number1);
                    break;
                }
                Polinom pl1(sp1);
                double valuex, valuey, valuez;
                double itog;
                cout << "\t������� ���������� ����� X: ";
                cin >> valuex;
                cout << "\n\t������� ���������� ����� Y: ";
                cin >> valuey;
                cout << "\n\t������� ���������� ����� Z: ";
                cin >> valuez;
                itog = pl1.CalculateInPoint(valuex, valuey, valuez);
                cout << "\n��������:\n";
                cout << "�������: ";
                pl1.Print();
                cout << "���������� �����: X(" << valuex << "), Y(" << valuey <<"), Z(" << valuez <<")\n";
                cout << "��������: " << itog << endl;
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
            cout << "\t������ ����� 4) ����� ����������� ��������\n";
            RulesWritePolinoms();
            string sp1, sp3;
            int number1;
            switch (ReadDataForPolinom(counter))
            {
            case 1:
                cout << "\t������� ������ �������: ";
                cin >> sp1;
                break;
            case 2:
                PrintPolinomsFromFile();
                cout << "\t������� ����� ����������� ��������: ";
                cin >> number1;
                sp1 = ReadPolinomFromFile(number1);
                break;
            case 3:
                cout << "����� � ��������� ������� " << stp.Size() << " ���������\n";
                stp.Print();
                cout << "\t������� ����� ����������� ��������: ";
                cin >> number1;
                sp1 = stp.GetPolinom(number1);
                break;
            }
            Polinom pl1(sp1);
            Polinom pl3;
            char coordpol;
            cout << "������� ���������� �� ������� ������ ����� ����������� (x ��� y ��� z): ";
            cin >> coordpol;
            pl3 = pl1.TakeDerivative(coordpol);
            cout << "\n��������:\n";
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
            cout << "\t������ ����� 5) ����� ������������� ��������\n";
            RulesWritePolinoms();
            string sp1, sp2;
            int number1;
            switch (ReadDataForPolinom(counter))
            {
            case 1:
                cout << "\t������� ������ �������: ";
                cin >> sp1;
                break;
            case 2:
                PrintPolinomsFromFile();
                cout << "\t������� ����� ����������� ��������: ";
                cin >> number1;
                sp1 = ReadPolinomFromFile(number1);
                break;
            case 3:
                cout << "����� � ��������� ������� " << stp.Size() << " ���������\n";
                stp.Print();
                cout << "\t������� ����� ����������� ��������: ";
                cin >> number1;
                sp1 = stp.GetPolinom(number1);
                break;
            }
            Polinom pl1(sp1);
            Polinom pl3;
            char coordpol;
            cout << "������� ���������� �� ������� ������ ����� ����������� (x ��� y ��� z): ";
            cin >> coordpol;
            pl3 = pl1.TakeIntegral(coordpol);
            cout << "��������:\n";
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
            cout << "\t������ ����� 6) ����� ����������� ��������\n";
            RulesWritePolinoms();
            string sp1, sp2;
            int number1;
            switch (ReadDataForPolinom(counter))
            {
            case 1:
                cout << "\t������� ������ �������: ";
                cin >> sp1;
                break;
            case 2:
                PrintPolinomsFromFile();
                cout << "\t������� ����� ����������� ��������: ";
                cin >> number1;
                sp1 = ReadPolinomFromFile(number1);
                break;
            case 3:
                cout << "����� � ��������� ������� " << stp.Size() << " ���������\n";
                stp.Print();
                cout << "\t������� ����� ����������� ��������: ";
                cin >> number1;
                sp1 = stp.GetPolinom(number1);
                break;
            }
            Polinom pl1(sp1);
            double itog;
            char coordpol;
            cout << "������� ���������� �� ������� ������ ����� ����������� (x ��� y ��� z): ";
            cin >> coordpol;
            double value1x, value1y, value1z;
            double value2x, value2y, value2z;
            cout << "\t������� ���������� ������ ����� X: ";
            cin >> value1x;
            cout << "\n\t������� ���������� ������ ����� Y: ";
            cin >> value1y;
            cout << "\n\t������� ���������� ������ ����� Z: ";
            cin >> value1z;
            cout << "\t������� ���������� ������ ����� X: ";
            cin >> value2x;
            cout << "\n\t������� ���������� ������ ����� Y: ";
            cin >> value2y;
            cout << "\n\t������� ���������� ������ ����� Z: ";
            cin >> value2z;
            itog = pl1.TakeAndCalculateDefiniteIntegral(coordpol, value1x, value1y, value1z, value2x, value2y, value2z);
            cout << "��������:\n";
            cout << "�������: ";
            pl1.Print();
            cout << "���������� ������ �����: X(" << value1x << "), Y(" << value1y << "), Z(" << value1z << ")\n";
            cout << "���������� ������ �����: X(" << value2x << "), Y(" << value2y << "), Z(" << value2z << ")\n";
            cout << "��������: " << itog;
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
        cout << "�������� ������! " <<  s << endl;
    }
    return 0;
}

void PrintMenu() 
{
    cout << "\n\t\t��������� ��������\n";
    cout << "\t1) ����� ����� ��������� \n";
    cout << "\t2) ����� ������������ ��������� \n";
    cout << "\t3) ��������� �������� �������� � ����� \n";
    cout << "\t4) ����� ����������� �� �������� \n";
    cout << "\t5) ����� ������������� �������� \n";
    cout << "\t6) ����� ����������� �������� \n";
    cout << "\t0) ���������� ������ ��������� \n\n";
}

void RulesWritePolinoms() 
{
    cout << "\n\t\t�������� ������� ������� ���������\n";
    cout << "\t1) ���� ������� ������� � ���� ������������������ ��� ��������\n";
    cout << "\t2) ����������� ������� ����������� � ������� �������� (� ������� ����)\n";
    cout << "\t3) ������� ��������� �����������, ���� ����� �� �����, �� � �������� ����������� ������������ �������\n";
    cout << "\t4) ������� ������� � ������������������ ������� �� ��������\n";
    cout << "\t ������: 5,6x5y2z1-84x5+8y2-9,2\n\n";
}

bool UseWritePolinomsInFileAuto() 
{
    int choice;
    cout << "\n\t������ �� ����� �������� ������������ ������������� � ��� �� ����������� �������� ��������������� �������?\n";
    cout << "\t1) ��\n";
    cout << "\t0) ���\n";
    cin >> choice;
    if (choice == 1)
        return true;
    return false;
}

bool WritePolinomInFile()
{
    int choice;
    cout << "\n\t������ ��������� �������� ���� ������?\n";
    cout << "\t1) ��\n";
    cout << "\t0) ���\n";
    cin >> choice;
    if (choice == 1)
        return true;
    return false;
}

int ReadDataForPolinom(int _number) 
{
    int choice;
    cout << "\n\t����� ������� �� ������ ������ �������?\n";
    cout << "\t1) �������\n";
    if (_number > 1) {
        cout << "\t2) �� �����\n";
        cout << "\t3) �� ���������\n";
    }
    cin >> choice;
    return choice;
}
