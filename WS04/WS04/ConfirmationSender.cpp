// Student
// Name: Mayara Rodrigues
// Student Number: 118758200
// Student ID: mrodrigues21
// Date: 2021-10-16
// I have done all the coding by myselfand only copied the code that my professor provided to complete my
// workshopsand assignments, and the references posted on WS assignment. 

#include "ConfirmationSender.h"

using namespace std;

namespace sdds{
	//Copy Constructor
	ConfirmationSender::ConfirmationSender(const ConfirmationSender& copyConst){
		//std::cout << "ConfirmationSender Copy Constructor" << "\n";
		*this = copyConst;
	}
	//Copy Assignment 
	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& copyAssig){
		//std::cout << "ConfirmationSender operator=" << "\n";

		//check for self assignemnt
		if (this != &copyAssig){
			//shallow copy
			this->m_noConfirReserv = copyAssig.m_noConfirReserv;

			//clean-up
			delete[] m_Reserptr;
			m_Reserptr = nullptr;

			//allocate memory
			m_Reserptr = new const Reservation*[m_noConfirReserv];

			//deep copy
			for (auto i = 0u; i < m_noConfirReserv; ++i){
				this->m_Reserptr[i] = copyAssig.m_Reserptr[i];
			}
		}
		return *this;
	}
	//Move Constructor
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& moveConst)noexcept{
		//std::cout << "ConfirmationSender Move Construtor" << "\n";
		*this = std::move(moveConst);
	}
	//Move Assignment
	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& moveAssig)noexcept{
		//std::cout << "ConfirmationSender Move Assign" << "\n";
		//check for self assignemnt
		if (this != &moveAssig){
			this->m_noConfirReserv = moveAssig.m_noConfirReserv;
			moveAssig.m_noConfirReserv = 0;

			//clean-up
			delete[] m_Reserptr;
			m_Reserptr = nullptr;

			//move the resource from parameter inter current
				this->m_Reserptr = moveAssig.m_Reserptr;
				moveAssig.m_Reserptr = nullptr;
		}
		return *this;
	}
	//Destructor
	ConfirmationSender::~ConfirmationSender(){
		//std::cout << "ConfirmationSender Destructor" << "\n";
		delete[] m_Reserptr;
		m_Reserptr = nullptr;
	}
	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res){
		//std::cout << "ConfirmationSender operator+=" << "\n";
		bool check = false;

		//compare if the rest exists into the Confirmation array
		for(auto i = 0u ; i < m_noConfirReserv && !check; ++i){
			if (m_Reserptr[i] == &res){
				check = true;
			}
		}
		//if not exists,put the rest into the array
		if (!check){
			// create a new array to "resize" the Reservation array
			const Reservation** addReserv = new const Reservation*[m_noConfirReserv + 1u];
			//add the reservation into a new array
			if (m_Reserptr != nullptr){
				for (auto i = 0u; i < m_noConfirReserv; ++i)
				addReserv[i] = m_Reserptr[i]; 
			}
			//add the rest register
			addReserv[m_noConfirReserv] = &res;


			//clean up the *this array
			if (m_Reserptr){
				delete[] m_Reserptr;
				m_Reserptr = nullptr;
			}

				m_Reserptr = addReserv;
			m_noConfirReserv++;

		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res){
		//std::cout << "ConfirmationSender operator-=" << "\n";
		//compare if the rest exists into the Confirmation array
		for (auto i = 0u ; i < m_noConfirReserv; ++i){
			if (m_Reserptr[i] == &res){
				m_Reserptr[i] = nullptr;
				m_noConfirReserv--;
			}
		}
		return *this;
	}

	//friend helper
	std::ostream& operator<<(std::ostream& ost, const ConfirmationSender& confirSender){
		ost << "--------------------------" << "\n";
		ost << "Confirmations to Send" << "\n";
		ost << "--------------------------" << "\n";

		if (confirSender.m_noConfirReserv == 0){
			ost << "There are no confirmations to send!" << "\n";
		}
		else{
			for (auto i = 0u ; i < confirSender.m_noConfirReserv; i++){
				//to prevent the nullptr element after operator-=
				if(confirSender.m_Reserptr[i] != nullptr)
				ost << *confirSender.m_Reserptr[i];
			}
		}
		ost << "--------------------------" << "\n";
		return ost;
	}
}