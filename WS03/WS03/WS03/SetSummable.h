// Workshop 3 - Templates
// Name: Mayara Rodrigues
// Student Number: 118758200
// Student ID: mrodrigues21
// Date: 2021-10-06
// I have done all the coding by myselfand only copied the code that my professor provided to complete my
// workshopsand assignments, and the references posted on WS assignment. I research these website https://www.geeksforgeeks.org/templates-cpp/, http://www.cplusplus.com/doc/oldtutorial/templates/ and https://stackoverflow.com/questions/20488579/why-we-declare-static-variable-in-a-class-the-definition-in-outside-of-the-cla

#ifndef SDDS_SETSUMMABLE_H__
#define SDDS_SETSUMMABLE_H__

//base class
#include <string>
#include "Set.h"

namespace sdds {
	template<size_t N, typename T>
	class SetSummable : public Set<N, T> {
	public:
		T accumulate(const std::string& filter) const;
	};

	//Function definition
	template<size_t N, typename T>
	T SetSummable< N, T>::accumulate(const std::string& filter) const {
		//std::cout << "T SetSummable< N, T>::accumulate(const std::string& filter) const" << "\n";
		T accumulatorEle(filter);
		for (auto i = 0u; i < this->size(); i++) {
			if (accumulatorEle.isCompatibleWith(this->get(i)))
				accumulatorEle += this->get(i);
		}
		return accumulatorEle;
	}
}
#endif // !SDDS_SETSUMMABLE_H__




