// Student
// Name: Mayara Rodrigues
// Student Number: 118758200
// Student ID: mrodrigues21
// Date: 2021-10-16
// I have done all the coding by myselfand only copied the code that my professor provided to complete my
// workshopsand assignments, and the references posted on WS assignment. 

#ifndef SDDS_RESTAURANT_H__
#define SDDS_RESTAURANT_H__

#include "Reservation.h" 

namespace sdds{
	class Restaurant{
		Reservation* m_listReserv{};
		size_t m_nolistReserv = 0;

	public:
		Restaurant(const Reservation* reservations[], size_t cnt);
		size_t size() const;
		//Copy Constructor
		Restaurant(const Restaurant& copyConst);
		//Copy Assignment 
		Restaurant& operator=(const Restaurant& copyAssig);
		//Move Constructor
		Restaurant(Restaurant&& moveConst)noexcept;
		//Move Assignment
		Restaurant& operator=(Restaurant&& moveAssig)noexcept;
		//Destructor
		~Restaurant();

		//friend helper
		friend std::ostream& operator<<(std::ostream& ost, const Restaurant& rest);
	};
	

}

#endif // !SDDS_RESTAURANT_H__

