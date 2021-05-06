#ifndef __VECTOR_H__
#define __VECTOR_H__
#include <exception>
#include <iostream>
///
///  Realization of basic functionalities from vector library
///
template<class T> class Vector {

public:
	/// default constructor
	Vector();

	/// constructor with parameters
	Vector(const T* data, unsigned size);

	/// constructor who adds only one item
	Vector(const T& item);

	/// copy constructor
	Vector(const Vector<T>& obj);

	/// assign content
	Vector<T>& operator=(const Vector<T>& obj);

	/// destructor
	~Vector();

	/// access element(nonconstant)
	T& operator[](unsigned index);

	/// access element(constant)
	const T& operator[](unsigned index) const;

	/// adds item at end of vector
	Vector<T>& operator+=(const T& item);

	/// sum of two vectors
	Vector<T>& operator+=(const Vector<T>& obj);

	/// checks if empty vector
	bool empy()const;

	/// adds item at end of vector
	void push_back(const T& item);

	/// delete last element 
	void pop_back();

	/// insert elements
	void insert(unsigned index, const T& item);

	/// erase elements 
	void erase(unsigned index);

	/// request a change in capacity
	void reserve(unsigned capacity);

	/// swap content
	void swap(Vector<T>& data);

	/// help method for access element(nonconstant)
	T& at(unsigned index);

	/// help method for access element(constant)
	const T& at(unsigned index)const;

	/// access first element(nonconstant)
	T& front();

	/// access first element(constant)
	const T& front()const;

	/// access last element(nonconstant) 
	T& back();

	/// access last element(constant) 
	const T& back()const;

	/// @returns Size
	unsigned size()const;

	/// @returns Size of allocated storage capacity
	unsigned capacity()const;

	/// access data(nonconstant)
	T* data();

	/// access data(constant)
	const T* data()const;

	/// output operator
	template<class T> friend std::ostream& operator<<(std::ostream& out, const Vector<T>& obj);

	/// input operator
	template<class T> friend std::istream& operator>>(std::istream& in, Vector<T>& obj);

private:
	/// help method for assign content and copy ctor 
	void copy(const Vector<T>& obj);

	/// deletes all dynamic allocated memory in Vector, more precisely dector call it
	void free();

private:
	unsigned m_size;
	unsigned m_capacity;
	T*       m_data;

	static const unsigned VECTOR_CAPACITY;

};

template<class T>
const unsigned Vector<T>::VECTOR_CAPACITY = 16;

template<class T>
inline Vector<T>::Vector()
 :m_size(0), m_capacity(VECTOR_CAPACITY), m_data(nullptr) {

	m_data = new T[m_capacity];
}

template<class T>
inline Vector<T>::Vector(const T* data, unsigned size) {

	if (size < 0) {
		m_size = 0;
	} else {
		m_size = size;
	}

	if (VECTOR_CAPACITY < m_size) {
		m_capacity = m_size;
	} else {
		m_capacity = VECTOR_CAPACITY;
	}

	m_data = new T[m_capacity];
	for (unsigned i = 0; i < m_size; ++i) {
		m_data[i] = data[i];
	}

	if (m_size == 0) {
		m_data = nullptr;
	}
}

template<class T>
inline Vector<T>::Vector(const T& item) 
 :m_capacity(VECTOR_CAPACITY), m_size(1) {

	m_data    = new T[m_capacity];
	m_data[0] = item;
}

template<class T>
inline Vector<T>::Vector(const Vector<T>& obj) {

	copy(obj);
}

template<class T>
inline Vector<T>& Vector<T>::operator=(const Vector<T>& obj) {

	if (this != &obj) {
		free();
		copy(obj);
	}
	return *this;
}

template<class T>
inline Vector<T>::~Vector() {

	free();
}

template<class T>
inline T& Vector<T>::operator[](unsigned index) {
	
	return at(index);
}

template<class T>
inline const T& Vector<T>::operator[](unsigned index) const {

	return at(index);
}

template<class T>
inline Vector<T>& Vector<T>::operator+=(const T& item) {

	push_back(item);
	return *this;
}

template<class T>
inline Vector<T>& Vector<T>::operator+=(const Vector<T>& obj) {

	if (m_size + obj.m_size > m_capacity) {
		reserve(2 * (m_size + obj.m_size));
	}

	for (unsigned i = 0; i < obj.m_size; i++) {
		*this += obj[i];
	}
	return *this;
}

template<class T>
inline bool Vector<T>::empy()const {

	return m_size == 0;
}

template<class T>
inline void Vector<T>::push_back(const T& item) {

	if (m_size + 1 >= m_capacity) {
		reserve(2 * m_size);
	}

	m_data[m_size] = item;
	++m_size;
}

template<class T>
inline void Vector<T>::pop_back() {

	--m_size;
}

template<class T>
inline void Vector<T>::insert(unsigned index, const T& item) {

	if (index < 0 || index >= m_size) {
		std::cout << "\nInvalid index!\n";
		return;
	}

	for (unsigned i = m_size; i > index; --i) {
		m_data[i] = m_data[i - 1];
	}

	m_data[index] = item;
	++m_size;
}

template<class T>
inline void Vector<T>::erase(unsigned index) {

	if (index < 0 || index >= m_size) {
		std::cout << "\nInvalid index!\n";
		return;
	}

	for (unsigned i = index; i < m_size - 1; ++i) {
		m_data[i] = m_data[i + 1];
	}

	//	m_data[m_size] = nullptr;
	--m_size;
}

template<class T>
inline void Vector<T>::reserve(unsigned capacity) {

	if (capacity <= 0 || capacity >= m_capacity) {
		std::cout << "\nInvalid capacity!\n";
		return;
	}

	m_capacity = capacity;
	//if (m_capacity < m_size) {
	//	m_size = m_capacity;
	//}

	T* data = new T[m_capacity];
	for (unsigned i = 0; i < m_size && i < m_capacity; ++i) {
		data[i] = m_data[i];
	}

	delete[] m_data;
	m_data = data;
}

template<class T>
inline void Vector<T>::swap(Vector<T>& data) {

	Vector<T> temp(*this);
	*this = data;
	data  = temp;
}

template<class T>
inline T& Vector<T>::at(unsigned index) {

	try {
		return m_data[index];
	}
	catch (std::out_of_range& e) {
		std::cerr << e.what() << std::endl;
		/*if (index < 0 || index > m_size) {
			throw std::out_of_range("Invalid index!");
		}*/
	}
}

template<class T>
inline const T& Vector<T>::at(unsigned index)const {

	try {
		return m_data[index];
	}
	catch (std::out_of_range& e) {
		std::cerr << e.what() << std::endl;
		/*if (index < 0 || index > m_size) {
			throw std::out_of_range("Invalid index!");
		}*/
	}
}

template<class T>
inline T& Vector<T>::front() {

	return at(0);
}

template<class T>
inline const T& Vector<T>::front()const {

	return at(0);
}

template<class T>
inline T& Vector<T>::back() {

	return at(m_size - 1);
}

template<class T>
inline const T& Vector<T>::back()const {

	return at(m_size - 1);
}

template<class T>
inline unsigned Vector<T>::size()const {

	return m_size;
}

template<class T>
inline unsigned Vector<T>::capacity()const {

	return m_capacity;
}

template<class T>
inline T* Vector<T>::data() {

	return m_data;
}

template<class T>
inline const T* Vector<T>::data()const {

	return m_data;
}

template<class T>
inline std::ostream& operator<<(std::ostream& out, const Vector<T>& obj) {

	for (unsigned i = 0; i < obj.m_size; ++i) {
		out << obj.m_data[i] << std::endl;
	}
	return out;
}

template<class T>
inline std::istream& operator>>(std::istream& in, Vector<T>& obj) {

	unsigned size;
	in >> size;
	if (size < 0) {
		obj.m_size = 0;
	} else {
		obj.m_size = size;
	}

	obj.m_capacity = 2 * obj.m_size;
	if (obj.m_capacity == 0) {
		obj.m_capacity = VECTOR_CAPACITY; 
	}

	obj.m_data = new T[obj.m_capacity];
	for (unsigned i = 0; i < obj.m_size; ++i) {
		in >> obj.m_data;
	}

	return in;
}

template<class T>
inline void Vector<T>::copy(const Vector<T>& obj) {

	m_capacity = obj.m_capacity;
	m_size     = obj.m_size;

	m_data = new T[m_capacity];
	for (unsigned i = 0; i < obj.m_size && i < m_capacity; ++i) {
		m_data[i] = obj.m_data[i];
	}
}

template<class T>
inline void Vector<T>::free() {

	delete[] m_data;
	m_data = nullptr;
}

#endif //__VECTOR_H__