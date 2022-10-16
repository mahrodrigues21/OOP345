// Workshop 2 - Copy and Move Semantics
// Name: Mayara Rodrigues
// Student Number: 118758200
// Student ID: mrodrigues21
// Date: 2021-09-28
// I have done all the coding by myselfand only copied the code that my professor provided to complete my
// workshopsand assignments, and the references posted on WS assignment. I also utilize my files for my
// previuos WS on the last term (WS06 - TextFile).

#ifndef SDDS_STRINGSET_H__
#define SDDS_STRINGSET_H__
#include <string>

namespace sdds {
	class StringSet {
		std::string* m_string{ nullptr };
		size_t m_nString = 0 ;

	public:
		//default constructor
		StringSet() {};
		//For read a file I used WS06 OOP244 as a base
		StringSet(const char* fileName);
		~StringSet();

		//copy constructor
		StringSet(const StringSet& copyConst);
		//copy assignment
		StringSet& operator=(const StringSet& copyAssig);

		//move constructor
		StringSet(StringSet&& moveConst)noexcept;
		//move assignment
		StringSet& operator=(StringSet&& moveAssig)noexcept;

		//retrieves the length of the data resource
		size_t size() const;
		
		std::string operator[](size_t index) const;

	};
}

#endif // !SDDS_STRINGSET_H__

