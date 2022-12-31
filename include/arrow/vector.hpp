/* SPDX-FileCopyrightText: © 2022 Alan Jian alanjian85@outlook.com
 * SPDX-LicenseIdentifier: GPL-3.0*/

#ifndef ARROW_VECTOR_HPP
#define ARROW_VECTOR_HPP

#include <cstdlib>

#include <algorithm>
#include <initializer_list>

namespace arrow {
    template <typename T, size_t N>
    class vector {
    public:
        vector(T value = T(0)) {
            std::fill(std::begin(m_components), std::end(m_components), value);
        }

        vector(std::initializer_list<T> list) {
            std::copy(list.begin(), list.end(), m_components);
        }

        T operator[](size_t i) const { return m_components[i]; }

        T &operator[](size_t i) { return m_components[i]; }

        friend bool operator==(const vector &lhs, const vector &rhs) {
            if (&lhs == &rhs)
                return true;

            for (size_t i = 0; i < N; ++i)
                if (lhs[i] != rhs[i])
                    return false;
            return true;
        }

        friend bool operator!=(const vector &lhs, const vector &rhs) {
            if (&lhs == &rhs)
                return false;

            for (size_t i = 0; i < N; ++i)
                if (lhs[i] != rhs[i])
                    return true;
            return false;
        }

        friend vector operator+(const vector &lhs, const vector &rhs) {
            vector result;
            for (size_t i = 0; i < N; ++i)
                result[i] = lhs[i] + rhs[i];
            return result;
        }
    private:
        T m_components[N];
    };
} // namespace arrow

#endif // ARROW_VECTOR_HPP
