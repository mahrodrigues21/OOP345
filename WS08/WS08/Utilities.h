// Workshop 8 - Smart Pointers
// 2019/11 - Cornel
// Student Information
// Name: Mayara Rodrigues
// Student Number: 118758200
// Student ID: mrodrigues21
// Date: 2021-11-06
// WS08
// I have done all the coding by myselfand only copied the code that my professor provided to complete my
// workshopsand assignments, and the references posted on WS assignment. 


#ifndef SDDS_UTILITIES__H
#define SDDS_UTILITIES__H

#include "List.h"
#include "Element.h"

namespace sdds
{
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price);
	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price);
}

#endif // !SDDS_UTILITIES__H