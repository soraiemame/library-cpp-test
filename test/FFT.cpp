#define PROBLEM "https://atcoder.jp/contests/atc001/tasks/fft_c"

#include <iostream>
#include <vector>

#include "../library-cpp/math/FFT.hpp"

int main(){
    int N;
    std::cin >> N;
    std::vector<int> A(N),B(N);
    for(int i = 0;i < N;i++)std::cin >> A[i] >> B[i];
    FFT f;
    auto ans = f.convolution(A,B);
    std::cout << "0\n";
    for(int i = 0;i < 2 * N - 1;i++)std::cout << ans[i] << "\n";
}