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

void Planet::print_jedi_on_planet_info_to_file(const char* jedi_name, std::ofstream& fout)const {

	fout << "\n>Iformation about jedi<\n";
	for (int i = 0; i < m_count_jedi; ++i) {
		if (cstring_namespace::strCmp(jedi_name, m_jedi[i].get_name_jedi()) == 0) {

			m_jedi[i].print_to_file(fout);

			fout << "\n>Name of planet: ";
			unsigned len = cstring_namespace::strLen(m_planet_name);
			fout.write((const char*)&m_planet_name, len);
			return;
		}
	}
}

void Planet::print_jedi_on_planet_info_to_console(const char* jedi_name, std::ostream& out)const {

	out << "\n>Iformation about jedi<\n";
	for (int i = 0; i < m_count_jedi; ++i) {
		if (cstring_namespace::strCmp(jedi_name, m_jedi[i].get_name_jedi()) == 0) {

			m_jedi[i].print(out);
			out << "\n>Name of planet: " << m_planet_name << std::endl;
			return;
		}
	}
}

const char* Planet::get_most_used_saber_color()const {

	return get_most_used_saber_color(Rank::GRAND_MASTER);
}

const char* Planet::get_most_used_saber_color(const Rank& rank)const {

	//TODO::
	for (int i = 0; i < m_count_jedi; ++i) {

		if (m_jedi[i].get_rank() == rank) {


		}

	}

}

void Planet::sort_by_rank() {

	for (int i = 0; i < m_count_jedi - 1; ++i) {

		int ind   = i;
		Rank curr = m_jedi[i].get_rank();
		for (int j = i + 1; j < m_count_jedi; ++j) {

			if (m_jedi[j].get_rank() < curr) {
				ind  = j;
				curr = m_jedi[j].get_rank();
			}
		}
		if (ind != i) {
			Jedi temp   = m_jedi[i];
			m_jedi[i]   = m_jedi[ind];
			m_jedi[ind] = temp;

		}
	}
}

const char* Planet::get_class_name() {

	return "planet";
}

std::istream& operator>>(std::istream& in, Planet& oth) {

	char buff[1024] = { '\0' };
	in.getline(buff, 1024, '\n');

	unsigned len = cstring_namespace::strLen(buff) + 1;
	oth.m_planet_name = new char[len];
	cstring_namespace::strCpy(oth.m_planet_name, buff);

	in >> oth.m_capacity;
	in >> oth.m_count_jedi;
	if (oth.m_capacity <= 0 || (oth.m_capacity < oth.m_count_jedi && oth.m_count_jedi < DEFAULT_CAPACITY)) {
		oth.m_capacity = DEFAULT_CAPACITY;
	}

	oth.m_jedi = new Jedi[oth.m_capacity];
	for (int i = 0; i < oth.m_count_jedi && i < oth.m_capacity; ++i) {
		in >> oth.m_jedi[i];
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const Planet& oth) {

	out << "\nName of planet: " << oth.m_planet_name;
	out << "\nCount of living jedi on this planet: " << oth.m_count_jedi;

	for (int i = 0; i < oth.m_count_jedi && i < oth.m_capacity; ++i) {
		out << oth.m_jedi[i];
	}
	return out;
}

Jedi& Planet::operator[](int ind) {

	return at(ind);
}

const Jedi& Planet::operator[](int ind)const {

	return at(ind);
}

Jedi& Planet::at(int ind) {

	if (ind < 0 || ind > m_count_jedi) {
		throw std::out_of_range("This index is not correct!");
	}
	return m_jedi[ind];
}

const Jedi& Planet::at(int ind)const {

	if (ind < 0 || ind > m_count_jedi) {
		throw std::out_of_range("This index is not correct!");
	}
	return m_jedi[ind];
}

void Planet::push_back(const Jedi& oth) {

	if (m_count_jedi + 1 >= m_capacity) {
		reserve(2 * m_count_jedi);
	}

	m_jedi[m_count_jedi] = oth;
	++m_count_jedi;
}

void Planet::reserve(int cap) {

	if (cap <= m_capacity || cap <= 0) {
		return;
	}

	m_capacity = cap;
    Jedi* curr = new Jedi[m_capacity];
	for (int i = 0; i < m_count_jedi && i < m_capacity; ++i) {
		curr[i] = m_jedi[i];
	}

	delete[]m_jedi;
	m_jedi = curr;
}

void Planet::erase_jedi(int ind) {

	if (ind < 0 || ind > m_count_jedi) {
		throw std::out_of_range("This index is not correct!");
	}

	for (int i = ind; i < m_count_jedi - 1; ++i) {
		m_jedi[i] = m_jedi[i + 1];
	}

	--m_count_jedi;
}

Base* Planet::clone()const {

	return new Planet(*this);
 }

void Planet::print(std::ostream& out)const {

	out << (*this);
}

void Planet::print_to_file(std::ofstream& fout)const {

	fout << "\n>Name of planet: ";
	unsigned len = cstring_namespace::strLen(m_planet_name);
    fout.write((const char*)&m_planet_name, len);

	fout << "\n>Iformation about jedi<\n";
	for (int i = 0; i < m_count_jedi; ++i) {
			m_jedi[i].print_to_file(fout);	
	}
}

void Planet::create_jedi(const char* planet_name, const char* jedi_name, const char* jedi_rank, int jedi_age, const char* saber_color, double jedi_strength) {

	for (int i = 0; i < m_count_jedi; ++i) {
		if (cstring_namespace::strCmp(jedi_name, m_jedi[i].get_name_jedi()) == 0) {
			std::cout << "\nAlready exists jedi with name like this!\n";
			return;
		}
		if (cstring_namespace::strCmp(planet_name, m_planet_name) == 0) {
			std::cout << "\nNot exist planet with this name!\n";
			return;
		}
	}

	if (m_count_jedi + 1 > m_capacity) {
		reserve(2 * m_count_jedi);
	}

	Jedi curr;
	curr.create_jedi(planet_name, jedi_name, jedi_rank, jedi_age, saber_color, jedi_strength);
	push_back(curr);

	std::cout << "\nSuccessful added jedi!\n";
}

void Planet::read(std::istream& in) {

	in >> (*this);
}

void Planet::read_from_file(std::ifstream& fin) {

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
		int temp = m_count_jedi;
		m_count_jedi = m_capacity;
		m_capacity = temp;
	}

	m_jedi = new Jedi[m_capacity];
	for (int i = 0; i < m_count_jedi && i < m_capacity; ++i) {
		m_jedi[i] = Jedi(fin);
	}
}

bool Planet::is_valid_type(const char* type)const {

	if (cstring_namespace::strCmp(type, "planet") == 0 || cstring_namespace::strCmp(type, "PLANET") == 0) {
		return true;
	}
	return false;
}
 
const char* Planet::type_name()const {

	return "planet";
}

void Planet::cpy(const Planet& oth) {

	m_capacity   = oth.m_capacity;
	m_count_jedi = oth.m_count_jedi;

	m_jedi = new Jedi[m_capacity];
	for (int i = 0; i < m_count_jedi && i < m_capacity; ++i) {
		m_jedi[i] = oth.m_jedi[i];
	}

	unsigned len  = cstring_namespace::strLen(oth.m_planet_name) + 1;
	m_planet_name = new char[len];
	cstring_namespace::strCpy(m_planet_name, oth.m_planet_name);
}

void Planet::clean() {

	delete[]m_jedi;
	m_jedi = nullptr;

	delete[]m_planet_name;
	m_planet_name = nullptr;
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