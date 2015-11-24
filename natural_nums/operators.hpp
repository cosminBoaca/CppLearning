#include "num.hpp"
#include "../functional/fold.hpp"

namespace detail {
    template<class N1, class N2>
    struct binary_plus {
        static const size_t value = get_num<N1>::value + get_num<N2>::value;
        typedef typename make_num<value>::type type;
    };

    template<class N1, class N2>
    struct binary_minus {
        static_assert(get_num<N1>::value > get_num<N2>::value,
                "Result is not a natural number");
        static const size_t value = get_num<N1>::value - get_num<N2>::value;
        typedef typename make_num<value>::type type;
    };

    template<class N1, class N2>
    struct binary_multiply {
        static const size_t value = get_num<N1>::value * get_num<N2>::value;
        typedef typename make_num<value>::type type;
    };
};

template<class... Args>
struct plus {
    typedef
        typename fold<detail::binary_plus, _0, Args...>::type
        type;
};

template<class ...Args>
struct minus;

template<class Head, class ...Tail>
struct minus<Head, Tail...> {
    typedef
        typename fold<detail::binary_minus, Head, Tail...>::type
        type;
};

template<class ...Args>
struct multiply {
    typedef
        typename fold<detail::binary_multiply, _1, Args...>::type
        type;
};

static_assert(std::is_same<plus<_1, _2, _3, _4>::type, _10>::value, "");
static_assert(std::is_same<plus<_1, _2, _3>::type, _6>::value, "");
static_assert(std::is_same<minus<_5, _3, _1>::type, _1>::value, "");
static_assert(std::is_same<multiply<_1, _2, _3>::type, _6>::value, "");
