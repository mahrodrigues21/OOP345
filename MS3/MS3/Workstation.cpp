// Name: Mayara Rodrigues
// Seneca Student ID: 118758200
// Seneca email: mrodrigues21@gmail.com	
// Date of completion: 12-04-2021
// PROJETCT - MS03
// I confirm that I am the only author of this file and the content was created entirely by me, based on my lasts WSs done and the MS01 and MS02.
//As reference https://www.cplusplus.com/reference/deque/deque/

#include <deque>
#include <iomanip>
#include <iostream>
#include "Workstation.h"

using namespace std;

namespace sdds
{

	//queues global variables double-ended queues of CustomerOrder
	std::deque<CustomerOrder> pending;     //orders onto assemblyline at first station
	std::deque<CustomerOrder> completed;   //orders removed from last station
	std::deque<CustomerOrder> incomplete; //orders removed from last station not filled

	//modify fills order, if there is a CustomerOrder, otherwise does nothing
	void Workstation::fill(std::ostream& os)
	{
		//m_orders is empty does nothing
		if (!m_orders.empty())
			//if not, fill at the front of the current object
			m_orders.front().fillItem(*this, os);
	}
	//move the order to next station
	bool Workstation::attemptToMoveOrder()
	{
		//return value of the function
		bool moveStatus = false;

		//check if the order has items != empty
		if (!m_orders.empty())
		{
			//get itemName and check if it's filled
			if (m_orders.front().isItemFilled(getItemName()))
			{
				//check next Station available
				if (m_pNextStation)
					*m_pNextStation += std::move(m_orders.front());
				//if order cannot be filled, get this information from CustomerOrder::isFilled()
				else if (!m_orders.front().isFilled())
					//if order cannot be filled, moved to incompleted queue
					incomplete.push_back(std::move(m_orders.front()));

				//no needs to assembly line moved to completed queue
				else completed.push_back(std::move(m_orders.front()));

				//order was moved at this point
				moveStatus = true;
				m_orders.pop_front();
			}
			//if no item in the Station(inventory)
			else if (this->getQuantity() <= 0)
			{
				//check next Station available
				if (m_pNextStation)
					//if exist move the order to there
					*m_pNextStation += std::move(m_orders.front());
				else
					//if order cannot be filled, moved to incompleted queue
					incomplete.push_back(std::move(m_orders.front()));

				//order was moved at this point
				moveStatus = true;
				m_orders.pop_front();
			}
		}
		return moveStatus;
	}
	//modify the address of the Workstation pointer m_pNextStation
	void Workstation::setNextStation(Workstation* station)
	{
		//pointed nextStation to station???
		m_pNextStation = station;
	}
	//return the next Workstation
	Workstation* Workstation::getNextStation() const
	{
		return m_pNextStation;
	}
	//insert the name of Item in the current object
	void Workstation::display(std::ostream& os) const
	{
		if (m_pNextStation)
			os << getItemName() << " --> " << m_pNextStation->getItemName() << '\n';
		else
			os << getItemName() << " --> " << "End of Line\n";
	}
	//moves CustomerOrder to back the queue
	Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
	{
		//push back the order from queue;
		m_orders.push_back(move(newOrder));

		return *this;
	}
}