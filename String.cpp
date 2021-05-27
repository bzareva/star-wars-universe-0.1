#include "String.h"

const unsigned String::DEFAULT_CAPACITY = 64;
const unsigned String::RESIZE           = 2;

String::String(const char* str)
 :m_size(str_len(str)), m_capacity(m_size + 1) {

	m_string = new char[m_capacity];
	str_cpy(m_string, str);
}

String::String(std::ifstream& fin) {

	load_string(fin);
}

String::String(const String& rhs) {

	cpy(rhs);
}

String& String::operator=(const String& rhs) {

	if (this != &rhs) {
		free();
		cpy(rhs);
	}
	return *this;
}
 
String::String(String&& rhs)noexcept
 :m_string(rhs.m_string), m_size(rhs.m_size), m_capacity(rhs.m_capacity) {

	rhs.to_zero();
}

String& String::operator=(String&& rhs)noexcept {

	if (this != &rhs) {
		free();

		m_string   = rhs.m_string;
		m_capacity = rhs.m_capacity;
		m_size     = rhs.m_size;

		rhs.to_zero();
	}

	return *this;
}

String::~String() {

	free();
}

void String::save_string(std::ofstream& fout) {

	fout << m_string;
}

void String::load_string(std::ifstream& fin) {

	char ch;
	short int cnt   = 0;
	char buff[1024] = { '\0' };

	while (fin.get(ch) && !fin.eof() && ch != '\n' && ch != ' ' && cnt < 1024) {
		buff[cnt] = ch;
		++cnt;
	}

	buff[cnt] = '\0';

	m_size     = str_len(buff);
	m_capacity = m_size + 1;
	m_string   = new char[m_capacity];
	str_cpy(m_string, buff);
}

std::istream& operator>>(std::istream& in, String& str) {

	char ch;
	short int cnt   = 0;
	char buff[1024] = { '\0' };

	while (in.get(ch) && !in.eof() && ch != '\n' && ch != ' ' && cnt < 1024) {
		buff[cnt] = ch;
		++cnt;
	}

	buff[cnt] = '\0';

	str.m_size     = str.str_len(buff);
	str.m_capacity = str.m_size + 1;
	str.m_string   = new char[str.m_capacity];
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

		try {
			reserve(RESIZE * m_size);

		} catch (std::logic_error& e) {
			std::cout << e.what() << std::endl;
		}
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

char& String::operator[](const unsigned& index) {

	return at(index);
}

const char& String::operator[](const unsigned& index)const {

	return at(index);
}

char& String::at(const unsigned& index) {

	if (index < 0 || index > m_size) {
		throw std::out_of_range("Invalid index!");
	}
	return m_string[index];
}

const char& String::at(const unsigned& index)const {

	if (index < 0 || index > m_size) {
		throw std::out_of_range("Invalid index!");
	}
	return m_string[index];
}

void String::reserve(const unsigned& new_cap) {

	if (new_cap <= 0 || new_cap == m_capacity) {
		throw std::logic_error("\nInvalid index!\n");
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

void String::add(const char& ch) {

	if (m_size + 1 >= m_capacity) {
		try {
			reserve(RESIZE * m_size);

		} catch (std::logic_error& e) {
			std::cout << e.what() << std::endl;
		}
	}

	m_string[m_size] = ch;
	++m_size;
	m_string[m_size] = '\0';
}

bool String::insert_at(const char& ch, const unsigned& index) {

	if (index < 0 || index > m_size) {
		return false;
	}

	if (m_size + 1 >= m_capacity) {

		try {
			reserve(RESIZE * m_size);

		} catch (std::logic_error& e) {
			std::cout << e.what() << std::endl;
		}
	}

	for (unsigned i = m_size; i > index; --i) {
		m_string[i] = m_string[i - 1];
	}

	m_string[index] = ch;
	++m_size;

	return true;
}

bool String::remove_at(const unsigned& index) {

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

	bool point    = false;
	int i         = 0;
	double before = 0.;
	double after  = 0.;

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

	throw std::logic_error("\nInvalid rank!\n");
}

unsigned String::cnt_digits(unsigned number) {

	unsigned cnt = 0;
	while (number != 0) {
		++cnt;
		number /= 10;
	}

	return cnt;
}

bool String::is_digit(const char& ch)const {

	return (ch >= '0' && ch <= '9');
}

bool String::is_lower(const char& ch)const {

	return(ch >= 'a' && ch <= 'z');
}

bool String::is_upper(const char& ch)const {

	return (ch >= 'A' && ch <= 'Z');
}

bool String::is_alpha(const char& ch)const {

	return (is_upper(ch) || is_lower(ch));
}

bool String::is_only_digits()const {

	unsigned i         = 0;
	unsigned one_point = 0;
	while (m_string[i] != '\0') {

		if (!is_digit(m_string[i]) && m_string[i] != '.') {
			return false;
		}

		if (m_string[i] == '.') { //if it is float or double
			++one_point;
		}

		++i;
	}

	if (one_point <= 1) {
		return true;
	}

	return false;
}

bool String::is_only_alpha()const {

	unsigned i = 0;
	while (m_string[i] != '\0') {

		if (!is_alpha(m_string[i])) {
			return false;
		}

		++i;
	}

	return true;
}

bool String::is_whitespace_and_letters()const {

	bool whitesp = false;
	unsigned i   = 0;
	while (m_string[i] != '\0') {

		if (is_digit(m_string[i])) {
			return false;
		}

		if (m_string[i] == ' ') {
			whitesp = true;
		}

		++i;
	}

	if (whitesp) {
		return true;
	}

	return false;
}

void String::to_lower(char& ch) {

	if (is_upper(ch)) {
		ch += 'a' - 'A';
	}
}

void String::to_upper(char& ch) {

	if (is_lower(ch)) {
		ch -= 'a' - 'A';
	}
}

bool String::is_valid_rank()const {

	String curr(m_string);
	if (curr == String("YOUNGLING") || curr == String("youngling")) {
		return true;

	} else if (curr == String("INITIATE") || curr == String("initiate")) {
		return true;

	} else if (curr == String("PADAWAN") || curr == String("padawan")) {
		return true;

	} else if (curr == String("KNIGHT_ASPIRANT") || curr == String("knight_aspirant")) {
		return true;

	} else if (curr == String("KNIGHT") || curr == String("knight")) {
		return true;

	} else if (curr == String("MASTER") || curr == String("master")) {
		return true;

	} else if (curr == String("BATTLE_MASTER") || curr == String("battle_master")) {
		return true;

	} else if (curr == String("GRAND_MASTER") || curr == String("grand_master")) {
		return true;
	}
	return false;
}

void String::to_zero() {

	m_string   = nullptr;
	m_size     = 0;
	m_capacity = 0;
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

void String::set_size(const unsigned& size) {

	if (size < 0) {
		m_size = 0;

	} else if (size > m_capacity) {

		try {
			reserve(RESIZE * size);
			m_size = size;

		} catch (std::logic_error& e) {
			std::cout << e.what();
		}

	} else if (size > 0 && size < m_capacity) {
		m_size = size;
	}
}

void String::set_cap(const unsigned& cap) {

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