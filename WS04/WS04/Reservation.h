// Student
// Name: Mayara Rodrigues
// Student Number: 118758200
// Student ID: mrodrigues21
// Date: 2021-10-16
// I have done all the coding by myselfand only copied the code that my professor provided to complete my
// workshopsand assignments, and the references posted on WS assignment. 

#ifndef SDDS_RESERVATION_H__
#define SDDS_RESERVATION_H__

#include<iostream>
#include <string>

namespace sdds{
	class Reservation{
		std::string m_idReserv = {};
		std::string m_nameReserv = {};
		std::string m_emailReserv = {};
		std::string m_noPeopleReserv = {};
		int m_dayReserv = 0;
		int m_hourReserv = 0;

	public:
		Reservation(){};
		void update(int day, int time);
		Reservation(const std::string& res);

		//friend helper
		friend std::ostream& operator<<(std::ostream& ost, const Reservation& reserv);
	};
}

#endif // !SDDS_RESERVATION_H__