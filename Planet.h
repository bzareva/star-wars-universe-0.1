#ifndef __PLANET_H__
#define __PLANET_H__
#include "Base.h"
///
/// Inherits of Base class
///
class Planet : public Base {

public:
	/// default constructor
	Planet() = default;

	/// constructor with parameter from type ifstream for load to text file
	Planet(std::ifstream& fin);

	/// constructor with parameters
	Planet(const Vector<Jedi>& jedi, const String& planet_name = String("def_planet"));

	/// copy constructor
	Planet(const Planet& obj);

	/// assign content
	Planet& operator=(const Planet& rhs);
	
	/// input from console for Planet
	friend std::istream& operator>>(std::istream& in, Planet& obj);

	/// formatted output for Planet on console
	friend std::ostream& operator<<(std::ostream& out, const Planet& obj);

	/// gathers the inhabitants of two planets
	friend Planet operator+(Planet lhs, const Planet& rhs);

	/// adds jedi on this planet
	friend Planet operator+(Planet lhs, const Jedi& rhs);

	/// remove jedi from this planet
	friend Planet operator-(Planet lhs, const Jedi& rhs);

	/// checks if two planets are equal 
	bool operator==(const Planet& rhs)const;

	/// checks if two planets are not equal
	bool operator!=(const Planet& rhs)const;

	/// adds jedi on this planet
	Planet& operator+=(const Jedi& rhs);

	/// gathers the inhabitants of two planets
	Planet& operator+=(const Planet& rhs);

	/// remove jedi from this planet
	Planet& operator-=(const Jedi& rhs);

	/// access element(nonconstant)
	Jedi& operator[](unsigned index);

	/// access element(constant) 
	const Jedi& operator[](unsigned index)const;

	/// help method for access element(nonconstant)
	Jedi& at(unsigned index);

	/// help method for access element(constant)
	const Jedi& at(unsigned index)const;

    /// @returns A pointer to a dynamically allocated polymorphic Planet
	virtual Base* clone()const override;

    /// outputs formatted information for given planet on *file* 
	virtual void write_to_file(std::ofstream& fout)const override;

	/// reading information for planet from *file*
	virtual void read_from_file(std::ifstream& fin)override;

	///
	/// @return type of object from this class, which is "planet" in this case 
	/// @note help further to create object from this class 
	///
	virtual String type_name()const override;

    /// add jedi on this planet
	virtual void create_jedi(const String& planet_name, const String& jedi_name, const Rank& jedi_rank, const unsigned& jedi_age, const String& saber_color, const double& jedi_strength)override;

	/// remove jedi from this planet
	virtual void remove_jedi(const String& jedi_name, const String& planet_name)override;

	/// @returns Strongest jedi on this planet
	virtual Jedi get_strongest_jedi(const String& planet_name)const override;

	/// @returns Youngest jedi on this planet
	virtual Vector<Jedi> get_youngest_jedi(const String& planet_name, const Rank& jedi_rank)const override;

	/// @returns Most used saber color on this planet by given planet name and rank of jedi
	virtual String get_most_used_saber_color(const String& planet_name, const Rank& jedi_rank)const override;

	/// @returns Most used saber color on this planet by given planet name
	virtual String get_most_used_saber_color(const String& planet_name)const override;

	/// print information about this planet
	virtual void print_planet(const String& planet_name)override;

	/// print information about jedi
	virtual void print_jedi(const String& jedi_name)const override;

	/// increases the given Jedi by one rank up in ladder and increases its strength by a formula
	virtual void promote_jedi(const String& jedi_name, const double& multiplier)override;

	/// decreases the given Jedi by one rank down in ladder and lowers its strength by a formula
	virtual void demote_jedi(const String& jedi_name, const double& multiplier)override;

	/// sorts jedi on this planet
	void sort();

	/// sorts jedi rank's
	void sort_rank();

	/// sort jedi name's
	void sort_names();

	/// @returns Count of jedi on this planet
	unsigned get_count_jedi()const;

	/// @returns Name of planet
	String get_planet_name()const;

	/// @returns All jedi on this planet
	Vector<Jedi> get_jedi()const;

	/// @returns Jedi on given index
	Jedi get_jedi(const unsigned& index)const;

	/// setter for planet name
	void set_planet_name(const String& planet_name);

	/// setter for inhabits jedi
	void set_jedi(const Vector<Jedi>& jedi);

private:
	/// help method for operator= and copy ctor
	void copy(const Planet& obj);

private:
	String       m_planet_name;
	Vector<Jedi> m_jedi;

};

#endif //__PLANET_H__