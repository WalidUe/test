#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include<iostream>
#include"MyString.h"

//No-args constructor
MyString::MyString()
	:str{ nullptr }
{
	str = new char[1];
	*str = '\0';
}

//Overloaded Constructor
MyString::MyString(const char* s)
	:str{ nullptr }
{
	if (s == nullptr)
	{
		str = new char[1];
		*str = '\0';
	}
	else
	{
		str = new char[std::strlen(s) + 1];
		strcpy(str, s);


	}
}
//Copy Constructor
MyString::MyString(const MyString& source)
	:str{ nullptr }
{
	str = new char[std::strlen(source.str) + 1];
	strcpy(str, source.str);

}

MyString::~MyString()
{
	delete[]str;
}

//Copy Assignment| This works with l-value references. by default if a move assigment operator is not overloaded then this copy assignment is used.
MyString& MyString::operator=(const MyString& rhs)//copy the right hand side object to the left hand side object.
{
	std::cout << "Copy Assignment" << std::endl;
	if (this == &rhs)//Is it the same object (comparing their addresses)
		return *this;//return a reference.

	delete[] str;
	str = new char[std::strlen(rhs.str) + 1];
	std::strcpy(this->str, rhs.str);
	return *this;


}


void MyString::display()const
{
	std::cout << str << ":" << getLength() << std::endl;
}


//Getters
int MyString::getLength() const { return std::strlen(str); }
const char* MyString::getStr()const { return str; }

