---
data:
  _extendedDependsOn:
  - {icon: ':heavy_check_mark:', path: utils/graph_alias.hpp, title: utils/graph_alias.hpp}
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - {icon: ':heavy_check_mark:', path: test/bellman_ford.test.cpp, title: test/bellman_ford.test.cpp}
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/bellman_ford.hpp\"\n\n\n\n#line 1 \"utils/graph_alias.hpp\"\
    \n\n\n\n#include <vector>\n#include <iostream>\n\nusing e_t = long long;\ntemplate<class\
    \ T>\nusing Graph = std::vector<std::vector<T>>;\nstruct edge{int to;e_t cost;};\n\
    std::ostream &operator<<(std::ostream os,edge& a){return os << \"{\" << a.to <<\
    \ \",\" << a.cost << \"}\";}\n\nstruct edge2{int from,to;e_t cost;};\nstd::ostream\
    \ &operator<<(std::ostream os,edge2& a){return os << \"{\" << a.from << \"->\"\
    \ << a.to << \",\" << a.cost << \"}\";}\n\n\n#line 5 \"graph/bellman_ford.hpp\"\
    \n\nstd::vector<e_t> bellman_ford(const std::vector<edge2> &G,int n,const std::vector<int>&\
    \ st,e_t LM = std::numeric_limits<e_t>::max()){\n    std::vector<e_t> res(n,LM);\n\
    \    for(const int& a : st)res[a] = 0;\n    for(int i = 0;i <= n;i++){\n     \
    \   bool updated = false;\n        for(const auto &e : G){\n            if(res[e.from]\
    \ == LM)continue;\n            if(res[e.to] > res[e.from] + e.cost){\n       \
    \         res[e.to] = res[e.from] + e.cost;\n                updated = true;\n\
    \            }\n        }\n        if(i == n && updated)res = std::vector<e_t>(n,LM);\n\
    \    }\n    return res;\n}\n\n\n"
  code: "#ifndef SORAIE_BELLMAN_FORD\n#define SORAIE_BELLMAN_FORD\n\n#include \"../utils/graph_alias.hpp\"\
    \n\nstd::vector<e_t> bellman_ford(const std::vector<edge2> &G,int n,const std::vector<int>&\
    \ st,e_t LM = std::numeric_limits<e_t>::max()){\n    std::vector<e_t> res(n,LM);\n\
    \    for(const int& a : st)res[a] = 0;\n    for(int i = 0;i <= n;i++){\n     \
    \   bool updated = false;\n        for(const auto &e : G){\n            if(res[e.from]\
    \ == LM)continue;\n            if(res[e.to] > res[e.from] + e.cost){\n       \
    \         res[e.to] = res[e.from] + e.cost;\n                updated = true;\n\
    \            }\n        }\n        if(i == n && updated)res = std::vector<e_t>(n,LM);\n\
    \    }\n    return res;\n}\n\n#endif /*SORAIE_BELLMAN_FORD*/"
  dependsOn: [utils/graph_alias.hpp]
  isVerificationFile: false
  path: graph/bellman_ford.hpp
  requiredBy: []
  timestamp: '2021-03-27 18:53:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith: [test/bellman_ford.test.cpp]
documentation_of: graph/bellman_ford.hpp
layout: document
redirect_from: [/library/graph/bellman_ford.hpp, /library/graph/bellman_ford.hpp.html]
title: graph/bellman_ford.hpp
---
