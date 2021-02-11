#ifndef SORAIE_DIJKSTRA
#define SORAIE_DIJKSTRA

#include "../utils/graph_alias.hpp"
#include <algorithm>
#include <queue>

std::vector<e_t> dijkstra(const Graph<edge>& G,const std::vector<int>& st,e_t LM = std::numeric_limits<e_t>::max()){
    std::vector<e_t> res(G.size(),LM);
    std::priority_queue<std::pair<e_t,int>,std::vector<std::pair<e_t,int>>,std::greater<std::pair<e_t,int>>> que;
    for(const int &a : st){
        que.push(std::make_pair(0,a));
        res[a] = 0;
    }
    while(!que.empty()){
        auto p = que.top();
        que.pop();
        if(res[p.second] < p.first)continue;
        for(const edge &e : G[p.second]){
            if(res[e.to] > res[p.second] + e.cost){
                res[e.to] = res[p.second] + e.cost;
                que.push(std::make_pair(res[e.to],e.to));
            }
        }
    }
    return res;
}

#endif /*SORAIE_DIJKSTRA*/