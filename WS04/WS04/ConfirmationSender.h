// Student
// Name: Mayara Rodrigues
// Student Number: 118758200
// Student ID: mrodrigues21
// Date: 2021-10-16
// I have done all the coding by myselfand only copied the code that my professor provided to complete my
// workshopsand assignments, and the references posted on WS assignment. 

#ifndef SDDS_CONFIRMATIONSENDER_H__
#define SDDS_CONFIRMATIONSENDER_H__

#include "Reservation.h" 

namespace sdds{
	class ConfirmationSender{
		const Reservation** m_Reserptr{nullptr};
		size_t m_noConfirReserv{ 0u };

	public:
		ConfirmationSender(){};
		//Copy Constructor
		ConfirmationSender(const ConfirmationSender& copyConst);
		//Copy Assignment 
		ConfirmationSender& operator=(const ConfirmationSender& copyAssig);
		//Move Constructor
		ConfirmationSender(ConfirmationSender&& moveConst)noexcept;
		//Move Assignment
		ConfirmationSender& operator=(ConfirmationSender&& moveAssig)noexcept;
		//Destructor
		~ConfirmationSender();
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);

		//friend helper
		friend std::ostream& operator<<(std::ostream& ost, const ConfirmationSender& confirSender);
	};
}

#endif // !SDDS_CONFIRMATIONSENDER_H__


