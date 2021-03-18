#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include "../math/prime.hpp"

#include <iostream>

int main(){
    int Q;
    std::cin >> Q;
    while(Q--){
        long long N;
        std::cin >> N;
        auto ans = factorize(N);
        std::cout << ans.size();
        for(auto&& x : ans)std::cout << " " << x;
        std::cout << "\n";
    }
}