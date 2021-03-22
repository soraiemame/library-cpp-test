#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"

#include <iostream>
#include <vector>

#include "../data-structure/sqrt_decomposition.hpp"

int main(){
    int N,Q;
    std::cin >> N >> Q;
    std::vector<long long> vec(N);
    for(int i = 0;i < N;i++)std::cin >> vec[i];
    sqrt_dec<long long> ST(vec,450,1LL << 60);
    for(int i = 0;i < Q;i++){
        int t;
        std::cin >> t;
        if(t == 0){
            int l,r;long long v;
            std::cin >> l >> r >> v;
            ST.range_chmin(l,r,v);
        }
        if(t == 1){
            int l,r;long long v;
            std::cin >> l >> r >> v;
            ST.range_chmax(l,r,v);
        }
        if(t == 2){
            int l,r;long long v;
            std::cin >> l >> r >> v;
            ST.range_add(l,r,v);
        }
        if(t == 3){
            int l,r;
            std::cin >> l >> r;
            std::cout << ST.range_sum(l,r) << "\n";
        }
    }
}