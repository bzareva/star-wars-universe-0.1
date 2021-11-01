#ifndef __BASE_H__
#define __BASE_H__
#include "Jedi.h" 
#include "Vector.h"
///
/// Abstract base class.
/// Planet and Galaxy herited this class and they implement all of the functions in own way.
///
class Base {

public:
	/// default constructor
	Base() = default;vdvdfvdvd

	/// default assign content
	Base& operator=(const Base& rhs) = default;

	/// default destructor
	virtual ~Base() = default;

	///
	/// Pure virtual clone method. Makes a copy of the Base object.
	/// Access to the object of this class is realize with clone method.
	///
	virtual Base* clone()const = 0;

	/// Pure virtual print method which allows each of Base heirs(Jedi, Planet) to be displayed in its own way on *file*.
	virtual void write_to_file(std::ofstream& fout)const = 0;

	/// Pure virtual method for reading information from *file*.
	virtual void read_from_file(std::ifstream& fin) = 0;

	/// Pure virtual method which return name of type object.
	virtual String type_name()const = 0;

	/// 
	/// Pure virtual create method.
	/// Display a message whether the addition was successful or not (there is a Jedi with
    /// such a name on this or that planet, or not there is a planet with such a name). 
	/// 
	virtual void create_jedi(const String& planet_name, const String& jedi_name, const Rank& jedi_rank, const unsigned& jedi_age, const String& saber_color, const double& jedi_strength) = 0;

	/// Displays a message whether the removal was successful or not (the Jedi did not inhabits this planet). 
	virtual void remove_jedi(const String& jedi_name, const String& planet_name) = 0;

	/// Displays information about the strongest Jedi of the submitted planet(with the greatest force).   
	virtual Jedi get_strongest_jedi(const String& planet_name)const = 0;

	///
	/// Brings out the youngest Jedi inhabiting the given planet and has
    /// the corresponding rank (if they are  more than one, to display the first on
    /// alphabetical order if none will be displayed appropriate message). 
	///
	virtual Vector<Jedi> get_youngest_jedi(const String& planet_name, const Rank& jedi_rank)const = 0;

	/// @returns The most common color to light sword in the given rank of the respective planet
	virtual String get_most_used_saber_color(const String& planet_name, const Rank& jedi_rank)const = 0;
	 
	/// @returns The most common color to light sword planet that enjoys at least one GRAND_MASTER
	virtual String get_most_used_saber_color(const String& planet_name)const = 0;

	/// Displays the information about heirs in of Base class an appropriate way.
	virtual void print_planet(const String& planet_name) = 0;

	/// Outputs the information for the Jedi, as well as which planet it currently inhabits.
	virtual void print_jedi(const String& jedi_name)const = 0;

	/// Increases the given Jedi by one rank up in ladder and increases its strength by a formula.
	virtual void promote_jedi(const String& jedi_name, const double& multiplier) = 0;

	/// Decreases the given Jedi by one rank down in ladder and lowers its strength by a formula.
	virtual void demote_jedi(const String& jedi_name, const double& multiplier) = 0;

};

#endif //__BASE_H__
