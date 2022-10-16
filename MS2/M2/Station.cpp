// Name: Mayara Rodrigues
// Seneca Student ID: 118758200
// Seneca email: mrodrigues21@gmail.com	
// Date of completion: 11-27-2021
// PROJETCT - MS02
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <algorithm>
#include <iostream>
#include <iomanip>
#include "Station.h"
#include "Utilities.h"

using namespace std;

namespace sdds
{
	//class member definition. As private needs to insert the module even it is the same module
	size_t Station::m_widthField = 0u;
	size_t Station::m_idgenetaror = 0u;

	//1 argument constructor, receives a reference(&) unmodifiable (const) single line
	Station::Station(const std::string& src)
	{
		//Utilities object local definition to uses the extractToken
		Utilities objecU;
		//is necessary to pass all parameters that the functions needed
		size_t next_pos = 0u;
		bool more = true;

		//as is used the thorw on the Utilities, it's necessary to declare a try catch here to handle a possible error
		try
		{
			m_nameStation = objecU.extractToken(src, next_pos, more);
			m_noSerial = stoi(objecU.extractToken(src, next_pos, more));
			m_noItem = stoi(objecU.extractToken(src, next_pos, more));

			//STL: to use algorith library
			m_widthField = max(objecU.getFieldWidth(), m_widthField);
			m_descStation = objecU.extractToken(src, next_pos, more);

			//As this function instantiate a new Station rise the id_generator
			++m_idgenetaror;
			//add the value into the instance variable
			m_idStation = m_idgenetaror;
		}
		catch (std::string error)
		{
			cout << error;
		}

	}
	//return the name of the current Station
	const std::string& Station::getItemName() const
	{
		return m_nameStation;
	}
	//returns the next serial number
	size_t Station::getNextSerialNumber()
	{
		return m_noSerial++;
	}
	//return the remaining quantity os items in the Station
	size_t Station::getQuantity() const
	{
		return m_noItem;
	}
	//substract 1 from available quantity, a non-negative value
	void Station::updateQuantity()
	{
		if (m_noItem > 0)
			--m_noItem;
	}
	//insert infomation into os why not return a os?
	void Station::display(std::ostream& os, bool full) const
	{
		//Standard print
		os << "[" << std::right << std::setw(3) << std::setfill('0') << m_idStation << "]";
		os << " Item: " << std::left << std::setw(m_widthField) << std::setfill(' ') << m_nameStation;
		os << " [" << std::right << std::setw(6) << std::setfill('0') << m_noSerial << "]";

		if (full)
		{
			os << " Quantity: " << std::left << std::setw(m_widthField) << std::setfill(' ') << m_noItem;
			os << " Description: " << m_descStation << "\n";
		}
		else
			os << "\n";
	}
}

