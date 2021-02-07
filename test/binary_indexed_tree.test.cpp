#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"

#include <iostream>

#include "../data-structure/binary_indexed_tree.hpp"

int main(){
    int N,Q;
    std::cin >> N >> Q;
    BinaryIndexedTree<int> BIT(N);
    for(int i = 0;i < Q;i++){
        int t,a,b;
        std::cin >> t >> a >> b;
        if(t == 0)BIT.add(a - 1,b);
        if(t == 1)std::cout << BIT.sum(a - 1,b) << "\n";
    }
}