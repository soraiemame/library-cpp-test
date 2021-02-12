#ifndef SORAIE_BELLMAN_FORD
#define SORAIE_BELLMAN_FORD

#include "../utils/graph_alias.hpp"

std::vector<e_t> bellman_ford(const std::vector<edge2> &G,int n,const std::vector<int>& st,e_t LM = std::numeric_limits<e_t>::max()){
    std::vector<e_t> res(n,LM);
    for(const int& a : st)res[a] = 0;
    for(int i = 0;i <= n;i++){
        bool updated = false;
        for(const auto &e : G){
            if(res[e.from] == LM)continue;
            if(res[e.to] > res[e.from] + e.cost){
                res[e.to] = res[e.from] + e.cost;
                updated = true;
            }
        }
        if(i == n && updated)res = std::vector<e_t>(n,LM);
    }
    return res;
}

#endif /*SORAIE_BELLMAN_FORD*/