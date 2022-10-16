// Workshop 3 - Templates
// Name: Mayara Rodrigues
// Student Number: 118758200
// Student ID: mrodrigues21
// Date: 2021-10-06
// I have done all the coding by myselfand only copied the code that my professor provided to complete my
// workshopsand assignments, and the references posted on WS assignment.
// I have done all the coding by myselfand only copied the code that my professor provided to complete my
// workshopsand assignments, and the references posted on WS assignment. I research these website https://www.geeksforgeeks.org/templates-cpp/, http://www.cplusplus.com/doc/oldtutorial/templates/ and https://stackoverflow.com/questions/20488579/why-we-declare-static-variable-in-a-class-the-definition-in-outside-of-the-cla

#ifndef  SDDS_SET_H__
#define  SDDS_SET_H__

#include <iostream>

namespace sdds {
	template <size_t N, typename T>
	class Set
	{
		     T m_arrSet[N]{};
		size_t m_noElement = 0u;

	public:
		size_t size()const;
		const T& get(size_t idx) const;
		void operator+=(const T& item);
	};

	//Function definition
	//return number of element
	template <size_t N, typename T>
	size_t Set<N, T>::size()const {
		return m_noElement;
	}
	//return a specific element of array
	template <size_t N, typename T>
	const T& Set<N, T>::get(size_t idx) const {
		return m_arrSet[idx];
	}
	//add the a new element into array, if the array has capacity
	template <size_t N, typename T>
	void Set<N, T>::operator+=(const T& item) {
		if (m_noElement < N) {
			m_arrSet[m_noElement] = item;
			m_noElement++;
		}
	}
}
#endif // ! SDDS_SET_H__



