#include <iostream>
#include <map>
#include <tuple>
#include <functional>
#include <unordered_map>
#include <memory>
using namespace std;

template<class R, class ...Args>
function<R(Args...)> memo(const function<R(Args...)>& f) {
    typedef tuple<Args...> args_t;
    shared_ptr<map<args_t, R>> h(new map<args_t, R>);
    return [h, f] (Args&&... x) -> R {
        tuple<Args...> argsTupple = make_tuple(x...);
        auto it = h->find(argsTupple);
        if (it == h->end()) {
            it = h->insert(make_pair(argsTupple, f(std::forward<Args>(x)...))).first;
        }
        return it->second;
    };
}

int f(int x) {
    cout << "Calling f for x = " << x << endl;
    return x * x;
}

int main() {
    function<int(int)> g = memo(function<int(int)>(f));
    auto h = g;
    cout << g(2) << endl;
    cout << g(2) << endl;
    cout << g(2) << endl;
    cout << g(3) << endl;
    cout << g(3) << endl;
    cout << g(3) << endl;
    cout << h(3) << endl;
    return 0;
}
