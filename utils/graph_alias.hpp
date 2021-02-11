#ifndef SORAIE_GRAPH_ALIAS
#define SORAIE_GRAPH_ALIAS

#include <vector>
using e_t = long long;
template<class T>
using Graph = std::vector<std::vector<T>>;
struct edge{int to;e_t cost;};
struct bellman_edge{int from,to;e_t cost;};

#endif /*SORAIE_GRAPH_ALIAS*/