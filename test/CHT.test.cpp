#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include <iostream>

#include "../data-structure/CHT.hpp"

int main(){
    int N,Q;
    std::cin >> N >> Q;
    ConvexHullTrick CHT;
    for(int i = 0;i < N;i++){
        int a;long long b;
        std::cin >> a >> b;
        CHT.add_line(a,b);
    }
    for(int i = 0;i < Q;i++){
        int t;
        std::cin >> t;
        if(t == 0){
            int a;long long b;
            std::cin >> a >> b;
            CHT.add_line(a,b);
        }
        else{
            long long x;
            std::cin >> x;
            std::cout << CHT.query(x) << "\n";
        }
    }
}