#include "Jedi.h"

Jedi::Jedi(std::ifstream& fin) {

//	read_from_file(fin);
	m_name_jedi.loadString(fin);
	m_color_of_lightsaber.loadString(fin);
	fin >> m_age;
	fin >> m_force;

	m_rank = Rank::YOUNGLING;
	String rank;
	rank.loadString(fin);

	/*if (rank.str_cmp(rank.get_string(), "youngling") == 0 || rank.str_cmp(rank.get_string(), "YOUNGLING") == 0) {
		m_rank = Rank::YOUNGLING;
	} else*/
	if (rank.str_cmp(rank.get_string(), "initiate") == 0 || rank.str_cmp(rank.get_string(), "INITIATE") == 0) {
		m_rank = Rank::INITIATE;
	} else if (rank.str_cmp(rank.get_string(), "padawan") == 0 || rank.str_cmp(rank.get_string(), "PADAWAN") == 0) {
		m_rank = Rank::PADAWAN;
	} else if (rank.str_cmp(rank.get_string(), "knight aspirant") == 0 || rank.str_cmp(rank.get_string(), "KNIGHT ASPIRANT") == 0) {
		m_rank = Rank::KNIGHT_ASPIRANT;
	} else if (rank.str_cmp(rank.get_string(), "knight") == 0 || rank.str_cmp(rank.get_string(), "KNIGHT") == 0) {
		m_rank = Rank::KNIGHT;
	} else if (rank.str_cmp(rank.get_string(), "master") == 0 || rank.str_cmp(rank.get_string(), "MASTER") == 0) {
		m_rank = Rank::MASTER;
	} else if (rank.str_cmp(rank.get_string(), "battle master") == 0 || rank.str_cmp(rank.get_string(), "BATTLE MASTER") == 0) {
		m_rank = Rank::BATTLE_MASTER;
	} else if(rank.str_cmp(rank.get_string(), "grand master") == 0 || rank.str_cmp(rank.get_string(), "GRAND MASTER") == 0) {
		m_rank = Rank::GRAND_MASTER;
	}
}

Jedi::Jedi(unsigned age, double force, Rank rank, String name, String color_of_lightsaber)
 :m_rank(rank), m_name_jedi(name), m_color_of_lightsaber(color_of_lightsaber){

	if (age <= 0) {
		m_age = 1;
	} else {
		m_age = age;
	}

	if (m_force < 0) {
		m_force = 0.;
	} else {
		m_force = force;
	}
}

Jedi::Jedi(const Jedi& oth) {

	copy(oth);
}

Jedi& Jedi::operator=(const Jedi& rhs) {

	if (this != &rhs) {
		copy(rhs);
	}
	return *this;
}

String Jedi::get_class_name() {

	return "jedi";
}

bool Jedi::operator==(const Jedi& rhs)const {

	if (m_age != rhs.m_age) {
		return false;
	}
	return true;
}

bool Jedi::operator!=(const Jedi& rhs)const {

	return !(*this == rhs);
}

bool Jedi::operator<(const Jedi& rhs)const {

	if (m_age < rhs.m_age) {
		return true;
	}
	return false;
}

std::istream& operator>>(std::istream& in, Jedi& oth) {

	in >> oth.m_name_jedi;
	in >> oth.m_age;
	in >> oth.m_force;
	in >> oth.m_color_of_lightsaber;

	oth.m_rank = Rank::YOUNGLING;
	String buff;
	in >> buff;

	/*if (!buff.str_cmp(buff.get_string(), "youngling") || !buff.str_cmp(buff.get_string(), "YOUNGLING")) {
		oth.m_rank = Rank::YOUNGLING;
	} else */
	if (!buff.str_cmp(buff.get_string(), "initiate") || !buff.str_cmp(buff.get_string(), "INITIATE")) {
		oth.m_rank = Rank::INITIATE;
	} else if (!buff.str_cmp(buff.get_string(), "padawan") || !buff.str_cmp(buff.get_string(), "PADAWAN")) {
		oth.m_rank = Rank::PADAWAN;
	} else if (!buff.str_cmp(buff.get_string(), "knight aspirant") || !buff.str_cmp(buff.get_string(), "KNIGHT ASPIRANT")) {
		oth.m_rank = Rank::KNIGHT_ASPIRANT;
	} else if (!buff.str_cmp(buff.get_string(), "knight") || !buff.str_cmp(buff.get_string(), "KNIGHT")) {
		oth.m_rank = Rank::KNIGHT;
	} else if (!buff.str_cmp(buff.get_string(), "master") || !buff.str_cmp(buff.get_string(), "MASTER")) {
		oth.m_rank = Rank::MASTER;
	} else if (!buff.str_cmp(buff.get_string(), "battle master") || !buff.str_cmp(buff.get_string(), "BATTLE MASTER")) {
		oth.m_rank = Rank::BATTLE_MASTER;
	} else if (!buff.str_cmp(buff.get_string(), "grand master") || !buff.str_cmp(buff.get_string(), "GRAND MASTER")) {
		oth.m_rank = Rank::GRAND_MASTER;
	} 

	return in;
}

std::ostream& operator<<(std::ostream& out, const Jedi& oth) {

	out << "\nName of jedi: "        << oth.m_name_jedi;
	out << "\nAge: "                 << oth.m_age;
	out << "\nForce: "               << oth.m_force;
	out << "\nColor of lightsaber: " << oth.m_color_of_lightsaber;

	if (oth.m_rank == Rank::YOUNGLING) {
		out << "\nRank: YOUNGLING\n";
	} else if (oth.m_rank == Rank::INITIATE) {
		out << "\nRank: INITIATE\n";
	} else if (oth.m_rank == Rank::PADAWAN) {
		out << "\nRank: PADAWAN\n";
	} else if (oth.m_rank == Rank::KNIGHT_ASPIRANT) {
		out << "\nRank: KNIGHT ASPIRANT\n";
	} else if (oth.m_rank == Rank::KNIGHT) {
		out << "\nRank: KNIGHT\n";
	} else if (oth.m_rank == Rank::MASTER) {
		out << "\nRank: MASTER\n";
	} else if (oth.m_rank == Rank::BATTLE_MASTER) {
		out << "\nRank: BATTLE MASTER\n";
	} else if (oth.m_rank == Rank::GRAND_MASTER) {
		out << "\nRank: GRAND MASTER\n";
	}
	return out;
}

void Jedi::promote(double multiplier) {

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

void Jedi::demote(double multiplier) {

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

Jedi* Jedi::clone()const {

	return new Jedi(*this);
}

void Jedi::write_to_file(std::ofstream& fout)const {

	fout << "\nName of jedi: " << m_name_jedi;
	fout << "\nAge of jedi: "  << m_age;
	fout << "\nForce of jedi: " << m_force;
	fout << "\n Color of lightsaber of jedi: " << m_color_of_lightsaber;
	fout << "\nRank of jedi: ";
	if (m_rank == Rank::GRAND_MASTER) {
		fout << "GRAND MASTER\n";
	} else if (m_rank == Rank::INITIATE) {
		fout << "INITIATE\n";
	} else if (m_rank == Rank::PADAWAN) {
		fout << "PADAWAN\n";
	} else if (m_rank == Rank::KNIGHT_ASPIRANT) {
		fout << "KNIGHT_ASPIRANT\n";
	} else if (m_rank == Rank::KNIGHT) {
		fout << "KNIGHT\n";
	} else if (m_rank == Rank::MASTER) {
		fout << "MASTER\n";
	} else if (m_rank == Rank::BATTLE_MASTER) {
		fout << "BATTLE MASTER\n";
	} else if (m_rank == Rank::YOUNGLING) {
		fout << "YOUNGLING\n";
	}
}

void Jedi::read_from_file(std::ifstream& fin) {

	m_name_jedi.loadString(fin);
	m_color_of_lightsaber.loadString(fin);
	fin >> m_age;
	fin >> m_force;

	m_rank = Rank::YOUNGLING;
	String buff;
	buff.loadString(fin);

	/*if (buff.str_cmp(buff.get_string(), "youngling") == 0 || buff.str_cmp(buff.get_string(), "YOUNGLING") == 0) {
		m_rank = Rank::YOUNGLING;
	} else*/
	if (buff.str_cmp(buff.get_string(), "initiate") == 0 || buff.str_cmp(buff.get_string(), "INITIATE") == 0) {
		m_rank = Rank::INITIATE;
	} else if (buff.str_cmp(buff.get_string(), "padawan") == 0 || buff.str_cmp(buff.get_string(), "PADAWAN") == 0) {
		m_rank = Rank::PADAWAN;
	} else if (buff.str_cmp(buff.get_string(), "knight aspirant") == 0 || buff.str_cmp(buff.get_string(), "KNIGHT ASPIRANT") == 0) {
		m_rank = Rank::KNIGHT_ASPIRANT;
	} else if (buff.str_cmp(buff.get_string(), "knight") == 0 || buff.str_cmp(buff.get_string(), "KNIGHT") == 0) {
		m_rank = Rank::KNIGHT;
	} else if (buff.str_cmp(buff.get_string(), "master") == 0 || buff.str_cmp(buff.get_string(), "MASTER") == 0) {
		m_rank = Rank::MASTER;
	} else if (buff.str_cmp(buff.get_string(), "battle master") == 0 || buff.str_cmp(buff.get_string(), "BATTLE MASTER") == 0) {
		m_rank = Rank::BATTLE_MASTER;
	} else if (buff.str_cmp(buff.get_string(), "grand master") == 0 || buff.str_cmp(buff.get_string(), "GRAND MASTER") == 0) {
		m_rank = Rank::GRAND_MASTER;
	} 
}

void Jedi::print()const {

	std::cout << *this;
}

unsigned Jedi::rank_num()const {

	unsigned num = 1;
    if (m_rank == Rank::INITIATE) {
	   num = 2;
	} else if (m_rank == Rank::PADAWAN) {
	   num = 3;
	} else if (m_rank == Rank::KNIGHT_ASPIRANT) {
	   num = 4;
	} else if (m_rank == Rank::KNIGHT) {
		num = 5;
	} else if (m_rank == Rank::MASTER) {
		num = 6;
	} else if (m_rank == Rank::BATTLE_MASTER) {
		num = 7;
	} else if (m_rank == Rank::GRAND_MASTER) {
		num = 8; 
	}
   return num;
}

void Jedi::copy(const Jedi& rhs) {

	set_age(rhs.m_age);
	set_force(rhs.m_force);
	m_rank                = rhs.m_rank;
	m_name_jedi           = rhs.m_name_jedi;
	m_color_of_lightsaber = rhs.m_color_of_lightsaber;
}

void Jedi::set_age(const unsigned& age) {

	if (age <= 0) {
		m_age = 1;
	} else {
		m_age = age;
	}
}

void Jedi::set_force(const double& force) {

	if (force < 0) {
		m_force = 0.;
	} else {
		m_force = force;
	}
}

void Jedi::set_name_jedi(const String& name) {

	m_name_jedi = name;
}

void Jedi::set_color_of_lightsaber(const String& color_of_lightsaber) {

	m_color_of_lightsaber = color_of_lightsaber;
}

void Jedi::set_rank(const Rank& rank) {

	m_rank = rank;
}

unsigned Jedi::get_age()const {

	return m_age;
}

double Jedi::get_force()const {

	return m_force;
}

String Jedi::get_name_jedi()const {

	return m_name_jedi;
}

String Jedi::get_color_of_lightsaber()const {

	return m_color_of_lightsaber;
}

Rank Jedi::get_rank()const {

	return m_rank;
}