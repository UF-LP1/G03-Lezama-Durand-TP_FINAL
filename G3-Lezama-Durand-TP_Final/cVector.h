#pragma once
#include "Header.h" 

 template <typename T>

class cVector: public vector<T>{
public:
	void operator+(T element);
	void operator-(T element);
	void operator==(T element);
	friend ostream& operator<<(ostream& out, const T& element);
};

template <typename T>
inline void cVector <T>:: operator+(T element) {
	this->push_back(element);
}

template <class T>
inline void cVector<T>:: operator-(T element) {
	this->erase(element);
}

template <class T>
inline void cVector<T>:: operator==(T element) {

}



