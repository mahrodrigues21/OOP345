// Student
// Name: Mayara Rodrigues
// Student Number: 118758200
// Student ID: mrodrigues21
// Date: 2021-11-06
// WS05
// I have done all the coding by myselfand only copied the code that my professor provided to complete my
// workshopsand assignments, and the references posted on WS assignment. 

#ifndef SDDS_COLLECTION__H
#define SDDS_COLLECTION__H

#include <string>
#include <iostream>
#include <iomanip>

namespace sdds{
	template <typename T>
	class Collection
	{
		T* m_item{};
		std::string m_name{};
		size_t m_sizeArr = 0;
		void (*f_observer) (const Collection<T>&, const T&) {};

	public:
		Collection(const std::string& name) { //copy the parameter to member M-name
			m_name = name;
		}
		Collection(const Collection&) = delete;
		Collection operator=(const Collection&) = delete;
		~Collection() {                       //destructor delete m_item
			if (m_item){
				delete[] m_item;
				m_item = nullptr;
			}
		}
		const std::string& name() const {     //return name
			return m_name;
		}
		size_t size() const {                //return size
			return m_sizeArr;
		}
		void setObserver(void (*observer)(const Collection<T> &, const T &)) { //resize m_item and add new item to it
			f_observer = observer;
		}
		Collection<T>& operator+=(const T& item) {
			bool checkTitle = true;

			for (auto i = 0u ; i < m_sizeArr; ++i){
				if (m_item[i].title() == item.title())
					checkTitle = false;
			}
			if (checkTitle){
				//check if m_item is empty and add the new item
				if (m_sizeArr == 0u){
					m_item = new T[++m_sizeArr];
					m_item[0] = item;
				}
				else{
					//if m_item is not empty resize it
					T* tempItem = new T[m_sizeArr];

					//copy the m_item into tempItem
					for (auto i = 0u; i < m_sizeArr; ++i){
						tempItem[i] = m_item[i];
					}
					//clean up
					delete[] m_item;
					m_item = nullptr;
					
					//copy the tempItem into m_item resize
					m_item = new T[++m_sizeArr];
					for (auto i = 0u; i < m_sizeArr -1u; i++){
						m_item[i] = tempItem[i];
					}
					//add the newm item
					m_item[m_sizeArr -1u] = item;

					//delete tem tempItem
					delete[] tempItem;
					tempItem = nullptr;

					//if registered observer
					if (f_observer){
						f_observer(*this, item);
					}
				}
			}
			return *this;
		}
		T& operator[](size_t idx) const {
			if (idx >= size()){
				std::string error = "Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(size()) + "] items.";

				throw std::out_of_range(error);
			}
			return m_item[idx];
		}
		T* operator[](const std::string& title) const {
			bool checkTitle = false;
			size_t cnt = 0u;

			for (auto i = 0u; ((i < m_sizeArr) && (checkTitle == false)); i++){
				if (m_item[i].title() == title){
					checkTitle = true;
					cnt = i;
				}
			}

			if (!checkTitle){
				return nullptr;
			}
			else{
				return &m_item[cnt];
			}
		}
	};
	template<typename T>
	std::ostream& operator<<(std::ostream& os, const Collection<T>& src) {
		for (auto i = 0u; i < src.size(); i++)
		{
			os << src[i];
		}
		return os;
	}
}
#endif // !SDDS_COLLECTION__H
