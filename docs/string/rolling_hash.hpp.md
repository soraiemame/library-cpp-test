---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - {icon: ':heavy_check_mark:', path: test/rolling_hash.test.cpp, title: test/rolling_hash.test.cpp}
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/rolling_hash.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <string>\n#include <random>\n#include <chrono>\n\nstruct rolling_hash{\nprivate:\n\
    \    static const unsigned long long mod = (1ULL << 61ULL) - 1;\n    const unsigned\
    \ long long base;\n    std::vector<unsigned long long> pows;\n\n    static inline\
    \ unsigned long long add(unsigned long long a,unsigned long long b){\n       \
    \ if((a += b) >= mod)a -= mod;\n        return a;\n    }\n    static inline unsigned\
    \ long long mul(unsigned long long a,unsigned long long b){\n        __uint128_t\
    \ c = (__uint128_t)a * b;\n        return add(c >> 61,c & mod);\n    }\n    static\
    \ inline unsigned long long gen_base(){\n        std::mt19937_64 mt(std::chrono::steady_clock::now().time_since_epoch().count());\n\
    \        std::uniform_int_distribution<unsigned long long> rand(1,rolling_hash::mod\
    \ - 1);\n        return rand(mt);\n    }\n    void expand(int n){\n        if(n\
    \ + 1 > int(pows.size())){\n            int fr = pows.size();\n            pows.resize(n\
    \ + 1);\n            for(int i = fr;i <= n;i++){\n                pows[i] = mul(pows[i\
    \ - 1],base);\n            }\n        }\n    }\npublic:\n    std::vector<unsigned\
    \ long long> build(const std::string &S)const{\n        int sz = S.size();\n \
    \       std::vector<unsigned long long> res(sz + 1);\n        for(int i = 0;i\
    \ < sz;i++){\n            res[i + 1] = add(mul(res[i],base),S[i]);\n        }\n\
    \        return res;\n    }\n\n    template<class T>\n    std::vector<unsigned\
    \ long long> build(const std::vector<T> &v)const{\n        int sz = v.size();\n\
    \        std::vector<unsigned long long> res(sz + 1);\n        for(int i = 0;i\
    \ < sz;i++){\n            res[i + 1] = add(mul(res[i],base),v[i]);\n        }\n\
    \        return res;\n    }\n\n    unsigned long long get(const std::vector<unsigned\
    \ long long>& hashed,int l,int r){\n        expand(r - l);\n        return add(hashed[r],mod\
    \ - mul(hashed[l],pows[r - l]));\n    }\n\n    explicit rolling_hash(unsigned\
    \ long long _base = gen_base()):base(_base),pows{1}{}\n};\n\n\n"
  code: "#ifndef SORAIE_ROLLING_HASH\n#define SORAIE_ROLLING_HASH\n\n#include <vector>\n\
    #include <string>\n#include <random>\n#include <chrono>\n\nstruct rolling_hash{\n\
    private:\n    static const unsigned long long mod = (1ULL << 61ULL) - 1;\n   \
    \ const unsigned long long base;\n    std::vector<unsigned long long> pows;\n\n\
    \    static inline unsigned long long add(unsigned long long a,unsigned long long\
    \ b){\n        if((a += b) >= mod)a -= mod;\n        return a;\n    }\n    static\
    \ inline unsigned long long mul(unsigned long long a,unsigned long long b){\n\
    \        __uint128_t c = (__uint128_t)a * b;\n        return add(c >> 61,c & mod);\n\
    \    }\n    static inline unsigned long long gen_base(){\n        std::mt19937_64\
    \ mt(std::chrono::steady_clock::now().time_since_epoch().count());\n        std::uniform_int_distribution<unsigned\
    \ long long> rand(1,rolling_hash::mod - 1);\n        return rand(mt);\n    }\n\
    \    void expand(int n){\n        if(n + 1 > int(pows.size())){\n            int\
    \ fr = pows.size();\n            pows.resize(n + 1);\n            for(int i =\
    \ fr;i <= n;i++){\n                pows[i] = mul(pows[i - 1],base);\n        \
    \    }\n        }\n    }\npublic:\n    std::vector<unsigned long long> build(const\
    \ std::string &S)const{\n        int sz = S.size();\n        std::vector<unsigned\
    \ long long> res(sz + 1);\n        for(int i = 0;i < sz;i++){\n            res[i\
    \ + 1] = add(mul(res[i],base),S[i]);\n        }\n        return res;\n    }\n\n\
    \    template<class T>\n    std::vector<unsigned long long> build(const std::vector<T>\
    \ &v)const{\n        int sz = v.size();\n        std::vector<unsigned long long>\
    \ res(sz + 1);\n        for(int i = 0;i < sz;i++){\n            res[i + 1] = add(mul(res[i],base),v[i]);\n\
    \        }\n        return res;\n    }\n\n    unsigned long long get(const std::vector<unsigned\
    \ long long>& hashed,int l,int r){\n        expand(r - l);\n        return add(hashed[r],mod\
    \ - mul(hashed[l],pows[r - l]));\n    }\n\n    explicit rolling_hash(unsigned\
    \ long long _base = gen_base()):base(_base),pows{1}{}\n};\n\n#endif/*SORAIE_ROLLING_HASH*/"
  dependsOn: []
  isVerificationFile: false
  path: string/rolling_hash.hpp
  requiredBy: []
  timestamp: '2021-03-27 11:53:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith: [test/rolling_hash.test.cpp]
documentation_of: string/rolling_hash.hpp
layout: document
redirect_from: [/library/string/rolling_hash.hpp, /library/string/rolling_hash.hpp.html]
title: string/rolling_hash.hpp
---
