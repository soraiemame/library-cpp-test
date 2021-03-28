---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - {icon: ':heavy_check_mark:', path: test/CHT.test.cpp, title: test/CHT.test.cpp}
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/CHT.hpp\"\n\n\n\n#include <set>\n#include\
    \ <map>\n#include <algorithm>\n\nstruct ConvexHullTrick{\nprivate:\n    bool MIN;\n\
    \    long long lim;\n    struct line{\n        long long a,b,lim;\n        line(long\
    \ long a_,long long b_,long long _lim = 1LL << 60):a(a_),b(b_),lim(_lim){}\n \
    \       bool operator<(const line& l)const{return std::make_pair(-a,b) < std::make_pair(-l.a,l.b);}\n\
    \    };\n    struct rational{\n        long long u,s,lim;//x\u304Cu/s\n      \
    \  rational(long long u_ = 0,long long s_ = 1,long long _lim = 1LL << 60):u(u_),s(s_),lim(_lim){\n\
    \            if(s < 0)u = -u,s = -s;\n        }\n        bool operator<(const\
    \ rational& CP_)const{\n            if(u == lim || CP_.u == -lim)return false;\n\
    \            if(u == -lim || CP_.u == lim)return true;\n            return (__int128_t)u\
    \ * CP_.s < (__int128_t)CP_.u * s;\n        }\n    };\n    using it = std::set<line>::iterator;\n\
    \    std::set<line> S;\n    std::map<rational,line> C;\n    void C_erase(it from,it\
    \ to){\n        for(;from != to;++from)C.erase(cp(*from,*next(from)));\n    }\n\
    \    rational cp(line l1,line l2){\n        if(l1.a == lim)return rational(-lim);\n\
    \        if(l2.a == -lim)return rational(lim);\n        return rational(l1.b -\
    \ l2.b,l2.a - l1.a);\n    }\n    bool need(line l1,line l2,line l3){\n       \
    \ if(l1.a == l2.a && l1.b <= l2.b)return false;\n        if(l1.a == lim || l3.a\
    \ == -lim)return true;\n        return (__int128_t)(l2.a - l1.a) * (l3.b - l2.b)\
    \ < (__int128_t)(l2.b - l1.b) * (l3.a - l2.a);\n    }\npublic:\n    ConvexHullTrick(bool\
    \ MIN_ = true,long long _lim = 1LL << 60):MIN(MIN_),lim(_lim){\n        S.insert({lim,0});\n\
    \        S.insert({-lim,0});\n        C.emplace(rational(-lim),line(-lim,0));\n\
    \    }\n    void add_line(long long a,long long b){\n        if(!MIN)a = -a,b\
    \ = -b;\n        it ite = S.insert({a,b}).first;\n        if(!need(*prev(ite),{a,b},*next(ite))){\n\
    \            S.erase(ite);\n            return;\n        }\n        C.erase(cp(*prev(ite),*next(ite)));\n\
    \        auto ju1 = prev(ite);\n        while(ju1 != S.begin() && !need(*prev(ju1),*ju1,{a,b}))--ju1;\n\
    \        C_erase(ju1,prev(ite));\n        ite = S.erase(++ju1,ite);\n        auto\
    \ ju2 = next(ite);\n        while(next(ju2) != S.end() && !need({a,b},*ju2,*next(ju2)))++ju2;\n\
    \        C_erase(++ite,ju2);\n        ite = prev(S.erase(ite,ju2));\n        C.emplace(cp(*prev(ite),*ite),*ite);\n\
    \        C.emplace(cp(*ite,*next(ite)),*next(ite));\n    }\n    long long query(long\
    \ long x){\n        line f = std::prev(C.lower_bound(rational(x)))->second;\n\
    \        return (f.a * x + f.b) * (MIN ? 1 : -1);\n    }\n};\n\n\n"
  code: "#ifndef SORAIE_CHT\n#define SORAIE_CHT\n\n#include <set>\n#include <map>\n\
    #include <algorithm>\n\nstruct ConvexHullTrick{\nprivate:\n    bool MIN;\n   \
    \ long long lim;\n    struct line{\n        long long a,b,lim;\n        line(long\
    \ long a_,long long b_,long long _lim = 1LL << 60):a(a_),b(b_),lim(_lim){}\n \
    \       bool operator<(const line& l)const{return std::make_pair(-a,b) < std::make_pair(-l.a,l.b);}\n\
    \    };\n    struct rational{\n        long long u,s,lim;//x\u304Cu/s\n      \
    \  rational(long long u_ = 0,long long s_ = 1,long long _lim = 1LL << 60):u(u_),s(s_),lim(_lim){\n\
    \            if(s < 0)u = -u,s = -s;\n        }\n        bool operator<(const\
    \ rational& CP_)const{\n            if(u == lim || CP_.u == -lim)return false;\n\
    \            if(u == -lim || CP_.u == lim)return true;\n            return (__int128_t)u\
    \ * CP_.s < (__int128_t)CP_.u * s;\n        }\n    };\n    using it = std::set<line>::iterator;\n\
    \    std::set<line> S;\n    std::map<rational,line> C;\n    void C_erase(it from,it\
    \ to){\n        for(;from != to;++from)C.erase(cp(*from,*next(from)));\n    }\n\
    \    rational cp(line l1,line l2){\n        if(l1.a == lim)return rational(-lim);\n\
    \        if(l2.a == -lim)return rational(lim);\n        return rational(l1.b -\
    \ l2.b,l2.a - l1.a);\n    }\n    bool need(line l1,line l2,line l3){\n       \
    \ if(l1.a == l2.a && l1.b <= l2.b)return false;\n        if(l1.a == lim || l3.a\
    \ == -lim)return true;\n        return (__int128_t)(l2.a - l1.a) * (l3.b - l2.b)\
    \ < (__int128_t)(l2.b - l1.b) * (l3.a - l2.a);\n    }\npublic:\n    ConvexHullTrick(bool\
    \ MIN_ = true,long long _lim = 1LL << 60):MIN(MIN_),lim(_lim){\n        S.insert({lim,0});\n\
    \        S.insert({-lim,0});\n        C.emplace(rational(-lim),line(-lim,0));\n\
    \    }\n    void add_line(long long a,long long b){\n        if(!MIN)a = -a,b\
    \ = -b;\n        it ite = S.insert({a,b}).first;\n        if(!need(*prev(ite),{a,b},*next(ite))){\n\
    \            S.erase(ite);\n            return;\n        }\n        C.erase(cp(*prev(ite),*next(ite)));\n\
    \        auto ju1 = prev(ite);\n        while(ju1 != S.begin() && !need(*prev(ju1),*ju1,{a,b}))--ju1;\n\
    \        C_erase(ju1,prev(ite));\n        ite = S.erase(++ju1,ite);\n        auto\
    \ ju2 = next(ite);\n        while(next(ju2) != S.end() && !need({a,b},*ju2,*next(ju2)))++ju2;\n\
    \        C_erase(++ite,ju2);\n        ite = prev(S.erase(ite,ju2));\n        C.emplace(cp(*prev(ite),*ite),*ite);\n\
    \        C.emplace(cp(*ite,*next(ite)),*next(ite));\n    }\n    long long query(long\
    \ long x){\n        line f = std::prev(C.lower_bound(rational(x)))->second;\n\
    \        return (f.a * x + f.b) * (MIN ? 1 : -1);\n    }\n};\n\n#endif /*SORAIE_CHT*/"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/CHT.hpp
  requiredBy: []
  timestamp: '2021-03-21 13:18:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith: [test/CHT.test.cpp]
documentation_of: data-structure/CHT.hpp
layout: document
redirect_from: [/library/data-structure/CHT.hpp, /library/data-structure/CHT.hpp.html]
title: data-structure/CHT.hpp
---
