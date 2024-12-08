//
// Created by daicanglan on 2024/12/8.
//

#ifndef TIME_H
#define TIME_H
#include <time.h>

namespace base {

class TimeDelta;

template <typename T>
constexpr TimeDelta Microseconds(T n);


class TimeDelta {

};


namespace time_interval {

template <class TimeClass>
class TimeBase {
public:
    static constexpr int64_t kHoursPerDay = 24;
    static constexpr int64_t kSecondsPerMinute = 60;
    static constexpr int64_t kMinutesPerHour = 60;
    static constexpr int64_t kSecondsPerHour =
        kSecondsPerMinute * kMinutesPerHour;
    static constexpr int64_t kMillisecondsPerSecond = 1000;
    static constexpr int64_t kMillisecondsPerDay =
        kMillisecondsPerSecond * kSecondsPerHour * kHoursPerDay;
    static constexpr int64_t kMicrosecondsPerMillisecond = 1000;
    static constexpr int64_t kMicrosecondsPerSecond =
        kMicrosecondsPerMillisecond * kMillisecondsPerSecond;
    static constexpr int64_t kMicrosecondsPerMinute =
        kMicrosecondsPerSecond * kSecondsPerMinute;
    static constexpr int64_t kMicrosecondsPerHour =
        kMicrosecondsPerMinute * kMinutesPerHour;
    static constexpr int64_t kMicrosecondsPerDay =
        kMicrosecondsPerHour * kHoursPerDay;
    static constexpr int64_t kMicrosecondsPerWeek = kMicrosecondsPerDay * 7;
    static constexpr int64_t kNanosecondsPerMicrosecond = 1000;
    static constexpr int64_t kNanosecondsPerSecond =
        kNanosecondsPerMicrosecond * kMicrosecondsPerSecond;

    constexpr bool is_null() const { return us_ == 0; }

protected:
    ClampedNumeric<int64_t> us_;
};


class Time: public time_interval::TimeBase<Time> {

};

}

}

#endif //TIME_H
