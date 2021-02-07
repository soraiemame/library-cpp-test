#define PROBLEM "https://atcoder.jp/contests/abc189/tasks/abc189_c"

#include <iostream>
#include <algorithm>
#include <vector>

#include "../data-structure/sparse_table.hpp"

int main(){
    int N;
    std::cin >> N;
    std::vector<int> vec(N);
    for(int i = 0;i < N;i++)std::cin >> vec[i];
    SparseTable<int> S(vec);
    int ans = 0;
    for(int i = 0;i < N;i++){
        for(int j = i + 1;j <= N;j++){
            ans = std::max(ans,(j - i) * S.query(i,j));
        }
    }
    std::cout << ans << "\n";
}