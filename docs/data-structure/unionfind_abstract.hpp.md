---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - {icon: ':warning:', path: test/unionfind_abstract.cpp, title: test/unionfind_abstract.cpp}
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/unionfind_abstract.hpp\"\n\n\n\n#include\
    \ <vector>\n#include <algorithm>\n#include <assert.h>\n#include <functional>\n\
    \ntemplate<class T = int>\nstruct UnionFind{\n    int n;\n    std::vector<int>\
    \ par;\n    std::vector<T> dat;\n    using FX = std::function<void(T&,T&)>;\n\
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
    \    }\n};\n\n\n"
  code: "#ifndef SORAIE_UNIONFIND_ABSTRACT\n#define SORAIE_UNIONFIND_ABSTRACT\n\n\
    #include <vector>\n#include <algorithm>\n#include <assert.h>\n#include <functional>\n\
    \ntemplate<class T = int>\nstruct UnionFind{\n    int n;\n    std::vector<int>\
    \ par;\n    std::vector<T> dat;\n    using FX = std::function<void(T&,T&)>;\n\
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
    \    }\n};\n\n#endif /*SORAIE_UNIONFIND_ABSTRACT*/"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/unionfind_abstract.hpp
  requiredBy: [test/unionfind_abstract.cpp]
  timestamp: '2021-03-21 13:18:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/unionfind_abstract.hpp
layout: document
redirect_from: [/library/data-structure/unionfind_abstract.hpp, /library/data-structure/unionfind_abstract.hpp.html]
title: data-structure/unionfind_abstract.hpp
---
