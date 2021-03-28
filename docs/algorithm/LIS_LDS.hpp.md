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
  bundledCode: "#line 1 \"algorithm/LIS_LDS.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <algorithm>\n\ntemplate<class T>\nstd::vector<int> LIS(const std::vector<T>&\
    \ vec){\n    int n = vec.size();\n    std::vector<int> memo(n,INT32_MAX);\n  \
    \  for(T a : vec)*std::lower_bound(memo.begin(),memo.end(),a) = a;\n    return\
    \ std::vector<int>(memo.begin(),std::lower_bound(memo.begin(),memo.end(),INT32_MAX));\n\
    }\ntemplate<class T>\nstd::vector<int> LDS(const std::vector<T>& _vec){\n    std::vector<T>\
    \ vec = _vec;\n    std::reverse(vec.begin(),vec.end());\n    auto res = LIS(vec);\n\
    \    std::reverse(res.begin(),res.end());\n    return res;\n}\n\n\n"
  code: "#ifndef SORAIE_LIS_LDS\n#define SORAIE_LIS_LDS\n\n#include <vector>\n#include\
    \ <algorithm>\n\ntemplate<class T>\nstd::vector<int> LIS(const std::vector<T>&\
    \ vec){\n    int n = vec.size();\n    std::vector<int> memo(n,INT32_MAX);\n  \
    \  for(T a : vec)*std::lower_bound(memo.begin(),memo.end(),a) = a;\n    return\
    \ std::vector<int>(memo.begin(),std::lower_bound(memo.begin(),memo.end(),INT32_MAX));\n\
    }\ntemplate<class T>\nstd::vector<int> LDS(const std::vector<T>& _vec){\n    std::vector<T>\
    \ vec = _vec;\n    std::reverse(vec.begin(),vec.end());\n    auto res = LIS(vec);\n\
    \    std::reverse(res.begin(),res.end());\n    return res;\n}\n\n#endif/*SORAIE_LIS_LDS*/"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/LIS_LDS.hpp
  requiredBy: []
  timestamp: '2021-03-21 13:18:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/LIS_LDS.hpp
layout: document
redirect_from: [/library/algorithm/LIS_LDS.hpp, /library/algorithm/LIS_LDS.hpp.html]
title: algorithm/LIS_LDS.hpp
---
