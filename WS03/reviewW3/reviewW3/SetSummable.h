
#ifndef SDDS_SETSUMMABLE_H
#define SDDS_SETSUMMABLE_H

#include <string>
#include "Set.h"

namespace sdds
{
    template<size_t N, typename T>
    class SetSummable : public Set<N, T>
    {
    public:
        T accumulate(const std::string& filter) const {
            T _temp(filter);

            for (auto i = 0u; i < this->size(); ++i) {
                if (_temp.isCompatibleWith(this->get(i)))
                    _temp += this->get(i);
            }

            return _temp;
        }
    };
}
#endif // !SDDS_SETSUMMABLE_H