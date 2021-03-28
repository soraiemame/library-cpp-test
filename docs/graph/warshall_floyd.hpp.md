---
data:
  _extendedDependsOn:
  - {icon: ':heavy_check_mark:', path: utils/graph_alias.hpp, title: utils/graph_alias.hpp}
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - {icon: ':heavy_check_mark:', path: test/warshall_floyd.test.cpp, title: test/warshall_floyd.test.cpp}
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/warshall_floyd.hpp\"\n\n\n\n#line 1 \"utils/graph_alias.hpp\"\
    \n\n\n\n#include <vector>\n#include <iostream>\n\nusing e_t = long long;\ntemplate<class\
    \ T>\nusing Graph = std::vector<std::vector<T>>;\nstruct edge{int to;e_t cost;};\n\
    std::ostream &operator<<(std::ostream os,edge& a){return os << \"{\" << a.to <<\
    \ \",\" << a.cost << \"}\";}\n\nstruct edge2{int from,to;e_t cost;};\nstd::ostream\
    \ &operator<<(std::ostream os,edge2& a){return os << \"{\" << a.from << \"->\"\
    \ << a.to << \",\" << a.cost << \"}\";}\n\n\n#line 5 \"graph/warshall_floyd.hpp\"\
    \n\nstd::vector<std::vector<e_t>> warshall_floyd(const std::vector<std::vector<e_t>>\
    \ &G,e_t LM = std::numeric_limits<e_t>::max()){\n    std::vector<std::vector<e_t>>\
    \ res = G;\n    int n = res.size();\n    for(int i = 0;i < n;i++){\n        for(int\
    \ j = 0;j < n;j++){\n            for(int k = 0;k < n;k++){\n                if(res[j][i]\
    \ == LM || res[i][k] == LM)continue;\n                else if(res[j][k] > res[j][i]\
    \ + res[i][k])res[j][k] = res[j][i] + res[i][k];\n            }\n        }\n \
    \   }\n    return res;\n}\n\nvoid append(std::vector<std::vector<e_t>> &G,int\
    \ from,int to,e_t cost,e_t LM = std::numeric_limits<e_t>::max()){\n    if(G[from][to]\
    \ <= cost)return;\n    int n = G.size();\n    G[from][to] = cost;\n    for(int\
    \ i = 0;i < n;i++){\n        for(int j = 0;j < n;j++){\n            if(G[i][from]\
    \ == LM || G[to][j] == LM)continue;\n            else if(G[i][j] > G[i][from]\
    \ + cost + G[to][j])G[i][j] = G[i][from] + cost + G[to][j];\n        }\n    }\n\
    }\n\n\n"
  code: "#ifndef SORAIE_WARSHALL_FLOYD\n#define SORAIE_WARSHALL_FLOYD\n\n#include\
    \ \"../utils/graph_alias.hpp\"\n\nstd::vector<std::vector<e_t>> warshall_floyd(const\
    \ std::vector<std::vector<e_t>> &G,e_t LM = std::numeric_limits<e_t>::max()){\n\
    \    std::vector<std::vector<e_t>> res = G;\n    int n = res.size();\n    for(int\
    \ i = 0;i < n;i++){\n        for(int j = 0;j < n;j++){\n            for(int k\
    \ = 0;k < n;k++){\n                if(res[j][i] == LM || res[i][k] == LM)continue;\n\
    \                else if(res[j][k] > res[j][i] + res[i][k])res[j][k] = res[j][i]\
    \ + res[i][k];\n            }\n        }\n    }\n    return res;\n}\n\nvoid append(std::vector<std::vector<e_t>>\
    \ &G,int from,int to,e_t cost,e_t LM = std::numeric_limits<e_t>::max()){\n   \
    \ if(G[from][to] <= cost)return;\n    int n = G.size();\n    G[from][to] = cost;\n\
    \    for(int i = 0;i < n;i++){\n        for(int j = 0;j < n;j++){\n          \
    \  if(G[i][from] == LM || G[to][j] == LM)continue;\n            else if(G[i][j]\
    \ > G[i][from] + cost + G[to][j])G[i][j] = G[i][from] + cost + G[to][j];\n   \
    \     }\n    }\n}\n\n#endif /*SORAIE_WARSHALL_FLOYD*/"
  dependsOn: [utils/graph_alias.hpp]
  isVerificationFile: false
  path: graph/warshall_floyd.hpp
  requiredBy: []
  timestamp: '2021-03-21 13:18:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith: [test/warshall_floyd.test.cpp]
documentation_of: graph/warshall_floyd.hpp
layout: document
redirect_from: [/library/graph/warshall_floyd.hpp, /library/graph/warshall_floyd.hpp.html]
title: graph/warshall_floyd.hpp
---
