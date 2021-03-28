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
  bundledCode: "#line 1 \"math/high_speed_prime.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <map>\n\nstd::vector<int> prime_factor_table;\nvoid prime_factor_pre_calc(int\
    \ n = 1e5){\n    prime_factor_table.resize(n);\n    prime_factor_table[1] = 1;\n\
    \    for(int i = 2;i < n;i++){\n        if(!prime_factor_table[i]){\n        \
    \    for(int j = i;j < n;j += i)prime_factor_table[j] = i;\n        }\n    }\n\
    }\nstd::map<int,int> high_speed_prime_factor(int n){\n    std::map<int,int> res;\n\
    \    while(n != 1){\n        res[prime_factor_table[n]]++;\n        n /= prime_factor_table[n];\n\
    \    }\n    return res;\n}\n\n\n"
  code: "#ifndef SORAIE_HIGH_SPEED_PRIME\n#define SORAIE_HIGH_SPEED_PRIME\n\n#include\
    \ <vector>\n#include <map>\n\nstd::vector<int> prime_factor_table;\nvoid prime_factor_pre_calc(int\
    \ n = 1e5){\n    prime_factor_table.resize(n);\n    prime_factor_table[1] = 1;\n\
    \    for(int i = 2;i < n;i++){\n        if(!prime_factor_table[i]){\n        \
    \    for(int j = i;j < n;j += i)prime_factor_table[j] = i;\n        }\n    }\n\
    }\nstd::map<int,int> high_speed_prime_factor(int n){\n    std::map<int,int> res;\n\
    \    while(n != 1){\n        res[prime_factor_table[n]]++;\n        n /= prime_factor_table[n];\n\
    \    }\n    return res;\n}\n\n#endif /*SORAIE_HIGH_SPEED_PRIME*/"
  dependsOn: []
  isVerificationFile: false
  path: math/high_speed_prime.hpp
  requiredBy: []
  timestamp: '2021-03-21 13:18:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/high_speed_prime.hpp
layout: document
redirect_from: [/library/math/high_speed_prime.hpp, /library/math/high_speed_prime.hpp.html]
title: math/high_speed_prime.hpp
---
