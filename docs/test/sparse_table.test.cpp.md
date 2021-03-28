---
data:
  _extendedDependsOn:
  - {icon: ':heavy_check_mark:', path: data-structure/sparse_table.hpp, title: data-structure/sparse_table.hpp}
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links: ['https://judge.yosupo.jp/problem/staticrmq']
  bundledCode: "#line 1 \"test/sparse_table.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
    \n\n#include <iostream>\n#include <algorithm>\n#include <vector>\n\n#line 1 \"\
    data-structure/sparse_table.hpp\"\n\n\n\n#line 6 \"data-structure/sparse_table.hpp\"\
    \n#include <assert.h>\n\ntemplate<class T>\nstruct SparseTable{\n    int n;\n\
    \    std::vector<std::vector<T>> table;\n    SparseTable(const std::vector<T>&\
    \ table_){\n        n = table_.size();\n        int log = 1;\n        while(1\
    \ << log < n)log++;\n        table = std::vector<std::vector<T>>(log,std::vector<T>(n));\n\
    \        for(int i = 0;i < n;i++)table[0][i] = table_[i];\n        for(int i =\
    \ 1;i < log;i++){\n            for(int j = 0;j + (1 << i - 1) < n;j++){\n    \
    \            table[i][j] = std::min(table[i - 1][j],table[i - 1][j + (1 << i -\
    \ 1)]);\n            }\n        }\n    }\n    T query(int l,int r){\n        assert(l\
    \ < r);\n        int log = 0;\n        while(1 << (log + 1) < r - l)log++;\n \
    \       return std::min(table[log][l],table[log][r - (1 << log)]);\n    }\n};\n\
    \n\n#line 8 \"test/sparse_table.test.cpp\"\n\nint main(){\n    int N,Q;\n    std::cin\
    \ >> N >> Q;\n    std::vector<long long> vec(N);\n    for(int i = 0;i < N;i++)std::cin\
    \ >> vec[i];\n    SparseTable<long long> S(vec);\n    for(int i = 0;i < Q;i++){\n\
    \        int l,r;\n        std::cin >> l >> r;\n        std::cout << S.query(l,r)\
    \ << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ <iostream>\n#include <algorithm>\n#include <vector>\n\n#include \"../data-structure/sparse_table.hpp\"\
    \n\nint main(){\n    int N,Q;\n    std::cin >> N >> Q;\n    std::vector<long long>\
    \ vec(N);\n    for(int i = 0;i < N;i++)std::cin >> vec[i];\n    SparseTable<long\
    \ long> S(vec);\n    for(int i = 0;i < Q;i++){\n        int l,r;\n        std::cin\
    \ >> l >> r;\n        std::cout << S.query(l,r) << \"\\n\";\n    }\n}"
  dependsOn: [data-structure/sparse_table.hpp]
  isVerificationFile: true
  path: test/sparse_table.test.cpp
  requiredBy: []
  timestamp: '2021-03-21 13:18:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/sparse_table.test.cpp
layout: document
redirect_from: [/verify/test/sparse_table.test.cpp, /verify/test/sparse_table.test.cpp.html]
title: test/sparse_table.test.cpp
---
