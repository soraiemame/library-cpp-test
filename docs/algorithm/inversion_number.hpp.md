---
data:
  _extendedDependsOn:
  - {icon: ':heavy_check_mark:', path: data-structure/binary_indexed_tree.hpp, title: data-structure/binary_indexed_tree.hpp}
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/inversion_number.hpp\"\n\n\n\n#include <vector>\n\
    #include <algorithm>\n\n#line 1 \"data-structure/binary_indexed_tree.hpp\"\n\n\
    \n\n#line 5 \"data-structure/binary_indexed_tree.hpp\"\n#include <iostream>\n\
    #include <assert.h>\n\ntemplate<class T>\nstruct BinaryIndexedTree{\n    int n;\n\
    \    std::vector<T> dat;\n    BinaryIndexedTree (int n_):n(n_),dat(n_,0){}\n \
    \   //[m]+=a\n    void add(int m,T a){\n        assert(0 <= m && m < n);\n   \
    \     m++;\n        while(m <= n){\n            dat[m - 1] += a;\n           \
    \ m += m & -m;\n        }\n    }\n    //0 ~ m - 1\n    T sum(int m){\n       \
    \ assert(0 <= m && m <= n);\n        T res = 0;\n        while(m > 0){\n     \
    \       res += dat[m - 1];\n            m -= m & -m;\n        }\n        return\
    \ res;\n    }\n    //l ~ r - 1\n    T sum(int l,int r){\n        assert(0 <= l\
    \ && l <= r && r <= n);\n        return sum(r) - sum(l);\n    }\n    void deb(){\n\
    \        std::cerr << \"BIT debug: [\";\n        for(int i = 0;i < n;i++)std::cerr\
    \ << sum(i,i + 1) << (i == n - 1 ? \"]\\n\":\",\");\n    }\n};\n\n\n#line 8 \"\
    algorithm/inversion_number.hpp\"\n\ntemplate<class T>\nlong long inversion_number(const\
    \ std::vector<T> &V,bool compress = true){\n    int n = V.size();\n    std::vector<T>\
    \ vec = V;\n    if(compress){\n        std::vector<T> zaatu = V;\n        std::sort(zaatu.begin(),zaatu.end());\n\
    \        for(T& a : vec)a = std::lower_bound(zaatu.begin(),zaatu.end(),a) - zaatu.begin();\n\
    \    }\n    BinaryIndexedTree<int> BIT(n);\n    long long ans = 0;\n    for(int\
    \ i = 0;i < n;i++){\n        ans = ans + i - BIT.sum(0,vec[i]);\n        BIT.add(vec[i],1);\n\
    \    }\n    return ans;\n}\n\n\n"
  code: "#ifndef SORAIE_INVERSION_NUMBER\n#define SORAIE_INVERSION_NUMBER\n\n#include\
    \ <vector>\n#include <algorithm>\n\n#include \"../data-structure/binary_indexed_tree.hpp\"\
    \n\ntemplate<class T>\nlong long inversion_number(const std::vector<T> &V,bool\
    \ compress = true){\n    int n = V.size();\n    std::vector<T> vec = V;\n    if(compress){\n\
    \        std::vector<T> zaatu = V;\n        std::sort(zaatu.begin(),zaatu.end());\n\
    \        for(T& a : vec)a = std::lower_bound(zaatu.begin(),zaatu.end(),a) - zaatu.begin();\n\
    \    }\n    BinaryIndexedTree<int> BIT(n);\n    long long ans = 0;\n    for(int\
    \ i = 0;i < n;i++){\n        ans = ans + i - BIT.sum(0,vec[i]);\n        BIT.add(vec[i],1);\n\
    \    }\n    return ans;\n}\n\n#endif /*SORAIE_INVERSION_NUMBER*/"
  dependsOn: [data-structure/binary_indexed_tree.hpp]
  isVerificationFile: false
  path: algorithm/inversion_number.hpp
  requiredBy: []
  timestamp: '2021-03-21 13:18:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/inversion_number.hpp
layout: document
redirect_from: [/library/algorithm/inversion_number.hpp, /library/algorithm/inversion_number.hpp.html]
title: algorithm/inversion_number.hpp
---
