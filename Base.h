#ifndef __BASE_H__
#define __BASE_H__
#include <iostream>
#include <fstream>
/// <summary>
/// 
/// </summary>

class Base {

public:

	Base() = default;

	Base& operator=(const Base& other) = default;

	virtual ~Base() = default;

	/// Makes a copy of the Base object. Access to the object of this class is realize with clone method
	virtual Base* clone()const = 0;

	/// It allows each of Base heirs(Jedi, Moon, Planet) to be displayed in its own way(prints to console)
	virtual void print(std::ostream&)const = 0;

	/// It allows each of Base heirs(Jedi, Moon, Planet) to be displayed in its own way(prints to file)
	virtual void print_to_file(std::ofstream&)const = 0;

	/// Read from file
	virtual void read_from_file(std::ifstream&) = 0;

	/// Checks if the entered string is valid type
	virtual bool isValidType(const char*)const = 0;

	/// Returns type of data
	virtual const char* typeName()const = 0;

};

#endif ///__BASE_H__