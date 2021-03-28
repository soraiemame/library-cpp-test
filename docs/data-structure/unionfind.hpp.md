---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - {icon: ':warning:', path: algorithm/minimum_spanning_tree.hpp, title: algorithm/minimum_spanning_tree.hpp}
  _extendedVerifiedWith:
  - {icon: ':heavy_check_mark:', path: test/unionfind.test.cpp, title: test/unionfind.test.cpp}
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/unionfind.hpp\"\n\n\n\n#include <vector>\n\
    #include <algorithm>\n#include <assert.h>\n\nstruct UnionFind{\n    int n;\n \
    \   std::vector<int> dat;\n    UnionFind(int n_){init(n_);}\n    void init(int\
    \ n_){\n        n = n_;\n        dat = std::vector<int>(n_,-1);\n    }\n    int\
    \ find(int v){\n        assert(0 <= v && v < n);\n        if(dat[v] < 0)return\
    \ v;\n        else return dat[v] = find(dat[v]);\n    }\n    void unite(int a,int\
    \ b){\n        assert(0 <= a && a < n && 0 <= b && b < n);\n        a = find(a);\n\
    \        b = find(b);\n        if(a == b)return;\n        if(dat[a] > dat[b])std::swap(a,b);\n\
    \        dat[a] += dat[b];\n        dat[b] = a;\n    }\n    bool same(int a,int\
    \ b){\n        assert(0 <= a && a < n && 0 <= b && b < n);\n        return find(a)\
    \ == find(b);\n    }\n    int size(int v){\n        assert(0 <= v && v < n);\n\
    \        return -dat[v];\n    }\n};\n\n\n"
  code: "#ifndef SORAIE_UNIONFIND\n#define SORAIE_UNIONFIND\n\n#include <vector>\n\
    #include <algorithm>\n#include <assert.h>\n\nstruct UnionFind{\n    int n;\n \
    \   std::vector<int> dat;\n    UnionFind(int n_){init(n_);}\n    void init(int\
    \ n_){\n        n = n_;\n        dat = std::vector<int>(n_,-1);\n    }\n    int\
    \ find(int v){\n        assert(0 <= v && v < n);\n        if(dat[v] < 0)return\
    \ v;\n        else return dat[v] = find(dat[v]);\n    }\n    void unite(int a,int\
    \ b){\n        assert(0 <= a && a < n && 0 <= b && b < n);\n        a = find(a);\n\
    \        b = find(b);\n        if(a == b)return;\n        if(dat[a] > dat[b])std::swap(a,b);\n\
    \        dat[a] += dat[b];\n        dat[b] = a;\n    }\n    bool same(int a,int\
    \ b){\n        assert(0 <= a && a < n && 0 <= b && b < n);\n        return find(a)\
    \ == find(b);\n    }\n    int size(int v){\n        assert(0 <= v && v < n);\n\
    \        return -dat[v];\n    }\n};\n\n#endif /*SORAIE_UNIONFIND*/"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/unionfind.hpp
  requiredBy: [algorithm/minimum_spanning_tree.hpp]
  timestamp: '2021-03-21 13:18:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith: [test/unionfind.test.cpp]
documentation_of: data-structure/unionfind.hpp
layout: document
redirect_from: [/library/data-structure/unionfind.hpp, /library/data-structure/unionfind.hpp.html]
title: data-structure/unionfind.hpp
---
