---
data:
  _extendedDependsOn:
  - {icon: ':heavy_check_mark:', path: data-structure/lazysegtree_abstract.hpp, title: data-structure/lazysegtree_abstract.hpp}
  - {icon: ':heavy_check_mark:', path: data-structure/lazysegtree_utils.hpp, title: data-structure/lazysegtree_utils.hpp}
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I
    links: ['https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I']
  bundledCode: "#line 1 \"test/range-queries/RSQ_RUQ_2.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I\"\n\n#line\
    \ 1 \"data-structure/lazysegtree_utils.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <iostream>\n\n#line 1 \"data-structure/lazysegtree_abstract.hpp\"\n\n\n\n#include\
    \ <vector>\n#include <assert.h>\n\ntemplate <class S,\n          S (*op)(S, S),\n\
    \          S (*e)(),\n          class F,\n          S (*mapping)(F, S),\n    \
    \      F (*composition)(F, F),\n          F (*id)()>\nstruct lazy_segtree_base\
    \ {\n  public:\n    lazy_segtree_base() : lazy_segtree_base(0) {}\n    explicit\
    \ lazy_segtree_base(int n) : lazy_segtree_base(std::vector<S>(n, e())) {}\n  \
    \  explicit lazy_segtree_base(const std::vector<S>& v) : _n(int(v.size())) {\n\
    \        log = 0,size = 1;\n        while(size < _n)size <<= 1,log++;\n      \
    \  d = std::vector<S>(2 * size, e());\n        lz = std::vector<F>(size, id());\n\
    \        for (int i = 0; i < _n; i++) d[size + i] = v[i];\n        for (int i\
    \ = size - 1; i >= 1; i--) {\n            update(i);\n        }\n    }\n\n   \
    \ void set(int p, S x) {\n        assert(0 <= p && p < _n);\n        p += size;\n\
    \        for (int i = log; i >= 1; i--) push(p >> i);\n        d[p] = x;\n   \
    \     for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    S get(int p)\
    \ {\n        assert(0 <= p && p < _n);\n        p += size;\n        for (int i\
    \ = log; i >= 1; i--) push(p >> i);\n        return d[p];\n    }\n\n    S query(int\
    \ l, int r) {\n        assert(0 <= l && l <= r && r <= _n);\n        if (l ==\
    \ r) return e();\n\n        l += size;\n        r += size;\n\n        for (int\
    \ i = log; i >= 1; i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n\
    \            if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\n    \
    \    S sml = e(), smr = e();\n        while (l < r) {\n            if (l & 1)\
    \ sml = op(sml, d[l++]);\n            if (r & 1) smr = op(d[--r], smr);\n    \
    \        l >>= 1;\n            r >>= 1;\n        }\n\n        return op(sml, smr);\n\
    \    }\n\n    S query_all() { return d[1]; }\n\n    void update(int p, F f) {\n\
    \        assert(0 <= p && p < _n);\n        p += size;\n        for (int i = log;\
    \ i >= 1; i--) push(p >> i);\n        d[p] = mapping(f, d[p]);\n        for (int\
    \ i = 1; i <= log; i++) update(p >> i);\n    }\n    void update(int l, int r,\
    \ F f) {\n        assert(0 <= l && l <= r && r <= _n);\n        if (l == r) return;\n\
    \n        l += size;\n        r += size;\n\n        for (int i = log; i >= 1;\
    \ i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n            if\
    \ (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\n        {\n       \
    \     int l2 = l, r2 = r;\n            while (l < r) {\n                if (l\
    \ & 1) all_apply(l++, f);\n                if (r & 1) all_apply(--r, f);\n   \
    \             l >>= 1;\n                r >>= 1;\n            }\n            l\
    \ = l2;\n            r = r2;\n        }\n\n        for (int i = 1; i <= log; i++)\
    \ {\n            if (((l >> i) << i) != l) update(l >> i);\n            if (((r\
    \ >> i) << i) != r) update((r - 1) >> i);\n        }\n    }\n\n    template <bool\
    \ (*g)(S)> int max_right(int l) {\n        return max_right(l, [](S x) { return\
    \ g(x); });\n    }\n    template <class G> int max_right(int l, G g) {\n     \
    \   assert(0 <= l && l <= _n);\n        assert(g(e()));\n        if (l == _n)\
    \ return _n;\n        l += size;\n        for (int i = log; i >= 1; i--) push(l\
    \ >> i);\n        S sm = e();\n        do {\n            while (l % 2 == 0) l\
    \ >>= 1;\n            if (!g(op(sm, d[l]))) {\n                while (l < size)\
    \ {\n                    push(l);\n                    l = (2 * l);\n        \
    \            if (g(op(sm, d[l]))) {\n                        sm = op(sm, d[l]);\n\
    \                        l++;\n                    }\n                }\n    \
    \            return l - size;\n            }\n            sm = op(sm, d[l]);\n\
    \            l++;\n        } while ((l & -l) != l);\n        return _n;\n    }\n\
    \n    template <bool (*g)(S)> int min_left(int r) {\n        return min_left(r,\
    \ [](S x) { return g(x); });\n    }\n    template <class G> int min_left(int r,\
    \ G g) {\n        assert(0 <= r && r <= _n);\n        assert(g(e()));\n      \
    \  if (r == 0) return 0;\n        r += size;\n        for (int i = log; i >= 1;\
    \ i--) push((r - 1) >> i);\n        S sm = e();\n        do {\n            r--;\n\
    \            while (r > 1 && (r % 2)) r >>= 1;\n            if (!g(op(d[r], sm)))\
    \ {\n                while (r < size) {\n                    push(r);\n      \
    \              r = (2 * r + 1);\n                    if (g(op(d[r], sm))) {\n\
    \                        sm = op(d[r], sm);\n                        r--;\n  \
    \                  }\n                }\n                return r + 1 - size;\n\
    \            }\n            sm = op(d[r], sm);\n        } while ((r & -r) != r);\n\
    \        return 0;\n    }\n\n  private:\n    int _n, size, log;\n    std::vector<S>\
    \ d;\n    std::vector<F> lz;\n\n    void update(int k) { d[k] = op(d[2 * k], d[2\
    \ * k + 1]); }\n    void all_apply(int k, F f) {\n        d[k] = mapping(f, d[k]);\n\
    \        if (k < size) lz[k] = composition(f, lz[k]);\n    }\n    void push(int\
    \ k) {\n        all_apply(2 * k, lz[k]);\n        all_apply(2 * k + 1, lz[k]);\n\
    \        lz[k] = id();\n    }\n};\n\n\n\n\n#line 8 \"data-structure/lazysegtree_utils.hpp\"\
    \n\nnamespace tools{\n    template<class T>\n    T lim_max(){return std::numeric_limits<T>::max();}\n\
    \    template<class T>\n    T lim_min(){return std::numeric_limits<T>::min();}\n\
    \    template<class T>\n    T zero(){return T(0);}\n\n    template<class T>\n\
    \    T _min(T a,T b){return std::min(a,b);}\n    template<class T>\n    T _max(T\
    \ a,T b){return std::max(a,b);}\n    template<class T>\n    T sum(T a,T b){return\
    \ a + b;}\n    template<class T>\n    T none(T a,T b){return a == tools::lim_max<T>()\
    \ ? b : a;}\n\n    template<class T>\n    struct range_add{\n        T val;\n\
    \        int size;\n        friend std::ostream& operator<<(std::ostream& os,range_add\
    \ r){return os << r.val;}\n    };\n    template<class T>\n    range_add<T> range_add_sum(range_add<T>\
    \ a,range_add<T> b){return range_add<T>{a.val + b.val,a.size + b.size};}\n   \
    \ template<class T>\n    range_add<T> range_add_e(){return range_add<T>{T(0),1};}\n\
    \    template<class T>\n    range_add<T> range_add_add(T f,range_add<T> x){return\
    \ range_add<T>{x.size * f + x.val,x.size};}\n    template<class T>\n    range_add<T>\
    \ range_add_update(T f,range_add<T> x){return f == lim_max<T>() ? x : range_add<T>{x.size\
    \ * f,x.size};}\n};\n\nnamespace aliases{\n    template<class T>\n    using RMQ_RUQ\
    \ = lazy_segtree_base<T,tools::_min<T>,tools::lim_max<T>,T,tools::none<T>,tools::none<T>,tools::lim_max<T>>;\n\
    \    template<class T>\n    using RMQ_RAQ = lazy_segtree_base<T,tools::_min<T>,tools::lim_max<T>,T,tools::sum<T>,tools::sum<T>,tools::zero<T>>;\n\
    \    template<class T>\n    using RSQ_RUQ = lazy_segtree_base<tools::range_add<T>,tools::range_add_sum<T>,tools::range_add_e<T>,\n\
    \    T,tools::range_add_update<T>,tools::none<T>,tools::lim_max<T>>;\n    template<class\
    \ T>\n    using RSQ_RAQ = lazy_segtree_base<tools::range_add<T>,tools::range_add_sum<T>,tools::range_add_e<T>,\n\
    \    T,tools::range_add_add,tools::sum<T>,tools::zero<T>>;\n};\n\nusing aliases::RMQ_RAQ;\n\
    using aliases::RMQ_RUQ;\nusing aliases::RSQ_RAQ;\nusing aliases::RSQ_RUQ;\n\n\n\
    #line 4 \"test/range-queries/RSQ_RUQ_2.test.cpp\"\n\n#line 6 \"test/range-queries/RSQ_RUQ_2.test.cpp\"\
    \n\nint main(){\n    int N,Q;\n    std::cin >> N >> Q;\n    RSQ_RUQ<long long>\
    \ ST(N);\n    for(int i = 0;i < Q;i++){\n        int t;\n        std::cin >> t;\n\
    \        if(t == 0){\n            int a,b,c;\n            std::cin >> a >> b >>\
    \ c;\n            ST.update(a,b + 1,c);\n        }\n        else{\n          \
    \  int a,b;\n            std::cin >> a >> b;\n            std::cout << ST.query(a,b\
    \ + 1).val << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I\"\
    \n\n#include \"../../data-structure/lazysegtree_utils.hpp\"\n\n#include <iostream>\n\
    \nint main(){\n    int N,Q;\n    std::cin >> N >> Q;\n    RSQ_RUQ<long long> ST(N);\n\
    \    for(int i = 0;i < Q;i++){\n        int t;\n        std::cin >> t;\n     \
    \   if(t == 0){\n            int a,b,c;\n            std::cin >> a >> b >> c;\n\
    \            ST.update(a,b + 1,c);\n        }\n        else{\n            int\
    \ a,b;\n            std::cin >> a >> b;\n            std::cout << ST.query(a,b\
    \ + 1).val << \"\\n\";\n        }\n    }\n}"
  dependsOn: [data-structure/lazysegtree_utils.hpp, data-structure/lazysegtree_abstract.hpp]
  isVerificationFile: true
  path: test/range-queries/RSQ_RUQ_2.test.cpp
  requiredBy: []
  timestamp: '2021-03-21 13:18:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/range-queries/RSQ_RUQ_2.test.cpp
layout: document
redirect_from: [/verify/test/range-queries/RSQ_RUQ_2.test.cpp, /verify/test/range-queries/RSQ_RUQ_2.test.cpp.html]
title: test/range-queries/RSQ_RUQ_2.test.cpp
---
