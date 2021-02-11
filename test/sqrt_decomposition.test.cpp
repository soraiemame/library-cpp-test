#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <assert.h>

#include "../data-structure/sqrt_decomposition.hpp"

void verify(int n,int coeff = 100){
    const long long INF = 10'000'000'000,e = 1LL << 60;
    std::random_device rnd;
    std::mt19937_64 mt(rnd());
    std::uniform_int_distribution<long long> uni(-INF,INF);
    std::uniform_int_distribution<int> cmd(0,6),index(0,n - 1);
    std::vector<long long> naive(n);
    int q = n * n * coeff;
    for(int i = 0;i < n;i++)naive[i] = uni(mt);
    sqrt_dec<long long> S(naive,5,e);
    while(q--){
        int c = cmd(mt),l = index(mt),r = index(mt);
        if(l > r)std::swap(l,r);
        r++;
        long long x = uni(mt);
        if(c == 0){
            //range chmin
            S.range_chmin(l,r,x);
            
            for(int i = l;i < r;i++)naive[i] = std::min(naive[i],x);
        }
        else if(c == 1){
            //range chmax
            S.range_chmax(l,r,x);
            
            for(int i = l;i < r;i++)naive[i] = std::max(naive[i],x);
        }
        else if(c == 2){
            //range add
            S.range_add(l,r,x);
            
            for(int i = l;i < r;i++)naive[i] += x;
        }
        else if(c == 3){
            //range update
            S.range_update(l,r,x);

            for(int i = l;i < r;i++)naive[i] = x;
        }
        else if(c == 4){
            //range min
            long long ans = S.range_min(l,r);

            long long expected = e;
            for(int i = l;i < r;i++)expected = std::min(expected,naive[i]);
            
            if(ans != expected){
                std::cerr << n << "\n";
                for(int i = 0;i < n;i++)std::cerr << naive[i] << " ";
                std::cerr << "\n";
                S.deb();
                std::cerr << ans << "," << expected << "\n";
            }
            assert(ans == expected && "range min");
        }
        else if(c == 5){
            //range max
            long long ans = S.range_max(l,r);

            long long expected = -e;
            for(int i = l;i < r;i++)expected = std::max(expected,naive[i]);
            
            if(ans != expected){
                std::cerr << n << "\n";
                for(int i = 0;i < n;i++)std::cerr << naive[i] << " ";
                std::cerr << "\n";
                S.deb();
                std::cerr << ans << "," << expected << "\n";
            }
            assert(ans == expected && "range max");
        }
        else if(c == 6){
            //range sum
            long long ans = S.range_sum(l,r);

            long long expected = 0;
            for(int i = l;i < r;i++)expected += naive[i];
            
            if(ans != expected){
                std::cerr << n << "\n";
                for(int i = 0;i < n;i++)std::cerr << naive[i] << " ";
                std::cerr << "\n";
                S.deb();
                std::cerr << ans << "," << expected << "\n";
            }
            assert(ans == expected && "range sum");
        }
        else assert(false);
    }
}

int main(){
    long long A,B;
    std::cin >> A >> B;
    std::cout << A + B << "\n";

    for(int i = 0;i < 5;i++){
        verify(1);
        verify(2);
        verify(63);
        verify(64);
        verify(65);
    }
}