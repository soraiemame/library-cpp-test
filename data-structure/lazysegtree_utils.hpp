#ifndef SORAIE_LAZYSEGTREE_UTILS
#define SORAIE_LAZYSEGTREE_UTILS

#include <algorithm>

#include "lazysegtree_abstract.hpp"

namespace tools{
    template<class T>
    T lim_max(){return std::numeric_limits<T>::max();}
    template<class T>
    T lim_min(){return std::numeric_limits<T>::min();}
    template<class T>
    T zero(){return T(0);}

    template<class T>
    T _min(T a,T b){return std::min(a,b);}
    template<class T>
    T _max(T a,T b){return std::max(a,b);}
    template<class T>
    T sum(T a,T b){return a + b;}
};
namespace min_update{
    template<class S>
    S none(S f,S x){return f == tools::lim_max<S>() ? x : f;}
    template<class S>
    using RMQ_RUQ = lazy_segtree_base<S,tools::_min<S>,tools::lim_max<S>,S,none<S>,none<S>,tools::lim_max<S>>;
};
namespace sum_add{
    template<class T>
    struct S{
        T val;
        int size;
    };
    template<class T>
    S<T> e(){return S{T(0),1};}
    template<class T>
    S<T> op(S<T> a,S<T> b){return S<T>{a.val + b.val,a.size + b.size};}
    template<class T>
    S<T> mapping(T f,S<T> x){return S<T>{x.size * f + x.val,x.size};}
    template<class T>
    using RSQ_RAQ = lazy_segtree_base<S<T>,op<T>,e<T>,T,mapping<T>,tools::sum<T>,tools::zero<T>>;
};

using min_update::RMQ_RUQ;
using sum_add::RSQ_RAQ;

#endif /*SORAIE_LAZYSEGTREE_UTILS*/