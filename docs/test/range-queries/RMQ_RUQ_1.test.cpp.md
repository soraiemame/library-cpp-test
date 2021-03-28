---
data:
  _extendedDependsOn:
  - {icon: ':heavy_check_mark:', path: data-structure/lazysegtree.hpp, title: data-structure/lazysegtree.hpp}
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F
    links: ['https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F']
  bundledCode: "#line 1 \"test/range-queries/RMQ_RUQ_1.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F\"\n\n#include\
    \ <iostream>\n\n#line 1 \"data-structure/lazysegtree.hpp\"\n\n\n\n#include <vector>\n\
    #line 6 \"data-structure/lazysegtree.hpp\"\n#include <algorithm>\n#include <assert.h>\n\
    \ntemplate<class T>\nstruct SegTree{//RAQ,RUQ,RSQ,RMinQ,RmaxQ\n    typedef std::pair<bool,T>\
    \ T_pair;\n    int n;T e;\n    std::vector<T> min_dat,max_dat,sum_dat;\n    std::vector<T_pair>\
    \ lazy;\n    SegTree(int n_,T e_ = 2147483647):e(e_){\n        int x = 1;\n  \
    \      while(x < n_)x <<= 1;\n        n = x;\n        min_dat = std::vector<T>(n\
    \ * 2 - 1);\n        max_dat = std::vector<T>(n * 2 - 1);\n        sum_dat = std::vector<T>(n\
    \ * 2 - 1);\n        lazy = std::vector<T_pair>(n * 2 - 1,std::make_pair(0,0));//0:add\
    \ 1:update\n    }\n    void set(int a,T x){\n        min_dat[a + n - 1] = x;max_dat[a\
    \ + n - 1] = x;sum_dat[a + n - 1] = x;\n    }\n    void build(){\n        for(int\
    \ i = n - 2;i >= 0;i--){\n            min_dat[i] = std::min(min_dat[i * 2 + 1],min_dat[i\
    \ * 2 + 2]);\n            max_dat[i] = std::max(max_dat[i * 2 + 1],max_dat[i *\
    \ 2 + 2]);\n            sum_dat[i] = sum_dat[i * 2 + 1] + sum_dat[i * 2 + 2];\n\
    \        }\n    }\n    void eval(int k,int l,int r){\n        if(k < n - 1){\n\
    \            if(lazy[k].first == 0){\n                lazy[k * 2 + 1].second +=\
    \ lazy[k].second;\n                lazy[k * 2 + 2].second += lazy[k].second;\n\
    \            }\n            else{\n                lazy[k * 2 + 1] = lazy[k];\n\
    \                lazy[k * 2 + 2] = lazy[k];\n            }\n        }\n      \
    \  if(lazy[k].first == 0){\n            min_dat[k] += lazy[k].second;\n      \
    \      max_dat[k] += lazy[k].second;\n            sum_dat[k] += lazy[k].second\
    \ * (r - l);\n        }\n        else{\n            min_dat[k] = lazy[k].second;\n\
    \            max_dat[k] = lazy[k].second;\n            sum_dat[k] = lazy[k].second\
    \ * (r - l);\n        }\n        lazy[k] = std::make_pair(0,0);\n    }\n    void\
    \ range_add(int a,int b,T x,int k,int l,int r){\n        eval(k,l,r);\n      \
    \  if(a >= r || b <= l)return;\n        else if(a <= l && r <= b){\n         \
    \   lazy[k] = std::make_pair(0,x);\n            eval(k,l,r);\n        }\n    \
    \    else{\n            int m = (l + r) / 2;\n            range_add(a,b,x,k *\
    \ 2 + 1,l,m);\n            range_add(a,b,x,k * 2 + 2,m,r);\n            min_dat[k]\
    \ = std::min(min_dat[k * 2 + 1],min_dat[k * 2 + 2]);\n            max_dat[k] =\
    \ std::max(max_dat[k * 2 + 1],max_dat[k * 2 + 2]);\n            sum_dat[k] = sum_dat[k\
    \ * 2 + 1] + sum_dat[k * 2 + 2];\n        }\n    }\n    void range_add(int a,int\
    \ b,T x){range_add(a,b,x,0,0,n);}\n    void range_update(int a,int b,T x,int k,int\
    \ l,int r){\n        eval(k,l,r);\n        if(a >= r || b <= l)return;\n     \
    \   else if(a <= l && r <= b){\n            lazy[k] = std::make_pair(1,x);\n \
    \           eval(k,l,r);\n        }\n        else{\n            int m = (l + r)\
    \ / 2;\n            range_update(a,b,x,k * 2 + 1,l,m);\n            range_update(a,b,x,k\
    \ * 2 + 2,m,r);\n            min_dat[k] = std::min(min_dat[k * 2 + 1],min_dat[k\
    \ * 2 + 2]);\n            max_dat[k] = std::max(max_dat[k * 2 + 1],max_dat[k *\
    \ 2 + 2]);\n            sum_dat[k] = sum_dat[k * 2 + 1] + sum_dat[k * 2 + 2];\n\
    \        }\n    }\n    void range_update(int a,int b,T x){range_update(a,b,x,0,0,n);}\n\
    \    T range_min(int a,int b,int k,int l,int r){\n        eval(k,l,r);\n     \
    \   if(a >= r || b <= l)return e;\n        else if(a <= l && r <= b)return min_dat[k];\n\
    \        else{\n            int m = (l + r) / 2;\n            return std::min(range_min(a,b,k\
    \ * 2 + 1,l,m),range_min(a,b,k * 2 + 2,m,r));\n        }\n    }\n    T range_min(int\
    \ a,int b){return range_min(a,b,0,0,n);}\n    T range_max(int a,int b,int k,int\
    \ l,int r){\n        eval(k,l,r);\n        if(a >= r || b <= l)return -e;\n  \
    \      else if(a <= l && r <= b)return max_dat[k];\n        else{\n          \
    \  int m = (l + r) / 2;\n            return std::max(range_max(a,b,k * 2 + 1,l,m),range_max(a,b,k\
    \ * 2 + 2,m,r));\n        }\n    }\n    T range_max(int a,int b){return range_max(a,b,0,0,n);}\n\
    \    T range_sum(int a,int b,int k,int l,int r){\n        eval(k,l,r);\n     \
    \   if(a >= r || b <= l)return 0;\n        else if(a <= l && r <= b)return sum_dat[k];\n\
    \        else{\n            int m = (l + r) / 2;\n            return range_sum(a,b,k\
    \ * 2 + 1,l,m) + range_sum(a,b,k * 2 + 2,m,r);\n        }\n    }\n    T range_sum(int\
    \ a,int b){return range_sum(a,b,0,0,n);}\n    T get(int a){return range_min(a,a\
    \ + 1);}\n    void deb(){\n        std::cerr << \"debug: [\";\n        for(int\
    \ i = 0;i < n;i++)std::cerr << range_min(i,i + 1) << (i == n - 1 ? \"]\\n\" :\
    \ \",\");\n    }\n};\n\n\n#line 6 \"test/range-queries/RMQ_RUQ_1.test.cpp\"\n\n\
    int main(){\n    int N,Q;\n    std::cin >> N >> Q;\n    SegTree<int> S(N,2147483647);\n\
    \    S.range_update(0,N,2147483647);\n    for(int i = 0;i < Q;i++){\n        int\
    \ t;\n        std::cin >> t;\n        if(t == 0){\n            int s,t,x;\n  \
    \          std::cin >> s >> t >> x;\n            S.range_update(s,t + 1,x);\n\
    \        }\n        if(t == 1){\n            int s,t;\n            std::cin >>\
    \ s >> t;\n            std::cout << S.range_min(s,t + 1) << \"\\n\";\n       \
    \ }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F\"\
    \n\n#include <iostream>\n\n#include \"../../data-structure/lazysegtree.hpp\"\n\
    \nint main(){\n    int N,Q;\n    std::cin >> N >> Q;\n    SegTree<int> S(N,2147483647);\n\
    \    S.range_update(0,N,2147483647);\n    for(int i = 0;i < Q;i++){\n        int\
    \ t;\n        std::cin >> t;\n        if(t == 0){\n            int s,t,x;\n  \
    \          std::cin >> s >> t >> x;\n            S.range_update(s,t + 1,x);\n\
    \        }\n        if(t == 1){\n            int s,t;\n            std::cin >>\
    \ s >> t;\n            std::cout << S.range_min(s,t + 1) << \"\\n\";\n       \
    \ }\n    }\n}"
  dependsOn: [data-structure/lazysegtree.hpp]
  isVerificationFile: true
  path: test/range-queries/RMQ_RUQ_1.test.cpp
  requiredBy: []
  timestamp: '2021-03-21 13:18:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/range-queries/RMQ_RUQ_1.test.cpp
layout: document
redirect_from: [/verify/test/range-queries/RMQ_RUQ_1.test.cpp, /verify/test/range-queries/RMQ_RUQ_1.test.cpp.html]
title: test/range-queries/RMQ_RUQ_1.test.cpp
---
