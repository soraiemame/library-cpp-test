---
data:
  _extendedDependsOn:
  - {icon: ':heavy_check_mark:', path: data-structure/segtree.hpp, title: data-structure/segtree.hpp}
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
    links: ['https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A']
  bundledCode: "#line 1 \"test/segtree.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\"\
    \n\n#include <iostream>\n#include <algorithm>\n\n#line 1 \"data-structure/segtree.hpp\"\
    \n\n\n\n#include<vector>\n#include<functional>\n#include<assert.h>\n\ntemplate<class\
    \ T>\nstruct SegTree{\n    using fx = std::function<T(T,T)>;\n    int n;\n   \
    \ std::vector<T> dat;\n    T e;\n    fx f;\n    SegTree(int n_,T e_,fx f_):e(e_),f(f_){\n\
    \        int x = 1;\n        while(x < n_)x <<= 1;\n        n = x;\n        dat\
    \ = std::vector<T>(x * 2 - 1,e);\n    }\n    void set(int m,T a){\n        assert(0\
    \ <= m && m < n);\n        dat[m + n - 1] = a;\n    }\n    void build(){\n   \
    \     for(int i = n - 2;i >= 0;i--){\n            dat[i] = f(dat[i * 2 + 1],dat[i\
    \ * 2 + 2]);\n        }\n    }\n    void update(int m,T a){\n        assert(0\
    \ <= m && m < n);\n        m += n - 1;\n        dat[m] = a;\n        while(m >\
    \ 0){\n            m = (m - 1) / 2;\n            dat[m] = f(dat[m * 2 + 1],dat[m\
    \ * 2 + 2]);\n        }\n    }\n    void add(int m,T a){\n        assert(0 <=\
    \ m && m < n);\n        m += n - 1;\n        dat[m] = a;\n        while(m > 0){\n\
    \            m = (m - 1) / 2;\n            dat[m] = f(dat[m * 2 + 1],dat[m * 2\
    \ + 2]);\n        }\n    }\n    T query(int a,int b,int k,int l,int r){\n    \
    \    if(a >= r || b <= l){\n            return e;\n        }\n        else if(a\
    \ <= l && r <= b){\n            return dat[k];\n        }\n        else{\n   \
    \         T L = query(a,b,k * 2 + 1,l,(l + r) / 2);\n            T R = query(a,b,k\
    \ * 2 + 2,(l + r) / 2,r);\n            return f(L,R);\n        }\n    }\n    T\
    \ query(int a,int b){\n        assert(0 <= a && a < n && 0 < b && b <= n && a\
    \ <= b);\n        return query(a,b,0,0,n);\n    }\n    T get(int a){\n       \
    \ assert(0 <= a && a < n);\n        return dat[a + n - 1];\n    }\n};\n\n\n#line\
    \ 7 \"test/segtree.test.cpp\"\n\nint fx(int a,int b){\n    return std::min(a,b);\n\
    }\n\nint main(){\n    int N,Q;\n    std::cin >> N >> Q;\n    SegTree<int> S(N,2147483647,fx);\n\
    \    for(int i = 0;i < Q;i++){\n        int t,a,b;\n        std::cin >> t >> a\
    \ >> b;\n        if(t == 0)S.update(a,b);\n        if(t == 1)std::cout << S.query(a,b\
    \ + 1) << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\"\
    \n\n#include <iostream>\n#include <algorithm>\n\n#include \"../data-structure/segtree.hpp\"\
    \n\nint fx(int a,int b){\n    return std::min(a,b);\n}\n\nint main(){\n    int\
    \ N,Q;\n    std::cin >> N >> Q;\n    SegTree<int> S(N,2147483647,fx);\n    for(int\
    \ i = 0;i < Q;i++){\n        int t,a,b;\n        std::cin >> t >> a >> b;\n  \
    \      if(t == 0)S.update(a,b);\n        if(t == 1)std::cout << S.query(a,b +\
    \ 1) << \"\\n\";\n    }\n}"
  dependsOn: [data-structure/segtree.hpp]
  isVerificationFile: true
  path: test/segtree.test.cpp
  requiredBy: []
  timestamp: '2021-03-21 13:18:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/segtree.test.cpp
layout: document
redirect_from: [/verify/test/segtree.test.cpp, /verify/test/segtree.test.cpp.html]
title: test/segtree.test.cpp
---
