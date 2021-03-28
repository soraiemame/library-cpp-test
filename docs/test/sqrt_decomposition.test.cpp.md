---
data:
  _extendedDependsOn:
  - {icon: ':heavy_check_mark:', path: data-structure/sqrt_decomposition.hpp, title: data-structure/sqrt_decomposition.hpp}
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links: ['https://judge.yosupo.jp/problem/aplusb']
  bundledCode: "#line 1 \"test/sqrt_decomposition.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n\n#include <iostream>\n#include <vector>\n#include <algorithm>\n#include <random>\n\
    #include <assert.h>\n\n#line 1 \"data-structure/sqrt_decomposition.hpp\"\n\n\n\
    \n#line 7 \"data-structure/sqrt_decomposition.hpp\"\n\ntemplate<class T>\nstruct\
    \ sqrt_dec{\n    struct bucket{\n        std::vector<T> dat,so,wa;\n        int\
    \ l,r;\n        T LM,min_val,max_val,add_val,low_val,high_val;\n        bucket(const\
    \ std::vector<T>& a,int l_,int r_,T LM_):l(l_),r(r_),LM(LM_),add_val(0),low_val(-LM),high_val(LM){\n\
    \            dat = std::vector<T>(r - l);\n            wa = std::vector<T>(r -\
    \ l + 1);\n            for(int i = l;i < r;i++)dat[i - l] = a[i];\n          \
    \  eval_calc();\n        }\n\n        void eval_update(){\n            for(auto\
    \ &i : dat)i = std::clamp(i + add_val,low_val,high_val);\n            add_val\
    \ = 0;\n            low_val = -LM;\n            high_val = LM;\n        }\n  \
    \      void eval_calc(){\n            so = dat;\n            std::sort(so.begin(),so.end());\n\
    \            for(int i = 0;i < int(so.size());i++)wa[i + 1] = wa[i] + so[i];\n\
    \            min_val = LM;\n            max_val = -LM;\n            for(T &i :\
    \ dat){\n                if(min_val > i)min_val = i;\n                if(max_val\
    \ < i)max_val = i;\n            }\n        }\n        void update_part(int a,int\
    \ b,T add_val_,T low_val_,T high_val_){\n            eval_update();\n        \
    \    for(int i = a;i < b;i++)dat[i] = std::clamp(dat[i] + add_val_,low_val_,high_val_);\n\
    \            eval_calc();\n        }\n        void update_all(T add_val_,T low_val_,T\
    \ high_val_){\n            add_val += add_val_;\n            low_val = std::clamp(low_val\
    \ + add_val_,low_val_,high_val_);\n            high_val = std::clamp(high_val\
    \ + add_val_,low_val_,high_val_);\n        }\n        T sum_part(int a,int b){\n\
    \            T res = 0;\n            for(int i = a;i < b;i++)res += std::clamp(dat[i]\
    \ + add_val,low_val,high_val);\n            return res;\n        }\n        T\
    \ sum_all(){\n            int lb = std::lower_bound(so.begin(),so.end(),low_val\
    \ - add_val) - so.begin();\n            int ub = std::upper_bound(so.begin(),so.end(),high_val\
    \ - add_val) - so.begin();\n            return wa[ub] - wa[lb] + add_val * (ub\
    \ - lb) + high_val * (r - l - ub) + low_val * lb;\n        }\n        T min_part(int\
    \ a,int b){\n            T res = LM;\n            for(int i = a;i < b;i++)res\
    \ = std::min(res,std::clamp(dat[i] + add_val,low_val,high_val));\n           \
    \ return res;\n        }\n        T min_all(){\n            return std::clamp(min_val\
    \ + add_val,low_val,high_val);\n        }\n        T max_part(int a,int b){\n\
    \            T res = -LM;\n            for(int i = a;i < b;i++)res = std::max(res,std::clamp(dat[i]\
    \ + add_val,low_val,high_val));\n            return res;\n        }\n        T\
    \ max_all(){\n            return std::clamp(max_val + add_val,low_val,high_val);\n\
    \        }\n\n        void range_update(int a,int b,T x){\n            if(r <=\
    \ a || b <= l)return;\n            else if(a <= l && r <= b)update_all(0,x,x);\n\
    \            else update_part(std::max(a,l) - l,std::min(b,r) - l,0,x,x);\n  \
    \      }\n        void range_add(int a,int b,T x){\n            if(r <= a || b\
    \ <= l)return;\n            else if(a <= l && r <= b)update_all(x,-LM,LM);\n \
    \           else update_part(std::max(a,l) - l,std::min(b,r) - l,x,-LM,LM);\n\
    \        }\n        void range_chmin(int a,int b,T x){\n            if(r <= a\
    \ || b <= l)return;\n            else if(a <= l && r <= b)update_all(0,-LM,x);\n\
    \            else update_part(std::max(a,l) - l,std::min(b,r) - l,0,-LM,x);\n\
    \        }\n        void range_chmax(int a,int b,T x){\n            if(r <= a\
    \ || b <= l)return;\n            else if(a <= l && r <= b)update_all(0,x,LM);\n\
    \            else update_part(std::max(a,l) - l,std::min(b,r) - l,0,x,LM);\n \
    \       }\n        T range_min(int a,int b){\n            if(r <= a || b <= l)return\
    \ LM;\n            else if(a <= l && r <= b)return min_all();\n            else\
    \ return min_part(std::max(a,l) - l,std::min(b,r) - l);\n        }\n        T\
    \ range_max(int a,int b){\n            if(r <= a || b <= l)return -LM;\n     \
    \       else if(a <= l && r <= b)return max_all();\n            else return max_part(std::max(a,l)\
    \ - l,std::min(b,r) - l);\n        }\n        T range_sum(int a,int b){\n    \
    \        if(r <= a || b <= l)return 0;\n            else if(a <= l && r <= b)return\
    \ sum_all();\n            else return sum_part(std::max(a,l) - l,std::min(b,r)\
    \ - l);\n        }\n    };\n    sqrt_dec(const std::vector<T>& a,int bs,T LM_){init(a,bs,LM_);}\n\
    \    sqrt_dec(int n_,int bs,T LM_){init(std::vector<T>(n_,bs,LM_));}\n    void\
    \ range_update(int a,int b,T x){\n        for(auto &i : dat)i.range_update(a,b,x);\n\
    \    }\n    void range_chmin(int a,int b,T x){\n        for(auto &i : dat)i.range_chmin(a,b,x);\n\
    \    }\n    void range_chmax(int a,int b,T x){\n        for(auto &i : dat)i.range_chmax(a,b,x);\n\
    \    }\n    void range_add(int a,int b,T x){\n        for(auto &i : dat)i.range_add(a,b,x);\n\
    \    }\n    T range_min(int a,int b){\n        T res = LM;\n        for(auto &i\
    \ : dat)res = std::min(res,i.range_min(a,b));\n        return res;\n    }\n  \
    \  T range_max(int a,int b){\n        T res = -LM;\n        for(auto &i : dat)res\
    \ = std::max(res,i.range_max(a,b));\n        return res;\n    }\n    T range_sum(int\
    \ a,int b){\n        T res = 0;\n        for(auto &i : dat)res += i.range_sum(a,b);\n\
    \        return res;\n    }\n    T get(int a){\n        return range_min(a,a +\
    \ 1);\n    }\n    void deb(){\n        std::cerr << \"debug: [\";\n        for(int\
    \ i = 0;i < n;i++)std::cerr << range_min(i,i + 1) << (i == n - 1 ? \"]\\n\":\"\
    ,\");\n    }\n    \nprivate:\n    int n;\n    T LM;\n    std::vector<bucket> dat;\n\
    \    void init(const std::vector<T>& a,int bs,T LM_){\n        LM = LM_;\n   \
    \     n = a.size();\n        dat = std::vector<bucket>();\n        for(int i =\
    \ 0;i < int(a.size());i += bs)dat.push_back(bucket(a,i,std::min(int(i + bs),int(a.size())),LM));\n\
    \    }\n};\n\n\n#line 10 \"test/sqrt_decomposition.test.cpp\"\n\nvoid verify(int\
    \ n,int coeff = 100){\n    const long long INF = 10'000'000'000,e = 1LL << 60;\n\
    \    std::random_device rnd;\n    std::mt19937_64 mt(rnd());\n    std::uniform_int_distribution<long\
    \ long> uni(-INF,INF);\n    std::uniform_int_distribution<int> cmd(0,6),index(0,n\
    \ - 1);\n    std::vector<long long> naive(n);\n    int q = n * n * coeff;\n  \
    \  for(int i = 0;i < n;i++)naive[i] = uni(mt);\n    sqrt_dec<long long> S(naive,5,e);\n\
    \    while(q--){\n        int c = cmd(mt),l = index(mt),r = index(mt);\n     \
    \   if(l > r)std::swap(l,r);\n        r++;\n        long long x = uni(mt);\n \
    \       if(c == 0){\n            //range chmin\n            S.range_chmin(l,r,x);\n\
    \            \n            for(int i = l;i < r;i++)naive[i] = std::min(naive[i],x);\n\
    \        }\n        else if(c == 1){\n            //range chmax\n            S.range_chmax(l,r,x);\n\
    \            \n            for(int i = l;i < r;i++)naive[i] = std::max(naive[i],x);\n\
    \        }\n        else if(c == 2){\n            //range add\n            S.range_add(l,r,x);\n\
    \            \n            for(int i = l;i < r;i++)naive[i] += x;\n        }\n\
    \        else if(c == 3){\n            //range update\n            S.range_update(l,r,x);\n\
    \n            for(int i = l;i < r;i++)naive[i] = x;\n        }\n        else if(c\
    \ == 4){\n            //range min\n            long long ans = S.range_min(l,r);\n\
    \n            long long expected = e;\n            for(int i = l;i < r;i++)expected\
    \ = std::min(expected,naive[i]);\n            \n            if(ans != expected){\n\
    \                std::cerr << n << \"\\n\";\n                for(int i = 0;i <\
    \ n;i++)std::cerr << naive[i] << \" \";\n                std::cerr << \"\\n\"\
    ;\n                S.deb();\n                std::cerr << ans << \",\" << expected\
    \ << \"\\n\";\n            }\n            assert(ans == expected && \"range min\"\
    );\n        }\n        else if(c == 5){\n            //range max\n           \
    \ long long ans = S.range_max(l,r);\n\n            long long expected = -e;\n\
    \            for(int i = l;i < r;i++)expected = std::max(expected,naive[i]);\n\
    \            \n            if(ans != expected){\n                std::cerr <<\
    \ n << \"\\n\";\n                for(int i = 0;i < n;i++)std::cerr << naive[i]\
    \ << \" \";\n                std::cerr << \"\\n\";\n                S.deb();\n\
    \                std::cerr << ans << \",\" << expected << \"\\n\";\n         \
    \   }\n            assert(ans == expected && \"range max\");\n        }\n    \
    \    else if(c == 6){\n            //range sum\n            long long ans = S.range_sum(l,r);\n\
    \n            long long expected = 0;\n            for(int i = l;i < r;i++)expected\
    \ += naive[i];\n            \n            if(ans != expected){\n             \
    \   std::cerr << n << \"\\n\";\n                for(int i = 0;i < n;i++)std::cerr\
    \ << naive[i] << \" \";\n                std::cerr << \"\\n\";\n             \
    \   S.deb();\n                std::cerr << ans << \",\" << expected << \"\\n\"\
    ;\n            }\n            assert(ans == expected && \"range sum\");\n    \
    \    }\n        else assert(false);\n    }\n}\n\nint main(){\n    long long A,B;\n\
    \    std::cin >> A >> B;\n    std::cout << A + B << \"\\n\";\n\n    for(int i\
    \ = 0;i < 5;i++){\n        verify(1);\n        verify(2);\n        verify(63);\n\
    \        verify(64);\n        verify(65);\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <iostream>\n\
    #include <vector>\n#include <algorithm>\n#include <random>\n#include <assert.h>\n\
    \n#include \"../data-structure/sqrt_decomposition.hpp\"\n\nvoid verify(int n,int\
    \ coeff = 100){\n    const long long INF = 10'000'000'000,e = 1LL << 60;\n   \
    \ std::random_device rnd;\n    std::mt19937_64 mt(rnd());\n    std::uniform_int_distribution<long\
    \ long> uni(-INF,INF);\n    std::uniform_int_distribution<int> cmd(0,6),index(0,n\
    \ - 1);\n    std::vector<long long> naive(n);\n    int q = n * n * coeff;\n  \
    \  for(int i = 0;i < n;i++)naive[i] = uni(mt);\n    sqrt_dec<long long> S(naive,5,e);\n\
    \    while(q--){\n        int c = cmd(mt),l = index(mt),r = index(mt);\n     \
    \   if(l > r)std::swap(l,r);\n        r++;\n        long long x = uni(mt);\n \
    \       if(c == 0){\n            //range chmin\n            S.range_chmin(l,r,x);\n\
    \            \n            for(int i = l;i < r;i++)naive[i] = std::min(naive[i],x);\n\
    \        }\n        else if(c == 1){\n            //range chmax\n            S.range_chmax(l,r,x);\n\
    \            \n            for(int i = l;i < r;i++)naive[i] = std::max(naive[i],x);\n\
    \        }\n        else if(c == 2){\n            //range add\n            S.range_add(l,r,x);\n\
    \            \n            for(int i = l;i < r;i++)naive[i] += x;\n        }\n\
    \        else if(c == 3){\n            //range update\n            S.range_update(l,r,x);\n\
    \n            for(int i = l;i < r;i++)naive[i] = x;\n        }\n        else if(c\
    \ == 4){\n            //range min\n            long long ans = S.range_min(l,r);\n\
    \n            long long expected = e;\n            for(int i = l;i < r;i++)expected\
    \ = std::min(expected,naive[i]);\n            \n            if(ans != expected){\n\
    \                std::cerr << n << \"\\n\";\n                for(int i = 0;i <\
    \ n;i++)std::cerr << naive[i] << \" \";\n                std::cerr << \"\\n\"\
    ;\n                S.deb();\n                std::cerr << ans << \",\" << expected\
    \ << \"\\n\";\n            }\n            assert(ans == expected && \"range min\"\
    );\n        }\n        else if(c == 5){\n            //range max\n           \
    \ long long ans = S.range_max(l,r);\n\n            long long expected = -e;\n\
    \            for(int i = l;i < r;i++)expected = std::max(expected,naive[i]);\n\
    \            \n            if(ans != expected){\n                std::cerr <<\
    \ n << \"\\n\";\n                for(int i = 0;i < n;i++)std::cerr << naive[i]\
    \ << \" \";\n                std::cerr << \"\\n\";\n                S.deb();\n\
    \                std::cerr << ans << \",\" << expected << \"\\n\";\n         \
    \   }\n            assert(ans == expected && \"range max\");\n        }\n    \
    \    else if(c == 6){\n            //range sum\n            long long ans = S.range_sum(l,r);\n\
    \n            long long expected = 0;\n            for(int i = l;i < r;i++)expected\
    \ += naive[i];\n            \n            if(ans != expected){\n             \
    \   std::cerr << n << \"\\n\";\n                for(int i = 0;i < n;i++)std::cerr\
    \ << naive[i] << \" \";\n                std::cerr << \"\\n\";\n             \
    \   S.deb();\n                std::cerr << ans << \",\" << expected << \"\\n\"\
    ;\n            }\n            assert(ans == expected && \"range sum\");\n    \
    \    }\n        else assert(false);\n    }\n}\n\nint main(){\n    long long A,B;\n\
    \    std::cin >> A >> B;\n    std::cout << A + B << \"\\n\";\n\n    for(int i\
    \ = 0;i < 5;i++){\n        verify(1);\n        verify(2);\n        verify(63);\n\
    \        verify(64);\n        verify(65);\n    }\n}"
  dependsOn: [data-structure/sqrt_decomposition.hpp]
  isVerificationFile: true
  path: test/sqrt_decomposition.test.cpp
  requiredBy: []
  timestamp: '2021-03-21 14:58:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/sqrt_decomposition.test.cpp
layout: document
redirect_from: [/verify/test/sqrt_decomposition.test.cpp, /verify/test/sqrt_decomposition.test.cpp.html]
title: test/sqrt_decomposition.test.cpp
---
