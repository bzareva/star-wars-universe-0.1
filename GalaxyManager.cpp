#include "GalaxyManager.h"

GalaxyManager::GalaxyManager() 
 :m_is_open(false) {}

GalaxyManager::GalaxyManager(const String& file_name, const Galaxy& universe)
 :m_is_open(false), m_file_name(file_name), m_universe(universe) {}

void GalaxyManager::open_file(const String& file_name) {

    if (m_is_open) {
        std::cout << "\nFile is already opened!\n";
        return;
    }

    std::ifstream fin(file_name.get_string(), std::ios::in);
    if (!fin) {

        std::cout << "Creating empty file with name " << file_name << std::endl;

        std::ofstream fout(file_name.get_string(), std::ios::out);
        if (!fout) {
            throw std::runtime_error("Run again the program!\n");
        }

        fout.clear();
        fout.close();
    }

    m_is_open   = true;
    m_file_name = file_name;
    std::cout << "Successfully opened " << m_file_name << std::endl;
}

void GalaxyManager::print(const String& type_object, const String& name) {

    if (!m_is_open) {

        if (type_object == String("planet") || type_object == String("PLANET")) {
            m_universe.print_planet(name);
            std::cout << "Successfully printed information about planet in file " << m_file_name << std::endl;
            return;
        }

        if (type_object == String("jedi") || type_object == String("JEDI")) {
            m_universe.print_jedi(name);
            std::cout << "Successfully printed information about jedi in file " << m_file_name << std::endl;
            return;
        }
    }
    std::cout << "\nCommand print cannot be executed because file is not open!\n";
}

void GalaxyManager::help()const {

    std::cout << "\nThe following commands are supported:\n"
        << "open <file> opens <file>\n"
        << "close closes currently opened file\n"
        << "save saves the currently open file\n"
        << "saveAs <file>\tsaves the currently open file in <file>\n"
        << "help prints this information\n"
        << "exit exits from program\n"
        << "add_planet <planet_name> adds planet\n"
        << "create_jedi <planet_name> <jedi_name> <jedi_rank> <jedi_age> <saber_color> <jedi_strength> adds the given jedi at given planet\n"
        << "removeJedi <jedi_name> <planet_name> remove jedi from given planet\n"
        << "promote_jedi <jedi_name> <multiplier> raises the given Jedi by one rank up in ladder and increases its strength\n"
        << "demote_jedi <jedi_name> <multiplier> reduced the rank of the submitted Jedi by one rank down the ladder and lowers its strength\n"
        << "get_strongest_jedi <planet_name> outputs information about the strongest Jedi of the submitted planet(with the greatest force)\n"
        << "get_youngest_jedi <planet_name> <jedi_rank>  the youngest Jedi inhabiting filed planet and has the appropriate rank\n"
        << "get_most_used_saber_color <planet_name> <jedi_rank> returns the most common saber color on the given planet and rank of jedi\n"
        << "get_most_used_saber_color <planet_name> returns the most common saber color on the given planet that it is used at least one GRAND MASTER\n"
        << "print <planet_name> outputs the name of the planet appropriately and  Jedi who inhabit it\n"
        << "print <jedi_name> outputs formatted information about the Jedi, as well as which planet it currently inhabits\n"
        << "<planet_name> + <planet_name> outputs information about the inhabitants the two Jedi planets in short format\n"; 
}

void GalaxyManager::close_file() {

    if (!m_is_open) {
        std::cerr << "File is already closed or is not opened!\n";
        return;
    }

    std::ofstream fout(m_file_name.get_string(), std::ios::trunc | std::ios::out);
    if (!fout) {
        throw std::runtime_error("Run again the program!\n");
    }

    fout.clear();
    fout.close();
    m_is_open = false;
    std::cout << "Successfully close file " << m_file_name << std::endl;
}

void GalaxyManager::save() {

    if (!m_is_open) {
        std::cerr << "File is not opened!\n";
        return;
    }

    std::ofstream fout(m_file_name.get_string(), std::ios::out | std::ios::trunc);
    if (!fout) {
        throw std::runtime_error("File cannot be opened!\n");
    }

    m_universe.write_to_file(fout);
    fout.clear();
    fout.close();
    m_is_open = false;
    std::cout << "\nSuccessfully saved "<< m_file_name << std::endl;
}

void GalaxyManager::save_as(const String& file_name) {

    std::ofstream fout(file_name.get_string(), std::ios::out | std::ios::trunc);
    if (!fout) {
        throw std::runtime_error("File cannot be opened!\n");
        return;
    }

    m_universe.write_to_file(fout);
    fout.clear();
    fout.close();
    m_is_open = false;    
    std::cout << "\nSuccessfully saved another" << file_name << std::endl;
}

void GalaxyManager::exit_command()const {

    exit(0); //EXIT_FAILURE 
}

void GalaxyManager::add_planet(const String& planet_name) {

    Planet curr(Vector<Jedi>(), planet_name);
    m_universe.add_planet(curr);
}

void GalaxyManager::create_jedi(const String& planet_name, const String& jedi_name, const Rank& jedi_rank, const unsigned& jedi_age, const String& saber_color, const double& jedi_strength) {

    m_universe.create_jedi(planet_name, jedi_name, jedi_rank, jedi_age, saber_color, jedi_strength);
}

void GalaxyManager::remove_jedi(const String& jedi_name, const String& planet_name) {

    m_universe.remove_jedi(jedi_name, planet_name);
}

void GalaxyManager::promote_jedi(const String& jedi_name, const double& multiplier) {

    for (unsigned i = 0; i < m_universe.get_count_planet(); ++i) {
        m_universe[i].promote_jedi(jedi_name, multiplier);
    }
}

void GalaxyManager::demote_jedi(const String& jedi_name, const double& multiplier) {

    for (unsigned i = 0; i < m_universe.get_count_planet(); ++i) {
        m_universe[i].demote_jedi(jedi_name, multiplier);
    }
}

void GalaxyManager::get_strongest_jedi(const String& planet_name)const {

    m_universe.get_strongest_jedi(planet_name);
}

void GalaxyManager::get_youngest_jedi(const String& planet_name, const Rank& jedi_rank)const {

    m_universe.get_youngest_jedi(planet_name, jedi_rank);
}

String GalaxyManager::get_most_used_saber_color(const String& planet_name, const Rank& jedi_rank)const {

   return m_universe.get_most_used_saber_color(planet_name, jedi_rank);
}

String GalaxyManager::get_most_used_saber_color(const String& planet_name)const {

   return m_universe.get_most_used_saber_color(planet_name);
}

void GalaxyManager::operator_plus(const String& lhs_planet_name, const String& rhs_planet_name) {

    m_universe.operator_plus(lhs_planet_name, rhs_planet_name);
}

void GalaxyManager::print_planet(const String& planet_name) {

    m_universe.print_planet(planet_name);
}

void GalaxyManager::print_jedi(const String& jedi_name)const {

    m_universe.print_jedi(jedi_name);
}

String GalaxyManager::get_file_name()const {

    return m_file_name;
}