// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// Name: Mayara Rodrigues
// Student Number: 118758200
// Student ID: mrodrigues21
// Date: 2021/09/21

#ifndef SDDS_EVENT_H__
#define SDDS_EVENT_H__

//global variable g_sysClock non negative declare
extern unsigned int g_sysClock;

namespace sdds
{
    class Event
    {
        //I initialize the member here to force that because on valgrind says that on set and copy the variables is uninitialized.
        char* m_descriptEvent = nullptr;
        unsigned int m_timeEvent = 0;

    public:
        //default constructor
        Event();
        void display()const;
        void set(const char* description = nullptr);
        //destructor
        ~Event();

        //For case "A" on main file copy the current to another??
        Event(const Event& copy);

        //To save the object on archive
        Event& operator=(const Event& copy);
    };
}

#endif // !SDDS_EVENT_H__
