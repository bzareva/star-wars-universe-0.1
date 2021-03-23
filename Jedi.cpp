#include "Jedi.h"
#include "cstring_namespace.h"

Jedi::Jedi() 
: m_age(0), m_force(1.0) {

	m_name_jedi    = new char[1];
	m_name_jedi[0] = '\0';

	m_color_of_lightsaber    = new char[1];
	m_color_of_lightsaber[0] = '\0';

	m_rank = Rank::MASTER;
}

Jedi::Jedi(std::ifstream& fin) {

	unsigned len1 = 0;
	fin.read((char*)&len1, sizeof(len1));
	++len1; // +1 because '\0'

	m_name_jedi = new char[len1];
	--len1; 
	fin.read(m_name_jedi, len1); // len1 * sizeof(char) -> len1
	m_name_jedi[len1] = '\0';

	fin.read((char*)&m_age, sizeof(m_age));
	fin.read((char*)&m_force, sizeof(m_force));

	unsigned len2 = 0;
	fin.read((char*)&len2, sizeof(len2));
	++len2; // +1 because '\0'

	m_color_of_lightsaber = new char[len2];
	--len2;
	fin.read((char*)&m_color_of_lightsaber, len2);
	m_color_of_lightsaber[len2] = '\0';

	unsigned len3 = 0;
	fin.read((char*)&len3, sizeof(len3));
	++len3;// +1 because '\0'

	char* buff = new char[len3];
	--len3;
	fin.read((char*)&buff, len3);

	if (!cstring_namespace::strCmp(buff, "youngling") || !cstring_namespace::strCmp(buff, "YOUNGLING")) {
		m_rank = Rank::YOUNGLING;
	} else if (!cstring_namespace::strCmp(buff, "initiate") || !cstring_namespace::strCmp(buff, "INITIATE")) {
		m_rank = Rank::INITIATE;
	} else if (!cstring_namespace::strCmp(buff, "padawan") || !cstring_namespace::strCmp(buff, "PADAWAN")) {
		m_rank = Rank::PADAWAN;
	} else if (!cstring_namespace::strCmp(buff, "knight aspirant") || !cstring_namespace::strCmp(buff, "KNIGHT ASPIRANT")) {
		m_rank = Rank::KNIGHT_ASPIRANT;
	} else if (!cstring_namespace::strCmp(buff, "knight") || !cstring_namespace::strCmp(buff, "KNIGHT")) {
		m_rank = Rank::KNIGHT;
	} else if (!cstring_namespace::strCmp(buff, "master") || !cstring_namespace::strCmp(buff, "MASTER")) {
		m_rank = Rank::MASTER;
	} else if (!cstring_namespace::strCmp(buff, "battle master") || !cstring_namespace::strCmp(buff, "BATTLE MASTER")) {
		m_rank = Rank::BATTLE_MASTER;
	} else if(!cstring_namespace::strCmp(buff, "grand master") || !cstring_namespace::strCmp(buff, "GRAND MASTER")) {
		m_rank = Rank::GRAND_MASTER;
	} else {
		m_rank = Rank::YOUNGLING;
	}
}

Jedi::Jedi(int age, double force, const Rank& rank, const char* name, const char* color_of_lightsaber) {

	if (age < 0) {
		m_age = 0;
	} else {
		m_age = age;
	}

	if (m_force < 0) {
		m_force = 0;
	} else {
		m_force = force;
	}

	m_rank = rank;

	unsigned len1 = cstring_namespace::strLen(name) + 1;
	m_name_jedi   = new char[len1];
	cstring_namespace::strCpy(m_name_jedi, name);

	unsigned len2         = cstring_namespace::strLen(color_of_lightsaber) + 1;
	m_color_of_lightsaber = new char[len2];
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

const char* Jedi::get_class_name() {

	return "jedi";
}

bool Jedi::operator==(const Jedi& rhs)const {

	if (m_age != rhs.m_age) {
		return false;
	}
	return true;
}

bool Jedi::operator<(const Jedi& rhs)const {

	if (m_age < rhs.m_age) {
		return true;
	}
	return false;
}

std::istream& operator>>(std::istream& in, Jedi& oth) {

	char buff1[1024] = { '\0' };
	in.getline(buff1, 1024, '\n');
	oth.set_name_jedi(buff1);

	in >> oth.m_age;
	in >> oth.m_force;

	char buff2[1024] = { '\0' };
	in.getline(buff2, 1024, '\n');
	oth.set_color_of_lightsaber(buff2);

	char buff3[64] = { '\0' };
	in.getline(buff3, 64, '\n');

	if (!cstring_namespace::strCmp(buff3, "youngling") || !cstring_namespace::strCmp(buff3, "YOUNGLING")) {
		oth.m_rank = Rank::YOUNGLING;
	} else if (!cstring_namespace::strCmp(buff3, "initiate") || !cstring_namespace::strCmp(buff3, "INITIATE")) {
		oth.m_rank = Rank::INITIATE;
	} else if (!cstring_namespace::strCmp(buff3, "padawan") || !cstring_namespace::strCmp(buff3, "PADAWAN")) {
		oth.m_rank = Rank::PADAWAN;
	} else if (!cstring_namespace::strCmp(buff3, "knight aspirant") || !cstring_namespace::strCmp(buff3, "KNIGHT ASPIRANT")) {
		oth.m_rank = Rank::KNIGHT_ASPIRANT;
	} else if (!cstring_namespace::strCmp(buff3, "knight") || !cstring_namespace::strCmp(buff3, "KNIGHT")) {
		oth.m_rank = Rank::KNIGHT;
	} else if (!cstring_namespace::strCmp(buff3, "master") || !cstring_namespace::strCmp(buff3, "MASTER")) {
		oth.m_rank = Rank::MASTER;
	} else if (!cstring_namespace::strCmp(buff3, "battle master") || !cstring_namespace::strCmp(buff3, "BATTLE MASTER")) {
		oth.m_rank = Rank::BATTLE_MASTER;
	} else if (!cstring_namespace::strCmp(buff3, "grand master") || !cstring_namespace::strCmp(buff3, "GRAND MASTER")) {
		oth.m_rank = Rank::GRAND_MASTER;
	} else {
		oth.m_rank = Rank::YOUNGLING;
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const Jedi& oth) {

	out << "\n>Name of jedi: "        << oth.m_name_jedi;
	out << "\n>Age: "                 << oth.m_age;
	out << "\n>Force: "               << oth.m_force;
	out << "\n>Color of lightsaber: " << oth.m_color_of_lightsaber;

	if (oth.m_rank == Rank::YOUNGLING) {
		out << "\n>Rank: YOUNGLING\n";
	} else if (oth.m_rank == Rank::INITIATE) {
		out << "\n>Rank: INITIATE\n";
	} else if (oth.m_rank == Rank::PADAWAN) {
		out << "\n>Rank: PADAWAN\n";
	} else if (oth.m_rank == Rank::KNIGHT_ASPIRANT) {
		out << "\n>Rank: KNIGHT ASPIRANT\n";
	} else if (oth.m_rank == Rank::KNIGHT) {
		out << "\n>Rank: KNIGHT\n";
	} else if (oth.m_rank == Rank::MASTER) {
		out << "\n>Rank: MASTER\n";
	} else if (oth.m_rank == Rank::BATTLE_MASTER) {
		out << "\n>Rank: BATTLE MASTER\n";
	} else if (oth.m_rank == Rank::GRAND_MASTER) {
		out << "\n>Rank: GRAND MASTER\n";
	}
	return out;
}

void Jedi::promote_jedi(double multiplier) {

	if (multiplier > 0) {
		m_force += (multiplier * m_force);
	} else {
		throw std::logic_error("Multiplier must be positive number!");
	}
	
	if (m_rank == Rank::YOUNGLING) {
		m_rank = Rank::INITIATE;
	} else if (m_rank == Rank::INITIATE) {
		m_rank = Rank::PADAWAN;
	} else if (m_rank == Rank::PADAWAN) {
		m_rank = Rank::KNIGHT_ASPIRANT;
	} else if (m_rank == Rank::KNIGHT_ASPIRANT) {
		m_rank = Rank::KNIGHT;
	} else if (m_rank == Rank::KNIGHT) {
		m_rank = Rank::MASTER;
	} else if (m_rank == Rank::MASTER) {
		m_rank = Rank::BATTLE_MASTER;
	} else if (m_rank == Rank::BATTLE_MASTER) {
		m_rank = Rank::GRAND_MASTER;
	}
}

void Jedi::demote_jedi(double multiplier) {

	if (multiplier > 0) {
		m_force -= (multiplier * m_force);
	} else {
		throw std::logic_error("Multiplier must be positive number!");
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
	} else if (m_rank == Rank::BATTLE_MASTER) {
		m_rank = Rank::MASTER;
	}
}

Base* Jedi::clone()const {

	return new Jedi(*this);
}

void Jedi::print(std::ostream& out)const { 

//  second way
//	out << *this;

	out << "\n>Name of jedi: "        << m_name_jedi;
	out << "\n>Age: "                 << m_age;
	out << "\n>Force: "               << m_force;
	out << "\n>Color of lightsaber: " << m_color_of_lightsaber;

	if (m_rank == Rank::YOUNGLING) {
		out << "\n>Rank: YOUNGLING\n";
	} else if (m_rank == Rank::INITIATE) {
		out << "\n>Rank: INITIATE\n";
	} else if (m_rank == Rank::PADAWAN) {
		out << "\n>Rank: PADAWAN\n";
	} else if (m_rank == Rank::KNIGHT_ASPIRANT) {
		out << "\n>Rank: KNIGHT ASPIRANT\n";
	} else if (m_rank == Rank::KNIGHT) {
		out << "\n>Rank: KNIGHT\n";
	} else if (m_rank == Rank::MASTER) {
		out << "\n>Rank: MASTER\n";
	} else if (m_rank == Rank::BATTLE_MASTER) {
		out << "\n>Rank: BATTLE MASTER\n";
	} else if (m_rank == Rank::GRAND_MASTER) {
		out << "\n>Rank: GRAND MASTER\n";
	}
}

void Jedi::print_to_file(std::ofstream& fout)const {

	unsigned len1 = cstring_namespace::strLen(m_name_jedi) + 1;
	fout.write((const char*)&m_name_jedi, sizeof(len1));

	fout.write((const char*)&m_age, sizeof(m_age));

	fout.write((const char*)&m_rank, sizeof(m_rank));

	fout.write((const char*)&m_force, sizeof(m_force));

	unsigned len2 = cstring_namespace::strLen(m_color_of_lightsaber) + 1;
	fout.write((const char*)&m_color_of_lightsaber, sizeof(len2));
}

void Jedi::create_jedi(const char* planet_name, const char* jedi_name, const char* rank, int age, const char* color_of_lightsaber, double force) {

	set_age(age);
	set_force(force);

	set_name_jedi(jedi_name);
	set_color_of_lightsaber(color_of_lightsaber);

	if (!cstring_namespace::strCmp(rank, "youngling") || !cstring_namespace::strCmp(rank, "YOUNGLING")) {
		m_rank = Rank::YOUNGLING;
	} else if (!cstring_namespace::strCmp(rank, "initiate") || !cstring_namespace::strCmp(rank, "INITIATE")) {
		m_rank = Rank::INITIATE;
	} else if (!cstring_namespace::strCmp(rank, "padawan") || !cstring_namespace::strCmp(rank, "PADAWAN")) {
		m_rank = Rank::PADAWAN;
	} else if (!cstring_namespace::strCmp(rank, "knight aspirant") || !cstring_namespace::strCmp(rank, "KNIGHT ASPIRANT")) {
		m_rank = Rank::KNIGHT_ASPIRANT;
	} else if (!cstring_namespace::strCmp(rank, "knight") || !cstring_namespace::strCmp(rank, "KNIGHT")) {
		m_rank = Rank::KNIGHT;
	} else if (!cstring_namespace::strCmp(rank, "master") || !cstring_namespace::strCmp(rank, "MASTER")) {
		m_rank = Rank::MASTER;
	} else if (!cstring_namespace::strCmp(rank, "battle master") || !cstring_namespace::strCmp(rank, "BATTLE MASTER")) {
		m_rank = Rank::BATTLE_MASTER;
	} else if (!cstring_namespace::strCmp(rank, "grand master") || !cstring_namespace::strCmp(rank, "GRAND MASTER")) {
		m_rank = Rank::GRAND_MASTER;
	}
}

void Jedi::read(std::istream& in) {

//	in >> *this;

	char buff1[1024] = { '\0' };
	in.getline(buff1, 1024, '\n');
	set_name_jedi(buff1);

	in >> m_age;
	in >> m_force;

	char buff2[1024] = { '\0' };
	in.getline(buff2, 1024, '\n');
	set_color_of_lightsaber(buff2);

	char buff3[64] = { '\0' };
	in.getline(buff3, 64, '\n');

	if (!cstring_namespace::strCmp(buff3, "youngling") || !cstring_namespace::strCmp(buff3, "YOUNGLING")) {
		m_rank = Rank::YOUNGLING;
	} else if (!cstring_namespace::strCmp(buff3, "initiate") || !cstring_namespace::strCmp(buff3, "INITIATE")) {
		m_rank = Rank::INITIATE;
	} else if (!cstring_namespace::strCmp(buff3, "padawan") || !cstring_namespace::strCmp(buff3, "PADAWAN")) {
		m_rank = Rank::PADAWAN;
	} else if (!cstring_namespace::strCmp(buff3, "knight aspirant") || !cstring_namespace::strCmp(buff3, "KNIGHT ASPIRANT")) {
		m_rank = Rank::KNIGHT_ASPIRANT;
	} else if (!cstring_namespace::strCmp(buff3, "knight") || !cstring_namespace::strCmp(buff3, "KNIGHT")) {
		m_rank = Rank::KNIGHT;
	} else if (!cstring_namespace::strCmp(buff3, "master") || !cstring_namespace::strCmp(buff3, "MASTER")) {
		m_rank = Rank::MASTER;
	} else if (!cstring_namespace::strCmp(buff3, "battle master") || !cstring_namespace::strCmp(buff3, "BATTLE MASTER")) {
		m_rank = Rank::BATTLE_MASTER;
	} else if (!cstring_namespace::strCmp(buff3, "grand master") || !cstring_namespace::strCmp(buff3, "GRAND MASTER")) {
		m_rank = Rank::GRAND_MASTER;
	} else {
		m_rank = Rank::YOUNGLING;
	}
}

void Jedi::read_from_file(std::ifstream& fin) {

	unsigned len1 = 0;
	fin.read((char*)&len1, sizeof(len1));
	++len1; // +1 because '\0'

	m_name_jedi = new char[len1];
	--len1;
	fin.read(m_name_jedi, len1); // len1 * sizeof(char) -> len1
	m_name_jedi[len1] = '\0';

	fin.read((char*)&m_age, sizeof(m_age));
	fin.read((char*)&m_force, sizeof(m_force));

	unsigned len2 = 0;
	fin.read((char*)&len2, sizeof(len2));
	++len2; // +1 because '\0'

	m_color_of_lightsaber = new char[len2];
	--len2;
	fin.read((char*)&m_color_of_lightsaber, len2);
	m_color_of_lightsaber[len2] = '\0';

	unsigned len3 = 0;
	fin.read((char*)&len3, sizeof(len3));

	++len3;// +1 because '\0'
	char* buff = new char[len3];
	--len3;
	fin.read((char*)&buff, len3);

	if (!cstring_namespace::strCmp(buff, "youngling") || !cstring_namespace::strCmp(buff, "YOUNGLING")) {
		m_rank = Rank::YOUNGLING;
	} else if (!cstring_namespace::strCmp(buff, "initiate") || !cstring_namespace::strCmp(buff, "INITIATE")) {
		m_rank = Rank::INITIATE;
	} else if (!cstring_namespace::strCmp(buff, "padawan") || !cstring_namespace::strCmp(buff, "PADAWAN")) {
		m_rank = Rank::PADAWAN;
	} else if (!cstring_namespace::strCmp(buff, "knight aspirant") || !cstring_namespace::strCmp(buff, "KNIGHT ASPIRANT")) {
		m_rank = Rank::KNIGHT_ASPIRANT;
	} else if (!cstring_namespace::strCmp(buff, "knight") || !cstring_namespace::strCmp(buff, "KNIGHT")) {
		m_rank = Rank::KNIGHT;
	} else if (!cstring_namespace::strCmp(buff, "master") || !cstring_namespace::strCmp(buff, "MASTER")) {
		m_rank = Rank::MASTER;
	} else if (!cstring_namespace::strCmp(buff, "battle master") || !cstring_namespace::strCmp(buff, "BATTLE MASTER")) {
		m_rank = Rank::BATTLE_MASTER;
	} else if (!cstring_namespace::strCmp(buff, "grand master") || !cstring_namespace::strCmp(buff, "GRAND MASTER")) {
		m_rank = Rank::GRAND_MASTER;
	} else {
		m_rank = Rank::YOUNGLING;
	}
}

bool Jedi::is_valid_type(const char* type)const {

	if (!cstring_namespace::strCmp(type, "jedi") || !cstring_namespace::strCmp(type, "JEDI")) {
		return true;
	}
	return false;
}

const char* Jedi::type_name()const {

	return "jedi";
}

void Jedi::cpy(const Jedi& rhs) {

	set_age(rhs.m_age);
	set_force(rhs.m_force);
	m_rank = rhs.m_rank;
	set_name_jedi(rhs.m_name_jedi);
	set_color_of_lightsaber(rhs.m_color_of_lightsaber);
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
	unsigned len = cstring_namespace::strLen(name) + 1;
	m_name_jedi  = new char[len];
	cstring_namespace::strCpy(m_name_jedi, name);
}

void Jedi::set_color_of_lightsaber(const char* color_of_lightsaber) {

	if (m_color_of_lightsaber != nullptr) {
		delete[]m_color_of_lightsaber;
	}
	unsigned len          = cstring_namespace::strLen(color_of_lightsaber) + 1;
	m_color_of_lightsaber = new char[len];
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

Rank Jedi::get_rank()const {

	return m_rank;
}