// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// Name: Mayara Rodrigues
// Student Number: 118758200
// Student ID: mrodrigues21
// Date: 2021/09/21

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cstring>
#include "event.h"

using namespace std;

//global variable g_sysClock non negative definition
unsigned int g_sysClock = 0;

namespace sdds {
	
	Event::Event() {
		//m_descriptEvent = nullptr;
		//m_timeEvent = 0;
		
		set();
	}
	void Event::display()const {
		static int count = 1;
		unsigned int hour = 0, min = 0, sec = 0;

		std::cout << setw(2);
		std::cout << setfill(' ');
		std::cout << count++ << ". ";

		if (m_descriptEvent != nullptr && m_descriptEvent[0] != '\0') {
			min = m_timeEvent / 60;
			hour = min / 60;
			sec = m_timeEvent % 60;

			std::cout << setfill('0');
			std::cout << setw(2);
			std::cout << hour << ":";
			std::cout << setfill('0');
			std::cout << setw(2);
			std::cout << int(min%60) << ":";
			std::cout << setfill('0');
			std::cout << setw(2);
			std::cout << sec << " => ";
			std::cout << m_descriptEvent << endl;
		}
		else
			std::cout << "| No Event |" << endl;

	}
	void Event::set(const char* description) {
		if (description != nullptr && description[0] != '\0'){
			delete[] m_descriptEvent;
			m_descriptEvent = nullptr;
			m_descriptEvent = new char[strlen(description) + 1];
			strcpy(m_descriptEvent, description);

			m_timeEvent = ::g_sysClock;
		}
		else{
			delete[] m_descriptEvent;
			m_descriptEvent = nullptr;
		}
	}
	Event::~Event() {
		delete[] m_descriptEvent;
		m_descriptEvent = nullptr;
	}

	Event::Event(const Event& copy) {
		if ((copy.m_descriptEvent != nullptr) && (copy.m_descriptEvent[0] != '\0')) {
			//m_descriptEvent = nullptr;
			m_descriptEvent = new char[strlen(copy.m_descriptEvent) + 1];
			strcpy(m_descriptEvent, copy.m_descriptEvent);
			m_timeEvent = copy.m_timeEvent;
		}
	}
	Event& Event::operator=(const Event& copy) {
		if ((m_descriptEvent != nullptr) && (m_descriptEvent[0] != '\0')) {
			delete[] m_descriptEvent;
			m_descriptEvent = nullptr;
		}

		if ((copy.m_descriptEvent != nullptr) && (copy.m_descriptEvent[0] != '\0')) {
			m_descriptEvent = new char[strlen(copy.m_descriptEvent) + 1];
			strcpy(m_descriptEvent, copy.m_descriptEvent);
			m_timeEvent = copy.m_timeEvent;
		}
		return *this;
	}
}
