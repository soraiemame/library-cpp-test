---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - {icon: ':heavy_check_mark:', path: test/sparse_table.test.cpp, title: test/sparse_table.test.cpp}
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/sparse_table.hpp\"\n\n\n\n#include <vector>\n\
    #include <algorithm>\n#include <assert.h>\n\ntemplate<class T>\nstruct SparseTable{\n\
    \    int n;\n    std::vector<std::vector<T>> table;\n    SparseTable(const std::vector<T>&\
    \ table_){\n        n = table_.size();\n        int log = 1;\n        while(1\
    \ << log < n)log++;\n        table = std::vector<std::vector<T>>(log,std::vector<T>(n));\n\
    \        for(int i = 0;i < n;i++)table[0][i] = table_[i];\n        for(int i =\
    \ 1;i < log;i++){\n            for(int j = 0;j + (1 << i - 1) < n;j++){\n    \
    \            table[i][j] = std::min(table[i - 1][j],table[i - 1][j + (1 << i -\
    \ 1)]);\n            }\n        }\n    }\n    T query(int l,int r){\n        assert(l\
    \ < r);\n        int log = 0;\n        while(1 << (log + 1) < r - l)log++;\n \
    \       return std::min(table[log][l],table[log][r - (1 << log)]);\n    }\n};\n\
    \n\n"
  code: "#ifndef SORAIE_SPARSE_TABLE\n#define SORAIE_SPARSE_TABLE\n\n#include <vector>\n\
    #include <algorithm>\n#include <assert.h>\n\ntemplate<class T>\nstruct SparseTable{\n\
    \    int n;\n    std::vector<std::vector<T>> table;\n    SparseTable(const std::vector<T>&\
    \ table_){\n        n = table_.size();\n        int log = 1;\n        while(1\
    \ << log < n)log++;\n        table = std::vector<std::vector<T>>(log,std::vector<T>(n));\n\
    \        for(int i = 0;i < n;i++)table[0][i] = table_[i];\n        for(int i =\
    \ 1;i < log;i++){\n            for(int j = 0;j + (1 << i - 1) < n;j++){\n    \
    \            table[i][j] = std::min(table[i - 1][j],table[i - 1][j + (1 << i -\
    \ 1)]);\n            }\n        }\n    }\n    T query(int l,int r){\n        assert(l\
    \ < r);\n        int log = 0;\n        while(1 << (log + 1) < r - l)log++;\n \
    \       return std::min(table[log][l],table[log][r - (1 << log)]);\n    }\n};\n\
    \n#endif /*SORAIE_SPARSE_TABLE*/"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/sparse_table.hpp
  requiredBy: []
  timestamp: '2021-03-21 13:18:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith: [test/sparse_table.test.cpp]
documentation_of: data-structure/sparse_table.hpp
layout: document
redirect_from: [/library/data-structure/sparse_table.hpp, /library/data-structure/sparse_table.hpp.html]
title: data-structure/sparse_table.hpp
---
