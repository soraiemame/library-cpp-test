---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/floor_ceil.hpp\"\n\n\n\n\n#include <assert.h>\n\nlong\
    \ long floordiv(long long a,long long b){\n    assert(b != 0);\n    if(b < 0)a\
    \ = -a,b = -b;\n    if(a >= 0)return a / b;\n    else return (a - b + 1) / b;\n\
    }\n\nlong long ceildiv(long long a,long long b){\n    assert(b != 0);\n    if(b\
    \ < 0)a = -a,b = -b;\n    if(a >= 0)return (a + b - 1) / b;\n    else return a\
    \ / b;\n}\n\nlong long floorsqrt(long long a){\n    assert(a >= 0);\n    long\
    \ long l = -1,r = 1;\n    while(r * r <= a)r <<= 1;\n    while(r - l > 1){\n \
    \       long long mid = (r + l) / 2;\n        if(mid * mid > a)r = mid;\n    \
    \    else l = mid;\n    }\n    return l;\n}\n\n\n"
  code: "#ifndef SORAIE_FLOOR_CEIL\n#define SORAIE_FLOOR_CEIL\n\n\n#include <assert.h>\n\
    \nlong long floordiv(long long a,long long b){\n    assert(b != 0);\n    if(b\
    \ < 0)a = -a,b = -b;\n    if(a >= 0)return a / b;\n    else return (a - b + 1)\
    \ / b;\n}\n\nlong long ceildiv(long long a,long long b){\n    assert(b != 0);\n\
    \    if(b < 0)a = -a,b = -b;\n    if(a >= 0)return (a + b - 1) / b;\n    else\
    \ return a / b;\n}\n\nlong long floorsqrt(long long a){\n    assert(a >= 0);\n\
    \    long long l = -1,r = 1;\n    while(r * r <= a)r <<= 1;\n    while(r - l >\
    \ 1){\n        long long mid = (r + l) / 2;\n        if(mid * mid > a)r = mid;\n\
    \        else l = mid;\n    }\n    return l;\n}\n\n#endif /*SORAIE_FLOOR_CEIL*/"
  dependsOn: []
  isVerificationFile: false
  path: math/floor_ceil.hpp
  requiredBy: []
  timestamp: '2021-03-21 13:18:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/floor_ceil.hpp
layout: document
redirect_from: [/library/math/floor_ceil.hpp, /library/math/floor_ceil.hpp.html]
title: math/floor_ceil.hpp
---
