#include <functional>
#include <iostream>
#include <type_traits>
#include <utility>
using namespace std;

template<class Fn, class Tuple, size_t... I>
void apply_impl(Fn fun, Tuple&& argsTuple, index_sequence<I...>) {
    return fun(get<I>(argsTuple)...);
}

template<class Fn, class...Args>
void apply(Fn f, tuple<Args...>&& argsTuple) {
    apply_impl(f, std::move(argsTuple),
            make_index_sequence<sizeof...(Args)>());
}

void f(int x) {
    cout << x << endl;
}

void g(int x, int y, int z) {
    cout << (x + y + z) << endl;
}

void h(int& t) {
    t++;
    cout << t << endl;
}

int main() {
    int x = 0;
    apply(g, make_tuple(1, 2, 3));
    apply(h, make_tuple(ref(x)));
    return 0;
}
