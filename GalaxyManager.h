#ifndef __GALAXY_MANAGER_H__
#define __GALAXY_MANAGER_H__
#include "Galaxy.h"

class GalaxyManager {

public:
    GalaxyManager() : m_is_open(false) {};

    Galaxy read_galaxy();
    Planet read_planet();
    Jedi read_jedi();
    void print_galaxy()const;

    void open_file(const String& file_name);
    void print(const String& type_object, const String& name)const;
    void help()const;
    void close_file();
    void save();
    void save_as(const String& file_name);
    void exit_command()const;

    void add_planet(const String& planet_name);
    void create_jedi(const String& planet_name, const String& jedi_name, const Rank& jedi_rank, const unsigned& jedi_age, const String& saber_color, const double& jedi_strength);  
    void remove_jedi(const String& jedi_name, const String& planet_name);
    void promote_jedi(const String& jedi_name, const double& multiplier);
    void demote_jedi(const String& jedi_name, const double& multiplier);
    void get_strongest_jedi(const String& planet_name)const;
    void get_youngest_jedi(const String& planet_name, const Rank& jedi_rank)const;
    String get_most_used_saber_color(const String& planet_name, const Rank& jedi_rank)const;
    String get_most_used_saber_color(const String& planet_name)const;
    void operator_plus(const String& lhs_planet_name, const String& rhs_planet_name);
    void print_planet(const String& planet_name)const;
    void print_jedi(const String& jedi_name)const;

private:
    bool   m_is_open;
    String m_file_name;
    Galaxy m_universe;
     
};

#endif //__GALAXY_MANAGER_H__