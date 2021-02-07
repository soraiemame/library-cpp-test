#ifndef SORAIE_SEGTREE
#define SORAIE_SEGTREE

#include<vector>
#include<functional>
#include<assert.h>
template<class T>
struct SegTree{
    using fx = std::function<T(T,T)>;
    int n;
    std::vector<T> dat;
    T e;
    fx f;
    SegTree(int n_,T e_,fx f_):e(e_),f(f_){
        int x = 1;
        while(x < n_)x <<= 1;
        n = x;
        dat = std::vector<T>(x * 2 - 1,e);
    }
    void set(int m,T a){
        assert(0 <= m && m < n);
        dat[m + n - 1] = a;
    }
    void build(){
        for(int i = n - 2;i >= 0;i--){
            dat[i] = f(dat[i * 2 + 1],dat[i * 2 + 2]);
        }
    }
    void update(int m,T a){
        assert(0 <= m && m < n);
        m += n - 1;
        dat[m] = a;
        while(m > 0){
            m = (m - 1) / 2;
            dat[m] = f(dat[m * 2 + 1],dat[m * 2 + 2]);
        }
    }
    void add(int m,T a){
        assert(0 <= m && m < n);
        m += n - 1;
        dat[m] = a;
        while(m > 0){
            m = (m - 1) / 2;
            dat[m] = f(dat[m * 2 + 1],dat[m * 2 + 2]);
        }
    }
    T query(int a,int b,int k,int l,int r){
        if(a >= r || b <= l){
            return e;
        }
        else if(a <= l && r <= b){
            return dat[k];
        }
        else{
            T L = query(a,b,k * 2 + 1,l,(l + r) / 2);
            T R = query(a,b,k * 2 + 2,(l + r) / 2,r);
            return f(L,R);
        }
    }
    T query(int a,int b){
        assert(0 <= a && a < n && 0 < b && b <= n && a <= b);
        return query(a,b,0,0,n);
    }
    T get(int a){
        assert(0 <= a && a < n);
        return dat[a + n - 1];
    }
};

#endif /*SORAIE_SEGTREE*/