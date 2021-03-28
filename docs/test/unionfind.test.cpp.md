---
data:
  _extendedDependsOn:
  - {icon: ':heavy_check_mark:', path: data-structure/unionfind.hpp, title: data-structure/unionfind.hpp}
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links: ['https://judge.yosupo.jp/problem/unionfind']
  bundledCode: "#line 1 \"test/unionfind.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n\n#include <iostream>\n\n#line 1 \"data-structure/unionfind.hpp\"\n\n\n\n#include\
    \ <vector>\n#include <algorithm>\n#include <assert.h>\n\nstruct UnionFind{\n \
    \   int n;\n    std::vector<int> dat;\n    UnionFind(int n_){init(n_);}\n    void\
    \ init(int n_){\n        n = n_;\n        dat = std::vector<int>(n_,-1);\n   \
    \ }\n    int find(int v){\n        assert(0 <= v && v < n);\n        if(dat[v]\
    \ < 0)return v;\n        else return dat[v] = find(dat[v]);\n    }\n    void unite(int\
    \ a,int b){\n        assert(0 <= a && a < n && 0 <= b && b < n);\n        a =\
    \ find(a);\n        b = find(b);\n        if(a == b)return;\n        if(dat[a]\
    \ > dat[b])std::swap(a,b);\n        dat[a] += dat[b];\n        dat[b] = a;\n \
    \   }\n    bool same(int a,int b){\n        assert(0 <= a && a < n && 0 <= b &&\
    \ b < n);\n        return find(a) == find(b);\n    }\n    int size(int v){\n \
    \       assert(0 <= v && v < n);\n        return -dat[v];\n    }\n};\n\n\n#line\
    \ 6 \"test/unionfind.test.cpp\"\n\nint main(){\n    int N,Q;\n    std::cin >>\
    \ N >> Q;\n    UnionFind UF(N);\n    for(int i = 0;i < Q;i++){\n        int t,u,v;\n\
    \        std::cin >> t >> u >> v;\n        if(t == 0)UF.unite(u,v);\n        if(t\
    \ == 1)std::cout << UF.same(u,v) << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ <iostream>\n\n#include \"../data-structure/unionfind.hpp\"\n\nint main(){\n\
    \    int N,Q;\n    std::cin >> N >> Q;\n    UnionFind UF(N);\n    for(int i =\
    \ 0;i < Q;i++){\n        int t,u,v;\n        std::cin >> t >> u >> v;\n      \
    \  if(t == 0)UF.unite(u,v);\n        if(t == 1)std::cout << UF.same(u,v) << \"\
    \\n\";\n    }\n}"
  dependsOn: [data-structure/unionfind.hpp]
  isVerificationFile: true
  path: test/unionfind.test.cpp
  requiredBy: []
  timestamp: '2021-03-21 13:18:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unionfind.test.cpp
layout: document
redirect_from: [/verify/test/unionfind.test.cpp, /verify/test/unionfind.test.cpp.html]
title: test/unionfind.test.cpp
---
