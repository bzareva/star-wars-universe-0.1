#include "cstring_namespace.h"
#include "Planet.h"

Planet::Planet() 
: m_capacity(DEFAULT_CAPACITY), m_count_jedi(1) {


	m_jedi = new Jedi[m_capacity];
	m_jedi[0] = Jedi(45, 3.44, Rank::YOUNGLING, "John", "blue");

	m_planet_name = new char[1];
	m_planet_name[0] = '\0';
}

Planet::Planet(std::ifstream& fin) {

	unsigned len = 0;
	fin.read((char*)&len, sizeof(len));
	++len; // +1 for '\0'

	m_planet_name = new char[len];
	--len;
	fin.read(m_planet_name, len);
	m_planet_name[len] = '\0';

	fin.read((char*)&m_capacity, sizeof(m_capacity));
	fin.read((char*)&m_count_jedi, sizeof(m_count_jedi));

	if (m_capacity <= 0) {
		m_capacity = DEFAULT_CAPACITY;
	}
	if (m_capacity < m_count_jedi) {
		int temp     = m_count_jedi;
		m_count_jedi = m_capacity;
		m_capacity   = temp;
	}

	m_jedi = new Jedi[m_capacity];
	for (int i = 0; i < m_count_jedi && i < m_capacity; ++i) {
		m_jedi[i] = Jedi(fin);
	}
}

Planet::Planet(int cap, int count, Jedi* jedi, const char* planet_name) {

	if (cap <= 0) {
		m_capacity = DEFAULT_CAPACITY;
	}

	if (cap < count) {
		m_capacity   = count;
		m_count_jedi = cap;
	} else {
		m_capacity   = cap;
		m_count_jedi = count;
	}

	m_jedi = new Jedi[m_capacity];
	for (int i = 0; i < m_count_jedi && i < m_capacity; ++i) {
		m_jedi[i] = jedi[i];
	}

	unsigned len  = cstring_namespace::strLen(planet_name) + 1;
	m_planet_name = new char[len];
	cstring_namespace::strCpy(m_planet_name, planet_name);
}

Planet::Planet(const Planet& oth) {

	cpy(oth);
}

Planet& Planet::operator=(const Planet& rhs) {

	if (this != &rhs) {
		clean();
		cpy(rhs);
	}
	return *this;
}

Planet:: ~Planet() {

	clean();
}

void Planet::promote_jedi(const char* jedi_name, double multiplier) {

	bool flag = false;
	for (int i = 0; i < m_count_jedi; ++i) {
		if (cstring_namespace::strCmp(jedi_name, m_jedi[i].get_name_jedi ()) == 0) {
			m_jedi[i].promote_jedi(multiplier);
			flag = true;
		}
	}
	if (flag) {
		std::cout << "\nSuccessful promote " << jedi_name << " on planet " << m_planet_name << std::endl;
	} else {
		std::cout << "\nNot successful promote " << jedi_name << " on planet " << m_planet_name << std::endl;
	}
}

void Planet::demote_jedi(const char* jedi_name, double multiplier) {

	bool flag = false;
	for (int i = 0; i < m_count_jedi; ++i) {
		if (cstring_namespace::strCmp(jedi_name, m_jedi[i].get_name_jedi()) == 0) {
			m_jedi[i].demote_jedi(multiplier);
			flag = true;
//			std::cout << "\nSuccessful demote " << jedi_name << " on planet " << m_planet_name << std::endl;
//      	return;
		}
	}
	if (flag) {
		std::cout << "\nSuccessful demote " << jedi_name << " on planet " << m_planet_name << std::endl;
	} else {
		std::cout << "\nNot successful demote " << jedi_name << " on planet " << m_planet_name << std::endl;
	}
//	std::cout << "\nSuccessful demote " << jedi_name << " on planet " << m_planet_name << std::endl;
}

bool Planet::remove_jedi(const char* jedi_name) {

	for (int i = 0; i < m_count_jedi; ++i) {
		if (cstring_namespace::strCmp(jedi_name, m_jedi[i].get_name_jedi()) == 0) {
			erase_jedi(i);
			return true;
		}
	}
	return false;
}

void Planet::get_strongest_jedi_to_file(std::ofstream& fout)const {

	int ind = 0;
	int max = m_jedi[ind].get_force();
	for (int i = 1; i < m_count_jedi; ++i) {
		if (m_jedi[i].get_force() > max) {
			ind = i;
			max = m_jedi[i].get_force();
		}
	}
	m_jedi[ind].print_to_file(fout);
}

void Planet::get_strongest_jedi_to_console(std::ostream& out)const {

	int ind = 0;
	int max = m_jedi[ind].get_force();
	for (int i = 1; i < m_count_jedi; ++i) {
		if (m_jedi[i].get_force() > max) {
			ind = i;
			max = m_jedi[i].get_force();
		}
	}
	m_jedi[ind].print(out);
}

void Planet::get_youngest_jedi_to_file(const Rank& jedi_rank, std::ofstream& fout)const {

	bool flag = false;
	int curr  = m_jedi[0].get_age();
	for (int i = 1; i < m_count_jedi; ++i) {
		if (m_jedi[i].get_rank() == jedi_rank && m_jedi[i].get_age() < curr) {
			curr = m_jedi[i].get_age();
			flag = true;
			m_jedi[i].print_to_file(fout);
		}
	}

	if (!flag) {
		std::cout << "\nHave not founded jedi with this description!\n";
	}
}

void Planet::get_youngest_jedi_to_console(const Rank& jedi_rank, std::ostream& out)const {

	bool flag = false;
	int curr = m_jedi[0].get_age();
	for (int i = 1; i < m_count_jedi; ++i) {
		if (m_jedi[i].get_rank() == jedi_rank && m_jedi[i].get_age() < curr) {
			curr = m_jedi[i].get_age();
			flag = true;
			m_jedi[i].print(out);
		}
	}

	if (!flag) {
		std::cout << "\nHave not founded jedi with this description!\n";
	}
}

void Planet::print_planet_info_to_file(const char* jedi_name, std::ofstream& fout)const {


}

void Planet::print_planet_info_to_console(const char* jedi_name, std::ostream& out)const {

}

const char* Planet::get_most_used_saber_color()const {

}

void Planet::sort_jedi() {

}

const char* Planet::get_class_name() {

}

std::istream& operator>>(std::istream& in, Planet& oth) {

}

std::ostream& operator<<(std::ostream& out, const Planet& oth) {

}

Jedi& Planet::operator[](int ind) {

}

const Jedi& Planet::operator[](int ind)const {

}

Jedi& Planet::at(int ind) {

}

const Jedi& Planet::at(int ind)const {

}

void Planet::push_back(const Jedi& oth) {

}

void Planet::reserve(int cap) {

}

void Planet::erase_jedi(int ind) {

}

Base* Planet::clone()const {

 }

void Planet::print(std::ostream& out)const {
}

void Planet::print_to_file(std::ofstream& fout)const {


}

void Planet::create_jedi(const char* planet_name, const char* jedi_name, const char* jedi_rank, int jedi_age, const char* saber_color, double jedi_strength) {

}

void Planet::read(std::istream& in) {
}

void Planet::read_from_file(std::ifstream& fin) {

}

bool Planet::is_valid_type(const char* type)const {

}
 
const char* Planet::type_name()const {
}

void Planet::cpy(const Planet& oth) {

}

void Planet::clean() {

}

int Planet::get_count_jedi()const {

	return m_count_jedi;
}

int Planet::get_capacity()const {

	return m_capacity;
}

const char* Planet::get_planet_name()const {

	return m_planet_name;
}

Jedi Planet::get_jedi_by_index(int ind)const {

	if (ind <0 || ind > m_count_jedi) {
		throw std::logic_error("This index is not correct!");
	}

	return m_jedi[ind];
}

Jedi* Planet::get_jedi()const {

	return m_jedi;
}