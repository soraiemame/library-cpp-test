#line 1 "RUQ_1.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D"

#include <iostream>

#line 1 "/mnt/c/Users/funas/OneDrive/\u30c7\u30b9\u30af\u30c8\u30c3\u30d7/cpp/library-cpp/data-structure/lazysegtree.hpp"



#include <vector>
#include <algorithm>
#include <assert.h>

template<class T>
struct SegTree{//RAQ,RUQ,RSQ,RMinQ,RmaxQ
    typedef std::pair<bool,T> T_pair;
    int n;T e;
    std::vector<T> min_dat,max_dat,sum_dat;
    std::vector<T_pair> lazy;
    SegTree(int n_,T e_ = 2147483647):e(e_){
        int x = 1;
        while(x < n_)x <<= 1;
        n = x;
        min_dat = std::vector<T>(n * 2 - 1);
        max_dat = std::vector<T>(n * 2 - 1);
        sum_dat = std::vector<T>(n * 2 - 1);
        lazy = std::vector<T_pair>(n * 2 - 1,std::make_pair(0,0));//0:add 1:update
        range_update(0,n,e);
    }
    void set(int a,T x){
        min_dat[a] = x;max_dat[a] = x;sum_dat[a] = x;
    }
    void build(){
        for(int i = n - 2;i >= 0;i--){
            min_dat[i] = std::min(min_dat[i * 2 + 1],min_dat[i * 2 + 2]);
            max_dat[i] = std::max(max_dat[i * 2 + 1],max_dat[i * 2 + 2]);
            sum_dat[i] = sum_dat[i * 2 + 1] + sum_dat[i * 2 + 2];
        }
    }
    void eval(int k,int l,int r){
        if(k < n - 1){
            if(lazy[k].first == 0){
                lazy[k * 2 + 1].second += lazy[k].second;
                lazy[k * 2 + 2].second += lazy[k].second;
            }
            else{
                lazy[k * 2 + 1] = lazy[k];
                lazy[k * 2 + 2] = lazy[k];
            }
        }
        if(lazy[k].first == 0){
            min_dat[k] += lazy[k].second;
            max_dat[k] += lazy[k].second;
            sum_dat[k] += lazy[k].second * (r - l);
        }
        else{
            min_dat[k] = lazy[k].second;
            max_dat[k] = lazy[k].second;
            sum_dat[k] = lazy[k].second * (r - l);
        }
        lazy[k] = std::make_pair(0,0);
    }
    void range_add(int a,int b,T x,int k,int l,int r){
        eval(k,l,r);
        if(a >= r || b <= l)return;
        else if(a <= l && r <= b){
            lazy[k] = std::make_pair(0,x);
            eval(k,l,r);
        }
        else{
            int m = (l + r) / 2;
            range_add(a,b,x,k * 2 + 1,l,m);
            range_add(a,b,x,k * 2 + 2,m,r);
            min_dat[k] = std::min(min_dat[k * 2 + 1],min_dat[k * 2 + 2]);
            max_dat[k] = std::max(max_dat[k * 2 + 1],max_dat[k * 2 + 2]);
            sum_dat[k] = sum_dat[k * 2 + 1] + sum_dat[k * 2 + 2];
        }
    }
    void range_add(int a,int b,T x){range_add(a,b,x,0,0,n);}
    void range_update(int a,int b,T x,int k,int l,int r){
        eval(k,l,r);
        if(a >= r || b <= l)return;
        else if(a <= l && r <= b){
            lazy[k] = std::make_pair(1,x);
            eval(k,l,r);
        }
        else{
            int m = (l + r) / 2;
            range_update(a,b,x,k * 2 + 1,l,m);
            range_update(a,b,x,k * 2 + 2,m,r);
            min_dat[k] = std::min(min_dat[k * 2 + 1],min_dat[k * 2 + 2]);
            max_dat[k] = std::max(max_dat[k * 2 + 1],max_dat[k * 2 + 2]);
            sum_dat[k] = sum_dat[k * 2 + 1] + sum_dat[k * 2 + 2];
        }
    }
    void range_update(int a,int b,T x){range_update(a,b,x,0,0,n);}
    T range_min(int a,int b,int k,int l,int r){
        eval(k,l,r);
        if(a >= r || b <= l)return e;
        else if(a <= l && r <= b)return min_dat[k];
        else{
            int m = (l + r) / 2;
            return std::min(range_min(a,b,k * 2 + 1,l,m),range_min(a,b,k * 2 + 2,m,r));
        }
    }
    T range_min(int a,int b){return range_min(a,b,0,0,n);}
    T range_max(int a,int b,int k,int l,int r){
        eval(k,l,r);
        if(a >= r || b <= l)return -e;
        else if(a <= l && r <= b)return max_dat[k];
        else{
            int m = (l + r) / 2;
            return std::max(range_max(a,b,k * 2 + 1,l,m),range_max(a,b,k * 2 + 2,m,r));
        }
    }
    T range_max(int a,int b){return range_max(a,b,0,0,n);}
    T range_sum(int a,int b,int k,int l,int r){
        eval(k,l,r);
        if(a >= r || b <= l)return 0;
        else if(a <= l && r <= b)return sum_dat[k];
        else{
            int m = (l + r) / 2;
            return range_sum(a,b,k * 2 + 1,l,m) + range_sum(a,b,k * 2 + 2,m,r);
        }
    }
    T range_sum(int a,int b){return range_sum(a,b,0,0,n);}
    T get(int a){return range_min(a,a + 1);}
};


#line 6 "RUQ_1.test.cpp"

int main(){
    int N,Q;
    std::cin >> N >> Q;
    SegTree<int> S(N,2147483647);
    for(int i = 0;i < Q;i++){
        int t;
        std::cin >> t;
        if(t == 0){
            int s,t,x;
            std::cin >> s >> t >> x;
            S.range_update(s,t + 1,x);
        }
        if(t == 1){
            int a;
            std::cin >> a;
            std::cout << S.get(a) << "\n";
        }
    }
}
