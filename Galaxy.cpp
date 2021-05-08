#include "Galaxy.h"

Galaxy::Galaxy() {

	m_planets.push_back(Planet());
}

Galaxy::Galaxy(std::ifstream& fin) {

	read_from_file(fin);
}

Galaxy::Galaxy(const Vector<Planet>& planets) {

	for (unsigned i = 0; i < planets.size(); ++i) {

		for (unsigned j = 0; j < planets[i].get_count_jedi(); ++j) {
			//add_planet(planets[i]);
			//m_planets += planets[i];
			m_planets.push_back(planets[i]);
		}
	}
}

Galaxy::Galaxy(const Planet& planet) {

	m_planets.push_back(planet);
}

Galaxy::Galaxy(const Galaxy& obj) {

	copy(obj);
}

Galaxy& Galaxy::operator=(const Galaxy& rhs) {

	if (this != &rhs) {
		copy(rhs);			
	}
	return *this;
}

std::istream& operator>>(std::istream& in, Galaxy& obj) {

	unsigned cnt;
	in >> cnt;
	while (cnt <= 0) {
		std::cout << "\nWrong input. Try again:";
		in >> cnt;
	}

	for (unsigned i = 0; i < cnt; ++i) {
		Planet curr;
		in >> curr;
		obj.m_planets.push_back(curr);
		//in >> obj.m_planets[i];
	}

	return in;
}

std::ostream& operator<<(std::ostream& out, const Galaxy& obj) {

	out << "\n**Information about the galaxy**\n";
	for (unsigned i = 0; i < obj.m_planets.size(); ++i) {
		out << obj.m_planets[i] << std::endl;
	}

	return out;
}

Galaxy operator+(Galaxy lhs, const Galaxy& rhs) {

	lhs += rhs;
	return lhs;
}

Galaxy operator+(Galaxy lhs, const Planet& rhs) {

	lhs += rhs;
	return lhs;
}

Galaxy operator-(Galaxy lhs, const Planet& rhs) {

	lhs -= rhs;
	return lhs;
}

Galaxy& Galaxy::operator+=(const Planet& rhs) {

	m_planets += rhs;
	//m_planets.push_back(rhs);
	return *this;
}

Galaxy& Galaxy::operator+=(const Galaxy& rhs) {

	for (unsigned i = 0; i < rhs.m_planets.size(); ++i) {
		m_planets += rhs.m_planets[i];
		//m_planets.push_back(rhs.m_planets[i]);
	}
	return *this;
}

Galaxy& Galaxy::operator-=(const Planet& rhs) {

	for (unsigned i = 0; i < m_planets.size(); ++i) {

		if (m_planets[i] == rhs) {
			m_planets.erase(i);
			return *this;
		}
	}
	return *this;
}

Planet& Galaxy::operator[](const unsigned& index) {

	return at(index);
}

const Planet& Galaxy::operator[](const unsigned& index)const {

	return at(index);
}

Planet& Galaxy::at(const unsigned& index) {

	if (index < 0 || index > m_planets.size()) {
		throw std::out_of_range("Invalid index!");
	}
	return m_planets[index];
}

const Planet& Galaxy::at(const unsigned& index)const {

	if (index < 0 || index > m_planets.size()) {
		throw std::out_of_range("Invalid index!");
	}
	return m_planets[index];
}

Base* Galaxy::clone()const {

	return new Galaxy(*this);
}

void Galaxy::write_to_file(std::ofstream& fout)const {

	fout << "\nInformation about galaxy**\n";
	for (unsigned i = 0; i < m_planets.size(); ++i) {
		m_planets[i].write_to_file(fout);
		fout << '\n';
	}
}

void Galaxy::read_from_file(std::ifstream& fin) {

	unsigned cnt;
	fin >> cnt;
	while (cnt <= 0) {
		fin >> cnt;
	}

	for (unsigned i = 0; i < cnt; ++i) {
		m_planets[i].read_from_file(fin);
	}
}

String Galaxy::type_name()const {

	return "galaxy";
}

void Galaxy::create_jedi(const String& planet_name, const String& jedi_name, const Rank& jedi_rank, const unsigned& jedi_age, const String& saber_color, const double& jedi_strength) {

	for (unsigned i = 0; i < m_planets.size(); ++i) {

		if (m_planets[i].get_planet_name() == planet_name) {
			for (unsigned j = 0; j < m_planets[i].get_count_jedi(); ++j) {

				if (m_planets[i].get_jedi(j).get_name_jedi() == jedi_name) {
					std::cout << "\nAlready exist Jedi with this name on the given planet.\n";
					return;
				}
			}

			m_planets[i].create_jedi(planet_name, jedi_name, jedi_rank, jedi_age, saber_color, jedi_strength);
			std::cout << "\nSuccessfully added jedi on planet " << planet_name << std::endl;
			return;
		}

		for (unsigned j = 0; j < m_planets[i].get_count_jedi(); ++j) {

			if (m_planets[i].get_jedi(j).get_name_jedi() == jedi_name) {
				std::cout << "\nAlready exist Jedi with this name on another planet.\n";
				return;
			}
		}
	}
}

void Galaxy::remove_jedi(const String& jedi_name, const String& planet_name) {

	for (unsigned i = 0; i < m_planets.size(); ++i) {

		if (m_planets[i].get_planet_name() == planet_name) {
			for (unsigned j = 0; j < m_planets[i].get_count_jedi(); ++j) {

				if (jedi_name == m_planets[i].get_jedi(j).get_name_jedi()) {
					m_planets[i].remove_jedi(jedi_name, planet_name);
					std::cout << "\nSuccessfully removed jedi.\n";
					return;
				}
			}
		}
	}

	std::cout << "\nNot successfully removed jedi.\n";
}

Jedi Galaxy::get_strongest_jedi(const String& planet_name)const {

	for (unsigned i = 0; i < m_planets.size(); ++i) {

		if (m_planets[i].get_planet_name() == planet_name) {
			return m_planets[i].get_strongest_jedi(planet_name);
		}
	}

	throw "Not founded information about jedi in the given planet.";
}

Vector<Jedi> Galaxy::get_youngest_jedi(const String& planet_name, const Rank& jedi_rank)const {

	for (unsigned i = 0; i < m_planets.size(); ++i) {

		if (m_planets[i].get_planet_name() == planet_name) {
			return m_planets[i].get_youngest_jedi(planet_name, jedi_rank);
		}
	}

	throw "Not founded jedi with the given rank on the given planet.";
}

String Galaxy::get_most_used_saber_color(const String& planet_name, const Rank& jedi_rank)const {

	for (unsigned i = 0; i < m_planets.size(); ++i) {

		if (m_planets[i].get_planet_name() == planet_name.get_string()) {
			return m_planets[i].get_most_used_saber_color(planet_name, jedi_rank);
		}
	}

	throw "Not founded jedi with the given rank on the given planet.";
}

String Galaxy::get_most_used_saber_color(const String& planet_name)const {

	for (unsigned i = 0; i < m_planets.size(); ++i) {

		if (m_planets[i].get_planet_name() == planet_name.get_string()) {
			return m_planets[i].get_most_used_saber_color(planet_name);
		}
	}

	throw "Not founded information about this planet.";
}

void Galaxy::print_planet(const String& planet_name) {

	for (unsigned i = 0; i < m_planets.size(); ++i) {

		if (m_planets[i].get_planet_name() == planet_name) {
			m_planets[i].print_planet(planet_name);
			break;
		}
	}
}

void Galaxy::print_jedi(const String& jedi_name)const {

	for (unsigned i = 0; i < m_planets.size(); ++i) {
		m_planets[i].print_jedi(jedi_name);
	}
}

void Galaxy::promote_jedi(const String& jedi_name, const double& multiplier) {

	for (unsigned i = 0; i < m_planets.size(); ++i) {

		for (unsigned j = 0; j < m_planets[i].get_count_jedi(); ++j) {
			if (at(i).get_jedi().at(j).get_name_jedi() == jedi_name) {

				m_planets[i].promote_jedi(jedi_name, multiplier);
			}
		}	
	}
}

void Galaxy::demote_jedi(const String& jedi_name, const double& multiplier) {

	for (unsigned i = 0; i < m_planets.size(); ++i) {

		for (unsigned j = 0; j < m_planets[i].get_count_jedi(); ++j) {
			if (at(i).get_jedi().at(j).get_name_jedi() == jedi_name) {

				m_planets[i].demote_jedi(jedi_name, multiplier);
			}
		}
	}
}

void Galaxy::add_planet(const Planet& planet) {

	m_planets.push_back(planet);
}

unsigned Galaxy::get_count_planet()const {

	return m_planets.size();
}

String Galaxy::get_planet_name(const unsigned& index)const {

	if (index < 0 || index > m_planets.size()) {
		throw std::out_of_range("Invalid index!");
	}
	return m_planets[index].get_planet_name();
}

void Galaxy::operator_plus(const String& lhs_planet, const String& rhs_planet) {

	for (unsigned i = 0; i < m_planets.size(); ++i) {

		if (lhs_planet == m_planets[i].get_planet_name()) {
			for (unsigned j = 0; j < m_planets.size(); ++j) {

				if (rhs_planet == m_planets[j].get_planet_name()) {
					std::cout << (m_planets[i] + m_planets[j]) << std::endl;
				}
			}
		}
	}
}

void Galaxy::add_vec_jedi(const Vector<Jedi>& jedi, const String& planet_name) {

	for (unsigned i = 0; i < m_planets.size(); ++i) {

		if (planet_name == m_planets[i].get_planet_name()) {
			m_planets[i] += jedi;
			break;
		}
	}
}

void Galaxy::copy(const Galaxy& obj) {

	for (unsigned i = 0; i < obj.m_planets.size(); ++i) {
		m_planets[i].set_planet_name(obj.m_planets[i].get_planet_name());
		m_planets[i].set_jedi(obj.m_planets[i].get_jedi());
	}
}