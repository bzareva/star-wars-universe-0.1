#include "Jedi.h"

Jedi::Jedi(std::ifstream& fin) {

	read_from_file(fin);
}

Jedi::Jedi(const unsigned& age, const double& force, const Rank& rank, const String& name, const String& color_of_lightsaber)
 :m_rank(rank), m_name_jedi(name), m_color_of_lightsaber(color_of_lightsaber) {

	if (age <= 0) {
		m_age = 1;

	} else {
		m_age = age;
	}

	if (force <= 0) {
		m_force = 10.;

	} else {
		m_force = force;
	}
}

Jedi::Jedi(const Jedi& rhs) {

	copy(rhs);
}

Jedi& Jedi::operator=(const Jedi& rhs) {

	if (this != &rhs) {
		copy(rhs);
	}
	return *this;
}

Jedi::Jedi(Jedi&& rhs)noexcept 
 :m_age(rhs.m_age), m_rank(rhs.m_rank), m_force(rhs.m_force), m_name_jedi(rhs.m_name_jedi), m_color_of_lightsaber(rhs.m_color_of_lightsaber) {

	rhs.to_zero();
}

Jedi& Jedi::operator=(Jedi&& rhs)noexcept {

	if (this != &rhs) {
		m_age                 = rhs.m_age;
		m_rank                = rhs.m_rank;
		m_force               = rhs.m_force;
		m_name_jedi           = rhs.m_name_jedi;
		m_color_of_lightsaber = rhs.m_color_of_lightsaber;

		rhs.to_zero();
	}
	return *this;
}

bool Jedi::operator==(const Jedi& rhs)const {

	if (m_age != rhs.m_age || m_force != rhs.m_force || m_rank != rhs.m_rank || m_name_jedi != rhs.m_name_jedi || m_color_of_lightsaber != rhs.m_color_of_lightsaber) {
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

	String buff;
	do {
		in >> buff; // get name
	} while (!buff.is_only_alpha());

	oth.m_name_jedi = buff; // set jedi name


	unsigned age;
	in >> age;
	while (age <= 0) {
		std::cerr << "\nAge of jedi must to be possitive integer! Try again:";
		in >> age;
	}

	oth.m_age = age; // set age of jedi


	double force;
	in >> force;
	while (force <= 0.) {
		std::cerr << "\nForce must to be possitive number! Try again:";
		in >> force;
	} 

	oth.m_force = force; // set jedi force


	do {
		in >> buff; // get saber color
	} while (!buff.is_only_alpha());

	oth.m_color_of_lightsaber = buff; // set saber color


	oth.m_rank = Rank::YOUNGLING; // if input is not valid, default rank will be youngling 
	do {
		in >> buff; // get rank
	} while (!buff.is_only_alpha());

/*	if (buff == String("youngling") || buff == String("YOUNGLING")) {
		oth.m_rank = Rank::YOUNGLING;
	} else*/ if (buff == String("initiate") || buff == String("INITIATE")) {
		oth.m_rank = Rank::INITIATE;

	} else if (buff == String("padawan") || buff == String("PADAWAN")) {
		oth.m_rank = Rank::PADAWAN;

	} else if (buff == String("knight_aspirant") || buff == String("KNIGHT_ASPIRANT")) {
		oth.m_rank = Rank::KNIGHT_ASPIRANT;

	} else if (buff == String("knight") || buff == String("KNIGHT")) {
		oth.m_rank = Rank::KNIGHT;

	} else if (buff == String("master") || buff == String("MASTER")) {
		oth.m_rank = Rank::MASTER;

	} else if (buff == String("battle_master") || buff == String("BATTLE_MASTER")) {
		oth.m_rank = Rank::BATTLE_MASTER;

	} else if (buff == String("grand_master") || buff == String("GRAND_MASTER")) {
		oth.m_rank = Rank::GRAND_MASTER;
	} 

	return in;
}

std::ostream& operator<<(std::ostream& out, const Jedi& oth) {

	out << "Name of jedi: "          << oth.m_name_jedi;
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
		out << "\nRank: KNIGHT_ASPIRANT\n";

	} else if (oth.m_rank == Rank::KNIGHT) {
		out << "\nRank: KNIGHT\n";

	} else if (oth.m_rank == Rank::MASTER) {
		out << "\nRank: MASTER\n";

	} else if (oth.m_rank == Rank::BATTLE_MASTER) {
		out << "\nRank: BATTLE_MASTER\n";

	} else if (oth.m_rank == Rank::GRAND_MASTER) {
		out << "\nRank: GRAND_MASTER\n";
	}

	return out;
}

void Jedi::promote(const double& multiplier) {

	if (multiplier > 0) {
		m_force += (multiplier * m_force);

	} else {
		throw std::logic_error("\nMultiplier must be positive number!\n");
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

void Jedi::demote(const double& multiplier) {

	if (multiplier > 0) {
		m_force -= (multiplier * m_force);

	} else {
		throw std::logic_error("\nMultiplier must be positive number!\n");
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

void Jedi::write_to_file(std::ofstream& fout)const {

	fout << "Name of jedi: " << m_name_jedi;
	fout << "\nAge: "  << m_age;
	fout << "\nForce: " << m_force; 
	fout << "\nColor of lightsaber: " << m_color_of_lightsaber;

	if (m_rank == Rank::GRAND_MASTER) {
		fout << "\nRank: GRAND_MASTER\n";

	} else if (m_rank == Rank::INITIATE) {
		fout << "\nRank: INITIATE\n";

	} else if (m_rank == Rank::PADAWAN) {
		fout << "\nRank: PADAWAN\n";

	} else if (m_rank == Rank::KNIGHT_ASPIRANT) {
		fout << "\nRank: KNIGHT_ASPIRANT\n";

	} else if (m_rank == Rank::KNIGHT) {
		fout << "\nRank: KNIGHT\n";

	} else if (m_rank == Rank::MASTER) {
		fout << "\nRank: MASTER\n";

	} else if (m_rank == Rank::BATTLE_MASTER) {
		fout << "\nRank: BATTLE MASTER\n";

	} else if (m_rank == Rank::YOUNGLING) {
		fout << "\nRank: YOUNGLING\n";
	}
}

void Jedi::read_from_file(std::ifstream& fin) {

	unsigned cnt = 0;
	while (cnt < 5) {

		String input;
		fin >> input;

		if (input == String("Name")) {

			String buff;
			do {
				fin >> buff;
			} while (buff != String("of"));

			do {
				fin >> buff;
			} while (buff != String("jedi:"));

			do {
				fin >> buff; // get jedi name
			} while (!buff.is_only_alpha());

			m_name_jedi = buff;

			++cnt;

		} else if (input == String("Age:")) {

			String age;
			do {
				fin >> age; // get jedi age
			} while (!age.is_only_digits());
			
			m_age = age.convert_to_integer(age.get_string());

			++cnt;

		} else if (input == String("Force:")) {

			String force;
			do {
				fin >> force; // get jedi force
			} while (!force.is_only_digits());

			m_force = force.convert_to_double(force.get_string());

			++cnt;

		} else if (input == String("Color")) {

			String buff;
			do {
				fin >> buff;
			} while (buff != String("of"));

			do {
				fin >> buff;
			} while (buff != String("lightsaber:"));

			do {
			fin >> buff; // get saber color
			} while (!buff.is_only_alpha());

			m_color_of_lightsaber = buff;

			++cnt;

		} else if (input == String("Rank:")) {

			bool flag = false;
			do {
				String buff;
				fin >> buff;

				if (buff == String("youngling") || buff == String("YOUNGLING")) {
					m_rank = Rank::YOUNGLING;
					flag = true;

				} else if (buff == String("initiate") || buff == String("INITIATE")) {
					m_rank = Rank::INITIATE;
					flag = true;

				} else if (buff == String("padawan") || buff == String("PADAWAN")) {
					m_rank = Rank::PADAWAN;
					flag = true;

				} else if (buff == String("knight_aspirant") || buff == String("KNIGHT_ASPIRANT")) {
					m_rank = Rank::KNIGHT_ASPIRANT;
					flag = true;

				} else if (buff == String("knight") || buff == String("KNIGHT")) {
					m_rank = Rank::KNIGHT;
					flag = true;

				} else if (buff == String("master") || buff == String("MASTER")) {
					m_rank = Rank::MASTER;
					flag = true;

				} else if (buff == String("battle_master") || buff == String("BATTLE_MASTER")) {
					m_rank = Rank::BATTLE_MASTER;
					flag = true;

				} else if (buff == String("grand_master") || buff == String("GRAND_MASTER")) {
					m_rank = Rank::GRAND_MASTER;
					flag = true;
				}

			} while (!flag);

			++cnt;

		}
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

void Jedi::to_zero() {

	m_age                 = 0;
	m_rank                = Rank::YOUNGLING;
	m_force               = 0.0;
	m_name_jedi           = nullptr;
	m_color_of_lightsaber = nullptr;
}

void Jedi::copy(const Jedi& rhs) {

	set_age(rhs.m_age);
	m_force               = rhs.m_force;
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

	if (force <= 0) {
		m_force = 10.;

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