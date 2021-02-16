#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"

#include <iostream>

#include "../math/NTT_all_mod.hpp"

int main(){
    int N,M;
    std::cin >> N >> M;
    std::vector<long long> A(N),B(M);
    for(int i = 0;i < N;i++)std::cin >> A[i];
    for(int i = 0;i < M;i++)std::cin >> B[i];
    if(N > M)B.resize(N);
    if(N < M)A.resize(M);
    NTT_all<1'000'000'007> ntt;
    auto ans = ntt.convolution(A,B);
    for(int i = 0;i < N + M - 1;i++)std::cout << ans[i] << (i == N + M - 2 ? "\n":" ");
}