#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A"

#include <iostream>
#include <vector>

#include "../graph/dijkstra.hpp"

int main(){
    int N,M,S;
    std::cin >> N >> M >> S;
    std::vector<std::vector<edge>> G(N);
    for(int i = 0;i < M;i++){
        int a,b;e_t c;
        std::cin >> a >> b >> c;
        G[a].push_back({b,c});
    }
    const e_t INF = 1LL << 60;
    auto ans = dijkstra(G,{S},INF);
    for(int i = 0;i < N;i++){
        if(ans[i] == INF)std::cout << "INF\n";
        else std::cout << ans[i] << "\n";
    }
}