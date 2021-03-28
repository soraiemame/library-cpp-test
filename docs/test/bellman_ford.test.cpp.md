---
data:
  _extendedDependsOn:
  - {icon: ':heavy_check_mark:', path: graph/bellman_ford.hpp, title: graph/bellman_ford.hpp}
  - {icon: ':heavy_check_mark:', path: utils/graph_alias.hpp, title: utils/graph_alias.hpp}
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
    links: ['https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B']
  bundledCode: "#line 1 \"test/bellman_ford.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B\"\
    \n\n#include <iostream>\n#include <vector>\n\n#line 1 \"graph/bellman_ford.hpp\"\
    \n\n\n\n#line 1 \"utils/graph_alias.hpp\"\n\n\n\n#line 6 \"utils/graph_alias.hpp\"\
    \n\nusing e_t = long long;\ntemplate<class T>\nusing Graph = std::vector<std::vector<T>>;\n\
    struct edge{int to;e_t cost;};\nstd::ostream &operator<<(std::ostream os,edge&\
    \ a){return os << \"{\" << a.to << \",\" << a.cost << \"}\";}\n\nstruct edge2{int\
    \ from,to;e_t cost;};\nstd::ostream &operator<<(std::ostream os,edge2& a){return\
    \ os << \"{\" << a.from << \"->\" << a.to << \",\" << a.cost << \"}\";}\n\n\n\
    #line 5 \"graph/bellman_ford.hpp\"\n\nstd::vector<e_t> bellman_ford(const std::vector<edge2>\
    \ &G,int n,const std::vector<int>& st,e_t LM = std::numeric_limits<e_t>::max()){\n\
    \    std::vector<e_t> res(n,LM);\n    for(const int& a : st)res[a] = 0;\n    for(int\
    \ i = 0;i <= n;i++){\n        bool updated = false;\n        for(const auto &e\
    \ : G){\n            if(res[e.from] == LM)continue;\n            if(res[e.to]\
    \ > res[e.from] + e.cost){\n                res[e.to] = res[e.from] + e.cost;\n\
    \                updated = true;\n            }\n        }\n        if(i == n\
    \ && updated)res = std::vector<e_t>(n,LM);\n    }\n    return res;\n}\n\n\n#line\
    \ 7 \"test/bellman_ford.test.cpp\"\n\nint main(){\n    int N,M,S;\n    std::cin\
    \ >> N >> M >> S;\n    std::vector<edge2> G(M);\n    for(int i = 0;i < M;i++)std::cin\
    \ >> G[i].from >> G[i].to >> G[i].cost;\n    const e_t INF = 1LL << 60;\n    auto\
    \ ans = bellman_ford(G,N,{S},INF);\n    if(ans[S] == INF)std::cout << \"NEGATIVE\
    \ CYCLE\\n\";\n    else{\n        for(e_t &x : ans){\n            if(x == INF)std::cout\
    \ << \"INF\\n\";\n            else std::cout << x << \"\\n\";\n        }\n   \
    \ }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../graph/bellman_ford.hpp\"\
    \n\nint main(){\n    int N,M,S;\n    std::cin >> N >> M >> S;\n    std::vector<edge2>\
    \ G(M);\n    for(int i = 0;i < M;i++)std::cin >> G[i].from >> G[i].to >> G[i].cost;\n\
    \    const e_t INF = 1LL << 60;\n    auto ans = bellman_ford(G,N,{S},INF);\n \
    \   if(ans[S] == INF)std::cout << \"NEGATIVE CYCLE\\n\";\n    else{\n        for(e_t\
    \ &x : ans){\n            if(x == INF)std::cout << \"INF\\n\";\n            else\
    \ std::cout << x << \"\\n\";\n        }\n    }\n}"
  dependsOn: [graph/bellman_ford.hpp, utils/graph_alias.hpp]
  isVerificationFile: true
  path: test/bellman_ford.test.cpp
  requiredBy: []
  timestamp: '2021-03-27 18:53:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/bellman_ford.test.cpp
layout: document
redirect_from: [/verify/test/bellman_ford.test.cpp, /verify/test/bellman_ford.test.cpp.html]
title: test/bellman_ford.test.cpp
---
