/*
 * arrow is freely redistributable under the GNU General Public License v3.0.
 * See the file "LICENSE" for information on usage and redistribution of this
 * file.
 */

#ifndef ARROW_VECTOR_HPP
#define ARROW_VECTOR_HPP

#include <cstdlib>

#include <algorithm>
#include <initializer_list>

namespace arrow {
    template <typename T, size_t N>
    class vector {
    public:
        vector(T value) {
            std::fill(std::begin(m_components), std::end(m_components), value);
        }

        vector(std::initializer_list<T> list) : m_components(list)  {
            std::copy(list.begin(), list.end(), m_components);
        }
    private:
        T m_components[N];
    };
}

#endif // ARROW_VECTOR_HPP
