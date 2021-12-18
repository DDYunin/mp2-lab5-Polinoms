#include "Store.h"

void StorePolinoms::PushPolinom(string& str)
{
    store.push_back(str);
}

string& StorePolinoms::GetPolinom(int index)
{
    return store[index];
}

void StorePolinoms::Print()
{
    for (size_t i = 0; i < store.size(); i++)
        cout << i << ") " << store[i] << endl;
}

int StorePolinoms::Size()
{
    return store.size();
}
