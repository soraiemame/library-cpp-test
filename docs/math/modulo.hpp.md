---
data:
  _extendedDependsOn:
  - {icon: ':heavy_check_mark:', path: math/modint.hpp, title: math/modint.hpp}
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/modulo.hpp\"\n\n\n\n#include <vector>\n#line 1 \"math/modint.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <iostream>\n\ntemplate<long long MOD =\
    \ 1000000007>\nstruct modint {\n    using mint = modint<MOD>;\n    long long x;\n\
    \    modint(long long a = 0):x((a % MOD + MOD) % MOD){}\n    inline constexpr\
    \ modint operator-()const noexcept{return modint(-x);}\n    inline constexpr modint\
    \ &operator+=(const modint &a)noexcept{\n        if ((x += a.x) >= MOD) x -= MOD;\n\
    \        return *this;\n    }\n    inline constexpr modint &operator-=(const modint\
    \ &a)noexcept{\n        if ((x -= a.x) < 0) x += MOD;\n        return *this;\n\
    \    }\n    inline constexpr modint &operator*=(const modint &a)noexcept{\n  \
    \      (x *= a.x) %= MOD;\n        return *this;\n    }\n    inline constexpr\
    \ modint &operator++()noexcept{\n        x++;\n        if(x == MOD)x = 0;\n  \
    \      return *this;\n    }\n    inline constexpr modint operator++(int)noexcept{\n\
    \        modint res(*this);\n        operator++();\n        return res;\n    }\n\
    \    inline constexpr modint &operator--()noexcept{\n        x--;\n        if(x\
    \ == -1)x = MOD - 1;\n        return *this;\n    }\n    inline constexpr modint\
    \ operator--(int)noexcept{\n        modint res(*this);\n        operator--();\n\
    \        return res;\n    }\n    inline constexpr modint operator+(const modint\
    \ &a)const noexcept{\n        modint res(*this);\n        return res += a;\n \
    \   }\n    inline constexpr modint operator-(const modint &a)const noexcept{\n\
    \        modint res(*this);\n        return res -= a;\n    }\n    inline constexpr\
    \ modint operator*(const modint &a)const noexcept{\n        modint res(*this);\n\
    \        return res *= a;\n    }\n    inline constexpr modint inv()const{\n  \
    \      long long a = x,b = MOD,u = 1,v = 0;\n        while(b){\n            long\
    \ long t = a / b;\n            a -= t * b;std::swap(a,b);\n            u -= t\
    \ * v;std::swap(u,v);\n        }\n        return u;\n    }\n    inline constexpr\
    \ modint &operator/=(const modint &a)noexcept{return (*this) *= a.inv();}\n  \
    \  inline constexpr modint operator/(const modint &a)const noexcept{\n       \
    \ modint res(*this);\n        return res /= a;\n    }\n    inline constexpr bool\
    \ operator==(const modint &a)const noexcept{return x == a.x;}\n    friend std::istream\
    \ &operator>>(std::istream &is,modint &a) {\n        is >> a.x;\n        a.x =\
    \ (a.x % MOD + MOD) % MOD;\n        return is;\n    }\n    friend std::ostream\
    \ &operator<<(std::ostream &os,const modint &a){\n        os << a.x;\n       \
    \ return os;\n    }\n    long long getmod(){return MOD;}\n    friend mint modpow(mint\
    \ a,long long b)noexcept{\n        mint res(1);\n        while(b){\n         \
    \   if(b & 1)res *= a;\n            a *= a;\n            b >>= 1;\n        }\n\
    \        return res;\n    }\n};\n//using mint = modint<1'000'000'007>::mint;\n\
    \n\n\n#line 6 \"math/modulo.hpp\"\n\na\n\n\n\n"
  code: '#ifndef SORAIE_MODULO

    #define SORAIE_MODULO


    #include <vector>

    #include "modint.hpp"


    a



    #endif /*SORAIE_MODULO*/'
  dependsOn: [math/modint.hpp]
  isVerificationFile: false
  path: math/modulo.hpp
  requiredBy: []
  timestamp: '2021-03-21 13:18:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/modulo.hpp
layout: document
redirect_from: [/library/math/modulo.hpp, /library/math/modulo.hpp.html]
title: math/modulo.hpp
---
