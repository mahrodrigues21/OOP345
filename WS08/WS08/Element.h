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

#ifndef SDDS_ELEMENT_H
#define SDDS_ELEMENT_H

#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>

extern const int FWC;
extern const int FWD;
extern const int FWP;

namespace sdds{

	struct Description{
		unsigned code;
		std::string desc;
		bool load(std::ifstream& f){
			f >> code >> desc;
			return f.good();
		}

		void display(std::ostream& os) const{
			os << std::setw(FWC) << code
				<< std::setw(FWD) << desc
				<< std::endl;
		}
	};

	struct Price{
		unsigned code;
		double price;
		bool load(std::ifstream& f){
			f >> code >> price;
			return f.good();
		}

		void display(std::ostream& os) const{
			os << std::setw(FWC) << code << std::setw(FWP)
				<< price << std::endl;
		}
	};

	struct Product{
		std::string m_desc{};
		double m_price{};
		int m_id{};
		static size_t idGenerator;
		// this variable is used to print trace messages from
		//     constructors/destructor
		static bool Trace;

		//default constructor
		Product(){
			m_id = ++Product::idGenerator;
			if (Product::Trace)
				std::cout << "    DC [" << m_id << "]" << std::endl;
		}

		//two argument custom-constructor, receives a dereferrence of string and a double as a parameter
		Product(const std::string& str, double p){
			this->m_desc = str;
			this->m_price = p;
			m_id = ++Product::idGenerator;
			if (Product::Trace)
				std::cout << "     C [" << m_id << "]" << std::endl;
		}
		//one argument custom-construror, receives a dereferrence of a Products
		Product(const Product& other){
			this->m_desc = other.m_desc;
			this->m_price = other.m_price;
			m_id = ++Product::idGenerator;
			if (Product::Trace)
				std::cout << "    CC [" << m_id
				<< "] from [" << other.m_id << "]"
				<< std::endl;
		}
		//destructor
		~Product(){
			if (Product::Trace)
				std::cout << "    ~D [" << m_id << "]" << std::endl;
		}

		// TODO: add a function here to validate the price
		void validate(){
			if (m_price < 0.0)
				throw std::string("*** Negative prices are invalid ***");
		}
		//display the content
		void display(std::ostream& os) const
		{
			os << std::setw(FWD) << m_desc
				<< std::setw(FWP) << m_price
				<< std::endl;
		}
	};
}
#endif