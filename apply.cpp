/*
   Similar to f(*list) from python.
   Limitations: Does not work on template functions
*/
#include <functional>
#include <cassert>
#include <iostream>
#include <type_traits>
#include <utility>
using namespace std;

namespace detail {
    template<class Fn, class Tuple, class ReturnType, size_t... I>
    inline ReturnType
    apply_impl(Fn fun, Tuple&& argsTuple, const index_sequence<I...>&)
    {
        return fun(get<I>(argsTuple)...);
    }

    template<class Fn, class...Args>
    inline auto apply(Fn f, tuple<Args...>&& argsTuple) ->
    typename result_of<Fn(Args...)>::type {
        using ReturnType = typename result_of<Fn(Args...)>::type;
        const size_t ArgsLength = sizeof...(Args);
        return apply_impl<
                    Fn,
                    tuple<Args...>,
                    ReturnType
                >(f, std::move(argsTuple), make_index_sequence<ArgsLength>());
    }
};

void printSum(int x, int y, int z) {
    cout << (x + y + z) << endl;
}

void incrementRef(int& t) {
    t++;
}

int sum(int x, int y) {
    return x + y;
}

int& returningRef(int value) {
    int *x = new int(value);
    return (*x);
}

int main() {
    using detail::apply;
    int x = 0;
    apply(printSum, make_tuple(1, 2, 3));
    apply(incrementRef, make_tuple(ref(x)));
    assert(x == 1);
    assert(apply(sum, make_tuple(1, 2)) == 3);
    int& y = apply(returningRef, make_tuple(1));
    y++;
    assert(y == 2);
    return 0;
}
