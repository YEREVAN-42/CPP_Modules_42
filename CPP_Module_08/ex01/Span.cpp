#include "Span.h"
#include <iostream>
Span::~Span() { mspanVector.clear(); }
Span::Span() : mspanVector(0) {	}
Span::Span(std::size_t N) : mspanVector(N) { mspanVector.clear(); }
Span::Span(const Span& other) : mspanVector(other.mspanVector) { mspanVector.clear(); }

Span& Span::operator=(const Span& other)
{
	if (this == &other) {
		return *this;
	}
	mspanVector.clear();
	mspanVector.reserve(other.mspanVector.capacity());
	mspanVector = other.mspanVector;
	return *this;
}

void Span::addNumber(std::size_t N)
{
	if (mspanVector.size() == mspanVector.capacity()) {
		throw std::out_of_range("Span is full. Cannot add more elements.");
	}
	mspanVector.push_back(N);
}

void Span::addNumber(iterator begin, iterator end)
{
	if (mspanVector.size() == mspanVector.capacity()) {
		throw std::out_of_range("Span is full. Cannot add more elements.");
	} else if (end < begin) {
		throw std::invalid_argument("Invalid arguments.");
	} else if (static_cast<std::size_t>(std::distance(begin, end))
		> mspanVector.capacity() - mspanVector.size()) {
		throw std::out_of_range("Not enough space in Span to add all numbers.");
	}
	mspanVector.insert(mspanVector.end(), begin, end);
}

std::size_t Span::longestSpan()
{
	if (mspanVector.size() < 2) {
		throw std::logic_error("Cannot find longist span with less than 2 elements.");
	}
	std::vector<int> sortVec(mspanVector);
	std::sort(sortVec.begin(), sortVec.end());
	return static_cast<std::size_t>(std::abs(sortVec.back() - sortVec.front()));
}

std::size_t Span::shortestSpan()
{
	if (mspanVector.size() < 2) {
		throw std::logic_error("Cannot find shortest span with less than 2 elements.");
	}
	std::vector<int> sortVec(mspanVector);
	std::sort(sortVec.begin(), sortVec.end());
	int shortestSpan = std::abs(sortVec[1] - sortVec[0]);
	for (std::size_t i = 2; i < sortVec.size(); ++i) {
		int shortest = std::abs(sortVec[i] - sortVec[i - 1]);
		if (shortest < shortestSpan) {
			shortestSpan = shortest;
		}
	}
	return static_cast<std::size_t>(shortestSpan);
}
