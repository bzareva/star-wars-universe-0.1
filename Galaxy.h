#ifndef __GALAXY_H__
#define __GALAXY_H__
#include "Planet.h"
///
/// Inherits of Base class. 
/// Container of planets. 
///
class Galaxy : public Base {

public:
	/// default constructor
	Galaxy() = default;

	/// constructor with parameter from type ifstream for load to text file
	Galaxy(std::ifstream& fin);

	/// constructor with parameters
	Galaxy(const Vector<Planet>& planets);

	/// constructor who adds only one planets for begin object
	Galaxy(const Planet& planet);

	/// copy constructor
	Galaxy(const Galaxy& rhs);

	/// assign content
	Galaxy& operator=(const Galaxy& rhs);

	/// move copy constructor
	Galaxy(Galaxy&& rhs)noexcept;

	/// move assign content
	Galaxy& operator=(Galaxy&& rhs)noexcept;

	/// input from console for Galaxy
	friend std::istream& operator>>(std::istream& in, Galaxy& obj);

	/// formatted output for Galaxy on console
	friend std::ostream& operator<<(std::ostream& out, const Galaxy& obj);

	/// gathers the inhabitants of two galaxy
	friend Galaxy operator+(Galaxy lhs, const Galaxy& rhs);

	/// adds planet on galaxy
	friend Galaxy operator+(Galaxy lhs, const Planet& rhs);

	/// remove planet from this galaxy
	friend Galaxy operator-(Galaxy lhs, const Planet& rhs);

	/// adds planet on this galaxy
	Galaxy& operator+=(const Planet& rhs);

	/// gathers two galaxy
	Galaxy& operator+=(const Galaxy& rhs);

	/// remove planet from this galaxy
	Galaxy& operator-=(const Planet& rhs);

	/// access element(nonconstant)
	Planet& operator[](const unsigned& index);

	/// access element(constant) 
	const Planet& operator[](const unsigned& index)const;

	/// help method for access element(nonconstant)
	Planet& at(const unsigned& index);

	/// help method for access element(constant)
	const Planet& at(const unsigned& index)const;

	/// @returns A pointer to a dynamically allocated polymorphic Planet
	virtual Base* clone()const final;

	/// outputs formatted information for given planet on *file* 
	virtual void write_to_file(std::ofstream& fout)const final;

	/// reading information for galaxy from *file*
	virtual void read_from_file(std::ifstream& fin)final;

	///
	/// @return type of object from this class, which is "galaxy" in this case
	/// @note help further to create object from this class
	///
	virtual String type_name()const final;

	/// add jedi on this planet
	virtual void create_jedi(const String& planet_name, const String& jedi_name, const Rank& jedi_rank, const unsigned& jedi_age, const String& saber_color, const double& jedi_strength)final;

	/// remove jedi from this planet
	virtual void remove_jedi(const String& jedi_name, const String& planet_name)final;

	/// @returns Strongest jedi on this planet
	virtual Jedi get_strongest_jedi(const String& planet_name)const final;

	/// @returns Youngest jedi on this planet
	virtual Vector<Jedi> get_youngest_jedi(const String& planet_name, const Rank& jedi_rank)const final;

	/// @returns Most used saber color on this planet by given planet name and rank of jedi
	virtual String get_most_used_saber_color(const String& planet_name, const Rank& jedi_rank)const final;

	/// @returns Most used saber color on this planet by given planet name
	virtual String get_most_used_saber_color(const String& planet_name)const final;

	/// print information about this planet
	virtual void print_planet(const String& planet_name)final;

	/// print information about jedi
	virtual void print_jedi(const String& jedi_name)const final;

	/// increases the given Jedi by one rank up in ladder and increases its strength by a formula
	virtual void promote_jedi(const String& jedi_name, const double& multiplier)final;

	/// decreases the given Jedi by one rank down in ladder and lowers its strength by a formula
	virtual void demote_jedi(const String& jedi_name, const double& multiplier)final;

	/// adds planet to galaxy
	void add_planet(const Planet& planet);

	/// @returns Count of jedi on this planet
	unsigned get_count_planet()const;

	/// @returns Name of planet
	String get_planet_name(const unsigned& index)const;

	/// console outputs is sorted form (lexicographic) information about the inhabitants two Jedi planets
	void operator_plus(const String& lhs_planet, const String& rhs_planet);

	/// adds vector of jedi in given planet 
	void add_vec_jedi(const Vector<Jedi>& jedi, const String& planet_name);

private:
	/// make data with null value
	void to_zero();

	/// help method for operator= and copy ctor
	void copy(const Galaxy& rhs);

private:
	Vector<Planet> m_planets;

};

#endif //__GALAXY_H__