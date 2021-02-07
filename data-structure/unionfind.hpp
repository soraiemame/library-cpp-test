#ifndef SORAIE_UNIONFIND
#define SORAIE_UNIONFIND

#include <vector>
#include <algorithm>
#include <assert.h>

struct UnionFind{
    int n;
    std::vector<int> dat;
    UnionFind(int n_):n(n_),dat(n_,-1){}
    int find(int v){
        assert(0 <= v && v < n);
        if(dat[v] < 0)return v;
        else return dat[v] = find(dat[v]);
    }
    void unite(int a,int b){
        assert(0 <= a && a < n && 0 <= b && b < n);
        a = find(a);
        b = find(b);
        if(a == b)return;
        if(dat[a] > dat[b])std::swap(a,b);
        dat[a] += dat[b];
        dat[b] = a;
    }
    bool same(int a,int b){
        assert(0 <= a && a < n && 0 <= b && b < n);
        return find(a) == find(b);
    }
    int size(int v){
        assert(0 <= v && v < n);
        return -dat[v];
    }
};

#endif /*SORAIE_UNIONFIND*/