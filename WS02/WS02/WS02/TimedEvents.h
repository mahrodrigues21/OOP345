// Workshop 2 - Copy and Move Semantics
// Name: Mayara Rodrigues
// Student Number: 118758200
// Student ID: mrodrigues21
// Date: 2021-09-28
// I have done all the coding by myselfand only copied the code that my professor provided to complete my
// workshopsand assignments, and the references posted on WS assignment. I also utilize my files for my
// previuos WS on the last term (WS06 - TextFile).


#ifndef SDDS_TIMEDEVENTS_H__
#define SDDS_TIMEDEVENTS_H__

#include <chrono>
#include <string>

//static variable
const unsigned int MAX_NUMBER = 10;

namespace sdds {
	class TimedEvents{
		size_t m_nRecords = 0;
		std::chrono::steady_clock::time_point m_startTime;
		std::chrono::steady_clock::time_point m_endTime;

		struct Event {
			std::string m_EventName{""};
			std::string m_UnitsTime{""};
			std::chrono::steady_clock::duration m_EventDuration;
		} m_event[MAX_NUMBER]; // name of Event's array
	public:
		//default constructor
		TimedEvents() {};

		void startClock();
		void stopClock();
		void addEvent(const char* nameEvent);

		//no destructor???

		friend std::ostream& operator<<(std::ostream& ost, const TimedEvents& timeEvent);
	};
}
#endif // !SDDS_TIMEDEVENTS_H__

