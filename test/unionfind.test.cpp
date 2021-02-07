#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <iostream>

#include "../data-structure/unionfind.hpp"

int main(){
    int N,Q;
    std::cin >> N >> Q;
    UnionFind UF(N);
    for(int i = 0;i < Q;i++){
        int t,u,v;
        std::cin >> t >> u >> v;
        if(t == 0)UF.unite(u,v);
        if(t == 1)std::cout << UF.same(u,v) << "\n";
    }
}