#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C"

#include <iostream>
#include <algorithm>
#include <vector>

#include "../graph/warshall_floyd.hpp"


int main(){
    const e_t INF = 1LL << 60;
    int N,M;
    std::cin >> N >> M;
    std::vector<std::vector<e_t>> G(N,std::vector<e_t>(N,INF));
    for(int i = 0;i < M;i++){
        int a,b;e_t c;
        std::cin >> a >> b >> c;
        G[a][b] = std::min(G[a][b],c);
    }
    for(int i = 0;i < N;i++)G[i][i] = 0;
    auto ans = warshall_floyd(G,INF);
    for(int i = 0;i < N;i++)if(ans[i][i] < 0){
        std::cout << "NEGATIVE CYCLE\n";
        return 0;
    }
    
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            if(ans[i][j] == INF)std::cout << "INF";
            else std::cout << ans[i][j];
            std::cout << (j == N - 1 ? "\n":" ");
        }
    }
}