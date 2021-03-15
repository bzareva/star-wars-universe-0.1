#include "cstring_namespace.h"

unsigned cstring_namespace::strLen(const char* str) {

	unsigned length = 0;
	while (*str) {
		++str;
		++length;
	}
	return length;
}

void cstring_namespace::strCat(char* dest, const char* src) {

	while (*dest) {
		++dest;
	}
	strCpy(dest, src);
}

void cstring_namespace::strCpy(char* dest, const char* src) {
	
	while (*src) {
		*dest = *src;
		++src;
		++dest;
	}
	*dest = '\0';
}

int cstring_namespace::strCmp(const char* str1, const char* str2) {

	while (*str1 && (*str1 == *str2)) {
		++str1;
		++str2;
	}
	return *str1 - *str2;
}
