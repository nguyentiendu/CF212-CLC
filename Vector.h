#pragma once
#include <iostream>
#include <string>
using namespace std;
template<typename T> class Vector;
template<typename T>
class SNode{
private:
    T elem;
    SNode<T> *next;
public:
    SNode(T elem)
    {
        this->elem=elem;
        this->next=NULL;
    }
    friend class Vector<T>;
};
template<typename T>
class Vector{
public:
    Vector();
    ~Vector();
    bool empty()const;
    const T&front()const;
    void addFront(T);
    void removeFront();
    void removeBack();
    void addBack(T);
    void print()const;
    int Size()const;
    void erase(T);
    void reSize(T);
    T &operator [](T);
private:
    SNode<T> *head;
    SNode<T> *tail;
    int size;
};
template<typename T>
Vector<T>::Vector():head(NULL),tail(NULL)
{}
template<typename T>
Vector<T>::~Vector()
{}
template<typename T>
bool Vector<T>::empty()const
{
    return this->head==NULL;
}
template<typename T>
const T& Vector<T>::front()const
{
    return this->head->elem;
}
template<typename T>
void Vector<T>::addFront(T data)
{
    SNode<T> *v = new SNode<T>(data);
    if (empty())
    {
        this->head = this->tail = v;
    }
    else
    {
        v->next = head;
        this->head = v;
    }
    this->size++;
}
template<typename T>
void Vector<T>::removeFront()
{
    if (!empty())
    {
        if (this->head == this->tail)
        {
            delete this->head;
            this->head=NULL;
            this->tail=NULL;
        }
        else
        {
            SNode<T> *temp = head;
            head = head->next;
            delete temp;
        }
        this->size--;
    }
}
template<typename T>
void Vector<T>::print()const
{
    SNode<T>* v = head;
    while (v!=NULL)
    {
        cout<<v->elem<<endl;
        v = v->next;
    }
}
template<typename T>
int Vector<T>::Size()const
{
    return this->size;
}
template<typename T>
void Vector<T>::addBack(T data)
{
    SNode<T> *v = new SNode<T>(data);
    if (empty())
    {
        this -> head = v;
        this -> tail = v;
    }
    else
    {
        this->tail -> next = v;
        this->tail = v;
    }
    this->size++;
}
template<typename T>
void Vector<T>::removeBack()
{
    if (!empty())
    {
        if (this->head == this->tail)
        {
            delete this -> head;
            this -> head = NULL;
            this -> tail = NULL;
        }
        else
        {
            SNode<T> *temp = this->head;
            while(temp->next->next != NULL)
                temp = temp -> next;
            this->tail = temp;
            delete temp->next;
            temp->next = NULL;
        }
        this->size --;
    }
}
template<typename T>
void Vector<T>::erase(T pos)
{
    SNode<T> *v = this->head;
    if (pos > Size())
        return;
    else if (pos==1)
    {
        this->head = this->head->next;
        delete v;
    }
    else
    {
        int k=0;
        while (k!=pos-2 && v->next->next != NULL)
        {
            v = v->next;
            ++k;
        }
        v->next = v->next->next;
    }
}
template<typename T>
void Vector<T>::reSize(T n)
{
    SNode<T> *v = this->head;
    int k = Size();
    if (n > Size())
    {
        while (k!=n)
        {
            SNode<T> *temp = new SNode<T>(0);
            this->tail->next = temp;
            this->tail = temp;
            k++;
        }
    }
    else
    {
        for (int i=0; i<n-1; i++)
            v = v->next;
        this->tail = v;
        v->next = NULL;
    }
}
template<typename T>
T &Vector<T>::operator [](T i)
{
    SNode<T> *v = this->head;
    int k=0;
    while (k!=i)
    {
        v = v->next;
        k++;
    }
    return v->elem;
}