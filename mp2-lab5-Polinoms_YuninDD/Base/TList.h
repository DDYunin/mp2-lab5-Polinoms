#ifndef __TLIST_H__
#define __TLIST_H__

#include <iostream>
#include <vector>

using namespace std;

template<typename TData>
class TList 
{
private:

    template<typename TData>
    struct Node
    {
        Node* pNext;//указатель на следующий элемент
        TData data;//хранимые данные
        
        Node(TData tmp_data = TData(), Node* tmp_pNext = nullptr) : data(tmp_data), pNext(tmp_pNext) {}
    };

    int list_size;//Количество элементов в списке.
    Node<TData>* head; //Указатель первого элемента.

    
public:
    TList() { list_size = 0, head = nullptr; };
    TList(const TList<TData>& l);
    TList(const vector<TData>& vect);
    TList(TList<TData>&& l) noexcept;
    ~TList();
    int size() { return list_size; }
    bool empty();
    void pop_front();
    void pop_back();
    void clear();
    void invert();
    vector<TData> to_vector();
    void removeAt(int index);
    void push_front(const TData _data);
    void push_back(const TData _data);
    void insert(const TData _data, int index);	
    void print();
    TData& operator[](const int index);
    TList<TData>& operator=(TList<TData>& l);
    TList<TData>& operator=(TList<TData>&& l) noexcept;
    
    friend void Swap(TList<TData>& left_list, TList<TData>& right_list) {
        std::swap(left_list.head, right_list.head);
        std::swap(left_list.list_size, right_list.list_size);
    }
};

template<typename TData>
TList<TData>::TList(const TList<TData>& l)
{
    head = nullptr;
    list_size = 0;
    Node<TData>* p = l.head;
    while (p != nullptr) {
        push_back(p->data);
        p=p->pNext;
    }
}
template<typename TData>
TList<TData>::TList(const vector<TData>& vect)
{
    head = nullptr;
    list_size = 0;
    for (size_t i = vect.size(); i > 0 ; i--) {
        push_front(vect[i - 1]);
    }
}


template<typename TData>
TList<TData>::TList(TList<TData>&& l) noexcept
{
    head = l.head;
    l.head = nullptr;
    int temp = list_size;
    list_size = l.list_size;
    l = temp;
}

template<typename TData>
TList<TData>::~TList()
{
    clear();
}

template<typename TData>
bool TList<TData>::empty()
{
    if (list_size == 0)
        return true;
    return false;
}

template<typename TData>
void TList<TData>::pop_front()
{
    Node<TData>* temp = head;
    head = head->pNext;
    delete temp;
    list_size--;
}

template<typename TData>
void TList<TData>::pop_back()
{
    removeAt(list_size - 1);
}

template<typename TData>
void TList<TData>::clear()
{
    while (list_size != 0)
        pop_front();
}

template<typename TData>
void TList<TData>::invert()
{
    if(head == nullptr)
        return;
    Node<TData>* p = head;
    head = p->pNext;
    p->pNext = nullptr;
    for (Node<TData>* np = head; np != nullptr; np = head) {
        head = np->pNext;
        np->pNext = p;
        p = np;
    }
    head = p;
}

template<typename TData>
vector<TData> TList<TData>::to_vector()
{
    vector<TData> vect;
    for (Node<TData>* p = head; p != nullptr; p=p->pNext)
        vect.push_back(p->data);
    return vect;
}

template<typename TData>
void TList<TData>::removeAt(int index)
{
    if ((index < 0) || (index >= list_size))
        throw "Недопустимый индекс";
    if (index == 0)
        pop_front();
    else {
        Node<TData>* curr = head;
        int i = 0;
        while (i != index - 1) {
            curr = curr->pNext;
            i++;
        }
        Node<TData>* elemdel = curr->pNext;
        curr->pNext = elemdel->pNext;
        delete elemdel;
        list_size--;
    }
}

template<typename TData>
void TList<TData>::push_front(const TData _data)
{
    head = new Node<TData>(_data, head);
    list_size++;
}

template<typename TData>
void TList<TData>::push_back(const TData _data)
{
    if (head == nullptr) {
        head = new Node<TData>(_data);
    }
    else {
        Node<TData>* current = head;
        while (current->pNext != nullptr) {
            current = current->pNext;
        }
        current->pNext = new Node<TData>(_data);
    }
    list_size++;
}

template<typename TData>
void TList<TData>::insert(const TData _data, int index)
{
    if ((index < 0) || (index > list_size))
        throw "Недопустимый индекс";
    if (index == 0)
        push_front(_data);
    else if (index == list_size)
        push_back(_data);
    else {
        Node<TData>* previous = head;
        for (int i = 0; i < index - 1; i++) {
            previous = previous->pNext;
        }
        Node<TData>* newNode = new Node<TData>(_data, previous->pNext);
        previous->pNext = newNode;
        list_size++;
    }
}

template<typename TData>
void TList<TData>::print()
{
    int i = 1;
    for (Node<TData>* p = head; p != nullptr; p=p->pNext){
        cout << i << ") " << p->data << endl;
        i++;
    }
}

template<typename TData>
TData& TList<TData>::operator[](const int index)
{
    if ((index < 0) || (index >= list_size))
        throw "Недопустимый индекс";
    Node<TData> *temp = head;
    int counter = 0;
    while (counter != index) {
        temp = temp->pNext;
        counter++;
    }
    return temp->data;
}

template<typename TData>
TList<TData>& TList<TData>::operator=(TList<TData>& l)
{
    if (this == &l) {
        return *this;
    }
    TList<TData> temp(l);
    Swap(temp,*this);
    return *this;
}

template<typename TData>
TList<TData>& TList<TData>::operator=(TList<TData>&& l) noexcept
{
    if (this != &l) {
        clear();
        head = l.head;
        l.head = nullptr;
        int temp = list_size;
        list_size = l.list_size;
        l = temp;
    }
    return *this;
}

#endif 
