#ifndef SDDS_SET_H_
#define SDDS_SET_H_

#include <iostream>

namespace sdds
{
    template <size_t N, typename T>
    class Set
    {
        size_t m_idx{ 0u };
        T m_array[N]{};

    public:
        // returns the current number of elements
        size_t size() const {
            return m_idx;
        }

        // returns a reference to the element at index idx of the statically allocated array
        const T& get(size_t idx) const {
            return m_array[idx];
        }

        void operator+=(const T& item) {
            // check the collection has capacity
            if (m_idx < N)
                m_array[m_idx++] = item; // adds a copy of item to the collection
        }
    };
}
#endif // !SDDS_SET_H_
