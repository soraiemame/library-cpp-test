---
data:
  _extendedDependsOn:
  - {icon: ':heavy_check_mark:', path: graph/dijkstra.hpp, title: graph/dijkstra.hpp}
  - {icon: ':heavy_check_mark:', path: utils/graph_alias.hpp, title: utils/graph_alias.hpp}
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A
    links: ['https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A']
  bundledCode: "#line 1 \"test/dijkstra.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\
    \n\n#include <iostream>\n#include <vector>\n\n#line 1 \"graph/dijkstra.hpp\"\n\
    \n\n\n#line 1 \"utils/graph_alias.hpp\"\n\n\n\n#line 6 \"utils/graph_alias.hpp\"\
    \n\nusing e_t = long long;\ntemplate<class T>\nusing Graph = std::vector<std::vector<T>>;\n\
    struct edge{int to;e_t cost;};\nstd::ostream &operator<<(std::ostream os,edge&\
    \ a){return os << \"{\" << a.to << \",\" << a.cost << \"}\";}\n\nstruct edge2{int\
    \ from,to;e_t cost;};\nstd::ostream &operator<<(std::ostream os,edge2& a){return\
    \ os << \"{\" << a.from << \"->\" << a.to << \",\" << a.cost << \"}\";}\n\n\n\
    #line 5 \"graph/dijkstra.hpp\"\n#include <algorithm>\n#include <queue>\n\nstd::vector<e_t>\
    \ dijkstra(const Graph<edge>& G,const std::vector<int>& st,e_t LM = std::numeric_limits<e_t>::max()){\n\
    \    std::vector<e_t> res(G.size(),LM);\n    std::priority_queue<std::pair<e_t,int>,std::vector<std::pair<e_t,int>>,std::greater<std::pair<e_t,int>>>\
    \ que;\n    for(const int &a : st){\n        que.push(std::make_pair(0,a));\n\
    \        res[a] = 0;\n    }\n    while(!que.empty()){\n        auto p = que.top();\n\
    \        que.pop();\n        if(res[p.second] < p.first)continue;\n        for(const\
    \ edge &e : G[p.second]){\n            if(res[e.to] > res[p.second] + e.cost){\n\
    \                res[e.to] = res[p.second] + e.cost;\n                que.push(std::make_pair(res[e.to],e.to));\n\
    \            }\n        }\n    }\n    return res;\n}\n\n\n#line 7 \"test/dijkstra.test.cpp\"\
    \n\nint main(){\n    int N,M,S;\n    std::cin >> N >> M >> S;\n    std::vector<std::vector<edge>>\
    \ G(N);\n    for(int i = 0;i < M;i++){\n        int a,b;e_t c;\n        std::cin\
    \ >> a >> b >> c;\n        G[a].push_back({b,c});\n    }\n    const e_t INF =\
    \ 1LL << 60;\n    auto ans = dijkstra(G,{S},INF);\n    for(int i = 0;i < N;i++){\n\
    \        if(ans[i] == INF)std::cout << \"INF\\n\";\n        else std::cout <<\
    \ ans[i] << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../graph/dijkstra.hpp\"\
    \n\nint main(){\n    int N,M,S;\n    std::cin >> N >> M >> S;\n    std::vector<std::vector<edge>>\
    \ G(N);\n    for(int i = 0;i < M;i++){\n        int a,b;e_t c;\n        std::cin\
    \ >> a >> b >> c;\n        G[a].push_back({b,c});\n    }\n    const e_t INF =\
    \ 1LL << 60;\n    auto ans = dijkstra(G,{S},INF);\n    for(int i = 0;i < N;i++){\n\
    \        if(ans[i] == INF)std::cout << \"INF\\n\";\n        else std::cout <<\
    \ ans[i] << \"\\n\";\n    }\n}"
  dependsOn: [graph/dijkstra.hpp, utils/graph_alias.hpp]
  isVerificationFile: true
  path: test/dijkstra.test.cpp
  requiredBy: []
  timestamp: '2021-03-21 13:18:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/dijkstra.test.cpp
layout: document
redirect_from: [/verify/test/dijkstra.test.cpp, /verify/test/dijkstra.test.cpp.html]
title: test/dijkstra.test.cpp
---
