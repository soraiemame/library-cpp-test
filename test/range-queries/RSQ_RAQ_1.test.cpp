#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G"

#include <iostream>

#include "../../data-structure/lazysegtree.hpp"

int main(){
    int N,Q;
    std::cin >> N >> Q;
    SegTree<long long> S(N,1LL << 60);
    S.range_update(0,N,0);
    for(int i = 0;i < Q;i++){
        int t;
        std::cin >> t;
        if(t == 0){
            int s,t;long long x;
            std::cin >> s >> t >> x;
            S.range_add(s - 1,t,x);
        }
        if(t == 1){
            int s,t;
            std::cin >> s >> t;
            std::cout << S.range_sum(s - 1,t) << "\n";
        }
    }
}