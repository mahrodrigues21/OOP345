// Workshop 8 - Smart Pointers
// 2019/11 - Cornel
// Student Information
// Name: Mayara Rodrigues
// Student Number: 118758200
// Student ID: mrodrigues21
// Date: 2021-11-28
// WS08
// I have done all the coding by myselfand only copied the code that my professor provided to complete my
// workshopsand assignments, and the references posted on WS assignment. 
// I used this website as reference to complete my WS https://en.cppreference.com/book/intro/smart_pointers, https://www.cplusplus.com/reference/memory/unique_ptr/ and https://www.geeksforgeeks.org/smart-pointers-cpp/

#ifndef SDDS_LIST__H
#define SDDS_LIST__H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sdds
{
	template <typename T>
	class List{
		std::vector<T> list;
	public:
		//default constructor
		List(){}
		//on argument custom-constructor, receives a unmodifiable name of the file and read a file. Show a exception if the file doesn't open
		List(const char* fn){
			std::ifstream file(fn);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(fn) + std::string(" ***");
			while (file){
				T e;
				if (e.load(file))
					list.push_back(T(e));
			}
		}
		//size() returna non-negative number of the length of list
		size_t size() const{
			return list.size();
		}
		//an unmodifialbe operator, receives a non-negative value and return a dereferrence of template T
		const T& operator[](size_t i) const{
			return list[i];
		}

		// TODO: Overload the += operator with a smart pointer
		//       as a second operand.
		//overload operator+=, receives a address of T (const restrict as possible)
		void operator+=(const std::unique_ptr<T>& smartP){
			//moves the object received into the container
			list.push_back(*smartP);
		}

		// TODO: Overload the += operator with a raw pointer
		//       as a second operand.
		void operator+=(const T* rawP){
			list.push_back(*rawP);
		}

		void display(std::ostream& os) const
		{
			os << std::fixed << std::setprecision(2);
			for (auto& e : list)
				e.display(os);
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const List<T>& l)
	{
		l.display(os);
		return os;
	}
}
#endif //!SDDS_LIST__H