#include <fstream>
#include <iostream>
#include "Jedi.h"
#include "cstring_namespace.h"

Jedi::Jedi() 
: m_age(0), m_force(1.0) {

	m_name_jedi = new char[1];
	m_name_jedi[0] = '\0';

	m_color_of_lightsaber = new char[1];
	m_color_of_lightsaber[0] = '\0';

	m_rank = Rank::MASTER;
}

Jedi::Jedi(std::ifstream& in) {

	in.read((char*)&m_age, sizeof(m_age));
	in.read((char*)&m_force, sizeof(m_force));

	int len1 = 0;
	in.read((char*)&len1, sizeof(int));

	if (m_name_jedi != nullptr) {
		delete[]m_name_jedi;
	}
	m_name_jedi = new char[len1 + 1];
	in.read(m_name_jedi, len1); //len1 * sizeof(char) -> len1
	m_name_jedi[len1] = '\0';

	int len2 = 0;
	in.read((char*)&len2, sizeof(int));

	if (m_color_of_lightsaber != nullptr) {
		delete[]m_color_of_lightsaber;
	}
	m_color_of_lightsaber = new char[len2 + 1];
	in.read((char*)&m_color_of_lightsaber, len2);
	m_color_of_lightsaber[len2] = '\0';

	int len3 = 0;
	in.read((char*)&len3, sizeof(int));

	char buff[64] = { '\0' };
	in.read((char*)&buff, sizeof(buff));
	if (!cstring_namespace::strCmp(buff, "youngling")) { 
		m_rank = Rank::YOUNGLING;
	} else if (!cstring_namespace::strCmp(buff, "initiate")) {
		m_rank = Rank::INITIATE;
	} else if (!cstring_namespace::strCmp(buff, "padawan")) { 
		m_rank = Rank::PADAWAN;
	} else if (!cstring_namespace::strCmp(buff, "knight aspirant")) { 
		m_rank = Rank::KNIGHT_ASPIRANT;
	} else if (!cstring_namespace::strCmp(buff, "knight")) { 
		m_rank = Rank::KNIGHT;
	} else if (!cstring_namespace::strCmp(buff, "master")) { 
		m_rank = Rank::MASTER;
	} else if (!cstring_namespace::strCmp(buff, "battle master")) {
		m_rank = Rank::BATTLE_MASTER;
	} else if(!cstring_namespace::strCmp(buff, "grand master")) { 
		m_rank = Rank::GRAND_MASTER;
	} else {
		m_rank = Rank::YOUNGLING;
	}
}

Jedi::Jedi(int age, double force, const Rank& rank, const char* name, const char* color_of_lightsaber) 
: m_force(force) {

	if (age < 0) {
		m_age = 0;
	} else {
		m_age = age;
	}

	m_rank = rank;

	m_name_jedi = new char[cstring_namespace::strLen(name) + 1];
	cstring_namespace::strCpy(m_name_jedi, name);

	m_color_of_lightsaber = new char[cstring_namespace::strLen(color_of_lightsaber) + 1];
	cstring_namespace::strCpy(m_color_of_lightsaber, color_of_lightsaber);
}

Jedi::Jedi(const Jedi& oth) {

	cpy(oth);
}

Jedi& Jedi::operator=(const Jedi& rhs) {

	if (this != &rhs) {
		clean();
		cpy(rhs);
	}
	return *this;
}

Jedi::~Jedi() {

	clean();
}

const char* Jedi::getClassName() {

	return "jedi";
}

bool Jedi::operator==(const Jedi& oth)const {

	if (m_age != oth.m_age) {
		return false;
	}
	return true;
}

bool Jedi::operator<(const Jedi& oth)const {

	if (m_age < oth.m_age) {
		return true;
	}
	return false;
}

bool Jedi::promote_jedi(double multiplier) {

	if (multiplier > 0) {
		m_force += (multiplier * m_force);
	} else {
		throw "out_of_range";
	}
	
	if (m_rank == Rank::YOUNGLING) {
		m_rank = Rank::INITIATE;
	} else if (m_rank  == Rank::INITIATE) {
		m_rank = Rank::PADAWAN;
	} else if (m_rank == Rank::PADAWAN) {
		m_rank = Rank::KNIGHT_ASPIRANT;
	} else if (m_rank == Rank::KNIGHT_ASPIRANT) {
		m_rank = Rank::KNIGHT;
	} else if (m_rank == Rank::KNIGHT) {
		m_rank = Rank::MASTER;
	} else if (m_rank == Rank::MASTER) {
		m_rank = Rank::BATTLE_MASTER;
	} else (m_rank == Rank::BATTLE_MASTER); {
		m_rank = Rank::GRAND_MASTER;
	}
}

bool Jedi::demote_jedi(double multiplier) {

	if (multiplier > 0) {
		m_force -= (multiplier * m_force);
	} else {
		throw "out_of_range";
	}
	
	if (m_rank == Rank::GRAND_MASTER) {
		m_rank = Rank::BATTLE_MASTER;
	} else if (m_rank == Rank::INITIATE) {
		m_rank = Rank::YOUNGLING;
	} else if (m_rank == Rank::PADAWAN) {
		m_rank = Rank::INITIATE;
	} else if (m_rank == Rank::KNIGHT_ASPIRANT) {
		m_rank = Rank::PADAWAN;
	} else if (m_rank == Rank::KNIGHT) {
		m_rank = Rank::KNIGHT_ASPIRANT;
	} else if (m_rank == Rank::MASTER) {
		m_rank = Rank::KNIGHT;
	} else (m_rank == Rank::BATTLE_MASTER); {
		m_rank = Rank::MASTER;
	}
}

Base* Jedi::clone()const {

	return new Jedi(*this);
}

void Jedi::print(std::ostream& out)const {

}

void Jedi::print_to_file(std::ofstream& ofs)const {

	//TODO::
}

void Jedi::read_from_console(std::istream& in) {

}

void Jedi::read_from_file(std::ifstream& ifs) {

	//TODO::
}

bool Jedi::is_valid_type(const char* str)const {

}

const char* Jedi::type_name()const {

	return "jedi";
}

void Jedi::cpy(const Jedi& rhs) {

	m_age = rhs.m_age;
	m_force = rhs.m_force;
	m_rank = rhs.m_rank;

	if (m_name_jedi != nullptr) {
		delete[] m_name_jedi;
	}
	m_name_jedi = new char[cstring_namespace::strLen(rhs.m_name_jedi) + 1];
	cstring_namespace::strCpy(m_name_jedi, rhs.m_name_jedi);

	if (m_color_of_lightsaber != nullptr) {
		delete[]m_color_of_lightsaber;
	}
	m_color_of_lightsaber = new char[cstring_namespace::strLen(rhs.m_color_of_lightsaber) + 1];
	cstring_namespace::strCpy(m_color_of_lightsaber, rhs.m_color_of_lightsaber);
}

void Jedi::clean() {

	delete[] m_name_jedi;
	m_name_jedi = nullptr;

	delete[] m_color_of_lightsaber;
	m_color_of_lightsaber = nullptr;
}

void Jedi::set_age(int age) {

	if (age < 0) {
		m_age = 0;
	} else {
		m_age = age;
	}
}

void Jedi::set_force(double force) {

	if (force < 0) {
		m_force = 0.;
	} else {
		m_force = force;
	}
}

void Jedi::set_name_jedi(const char* name) {

	if (m_name_jedi != nullptr) {
		delete[]m_name_jedi;
	}
	m_name_jedi = new char[cstring_namespace::strLen(name) + 1];
	cstring_namespace::strCpy(m_name_jedi, name);
}

void Jedi::set_color_of_lightsaber(const char* color_of_lightsaber) {

	if (m_color_of_lightsaber != nullptr) {
		delete[]m_color_of_lightsaber;
	}
	m_color_of_lightsaber = new char[cstring_namespace::strLen(color_of_lightsaber) + 1];
	cstring_namespace::strCpy(m_color_of_lightsaber, color_of_lightsaber);
}

void Jedi::set_rank(const Rank& rank) {

	m_rank = rank;
}

int Jedi::get_age()const {

	return m_age;
}

double Jedi::get_force()const {

	return m_force;
}

const char* Jedi::get_name_jedi()const {

	return m_name_jedi;
}

const char* Jedi::get_color_of_lightsaber()const {

	return m_color_of_lightsaber;
}

Jedi::Rank Jedi::get_rank()const {

	return m_rank;
}

//std::istream& operator>>(std::istream& in, Jedi& other) {

	// TODO::
//}

std::ostream& operator<<(std::ostream& out, const Jedi& other) {

	// TODO::
}