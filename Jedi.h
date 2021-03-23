#ifndef __JEDI_H__
#define __JEDI_H__
#include <iostream>
#include <fstream>
#include "Base.h"
///
/// Inherits of Base class.
/// 
class Jedi: public Base {

public:
	/// Rank of jedi is enum class 
	/// 
	/// Contains the possible rank, that a jedi can have.
	/// Ranks are arranged in ascending order- 1, 2,.., 8
	/// 
	enum class Rank {
		YOUNGLING = 1,
		INITIATE,
		PADAWAN,
		KNIGHT_ASPIRANT,
		KNIGHT,
		MASTER, 
		BATTLE_MASTER,
		GRAND_MASTER
	};

/// Implements big four and ctor with  parameter from type ifstream 
	Jedi();
	Jedi(std::ifstream& ifs);
	Jedi(int age, double force, const Rank& rank, const char* name, const char* color_of_lightsaber);
	Jedi(const Jedi& oth);
	Jedi& operator=(const Jedi& rhs);
	virtual ~Jedi();

	/* @returns name of class */
	static const char* get_class_name();

	/* compares by age */
	bool operator==(const Jedi& rhs)const;	

	/* compares two jedi and if left side jedi is younger return true, otherwise false */
	bool operator<(const Jedi& rhs)const;

	/* formatted output for jedi on console */
	friend std::istream& operator>>(std::istream& is, Jedi& oth);

	/* input from console for jedi */
	friend std::ostream& operator<<(std::ostream& os, const Jedi& oth);

	/* increases the given Jedi by one rank up in ladder and increases its strength by a formula */
	void promote_jedi(double multiplier);

	/* decreases the given Jedi by one rank down in ladder and lowers its strength by a formula  */
	void demote_jedi(double multiplier);

/// Override methods from class Base
/// 	
	/* @returns A pointer to a dynamically allocated polymorphic Jedi */
	virtual Base* clone()const override;

	/* outputs formatted information for jedi on *console* */
	virtual void print(std::ostream& out)const override;

	/* outputs formatted information for jedi on *file* */
	virtual void print_to_file(std::ofstream& fout)const override;

	/* create jedi */
	virtual void create_jedi(const char* planet_name, const char* jedi_name, const char* jedi_rank, int jedi_age, const char* saber_color, double jedi_strength)override;
	 
	/* reading information for jedi from *console* */
	virtual void read(std::istream& in)override;
	
	/* reading information for jedi from *file* */
	virtual void read_from_file(std::ifstream& fin)override;
	
	/* checks is it from jedi object */
	virtual bool is_valid_type(const char* type)const override;
	
	/// @return type of object from this class, which is "jedi" in this case 
	/// @note help further to create object from this class  
	virtual const char* type_name()const override;

private:
	/* help method for operator= and copy ctor */
	void cpy(const Jedi& oth);

	/* deletes all dynamic allocated memory in Jedi, more precisely dector call it */
	void clean();

public: 
	/* setter for age of jedi */
	void set_age(int age);

	/* setter for force of jedi*/
	void set_force(double force);

	/* setter for name of jedi */
	void set_name_jedi(const char* name);

	/* setter for color of lightsaber of jedi */
	void set_color_of_lightsaber(const char* color_of_lightsaber);

	/* setter for rank of jedi */
	void set_rank(const Rank& rank);

	/* @returns A age of jedi */
	int get_age()const;

	/* @returns A force of jedi */
	double get_force()const;

	/* @returns A name of jedi */
	const char* get_name_jedi()const;

	/* @returns A color of the lightsaber of jedi */
	const char* get_color_of_lightsaber()const;

	/* @returns A rank of jedi */
	Rank get_rank()const;

private:	
	/* age of jedi */
	int    m_age;
	/* force of jedi*/
	double m_force;
	/* rank of jedi*/
	Rank   m_rank;
	/* name of jedi */
	char*  m_name_jedi;
	/* color of lightsaber of jedi */
	char*  m_color_of_lightsaber;

};

#endif //__JEDI_H__