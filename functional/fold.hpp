#include <functional>
template<

    template<class,class> class BinaryOp,
    class Acc,
    class ...List
>
struct fold;

template<
    template<class,class> class BinaryOp,
    class Acc,
    class Head,
    class...Tail
>
struct fold<BinaryOp, Acc, Head, Tail...>
{
    typedef typename
        fold<
            BinaryOp,
            typename BinaryOp<Acc, Head>::type,
            Tail...
        >::type type;
};

template<
    template<class,class> class BinaryOp,
    class Acc,
    class Head
>
struct fold<BinaryOp, Acc, Head> {
    typedef typename BinaryOp<Acc, Head>::type type;
};
