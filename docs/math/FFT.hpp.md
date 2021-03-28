---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - {icon: ':warning:', path: test/FFT.cpp, title: test/FFT.cpp}
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/FFT.hpp\"\n\n\n\n#include <vector>\n#include <complex>\n\
    \nstruct FFT{\n    using C = std::complex<long double>;\n    void dft(std::vector<C>&\
    \ vec,int t){\n        int sz = vec.size();\n        if(sz == 1)return;\n    \
    \    std::vector<C> veca,vecb;\n        for(int i = 0;i < sz / 2;i++){\n     \
    \       veca.push_back(vec[i * 2]);\n            vecb.push_back(vec[i * 2 + 1]);\n\
    \        }\n        dft(veca,t);dft(vecb,t);\n        C now = 1.0,z = std::polar(1.0,2.0\
    \ * std::acos(-1) * t / sz);\n        for(int i = 0;i < sz;i++){\n           \
    \ vec[i] = veca[i % (sz / 2)] + now * vecb[i % (sz / 2)];\n            now *=\
    \ z;\n        }\n    }\n    template<class T>\n    std::vector<T> convolution(const\
    \ std::vector<T>& A,const std::vector<T>& B){\n        int sz = 1;\n        while(sz\
    \ < A.size() + B.size())sz <<= 1;\n        std::vector<C> f(sz),g(sz);\n     \
    \   for(int i = 0;i < A.size();i++){\n            f[i] = A[i];\n            g[i]\
    \ = B[i];\n        }\n        dft(f,1);dft(g,1);\n        for(int i = 0;i < sz;i++)f[i]\
    \ *= g[i];\n        dft(f,-1);\n        std::vector<T> res(sz);\n        for(int\
    \ i = 0;i < sz;i++)res[i] = T(f[i].real() / sz + 0.1);\n        return res;\n\
    \    }\n};\n\n\n"
  code: "#ifndef SORAIE_FFT\n#define SORAIE_FFT\n\n#include <vector>\n#include <complex>\n\
    \nstruct FFT{\n    using C = std::complex<long double>;\n    void dft(std::vector<C>&\
    \ vec,int t){\n        int sz = vec.size();\n        if(sz == 1)return;\n    \
    \    std::vector<C> veca,vecb;\n        for(int i = 0;i < sz / 2;i++){\n     \
    \       veca.push_back(vec[i * 2]);\n            vecb.push_back(vec[i * 2 + 1]);\n\
    \        }\n        dft(veca,t);dft(vecb,t);\n        C now = 1.0,z = std::polar(1.0,2.0\
    \ * std::acos(-1) * t / sz);\n        for(int i = 0;i < sz;i++){\n           \
    \ vec[i] = veca[i % (sz / 2)] + now * vecb[i % (sz / 2)];\n            now *=\
    \ z;\n        }\n    }\n    template<class T>\n    std::vector<T> convolution(const\
    \ std::vector<T>& A,const std::vector<T>& B){\n        int sz = 1;\n        while(sz\
    \ < A.size() + B.size())sz <<= 1;\n        std::vector<C> f(sz),g(sz);\n     \
    \   for(int i = 0;i < A.size();i++){\n            f[i] = A[i];\n            g[i]\
    \ = B[i];\n        }\n        dft(f,1);dft(g,1);\n        for(int i = 0;i < sz;i++)f[i]\
    \ *= g[i];\n        dft(f,-1);\n        std::vector<T> res(sz);\n        for(int\
    \ i = 0;i < sz;i++)res[i] = T(f[i].real() / sz + 0.1);\n        return res;\n\
    \    }\n};\n\n#endif /*SORAIE_FFT*/"
  dependsOn: []
  isVerificationFile: false
  path: math/FFT.hpp
  requiredBy: [test/FFT.cpp]
  timestamp: '2021-03-21 13:18:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/FFT.hpp
layout: document
redirect_from: [/library/math/FFT.hpp, /library/math/FFT.hpp.html]
title: math/FFT.hpp
---
