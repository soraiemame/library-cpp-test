#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include <iostream>

#include "../graph/SCC.hpp"

int main(){
    int N,M;
    std::cin >> N >> M;
    SCC scc(N);
    for(int i = 0;i < M;i++){
        int a,b;
        std::cin >> a >> b;
        scc.add_edge(a,b);
    }
    scc.build();
    auto ans = scc.components();
    std::cout << ans.size() << "\n";
    for(auto x : ans){
        std::cout << x.size();
        for(int i = 0;i < int(x.size());i++)std::cout << " " << x[i];
        std::cout << "\n";
    }
}