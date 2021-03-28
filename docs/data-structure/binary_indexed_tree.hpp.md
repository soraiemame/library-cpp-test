---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - {icon: ':warning:', path: algorithm/inversion_number.hpp, title: algorithm/inversion_number.hpp}
  _extendedVerifiedWith:
  - {icon: ':heavy_check_mark:', path: test/binary_indexed_tree.test.cpp, title: test/binary_indexed_tree.test.cpp}
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/binary_indexed_tree.hpp\"\n\n\n\n#include\
    \ <vector>\n#include <iostream>\n#include <assert.h>\n\ntemplate<class T>\nstruct\
    \ BinaryIndexedTree{\n    int n;\n    std::vector<T> dat;\n    BinaryIndexedTree\
    \ (int n_):n(n_),dat(n_,0){}\n    //[m]+=a\n    void add(int m,T a){\n       \
    \ assert(0 <= m && m < n);\n        m++;\n        while(m <= n){\n           \
    \ dat[m - 1] += a;\n            m += m & -m;\n        }\n    }\n    //0 ~ m -\
    \ 1\n    T sum(int m){\n        assert(0 <= m && m <= n);\n        T res = 0;\n\
    \        while(m > 0){\n            res += dat[m - 1];\n            m -= m & -m;\n\
    \        }\n        return res;\n    }\n    //l ~ r - 1\n    T sum(int l,int r){\n\
    \        assert(0 <= l && l <= r && r <= n);\n        return sum(r) - sum(l);\n\
    \    }\n    void deb(){\n        std::cerr << \"BIT debug: [\";\n        for(int\
    \ i = 0;i < n;i++)std::cerr << sum(i,i + 1) << (i == n - 1 ? \"]\\n\":\",\");\n\
    \    }\n};\n\n\n"
  code: "#ifndef SORAIE_BINARY_INDEXED_TREE\n#define SORAIE_BINARY_INDEXED_TREE\n\n\
    #include <vector>\n#include <iostream>\n#include <assert.h>\n\ntemplate<class\
    \ T>\nstruct BinaryIndexedTree{\n    int n;\n    std::vector<T> dat;\n    BinaryIndexedTree\
    \ (int n_):n(n_),dat(n_,0){}\n    //[m]+=a\n    void add(int m,T a){\n       \
    \ assert(0 <= m && m < n);\n        m++;\n        while(m <= n){\n           \
    \ dat[m - 1] += a;\n            m += m & -m;\n        }\n    }\n    //0 ~ m -\
    \ 1\n    T sum(int m){\n        assert(0 <= m && m <= n);\n        T res = 0;\n\
    \        while(m > 0){\n            res += dat[m - 1];\n            m -= m & -m;\n\
    \        }\n        return res;\n    }\n    //l ~ r - 1\n    T sum(int l,int r){\n\
    \        assert(0 <= l && l <= r && r <= n);\n        return sum(r) - sum(l);\n\
    \    }\n    void deb(){\n        std::cerr << \"BIT debug: [\";\n        for(int\
    \ i = 0;i < n;i++)std::cerr << sum(i,i + 1) << (i == n - 1 ? \"]\\n\":\",\");\n\
    \    }\n};\n\n#endif /*SORAIE_BINARY_INDEXED_TREE*/"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/binary_indexed_tree.hpp
  requiredBy: [algorithm/inversion_number.hpp]
  timestamp: '2021-03-21 13:18:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith: [test/binary_indexed_tree.test.cpp]
documentation_of: data-structure/binary_indexed_tree.hpp
layout: document
redirect_from: [/library/data-structure/binary_indexed_tree.hpp, /library/data-structure/binary_indexed_tree.hpp.html]
title: data-structure/binary_indexed_tree.hpp
---
