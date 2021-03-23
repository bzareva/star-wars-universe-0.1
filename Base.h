#ifndef __BASE_H__
#define __BASE_H__
#include <iostream>
#include <fstream>
///
/// Abstract base class for Galaxy
/// Jedi and Planet herited this class. 
/// The heirs(Jedi and Planet) of Base class implement all of the functions in own way.
///
class Base {

public:

	Base() = default;

	Base& operator=(const Base& rhs) = default;

	virtual ~Base() = default;

	/// Pure virtual clone method 
	/// Makes a copy of the Base object. Access to the object of this class is realize with clone method.
	virtual Base* clone()const = 0;

	/// Pure virtual print method which allows each of Base heirs(Jedi, Planet) to be displayed in its own way on *console*
	virtual void print(std::ostream& out)const = 0;

	/// Pure virtual print method which allows each of Base heirs(Jedi, Planet) to be displayed in its own way on *file*
	virtual void print_to_file(std::ofstream& fout)const = 0;

	/// Pure virtual create method 
	virtual void create_jedi(const char* planet_name, const char* jedi_name, const char* jedi_rank, int jedi_age, const char* saber_color, double jedi_strength) = 0;

	/// Pure virtual method for reading information from *console*
	virtual void read(std::istream& in) = 0;

	/// Pure virtual method for reading information from *file*
	virtual void read_from_file(std::ifstream& fin) = 0;

	/// Pure virtual method which check is it valid type the submission parameter
	virtual bool is_valid_type(const char* type)const = 0;

	/// Pure virtual method which return name of type object
	virtual const char* type_name()const = 0;

};

#endif //__BASE_H__