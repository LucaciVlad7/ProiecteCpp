#pragma once

#include "Locatar.h"

#include <cassert>
#include <iostream>
#include <vector>

void runAlltests();

template <typename MyVector>
MyVector testCopyIterate(MyVector v) {
	unsigned int suprafata = 0;
	for (auto el : v) {
		suprafata = el.getSuprafata();
	}
	string propr = "Vlad";
	string tip = "tip";
	Locatar lo{ 24, propr, 70, tip };
	v.push_back(lo);
	return v;
}

template <typename MyVector>
void addLocatar(MyVector& v, int cate) {
	for (unsigned int i = 0; i < cate; i++) {
		string propr = "propr";
		string tip = "tip";
		Locatar loc{ i, propr, i, tip};
		v.push_back(loc);
	}
}

template <typename MyVector>
void testCreateCopyAssign() {
	MyVector v;
	addLocatar(v, 100);
	assert(v.getSize() == 100);
	assert(v.get(50).getApartament() == 50);

	MyVector v2{ v };
	assert(v2.getSize() == 100);
	assert(v2.get(50).getApartament() == 50);

	MyVector v3;
	v3 = v;
	assert(v3.getSize() == 100);
	assert(v3.get(50).getApartament() == 50);

	auto v4 = testCopyIterate(v3);
	assert(v4.getSize() == 101);
	assert(v4.get(50).getApartament() == 50);
}

template <typename MyVector>
void testMoveConstrAssgnment() {
	std::vector<MyVector> v;

	v.push_back(MyVector{});

	v.insert(v.begin(), MyVector{});

	assert(v.size() == 2);

	MyVector v2;
	addLocatar(v2, 50);

	v2 = MyVector{};

	assert(v2.getSize() == 0);
}

template <typename MyVector>
void TestAllVector() {
	testCreateCopyAssign<MyVector>();
	testMoveConstrAssgnment<MyVector>();
	std::cout << "Vector passed!\n";
}