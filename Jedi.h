#ifndef __JEDI_H__
#define __JEDI_H__
#include "String.h"
///
/// Describes a Jedi
///
class Jedi {

public:
	/// constructor with parameter from type ifstream for load to text file
	Jedi(std::ifstream& fin);

	/// constructor with parameters, each of them has default values
	Jedi(const unsigned& age = 56, const double& force = 34.43, const Rank& rank = Rank::YOUNGLING, const String& name = String("def_jedi"), const String& color_of_lightsaber = String("def_lightsaber"));

	/// copy constructor
	Jedi(const Jedi& oth);

	/// assign content
	Jedi& operator=(const Jedi& rhs);

	/// compares two jedi by their ages are equal
	bool operator==(const Jedi& rhs)const;	

	/// compares two jedi by their ages are not equal
	bool operator!=(const Jedi& rhs)const;

	/// compares two jedi and if left side jedi is younger return true, otherwise false
	bool operator<(const Jedi& rhs)const;

	/// input from console for jedi
	friend std::istream& operator>>(std::istream& in, Jedi& oth);

	/// formatted output for jedi on console
	friend std::ostream& operator<<(std::ostream& out, const Jedi& oth);

	/// increases the given jedi by one rank up in ladder and increases its strength by a formula
	void promote(const double& multiplier);

	/// decreases the given jedi by one rank down in ladder and lowers its strength by a formula
	void demote(const double& multiplier);

	/// @returns A pointer to a dynamically allocated jedi 
	Jedi* clone()const;

	/// outputs formatted information for jedi on *file*  
	void write_to_file(std::ofstream& fout)const;

	/// reading information for jedi from *file*
	void read_from_file(std::ifstream& fin);

	/// print information about jedi
	void print()const;

	/// @returns Num of rank
	unsigned rank_num()const;

private:
	/// help method for operator= and copy ctor
	void copy(const Jedi& oth);

public: 
	/// setter for age of jedi
	void set_age(const unsigned& age);

	/// setter for force of jedi
	void set_force(const double& force);

	/// setter for name of jedi
	void set_name_jedi(const String& name);

	/// setter for color of lightsaber of jedi
	void set_color_of_lightsaber(const String& color_of_lightsaber);

	/// setter for rank of jedi
	void set_rank(const Rank& rank);

	/// @returns Age of jedi
	unsigned get_age()const;

	/// @returns The force of jedi
	double get_force()const;

	/// @returns Name of jedi
	String get_name_jedi()const;

	/// @returns Color of the lightsaber of jedi
	String get_color_of_lightsaber()const;

	/// @returns Rank of jedi
	Rank get_rank()const;

private:	
	unsigned m_age;
	Rank     m_rank;
	double   m_force;
	String   m_name_jedi;
	String   m_color_of_lightsaber;

};

#endif //__JEDI_H__