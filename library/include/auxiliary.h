#ifndef AUXILIARY
#define AUXILIARY
#include"axisVector.h"

#include <iostream>
#include <algorithm>
#include <string>
#include <array>
#include"math.h"
#include <sstream>
#include <cstdio>
#include <stdarg.h>

template <typename T>
class smPtr {
	T* m_obj;
public:

	smPtr(T* obj)
		: m_obj(obj)
	{ }

   

	~smPtr() {
		delete m_obj;
	}
    T* operator[] (const int index) { return  m_obj[index]; }
	T* operator->() { return m_obj; }

	T& operator* () { return *m_obj; }
};


template<class T>
class smArray
{
	std::vector<T*>array_ptrs;
public:

    T* operator[] (const int index) { return array_ptrs[index]; }

	void add(T* pt)
	{
		array_ptrs.push_back(pt);
	}


	void erase(T* pt)
	{
		array_ptrs.erase(std::find(array_ptrs.begin(), array_ptrs.end(), pt));
	}

	size_t size() const
	{
		return array_ptrs.size();
	}

};

template<typename T>
class Vector {
public:
    Vector() {
        arr_ = new T[1];
        capacity_ = 1;
    }
    Vector(Vector& other) {
        if (this != &other) {
            delete[] arr_;
            arr_ = other.arr_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            other.arr_ = nullptr;
            other.size_ = other.capacity_ = 0;
        }
    }
    Vector(Vector&& other)  noexcept {
        if (this != &other) {
            delete[] arr_;
            arr_ = other.arr_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            other.arr_ = nullptr;
            other.size_ = other.capacity_ = 0;
        }
    }
    Vector& operator=(Vector& other) {
        if (this != &other) {
            delete[] arr_;
            arr_ = other.arr_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            other.arr_ = nullptr;
            other.size_ = other.capacity_ = 0;
        }
        return *this;
    }

    Vector& operator=(Vector&& other) noexcept {
        if (this != &other) {
            delete[] arr_;
            arr_ = other.arr_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            other.arr_ = nullptr;
            other.size_ = other.capacity_ = 0;
        }
        return *this;
    }

    ~Vector() {
        delete[] arr_;
    }
public:
    [[nodiscard]] bool isEmpty() const {
        return size_ == 0;
    }

    [[nodiscard]] size_t size() const {
        return size_;
    }

    [[nodiscard]] size_t capacity() const {
        return capacity_;
    }

    void pushBack(const T& value) {
        if (size_ >= capacity_) addMemory();
        arr_[size_++] = value;
    }

    void remove(size_t index) {
        for (size_t i = index + 1; i < size_; ++i) {
            arr_[i - 1] = arr_[i];
        }
        --size_;
    }
public:
    T* begin() {
        return &arr_[0];
    }

    const T* begin() const {
        return &arr_[0];
    }

    T* end() {
        return &arr_[size_];
    }

    const T* end() const {
        return &arr_[size_];
    }
public:
    T& operator[](size_t index) {
        return arr_[index];
    }

    const T& operator[](size_t index) const {
        return arr_[index];
    }
private:

    void addMemory() {
        capacity_ *= 2;
        T* tmp = arr_;
        arr_ = new T[capacity_];
        for (size_t i = 0; i < size_; ++i) arr_[i] = tmp[i];
        delete[] tmp;
    }

    T* arr_;
    size_t size_{};
    size_t capacity_{};
};

template<typename T>
inline std::ostream& operator<<(std::ostream& os, const Vector<T>& vec) {
    for (const T& val : vec) os << val << " ";
    return os;
}


void swap(float& a, float& b);
float down(const float x);
float area(axisVector a, axisVector b, axisVector c);
bool between(float a, float b, double c);
bool intersect_1(float a, float  b, float c, float d);
int det(int a, int b, int c, int d);
bool intersect(axisVector a, axisVector b, axisVector c, axisVector d);
int random(int min, int max);
std::string format(const char* fmt, ...);

#endif
