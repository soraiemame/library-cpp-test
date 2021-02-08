#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <iostream>
#include <algorithm>
#include <vector>

#include "../data-structure/sparse_table.hpp"

int main(){
    int N,Q;
    std::cin >> N >> Q;
    std::vector<long long> vec(N);
    for(int i = 0;i < N;i++)std::cin >> vec[i];
    SparseTable<long long> S(vec);
    for(int i = 0;i < Q;i++){
        int l,r;
        std::cin >> l >> r;
        std::cout << S.query(l,r) << "\n";
    }
}