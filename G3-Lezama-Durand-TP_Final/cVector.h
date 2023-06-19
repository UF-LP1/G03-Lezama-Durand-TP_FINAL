#pragma once
#include "Header.h" 

 template <typename T>
class cVector: public vector<T>{
public:
	void operator+(T& element);
};

template <typename T>
inline void cVector <T>:: operator+(T& element) {
	this->push_back(element);
}


