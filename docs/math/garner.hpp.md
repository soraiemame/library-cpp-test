---
data:
  _extendedDependsOn:
  - {icon: ':heavy_check_mark:', path: math/math.hpp, title: math/math.hpp}
  _extendedRequiredBy:
  - {icon: ':heavy_check_mark:', path: math/NTT_all_mod.hpp, title: math/NTT_all_mod.hpp}
  _extendedVerifiedWith:
  - {icon: ':heavy_check_mark:', path: test/NTT_1000000007.test.cpp, title: test/NTT_1000000007.test.cpp}
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: garner precalc
    links: []
  bundledCode: "#line 1 \"math/garner.hpp\"\n\n\n\n#include <numeric>\n#include <vector>\n\
    #include <assert.h>\n\n#line 1 \"math/math.hpp\"\n\n\n\n#include <algorithm>\n\
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
    \ * mods[i] % mods[j];\n        }\n    }\n    return con.back();\n}\n\n\n"
  code: "#ifndef SORAIE_GARNER\n#define SORAIE_GARNER\n\n#include <numeric>\n#include\
    \ <vector>\n#include <assert.h>\n\n#include \"math.hpp\"\n\n/**\n * @brief garner\
    \ precalc\n * @return long long \n */\nlong long pregarner(std::vector<long long>\
    \ &rems,std::vector<long long> &mods,long long MOD){\n    assert(rems.size() ==\
    \ mods.size());\n    for(int i = 0;i < int(rems.size());i++){\n        for(int\
    \ j = 0;j < i;j++){\n            long long g = std::gcd(mods[i],mods[j]);\n  \
    \          if((rems[i] - rems[j]) % g != 0)return -1;\n            mods[i] /=\
    \ g;mods[j] /= g;\n            long long gi = std::gcd(g,mods[i]),gj = g / gi;\n\
    \            do{\n                g = std::gcd(gi,gj);\n                gi *=\
    \ g;gj /= g;\n            }while(g != 1);\n            mods[i] *= gi;mods[j] *=\
    \ gj;\n            rems[i] %= mods[i];rems[j] %= mods[j];\n        }\n    }\n\
    \    long long res = 1;\n    for(long long &a : mods)res = res * a % MOD;\n  \
    \  return res;\n}\n\n/**\n * @brief returns a integer where rems[i](mod.mods[i]).\n\
    \ * @return long long \n */\nlong long garner(std::vector<long long> rems,std::vector<long\
    \ long> mods,long long MOD){\n    assert(rems.size() == mods.size());\n    mods.push_back(MOD);\n\
    \    int sz = mods.size();\n    std::vector<long long> cof(sz,1LL),con(sz,0LL);\n\
    \    for(int i = 0;i < sz - 1;i++){\n        long long cur = (rems[i] - con[i])\
    \ * modinv(cof[i],mods[i]) % mods[i];\n        if(cur < 0)cur += mods[i];\n  \
    \      for(int j = i + 1;j < sz;j++){\n            con[j] = (con[j] + cur * cof[j])\
    \ % mods[j];\n            cof[j] = cof[j] * mods[i] % mods[j];\n        }\n  \
    \  }\n    return con.back();\n}\n\n#endif /*SORAIE_GARNER*/"
  dependsOn: [math/math.hpp]
  isVerificationFile: false
  path: math/garner.hpp
  requiredBy: [math/NTT_all_mod.hpp]
  timestamp: '2021-03-21 13:18:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith: [test/NTT_1000000007.test.cpp]
documentation_of: math/garner.hpp
layout: document
redirect_from: [/library/math/garner.hpp, /library/math/garner.hpp.html]
title: garner precalc
---
