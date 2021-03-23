#include "Planet.h"

Planet::Planet() {



}

Planet::Planet(std::ifstream& fin) {



}

Planet::Planet(int cap, int count, Jedi* jedi, const char* planet_name) {

}

Planet::Planet(const Planet& oth) {

	cpy(oth);
}

Planet& Planet::operator=(const Planet& rhs) {


}

Planet:: ~Planet() {

}

void Planet::promote_jedi(const char* jedi_name, double multiplier) {

}

void Planet::demote_jedi(const char* jedi_name, double multiplier) {

}

bool Planet::remove_jedi(const char* jedi_name) {

}

void Planet::get_strongest_jedi()const {

}

void Planet::get_youngest_jedi(const Rank& jedi_rank)const {

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