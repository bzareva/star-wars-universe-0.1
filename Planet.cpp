#include "Planet.h"

Planet::Planet(std::ifstream& fin) {

	read_from_file(fin);
}

Planet::Planet(const Vector<Jedi>& jedi, const String& planet_name)
 :m_planet_name(planet_name) {

	for (unsigned i = 0; i < jedi.size(); ++i) {
		m_jedi.push_back(jedi[i]);
	}
}

Planet::Planet(const Planet& rhs) {

	copy(rhs);
}

Planet& Planet::operator=(const Planet& rhs) {

	if (this != &rhs) {
		copy(rhs);
	}
	return *this;
}

Planet::Planet(Planet&& rhs)noexcept
 :m_planet_name(rhs.m_planet_name) {

	for (unsigned i = 0; i < rhs.get_count_jedi(); ++i) {
		m_jedi[i] = rhs.m_jedi[i];
	}

	rhs.to_zero();
}

Planet& Planet::operator=(Planet&& rhs)noexcept {

	if (this != &rhs) {
		m_planet_name = rhs.m_planet_name;

		for (unsigned i = 0; i < rhs.get_count_jedi(); ++i) {
			m_jedi[i] = rhs.m_jedi[i];
		}

		rhs.to_zero();
	}
	return *this;
}

std::istream& operator>>(std::istream& in, Planet& oth) {

	in >> oth.m_planet_name;

	unsigned cnt;
	in >> cnt;
	while (cnt <= 0) {
		std::cout << "\nWrong input! It has to be possitive number bigger than zero. Enter again:";
		in >> cnt;
	}

	for (unsigned i = 0; i < cnt; ++i) {
		in >> oth.m_jedi[i];
	}

	return in;
}

std::ostream& operator<<(std::ostream& out, const Planet& oth) {

	out << "Planet name: " << oth.m_planet_name;
	out << "\nCounts of inhabitants jedi: " << oth.m_jedi.size() << std::endl;
	for (unsigned i = 0; i < oth.m_jedi.size(); ++i) { 
		out << oth.m_jedi[i];
	}
	return out;
}

Planet operator+(Planet lhs, const Planet& rhs) {

	lhs += rhs;
	lhs.sort();
	return lhs;
}

Planet operator+(Planet lhs, const Jedi& rhs) {

	lhs += rhs;
	return lhs;
}

Planet operator-(Planet lhs, const Jedi& rhs) {

	lhs -= rhs;
	return lhs;
}

bool Planet::operator==(const Planet& rhs)const {

	if ((m_jedi.size() != rhs.m_jedi.size()) || (m_planet_name != rhs.m_planet_name)) {
		return false;
	}

	for (unsigned i = 0, j = 0; i < m_jedi.size() && j < rhs.m_jedi.size(); ++i, ++j) {

		if (m_jedi[i] != rhs[j]) {
			return false;
		}
	}

	return true;
}

bool Planet::operator!=(const Planet& rhs)const {

	return !(*this == rhs);
}

Planet& Planet::operator+=(const Jedi& rhs) {

	m_jedi.push_back(rhs);
	return *this;
}

Planet& Planet::operator+=(const Planet& rhs) {

	for (unsigned i = 0; i < rhs.m_jedi.size(); ++i) { // rhs.m_jedi.size() <==> rhs.get_count_jedi()
		m_jedi += rhs.m_jedi[i];                       
	}
	return *this;
}

Planet& Planet::operator-=(const Jedi& rhs) {

	for (unsigned i = 0; i < m_jedi.size(); ++i) {

		if (m_jedi[i] == rhs) {
			m_jedi.erase(i);
			return *this;
		}
	}

	return *this;
}

Jedi& Planet::operator[](const unsigned& index) {

	return at(index);
}

const Jedi& Planet::operator[](const unsigned& index)const {

	return at(index);
}

Jedi& Planet::at(const unsigned& index) {

	if (index < 0 || index > m_jedi.size()) {
		throw std::out_of_range("This index is not correct!");
	}

	return m_jedi[index];
}

const Jedi& Planet::at(const unsigned& index)const {

	if (index < 0 || index > m_jedi.size()) {
		throw std::out_of_range("This index is not correct!");
	}

	return m_jedi[index];
}

Base* Planet::clone()const {

	return new Planet(*this);
}

void Planet::write_to_file(std::ofstream& fout)const {

	fout << "Name of planet: " << m_planet_name;
	fout << "\nCounts of inhabitants jedi: " << m_jedi.size() << std::endl;
	for (unsigned i = 0; i < m_jedi.size(); ++i) {
		m_jedi[i].write_to_file(fout);
	}
}

void Planet::read_from_file(std::ifstream& fin) {
	
	unsigned cnt = 0;
	String input;
	while (cnt < 2) {
	
		fin >> input;

		if (input == String("Planet")) {

			String buff;
			do {
				fin >> buff;
			} while (buff != String("name:"));

			do {
				fin >> buff; // get planet name
			} while (!buff.is_only_alpha());

			m_planet_name = buff;

			++cnt;

		} else if(input == String("Counts")){
		
			String buff;
			do {
				fin >> buff;
			} while (buff != String("of"));

			do {
				fin >> buff;
			} while (buff != String("inhabitants"));

			do {
				fin >> buff;
			} while (buff != String("jedi:"));

		
			do {
				fin >> buff; // counts of jedi on this planet
			} while (!buff.is_only_digits());

			unsigned br = buff.convert_to_integer(buff.get_string());

			for (unsigned i = 0; i < br; ++i) {

				Jedi j_read(fin);
				m_jedi += j_read;
			}

			++cnt;
		}
	}
}

String Planet::type_name()const {

	return "planet";
}

void Planet::create_jedi(const String& planet_name, const String& jedi_name, const Rank& jedi_rank, const unsigned& jedi_age, const String& saber_color, const double& jedi_strength) {

	if (planet_name != m_planet_name) {
		std::cout << "\nNot exist planet with this name!\n";
		return;
	}
	 
	for (unsigned i = 0; i < m_jedi.size(); ++i) {
	
		if (jedi_name == m_jedi[i].get_name_jedi()) {
			std::cout << "\nAlready exists jedi with name like this!\n";
			return;
		}
	}

	Jedi curr(jedi_age, jedi_strength, jedi_rank, jedi_name, saber_color);
	m_jedi += curr;

	std::cout << "\nSuccessfully added jedi on planet " << planet_name << "!\n";
}

void Planet::remove_jedi(const String& jedi_name, const String& planet_name) {

	for (unsigned i = 0; i < m_jedi.size(); ++i) {

		if (jedi_name == m_jedi[i].get_name_jedi()) {

			try {
				m_jedi.erase(i);
				std::cout << "\nSuccessfully removed jedi!\n";
				return;

			} catch (std::out_of_range& e) {
				std::cerr << e.what() << std::endl;
			}
		}
	}

	std::cout << "\nNot successfully deleted jedi!\n";
}

Jedi Planet::get_strongest_jedi(const String& planet_name)const {

	unsigned ind = 0;
	unsigned max = m_jedi[ind].get_force();

	for (unsigned i = 1; i < m_jedi.size(); ++i) {

		if (m_jedi[i].get_force() > max) {
			ind = i;
			max = m_jedi[i].get_force();
		}
	}

	return m_jedi[ind];
}

Vector<Jedi> Planet::get_youngest_jedi(const String& planet_name, const Rank& jedi_rank)const {

	bool flag = false;
	Vector<Jedi> temp;

	for (unsigned i = 0; i < m_jedi.size(); ++i) {

		if (m_jedi[i].get_rank() == jedi_rank) {
			temp.push_back(m_jedi[i]);
			flag = true;
		}
	}

	if (!flag) {
		throw std::exception("\nHave not founded jedi with this description!\n");
	}

	for (unsigned i = 0; i < temp.size() - 1; ++i) {

		unsigned curr = temp[i].get_age();
		unsigned ind  = i;
		for (unsigned j = i + 1; j < temp.size(); ++j) {

			if (curr > temp[j].get_age()) {
				ind = j;
				curr = temp[j].get_age();
			}
		}

		if (ind != i) {
			Jedi sw   = temp[i];
			temp[i]   = temp[ind];
			temp[ind] = sw;
		}
	}

	unsigned first = m_jedi[0].get_age();
	for (unsigned i = 1; i < temp.size() - 1; ++i) {

		if (temp[i].get_age() != first) {
			temp.erase(i);
			//temp.erase(i + 1);
		}
	}

	return temp;
}

String Planet::get_most_used_saber_color(const String& planet_name, const Rank& jedi_rank)const {

	Vector<String> colors;
	for (unsigned i = 0; i < m_jedi.size(); ++i) {

		if (m_jedi[i].get_rank() == jedi_rank) {
			colors.push_back(m_jedi[i].get_color_of_lightsaber());
		}
	}

	Vector<String> erase_repeates = colors;
	for (unsigned i = 0; i < erase_repeates.size() - 1; ++i) {

		for (unsigned j = i + 1; j < erase_repeates.size(); ++j) {

			if (erase_repeates[i] == erase_repeates[j]) {
				erase_repeates.erase(j);
			}
		}
	}

	Vector<int> cnt_colors;
	for (unsigned i = 0; i < erase_repeates.size(); ++i) {

		unsigned br = 0;
		for (unsigned j = 0; j < colors.size(); ++j) {

			if (erase_repeates[i] == colors[j]) {
				++br;
			}
		}

		cnt_colors.push_back(br);
	}

	unsigned ind = 0;
	for (unsigned i = 1; i < cnt_colors.size(); ++i) {

		if (cnt_colors[i] > cnt_colors[ind]) {
			ind = i;
		}
	}

	return erase_repeates[ind];
}

String Planet::get_most_used_saber_color(const String& planet_name)const {

	return get_most_used_saber_color(planet_name, Rank::GRAND_MASTER);
}

void Planet::print_planet(const String& name) {

	if (m_planet_name != name) {
		return;
	}

	sort();
	std::cout << *this;
	std::cout << "\n\nSuccessfully printed information of " << name << "!\n";
}

void Planet::print_jedi(const String& jedi_name)const {

	for (unsigned i = 0; i < m_jedi.size(); ++i) {

		if (m_jedi[i].get_name_jedi() == jedi_name) {
			std::cout << m_jedi[i] << std::endl;
			std::cout << "\n\nSuccessfully printed information of " << jedi_name << "!\n";
			return;
		}
	}
}

void Planet::promote_jedi(const String& jedi_name, const double& multiplier) {

	bool flag = false;
	for (unsigned i = 0; i < m_jedi.size(); ++i) {

		if (jedi_name == m_jedi[i].get_name_jedi()) {

			try {
				m_jedi[i].promote(multiplier);
				flag = true;

			} catch (std::logic_error& e){
				std::cerr << e.what() << std::endl;
			}
		}
	}

	if (flag) {
		std::cout << "\nSuccessful promote " << jedi_name << " on planet " << m_planet_name << "!\n";
		return;
	}

	std::cout << "\nNot successful promote " << jedi_name << " on planet " << m_planet_name << "!\n";
}

void Planet::demote_jedi(const String& jedi_name, const double& multiplier) {

	bool flag = false;
	for (unsigned i = 0; i < m_jedi.size(); ++i) {
		if (jedi_name == m_jedi[i].get_name_jedi()) {

			try {
				m_jedi[i].demote(multiplier);
				flag = true;

			} catch (std::logic_error& e) {
				std::cerr << e.what() << std::endl;
			}
		}
	}

	if (flag) {
		std::cout << "\nSuccessful demote " << jedi_name << " on planet " << m_planet_name << "!\n";
		return;
	}

	std::cout << "\nNot successful demote " << jedi_name << " on planet " << m_planet_name << "!\n";
}

void Planet::sort() {

	sort_rank();
	sort_names();
}

void Planet::sort_rank() {

	for (unsigned i = 0; i < m_jedi.size() - 1; ++i) {

		unsigned ind = i;
		for (unsigned j = i + 1; j < m_jedi.size(); ++j) {

			if (m_jedi[i].rank_num() > m_jedi[j].rank_num()) {
				ind = j;
			}
		}

		if (ind != i) {
			Jedi temp   = m_jedi[i];
			m_jedi[i]   = m_jedi[ind];
			m_jedi[ind] = temp;
		}
	}
}

void Planet::sort_names() {

	unsigned cnt = 1;
	unsigned beg = 0;
	for (unsigned k = 0; k < m_jedi.size() - 1; ++k) {

		if (m_jedi[k].get_rank() == m_jedi[k + 1].get_rank()) {
			++cnt;

		} else {	
			for (unsigned i = beg; i < cnt; ++i) {

				unsigned ind = i;
				for (unsigned j = i + 1; j < cnt; ++j) {

					if (m_jedi[i].get_name_jedi().str_cmp(m_jedi[i].get_name_jedi().get_string(), m_jedi[j].get_name_jedi().get_string()) > 0) {
						ind = j;
					}
				}

				if (ind != i) {
					Jedi temp   = m_jedi[i];
					m_jedi[i]   = m_jedi[ind];
					m_jedi[ind] = temp;
				}
			}

			beg += k;
			cnt = 1;
		}
	}
}

unsigned Planet::get_count_jedi()const {

	return m_jedi.size();
}

String Planet::get_planet_name()const {

	return m_planet_name;
}

Vector<Jedi> Planet::get_jedi()const {

	return m_jedi;
}

Jedi Planet::get_jedi(const unsigned& index)const {

	return m_jedi[index];
}

void Planet::set_planet_name(const String& planet_name) {

	m_planet_name = planet_name;
}

void Planet::set_jedi(const Vector<Jedi>& jedi) {

	for (unsigned i = 0; i < jedi.size(); ++i) {
		m_jedi.push_back(jedi[i]);
	}
}

void Planet::to_zero() {

	m_planet_name = nullptr;

	for (unsigned i = 0; i < m_jedi.size(); ++i) {
		m_jedi[i] = Jedi();
	}
}

void Planet::copy(const Planet& obj) {

	m_planet_name = obj.m_planet_name;

	for (unsigned i = 0; i < obj.m_jedi.size(); ++i) {
		m_jedi += obj.m_jedi[i];
	}
}