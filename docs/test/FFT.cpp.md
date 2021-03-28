---
data:
  _extendedDependsOn:
  - {icon: ':warning:', path: math/FFT.hpp, title: math/FFT.hpp}
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: ['https://atcoder.jp/contests/atc001/tasks/fft_c']
  bundledCode: "#line 1 \"test/FFT.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/atc001/tasks/fft_c\"\
    \n\n#include <iostream>\n#include <vector>\n\n#line 1 \"math/FFT.hpp\"\n\n\n\n\
    #line 5 \"math/FFT.hpp\"\n#include <complex>\n\nstruct FFT{\n    using C = std::complex<long\
    \ double>;\n    void dft(std::vector<C>& vec,int t){\n        int sz = vec.size();\n\
    \        if(sz == 1)return;\n        std::vector<C> veca,vecb;\n        for(int\
    \ i = 0;i < sz / 2;i++){\n            veca.push_back(vec[i * 2]);\n          \
    \  vecb.push_back(vec[i * 2 + 1]);\n        }\n        dft(veca,t);dft(vecb,t);\n\
    \        C now = 1.0,z = std::polar(1.0,2.0 * std::acos(-1) * t / sz);\n     \
    \   for(int i = 0;i < sz;i++){\n            vec[i] = veca[i % (sz / 2)] + now\
    \ * vecb[i % (sz / 2)];\n            now *= z;\n        }\n    }\n    template<class\
    \ T>\n    std::vector<T> convolution(const std::vector<T>& A,const std::vector<T>&\
    \ B){\n        int sz = 1;\n        while(sz < A.size() + B.size())sz <<= 1;\n\
    \        std::vector<C> f(sz),g(sz);\n        for(int i = 0;i < A.size();i++){\n\
    \            f[i] = A[i];\n            g[i] = B[i];\n        }\n        dft(f,1);dft(g,1);\n\
    \        for(int i = 0;i < sz;i++)f[i] *= g[i];\n        dft(f,-1);\n        std::vector<T>\
    \ res(sz);\n        for(int i = 0;i < sz;i++)res[i] = T(f[i].real() / sz + 0.1);\n\
    \        return res;\n    }\n};\n\n\n#line 7 \"test/FFT.cpp\"\n\nint main(){\n\
    \    int N;\n    std::cin >> N;\n    std::vector<int> A(N),B(N);\n    for(int\
    \ i = 0;i < N;i++)std::cin >> A[i] >> B[i];\n    FFT f;\n    auto ans = f.convolution(A,B);\n\
    \    std::cout << \"0\\n\";\n    for(int i = 0;i < 2 * N - 1;i++)std::cout <<\
    \ ans[i] << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/atc001/tasks/fft_c\"\n\n#include\
    \ <iostream>\n#include <vector>\n\n#include \"../library-cpp/math/FFT.hpp\"\n\n\
    int main(){\n    int N;\n    std::cin >> N;\n    std::vector<int> A(N),B(N);\n\
    \    for(int i = 0;i < N;i++)std::cin >> A[i] >> B[i];\n    FFT f;\n    auto ans\
    \ = f.convolution(A,B);\n    std::cout << \"0\\n\";\n    for(int i = 0;i < 2 *\
    \ N - 1;i++)std::cout << ans[i] << \"\\n\";\n}"
  dependsOn: [math/FFT.hpp]
  isVerificationFile: false
  path: test/FFT.cpp
  requiredBy: []
  timestamp: '2021-03-21 13:18:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/FFT.cpp
layout: document
redirect_from: [/library/test/FFT.cpp, /library/test/FFT.cpp.html]
title: test/FFT.cpp
---
