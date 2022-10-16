// Student
// Name: Mayara Rodrigues
// Student Number: 118758200
// Student ID: mrodrigues21
// Date: 2021-10-16
// I have done all the coding by myselfand only copied the code that my professor provided to complete my
// workshopsand assignments, and the references posted on WS assignment. 


#include "Restaurant.h"
#include "Reservation.h"

using namespace std;

namespace sdds{
	Restaurant::Restaurant(const Reservation* reservations[], size_t cnt){
		m_nolistReserv = cnt;
		m_listReserv = new Reservation[m_nolistReserv];

		for (auto i = 0u; i < m_nolistReserv; i++){
			m_listReserv[i] = *reservations[i];
		}
	}
	size_t Restaurant::size() const{
		return m_nolistReserv;
	}
	//Copy Constructor
	Restaurant::Restaurant(const Restaurant& copyConst){
		//std::cout << "Restaurant Copu Const" << "\n";
		*this = copyConst;
	}
	//Copy Assignment 
	Restaurant& Restaurant::operator=(const Restaurant& copyAssig){
		//std::cout << "Restaurant Copy Assign" << "\n";
		//check for self assignment
		if (this != &copyAssig)
		{
			//shallow copy
			this->m_nolistReserv = copyAssig.m_nolistReserv;

			//clean-up
			delete[] m_listReserv;
			m_listReserv = nullptr;

			//allocate memory
			m_listReserv = new Reservation[m_nolistReserv];

			//deep copy
			for (auto i = 0u; i < m_nolistReserv; i++){
				m_listReserv[i] = copyAssig.m_listReserv[i];
			}
		} return *this;
	}
	//Move Constructor
	Restaurant::Restaurant(Restaurant&& moveConst)noexcept{
		//std::cout << "Restaurnat Move Constr" << "\n";
		*this = std::move(moveConst);
	}
	//Move Assignment
	Restaurant& Restaurant::operator=(Restaurant&& moveAssig)noexcept{
		//std::cout << "Restaurant Move Assig" << "\n";
		//check for self assignment
		if (this != &moveAssig){
			//shallow copy
			this->m_nolistReserv = moveAssig.m_nolistReserv;
			moveAssig.m_nolistReserv = 0;

			//clean up
			delete[] m_listReserv;

			// move the resource from parameter into current object
			this->m_listReserv = moveAssig.m_listReserv;
			moveAssig.m_listReserv = {};
		}
		return *this;
	}
	//Destructor
	Restaurant::~Restaurant(){
		delete[] m_listReserv;
	}

	//friend helper
	std::ostream& operator<<(std::ostream& ost, const Restaurant& rest){
		static int counter = 0;

		ost << "--------------------------" << "\n";
		//counter increments before shows
		ost << "Fancy Restaurant ("<< ++counter <<")" << "\n";
		ost << "--------------------------" << "\n";

		if (rest.m_nolistReserv == 0){
			ost << "This restaurant is empty!" << "\n";
		}
		else{
			for (auto i = 0u ; i < rest.m_nolistReserv; i++){
				ost << rest.m_listReserv[i];
			}
		}

		ost << "--------------------------" << "\n";

		return ost;
	}

}
