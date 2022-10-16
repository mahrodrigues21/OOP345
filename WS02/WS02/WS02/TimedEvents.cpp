// Workshop 2 - Copy and Move Semantics
// Name: Mayara Rodrigues
// Student Number: 118758200
// Student ID: mrodrigues21
// Date: 2021-09-28
// I have done all the coding by myselfand only copied the code that my professor provided to complete my
// workshopsand assignments, and the references posted on WS assignment. I also utilize my files for my
// previuos WS on the last term (WS06 - TextFile).

#include <iostream>
#include <iomanip>
#include <chrono>
#include "TimedEvents.h"

using namespace std;

namespace sdds {
	//starts event's time
	void TimedEvents::startClock() {
		//std::cout << "startClock()" << "\n";
		m_startTime = std::chrono::steady_clock::now();
	}
	//stop event's time
	void TimedEvents::stopClock() {
		//std::cout << "stopClock()" << "\n";
		m_endTime = std::chrono::steady_clock::now();
	}
	//add a new event
	void TimedEvents::addEvent(const char* nameEvent) {
		//std::cout << "addEvent()" << "\n";
		if (m_nRecords < MAX_NUMBER) {
			if (nameEvent != nullptr || nameEvent[0] != '\0') {
				m_event[m_nRecords].m_EventName = nameEvent;
				m_event[m_nRecords].m_UnitsTime = "nanoseconds";
				m_event[m_nRecords].m_EventDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(m_endTime - m_startTime);

				++m_nRecords;
			}
			else {
				m_event[m_nRecords].m_EventName = "";
				m_event[m_nRecords].m_UnitsTime = "";
			}
		}
	}
	//print the records of TimeEvents
	std::ostream& operator<<(std::ostream& ost, const TimedEvents& timeEvent) {
		//std::cout << "operator<<" << "\n";
		ost << "--------------------------" << "\n";
		ost << "Execution Times:" << "\n";
		ost << "--------------------------" << "\n";

		for (auto i = 0u; i < timeEvent.m_nRecords; i++) {
			ost << std::setw(21);
			ost << std::left;
			ost << timeEvent.m_event[i].m_EventName;

			ost << std::setw(13);
			ost << std::right;
			ost << timeEvent.m_event[i].m_EventDuration.count();
			ost << " " << timeEvent.m_event[i].m_UnitsTime << "\n";
		}
		ost << "--------------------------" << "\n";

		return ost;
	}
}
