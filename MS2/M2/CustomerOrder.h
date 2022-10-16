// Name: Mayara Rodrigues
// Seneca Student ID: 118758200
// Seneca email: mrodrigues21@gmail.com	
// Date of completion: 11-27-2021
// PROJETCT - MS02
// I confirm that I am the only author of this file and the content was created entirely by me, based on my lasts WSs done and the MS01.

#ifndef SDDS_CUSTOMER_ORDER__H
#define SDDS_CUSTOMER_ORDER__H

#include <string>
#include "Station.h"

namespace sdds{
	//Item definition
	struct Item
	{
		std::string m_itemName{};
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };

		Item(const std::string& src) : m_itemName(src){};
	};

	class CustomerOrder{

		//Instance Variables
		std::string m_name{};   //name customer
		std::string m_product{};//product name
		size_t m_cntItem = 0u;  //count customer's order
		Item** m_lsItem{};      //array of pointers. Each element point to a dynamically object of Item.

		//class variable
		static size_t m_widthField; //max width of a field

	public:
		//default constructor
		CustomerOrder(){};
		//custom 1-arg constructor., receives a unmodifiable string.
		CustomerOrder(const std::string& src);
		//copy contructor
		CustomerOrder(const CustomerOrder& copyConst);
		//copy assignment = if called should be deleted
		CustomerOrder& operator=(const CustomerOrder& copyAssig) = delete;
		//move constructor
		CustomerOrder(CustomerOrder&& moveConst) noexcept;
		//move assignment
		CustomerOrder& operator=(CustomerOrder&& moveAssig) noexcept;
		//destructor
		~CustomerOrder();
		//return true if all items in the order are have been filled
		bool isFilled() const;
		//return true if a specific item have been filled.
		bool isItemFilled(const std::string& itemName) const;
		//fills all items in the current order in a specific Station
		void fillItem(Station& station, std::ostream& os);
		//display the state od the current object
		void display(std::ostream& os) const;

	};
}
#endif // !SDDS_CUSTOMER_ORDER__H
