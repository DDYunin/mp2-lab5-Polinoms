#ifndef __MONOM_H__
#define __MONOM_H__

#include <iostream>

const int maxDegree = 10;

using namespace std;

struct Monom
{
    double coefficient;
    int degreeX;
    int degreeY;
    int degreeZ;

    Monom(double _coef = 0, int _degX = 0, int _degY = 0, int _degZ = 0) 
    {
        if ((_degX >= maxDegree) || (_degY >= maxDegree) || (_degZ >= maxDegree))
            throw "Введена степень большая, чем максимальная!";
        if ((_degX < 0) || (_degY < 0) || (_degZ < 0))
            throw "Степень меньше нуля, не допустимо!";
        coefficient = _coef; degreeX = _degX; degreeY = _degY; degreeZ = _degZ;
    }

    bool operator==(const Monom& mon) 
    {
        if ((degreeX == mon.degreeX) && (degreeY == mon.degreeY) && (degreeZ == mon.degreeZ))
            return true;
        return false;
    }

    bool operator>(const Monom& mon) 
    {
        if (degreeX > mon.degreeX)
            return true;
        else if (degreeX < mon.degreeX)
            return false;

        if ((degreeX == mon.degreeX) && (degreeY > mon.degreeY))
            return true;
        else if ((degreeX == mon.degreeX) && (degreeY < mon.degreeY))
            return false;

        if ((degreeX == mon.degreeX) && (degreeY == mon.degreeY) && (degreeZ > mon.degreeZ))
            return true;
        else if ((degreeX == mon.degreeX) && (degreeY == mon.degreeY) && (degreeZ < mon.degreeZ))
            return false;
    }

    bool operator<(const Monom& mon) 
    {
        if (degreeX < mon.degreeX)
            return true;
        else if (degreeX > mon.degreeX)
            return false;

        if ((degreeX == mon.degreeX) && (degreeY < mon.degreeY))
            return true;
        else if ((degreeX == mon.degreeX) && (degreeY > mon.degreeY))
            return false;

        if ((degreeX == mon.degreeX) && (degreeY == mon.degreeY) && (degreeZ < mon.degreeZ))
            return true;
        else if ((degreeX == mon.degreeX) && (degreeY == mon.degreeY) && (degreeZ > mon.degreeZ))
            return false;
        //return !(*this > mon);
    }

    bool operator!= (const Monom& mon) 
    {
        return !(*this == mon);
    }

    Monom operator+(const Monom& mon) 
    {
        Monom mon1;
        mon1.coefficient = this->coefficient + mon.coefficient;
        mon1.degreeX = degreeX;
        mon1.degreeY = degreeY;
        mon1.degreeZ = degreeZ;
        return mon1;
    }

    Monom operator*(const Monom& mon) 
    {
        if ((degreeX + mon.degreeX >= maxDegree) || (degreeY + mon.degreeY >= maxDegree) || (degreeZ + mon.degreeZ >= maxDegree))
            throw "Получившаяся степень больше, чем максимальная!";
        Monom mon1;
        mon1.coefficient = this->coefficient * mon.coefficient;
        mon1.degreeX = degreeX + mon.degreeX;
        mon1.degreeY = degreeY + mon.degreeY;
        mon1.degreeZ = degreeZ + mon.degreeZ;
        return mon1;
    }

    void Derivative(char _var) 
    {
        switch (_var)
        {
        case 'x':
            coefficient *= degreeX;
            if (degreeX != 0)
                degreeX--;
            break;
        case 'y':
            coefficient *= degreeY;
            if (degreeY != 0)
                degreeY--;
            break;
        case 'z':
            coefficient *= degreeZ;
            if (degreeZ != 0)
                degreeZ--;
            break;
        }
    }

    void Integrate(char _var) 
    {
        switch (_var)
        {
        case 'x':
            if (degreeX + 1 >= maxDegree)
                throw "Невозможно проинтегрировать, так как степень превысила максимальную!";
            if (coefficient == 0)
                break;
            degreeX++;
            coefficient /= degreeX;
            break;
        case 'y':
            if (degreeY + 1 >= maxDegree)
                throw "Невозможно проинтегрировать, так как степень превысила максимальную!";
            if (coefficient == 0)
                break;
            degreeY++;
            coefficient /= degreeY;
            break;
        case 'z':
            if (degreeZ + 1 >= maxDegree)
                throw "Невозможно проинтегрировать, так как степень превысила максимальную!";
            if (coefficient == 0)
                break;
            degreeZ++;
            coefficient /= degreeZ;
            break;
        }
    }

    friend ostream& operator<< (ostream& out, const Monom& monom) {
        //1. Когда коэффициент 0, то просто 0 выводим.
        if (monom.coefficient == 0) {
            out << monom.coefficient;//<< " "
            return out;
        }
        //2. Когда коэффициент не 0, а степени все ноль.
        if ((monom.coefficient != 0) && (monom.degreeX == 0) && (monom.degreeY == 0) && (monom.degreeZ == 0)) {
            out << monom.coefficient;//<< " "
            return out;
        }
        //3. Когда коэффициент не 0, а две из степеней 0, а последняя не ноль.
        if ((monom.degreeX != 0) && (monom.degreeY == 0) && (monom.degreeZ == 0)) {
            out << monom.coefficient << "x" << monom.degreeX;//<< " "
            return out;
        }
        if ((monom.degreeX == 0) && (monom.degreeY != 0) && (monom.degreeZ == 0)) {
            out << monom.coefficient << "y" << monom.degreeY;//<< " "
            return out;
        }
        if ((monom.degreeX == 0) && (monom.degreeY == 0) && (monom.degreeZ != 0)) {
            out << monom.coefficient << "z" << monom.degreeZ;//<< " "
            return out;
        }
        //4. Когда коэффициент не 0, одна из степеней 0, а другие не ноль.
        if ((monom.degreeX == 0) && (monom.degreeY != 0) && (monom.degreeZ != 0)) {
            out << monom.coefficient << "y" << monom.degreeY << "z" << monom.degreeZ;//<< " "
            return out;
        }
        if ((monom.degreeX != 0) && (monom.degreeY == 0) && (monom.degreeZ != 0)) {
            out << monom.coefficient << "x" << monom.degreeX << "z" << monom.degreeZ;//<< " "
            return out;
        }
        if ((monom.degreeX != 0) && (monom.degreeY != 0) && (monom.degreeZ == 0)) {
            out << monom.coefficient << "x" << monom.degreeX << "y" << monom.degreeY;//<< " "
            return out;
        }
        //5. Когда коэффициент и все степени переменных не ноль.
        if ((monom.degreeX != 0) && (monom.degreeY != 0) && (monom.degreeZ != 0)) {
            out << monom.coefficient << "x" << monom.degreeX << "y" << monom.degreeY << "z" << monom.degreeZ;//<< " "
            return out;
        }
    }
};

#endif // !__MONOM_H__
