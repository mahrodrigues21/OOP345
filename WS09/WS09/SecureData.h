// Workshop 9 - Multi-Threading
// SecureData.cpp
// Student Information
// Name: Mayara Rodrigues
// Student Number: 118758200
// Student ID: mrodrigues21
// Date: 2021-11-28
// WS08
//https://en.cppreference.com/w/cpp/utility/functional/bind
//https://stackoverflow.com/questions/5420317/reading-and-writing-binary-file
//https://www.geeksforgeeks.org/bind-function-placeholders-c/

#ifndef W9_SECUREDATA_H
#define W9_SECUREDATA_H

#include <iostream>

namespace w9
{
	class Cryptor {
	public:
		char operator()(char in, char key) const {
			return in ^ key;
		}
	};
	void converter(char*, char, int, const Cryptor&);

	class SecureData {
		char* text;
		std::ostream* ofs;
		int nbytes;
		bool encoded;
		void code(char);
	public:
		SecureData(const char*, char, std::ostream*);
		SecureData(const SecureData&) = delete;
		SecureData& operator=(const SecureData&) = delete;
		~SecureData();
		void display(std::ostream&) const;
		void backup(const char*);
		void restore(const char*, char);
	};
	std::ostream& operator<<(std::ostream&, const SecureData&);
}
#endif