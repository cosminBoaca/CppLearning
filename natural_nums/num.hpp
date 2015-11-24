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

using _0 = make_num<0>::type;
using _1 = make_num<1>::type;
using _2 = make_num<2>::type;
using _3 = make_num<3>::type;
using _4 = make_num<4>::type;
using _5 = make_num<5>::type;
using _6 = make_num<6>::type;
using _7 = make_num<7>::type;
using _8 = make_num<8>::type;
using _9 = make_num<9>::type;
using _10 = make_num<10>::type;
using _11 = make_num<11>::type;
using _12 = make_num<12>::type;
using _13 = make_num<13>::type;
using _14 = make_num<14>::type;
using _15 = make_num<15>::type;
using _16 = make_num<16>::type;
using _17 = make_num<17>::type;
using _18 = make_num<18>::type;
using _19 = make_num<19>::type;
using _20 = make_num<20>::type;
using _21 = make_num<21>::type;
using _22 = make_num<22>::type;
using _23 = make_num<23>::type;
using _24 = make_num<24>::type;
using _25 = make_num<25>::type;
using _26 = make_num<26>::type;
using _27 = make_num<27>::type;
using _28 = make_num<28>::type;
using _29 = make_num<29>::type;
using _30 = make_num<30>::type;

static_assert(std::is_same<_0, zero>::value, "");
static_assert(std::is_same<_3, succ<succ<succ<zero>>>>::value, "");
static_assert(get_num<succ<succ<succ<zero>>>>::value == 3, "");
