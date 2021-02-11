#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B"

#include <iostream>
#include <vector>

#include "../graph/bellman_ford.hpp"

int main(){
    int N,M,S;
    std::cin >> N >> M >> S;
    std::vector<bellman_edge> G(M);
    for(int i = 0;i < M;i++)std::cin >> G[i].from >> G[i].to >> G[i].cost;
    const e_t INF = 1LL << 60;
    auto ans = bellman_ford(G,N,{S},INF);
    if(ans[S] == INF)std::cout << "NEGATIVE CYCLE\n";
    else{
        for(e_t &x : ans){
            if(x == INF)std::cout << "INF\n";
            else std::cout << x << "\n";
        }
    }
}