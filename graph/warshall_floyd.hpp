#ifndef SORAIE_WARSHALL_FLOYD
#define SORAIE_WARSHALL_FLOYD

#include "../utils/graph_alias.hpp"

std::vector<std::vector<e_t>> warshall_floyd(const std::vector<std::vector<e_t>> &G,e_t LM = std::numeric_limits<e_t>::max()){
    std::vector<std::vector<e_t>> res = G;
    int n = res.size();
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            for(int k = 0;k < n;k++){
                if(res[j][i] == LM || res[i][k] == LM)continue;
                else if(res[j][k] > res[j][i] + res[i][k])res[j][k] = res[j][i] + res[i][k];
            }
        }
    }
    return res;
}

void append(std::vector<std::vector<e_t>> &G,int from,int to,e_t cost,e_t LM = std::numeric_limits<e_t>::max()){
    if(G[from][to] <= cost)return;
    int n = G.size();
    G[from][to] = cost;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(G[i][from] == LM || G[to][j] == LM)continue;
            else if(G[i][j] > G[i][from] + cost + G[to][j])G[i][j] = G[i][from] + cost + G[to][j];
        }
    }
}

#endif /*SORAIE_WARSHALL_FLOYD*/