#include "GalaxyManager.h"

GalaxyManager::GalaxyManager(const String& file_name, const Galaxy& universe)
 :m_is_open(false), m_file_name(file_name), m_universe(universe) {}

void GalaxyManager::open_file() {

    if (m_is_open) {
        std::cout << "File is already opened!\n";
        return;
    }

    std::ifstream fin(m_file_name.get_string(), std::ios::in);
    if (!fin || !fin.is_open()) {

        std::cout << "Creating empty file with name " << m_file_name << "!\n";

        std::ofstream fout(m_file_name.get_string(), std::ios::out);
        if (!fout || !fout.is_open()) {
            throw std::runtime_error("There is a problem with the program and need to be restarted!\n");
        }

        m_is_open  = true;
        m_universe = Galaxy();

        fout.clear();
        fout.close();

        return;
    }

    m_universe.read_from_file(fin);
    m_is_open = true;
    std::cout << "Successfully opened " << m_file_name << "!\n";
}

void GalaxyManager::print(const String& name) {

    if (m_is_open) {
        m_universe.print_planet(name);
        m_universe.print_jedi(name);
        return;
    }

    std::cout << "\nCommand print can not be executed because file is not open!\n";
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

    std::ofstream fout(m_file_name.get_string(), std::ios::out); //, std::ios::trunc | 
    if (!fout) {
        throw std::runtime_error("There is a problem with the program and need to be restarted!\n");
    }

    fout.clear();
    fout.close();
    m_is_open = false;
    std::cout << "Successfully close file " << m_file_name << "!\n";
}

void GalaxyManager::save() {

    if (!m_is_open) {
        std::cerr << "File is not opened!\n";
        return;
    }

    std::ofstream fout(m_file_name.get_string(), std::ios::out); // | std::ios::trunc
    if (!fout) {
        throw std::runtime_error("There is a problem with the program and need to be restarted!\n");
    }

    m_universe.write_to_file(fout);

    fout.clear();
    fout.close();

    m_is_open = false;
    std::cout << "\nSuccessfully saved "<< m_file_name << " !\n";
}

void GalaxyManager::save_as(const String& new_file_name) {

    std::ofstream fout(new_file_name.get_string(), std::ios::out | std::ios::trunc);
    if (!fout || !fout.is_open()) {
        throw std::runtime_error("There is a problem with the program and need to be restarted!\n");
    }

    m_universe.write_to_file(fout);

    fout.clear();
    fout.close();

    m_is_open = false;    
    std::cout << "\nSuccessfully saved another " << new_file_name << "!\n";
}

void GalaxyManager::exit_command()const {

    exit(0); 
}

void GalaxyManager::add_planet(const String& planet_name) {

    if (!m_is_open) {
        std::cout << "\nCommand add_planet can not be executed because file is not open!\n";
        return;
    }

    Planet curr(Vector<Jedi>(), planet_name);
    m_universe.add_planet(curr);
}

void GalaxyManager::create_jedi(const String& planet_name, const String& jedi_name, const Rank& jedi_rank, const unsigned& jedi_age, const String& saber_color, const double& jedi_strength) {

    if (!m_is_open) {
        std::cout << "\nCommand create_jedi can not be executed because file is not open!\n";
        return;
    }

    m_universe.create_jedi(planet_name, jedi_name, jedi_rank, jedi_age, saber_color, jedi_strength);
}

void GalaxyManager::remove_jedi(const String& jedi_name, const String& planet_name) {

    if (!m_is_open) {
        std::cout << "\nCommand remove_jedi can not be executed because file is not open!\n";
        return;
    }

    m_universe.remove_jedi(jedi_name, planet_name);
}

void GalaxyManager::promote_jedi(const String& jedi_name, const double& multiplier) {

    if (!m_is_open) {
        std::cout << "\nCommand promote_jedi can not be executed because file is not open!\n";
        return;
    }

    for (unsigned i = 0; i < m_universe.get_count_planet(); ++i) {
        for (unsigned j = 0; j < m_universe[i].get_count_jedi(); ++j) {

            if (jedi_name == m_universe[i].get_jedi()[j].get_name_jedi()) {
                m_universe[i].promote_jedi(jedi_name, multiplier);
            }
        }
    }
}

void GalaxyManager::demote_jedi(const String& jedi_name, const double& multiplier) {

    if (!m_is_open) {
        std::cout << "\nCommand demote_jedi can not be executed because file is not open!\n";
        return;
    }

    for (unsigned i = 0; i < m_universe.get_count_planet(); ++i) {
        for (unsigned j = 0; j < m_universe[i].get_count_jedi(); ++j) {

            if (jedi_name == m_universe[i].get_jedi()[j].get_name_jedi()) {
                m_universe[i].demote_jedi(jedi_name, multiplier);
            }
        }
    }
}

void GalaxyManager::get_strongest_jedi(const String& planet_name)const {

    if (!m_is_open) {
        std::cout << "\nCommand get_strongest_jedi can not be executed because file is not open!\n";
        return;
    }

    std::cout << m_universe.get_strongest_jedi(planet_name) << std::endl;
}

void GalaxyManager::get_youngest_jedi(const String& planet_name, const Rank& jedi_rank)const {

    if (!m_is_open) {
        std::cout << "\nCommand get_youngest_jedi can not be executed because file is not open!\n";
        return;
    }

    Vector<Jedi> temp = m_universe.get_youngest_jedi(planet_name, jedi_rank);
    for (unsigned i = 0; i < temp.size(); ++i) {
        std::cout << temp[i];
    }
}

void GalaxyManager::get_most_used_saber_color(const String& planet_name, const Rank& jedi_rank)const {

    if (!m_is_open) {
        std::cout << "\nCommand get_most_used_saber_color can not be executed because file is not open!\n";
        return;
    }

    std::cout << m_universe.get_most_used_saber_color(planet_name, jedi_rank) << std::endl;
}

void GalaxyManager::get_most_used_saber_color(const String& planet_name)const {

    if (!m_is_open) {
        std::cout << "\nCommand get_most_used_saber_color can not be executed because file is not open!\n";
        return;
    }

   std::cout << m_universe.get_most_used_saber_color(planet_name) << std::endl;
}

void GalaxyManager::operator_plus(const String& lhs_planet_name, const String& rhs_planet_name) {

    if (!m_is_open) {
        std::cout << "\nCommand operator_plus can not be executed because file is not open!\n";
        return;
    }

    m_universe.operator_plus(lhs_planet_name, rhs_planet_name);
}

String GalaxyManager::get_file_name()const {

    return m_file_name;
}

void GalaxyManager::set_file_name(const String& file_name) {

    m_file_name = file_name;
}