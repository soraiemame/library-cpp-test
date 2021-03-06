---
data:
  _extendedDependsOn:
  - {icon: ':heavy_check_mark:', path: math/NTT_primitive_mod.hpp, title: math/NTT_primitive_mod.hpp}
  - {icon: ':heavy_check_mark:', path: math/garner.hpp, title: garner precalc}
  - {icon: ':heavy_check_mark:', path: math/math.hpp, title: math/math.hpp}
  - {icon: ':heavy_check_mark:', path: math/modint.hpp, title: math/modint.hpp}
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - {icon: ':heavy_check_mark:', path: test/NTT_1000000007.test.cpp, title: test/NTT_1000000007.test.cpp}
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/NTT_all_mod.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <assert.h>\n\n#line 1 \"math/garner.hpp\"\n\n\n\n#include <numeric>\n#line 7\
    \ \"math/garner.hpp\"\n\n#line 1 \"math/math.hpp\"\n\n\n\n#include <algorithm>\n\
    \nlong long extgcd(long long a,long long b,long long &x,long long &y){\n    if(b\
    \ == 0){\n        x = 1;\n        y = 0;\n        return a;\n    }\n    long long\
    \ d = extgcd(b,a % b,y,x);\n    y -= a / b * x;\n    return d;\n}\n\nlong long\
    \ modinv(long long a,long long p){\n    long long b = p, u = 1, v = 0;\n    while(b){\n\
    \        long long t = a / b;\n        a -= t * b;std::swap(a, b);\n        u\
    \ -= t * v;std::swap(u, v);\n    }\n    u %= p;\n    if(u < 0)u += p;\n    return\
    \ u;\n}\n\n\n#line 9 \"math/garner.hpp\"\n\n/**\n * @brief garner precalc\n *\
    \ @return long long \n */\nlong long pregarner(std::vector<long long> &rems,std::vector<long\
    \ long> &mods,long long MOD){\n    assert(rems.size() == mods.size());\n    for(int\
    \ i = 0;i < int(rems.size());i++){\n        for(int j = 0;j < i;j++){\n      \
    \      long long g = std::gcd(mods[i],mods[j]);\n            if((rems[i] - rems[j])\
    \ % g != 0)return -1;\n            mods[i] /= g;mods[j] /= g;\n            long\
    \ long gi = std::gcd(g,mods[i]),gj = g / gi;\n            do{\n              \
    \  g = std::gcd(gi,gj);\n                gi *= g;gj /= g;\n            }while(g\
    \ != 1);\n            mods[i] *= gi;mods[j] *= gj;\n            rems[i] %= mods[i];rems[j]\
    \ %= mods[j];\n        }\n    }\n    long long res = 1;\n    for(long long &a\
    \ : mods)res = res * a % MOD;\n    return res;\n}\n\n/**\n * @brief returns a\
    \ integer where rems[i](mod.mods[i]).\n * @return long long \n */\nlong long garner(std::vector<long\
    \ long> rems,std::vector<long long> mods,long long MOD){\n    assert(rems.size()\
    \ == mods.size());\n    mods.push_back(MOD);\n    int sz = mods.size();\n    std::vector<long\
    \ long> cof(sz,1LL),con(sz,0LL);\n    for(int i = 0;i < sz - 1;i++){\n       \
    \ long long cur = (rems[i] - con[i]) * modinv(cof[i],mods[i]) % mods[i];\n   \
    \     if(cur < 0)cur += mods[i];\n        for(int j = i + 1;j < sz;j++){\n   \
    \         con[j] = (con[j] + cur * cof[j]) % mods[j];\n            cof[j] = cof[j]\
    \ * mods[i] % mods[j];\n        }\n    }\n    return con.back();\n}\n\n\n#line\
    \ 1 \"math/NTT_primitive_mod.hpp\"\n\n\n\n#line 6 \"math/NTT_primitive_mod.hpp\"\
    \n\n#line 1 \"math/modint.hpp\"\n\n\n\n#line 5 \"math/modint.hpp\"\n#include <iostream>\n\
    \ntemplate<long long MOD = 1000000007>\nstruct modint {\n    using mint = modint<MOD>;\n\
    \    long long x;\n    modint(long long a = 0):x((a % MOD + MOD) % MOD){}\n  \
    \  inline constexpr modint operator-()const noexcept{return modint(-x);}\n   \
    \ inline constexpr modint &operator+=(const modint &a)noexcept{\n        if ((x\
    \ += a.x) >= MOD) x -= MOD;\n        return *this;\n    }\n    inline constexpr\
    \ modint &operator-=(const modint &a)noexcept{\n        if ((x -= a.x) < 0) x\
    \ += MOD;\n        return *this;\n    }\n    inline constexpr modint &operator*=(const\
    \ modint &a)noexcept{\n        (x *= a.x) %= MOD;\n        return *this;\n   \
    \ }\n    inline constexpr modint &operator++()noexcept{\n        x++;\n      \
    \  if(x == MOD)x = 0;\n        return *this;\n    }\n    inline constexpr modint\
    \ operator++(int)noexcept{\n        modint res(*this);\n        operator++();\n\
    \        return res;\n    }\n    inline constexpr modint &operator--()noexcept{\n\
    \        x--;\n        if(x == -1)x = MOD - 1;\n        return *this;\n    }\n\
    \    inline constexpr modint operator--(int)noexcept{\n        modint res(*this);\n\
    \        operator--();\n        return res;\n    }\n    inline constexpr modint\
    \ operator+(const modint &a)const noexcept{\n        modint res(*this);\n    \
    \    return res += a;\n    }\n    inline constexpr modint operator-(const modint\
    \ &a)const noexcept{\n        modint res(*this);\n        return res -= a;\n \
    \   }\n    inline constexpr modint operator*(const modint &a)const noexcept{\n\
    \        modint res(*this);\n        return res *= a;\n    }\n    inline constexpr\
    \ modint inv()const{\n        long long a = x,b = MOD,u = 1,v = 0;\n        while(b){\n\
    \            long long t = a / b;\n            a -= t * b;std::swap(a,b);\n  \
    \          u -= t * v;std::swap(u,v);\n        }\n        return u;\n    }\n \
    \   inline constexpr modint &operator/=(const modint &a)noexcept{return (*this)\
    \ *= a.inv();}\n    inline constexpr modint operator/(const modint &a)const noexcept{\n\
    \        modint res(*this);\n        return res /= a;\n    }\n    inline constexpr\
    \ bool operator==(const modint &a)const noexcept{return x == a.x;}\n    friend\
    \ std::istream &operator>>(std::istream &is,modint &a) {\n        is >> a.x;\n\
    \        a.x = (a.x % MOD + MOD) % MOD;\n        return is;\n    }\n    friend\
    \ std::ostream &operator<<(std::ostream &os,const modint &a){\n        os << a.x;\n\
    \        return os;\n    }\n    long long getmod(){return MOD;}\n    friend mint\
    \ modpow(mint a,long long b)noexcept{\n        mint res(1);\n        while(b){\n\
    \            if(b & 1)res *= a;\n            a *= a;\n            b >>= 1;\n \
    \       }\n        return res;\n    }\n};\n//using mint = modint<1'000'000'007>::mint;\n\
    \n\n\n#line 9 \"math/NTT_primitive_mod.hpp\"\n\n//ex. (2013265921,137,27),(998244353,31,23),(469762049,30,26)\n\
    template<long long MOD,int base,int max_exp>\nstruct NTT_primitive{\n    using\
    \ mint = modint<MOD>;\n    std::vector<mint> bases,invs;\n    NTT_primitive(){\n\
    \        bases.resize(max_exp + 1);invs.resize(max_exp + 1);\n        bases[max_exp]\
    \ = base;\n        invs[max_exp] = mint(base).inv();\n        for(int i = max_exp\
    \ - 1;i >= 0;i--){\n            bases[i] = bases[i + 1] * bases[i + 1];\n    \
    \        invs[i] = invs[i + 1] * invs[i + 1];\n        }\n    }\n    void dft(std::vector<mint>&\
    \ vec,int t){\n        int sz = vec.size();\n        if(sz == 1)return;\n    \
    \    std::vector<mint> veca,vecb;\n        for(int i = 0;i < sz / 2;i++){\n  \
    \          veca.push_back(vec[i * 2]);\n            vecb.push_back(vec[i * 2 +\
    \ 1]);\n        }\n        dft(veca,t);\n        dft(vecb,t);\n        \n    \
    \    int e = __builtin_ffsll(sz) - 1;\n        mint now = 1,zeta = (t == 1 ? bases[e]:invs[e]);\n\
    \        for(int i = 0;i < sz;i++){\n            vec[i] = veca[i % (sz / 2)] +\
    \ now * vecb[i % (sz / 2)];\n            now *= zeta;\n        }\n    }\n    std::vector<mint>\
    \ convolution(const std::vector<mint>& A,const std::vector<mint>& B){\n      \
    \  // assert(A.size() == B.size());\n        int sz = 1;\n        while(sz < int(A.size()\
    \ + B.size()))sz <<= 1;\n        std::vector<mint> f(sz),g(sz);\n        for(int\
    \ i = 0;i < int(A.size());i++)f[i] = A[i];\n        for(int i = 0;i < int(B.size());i++)g[i]\
    \ = B[i];\n        dft(f,1);dft(g,1);\n        for(int i = 0;i < sz;i++)f[i] =\
    \ f[i] * g[i];\n        dft(f,-1);\n        mint inv = mint(sz).inv();\n     \
    \   for(int i = 0;i < sz;i++)f[i] *= inv;\n        return f;\n    }\n    void\
    \ dft(std::vector<long long>& vec,int t){\n        int sz = vec.size();\n    \
    \    if(sz == 1)return;\n        std::vector<long long> veca,vecb;\n        for(int\
    \ i = 0;i < sz / 2;i++){\n            veca.push_back(vec[i * 2]);\n          \
    \  vecb.push_back(vec[i * 2 + 1]);\n        }\n        dft(veca,t);\n        dft(vecb,t);\n\
    \        \n        int e = __builtin_ffsll(sz) - 1;\n        long long now = 1,zeta\
    \ = (t == 1 ? bases[e].x:invs[e].x);\n        for(int i = 0;i < sz;i++){\n   \
    \         vec[i] = (veca[i % (sz / 2)] + now * vecb[i % (sz / 2)] % MOD) % MOD;\n\
    \            now = now * zeta % MOD;\n        }\n    }\n    std::vector<long long>\
    \ convolution(const std::vector<long long>& A,const std::vector<long long>& B){\n\
    \        // assert(A.size() == B.size());\n        int sz = 1;\n        while(sz\
    \ < int(A.size() + B.size()))sz <<= 1;\n        std::vector<long long> f(sz),g(sz);\n\
    \        for(int i = 0;i < int(A.size());i++)f[i] = A[i] % MOD;\n        for(int\
    \ i = 0;i < int(B.size());i++)g[i] = B[i] % MOD;\n        dft(f,1);dft(g,1);\n\
    \        for(int i = 0;i < sz;i++)f[i] = f[i] * g[i] % MOD;\n        dft(f,-1);\n\
    \        long long inv = modinv(sz,MOD);\n        for(int i = 0;i < sz;i++)f[i]\
    \ = f[i] * inv % MOD;\n        return f;\n    }\n};\n\n\n\n\n#line 9 \"math/NTT_all_mod.hpp\"\
    \n\ntemplate<long long MOD>\nstruct NTT_all{\n    NTT_primitive<2013265921,137,27>\
    \ ntt1;\n    NTT_primitive<998244353,31,23> ntt2;\n    NTT_primitive<469762049,30,26>\
    \ ntt3;\n    using mint = modint<MOD>;\n    using mint1 = modint<2013265921>;\n\
    \    using mint2 = modint<998244353>;\n    using mint3 = modint<469762049>;\n\
    \    NTT_all(){}\n    \n    std::vector<mint> convolution(const std::vector<mint>&\
    \ A,const std::vector<mint>& B){\n        int sza = A.size(),szb = B.size();\n\
    \        std::vector<mint1> A1(sza),B1(szb);\n        std::vector<mint2> A2(sza),B2(szb);\n\
    \        std::vector<mint3> A3(sza),B3(szb);\n        for(int i = 0;i < sza;i++){\n\
    \            A1[i] = A[i].x;A2[i] = A[i].x;A3[i] = A[i].x;\n        }\n      \
    \  for(int i = 0;i < szb;i++){\n            B1[i] = B[i].x;B2[i] = B[i].x;B3[i]\
    \ = B[i].x;\n        }\n        auto C1 = ntt1.convolution(A1,B1);\n        auto\
    \ C2 = ntt2.convolution(A2,B2);\n        auto C3 = ntt3.convolution(A3,B3);\n\
    \        int rs = C1.size();\n        std::vector<mint> res(rs);\n        for(int\
    \ i = 0;i < rs;i++){\n            std::vector<long long> r = {C1[i].x,C2[i].x,C3[i].x},m\
    \ = {2013265921,998244353,469762049};\n            res[i] = garner(r,m,MOD);\n\
    \        }\n        return res;\n    }\n    std::vector<long long> convolution(const\
    \ std::vector<long long>& A,const std::vector<long long>& B){\n        int sza\
    \ = A.size(),szb = B.size();\n        std::vector<long long> A1(sza),B1(szb),A2(sza),B2(szb),A3(sza),B3(szb);\n\
    \        for(int i = 0;i < sza;i++){\n            A1[i] = A[i] % 2013265921;\n\
    \            A2[i] = A[i] % 998244353;\n            A3[i] = A[i] % 469762049;\n\
    \        }\n        for(int i = 0;i < szb;i++){\n            B1[i] = B[i] % 2013265921;\n\
    \            B2[i] = B[i] % 998244353;\n            B3[i] = B[i] % 469762049;\n\
    \        }\n        auto C1 = ntt1.convolution(A1,B1);\n        auto C2 = ntt2.convolution(A2,B2);\n\
    \        auto C3 = ntt3.convolution(A3,B3);\n        int rs = C1.size();\n   \
    \     std::vector<long long> res(rs);\n        for(int i = 0;i < rs;i++){\n  \
    \          std::vector<long long> r = {C1[i],C2[i],C3[i]},m = {2013265921,998244353,469762049};\n\
    \            res[i] = garner(r,m,MOD) % MOD;\n        }\n        return res;\n\
    \    }\n};\n\n\n"
  code: "#ifndef SORAIE_NTT\n#define SORAIE_NTT\n\n#include <vector>\n#include <assert.h>\n\
    \n#include \"garner.hpp\"\n#include \"NTT_primitive_mod.hpp\"\n\ntemplate<long\
    \ long MOD>\nstruct NTT_all{\n    NTT_primitive<2013265921,137,27> ntt1;\n   \
    \ NTT_primitive<998244353,31,23> ntt2;\n    NTT_primitive<469762049,30,26> ntt3;\n\
    \    using mint = modint<MOD>;\n    using mint1 = modint<2013265921>;\n    using\
    \ mint2 = modint<998244353>;\n    using mint3 = modint<469762049>;\n    NTT_all(){}\n\
    \    \n    std::vector<mint> convolution(const std::vector<mint>& A,const std::vector<mint>&\
    \ B){\n        int sza = A.size(),szb = B.size();\n        std::vector<mint1>\
    \ A1(sza),B1(szb);\n        std::vector<mint2> A2(sza),B2(szb);\n        std::vector<mint3>\
    \ A3(sza),B3(szb);\n        for(int i = 0;i < sza;i++){\n            A1[i] = A[i].x;A2[i]\
    \ = A[i].x;A3[i] = A[i].x;\n        }\n        for(int i = 0;i < szb;i++){\n \
    \           B1[i] = B[i].x;B2[i] = B[i].x;B3[i] = B[i].x;\n        }\n       \
    \ auto C1 = ntt1.convolution(A1,B1);\n        auto C2 = ntt2.convolution(A2,B2);\n\
    \        auto C3 = ntt3.convolution(A3,B3);\n        int rs = C1.size();\n   \
    \     std::vector<mint> res(rs);\n        for(int i = 0;i < rs;i++){\n       \
    \     std::vector<long long> r = {C1[i].x,C2[i].x,C3[i].x},m = {2013265921,998244353,469762049};\n\
    \            res[i] = garner(r,m,MOD);\n        }\n        return res;\n    }\n\
    \    std::vector<long long> convolution(const std::vector<long long>& A,const\
    \ std::vector<long long>& B){\n        int sza = A.size(),szb = B.size();\n  \
    \      std::vector<long long> A1(sza),B1(szb),A2(sza),B2(szb),A3(sza),B3(szb);\n\
    \        for(int i = 0;i < sza;i++){\n            A1[i] = A[i] % 2013265921;\n\
    \            A2[i] = A[i] % 998244353;\n            A3[i] = A[i] % 469762049;\n\
    \        }\n        for(int i = 0;i < szb;i++){\n            B1[i] = B[i] % 2013265921;\n\
    \            B2[i] = B[i] % 998244353;\n            B3[i] = B[i] % 469762049;\n\
    \        }\n        auto C1 = ntt1.convolution(A1,B1);\n        auto C2 = ntt2.convolution(A2,B2);\n\
    \        auto C3 = ntt3.convolution(A3,B3);\n        int rs = C1.size();\n   \
    \     std::vector<long long> res(rs);\n        for(int i = 0;i < rs;i++){\n  \
    \          std::vector<long long> r = {C1[i],C2[i],C3[i]},m = {2013265921,998244353,469762049};\n\
    \            res[i] = garner(r,m,MOD) % MOD;\n        }\n        return res;\n\
    \    }\n};\n\n#endif /*SORAIE_NTT*/"
  dependsOn: [math/garner.hpp, math/math.hpp, math/NTT_primitive_mod.hpp, math/modint.hpp]
  isVerificationFile: false
  path: math/NTT_all_mod.hpp
  requiredBy: []
  timestamp: '2021-03-22 15:00:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith: [test/NTT_1000000007.test.cpp]
documentation_of: math/NTT_all_mod.hpp
layout: document
redirect_from: [/library/math/NTT_all_mod.hpp, /library/math/NTT_all_mod.hpp.html]
title: math/NTT_all_mod.hpp
---
