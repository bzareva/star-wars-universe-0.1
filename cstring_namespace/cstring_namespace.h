#ifndef __CSTRING_NAMESPACE_H__
#define __CSTRING_NAMESPACE_H__

/**
  * @ Functions from cstring library.
  * @ The only functions which i use in this program
  * @ are - strlen, strcat, strcpy and strcmp.
  * @ These functions work in the same way as
  * @ the functions in the cstring library.
  * @ I learned the solutions of these functions during 
  * @ Introduction to Programming course.
*/

namespace cstring_namespace {

	unsigned strLen(const char* str);

	void strCat(char* dest, const char* src);

	void strCpy(char* dest, const char* src);

	int strCmp(const char* str1, const char* str2);

};

#endif ///__CSTRING_NAMESPACE_H__