// Name: Mayara Rodrigues
// Seneca Student ID: 118758200
// Seneca email: mrodrigues21@gmail.com	
// Date of completion: 12-04-2021
// PROJETCT - MS03
// I confirm that I am the only author of this file and the content was created entirely by me, based on my lasts WSs done and the MS01 and MS02.
//As reference https://www.cplusplus.com/reference/deque/deque/

#ifndef SDDS_WORKSTATION__H
#define SDDS_WORKSTATION__H

#include <deque>
#include "CustomerOrder.h"

namespace sdds
{
	//queues global variables double-ended queues of CustomerOrder
	extern std::deque<CustomerOrder> pending;     //orders onto assemblyline at first station
	extern std::deque<CustomerOrder> completed;   //orders removed from last station
	extern std::deque<CustomerOrder> incomplete; //orders removed from last station not filled

	//Workstation is a kind of Station
	class Workstation : public Station
	{
		//instance variable
		std::deque<CustomerOrder> m_orders; //orders placed on station
		Workstation* m_pNextStation{};      //pointer to next Workstation

	public:
		//*****the Workstation object cannot be copied or moved
		//copy constr
		Workstation(const Workstation&) = delete;
		//copy assignment
		Workstation& operator=(const Workstation&) = delete;
		//move constr
		Workstation(Workstation&&) = delete;
		//move assignment
		Workstation& operator=(Workstation&&) = delete;

		//custom 1-arg constructor, receives a string and pass it to Station constructor
		Workstation(const std::string& receive) : Station(receive)
		{
		};
		//modify fills order, if there is a CustomerOrder, otherwise does nothing
		void fill(std::ostream& os);
		//move the order to next station
		bool attemptToMoveOrder();
		//modify the address of the Workstation pointer m_pNextStation
		void setNextStation(Workstation* station);
		//return the next Workstation
		Workstation* getNextStation() const;
		//insert the name of Item in the current object
		void display(std::ostream& os) const;
		//moves CustomerOrder to back the queue
		Workstation& operator+=(CustomerOrder&& newOrder);
	};
}

#endif // !SDDS_WORKSTATION__H

