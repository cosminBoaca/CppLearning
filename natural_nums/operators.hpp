#include "num.hpp"

template<class N1, class N2>
struct plus {
    static const int value = get_num<N1>::value + get_num<N2>::value;
    typedef typename make_num<value>::type type;
};

static_assert(std::is_same<plus<_3, _5>::type, _8>::value, "");
