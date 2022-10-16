// Name: Mayara Rodrigues
// Seneca Student ID: 118758200
// Seneca email: mrodrigues21@gmail.com	
// Date of completion: 12-04-2021
// PROJETCT - MS03
// I confirm that I am the only author of this file and the content was created entirely by me, based on my lasts WSs done and the MS01 and MS02.
//As reference https://www.cplusplus.com/reference/deque/deque/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Utilities.h"
#include "Workstation.h"
#include "LineManager.h"

using namespace std;

namespace sdds
{
	//import the file, starts a Station, and vector Workstation to get the assembly fine (STL mandatory)
	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
	{
		//Utilities object local definition to uses the extractToken
		Utilities objecU;
		//is necessary to pass all parameters that the functions needed
		//size_t next_pos = 0u;
		bool more = true;

		//store the station on the local variable
		std::string line{};
		std::string workStation{};
		std::string nworkStation{};

		//collection
		vector<string> collectionWS, ncollectionWS;

		//load the file
		std::ifstream fileIn(file);

		//check if the file failed
		if (fileIn.is_open() == false)
			throw "Bad file name!";
		else
		{
			//extract the line in this format WORKSTATION|NEXT_WORKSTATION
			while (std::getline(fileIn, line))
			{
				//restart the position of a new line, and the variables
				size_t next_pos = 0u;
				std::string workStation{};
				std::string nworkStation{};
				//if line isn't empty extract the workstation
				if (!line.empty())
				{
					workStation = objecU.extractToken(line, next_pos, more);
					//pushback to the queue container
					collectionWS.push_back(workStation);
					//if more = false extract the neextWorkstation
					if (more)
					{
						nworkStation = objecU.extractToken(line, next_pos, more);
						//pushback to the queue container
						ncollectionWS.push_back(nworkStation);
					}
					//check if the *ws == value on file ***STL mandadory
					any_of(stations.begin(), stations.end(), [=](Workstation* ws)
						{
							if (ws->getItemName() == workStation)
							{
								//check if the workstation has a next workstation **Bookcase
								if (!nworkStation.empty())
								{
									any_of(stations.begin(), stations.end(), [=](Workstation* Nws)
										{
											if (Nws->getItemName() == nworkStation)
											{
												//set the next station
												ws->setNextStation(Nws);
												return true;
											}
											else return false;
										});
								}
								//add the workstation
								activeLine.push_back(ws);
								return true;
							}
							else return false;
						});
				}
			}
		}
		//close the file
		fileIn.close();

		//activeLine
		for_each(activeLine.begin(), activeLine.end(), [=](Workstation* ws)
			{
				auto line = any_of(stations.begin(), stations.end(), [=](Workstation* ws1)
					{
						if (ws1->getNextStation() == ws)
							return true;
						else return false;
					});
				if (!line)
					m_firstStation = ws;
			});
		m_cntCustomerOrder = pending.size();
	}
	//reorder the workstations, and store at the same vector
	void LineManager::linkStations()
	{
		//get firstStation
		Workstation* nextWS = m_firstStation;
		//new collection
		vector<Workstation*> WStation;

		while (nextWS)
		{
			WStation.push_back(nextWS);
			nextWS = nextWS->getNextStation();
		}
		//load the collection in active Line
		activeLine = WStation;
	}
	//modify on interation of display
	bool LineManager::run(std::ostream& os)
	{
		//local variable for each interation doesn't restart (static)
		static size_t cnt = 0u;

		os << "Line Manager Iteration: " << ++cnt << "\n";

		//if pending on queue
		if (!pending.empty())
		{
			//moves at the front to queue
			*activeLine.front() += move(pending.front());
			//remove the queue
			pending.pop_front();
		}
		//for each station on the line, executes one fill operation
		for (auto line : activeLine)
			line->fill(os);
		//for each station on the line, executes one fill operation
		for (auto line : activeLine)
			line->attemptToMoveOrder();

		return m_cntCustomerOrder == completed.size() + incomplete.size();
	}
	//display all active station
	void LineManager::display(std::ostream& os) const
	{
		//I'm trying to use the algorithm 
		for_each(activeLine.begin(), activeLine.end(), [&](Workstation* ws)
			{
				ws->display(os);
			});
	}
}

