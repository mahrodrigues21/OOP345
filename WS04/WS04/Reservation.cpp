// Student
// Name: Mayara Rodrigues
// Student Number: 118758200
// Student ID: mrodrigues21
// Date: 2021-10-16
// I have done all the coding by myselfand only copied the code that my professor provided to complete my
// workshopsand assignments, and the references posted on WS assignment. 

#include <string>
#include <iostream>
#include <iomanip>
#include "Reservation.h"

using namespace std;

namespace sdds
{
	void Reservation::update(int day, int time)
	{
		m_dayReserv = day;
		m_hourReserv = time;
	}
	Reservation::Reservation(const std::string& res)
	{
		std::string textReserv = res;
		std::string partMember = {};
		int pos = 0;

		//get reserva id
		//remove blank space in beginning of the string
		textReserv.erase(0, textReserv.find_first_not_of(" "));
		pos = textReserv.find(":");
		m_idReserv = textReserv.substr(0, pos);
		//remove blank space at the end of the string
		m_idReserv.erase(m_idReserv.find_last_not_of(" ") + 1);

		//get name		
		//remove the id got and the delimiter (:)
		textReserv.erase(0, pos + 1);
		//remove blank space in beginning of the string
		textReserv.erase(0, textReserv.find_first_not_of(" "));
		pos = textReserv.find(",");
		m_nameReserv = textReserv.substr(0, pos);
		//remove blank space at the end of the string
		m_nameReserv.erase(m_nameReserv.find_last_not_of(" ") + 1);

		//get email
		//remove blank space in beginning of the string
		textReserv.erase(0, pos + 1);
		textReserv.erase(0, textReserv.find_first_not_of(" "));
		pos = textReserv.find(",");
		m_emailReserv = textReserv.substr(0, pos);
		//remove blank space at the end of the string
		m_emailReserv.erase(m_emailReserv.find_last_not_of(" ") + 1);

		//get part size
		//remove blank space in beginning of the string
		textReserv.erase(0, pos + 1);
		textReserv.erase(0, textReserv.find_first_not_of(" "));
		pos = textReserv.find(",");
		m_noPeopleReserv = textReserv.substr(0, pos);
		//remove blank space at the end of the string
		m_noPeopleReserv.erase(m_noPeopleReserv.find_last_not_of(" ") + 1);

		//get part day
		//remove blank space in beginning of the string
		textReserv.erase(0, pos+ 1);
		textReserv.erase(0, textReserv.find_first_not_of(" "));
		pos = textReserv.find(",");
		m_dayReserv = std::stoi(textReserv.substr(0, pos));

		//get part day
		//remove blank space in beginning of the string
		textReserv.erase(0, pos + 1);
		textReserv.erase(0, textReserv.find_first_not_of(" "));
		pos = textReserv.find(",");
		m_hourReserv = std::stoi(textReserv.substr(0, pos));
	}
	std::ostream& operator<<(std::ostream& ost, const Reservation& reserv){
		ost << "Reservation " << std::setw(10) << reserv.m_idReserv << ": ";
		ost << std::setw(20) << reserv.m_nameReserv << "  ";
		ost << std::setw(20) << std::left << "<" + reserv.m_emailReserv + ">" << std::right << "    ";

		if (reserv.m_hourReserv >= 6 && reserv.m_hourReserv <= 9){
			ost << "Breakfast" << " on day " << reserv.m_dayReserv << " @ " << reserv.m_hourReserv;
			ost << ":00 for " << reserv.m_noPeopleReserv;
		}
		else if (reserv.m_hourReserv >= 11 && reserv.m_hourReserv <= 15){
			ost << "Lunch" << " on day " << reserv.m_dayReserv << " @ " << reserv.m_hourReserv;
			ost << ":00 for " << reserv.m_noPeopleReserv;
		}
		else if (reserv.m_hourReserv >= 17 && reserv.m_hourReserv <= 21){
			ost << "Dinner" << " on day " << reserv.m_dayReserv << " @ " << reserv.m_hourReserv;
			ost << ":00 for " << reserv.m_noPeopleReserv;
		}
		else{
			ost << "Drinks" << " on day " << reserv.m_dayReserv << " @ " << reserv.m_hourReserv;
			ost << ":00 for " << reserv.m_noPeopleReserv;
		}

		if (reserv.m_noPeopleReserv > "1")
			ost << " people." << "\n";
		else ost << " person." << "\n";

		return ost;
	}
}

