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

};


class Time: public time_interval::TimeBase<Time> {

};

}

}

#endif //TIME_H
