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
  bundledCode: "#line 1 \"utils/time.hpp\"\n\n\n\n#include <chrono>\n#include <assert.h>\n\
    \nstruct mytime{\n    bool started;\n    std::chrono::_V2::system_clock::time_point\
    \ start;\n    mytime(){started = false;}\n    void s(){\n        started = true;\n\
    \        start = std::chrono::system_clock::now();\n    }\n    long long get(){\n\
    \        assert(started);\n        auto end = std::chrono::system_clock::now();\n\
    \        auto diff = end - start;\n        return std::chrono::duration_cast<std::chrono::milliseconds>(diff).count();\n\
    \    }\n    void out(){\n        cout << \"Elapsed Time: \" << get() << \" ms\\\
    n\";\n    }\n};\n\n\n"
  code: "#ifndef SORAIE_TIME\n#define SORAIE_TIME\n\n#include <chrono>\n#include <assert.h>\n\
    \nstruct mytime{\n    bool started;\n    std::chrono::_V2::system_clock::time_point\
    \ start;\n    mytime(){started = false;}\n    void s(){\n        started = true;\n\
    \        start = std::chrono::system_clock::now();\n    }\n    long long get(){\n\
    \        assert(started);\n        auto end = std::chrono::system_clock::now();\n\
    \        auto diff = end - start;\n        return std::chrono::duration_cast<std::chrono::milliseconds>(diff).count();\n\
    \    }\n    void out(){\n        cout << \"Elapsed Time: \" << get() << \" ms\\\
    n\";\n    }\n};\n\n#endif /*SORAIE_TIME*/"
  dependsOn: []
  isVerificationFile: false
  path: utils/time.hpp
  requiredBy: []
  timestamp: '2021-03-21 13:18:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utils/time.hpp
layout: document
redirect_from: [/library/utils/time.hpp, /library/utils/time.hpp.html]
title: utils/time.hpp
---
