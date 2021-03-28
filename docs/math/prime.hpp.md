---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - {icon: ':heavy_check_mark:', path: test/prime.test.cpp, title: test/prime.test.cpp}
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/prime.hpp\"\n\n\n\n#include <vector>\n#include <algorithm>\n\
    \nnamespace prime{\n    long long inner_modmul(long long x,long long y,long long\
    \ p){\n        #ifdef __SIZEOF_INT128__\n        return __int128_t(x) * y % p;\n\
    \        #else\n        unsigned long long q = long double(x) * y / p;\n     \
    \   long long res = long long(x * y - p * q) % p;\n        return res < 0 ? res\
    \ + p : res;\n        #endif\n    }\n\n    long long inner_modpow(long long n,long\
    \ long m,long long p){\n        long long res = 1;\n        while(m){\n      \
    \      if(m & 1)res = inner_modmul(res,n,p);\n            m >>= 1;\n         \
    \   n = inner_modmul(n,n,p);\n        }\n        return res;\n    }\n\n    bool\
    \ miller_rabin(long long n,const std::vector<long long> as){\n        long long\
    \ s = __builtin_ctzll(n - 1),d = n >> s;\n        for(long long a : as){\n   \
    \         if(n <= a)break;\n            long long t = d,y = inner_modpow(a,t,n);\n\
    \            while(t != n - 1 && y != 1 && y != (n - 1)){\n                y =\
    \ inner_modmul(y,y,n);\n                t = inner_modmul(t,2,n);\n           \
    \ }\n            if(y != n - 1 && ~t & 1)return false;\n        }\n        return\
    \ true;\n    }\n\n    bool is_prime(long long n){\n        if(n <= 2)return n\
    \ == 2;\n        else if(~n & 1)return false;\n        else if(n < 4'759'123'141)return\
    \ miller_rabin(n,{2,7,61});\n        else return miller_rabin(n,{2,325,9375,28178,450775,9780504,1795265022});\n\
    \    }\n\n    long long factor(long long n){\n        if(~n & 1)return 2;\n  \
    \      else if(is_prime(n))return n;\n        int c = 2;\n        while(true){\n\
    \            auto f = [&](long long x){\n                long long r = inner_modmul(x,x,n)\
    \ + c;\n                if(r >= n)r -= n;\n                return r;\n       \
    \     };\n            long long x = c,g = 1,q = 1,xs,y;\n            constexpr\
    \ int m = 128;\n            int l = 1;\n            while(g == 1){\n         \
    \       y = x;\n                for(int i = 1;i < l;i++){\n                  \
    \  x = f(x);\n                }\n                int k = 0;\n                while(k\
    \ < l && g == 1){\n                    xs = x;\n                    for(int i\
    \ = 0;i < m && i < l - k;i++){\n                        x = f(x);\n          \
    \              q = inner_modmul(q,std::llabs(y - x),n);\n                    }\n\
    \                    g = std::__gcd(q,n);\n                    k += m;\n     \
    \           }\n                l *= 2;\n            }\n            if(g == n){\n\
    \                do{\n                    xs = f(xs);\n                    g =\
    \ std::__gcd(std::llabs(xs - y),n);\n                }while(g == 1);\n       \
    \     }\n            if(g != n)return g;\n            c++;\n        }\n    }\n\
    \n    std::vector<long long> factorize_sub(long long n){\n        if(n <= 1)return\
    \ {};\n        long long p = factor(n);\n        if(p == n)return {p};\n     \
    \   auto l = factorize_sub(n / p);\n        auto r = factorize_sub(p);\n     \
    \   copy(begin(r),end(r),back_inserter(l));\n        return l;\n    }\n\n    std::vector<long\
    \ long> factorize(long long n,bool sorted = true){\n        auto res = factorize_sub(n);\n\
    \        if(sorted)std::sort(res.begin(),res.end());\n        return res;\n  \
    \  }\n};\nusing prime::factorize;\nusing prime::is_prime;\n\n\n\n"
  code: "#ifndef SORAIE_PRIME\n#define SORAIE_PRIME\n\n#include <vector>\n#include\
    \ <algorithm>\n\nnamespace prime{\n    long long inner_modmul(long long x,long\
    \ long y,long long p){\n        #ifdef __SIZEOF_INT128__\n        return __int128_t(x)\
    \ * y % p;\n        #else\n        unsigned long long q = long double(x) * y /\
    \ p;\n        long long res = long long(x * y - p * q) % p;\n        return res\
    \ < 0 ? res + p : res;\n        #endif\n    }\n\n    long long inner_modpow(long\
    \ long n,long long m,long long p){\n        long long res = 1;\n        while(m){\n\
    \            if(m & 1)res = inner_modmul(res,n,p);\n            m >>= 1;\n   \
    \         n = inner_modmul(n,n,p);\n        }\n        return res;\n    }\n\n\
    \    bool miller_rabin(long long n,const std::vector<long long> as){\n       \
    \ long long s = __builtin_ctzll(n - 1),d = n >> s;\n        for(long long a :\
    \ as){\n            if(n <= a)break;\n            long long t = d,y = inner_modpow(a,t,n);\n\
    \            while(t != n - 1 && y != 1 && y != (n - 1)){\n                y =\
    \ inner_modmul(y,y,n);\n                t = inner_modmul(t,2,n);\n           \
    \ }\n            if(y != n - 1 && ~t & 1)return false;\n        }\n        return\
    \ true;\n    }\n\n    bool is_prime(long long n){\n        if(n <= 2)return n\
    \ == 2;\n        else if(~n & 1)return false;\n        else if(n < 4'759'123'141)return\
    \ miller_rabin(n,{2,7,61});\n        else return miller_rabin(n,{2,325,9375,28178,450775,9780504,1795265022});\n\
    \    }\n\n    long long factor(long long n){\n        if(~n & 1)return 2;\n  \
    \      else if(is_prime(n))return n;\n        int c = 2;\n        while(true){\n\
    \            auto f = [&](long long x){\n                long long r = inner_modmul(x,x,n)\
    \ + c;\n                if(r >= n)r -= n;\n                return r;\n       \
    \     };\n            long long x = c,g = 1,q = 1,xs,y;\n            constexpr\
    \ int m = 128;\n            int l = 1;\n            while(g == 1){\n         \
    \       y = x;\n                for(int i = 1;i < l;i++){\n                  \
    \  x = f(x);\n                }\n                int k = 0;\n                while(k\
    \ < l && g == 1){\n                    xs = x;\n                    for(int i\
    \ = 0;i < m && i < l - k;i++){\n                        x = f(x);\n          \
    \              q = inner_modmul(q,std::llabs(y - x),n);\n                    }\n\
    \                    g = std::__gcd(q,n);\n                    k += m;\n     \
    \           }\n                l *= 2;\n            }\n            if(g == n){\n\
    \                do{\n                    xs = f(xs);\n                    g =\
    \ std::__gcd(std::llabs(xs - y),n);\n                }while(g == 1);\n       \
    \     }\n            if(g != n)return g;\n            c++;\n        }\n    }\n\
    \n    std::vector<long long> factorize_sub(long long n){\n        if(n <= 1)return\
    \ {};\n        long long p = factor(n);\n        if(p == n)return {p};\n     \
    \   auto l = factorize_sub(n / p);\n        auto r = factorize_sub(p);\n     \
    \   copy(begin(r),end(r),back_inserter(l));\n        return l;\n    }\n\n    std::vector<long\
    \ long> factorize(long long n,bool sorted = true){\n        auto res = factorize_sub(n);\n\
    \        if(sorted)std::sort(res.begin(),res.end());\n        return res;\n  \
    \  }\n};\nusing prime::factorize;\nusing prime::is_prime;\n\n\n#endif /*SORAIE_PRIME*/"
  dependsOn: []
  isVerificationFile: false
  path: math/prime.hpp
  requiredBy: []
  timestamp: '2021-03-24 15:11:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith: [test/prime.test.cpp]
documentation_of: math/prime.hpp
layout: document
redirect_from: [/library/math/prime.hpp, /library/math/prime.hpp.html]
title: math/prime.hpp
---
