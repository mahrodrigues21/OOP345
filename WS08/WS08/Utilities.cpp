// Workshop 8 - Smart Pointers
// 2019/11 - Cornel
// Student Information
// Name: Mayara Rodrigues
// Student Number: 118758200
// Student ID: mrodrigues21
// Date: 2021-11-28
// WS08
// I have done all the coding by myselfand only copied the code that my professor provided to complete my
// workshopsand assignments, and the references posted on WS assignment. 
// I used this website as reference to complete my WS https://en.cppreference.com/book/intro/smart_pointers, https://www.cplusplus.com/reference/memory/unique_ptr/ and https://www.geeksforgeeks.org/smart-pointers-cpp/


#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds
{
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price){
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		//compare the element of two list

		for (size_t i = 0u; i < desc.size(); ++i){
			for (size_t j = 0u; j < price.size(); ++j){
				if (desc[i].code == price[j].code){
					//if the code's matches creates a new Product object
					Product* matchProd = new Product(desc[i].desc, price[j].price);

					//valide if the price is less then 0
					//it caused memory leak =/ because if objects match and has price < 0.0 it trow an exception
					matchProd->validate();
					//add the product into the priceList
					priceList += matchProd;

					//deallocated memory
					delete matchProd;
					matchProd = nullptr;
				}
			}
		}
		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price)
	{
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers
		for (size_t i = 0u; i < desc.size(); ++i){
			for (size_t j = 0u; j < price.size(); ++j){
				if (desc[i].code == price[j].code){
					//if the code's matches creates a smart pointer 
					std::unique_ptr<Product> matchProd(new Product(desc[i].desc, price[j].price));

					//valide if the price is less then 0
					matchProd->validate();
					//add the product into the priceList
					priceList += matchProd;
				}
			}
		}
		return priceList;
	}
}