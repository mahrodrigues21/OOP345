// Workshop 3 - Templates
// Name: Mayara Rodrigues
// Student Number: 118758200
// Student ID: mrodrigues21
// Date: 2021-10-06
// I have done all the coding by myselfand only copied the code that my professor provided to complete my
// workshopsand assignments, and the references posted on WS assignment. I research these website https://www.geeksforgeeks.org/templates-cpp/, http://www.cplusplus.com/doc/oldtutorial/templates/ and https://stackoverflow.com/questions/20488579/why-we-declare-static-variable-in-a-class-the-definition-in-outside-of-the-cla

#ifndef SDDS_PAIR_H__
#define SDDS_PAIR_H__

#include <iostream>

namespace sdds
{
	template<typename V, typename K>
	class Pair
	{
		V m_typeValue;
		K m_typeKey;

	public:
		Pair() : m_typeValue(), m_typeKey(){};
		Pair(const K& key, const V& value);
		const V& value()const;
		const K& key()const;

		//virtual to allow polymorphism
		virtual void display(std::ostream& os) const;
	};

	// Functions definition initialized members
	//copy the paramenter into the member
	template<typename V, typename K>
	Pair<V, K>::Pair(const K& key, const V& value) {
		m_typeKey = key;
		m_typeValue = value;
	};

	//return V value
	template<typename V, typename K>
	const V& Pair<V, K>::value()const {
		return m_typeValue;
	};

	//return K value
	template<typename V, typename K>
	const K& Pair<V, K>::key()const {
		return m_typeKey;
	};

	//display key and value
	template<typename V, typename K>
	void Pair<V, K>::display(std::ostream& os)const {
		os << key();
		os << " : ";
		os << value() << "\n";
	};
	//Free helper pass pair to display function
	template<typename V, typename K>
	std::ostream& operator<<(std::ostream& os, const Pair<V, K>& pair) {
		pair.display(os);
		return os;
	}
}
#endif // !SDDS_PAIR_H__



