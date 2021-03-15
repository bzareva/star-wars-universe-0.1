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

public:
	Jedi();
	Jedi(std::ifstream&);
	Jedi(int, double, const char*, const char*, const Rank&);
	Jedi(const Jedi& oth);
	Jedi& operator=(const Jedi& rhs);
	virtual ~Jedi();

	static const char* getClassName();
	bool operator==(const Jedi& other)const;	

	bool promote_jedi(int);
	bool demote_jedi(int);
	void init_jedi(int, double, const char*, const char*, const Rank&);

	/// override methods form Base class 
	virtual Base* clone()const override;
	virtual void print(std::ostream&)const override;
	virtual void print_to_file(std::ofstream&)const override;
	virtual void read_from_file(std::ifstream&)override;
	virtual bool isValidType(const char*)const override;
	virtual const char* typeName()const override;

private:
	void cpy(const Jedi& rhs);
	void clean();

public: 
	/// setters 
	void set_age(int);
	void set_force(double);
	void set_name_jedi(const char*);
	void set_rank(const Rank&);

	/// getters
	int get_age()const;
	double get_force()const;
	const char* get_name_jedi()const;
	const char* color_of_lightsaber()const;
	Rank get_rank()const;

private:	
	int    m_age;
	double m_force;
	char*  m_name_jedi;
	char*  m_color_of_lightsaber;
	Rank   m_rank;

};

std::ostream& operator>>(std::istream& in, Jedi& other);
std::ostream& operator<<(std::ostream& out, const Jedi& other);

#endif ///__JEDI_H__