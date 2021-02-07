#line 1 "binary_indexed_tree.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"

#include <iostream>

#line 1 "/mnt/c/Users/funas/OneDrive/\u30c7\u30b9\u30af\u30c8\u30c3\u30d7/cpp/library-cpp/data-structure/binary_indexed_tree.hpp"



#include <vector>
#include <assert.h>
template<class T>
struct BinaryIndexedTree{
    int n;
    std::vector<T> dat;
    BinaryIndexedTree (int n_):n(n_),dat(n_,0){}
    //[m]+=a
    void add(int m,T a){
        assert(0 <= m && m < n);
        m++;
        while(m <= n){
            dat[m - 1] += a;
            m += m & -m;
        }
    }
    //0 ~ m - 1
    T sum(int m){
        assert(0 <= m && m <= n);
        T res = 0;
        while(m > 0){
            res += dat[m - 1];
            m -= m & -m;
        }
        return res;
    }
    //l ~ r - 1
    T sum(int l,int r){
        assert(0 <= l && l <= r && r <= n);
        return sum(r) - sum(l);
    }
};


#line 6 "binary_indexed_tree.test.cpp"

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
