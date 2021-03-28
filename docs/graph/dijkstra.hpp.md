---
data:
  _extendedDependsOn:
  - {icon: ':heavy_check_mark:', path: utils/graph_alias.hpp, title: utils/graph_alias.hpp}
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - {icon: ':heavy_check_mark:', path: test/dijkstra.test.cpp, title: test/dijkstra.test.cpp}
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/dijkstra.hpp\"\n\n\n\n#line 1 \"utils/graph_alias.hpp\"\
    \n\n\n\n#include <vector>\n#include <iostream>\n\nusing e_t = long long;\ntemplate<class\
    \ T>\nusing Graph = std::vector<std::vector<T>>;\nstruct edge{int to;e_t cost;};\n\
    std::ostream &operator<<(std::ostream os,edge& a){return os << \"{\" << a.to <<\
    \ \",\" << a.cost << \"}\";}\n\nstruct edge2{int from,to;e_t cost;};\nstd::ostream\
    \ &operator<<(std::ostream os,edge2& a){return os << \"{\" << a.from << \"->\"\
    \ << a.to << \",\" << a.cost << \"}\";}\n\n\n#line 5 \"graph/dijkstra.hpp\"\n\
    #include <algorithm>\n#include <queue>\n\nstd::vector<e_t> dijkstra(const Graph<edge>&\
    \ G,const std::vector<int>& st,e_t LM = std::numeric_limits<e_t>::max()){\n  \
    \  std::vector<e_t> res(G.size(),LM);\n    std::priority_queue<std::pair<e_t,int>,std::vector<std::pair<e_t,int>>,std::greater<std::pair<e_t,int>>>\
    \ que;\n    for(const int &a : st){\n        que.push(std::make_pair(0,a));\n\
    \        res[a] = 0;\n    }\n    while(!que.empty()){\n        auto p = que.top();\n\
    \        que.pop();\n        if(res[p.second] < p.first)continue;\n        for(const\
    \ edge &e : G[p.second]){\n            if(res[e.to] > res[p.second] + e.cost){\n\
    \                res[e.to] = res[p.second] + e.cost;\n                que.push(std::make_pair(res[e.to],e.to));\n\
    \            }\n        }\n    }\n    return res;\n}\n\n\n"
  code: "#ifndef SORAIE_DIJKSTRA\n#define SORAIE_DIJKSTRA\n\n#include \"../utils/graph_alias.hpp\"\
    \n#include <algorithm>\n#include <queue>\n\nstd::vector<e_t> dijkstra(const Graph<edge>&\
    \ G,const std::vector<int>& st,e_t LM = std::numeric_limits<e_t>::max()){\n  \
    \  std::vector<e_t> res(G.size(),LM);\n    std::priority_queue<std::pair<e_t,int>,std::vector<std::pair<e_t,int>>,std::greater<std::pair<e_t,int>>>\
    \ que;\n    for(const int &a : st){\n        que.push(std::make_pair(0,a));\n\
    \        res[a] = 0;\n    }\n    while(!que.empty()){\n        auto p = que.top();\n\
    \        que.pop();\n        if(res[p.second] < p.first)continue;\n        for(const\
    \ edge &e : G[p.second]){\n            if(res[e.to] > res[p.second] + e.cost){\n\
    \                res[e.to] = res[p.second] + e.cost;\n                que.push(std::make_pair(res[e.to],e.to));\n\
    \            }\n        }\n    }\n    return res;\n}\n\n#endif /*SORAIE_DIJKSTRA*/"
  dependsOn: [utils/graph_alias.hpp]
  isVerificationFile: false
  path: graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2021-03-21 13:18:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith: [test/dijkstra.test.cpp]
documentation_of: graph/dijkstra.hpp
layout: document
redirect_from: [/library/graph/dijkstra.hpp, /library/graph/dijkstra.hpp.html]
title: graph/dijkstra.hpp
---
