#ifndef SORAIE_BINARY_INDEXED_TREE
#define SORAIE_BINARY_INDEXED_TREE

#include <vector>
#include <iostream>
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
    void deb(){
        std::cerr << "BIT debug: [";
        for(int i = 0;i < n;i++)std::cerr << sum(i,i + 1) << (i == n - 1 ? "]\n":",");
    }
};

#endif /*SORAIE_BINARY_INDEXED_TREE*/