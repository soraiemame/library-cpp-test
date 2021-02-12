#ifndef SORAIE_GRAPH_ALIAS
#define SORAIE_GRAPH_ALIAS

#include <vector>
#include <iostream>

using e_t = long long;
template<class T>
using Graph = std::vector<std::vector<T>>;
struct edge{int to;e_t cost;};
std::ostream &operator<<(std::ostream os,edge& a){return os << "{" << a.to << "," << a.cost << "}";}

struct edge2{int from,to;e_t cost;};
std::ostream &operator<<(std::ostream os,edge2& a){return os << "{" << a.from << "->" << a.to << "," << a.cost << "}";}

#endif /*SORAIE_GRAPH_ALIAS*/