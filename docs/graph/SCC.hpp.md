---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - {icon: ':heavy_check_mark:', path: test/SCC.test.cpp, title: test/SCC.test.cpp}
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/SCC.hpp\"\n\n\n\n#include <vector>\n\nstruct SCC{\n\
    private:\n    int n,k;\n    std::vector<std::vector<int>> G,RG;\n    std::vector<bool>\
    \ use;\n    std::vector<int> ret,topo;\n    void dfs1(int v){\n        use[v]\
    \ = true;\n        for(int x : G[v])if(!use[x])dfs1(x);\n        ret.push_back(v);\n\
    \    }\n    void dfs2(int v,int k){\n        topo[v] = k;\n        use[v] = true;\n\
    \        for(int x : RG[v])if(!use[x])dfs2(x,k);\n    }\n    void init(const std::vector<std::vector<int>>&\
    \ _G){\n        n = _G.size();k = -1;\n        use.resize(n,false);topo.resize(n,0);\n\
    \        G = _G;RG.resize(n);\n        for(int i = 0;i < n;i++)for(const int &x\
    \ : _G[i])RG[x].push_back(i);\n    }\npublic:\n    void build(){\n        k =\
    \ 0;\n        for(int i = 0;i < n;i++)if(!use[i])dfs1(i);\n        use.assign(n,false);\n\
    \        for(int i = n - 1;i >= 0;i--)if(!use[ret[i]])dfs2(ret[i],k++);\n    }\n\
    \    std::vector<std::vector<int>> components(){\n        if(k == -1)build();\n\
    \        std::vector<std::vector<int>> res(k);\n        for(int i = 0;i < n;i++)res[topo[i]].push_back(i);\n\
    \        return res;\n    }\n    std::vector<std::vector<int>> compressed(){\n\
    \        if(k == -1)build();\n        std::vector<std::vector<int>> res(n);\n\
    \        for(int i = 0;i < n;i++)for(auto x : G[i])res[topo[i]].push_back(topo[x]);\n\
    \        return res;\n    }\n    \n    SCC(int _n = 0){init(std::vector<std::vector<int>>(_n));}\n\
    \    SCC(const std::vector<std::vector<int>>& _G){init(_G);}\n    void add_edge(int\
    \ a,int b){\n        G[a].push_back(b);\n        RG[b].push_back(a);\n    }\n\
    };\n\n\n"
  code: "#ifndef SORAIE_SCC\n#define SORAIE_SCC\n\n#include <vector>\n\nstruct SCC{\n\
    private:\n    int n,k;\n    std::vector<std::vector<int>> G,RG;\n    std::vector<bool>\
    \ use;\n    std::vector<int> ret,topo;\n    void dfs1(int v){\n        use[v]\
    \ = true;\n        for(int x : G[v])if(!use[x])dfs1(x);\n        ret.push_back(v);\n\
    \    }\n    void dfs2(int v,int k){\n        topo[v] = k;\n        use[v] = true;\n\
    \        for(int x : RG[v])if(!use[x])dfs2(x,k);\n    }\n    void init(const std::vector<std::vector<int>>&\
    \ _G){\n        n = _G.size();k = -1;\n        use.resize(n,false);topo.resize(n,0);\n\
    \        G = _G;RG.resize(n);\n        for(int i = 0;i < n;i++)for(const int &x\
    \ : _G[i])RG[x].push_back(i);\n    }\npublic:\n    void build(){\n        k =\
    \ 0;\n        for(int i = 0;i < n;i++)if(!use[i])dfs1(i);\n        use.assign(n,false);\n\
    \        for(int i = n - 1;i >= 0;i--)if(!use[ret[i]])dfs2(ret[i],k++);\n    }\n\
    \    std::vector<std::vector<int>> components(){\n        if(k == -1)build();\n\
    \        std::vector<std::vector<int>> res(k);\n        for(int i = 0;i < n;i++)res[topo[i]].push_back(i);\n\
    \        return res;\n    }\n    std::vector<std::vector<int>> compressed(){\n\
    \        if(k == -1)build();\n        std::vector<std::vector<int>> res(n);\n\
    \        for(int i = 0;i < n;i++)for(auto x : G[i])res[topo[i]].push_back(topo[x]);\n\
    \        return res;\n    }\n    \n    SCC(int _n = 0){init(std::vector<std::vector<int>>(_n));}\n\
    \    SCC(const std::vector<std::vector<int>>& _G){init(_G);}\n    void add_edge(int\
    \ a,int b){\n        G[a].push_back(b);\n        RG[b].push_back(a);\n    }\n\
    };\n\n#endif /*SORAIE_SCC*/"
  dependsOn: []
  isVerificationFile: false
  path: graph/SCC.hpp
  requiredBy: []
  timestamp: '2021-03-21 13:18:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith: [test/SCC.test.cpp]
documentation_of: graph/SCC.hpp
layout: document
redirect_from: [/library/graph/SCC.hpp, /library/graph/SCC.hpp.html]
title: graph/SCC.hpp
---
