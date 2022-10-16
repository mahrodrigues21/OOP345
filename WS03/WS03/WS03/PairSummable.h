// Workshop 3 - Templates
// Name: Mayara Rodrigues
// Student Number: 118758200
// Student ID: mrodrigues21
// Date: 2021-10-06
// I have done all the coding by myselfand only copied the code that my professor provided to complete my
// workshopsand assignments, and the references posted on WS assignment. I research these website https://www.geeksforgeeks.org/templates-cpp/, http://www.cplusplus.com/doc/oldtutorial/templates/ and https://stackoverflow.com/questions/20488579/why-we-declare-static-variable-in-a-class-the-definition-in-outside-of-the-cla

#ifndef SSDS_PAIRSUMMABLE_H__
#define SSDS_PAIRSUMMABLE_H__

//base class
#include <iostream>
#include <iomanip>
#include <string>
#include "Pair.h"

namespace sdds
{
	template<typename V, typename K>
	class PairSummable : public Pair<V, K> {
		     static V m_initialValue;
		static size_t m_minField;
	
	public:
		//default constructor, calls base class Pair
		PairSummable() : Pair<V, K>() {};
		PairSummable(const K& key, const V& value = m_initialValue);
		//compare key between parameter object and current object
		bool isCompatibleWith(const PairSummable<V, K>& b);
		//overload receive a parameter reference object and then add to a reference of current object
		PairSummable<V, K>& operator+=(const PairSummable& pairS);
		//override
		void display(std::ostream& os) const override;
	};

	//Definition according to help of the Prof Cornel Barna. Static member need to be initilized out of the class declared.
	template<typename V, typename K>
	V PairSummable< V, K>::m_initialValue {};
	template<typename V, typename K>
	size_t PairSummable< V, K>::m_minField{ 0u };

	//Function definition
	//Calls the function of base class to update or add value of its members and then check
	template<typename V, typename K>
	PairSummable<V, K>::PairSummable(const K& key, const V& value) : Pair<V, K>(key, value) {
		//std::cout << "PairSummable<V, K>::PairSummable(const K& key, const V& value ) : Pair<V, K>(key, value)" << "\n";
	    //check if the key size is different
		if (m_minField < key.size())
			m_minField = key.size();
	}

	template<typename V, typename K>
	bool PairSummable<V, K>::isCompatibleWith(const PairSummable<V, K>& b) {
		//std::cout << "bool PairSummable<V, K>::isCompatibleWith(const PairSummable<V, K>& b)" << "\n";
		bool check = (b.key() == this->key());
		return check;
	};

	template<typename V, typename K>
	PairSummable<V, K>& PairSummable<V, K>::operator+=(const PairSummable<V, K>& pairS) {
		//std::cout << "PairSummable<V, K>& PairSummable<V, K>::operator+=(const PairSummable& pairS)" << "\n";
		return *this = PairSummable(this->key(), this->value() + pairS.value());
	};

	template<typename V, typename K>
	void PairSummable<V, K>::display(std::ostream& os) const {
		//std::cout << "void PairSummable<V, K>::display(std::ostream& os) const" << "\n";
		os << std::left;
		os << std::setw(m_minField);
		Pair<V, K>::display(os);
		os << std::right;
	};

	//specialization, no template, V = string, K= string
	template<>
	PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+=(const PairSummable<std::string, std::string>& pairS) {
		//std::cout << "PairSummable<std::string, std::string>& " << "\n";
		if (this->value() == "") 
			return *this = PairSummable(this->key(), pairS.value());
		else
			return *this = PairSummable(this->key(), this->value() + ", " + pairS.value());
	};
}

#endif // !SSDS_PAIRSUMMABLE_H__


