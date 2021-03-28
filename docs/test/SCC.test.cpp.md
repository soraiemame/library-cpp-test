---
data:
  _extendedDependsOn:
  - {icon: ':heavy_check_mark:', path: graph/SCC.hpp, title: graph/SCC.hpp}
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links: ['https://judge.yosupo.jp/problem/scc']
  bundledCode: "#line 1 \"test/SCC.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\
    \n\n#include <iostream>\n\n#line 1 \"graph/SCC.hpp\"\n\n\n\n#include <vector>\n\
    \nstruct SCC{\nprivate:\n    int n,k;\n    std::vector<std::vector<int>> G,RG;\n\
    \    std::vector<bool> use;\n    std::vector<int> ret,topo;\n    void dfs1(int\
    \ v){\n        use[v] = true;\n        for(int x : G[v])if(!use[x])dfs1(x);\n\
    \        ret.push_back(v);\n    }\n    void dfs2(int v,int k){\n        topo[v]\
    \ = k;\n        use[v] = true;\n        for(int x : RG[v])if(!use[x])dfs2(x,k);\n\
    \    }\n    void init(const std::vector<std::vector<int>>& _G){\n        n = _G.size();k\
    \ = -1;\n        use.resize(n,false);topo.resize(n,0);\n        G = _G;RG.resize(n);\n\
    \        for(int i = 0;i < n;i++)for(const int &x : _G[i])RG[x].push_back(i);\n\
    \    }\npublic:\n    void build(){\n        k = 0;\n        for(int i = 0;i <\
    \ n;i++)if(!use[i])dfs1(i);\n        use.assign(n,false);\n        for(int i =\
    \ n - 1;i >= 0;i--)if(!use[ret[i]])dfs2(ret[i],k++);\n    }\n    std::vector<std::vector<int>>\
    \ components(){\n        if(k == -1)build();\n        std::vector<std::vector<int>>\
    \ res(k);\n        for(int i = 0;i < n;i++)res[topo[i]].push_back(i);\n      \
    \  return res;\n    }\n    std::vector<std::vector<int>> compressed(){\n     \
    \   if(k == -1)build();\n        std::vector<std::vector<int>> res(n);\n     \
    \   for(int i = 0;i < n;i++)for(auto x : G[i])res[topo[i]].push_back(topo[x]);\n\
    \        return res;\n    }\n    \n    SCC(int _n = 0){init(std::vector<std::vector<int>>(_n));}\n\
    \    SCC(const std::vector<std::vector<int>>& _G){init(_G);}\n    void add_edge(int\
    \ a,int b){\n        G[a].push_back(b);\n        RG[b].push_back(a);\n    }\n\
    };\n\n\n#line 6 \"test/SCC.test.cpp\"\n\nint main(){\n    int N,M;\n    std::cin\
    \ >> N >> M;\n    SCC scc(N);\n    for(int i = 0;i < M;i++){\n        int a,b;\n\
    \        std::cin >> a >> b;\n        scc.add_edge(a,b);\n    }\n    scc.build();\n\
    \    auto ans = scc.components();\n    std::cout << ans.size() << \"\\n\";\n \
    \   for(auto x : ans){\n        std::cout << x.size();\n        for(int i = 0;i\
    \ < int(x.size());i++)std::cout << \" \" << x[i];\n        std::cout << \"\\n\"\
    ;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include <iostream>\n\
    \n#include \"../graph/SCC.hpp\"\n\nint main(){\n    int N,M;\n    std::cin >>\
    \ N >> M;\n    SCC scc(N);\n    for(int i = 0;i < M;i++){\n        int a,b;\n\
    \        std::cin >> a >> b;\n        scc.add_edge(a,b);\n    }\n    scc.build();\n\
    \    auto ans = scc.components();\n    std::cout << ans.size() << \"\\n\";\n \
    \   for(auto x : ans){\n        std::cout << x.size();\n        for(int i = 0;i\
    \ < int(x.size());i++)std::cout << \" \" << x[i];\n        std::cout << \"\\n\"\
    ;\n    }\n}"
  dependsOn: [graph/SCC.hpp]
  isVerificationFile: true
  path: test/SCC.test.cpp
  requiredBy: []
  timestamp: '2021-03-21 13:18:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/SCC.test.cpp
layout: document
redirect_from: [/verify/test/SCC.test.cpp, /verify/test/SCC.test.cpp.html]
title: test/SCC.test.cpp
---
