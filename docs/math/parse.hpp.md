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
  bundledCode: "#line 1 \"math/parse.hpp\"\n\n\n\n#include <string>\n\nlong long x10(const\
    \ std::string& s,size_t n){\n    if(s.front() == '-')return -x10(s.substr(1),n);\n\
    \    auto pos = s.find('.');\n    if(pos == std::string::npos)return stoll(s +\
    \ std::string(n,'0'));\n    else return stoll(s.substr(0,pos) + s.substr(pos +\
    \ 1) + std::string(n + pos + 1 - s.size(),'0'));\n}\n\n\n"
  code: "#ifndef SORAIE_PARSE\n#define SORAIE_PARSE\n\n#include <string>\n\nlong long\
    \ x10(const std::string& s,size_t n){\n    if(s.front() == '-')return -x10(s.substr(1),n);\n\
    \    auto pos = s.find('.');\n    if(pos == std::string::npos)return stoll(s +\
    \ std::string(n,'0'));\n    else return stoll(s.substr(0,pos) + s.substr(pos +\
    \ 1) + std::string(n + pos + 1 - s.size(),'0'));\n}\n\n#endif /*SORAIE_PARSE*/"
  dependsOn: []
  isVerificationFile: false
  path: math/parse.hpp
  requiredBy: []
  timestamp: '2021-03-21 13:18:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/parse.hpp
layout: document
redirect_from: [/library/math/parse.hpp, /library/math/parse.hpp.html]
title: math/parse.hpp
---
