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
	String(const String& rhs);

	/// operator=
	String& operator=(const String& rhs);

	/// move copy constructor
	String(String&& rhs)noexcept;

	/// move operator=
	String& operator=(String&& rhs)noexcept;

	/// destructor
	~String();

	/// saves string to file
	void save_string(std::ofstream& fout);

	/// loads string from file
	void load_string(std::ifstream& fin);

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
	char& operator[](const unsigned& index);

	/// @reurns Constant element of given position
	const char& operator[](const unsigned& index)const;

	/// help method for not constant operator[]
	char& at(const unsigned& index);

	/// help method for constant operator[]
	const char& at(const unsigned& index)const;

	/// sets aside memory
	void reserve(const unsigned& new_cap);

	/// adds element in end of array
	void add(const char& ch);

	/// adds element in the given position of array
	bool insert_at(const char& ch, const unsigned& index);

	/// remove element in the given position of array 
	bool remove_at(const unsigned& index);

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

	/// @return True if given symbol is digit otherwise False
	bool is_digit(const char& ch)const;

	/// @return True if given symbol is lower alpha otherwise False
	bool is_lower(const char& ch)const;

	/// @return True if given symbol is upper alpha otherwise False
	bool is_upper(const char& ch)const;

	/// @return True if given symbol is alpha otherwise False
	bool is_alpha(const char& ch)const;

	/// @return True if string contains only digits otherwise False
	bool is_only_digits()const;

	/// @return True if string contains only letters otherwise False
	bool is_only_alpha()const;

	/// @return True if string contains letters and whitespace otherwise False
	bool is_whitespace_and_letters()const;

	/// convert alpha to lower alpha if is it upper
	void to_lower(char& ch);

	/// convert alpha to upper alpha if is it lower
	void to_upper(char& ch);

	/// @return True if given string is valid rank of jedi otherwise False
	bool is_valid_rank()const;

private:
	/// make null value of data
	void to_zero();

	/// help method for operator= and copy ctor 
	void cpy(const String& obj);

	/// deletes all dynamic allocated memory in String, more precisely dector call it
	void free();

public:
	/// setter for string
	void set_string(const char* str);

	/// setter for size of string
	void set_size(const unsigned& size);

	/// setter for capacity of string
	void set_cap(const unsigned& cap);

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