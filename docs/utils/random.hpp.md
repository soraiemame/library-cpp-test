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
  bundledCode: "#line 1 \"utils/random.hpp\"\n\n\n\n#include <random>\n\nunsigned\
    \ long long xor128(){\n    static unsigned long long tx = 123456789, ty=362436069,\
    \ tz=521288629, tw=88675123;\n    unsigned long long tt = (tx^(tx<<11));\n   \
    \ tx = ty; ty = tz; tz = tw;\n    return (tw=(tw^(tw>>19))^(tt^(tt>>8)));\n}\n\
    \nunsigned long long xor128(unsigned long long a){\n    return xor128() % (a +\
    \ 1);\n}\n\nunsigned long long xor128(unsigned long long a,unsigned long long\
    \ b){\n    return xor128(b - a + 1) + a;\n}\n\nlong long xor128(long long a,long\
    \ long b){\n    return xor128(b - a - 1) + a;\n}\n\nstd::random_device randomd;\n\
    std::mt19937_64 mt(randomd());\nlong long randint(){\n    std::uniform_int_distribution<long\
    \ long> uni;\n    return uni(mt);\n}\n\nlong long randint(long long a){\n    std::uniform_int_distribution<long\
    \ long> uni(0,a);\n    return uni(mt);\n}\n\nlong long randint(long long a,long\
    \ long b){\n    std::uniform_int_distribution<long long> uni(a,b);\n    return\
    \ uni(mt);\n}\n\nlong long randfloat(){\n    std::uniform_real_distribution<long\
    \ double> uni;\n    return uni(mt);\n}\n\nlong long randfloat(long long a){\n\
    \    std::uniform_real_distribution<long double> uni(0,a);\n    return uni(mt);\n\
    }\n\nlong double randfloat(long double a,long double b){\n    std::uniform_real_distribution<long\
    \ double> uni(a,b);\n    return uni(mt);\n}\n\n\n\n\n"
  code: "#ifndef SORAIE_RANDOM\n#define SORAIE_RANDOM\n\n#include <random>\n\nunsigned\
    \ long long xor128(){\n    static unsigned long long tx = 123456789, ty=362436069,\
    \ tz=521288629, tw=88675123;\n    unsigned long long tt = (tx^(tx<<11));\n   \
    \ tx = ty; ty = tz; tz = tw;\n    return (tw=(tw^(tw>>19))^(tt^(tt>>8)));\n}\n\
    \nunsigned long long xor128(unsigned long long a){\n    return xor128() % (a +\
    \ 1);\n}\n\nunsigned long long xor128(unsigned long long a,unsigned long long\
    \ b){\n    return xor128(b - a + 1) + a;\n}\n\nlong long xor128(long long a,long\
    \ long b){\n    return xor128(b - a - 1) + a;\n}\n\nstd::random_device randomd;\n\
    std::mt19937_64 mt(randomd());\nlong long randint(){\n    std::uniform_int_distribution<long\
    \ long> uni;\n    return uni(mt);\n}\n\nlong long randint(long long a){\n    std::uniform_int_distribution<long\
    \ long> uni(0,a);\n    return uni(mt);\n}\n\nlong long randint(long long a,long\
    \ long b){\n    std::uniform_int_distribution<long long> uni(a,b);\n    return\
    \ uni(mt);\n}\n\nlong long randfloat(){\n    std::uniform_real_distribution<long\
    \ double> uni;\n    return uni(mt);\n}\n\nlong long randfloat(long long a){\n\
    \    std::uniform_real_distribution<long double> uni(0,a);\n    return uni(mt);\n\
    }\n\nlong double randfloat(long double a,long double b){\n    std::uniform_real_distribution<long\
    \ double> uni(a,b);\n    return uni(mt);\n}\n\n\n\n#endif /*SORAIE_RANDOM*/"
  dependsOn: []
  isVerificationFile: false
  path: utils/random.hpp
  requiredBy: []
  timestamp: '2021-03-21 13:18:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utils/random.hpp
layout: document
redirect_from: [/library/utils/random.hpp, /library/utils/random.hpp.html]
title: utils/random.hpp
---
