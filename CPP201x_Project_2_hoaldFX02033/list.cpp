#include "list.h"

template <class T>
List<T>::List()
{
}

template <typename T>
List<T>::~List()
{
}

template <class T>
void List<T>::add(T const &item)
{
    //check
    elements_[index] = item;
    index++;
}

template <class T>
void List<T>::changeElement(T const &item, int pos)
{
    //check
    delete elements_[pos]; //Giai phong vung nho cap phat
    elements_[pos] = item;
}

template <class T>
T List<T>::get(int pos)
{
    return elements_[pos];
}

template <class T>
int List<T>::size()
{
    return index;
}

template <class T>
void List<T>::Sap_Xep()
{
    T p;
    for (int i = 0; i < index - 1; ++i)
    {
        for (int j = index - 1; j > i; --j)
        {
            if (elements_[j]->layMaSoCaNhan().compare(elements_[j - 1]->layMaSoCaNhan()) == -1)
            {
                p = elements_[j];
                elements_[j] = elements_[j - 1];
                elements_[j - 1] = p;
            }
        }
    }
}

template <class T>
void List<T>::pop_element(int pos)
{
    delete elements_[pos]; //Giai phong vung nho cap phat
    for (int i = pos; i < index - 1; ++i)
    {
        elements_[i] = elements_[i + 1];
    }
    index--;
}
