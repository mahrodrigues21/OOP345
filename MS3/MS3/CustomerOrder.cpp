// Name: Mayara Rodrigues
// Seneca Student ID: 118758200
// Seneca email: mrodrigues21@gmail.com	
// Date of completion: 12-04-2021
// PROJETCT - MS03
// I confirm that I am the only author of this file and the content was created entirely by me, based on my lasts WSs done and the MS01 and MS02.
//As reference https://www.cplusplus.com/reference/deque/deque/

#include <string>
#include <algorithm>
#include <iostream>
#include "CustomerOrder.h"
#include "Station.h"
#include "Utilities.h"
#include <iomanip>

using namespace std;

namespace sdds
{
	//define the class variable max width of a field. Used for display
	size_t CustomerOrder::m_widthField = 0u;

	//custom 1-arg constructor., receives a unmodifiable string.
	CustomerOrder::CustomerOrder(const std::string& src)
	{
		//Utilities object local definition to uses the extractToken
		Utilities objecU;
		//is necessary to pass all parameters that the functions needed
		size_t next_pos = 0u;
		bool more = true;

		try
		{
			m_name = objecU.extractToken(src, next_pos, more);
			m_product = objecU.extractToken(src, next_pos, more);
			//need to count each product that the customer ordered
			m_cntItem = (std::count(src.begin(), src.end(), objecU.getDelimiter())) - 1;

			//list of items making up the order
			if (m_cntItem)
				//define a new pointer to Item to input the customer's order
				// the length = m_cntItem
				m_lsItem = new Item * [m_cntItem];

			//more == true still has product
			//counter to add elements into the pointer
			for (size_t i = 0u; i < m_cntItem; ++i)
				m_lsItem[i] = new Item(objecU.extractToken(src, next_pos, more));

			//update m_widthField if it is less then token
			if (CustomerOrder::m_widthField < objecU.getFieldWidth())
				CustomerOrder::m_widthField = objecU.getFieldWidth();
		}
		catch (std::string error)
		{
			cout << error;
		}
	}
	//copy contructor does not allow copy constructor
	CustomerOrder::CustomerOrder(const CustomerOrder& copyConst)
	{
		throw false;
	}
	//move constructor
	CustomerOrder::CustomerOrder(CustomerOrder&& moveConst) noexcept
	{
		*this = std::move(moveConst);
	}
	//move assignment
	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& moveAssig) noexcept
	{
		//check for self assignemnt
		if (this != &moveAssig)
		{
			//clean-up for each element of the pointer array
			if (m_lsItem)
			{
				for (size_t i = 0u; i < m_cntItem; ++i){
					delete m_lsItem[i];
				}

				delete[] m_lsItem;
			}

			//move the resource from parameter inter current
			this->m_name = moveAssig.m_name;
			this->m_product = moveAssig.m_product;
			this->m_cntItem = moveAssig.m_cntItem;
			this->m_lsItem = moveAssig.m_lsItem;

			//delete moveAssig 
			moveAssig.m_name = "";
			moveAssig.m_product = "";
			moveAssig.m_cntItem = 0u;
			moveAssig.m_lsItem = nullptr;
		}
		return *this;
	}
	//destructor
	CustomerOrder::~CustomerOrder()
	{
		//clean-up for each element of the pointer array
		if (m_lsItem)
		{
			for (size_t i = 0u; i < m_cntItem; ++i)
			{
				delete m_lsItem[i];
			}
			delete[] m_lsItem;
			m_lsItem = nullptr;
		}
	}
	//return true if all items in the order are have been filled
	bool CustomerOrder::isFilled() const{
		bool check = true;

		//for each element return m_isFilled
		for (size_t i = 0u; i < m_cntItem; ++i){
			if (!m_lsItem[i]->m_isFilled)
				check = false;
		}
		return check;
	}
	//return true if a specific item have been filled. If the item doesn't exist return true as well.
	bool CustomerOrder::isItemFilled(const std::string& itemName) const
	{
		bool check = true;

		for (size_t i = 0u; i < m_cntItem; ++i)
		{
			if (m_lsItem[i]->m_itemName == itemName)
				check = m_lsItem[i]->m_isFilled;
		}
		return check;
	}
	//fills all items in the current order in a specific Station
	void CustomerOrder::fillItem(Station& station, std::ostream& os)
	{
		for (size_t i = 0u; i < m_cntItem; ++i)
		{
			//order product == station product
			if (m_lsItem[i]->m_itemName == station.getItemName())
			{
				//station has at least 1 product
				if (station.getQuantity() >= 1)
				{
					//substracts 1
					station.updateQuantity();

					//update serialNumber
					m_lsItem[i]->m_serialNumber = station.getNextSerialNumber();

					//"fill" the order
					m_lsItem[i]->m_isFilled = true;

					//print Filled NAME, PRODUCT [ITEM_NAME]
					os << "    Filled ";
				}
				//print Unable to fill NAME, PRODUCT [ITEM_NAME]
				else os << "    Unable to fill ";

				os << m_name << ", " << m_product << " [" << m_lsItem[i]->m_itemName << "]" << "\n";
			}
		}
	}
	//display the state od the current object
	void CustomerOrder::display(std::ostream& os) const
	{
		//CUSTOMER_NAME - PRODUCT
		os << m_name << " - " << m_product << "\n";

		//[SERIAL] = [000000] filled with 6 0
		//ITEM_NAME = Bed                             31 position
		//- STATUS
		//[000000] Bed                            - TO BE FILLED
		for (size_t i = 0u; i < m_cntItem; ++i)
		{
			os << "[" << std::right << std::setw(6) << std::setfill('0') << m_lsItem[i]->m_serialNumber << "] ";
			os << std::left << std::setw(CustomerOrder::m_widthField) << std::setfill(' ') << m_lsItem[i]->m_itemName << " - ";

			//if m_isFilled is true print Filled, otherwise To be Filled
			if (m_lsItem[i]->m_isFilled)
				os << "FILLED" << "\n";
			else os << "TO BE FILLED" << "\n";
		}
	}
}