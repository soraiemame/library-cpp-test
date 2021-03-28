---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - {icon: ':heavy_check_mark:', path: math/NTT_all_mod.hpp, title: math/NTT_all_mod.hpp}
  - {icon: ':heavy_check_mark:', path: math/NTT_primitive_mod.hpp, title: math/NTT_primitive_mod.hpp}
  - {icon: ':heavy_check_mark:', path: math/garner.hpp, title: garner precalc}
  _extendedVerifiedWith:
  - {icon: ':heavy_check_mark:', path: test/NTT_1000000007.test.cpp, title: test/NTT_1000000007.test.cpp}
  - {icon: ':heavy_check_mark:', path: test/NTT_998244353.test.cpp, title: test/NTT_998244353.test.cpp}
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/math.hpp\"\n\n\n\n#include <algorithm>\n\nlong long\
    \ extgcd(long long a,long long b,long long &x,long long &y){\n    if(b == 0){\n\
    \        x = 1;\n        y = 0;\n        return a;\n    }\n    long long d = extgcd(b,a\
    \ % b,y,x);\n    y -= a / b * x;\n    return d;\n}\n\nlong long modinv(long long\
    \ a,long long p){\n    long long b = p, u = 1, v = 0;\n    while(b){\n       \
    \ long long t = a / b;\n        a -= t * b;std::swap(a, b);\n        u -= t *\
    \ v;std::swap(u, v);\n    }\n    u %= p;\n    if(u < 0)u += p;\n    return u;\n\
    }\n\n\n"
  code: "#ifndef SORAIE_MATH\n#define SORAIE_MATH\n\n#include <algorithm>\n\nlong\
    \ long extgcd(long long a,long long b,long long &x,long long &y){\n    if(b ==\
    \ 0){\n        x = 1;\n        y = 0;\n        return a;\n    }\n    long long\
    \ d = extgcd(b,a % b,y,x);\n    y -= a / b * x;\n    return d;\n}\n\nlong long\
    \ modinv(long long a,long long p){\n    long long b = p, u = 1, v = 0;\n    while(b){\n\
    \        long long t = a / b;\n        a -= t * b;std::swap(a, b);\n        u\
    \ -= t * v;std::swap(u, v);\n    }\n    u %= p;\n    if(u < 0)u += p;\n    return\
    \ u;\n}\n\n#endif /*SORAIE_MATH*/"
  dependsOn: []
  isVerificationFile: false
  path: math/math.hpp
  requiredBy: [math/garner.hpp, math/NTT_all_mod.hpp, math/NTT_primitive_mod.hpp]
  timestamp: '2021-03-21 13:18:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith: [test/NTT_1000000007.test.cpp, test/NTT_998244353.test.cpp]
documentation_of: math/math.hpp
layout: document
redirect_from: [/library/math/math.hpp, /library/math/math.hpp.html]
title: math/math.hpp
---
