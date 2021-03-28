---
data:
  _extendedDependsOn:
  - {icon: ':heavy_check_mark:', path: data-structure/binary_indexed_tree.hpp, title: data-structure/binary_indexed_tree.hpp}
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
    links: ['https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B']
  bundledCode: "#line 1 \"test/binary_indexed_tree.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\"\n\n#include\
    \ <iostream>\n\n#line 1 \"data-structure/binary_indexed_tree.hpp\"\n\n\n\n#include\
    \ <vector>\n#line 6 \"data-structure/binary_indexed_tree.hpp\"\n#include <assert.h>\n\
    \ntemplate<class T>\nstruct BinaryIndexedTree{\n    int n;\n    std::vector<T>\
    \ dat;\n    BinaryIndexedTree (int n_):n(n_),dat(n_,0){}\n    //[m]+=a\n    void\
    \ add(int m,T a){\n        assert(0 <= m && m < n);\n        m++;\n        while(m\
    \ <= n){\n            dat[m - 1] += a;\n            m += m & -m;\n        }\n\
    \    }\n    //0 ~ m - 1\n    T sum(int m){\n        assert(0 <= m && m <= n);\n\
    \        T res = 0;\n        while(m > 0){\n            res += dat[m - 1];\n \
    \           m -= m & -m;\n        }\n        return res;\n    }\n    //l ~ r -\
    \ 1\n    T sum(int l,int r){\n        assert(0 <= l && l <= r && r <= n);\n  \
    \      return sum(r) - sum(l);\n    }\n    void deb(){\n        std::cerr << \"\
    BIT debug: [\";\n        for(int i = 0;i < n;i++)std::cerr << sum(i,i + 1) <<\
    \ (i == n - 1 ? \"]\\n\":\",\");\n    }\n};\n\n\n#line 6 \"test/binary_indexed_tree.test.cpp\"\
    \n\nint main(){\n    int N,Q;\n    std::cin >> N >> Q;\n    BinaryIndexedTree<int>\
    \ BIT(N);\n    for(int i = 0;i < Q;i++){\n        int t,a,b;\n        std::cin\
    \ >> t >> a >> b;\n        if(t == 0)BIT.add(a - 1,b);\n        if(t == 1)std::cout\
    \ << BIT.sum(a - 1,b) << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\"\
    \n\n#include <iostream>\n\n#include \"../data-structure/binary_indexed_tree.hpp\"\
    \n\nint main(){\n    int N,Q;\n    std::cin >> N >> Q;\n    BinaryIndexedTree<int>\
    \ BIT(N);\n    for(int i = 0;i < Q;i++){\n        int t,a,b;\n        std::cin\
    \ >> t >> a >> b;\n        if(t == 0)BIT.add(a - 1,b);\n        if(t == 1)std::cout\
    \ << BIT.sum(a - 1,b) << \"\\n\";\n    }\n}"
  dependsOn: [data-structure/binary_indexed_tree.hpp]
  isVerificationFile: true
  path: test/binary_indexed_tree.test.cpp
  requiredBy: []
  timestamp: '2021-03-21 13:18:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/binary_indexed_tree.test.cpp
layout: document
redirect_from: [/verify/test/binary_indexed_tree.test.cpp, /verify/test/binary_indexed_tree.test.cpp.html]
title: test/binary_indexed_tree.test.cpp
---
