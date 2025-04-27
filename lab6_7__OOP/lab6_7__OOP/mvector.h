#pragma once

#define unt unsigned int
#include <iostream>
#include <ostream>
#include <stdexcept>
#define ALPHA 0.7
#define BETA 0.3

template <typename T>
class IteratorVectorT;

template<typename T>class mvector {
private:
	T* elems;
	unt size, capacity;
	void resize(unt newCapacity) {
		T* temp_elems = new T[newCapacity];
		for (unt i = 0;i < this->size;i++)
			temp_elems[i] = this->elems[i];
		delete[] this->elems;
		this->elems = temp_elems;
		this->capacity = newCapacity;
	}

public:
	//Constructor default
	mvector() : elems{ new T[1] }, size{ 0 }, capacity{ 1 } {};

	//Constructor prin atribuire =
	mvector& operator=(const mvector& other) {
		if (this != &other) {
			delete[] elems;
			size = other.size;
			capacity = other.capacity;
			elems = new T[capacity];
			for (unt i = 0;i < size;i++) {
				elems[i] = other.elems[i];
			}
		}
		return *this;
	}

	// Copy constructor
	mvector(const mvector& other) : size(other.size), capacity(other.capacity) {
		elems = new T[capacity];
		for (unt i = 0;i < size;i++)
			elems[i] = other.elems[i];
	}

	//Destructor
	~mvector() {
		delete[] this->elems;
	}

	T& operator[](unt index) {
		if (index < size)
			return elems[index];
		throw std::out_of_range("Index out of bounds");
	}

	void push_back(T elem) {
		if (this->size >= this->capacity * ALPHA)
			resize(this->capacity * 2);
		this->elems[this->size++] = elem;
	}

	void pop_back() {
		if (this->size > 0) {
			this->size--;
			if (this->size <= this->capacity * BETA && this->capacity > 1)
				resize(this->capacity / 2);
		}
	}

	void pop(const unt& index) {
		if (index >= this->size)
			return;
		for (unt j = index; j < this->size - 1; j++)
			this->elems[j] = this->elems[j + 1];
		this->size--;
		if (this->size <= this->capacity * BETA && this->capacity > 1)
			resize(this->capacity / 2);
	}

	T back() {
		return this->elems[this->size - 1];
	}

	T get(int index) {
		return this->elems[index];
	}

	unt getSize() const {
		return this->size;
	}

	friend class IteratorVectorT<T>;
	IteratorVectorT<T> begin();
	IteratorVectorT<T> end();
};

/*========================================*/
template<typename T>
IteratorVectorT<T> mvector<T>::begin()
{
	return IteratorVectorT<T>(*this);
}

template<typename T>
IteratorVectorT<T> mvector<T>::end()
{
	return IteratorVectorT<T>(*this, size);
}
template<typename T>
class IteratorVectorT {
private:
	const mvector<T>& v;
	int poz = 0;
public:
	IteratorVectorT(const mvector<T>& v) noexcept;
	IteratorVectorT(const mvector<T>& v, int poz)noexcept;
	bool valid()const;
	T& element() const;
	void next();
	T& operator*();
	IteratorVectorT& operator++();
	bool operator==(const IteratorVectorT& ot)noexcept;
	bool operator!=(const IteratorVectorT& ot)noexcept;
};

template<typename T>
IteratorVectorT<T>::IteratorVectorT(const mvector<T>& v) noexcept :v{ v } {}

template<typename T>
IteratorVectorT<T>::IteratorVectorT(const mvector<T>& v, int poz)noexcept : v{ v }, poz{ poz } {}

template<typename T>
bool IteratorVectorT<T>::valid()const {
	return poz < v.lg;
}

template<typename T>
T& IteratorVectorT<T>::element() const {
	return v.elems[poz];
}

template<typename T>
void IteratorVectorT<T>::next() {
	poz++;
}

template<typename T>
T& IteratorVectorT<T>::operator*() {
	return element();
}

template<typename T>
IteratorVectorT<T>& IteratorVectorT<T>::operator++() {
	next();
	return *this;
}

template<typename T>
bool IteratorVectorT<T>::operator==(const IteratorVectorT<T>& ot) noexcept {
	return poz == ot.poz;
}

template<typename T>
bool IteratorVectorT<T>::operator!=(const IteratorVectorT<T>& ot)noexcept {
	return !(*this == ot);
}