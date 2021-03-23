#ifndef __CSTRING_NAMESPACE_H__
#define __CSTRING_NAMESPACE_H__
///
/// Functions from cstring library.
/// 
/// The only functions which i use in this program
/// are - strlen, strcat, strcpy and strcmp.
/// These functions work in the same way as
/// the functions in the cstring library.
/// I learned the solutions of these functions during 
/// Introduction to Programming course.
/// 
namespace cstring_namespace {

	/// @returns The length of string
	unsigned strLen(const char* str);

	/// Appends the string pointed to by src to the end of the string pointed to by dest.
	/// @param dest This is pointer to the destination array, which should contain a string, and should be large enough to contain the concatenated resulting string.
	/// @param src This is the string to be appended. This should not overlap the destination.
	void strCat(char* dest, const char* src);

	/// Copies the string pointed by source into the array pointed by destination,
	/// including the terminating null character (and stopping at that point).
	void strCpy(char* dest, const char* src);

	/// Compares the string str1 to the string str2.
	/// Return value <0 if the first character that does not match has a lower value in ptr1 than in ptr2.
	/// Return value  0 if the contents of both strings are equal.
	/// Return value >0 if the first character that does not match has a greater value in ptr1 than in ptr2.
	int strCmp(const char* str1, const char* str2);

};

#endif //__CSTRING_NAMESPACE_H__