#ifndef __PLANET_H__
#define __PLANET_H__
#include "Base.h"
#include "Jedi.h"
///
/// Inherits of Base class
/// 

/* default value for capacity of this class */
const int DEFAULT_CAPACITY = 64;

class Planet: public Base {

public:
/// Implements big four and constructor with parameter from type ifstream 
	Planet();
	Planet(std::ifstream& fin);
	Planet(int cap, int count, Jedi* jedi, const char* planet_name);
	Planet(const Planet& oth);
	Planet& operator=(const Planet& rhs);
	virtual ~Planet();

	/* increases the given Jedi by one rank up in ladder and increases its strength by a formula */
	void promote_jedi(const char* jedi_name, double multiplier);

	/* decreases the given Jedi by one rank down in ladder and lowers its strength by a formula */
	void demote_jedi(const char* jedi_name, double multiplier);

    /// removes jedi from this planet 
	/// @returns True if is successful removed jedi, otherwise false
	bool remove_jedi(const char* jedi_name);

	/* outputs information about strongest(mean by force) jedi on given planet */
	void get_strongest_jedi()const;

	/* outputs the youngest Jedi inhabiting on this planet and has the appropriate rank */
	void get_youngest_jedi(const Rank& jedi_rank)const;

	/* outputs the information on *file* for Planet */
	void print_planet_info_to_file(const char* jedi_name, std::ofstream& fout)const;

	/* outputs the information on *console* for the Planet */
	void print_planet_info_to_console(const char* jedi_name, std::ostream& out)const;

	/* returns the most common color to light sword planet that enjoys at least one GRAND_MASTER  */
	const char* get_most_used_saber_color()const;

	/* sorts the jedi on this planet */
	void sort_jedi();

	/* @returns name of class */
	static const char* get_class_name();

	/* input from console for Planet */
	friend std::istream& operator>>(std::istream& in, Planet& oth);

	/* formatted output for Planet on console */
	friend std::ostream& operator<<(std::ostream& out, const Planet& oth);

	/* operator[] */
	Jedi& operator[](int ind);

	/* operator[] for const object */
	const Jedi& operator[](int ind)const;

	/* help method for operator[] */
	Jedi& at(int ind);

	/* help method for const operator[] */
	const Jedi& at(int ind)const;

	/* push back new jedi at dynamic array */
	void push_back(const Jedi& oth);

	/* request a change in capacity */
	void reserve(int cap);

/// Override methods from class Base
	/* @returns A pointer to a dynamically allocated polymorphic Planet */
	virtual Base* clone()const override;

	/* outputs formatted information for given planet on *console* */
	virtual void print(std::ostream& out)const override;

	/* outputs formatted information for given planet on *file* */
	virtual void print_to_file(std::ofstream& fout)const override;

	/* add jedi on this planet */
	virtual void create_jedi(const char* planet_name, const char* jedi_name, const char* jedi_rank, int jedi_age, const char* saber_color, double jedi_strength)override;

	/* reading information for planet from *console* */
	virtual void read(std::istream& in)override;

	/* reading information for planet from *file* */
	virtual void read_from_file(std::ifstream& fin)override;

	/* checks string is it Planet object */
	virtual bool is_valid_type(const char* type)const override;

	/// @return type of object from this class, which is "planet" in this case 
	/// @note help further to create object from this class  
	virtual const char* type_name()const override;

private:
	/* help method for operator= and copy ctor */
	void cpy(const Planet& oth);

	/* deletes all dynamic allocated memory in Planet, more precisely dector call it */
	void clean();

public:
	/* @returns Counts of jedi on this planet */
	int get_count_jedi()const;

	/* @returns Capacity of living jedi in this planet */
	int get_capacity()const;

	/* @returns Name of planet */
	const char* get_planet_name()const;

	/* @returns Return jedi at given index */
	Jedi get_jedi_by_index(int ind)const;

	/* @returns Array of jedi */
	Jedi* get_jedi()const;

private:
	/* count of jedi in this planet */
	int   m_count_jedi;
	/* capacity of living jedi in this planet */
	int   m_capacity;
	/* dynamic array of Jedi */
	Jedi* m_jedi;
	/* name of planet */
	char* m_planet_name;

};

#endif //__PLANET_H__