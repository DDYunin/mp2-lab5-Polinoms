#ifndef __POLINOM_H__
#define __POLINOM_H__

#include "Monom.h"
#include "TList.h"
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstdlib> // для использования функции exit()

using namespace std;

class Polinom
{
private:
    TList<Monom> list;

    void CollectTerms(TList<Monom>& nlist);

    Monom CreateMonomWithoutVars(const string& str);
    Monom CreateMonomWithOneVar(const string& str);
    Monom CreateMonomWithTwoVars(const string& str);
    Monom CreateMonomWithThreeVars(const string& str);

    double CalculateNumInPow(double num, int pow, char symbol);

    void TransformString(string& str);

    string CreateStringFromMonom(const Monom& mon);
    int FindNumVars(const Monom& mon, vector<char>& v);

    void  CreateStringWithoutVars(string& str, const Monom& mon);
    void  CreateStringWithOneVars(string& str, const Monom& mon, char name_var);

    void DeleteNullCoefficients(TList<Monom>& nlist);
    void AddNull(TList<Monom>& nlist);

    void DetermineVarAndFillMonom(Monom& mon, char var_name, int value);

    void CreateList(const string& str);
    int FindNumVars(const string& str);
    void CreateVectorString(vector<string>& v, const string& str);
public:
    Polinom(const string& _polinom);
    Polinom();
    Polinom(Polinom& _polinom);
    Polinom(Polinom&& _polinom) noexcept;
    Polinom(TList<Monom>& _list) { list = _list;}
    void Sorted();
    string ToString();
    Polinom& operator=(Polinom& pl);
    Polinom& operator=(Polinom&& pl) noexcept;
    void Print();
    Polinom& operator+=(Polinom& pl);
    Polinom operator+(Polinom& pl);
    Polinom& operator*=(Polinom& pl);
    Polinom operator*(Polinom& pl);
    //дополнительные задания
    double CalculateInPoint(double valueX, double valueY, double valueZ);
    Polinom TakeDerivative(char varDerivative);
    Polinom TakeIntegral(char varIntegration);//без константы неопределённой;
    double TakeAndCalculateDefiniteIntegral(char varIntegration, double startpointX, double startpointY, double startpointZ, double endpointX, double endpointY, double endpointZ);
    //работа с файлами
    friend void WritePolinomInFile(Polinom& polinom);
    friend string ReadPolinomFromFile(int num_polinom);
    friend void PrintPolinomsFromFile();
};

string ReadPolinomFromFile(int num_polinom);
void PrintPolinomsFromFile();

#endif // !__POLINOM_H__
