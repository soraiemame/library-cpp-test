#line 1 "sparse_table.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <iostream>
#include <algorithm>
#include <vector>

#line 1 "/mnt/c/Users/funas/OneDrive/\u30c7\u30b9\u30af\u30c8\u30c3\u30d7/cpp/library-cpp/data-structure/sparse_table.hpp"



#line 6 "/mnt/c/Users/funas/OneDrive/\u30c7\u30b9\u30af\u30c8\u30c3\u30d7/cpp/library-cpp/data-structure/sparse_table.hpp"
#include <assert.h>

template<class T>
struct SparseTable{
    int n;
    std::vector<std::vector<T>> table;
    SparseTable(const std::vector<T>& table_){
        n = table_.size();
        int log = 1;
        while(1 << log < n)log++;
        table = std::vector<std::vector<T>>(log,std::vector<T>(n));
        for(int i = 0;i < n;i++)table[0][i] = table_[i];
        for(int i = 1;i < log;i++){
            for(int j = 0;j + (1 << i - 1) < n;j++){
                table[i][j] = std::min(table[i - 1][j],table[i - 1][j + (1 << i - 1)]);
            }
        }
    }
    T query(int l,int r){
        assert(l < r);
        int log = 0;
        while(1 << (log + 1) < r - l)log++;
        return std::min(table[log][l],table[log][r - (1 << log)]);
    }
};


#line 8 "sparse_table.test.cpp"

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
