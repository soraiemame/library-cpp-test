---
data:
  _extendedDependsOn:
  - {icon: ':heavy_check_mark:', path: math/bigint.hpp, title: math/bigint.hpp}
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_A
    links: ['https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_A']
  bundledCode: "#line 1 \"test/bigint/addition.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_A\"\
    \n\n#include <iostream>\n\n#line 1 \"math/bigint.hpp\"\n\n\n\n#include <vector>\n\
    #include <functional>\n#include <algorithm>\n#include <assert.h>\n#line 9 \"math/bigint.hpp\"\
    \n#include <string>\n\nnamespace bigint_convolution{\n    bool is_set = false;\n\
    \    std::function<std::vector<long long>(std::vector<long long>,std::vector<long\
    \ long>)> f;\n    void set(const std::function<std::vector<long long>(std::vector<long\
    \ long>,std::vector<long long>)>& _f){\n        is_set = true;\n        f = _f;\n\
    \    }\n    std::vector<long long> convolution(const std::vector<long long>& a,const\
    \ std::vector<long long>& b){\n        assert(is_set);\n        return f(a,b);\n\
    \    }\n    std::vector<long long> naive(const std::vector<long long>& a,const\
    \ std::vector<long long>& b){\n        int n = int(a.size()),m = int(b.size());\n\
    \        std::vector<long long> res(n + m - 1);\n        if(n < m)\n         \
    \   for(int j = 0;j < m;j++)for(int i = 0;i < n;i++)res[i + j] += a[i] * b[j];\n\
    \        else\n            for(int i = 0;i < n;i++)for(int j = 0;j < m;j++)res[i\
    \ + j] += a[i] * b[j];\n        return res;\n    };\n};\n\ntemplate<int d,int\
    \ base>\nstruct bigint{\n    using bint = bigint<d,base>;\n    bigint(const std::string&\
    \ _s){\n        sign = 1;\n        dat.clear();\n        if(_s.empty())return;\n\
    \        if(_s[0] == '-')sign = -1;\n        std::string s = sign == 1 ? _s :\
    \ _s.substr(1);\n        int i;\n        for(i = int(s.size()) - d;i >= 0;i -=\
    \ d){\n            assert('0' <= s[i] && s[i] <= '9');\n            dat.push_back(std::stoll(s.substr(i,d)));\n\
    \        }\n        if(i + d)dat.push_back(std::stoll(s.substr(0,i + d)));\n \
    \       while(!dat.empty() && dat.back() == 0)dat.pop_back();\n    }\n    bigint(long\
    \ long n = 0){\n        sign = 1;\n        dat.clear();\n        if(n < 0)sign\
    \ = -1,n = -n;\n        while(n){\n            dat.push_back(n % base);\n    \
    \        n /= base;\n        }\n    }\n    int size()const{return int(dat.size());}\n\
    \    int number_len()const{\n        if(size() == 0)return 0;\n        int res\
    \ = (int(dat.size()) - 1) * d;\n        int b = 1,p = 0;\n        while(b <= dat.back())p++,b\
    \ *= 10;\n        return res + p;\n    }\n    std::string to_string()const{\n\
    \        if(size() == 0)return \"0\";\n        std::string res = \"\";\n     \
    \   if(sign == -1)res = \"-\";\n        auto to_string_pad = [](long long m,int\
    \ _d){\n            std::string r = std::to_string(m);\n            std::string\
    \ ap(_d - int(r.size()),'0');\n            return ap + r;\n        };\n      \
    \  for(int i = size() - 1;i >= 0;i--){\n            if(i != size() - 1)res +=\
    \ to_string_pad(dat[i],d);\n            else res += std::to_string(dat[i]);\n\
    \        }\n        return res;\n    }\n    long long to_ll()const{\n        long\
    \ long res = 0;\n        for(int i = size() - 1;i >= 0;i--)res = res * base +\
    \ dat[i];\n        return sign * res;\n    }\n    void norm(){\n        if(dat.empty())return;\n\
    \        for(int i = 0;i < size() - 1;i++){\n            long long nex = dat[i]\
    \ / base;\n            if(nex * base > dat[i])nex--;\n            dat[i] -= nex\
    \ * base;\n            dat[i + 1] += nex;\n        }\n        while(dat.back()\
    \ >= base){\n            long long nex = dat.back() / base;\n            dat.back()\
    \ -= nex * base;\n            dat.push_back(nex);\n        }\n        while(!dat.empty()\
    \ && dat.back() == 0)dat.pop_back();\n    }\n\n    inline constexpr bool operator<(const\
    \ bint& a)const noexcept{\n        if(a.dat.empty())return false;\n        else\
    \ if(sign != a.sign)return sign < a.sign;\n        else if(sign == -1)return (-a)\
    \ < (-bint(*this));\n        else if(number_len() != a.number_len())return number_len()\
    \ < a.number_len();\n        else{\n            for(int i = size() - 1;i >= 0;i--)if(dat[i]\
    \ != a.dat[i])return dat[i] < a.dat[i];\n            return false;\n        }\n\
    \    }\n    inline constexpr bool operator>(const bint& a)const noexcept{return\
    \ a < bint(*this);}\n    inline constexpr bool operator<=(const bint& a)const\
    \ noexcept{return !(a < bint(*this));}\n    inline constexpr bool operator>=(const\
    \ bint& a)const noexcept{return !(bint(*this) < a);}\n    inline constexpr bool\
    \ operator==(const bint& a)const noexcept{return dat == a.dat;}\n    inline constexpr\
    \ bool operator!=(const bint& a)const noexcept{return dat != a.dat;}\n\n    inline\
    \ constexpr bint operator-()const noexcept{\n        bint res(*this);\n      \
    \  res.sign = -res.sign;\n        return res;\n    }\n    friend bint abs(const\
    \ bint& a){return a.sign == -1 ? -a : a;}\n\n    inline constexpr bint &operator+=(const\
    \ bint& a)noexcept{\n        if(sign != a.sign)return *this -= (-a);\n       \
    \ else{\n            if(size() < a.size())dat.resize(a.size());\n            for(int\
    \ i = 0;i < a.size();i++)dat[i] += a.dat[i];\n            norm();\n          \
    \  return *this;\n        }\n    }\n    inline constexpr bint &operator-=(const\
    \ bint& a)noexcept{\n        if(sign != a.sign)return *this += (-a);\n       \
    \ else if(abs(bint(*this)) < abs(a)){\n            *this = a - *this;sign = -sign;\n\
    \            return *this;\n        }\n        else{\n            for(int i =\
    \ 0;i < a.size();i++)dat[i] -= a.dat[i];\n            norm();\n            return\
    \ *this;\n        }\n    }\n\n    inline constexpr bint &operator++()noexcept{return\
    \ *this += bint(1);}\n    inline constexpr bint operator++(int)noexcept{operator++();return\
    \ bint(*this);}\n    inline constexpr bint &operator--()noexcept{return *this\
    \ -= bint(1);}\n    inline constexpr bint operator--(int)noexcept{operator--();return\
    \ bint(*this);}\n\n    inline constexpr bint &operator*=(const bint& a)noexcept{\n\
    \        assert(bigint_convolution::is_set);\n        if(size() == 0 || a.size()\
    \ == 0)return *this = bint(0);\n        if(std::min(size(),a.size()) <= 60)dat\
    \ = bigint_convolution::naive(dat,a.dat);\n        else dat = bigint_convolution::convolution(dat,a.dat);\n\
    \        norm();\n        sign *= a.sign;\n        return *this;\n    }\n    inline\
    \ constexpr bint mul2()const noexcept{\n        bint res(*this);\n        for(auto&\
    \ x : res.dat)x *= 2;\n        res.norm();\n        return res;\n    }\n    inline\
    \ constexpr bint div2()const noexcept{\n        bint res(*this);\n        int\
    \ nex = 0;\n        for(int i = res.size() - 1;i >= 0;i--){\n            long\
    \ long cur = (res.dat[i] + nex * base);\n            res.dat[i] = cur >> 1;\n\
    \            nex = cur & 1;\n        }\n        while(!res.dat.empty() && res.dat.back()\
    \ == 0)res.dat.pop_back();\n        return res;\n    }\n    inline constexpr int\
    \ rem2()const noexcept{\n        if(dat.empty())return 0;\n        else return\
    \ dat[0] & 1;\n    }\n    inline constexpr bint &operator>>=(int k)noexcept{\n\
    \        dat = std::vector<long long>(dat.begin() + std::min(k,int(size())),dat.end());\n\
    \        return *this;\n    }\n    inline constexpr bint &operator<<=(int k)noexcept{\n\
    \        if(!dat.empty()){\n            std::vector<long long> add(k,0);\n   \
    \         dat.insert(dat.begin(),add.begin(),add.end());\n        }\n        return\
    \ *this;\n    }\n\n    inline constexpr bint &operator/=(long long v)noexcept{\n\
    \        if(v < 0)sign = -sign,v = -v;\n        for(int i = size() - 1,rem = 0;i\
    \ >= 0;i--){\n            long long cur = dat[i] + rem * (long long)(base);\n\
    \            dat[i] = (long long)(cur / v);\n            rem = (long long)(cur\
    \ % v);\n        }\n        norm();\n        return *this;\n    }\n    friend\
    \ std::pair<bint,bint> divmod_naive(const bint& _a,const bint& _b){\n        bint\
    \ zero,s,t;\n        bint a = abs(_a),b = abs(_b);\n        if(a < b)return std::make_pair(zero,a);\n\
    \        bint ar = b;\n        s.dat.resize(a.size()),t.dat.resize(b.size());\n\
    \        int tx = a.size() - 1;\n        for(;tx >= 0;--tx)if(a.dat[tx] > 0)break;\n\
    \        for(int i = tx; i >= 0; --i){\n            t <<= 1;\n            t +=\
    \ a.dat[i];\n            long long lo = 0,hi = base;\n            if(t >= ar){\n\
    \                while(hi - lo > 1){\n                    int mid = (hi + lo)\
    \ / 2;\n                    if(ar * mid > t)hi = mid;\n                    else\
    \ lo = mid;\n                }\n                t -= ar * lo;\n            }\n\
    \            s.dat[i] = lo;\n        }\n        if(_a.sign == _b.sign)s.sign =\
    \ 1,t.sign = 1;\n        else s.sign = -1,t.sign = 1;\n        s.norm();t.norm();\n\
    \        return std::make_pair(s,t);\n    }\n    inline constexpr bint &operator/=(const\
    \ bint& a)noexcept{\n        if(size() - a.size() <= 10)return *this = divmod_naive(bint(*this),a).first;\n\
    \        else return *this = this->div_fast(a);\n    }\n    \n    inline constexpr\
    \ bint &operator%=(const bint& a)noexcept{\n        if(size() - a.size() <= 10)return\
    \ *this = divmod_naive(bint(*this),a).second;\n        else return *this = bint(*this)\
    \ - this->div_fast(a) * a;\n    }\n\n    inline constexpr bint operator+(const\
    \ bint& a)const noexcept{return bint(*this) += a;}\n    inline constexpr bint\
    \ operator-(const bint& a)const noexcept{return bint(*this) -= a;}\n    inline\
    \ constexpr bint operator*(const bint& a)const noexcept{return bint(*this) *=\
    \ a;}\n    inline constexpr bint operator>>(int k)const noexcept{return bint(*this)\
    \ >>= k;}\n    inline constexpr bint operator<<(int k)const noexcept{return bint(*this)\
    \ <<= k;}\n    inline constexpr bint operator/(long long v)const noexcept{return\
    \ bint(*this) /= v;}\n    inline constexpr bint operator/(const bint& a)const\
    \ noexcept{return bint(*this) /= a;}\n    inline constexpr bint operator%(const\
    \ bint& a)const noexcept{return bint(*this) %= a;}\n\n    friend std::ostream\
    \ &operator<<(std::ostream& os,const bint& a){return os << a.to_string();}\n \
    \   friend std::istream &operator>>(std::istream& is,bint& a){\n        std::string\
    \ s;\n        is >> s;\n        a = bint(s);\n        return is;\n    }\n\n  \
    \  explicit operator bool()const noexcept{return !dat.empty();}\n    explicit\
    \ operator int()const noexcept{return to_ll();}\n    using long_long = long long;\n\
    \    explicit operator long_long()const noexcept{return to_ll();}\n\nprivate:\n\
    \    int sign;\n    std::vector<long long> dat;\n    bint div_fast(const bint&\
    \ _a)const noexcept{\n        bint a = abs(*this),b = abs(_a);\n        if(a <\
    \ b)return bint();\n        int tar = a.size() - b.size() + 1,m = 1;\n       \
    \ while(b.dat.back() * m * 10 < base)m *= 10;\n        bint inv(m * base),pre(0);\n\
    \        const bint two(2);\n        while(inv != pre){\n            pre = inv;\n\
    \            inv *= (two << 2) - inv * b.dat.back();\n            inv >>= 2;\n\
    \        }\n        int cur = 2,bcur = 1;\n        pre = bint(0);\n        while(inv\
    \ != pre){\n            bint c;\n            c.dat = std::vector<long long>(b.dat.end()\
    \ - bcur,b.dat.end());\n            pre = inv;\n            inv *= (two << (cur\
    \ + bcur - 1)) - inv * c;\n            int nex = std::min(cur << 1,tar);\n   \
    \         inv.dat = std::vector<long long>(inv.dat.end() - nex,inv.dat.end());\n\
    \            cur = nex;\n            bcur = std::min(bcur << 1,b.size());\n  \
    \      }\n        inv.dat = std::vector<long long>(inv.dat.end() - tar,inv.dat.end());\n\
    \        bint res = a * inv;res.dat = std::vector<long long>(res.dat.begin() +\
    \ a.size(),res.dat.end());\n        bint mul = res * b;\n        while(mul + b\
    \ <= a){\n            res++;\n            mul += b;\n        }\n        res.sign\
    \ = sign * _a.sign;\n        return res;\n    }\n};\nusing bint = bigint<4,10000>;\n\
    \n\n#line 6 \"test/bigint/addition.test.cpp\"\n\nint main(){\n    bint a,b;\n\
    \    std::cin >> a >> b;\n    std::cout << a + b << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_A\"\
    \n\n#include <iostream>\n\n#include \"../../math/bigint.hpp\"\n\nint main(){\n\
    \    bint a,b;\n    std::cin >> a >> b;\n    std::cout << a + b << \"\\n\";\n}"
  dependsOn: [math/bigint.hpp]
  isVerificationFile: true
  path: test/bigint/addition.test.cpp
  requiredBy: []
  timestamp: '2021-03-24 19:21:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/bigint/addition.test.cpp
layout: document
redirect_from: [/verify/test/bigint/addition.test.cpp, /verify/test/bigint/addition.test.cpp.html]
title: test/bigint/addition.test.cpp
---
