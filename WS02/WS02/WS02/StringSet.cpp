// Workshop 2 - Copy and Move Semantics
// Name: Mayara Rodrigues
// Student Number: 118758200
// Student ID: mrodrigues21
// Date: 2021-09-28
// I have done all the coding by myselfand only copied the code that my professor provided to complete my
// workshopsand assignments, and the references posted on WS assignment. I also utilize my files for my
// previuos WS on the last term (WS06 - TextFile).

#include <fstream>
#include <iostream>
#include <string>
#include "StringSet.h"

using namespace std;

namespace sdds {
	StringSet::StringSet(const char* fileName) {
		int n = 0;
		std::ifstream fileIn(fileName);

		//check if the file failed
		if (fileIn.is_open() == false)
		{
			std::cout << "Cannot open file [" << fileName << "]\n";
			m_nString = 0;
			m_string = nullptr;
		}
		else {
			//count the number of strings and storage the value in the member
			string temp;
			while (getline(fileIn, temp, ' '))
				m_nString++;

			//Return to position 0 of the file, and  storage thte file content to the member
			//Clear the variable first than restart the file content.
			fileIn.clear();
			fileIn.seekg(0, std::ios_base::beg);

			//allocates memory for the number of strings in the array
			m_string = new string[m_nString];

			//re-reads the file and loads the strings into the array.
			string copy;
			while (getline(fileIn, copy,' '))
				{
				m_string[n] = copy;
					n ++;
				} m_nString = n;

			fileIn.close();

		}
	}
	//deallocate memory
	StringSet::~StringSet() {
		//std::cout << "~StringSet()" << "\n";
		delete[] m_string;
	}
	//copy constructor
    StringSet::StringSet(const StringSet& copyConst){
		//std::cout << "StringSet(const StringSet& copyConst)" << "\n";
		*this = copyConst;
	}
	//copy assignment
	StringSet& StringSet::operator=(const StringSet& copyAssig) {
		//std::cout << "StringSet::operator=(const StringSet& copyAssig) " << "\n";
		//check for self assignment
		if (this != &copyAssig) {
			//shallow copy
			this->m_nString = copyAssig.m_nString;

			//clean-up
			delete[] m_string;

			//allocate memory
			this->m_string = new string[copyAssig.m_nString];

			//deep copy
			for (auto i = 0u; i < copyAssig.m_nString; i++) {
				this->m_string[i] = copyAssig.m_string[i];
			}
		} return *this;
	}

	//move constructor this function doesn't generation excepts
	// move the source to current instance
	StringSet::StringSet(StringSet&& moveConst) noexcept {
		//std::cout << "StringSet(StringSet&& moveConst) noexcept" << "\n";
		*this = std::move(moveConst);
	}
	//move assignment this function doesn't generation excepts
	StringSet& StringSet::operator=(StringSet&& moveAssig) noexcept {
		//std::cout << "StringSet::operator=(StringSet&& moveAssig) noexcept " << "\n";
		//check for sel assignment
		if (this != &moveAssig) {
			//shallow copy
			this->m_nString = moveAssig.m_nString;
			moveAssig.m_nString = 0;

			//clean-up
			delete[] m_string;

			//move the resource from parameter into current 
			this->m_string = moveAssig.m_string;
			moveAssig.m_string = nullptr;
		}
		return *this;
	}

	//retrieves the length of the data resource
	size_t StringSet::size() const {
		//std::cout << "size()" << "\n";
		return m_nString;
	}

	std::string StringSet::operator[](size_t index) const {
		//std::cout << "StringSet::operator[](size_t index)" << "\n";
		string m_copyString;

		if ((index >= 0) && (index < m_nString)) {
			 return m_copyString = m_string[index];
		}
		else {
			return m_copyString;
		}
	}
}