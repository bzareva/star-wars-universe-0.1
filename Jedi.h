#ifndef __JEDI_H__
#define __JEDI_H__
#include <iostream>
#include <fstream>
#include "Base.h"

class Jedi: public Base {

public:
	enum Rank {
		YOUNGLING = 1,
		INITIATE,
		PADAWAN,
		KNIGHT_ASPIRANT,
		KNIGHT,
		MASTER, 
		BATTLE_MASTER,
		GRAND_MASTER
	};

	Jedi();
	Jedi(std::ifstream&);
	Jedi(int, double, const Rank&, const char*, const char*);
	Jedi(const Jedi&);
	Jedi& operator=(const Jedi&);
	virtual ~Jedi();

	static const char* getClassName();
	bool operator==(const Jedi&)const;	
	bool operator<(const Jedi&)const;

	bool promote_jedi(double);
	bool demote_jedi(double);

	/// override methods form Base class 
	virtual Base* clone()const override;
	virtual void print(std::ostream&)const override;
	virtual void print_to_file(std::ofstream&)const override;
	virtual void read_from_console(std::istream&)override;
	virtual void read_from_file(std::ifstream&)override;
	virtual bool is_valid_type(const char*)const override;
	virtual const char* type_name()const override;

private:
	void cpy(const Jedi& rhs);
	void clean();

public: 
	/// setters 
	void set_age(int);
	void set_force(double);
	void set_name_jedi(const char*);
	void set_color_of_lightsaber(const char*);
	void set_rank(const Rank&);

	/// getters
	int get_age()const;
	double get_force()const;
	const char* get_name_jedi()const;
	const char* get_color_of_lightsaber()const;
	Rank get_rank()const;

private:	
	int    m_age;
	double m_force;
	Rank   m_rank;
	char*  m_name_jedi;
	char*  m_color_of_lightsaber;

};

std::istream& operator>>(std::istream&, Jedi&);
std::ostream& operator<<(std::ostream&, const Jedi&);

#endif ///__JEDI_H__