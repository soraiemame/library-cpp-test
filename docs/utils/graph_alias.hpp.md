---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - {icon: ':warning:', path: algorithm/minimum_spanning_tree.hpp, title: algorithm/minimum_spanning_tree.hpp}
  - {icon: ':heavy_check_mark:', path: graph/bellman_ford.hpp, title: graph/bellman_ford.hpp}
  - {icon: ':heavy_check_mark:', path: graph/dijkstra.hpp, title: graph/dijkstra.hpp}
  - {icon: ':heavy_check_mark:', path: graph/warshall_floyd.hpp, title: graph/warshall_floyd.hpp}
  _extendedVerifiedWith:
  - {icon: ':heavy_check_mark:', path: test/bellman_ford.test.cpp, title: test/bellman_ford.test.cpp}
  - {icon: ':heavy_check_mark:', path: test/dijkstra.test.cpp, title: test/dijkstra.test.cpp}
  - {icon: ':heavy_check_mark:', path: test/warshall_floyd.test.cpp, title: test/warshall_floyd.test.cpp}
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: '#line 1 "utils/graph_alias.hpp"




    #include <vector>

    #include <iostream>


    using e_t = long long;

    template<class T>

    using Graph = std::vector<std::vector<T>>;

    struct edge{int to;e_t cost;};

    std::ostream &operator<<(std::ostream os,edge& a){return os << "{" << a.to <<
    "," << a.cost << "}";}


    struct edge2{int from,to;e_t cost;};

    std::ostream &operator<<(std::ostream os,edge2& a){return os << "{" << a.from
    << "->" << a.to << "," << a.cost << "}";}



    '
  code: '#ifndef SORAIE_GRAPH_ALIAS

    #define SORAIE_GRAPH_ALIAS


    #include <vector>

    #include <iostream>


    using e_t = long long;

    template<class T>

    using Graph = std::vector<std::vector<T>>;

    struct edge{int to;e_t cost;};

    std::ostream &operator<<(std::ostream os,edge& a){return os << "{" << a.to <<
    "," << a.cost << "}";}


    struct edge2{int from,to;e_t cost;};

    std::ostream &operator<<(std::ostream os,edge2& a){return os << "{" << a.from
    << "->" << a.to << "," << a.cost << "}";}


    #endif /*SORAIE_GRAPH_ALIAS*/'
  dependsOn: []
  isVerificationFile: false
  path: utils/graph_alias.hpp
  requiredBy: [algorithm/minimum_spanning_tree.hpp, graph/bellman_ford.hpp, graph/dijkstra.hpp,
    graph/warshall_floyd.hpp]
  timestamp: '2021-03-21 13:18:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith: [test/bellman_ford.test.cpp, test/dijkstra.test.cpp, test/warshall_floyd.test.cpp]
documentation_of: utils/graph_alias.hpp
layout: document
redirect_from: [/library/utils/graph_alias.hpp, /library/utils/graph_alias.hpp.html]
title: utils/graph_alias.hpp
---
