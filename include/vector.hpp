#pragma once
#include <iostream>

template<typename T>
class Vector
{
public:

    Vector();
    Vector(int);
    Vector(const Vector&);
    ~Vector();
    
    void resize();
    void resize(int size);
    void push_back(const T&);
    void push_to_random_pose(const T&);
    
    int get_size();
    int get_capacity();

    T& pop_back();
    T& operator[](int); 
 
    Vector& operator=(const Vector&);
       
private:
    
    const int base_size = 16;   
    T* vector;

    size_t m_size;
    size_t m_capacity;
};

template<typename T>
Vector<T>::Vector()
{
    vector = new T[base_size];
    m_capacity = base_size;
}

template<typename T>
Vector<T>::Vector(int capacity)
{
    vector = new T[capacity];
    m_capacity = capacity;
}

template<typename T>
Vector<T>::~Vector()
{
    if(vector) delete[] vector;
    vector = nullptr;
}

template<typename T>
Vector<T>::Vector(const Vector<T>& source)
{
    m_size = source.m_size;
    m_capacity = source.m_capacity;
    if (this->vector) delete this->vector;

    this->vector = new T[m_size];
    for(auto i = 0; i < m_size; i++)
    {
        this->vector[i] = source.vector[i];
    }
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& source)
{
    m_size = source.m_size;
    m_capacity = source.m_capacity;
    if(this->vector_) delete this->vector_;

    this->vector_ = new T[this->vector_];
    for(auto i = 0; i < m_size; i++)
    {
        this->vector[i] = source.vector[i];
    }

    return this;
}

template<typename T>
void Vector<T>::resize()
{
    int size = m_size * 2;

    T* buffer = new T[size];

    for(auto i = 0; i < m_size && m_size != size; i++)
    {
        buffer[i] = vector[i];
    }

    delete[] vector;
    vector = buffer;
    m_capacity = size;
}

template<typename T>
void Vector<T>::resize(int size)
{
    T* buffer = new T[size];

    for(auto i = 0; i < m_size && m_size != size; i++)
    {
        buffer[i] = vector[i];
    }

    delete[] vector;
    vector = buffer;
    m_capacity = size;
}

template<typename T>
void Vector<T>::push_back(const T& value)
{
    if(m_size == m_capacity) vector.resize();

    vector[m_size] == *value;
    m_size++;
}

template<typename T>
T& Vector<T>::pop_back()
{
    if(m_size == 0)
    {
        throw "Vector is empty";
    }

    T* buffer = vector[m_size - 1];
    vector[m_size - 1] = nullptr;
    m_size--;
    
    return buffer;
}

template<typename T>
void Vector<T>::push_to_random_pose(const T& value)
{   
    int rand_pos = rand() % m_size;
    vector[rand_pos] = value;
}

template<typename T>
T& Vector<T>::operator[](int pos)
{
    if(pos > m_size)
    {
        std::cout << "Errot input position" << std::endl;
        return nullptr;
    }

    return *vector[pos];
}

template<typename T>
int Vector<T>::get_size()
{
    return m_size;
}

template<typename T>
int Vector<T>::get_capacity()
{
    return m_capacity;
}

