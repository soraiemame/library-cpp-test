---
data:
  _extendedDependsOn:
  - {icon: ':warning:', path: data-structure/unionfind_abstract.hpp, title: data-structure/unionfind_abstract.hpp}
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: ['https://atcoder.jp/contests/abc183/tasks/abc183_f']
  bundledCode: "#line 1 \"test/unionfind_abstract.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc183/tasks/abc183_f\"\
    \n\n#include <iostream>\n#include <map>\n\n#line 1 \"data-structure/unionfind_abstract.hpp\"\
    \n\n\n\n#include <vector>\n#include <algorithm>\n#include <assert.h>\n#include\
    \ <functional>\n\ntemplate<class T = int>\nstruct UnionFind{\n    int n;\n   \
    \ std::vector<int> par;\n    std::vector<T> dat;\n    using FX = std::function<void(T&,T&)>;\n\
    \    FX fx;\n    UnionFind(int n_,FX fx_ = [](T &a,T &b)->void{return;}):n(n_),par(n_,-1),dat(n_),fx(fx_){}\n\
    \    void set(int a,T m){\n        assert(0 <= a && a < n);\n        dat[a] =\
    \ m;\n    }\n    int find(int a){\n        assert(0 <= a && a < n);\n        if(par[a]\
    \ < 0)return a;\n        else return par[a] = find(par[a]);\n    }\n    void unite(int\
    \ a,int b){\n        assert(0 <= a && a < n && 0 <= b && b < n);\n        a =\
    \ find(a);\n        b = find(b);\n        if(a == b)return;\n        if(par[a]\
    \ > par[b])std::swap(a,b);\n        par[a] += par[b];\n        par[b] = a;\n \
    \       fx(dat[a],dat[b]);\n    }\n    bool same(int a,int b){\n        assert(0\
    \ <= a && a < n && 0 <= b && b < n);\n        return find(a) == find(b);\n   \
    \ }\n    int size(int v){\n        assert(0 <= v && v < n);\n        return -par[v];\n\
    \    }\n};\n\n\n#line 7 \"test/unionfind_abstract.cpp\"\n\ntypedef std::map<int,int>\
    \ T;\nvoid fx(T& a,T& b){\n    for(auto &x : b){\n        a[x.first] += x.second;\n\
    \        x.second = 0;\n    }\n}\nint main(){\n    int N,M;\n    std::cin >> N\
    \ >> M;\n    UnionFind<T> UF(N,fx);\n    for(int i = 0;i < N;i++){\n        T\
    \ ma;\n        int n;\n        std::cin >> n;\n        ma[n]++;\n        UF.set(i,ma);\n\
    \    }\n    for(int i = 0;i < M;i++){\n        int t,a,b;\n        std::cin >>\
    \ t >> a >> b;\n        if(t == 1){\n            a--;b--;\n            UF.unite(a,b);\n\
    \        }\n        if(t == 2){\n            a--;\n            std::cout << UF.dat[UF.find(a)][b]\
    \ << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc183/tasks/abc183_f\"\n\n\
    #include <iostream>\n#include <map>\n\n#include \"../data-structure/unionfind_abstract.hpp\"\
    \n\ntypedef std::map<int,int> T;\nvoid fx(T& a,T& b){\n    for(auto &x : b){\n\
    \        a[x.first] += x.second;\n        x.second = 0;\n    }\n}\nint main(){\n\
    \    int N,M;\n    std::cin >> N >> M;\n    UnionFind<T> UF(N,fx);\n    for(int\
    \ i = 0;i < N;i++){\n        T ma;\n        int n;\n        std::cin >> n;\n \
    \       ma[n]++;\n        UF.set(i,ma);\n    }\n    for(int i = 0;i < M;i++){\n\
    \        int t,a,b;\n        std::cin >> t >> a >> b;\n        if(t == 1){\n \
    \           a--;b--;\n            UF.unite(a,b);\n        }\n        if(t == 2){\n\
    \            a--;\n            std::cout << UF.dat[UF.find(a)][b] << \"\\n\";\n\
    \        }\n    }\n}"
  dependsOn: [data-structure/unionfind_abstract.hpp]
  isVerificationFile: false
  path: test/unionfind_abstract.cpp
  requiredBy: []
  timestamp: '2021-03-21 13:18:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/unionfind_abstract.cpp
layout: document
redirect_from: [/library/test/unionfind_abstract.cpp, /library/test/unionfind_abstract.cpp.html]
title: test/unionfind_abstract.cpp
---
