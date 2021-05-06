#ifndef __STRING_H__
#define __STRING_H__
#include <exception>
#include <fstream>
#include <iostream>
#include "Rank.h"
///
/// Realization of basic functionalities from string library
///
class String {

public:
	/// constructor with parameter, who has default value
	String(const char* str = "default_string");

	/// constructor with parameter from type ifstream
	String(std::ifstream& fin);

	/// copy constructor
	String(const String& obj);

	/// operator=
	String& operator=(const String& obj);

	/// destructor
	~String();

	/// saves string to file
	void saveString(std::ofstream& fout);

	/// loads string from file
	void loadString(std::ifstream& fin);

	/// input from console for string
	friend std::istream& operator>>(std::istream& in, String& str);

	/// output to console for string
	friend std::ostream& operator<<(std::ostream& out, const String& str);

	/// concatenates two strings
	friend String operator+(String lhs, const String& rhs);

	/// second string is added to the first string
	String& operator+=(const String& rhs);

	/// checks if two strings are equal 
	bool operator==(const String& rhs)const;

	/// checks if two strings are not equal
	bool operator!=(const String& rhs)const;

	/// @returns Not constant element of given position
	char& operator[](unsigned index);

	/// @reurns Constant element of given position
	const char& operator[](unsigned index)const;

	/// help method for not constant operator[]
	char& at(unsigned index);

	/// help method for constant operator[]
	const char& at(unsigned index)const;

	/// sets aside memory
	void reserve(unsigned new_cap);

	/// adds element in end of array
	void add(char ch);

	/// adds element in the given position of array
	bool insert_at(char ch, unsigned index);

	/// remove element in the given position of array 
	bool remove_at(unsigned index);

	//// 
	/// If capacity of array if bigger than size,
	/// then fills not used memory with '\0'.
	///
	void fill_zeros(char* str);

	///
	/// Copies the string pointed by source into the array pointed by destination,
	/// including the terminating null character (and stopping at that point).
	///
	void str_cpy(char* dest, const char* src);

	/// @returns The length of string  
	unsigned str_len(const char* str);

	///
	/// Compares the string str1 to the string str2.
	/// Return value <0 if the first character that does not match has a lower value in ptr1 than in ptr2.
	/// Return value  0 if the contents of both strings are equal.
	/// Return value >0 if the first character that does not match has a greater value in ptr1 than in ptr2.
	///
	int str_cmp(const char* str1, const char* str2);

	/// 
	/// Appends the string pointed to by src to the end of the string pointed to by dest.
    /// @param dest This is pointer to the destination array, which should contain a string, and should be large enough to contain the concatenated resulting string.
    /// @param src This is the string to be appended. This should not overlap the destination.
    ///
	void str_cat(char* dest, const char* src);

	/// convert string to integer
	unsigned convert_to_integer(const char* str);

	/// convert string to double
	double convert_to_double(const char* str);

	/// convert string to rank
	Rank convert_to_rank(const char* str);

	/// find digits to given number
	unsigned cnt_digits(unsigned number);

private:
	/// help method for operator= and copy ctor 
	void cpy(const String& obj);

	/// deletes all dynamic allocated memory in String, more precisely dector call it
	void free();

public:
	/// setter for string
	void set_string(const char* str);

	/// setter for size of string
	void set_size(unsigned size);

	/// setter for capacity of string
	void set_cap(unsigned cap);

	/// @returns Capacity of string
	unsigned get_capacity()const;

	/// @returns Size of string
	unsigned get_size()const;

	/// @returns The string
	const char* get_string()const;

private:
	unsigned m_size;
	unsigned m_capacity;
	char*    m_string;

	static const unsigned DEFAULT_CAPACITY;
	static const unsigned RESIZE;

};

#endif //__STRING_H__