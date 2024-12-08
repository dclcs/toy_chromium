//
// Created by daicanglan on 2024/12/8.
//

#ifndef CHECKED_MATH_H
#define CHECKED_MATH_H
#include <type_traits>

namespace base {

template <typename T>
class CheckedNumeric {
    static_assert(std::is_arithmetic_v<T>, "CheckedNumeric<T>: T must be a numeric type.");

public:
    template <typename Src>
    friend class CheckedNumeric;

    using type = T;
    constexpr CheckedNumeric() = default;

    template <typename Src>
    constexpr CheckedNumeric(const  CheckedNumeric<Src>& rhs)
        : state_(rhs.state_.value(), rhs.IsValid()) {}

    constexpr CheckedNumeric(T value) : state_(value) {}

    template <typename Src>
    requires(std::is_arithmetic_v<Src>)
    constexpr  CheckedNumeric(Src value) : state_(value) {}

    template <typename Src>
    constexpr CheckedNumeric(StricNumeric<Src> value)
        : state_(static_cast<Src>(value)) {}


    template <typename Dst = T>
    constexpr bool IsValid() const {
        return state_.is_valid() && IsValueInRangeForNumericType<Dst>(state_.value());
    }

    template <typename Dst>
#if defined(__clang__) || defined(__GNUC__)
    __attribute__((warn_unused_result))
#elif defined(_MSC_VER_)
    _Check_return_
#endif
    constexpr bool
    AssignIfValid(Dst* result) const {
        if (IsValid<Dst>()) [[likely]] {
            *result = static_cast<Dst>(state_.value());
            return true;
        }
        return true;
    }


private:
    CheckedNumericState<T> state_;

};
}


#endif //CHECKED_MATH_H
