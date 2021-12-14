#ifndef __STORE_H__
#define __STORE_H__

#include "Polinom.h"

class StorePolinoms
{
private:
    vector<string> store;
public:
    StorePolinoms(){};
    void PushPolinom(string& str);
    string& GetPolinom(int index);
    void Print();
    int Size();
};

#endif // !__STORE_H__
