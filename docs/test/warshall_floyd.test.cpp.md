---
data:
  _extendedDependsOn:
  - {icon: ':heavy_check_mark:', path: graph/warshall_floyd.hpp, title: graph/warshall_floyd.hpp}
  - {icon: ':heavy_check_mark:', path: utils/graph_alias.hpp, title: utils/graph_alias.hpp}
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
    links: ['https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C']
  bundledCode: "#line 1 \"test/warshall_floyd.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C\"\
    \n\n#include <iostream>\n#include <algorithm>\n#include <vector>\n\n#line 1 \"\
    graph/warshall_floyd.hpp\"\n\n\n\n#line 1 \"utils/graph_alias.hpp\"\n\n\n\n#line\
    \ 6 \"utils/graph_alias.hpp\"\n\nusing e_t = long long;\ntemplate<class T>\nusing\
    \ Graph = std::vector<std::vector<T>>;\nstruct edge{int to;e_t cost;};\nstd::ostream\
    \ &operator<<(std::ostream os,edge& a){return os << \"{\" << a.to << \",\" <<\
    \ a.cost << \"}\";}\n\nstruct edge2{int from,to;e_t cost;};\nstd::ostream &operator<<(std::ostream\
    \ os,edge2& a){return os << \"{\" << a.from << \"->\" << a.to << \",\" << a.cost\
    \ << \"}\";}\n\n\n#line 5 \"graph/warshall_floyd.hpp\"\n\nstd::vector<std::vector<e_t>>\
    \ warshall_floyd(const std::vector<std::vector<e_t>> &G,e_t LM = std::numeric_limits<e_t>::max()){\n\
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
    \     }\n    }\n}\n\n\n#line 8 \"test/warshall_floyd.test.cpp\"\n\n\nint main(){\n\
    \    const e_t INF = 1LL << 60;\n    int N,M;\n    std::cin >> N >> M;\n    std::vector<std::vector<e_t>>\
    \ G(N,std::vector<e_t>(N,INF));\n    for(int i = 0;i < M;i++){\n        int a,b;e_t\
    \ c;\n        std::cin >> a >> b >> c;\n        G[a][b] = std::min(G[a][b],c);\n\
    \    }\n    for(int i = 0;i < N;i++)G[i][i] = 0;\n    auto ans = warshall_floyd(G,INF);\n\
    \    for(int i = 0;i < N;i++)if(ans[i][i] < 0){\n        std::cout << \"NEGATIVE\
    \ CYCLE\\n\";\n        return 0;\n    }\n    \n    for(int i = 0;i < N;i++){\n\
    \        for(int j = 0;j < N;j++){\n            if(ans[i][j] == INF)std::cout\
    \ << \"INF\";\n            else std::cout << ans[i][j];\n            std::cout\
    \ << (j == N - 1 ? \"\\n\":\" \");\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C\"\
    \n\n#include <iostream>\n#include <algorithm>\n#include <vector>\n\n#include \"\
    ../graph/warshall_floyd.hpp\"\n\n\nint main(){\n    const e_t INF = 1LL << 60;\n\
    \    int N,M;\n    std::cin >> N >> M;\n    std::vector<std::vector<e_t>> G(N,std::vector<e_t>(N,INF));\n\
    \    for(int i = 0;i < M;i++){\n        int a,b;e_t c;\n        std::cin >> a\
    \ >> b >> c;\n        G[a][b] = std::min(G[a][b],c);\n    }\n    for(int i = 0;i\
    \ < N;i++)G[i][i] = 0;\n    auto ans = warshall_floyd(G,INF);\n    for(int i =\
    \ 0;i < N;i++)if(ans[i][i] < 0){\n        std::cout << \"NEGATIVE CYCLE\\n\";\n\
    \        return 0;\n    }\n    \n    for(int i = 0;i < N;i++){\n        for(int\
    \ j = 0;j < N;j++){\n            if(ans[i][j] == INF)std::cout << \"INF\";\n \
    \           else std::cout << ans[i][j];\n            std::cout << (j == N - 1\
    \ ? \"\\n\":\" \");\n        }\n    }\n}"
  dependsOn: [graph/warshall_floyd.hpp, utils/graph_alias.hpp]
  isVerificationFile: true
  path: test/warshall_floyd.test.cpp
  requiredBy: []
  timestamp: '2021-03-21 13:18:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/warshall_floyd.test.cpp
layout: document
redirect_from: [/verify/test/warshall_floyd.test.cpp, /verify/test/warshall_floyd.test.cpp.html]
title: test/warshall_floyd.test.cpp
---
