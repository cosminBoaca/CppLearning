#include <functional>

struct zero;

template<class Previous>
struct succ;

template<size_t I>
struct make_num {
    typedef succ<typename make_num<I - 1>::type> type;
};

template<>
struct make_num<0> {
    typedef zero type;
};

template<class Succ>
struct get_num;

template<class SuccArg>
struct get_num<succ<SuccArg>> {
    static const size_t value = 
        1 + get_num<SuccArg>::value;
};

template<>
struct get_num<zero> {
    static const size_t value = 0;
};

static_assert(std::is_same<make_num<3>::type, succ<succ<succ<zero>>>>::value, "");
static_assert(get_num<succ<succ<succ<zero>>>>::value == 3, "");
