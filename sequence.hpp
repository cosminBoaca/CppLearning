#include <functional>
#include <cassert>
#include <type_traits>
using namespace std;

namespace detail {

template<size_t ...Idx>
struct index_sequence { };

template<size_t N, size_t ...Idx>
struct index_sequence_type :
    index_sequence_type<N - 1, N - 1, Idx...> { };

template<size_t ...Idx>
struct index_sequence_type<0, Idx...> {
    typedef index_sequence<Idx...> type;
};

template<size_t N>
auto make_index_sequence() ->
    typename index_sequence_type<N>::type {
        return typename index_sequence_type<N>::type();
    }

static_assert(is_same<decltype(make_index_sequence<3>()), index_sequence<0, 1, 2>>::value, "");

}
