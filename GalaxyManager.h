#ifndef __GALAXY_MANAGER_H__
#define __GALAXY_MANAGER_H__
#include "Galaxy.h"
/*!
 * Stores all commands and also has a datas which are:
 * file name and a variable type of bool- tells whether the file we are working with is closed or open 
 * and an object of type Galaxy- we need it for execution of all supported commands in program.
 */
class GalaxyManager {

public:
    //! default constructor
    GalaxyManager();

    //! constructor with parameters for datas in class
    GalaxyManager(const String& file_name, Galaxy universe = Galaxy());

    //! open file by wanted name
    void open_file(const String& file_name);

    //! print information about given object(Jedi or Planet) by wanted name
    void print(const String& type_object, const String& name);

    //! gives information about all commands which supported the program for successfully works
    void help()const;

    //! close current opened file
    void close_file();

    //! saves current information in file with which we works from starting the program
    void save();

    //! saves current information in another file
    void save_as(const String& file_name);

    //! exit program
    void exit_command()const;

    //! adds planet which name is choosen from user
    void add_planet(const String& planet_name);

    //! create jedi by given characteristic
    void create_jedi(const String& planet_name, const String& jedi_name, const Rank& jedi_rank, const unsigned& jedi_age, const String& saber_color, const double& jedi_strength);  

    //! deletes jedi who lives on given planet with wanted name
    void remove_jedi(const String& jedi_name, const String& planet_name);

    //! promote force on given jedi if has jedi with wanted name in galaxy
    void promote_jedi(const String& jedi_name, const double& multiplier);

    //! demote force on given jedi if has jedi with wanted name in galaxy
    void demote_jedi(const String& jedi_name, const double& multiplier);

    //! get strongest jedi on given planet
    void get_strongest_jedi(const String& planet_name)const;

    //! get youngest jedi on the given planet and rank
    void get_youngest_jedi(const String& planet_name, const Rank& jedi_rank)const;

    //! get most used saber color of jedi on given planet with wanted rank
    String get_most_used_saber_color(const String& planet_name, const Rank& jedi_rank)const;

    //! get most used saber color of jedi on given planet
    String get_most_used_saber_color(const String& planet_name)const;

    //! console outputs is sorted form(lexicographic) information about the inhabitants two planets
    void operator_plus(const String& lhs_planet_name, const String& rhs_planet_name);

    //! print information about the given planet
    void print_planet(const String& planet_name);

    //! print information about the given jedi
    void print_jedi(const String& jedi_name)const;

    //! @returns Name of file with which is current opened
    String get_file_name()const;

private:
    bool   m_is_open;
    String m_file_name;
    Galaxy m_universe;
     
};

#endif //__GALAXY_MANAGER_H__