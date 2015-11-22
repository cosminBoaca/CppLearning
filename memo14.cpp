#include <iostream>
#include <map>
#include <tuple>
#include <functional>
#include <unordered_map>
#include <memory>
using namespace std;

namespace detail {
auto memo = [](auto f) {
    return [=](auto... args) {
        using args_t = std::tuple<decltype(args)...>;
        using return_t = decltype(f(args...));
        static map<args_t, return_t> m;

        auto argsTuple = make_tuple(args...);
        auto it = m.find(argsTuple);
        if (it != m.end()) {
            return it->second;
        }
        return m.emplace(move(argsTuple),
                f(forward<decltype(args)>(args)...)).first->second;
    };
};
};


int f(int x) {
    cout << "Calling f for x = " << x << endl;
    return x * x;
}

int main() {
    using detail::memo;
    auto g = memo(f);
    cout << g(2) << endl;
    cout << g(2) << endl;
    cout << g(2) << endl;
    cout << g(3) << endl;
    cout << g(3) << endl;
    cout << g(3) << endl;
    auto h = memo(g);
    cout << h(10) << endl;
    return 0;
}
