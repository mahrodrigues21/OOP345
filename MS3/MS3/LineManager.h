// Name: Mayara Rodrigues
// Seneca Student ID: 118758200
// Seneca email: mrodrigues21@gmail.com	
// Date of completion: 12-04-2021
// PROJETCT - MS03
// I confirm that I am the only author of this file and the content was created entirely by me, based on my lasts WSs done and the MS01 and MS02.
//As reference https://www.cplusplus.com/reference/deque/deque/

#ifndef SDDS_LINEMANAGER__H
#define  SDDS_LINEMANAGER__H

#include <vector>
#include "Workstation.h"

namespace sdds
{

	class LineManager
	{
		//instance variables
		//collection of workstation
		std::vector<Workstation*> activeLine{};
		//total number of CustomerOrder objects
		size_t m_cntCustomerOrder{};
		//points to the first station on the current line
		Workstation* m_firstStation{};

	public:
		//import the file, starts a Station, and vector Workstation to get the assembly fine
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);
		//reorder the workstations, and store at the same vector
		void linkStations();
		//modify on interation of display
		bool run(std::ostream& os);
		//display all active station
		void display(std::ostream& os) const;
	};
}

#endif // !SDDS_LINEMANAGER__H



