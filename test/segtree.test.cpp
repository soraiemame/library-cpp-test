#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A"

#include <iostream>
#include <algorithm>

#include "../data-structure/segtree.hpp"

int fx(int a,int b){
    return std::min(a,b);
}

int main(){
    int N,Q;
    std::cin >> N >> Q;
    SegTree<int> S(N,2147483647,fx);
    for(int i = 0;i < Q;i++){
        int t,a,b;
        std::cin >> t >> a >> b;
        if(t == 0)S.update(a,b);
        if(t == 1)std::cout << S.query(a,b + 1) << "\n";
    }
}