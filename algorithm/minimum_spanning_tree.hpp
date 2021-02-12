#ifndef SORAIE_MST
#define SORAIE_MST

#include <vector>
#include <algorithm>

#include "../data-structure/unionfind.hpp"
#include "../utils/graph_alias.hpp"

std::pair<e_t,std::vector<edge2>> minimum_spanning_tree(const std::vector<edge2> &_es,bool sorted = false){
    std::vector<edge2> es = _es;
    if(!sorted)std::sort(es.begin(),es.end(),[](edge2 a,edge2 b){return a.cost < b.cost;});
    int n = es.size();
    std::pair<e_t,std::vector<edge2>> res;
    UnionFind UF(n);
    for(edge2& e : es){
        if(!UF.same(e.from,e.to)){
            res.first += e.cost;
            res.second.push_back(e);
        }
    }
    return res;
}

#endif /*SORAIE_MST*/