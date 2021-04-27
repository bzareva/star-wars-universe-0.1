#include "String.h"

const unsigned String::DEFAULT_CAPACITY = 64;
const unsigned String::RESIZE           = 2;

String::String(const char* str)
 :m_size(str_len(str)), m_capacity(m_size + 1) {

	m_string = new char[m_capacity];
	str_cpy(m_string, str);
}

String::String(std::ifstream& fin) {

	loadString(fin);
}

String::String(const String& obj) {

	cpy(obj);
}

String& String::operator=(const String& oth) {

	if (this != &oth) {
		free();
		cpy(oth);
	}
	return *this;
}

String::~String() {

	free();
}

void String::saveString(std::ofstream& fout) {

	fout << m_string;
}

void String::loadString(std::ifstream& fin) {

	char ch;
	short int cnt   = 0;
	char buff[1024] = { '\0' };

	while (fin.get(ch) && !fin.eof() && ch != '\n' && cnt < 1024) {
		buff[cnt] = ch;
		++cnt;
	}

	buff[cnt] = '\0';

	m_size     = str_len(buff);
	m_capacity = m_size + 1;
	m_string   = new char[m_capacity];
	str_cpy(m_string, buff);
//	fill_zeros(m_string);
}

std::istream& operator>>(std::istream& in, String& str) {

	char buff[1024] = { '\0' };
	in.getline(buff, 1024, '\n');

	str.m_size = str.str_len(buff);
	if (str.m_size == 0) {
		str.m_capacity = String::DEFAULT_CAPACITY;
	} else {
		str.m_capacity = str.m_size + 1;
	}

	if (str.m_string != nullptr) {
		delete[] str.m_string;
	}

	str.m_string = new char[str.m_capacity];
	str.str_cpy(str.m_string, buff);
	str.fill_zeros(str.m_string);

	return in;
}

std::ostream& operator<<(std::ostream& out, const String& str) {

	out << str.m_string;
	return out;
}

String operator+(String lhs, const String& rhs) {

	lhs += rhs;
	return lhs;
}

String& String::operator+=(const String& rhs) {

	m_size += rhs.m_size;
	if (m_size >= m_capacity) {
		reserve(RESIZE * m_size);
	}

	str_cat(m_string, rhs.m_string);
	fill_zeros(m_string);

	return *this;
}

bool String::operator==(const String& rhs)const {

	if (m_size != rhs.m_size) {
		return false;
	}

	for (unsigned i = 0, j = 0; i < m_size && j < rhs.m_size; ++i, ++j) {
		if (m_string[i] != rhs.m_string[j]) {
			return false;
		}
	}

	return true;
}

bool String::operator!=(const String& rhs)const {

	return !(*this == rhs);
}

char& String::operator[](unsigned index) {

	return at(index);
}

const char& String::operator[](unsigned index)const {

	return at(index);
}

char& String::at(unsigned index) {

	if (index < 0 || index > m_size) {
		throw std::out_of_range("Invalid index!");
	}
	return m_string[index];
}

const char& String::at(unsigned index)const {

	if (index < 0 || index > m_size) {
		throw std::out_of_range("Invalid index!");
	}
	return m_string[index];
}

void String::reserve(unsigned new_cap) {

	if (new_cap <= 0 || new_cap == m_capacity) {
		return;
	}

	if (new_cap > m_capacity) {

		m_capacity = new_cap;
		char* curr = new char[m_capacity];
		str_cpy(curr, m_string);

		if (m_string != nullptr) {
			delete[]m_string;
		}

		m_string = curr;
		fill_zeros(m_string);
	}
}

void String::add(char ch) {

	if (m_size + 1 >= m_capacity) {
		reserve(RESIZE * m_size);
	}

	m_string[m_size] = ch;
	++m_size;
	m_string[m_size] = '\0';
}

bool String::insert_at(char ch, unsigned index) {

	if (index < 0 || index > m_size) {
		return false;
	}

	if (m_size + 1 >= m_capacity) {
		reserve(RESIZE * m_size);
	}

	for (unsigned i = m_size; i > index; --i) {
		m_string[i] = m_string[i - 1];
	}

	m_string[index] = ch;
	++m_size;

	return true;
}

bool String::remove_at(unsigned index) {

	if (index < 0 || index > m_size) {
		return false;
	}

	for (unsigned i = index; i < m_size - 1; ++i) {
		m_string[i] = m_string[i + 1];
	}

	m_string[m_size - 1] = '\0';
	--m_size;

	return true;
}

void String::fill_zeros(char* str) {

	unsigned len = str_len(str);
	while (len < m_capacity) {
		*(str + len) = '\0';
		++len;
	}
}

void String::str_cpy(char* dest, const char* src) {

	while (*src) {
		*dest = *src;
		++src;
		++dest;
	}

	*dest = '\0';
}

unsigned String::str_len(const char* str) {

	unsigned length = 0;
	while (*str) {
		++str;
		++length;
	}

	return length;
}

int String::str_cmp(const char* str1, const char* str2) {

	while (*str1 && (*str1 == *str2)) {
		++str1;
		++str2;
	}

	return *str1 - *str2;
}

void String::str_cat(char* dest, const char* src) {

	while (*dest) {
		++dest;
	}

	str_cpy(dest, src);
}

unsigned String::convert_to_integer(const char* str) {

	if (str == nullptr) {
		return 0;
	}

	unsigned number = 0;
	unsigned i      = 0;
	while (str[i] != '\0') {

		switch (str[i]) {
		case '0': {
			number += 0;
			break;
		} case '1': {
			number += 1;
			break;
		} case '2': {
			number += 2;
			break;
		} case '3': {
			number += 3;
			break;
		} case '4': {
			number += 4;
			break;
		} case '5': {
			number += 5;
			break;
		} case '6': {
			number += 6;
			break;
		} case '7': {
			number += 7;
			break;
		} case '8': {
			number += 8;
			break;
		} case '9': {
			number += 9;
			break;
		}
		default: break;
		}

		number *= 10;
		++i;
	}

	number /= 10;

	return number;
}

double String::convert_to_double(const char* str) {


	if (str == nullptr) {
		return 0;
	}

	double before = 0.;
	double after = 0.;
	int i = 0;
	bool point = false;
	while (str[i] != '\0') {

		switch (str[i]) {
		case '0': {
			if (point) {
				after += 0;
				break;
			}
			before += 0;
			break;
		} case '1': {
			if (point) {
				after += 1;
				break;
			}
			before += 1;
			break;
		} case '2': {
			if (point) {
				after += 2;
				break;
			}
			before += 2;
			break;
		} case '3': {
			if (point) {
				after += 3;
				break;
			}
			before += 3;
			break;
		} case '4': {
			if (point) {
				after += 4;
				break;
			}
			before += 4;
			break;
		} case '5': {
			if (point) {
				after += 5;
				break;
			}
			before += 5;
			break;
		} case '6': {
			if (point) {
				after += 6;
				break;
			}
			before += 6;
			break;
		} case '7': {
			if (point) {
				after += 7;
				break;
			}
			before += 7;
			break;
		} case '8': {
			if (point) {
				after += 8;
				break;
			}
			before += 8;
			break;
		} case '9': {
			if (point) {
				after += 9;
				break;
			}
			before += 9;
			break;
		} case '.': {
			point = true;
		}
		default: break;
		}

		if (!point) {
			before *= 10;
		}

		if (point) {
			after *= 10;
		}

		++i;
	}

	after /= 10;
	before /= 10;

	unsigned digits = cnt_digits(after);
	while (digits > 0) {
		after *= 0.1;
		--digits;
	}

	return (after + before);
}

Rank String::convert_to_rank(const char* str) {

	String curr(str);
	if (curr == String("YOUNGLING") || curr == String("youngling")) {
		return Rank::YOUNGLING;
	} else if (curr == String("INITIATE") || curr == String("initiate")) {
		return Rank::INITIATE;
	} else if (curr == String("PADAWAN") || curr == String("padawan")) {
		return Rank::PADAWAN;
	} else if (curr == String("KNIGHT_ASPIRANT") || curr == String("knight_aspirant")) {
		return Rank::KNIGHT_ASPIRANT;
	} else if (curr == String("KNIGHT") || curr == String("knight")) {
		return Rank::KNIGHT;
	} else if (curr == String("MASTER") || curr == String("master")) {
		return Rank::MASTER;
	} else if (curr == String("BATTLE_MASTER") || curr == String("battle_master")) {
		return Rank::BATTLE_MASTER;
	} else if (curr == String("GRAND_MASTER") || curr == String("grand_master")) {
		return Rank::GRAND_MASTER;
	}

	throw "\nInvalid rank!\n";
}

unsigned String::cnt_digits(unsigned number) {

	unsigned cnt = 0;
	while (number != 0) {
		++cnt;
		number /= 10;
	}
	return cnt;
}

void String::cpy(const String& obj) {

	m_size     = obj.m_size;
	m_capacity = obj.m_capacity;

	m_string = new char[m_capacity];
	str_cpy(m_string, obj.m_string);
	fill_zeros(m_string);
}

void String::free() {

	delete[]m_string;
	m_string = nullptr;
}

void String::set_string(const char* str) {

	if (m_string != nullptr) {
		delete[]m_string;
	}

	m_size     = str_len(str);
	m_capacity = m_size + 1;
	m_string   = new char[m_capacity];
	str_cpy(m_string, str);
	fill_zeros(m_string);
}

void String::set_size(unsigned size) {

	if (size < 0) {
		m_size = 0;
	} else if (size > m_capacity) {
		reserve(RESIZE * size);
		m_size = size;
	} else if (size > 0 && size < m_capacity) {
		m_size = size;
	}
}

void String::set_cap(unsigned cap) {

	if (cap < 0) {
		m_capacity = DEFAULT_CAPACITY;
		return;
	}
	if (cap > m_capacity) {
		m_capacity = cap;
	}
}

unsigned String::get_capacity()const {

	return m_capacity;
}

unsigned String::get_size()const {

	return m_size;
}

const char* String::get_string()const {

	return m_string;
}