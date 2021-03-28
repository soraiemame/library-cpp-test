---
data:
  _extendedDependsOn:
  - {icon: ':heavy_check_mark:', path: atcoder/convolution.hpp, title: atcoder/convolution.hpp}
  - {icon: ':heavy_check_mark:', path: atcoder/internal_bit.hpp, title: atcoder/internal_bit.hpp}
  - {icon: ':heavy_check_mark:', path: atcoder/internal_math.hpp, title: atcoder/internal_math.hpp}
  - {icon: ':heavy_check_mark:', path: atcoder/internal_type_traits.hpp, title: atcoder/internal_type_traits.hpp}
  - {icon: ':heavy_check_mark:', path: atcoder/modint.hpp, title: atcoder/modint.hpp}
  - {icon: ':heavy_check_mark:', path: math/bigint.hpp, title: math/bigint.hpp}
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_C
    links: ['https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_C']
  bundledCode: "#line 1 \"test/bigint/multipication.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_C\"\n\n#include\
    \ <iostream>\n\n#line 1 \"math/bigint.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <functional>\n#include <algorithm>\n#include <assert.h>\n#line 9 \"math/bigint.hpp\"\
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
    \n\n#line 1 \"atcoder/convolution.hpp\"\n\n\n\n#line 5 \"atcoder/convolution.hpp\"\
    \n#include <array>\n#include <cassert>\n#include <type_traits>\n#line 9 \"atcoder/convolution.hpp\"\
    \n\n#line 1 \"atcoder/internal_bit.hpp\"\n\n\n\n#ifdef _MSC_VER\n#include <intrin.h>\n\
    #endif\n\nnamespace atcoder {\n\nnamespace internal {\n\n// @param n `0 <= n`\n\
    // @return minimum non-negative `x` s.t. `n <= 2**x`\nint ceil_pow2(int n) {\n\
    \    int x = 0;\n    while ((1U << x) < (unsigned int)(n)) x++;\n    return x;\n\
    }\n\n// @param n `1 <= n`\n// @return minimum non-negative `x` s.t. `(n & (1 <<\
    \ x)) != 0`\nint bsf(unsigned int n) {\n#ifdef _MSC_VER\n    unsigned long index;\n\
    \    _BitScanForward(&index, n);\n    return index;\n#else\n    return __builtin_ctz(n);\n\
    #endif\n}\n\n}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 1\
    \ \"atcoder/modint.hpp\"\n\n\n\n#line 5 \"atcoder/modint.hpp\"\n#include <numeric>\n\
    #line 7 \"atcoder/modint.hpp\"\n\n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\
    \n#line 1 \"atcoder/internal_math.hpp\"\n\n\n\n#include <utility>\n\n#ifdef _MSC_VER\n\
    #include <intrin.h>\n#endif\n\nnamespace atcoder {\n\nnamespace internal {\n\n\
    // @param m `1 <= m`\n// @return x mod m\nconstexpr long long safe_mod(long long\
    \ x, long long m) {\n    x %= m;\n    if (x < 0) x += m;\n    return x;\n}\n\n\
    // Fast modular multiplication by barrett reduction\n// Reference: https://en.wikipedia.org/wiki/Barrett_reduction\n\
    // NOTE: reconsider after Ice Lake\nstruct barrett {\n    unsigned int _m;\n \
    \   unsigned long long im;\n\n    // @param m `1 <= m < 2^31`\n    explicit barrett(unsigned\
    \ int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}\n\n    // @return m\n\
    \    unsigned int umod() const { return _m; }\n\n    // @param a `0 <= a < m`\n\
    \    // @param b `0 <= b < m`\n    // @return `a * b % m`\n    unsigned int mul(unsigned\
    \ int a, unsigned int b) const {\n        // [1] m = 1\n        // a = b = im\
    \ = 0, so okay\n\n        // [2] m >= 2\n        // im = ceil(2^64 / m)\n    \
    \    // -> im * m = 2^64 + r (0 <= r < m)\n        // let z = a*b = c*m + d (0\
    \ <= c, d < m)\n        // a*b * im = (c*m + d) * im = c*(im*m) + d*im = c*2^64\
    \ + c*r + d*im\n        // c*r + d*im < m * m + m * im < m * m + 2^64 + m <= 2^64\
    \ + m * (m + 1) < 2^64 * 2\n        // ((ab * im) >> 64) == c or c + 1\n     \
    \   unsigned long long z = a;\n        z *= b;\n#ifdef _MSC_VER\n        unsigned\
    \ long long x;\n        _umul128(z, im, &x);\n#else\n        unsigned long long\
    \ x =\n            (unsigned long long)(((unsigned __int128)(z)*im) >> 64);\n\
    #endif\n        unsigned int v = (unsigned int)(z - x * _m);\n        if (_m <=\
    \ v) v += _m;\n        return v;\n    }\n};\n\n// @param n `0 <= n`\n// @param\
    \ m `1 <= m`\n// @return `(x ** n) % m`\nconstexpr long long pow_mod_constexpr(long\
    \ long x, long long n, int m) {\n    if (m == 1) return 0;\n    unsigned int _m\
    \ = (unsigned int)(m);\n    unsigned long long r = 1;\n    unsigned long long\
    \ y = safe_mod(x, m);\n    while (n) {\n        if (n & 1) r = (r * y) % _m;\n\
    \        y = (y * y) % _m;\n        n >>= 1;\n    }\n    return r;\n}\n\n// Reference:\n\
    // M. Forisek and J. Jancina,\n// Fast Primality Testing for Integers That Fit\
    \ into a Machine Word\n// @param n `0 <= n`\nconstexpr bool is_prime_constexpr(int\
    \ n) {\n    if (n <= 1) return false;\n    if (n == 2 || n == 7 || n == 61) return\
    \ true;\n    if (n % 2 == 0) return false;\n    long long d = n - 1;\n    while\
    \ (d % 2 == 0) d /= 2;\n    constexpr long long bases[3] = {2, 7, 61};\n    for\
    \ (long long a : bases) {\n        long long t = d;\n        long long y = pow_mod_constexpr(a,\
    \ t, n);\n        while (t != n - 1 && y != 1 && y != n - 1) {\n            y\
    \ = y * y % n;\n            t <<= 1;\n        }\n        if (y != n - 1 && t %\
    \ 2 == 0) {\n            return false;\n        }\n    }\n    return true;\n}\n\
    template <int n> constexpr bool is_prime = is_prime_constexpr(n);\n\n// @param\
    \ b `1 <= b`\n// @return pair(g, x) s.t. g = gcd(a, b), xa = g (mod b), 0 <= x\
    \ < b/g\nconstexpr std::pair<long long, long long> inv_gcd(long long a, long long\
    \ b) {\n    a = safe_mod(a, b);\n    if (a == 0) return {b, 0};\n\n    // Contracts:\n\
    \    // [1] s - m0 * a = 0 (mod b)\n    // [2] t - m1 * a = 0 (mod b)\n    //\
    \ [3] s * |m1| + t * |m0| <= b\n    long long s = b, t = a;\n    long long m0\
    \ = 0, m1 = 1;\n\n    while (t) {\n        long long u = s / t;\n        s -=\
    \ t * u;\n        m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b\n\n        // [3]:\n\
    \        // (s - t * u) * |m1| + t * |m0 - m1 * u|\n        // <= s * |m1| - t\
    \ * u * |m1| + t * (|m0| + |m1| * u)\n        // = s * |m1| + t * |m0| <= b\n\n\
    \        auto tmp = s;\n        s = t;\n        t = tmp;\n        tmp = m0;\n\
    \        m0 = m1;\n        m1 = tmp;\n    }\n    // by [3]: |m0| <= b/g\n    //\
    \ by g != b: |m0| < b/g\n    if (m0 < 0) m0 += b / s;\n    return {s, m0};\n}\n\
    \n// Compile time primitive root\n// @param m must be prime\n// @return primitive\
    \ root (and minimum in now)\nconstexpr int primitive_root_constexpr(int m) {\n\
    \    if (m == 2) return 1;\n    if (m == 167772161) return 3;\n    if (m == 469762049)\
    \ return 3;\n    if (m == 754974721) return 11;\n    if (m == 998244353) return\
    \ 3;\n    int divs[20] = {};\n    divs[0] = 2;\n    int cnt = 1;\n    int x =\
    \ (m - 1) / 2;\n    while (x % 2 == 0) x /= 2;\n    for (int i = 3; (long long)(i)*i\
    \ <= x; i += 2) {\n        if (x % i == 0) {\n            divs[cnt++] = i;\n \
    \           while (x % i == 0) {\n                x /= i;\n            }\n   \
    \     }\n    }\n    if (x > 1) {\n        divs[cnt++] = x;\n    }\n    for (int\
    \ g = 2;; g++) {\n        bool ok = true;\n        for (int i = 0; i < cnt; i++)\
    \ {\n            if (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {\n    \
    \            ok = false;\n                break;\n            }\n        }\n \
    \       if (ok) return g;\n    }\n}\ntemplate <int m> constexpr int primitive_root\
    \ = primitive_root_constexpr(m);\n\n// @param n `n < 2^32`\n// @param m `1 <=\
    \ m < 2^32`\n// @return sum_{i=0}^{n-1} floor((ai + b) / m) (mod 2^64)\nunsigned\
    \ long long floor_sum_unsigned(unsigned long long n,\n                       \
    \               unsigned long long m,\n                                      unsigned\
    \ long long a,\n                                      unsigned long long b) {\n\
    \    unsigned long long ans = 0;\n    while (true) {\n        if (a >= m) {\n\
    \            ans += n * (n - 1) / 2 * (a / m);\n            a %= m;\n        }\n\
    \        if (b >= m) {\n            ans += n * (b / m);\n            b %= m;\n\
    \        }\n\n        unsigned long long y_max = a * n + b;\n        if (y_max\
    \ < m) break;\n        // y_max < m * (n + 1)\n        // floor(y_max / m) <=\
    \ n\n        n = (unsigned long long)(y_max / m);\n        b = (unsigned long\
    \ long)(y_max % m);\n        std::swap(m, a);\n    }\n    return ans;\n}\n\n}\
    \  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 1 \"atcoder/internal_type_traits.hpp\"\
    \n\n\n\n#line 7 \"atcoder/internal_type_traits.hpp\"\n\nnamespace atcoder {\n\n\
    namespace internal {\n\n#ifndef _MSC_VER\ntemplate <class T>\nusing is_signed_int128\
    \ =\n    typename std::conditional<std::is_same<T, __int128_t>::value ||\n   \
    \                               std::is_same<T, __int128>::value,\n          \
    \                    std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing is_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __uint128_t>::value ||\n                                  std::is_same<T, unsigned\
    \ __int128>::value,\n                              std::true_type,\n         \
    \                     std::false_type>::type;\n\ntemplate <class T>\nusing make_unsigned_int128\
    \ =\n    typename std::conditional<std::is_same<T, __int128_t>::value,\n     \
    \                         __uint128_t,\n                              unsigned\
    \ __int128>;\n\ntemplate <class T>\nusing is_integral = typename std::conditional<std::is_integral<T>::value\
    \ ||\n                                                  is_signed_int128<T>::value\
    \ ||\n                                                  is_unsigned_int128<T>::value,\n\
    \                                              std::true_type,\n             \
    \                                 std::false_type>::type;\n\ntemplate <class T>\n\
    using is_signed_int = typename std::conditional<(is_integral<T>::value &&\n  \
    \                                               std::is_signed<T>::value) ||\n\
    \                                                    is_signed_int128<T>::value,\n\
    \                                                std::true_type,\n           \
    \                                     std::false_type>::type;\n\ntemplate <class\
    \ T>\nusing is_unsigned_int =\n    typename std::conditional<(is_integral<T>::value\
    \ &&\n                               std::is_unsigned<T>::value) ||\n        \
    \                          is_unsigned_int128<T>::value,\n                   \
    \           std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing to_unsigned = typename std::conditional<\n    is_signed_int128<T>::value,\n\
    \    make_unsigned_int128<T>,\n    typename std::conditional<std::is_signed<T>::value,\n\
    \                              std::make_unsigned<T>,\n                      \
    \        std::common_type<T>>::type>::type;\n\n#else\n\ntemplate <class T> using\
    \ is_integral = typename std::is_integral<T>;\n\ntemplate <class T>\nusing is_signed_int\
    \ =\n    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <class T>\nusing is_unsigned_int =\n   \
    \ typename std::conditional<is_integral<T>::value &&\n                       \
    \           std::is_unsigned<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <class T>\n\
    using to_unsigned = typename std::conditional<is_signed_int<T>::value,\n     \
    \                                         std::make_unsigned<T>,\n           \
    \                                   std::common_type<T>>::type;\n\n#endif\n\n\
    template <class T>\nusing is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;\n\
    \ntemplate <class T>\nusing is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;\n\
    \ntemplate <class T> using to_unsigned_t = typename to_unsigned<T>::type;\n\n\
    }  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 14 \"atcoder/modint.hpp\"\
    \n\nnamespace atcoder {\n\nnamespace internal {\n\nstruct modint_base {};\nstruct\
    \ static_modint_base : modint_base {};\n\ntemplate <class T> using is_modint =\
    \ std::is_base_of<modint_base, T>;\ntemplate <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\
    \n}  // namespace internal\n\ntemplate <int m, std::enable_if_t<(1 <= m)>* = nullptr>\n\
    struct static_modint : internal::static_modint_base {\n    using mint = static_modint;\n\
    \n  public:\n    static constexpr int mod() { return m; }\n    static mint raw(int\
    \ v) {\n        mint x;\n        x._v = v;\n        return x;\n    }\n\n    static_modint()\
    \ : _v(0) {}\n    template <class T, internal::is_signed_int_t<T>* = nullptr>\n\
    \    static_modint(T v) {\n        long long x = (long long)(v % (long long)(umod()));\n\
    \        if (x < 0) x += umod();\n        _v = (unsigned int)(x);\n    }\n   \
    \ template <class T, internal::is_unsigned_int_t<T>* = nullptr>\n    static_modint(T\
    \ v) {\n        _v = (unsigned int)(v % umod());\n    }\n\n    unsigned int val()\
    \ const { return _v; }\n\n    mint& operator++() {\n        _v++;\n        if\
    \ (_v == umod()) _v = 0;\n        return *this;\n    }\n    mint& operator--()\
    \ {\n        if (_v == 0) _v = umod();\n        _v--;\n        return *this;\n\
    \    }\n    mint operator++(int) {\n        mint result = *this;\n        ++*this;\n\
    \        return result;\n    }\n    mint operator--(int) {\n        mint result\
    \ = *this;\n        --*this;\n        return result;\n    }\n\n    mint& operator+=(const\
    \ mint& rhs) {\n        _v += rhs._v;\n        if (_v >= umod()) _v -= umod();\n\
    \        return *this;\n    }\n    mint& operator-=(const mint& rhs) {\n     \
    \   _v -= rhs._v;\n        if (_v >= umod()) _v += umod();\n        return *this;\n\
    \    }\n    mint& operator*=(const mint& rhs) {\n        unsigned long long z\
    \ = _v;\n        z *= rhs._v;\n        _v = (unsigned int)(z % umod());\n    \
    \    return *this;\n    }\n    mint& operator/=(const mint& rhs) { return *this\
    \ = *this * rhs.inv(); }\n\n    mint operator+() const { return *this; }\n   \
    \ mint operator-() const { return mint() - *this; }\n\n    mint pow(long long\
    \ n) const {\n        assert(0 <= n);\n        mint x = *this, r = 1;\n      \
    \  while (n) {\n            if (n & 1) r *= x;\n            x *= x;\n        \
    \    n >>= 1;\n        }\n        return r;\n    }\n    mint inv() const {\n \
    \       if (prime) {\n            assert(_v);\n            return pow(umod() -\
    \ 2);\n        } else {\n            auto eg = internal::inv_gcd(_v, m);\n   \
    \         assert(eg.first == 1);\n            return eg.second;\n        }\n \
    \   }\n\n    friend mint operator+(const mint& lhs, const mint& rhs) {\n     \
    \   return mint(lhs) += rhs;\n    }\n    friend mint operator-(const mint& lhs,\
    \ const mint& rhs) {\n        return mint(lhs) -= rhs;\n    }\n    friend mint\
    \ operator*(const mint& lhs, const mint& rhs) {\n        return mint(lhs) *= rhs;\n\
    \    }\n    friend mint operator/(const mint& lhs, const mint& rhs) {\n      \
    \  return mint(lhs) /= rhs;\n    }\n    friend bool operator==(const mint& lhs,\
    \ const mint& rhs) {\n        return lhs._v == rhs._v;\n    }\n    friend bool\
    \ operator!=(const mint& lhs, const mint& rhs) {\n        return lhs._v != rhs._v;\n\
    \    }\n\n  private:\n    unsigned int _v;\n    static constexpr unsigned int\
    \ umod() { return m; }\n    static constexpr bool prime = internal::is_prime<m>;\n\
    };\n\ntemplate <int id> struct dynamic_modint : internal::modint_base {\n    using\
    \ mint = dynamic_modint;\n\n  public:\n    static int mod() { return (int)(bt.umod());\
    \ }\n    static void set_mod(int m) {\n        assert(1 <= m);\n        bt = internal::barrett(m);\n\
    \    }\n    static mint raw(int v) {\n        mint x;\n        x._v = v;\n   \
    \     return x;\n    }\n\n    dynamic_modint() : _v(0) {}\n    template <class\
    \ T, internal::is_signed_int_t<T>* = nullptr>\n    dynamic_modint(T v) {\n   \
    \     long long x = (long long)(v % (long long)(mod()));\n        if (x < 0) x\
    \ += mod();\n        _v = (unsigned int)(x);\n    }\n    template <class T, internal::is_unsigned_int_t<T>*\
    \ = nullptr>\n    dynamic_modint(T v) {\n        _v = (unsigned int)(v % mod());\n\
    \    }\n\n    unsigned int val() const { return _v; }\n\n    mint& operator++()\
    \ {\n        _v++;\n        if (_v == umod()) _v = 0;\n        return *this;\n\
    \    }\n    mint& operator--() {\n        if (_v == 0) _v = umod();\n        _v--;\n\
    \        return *this;\n    }\n    mint operator++(int) {\n        mint result\
    \ = *this;\n        ++*this;\n        return result;\n    }\n    mint operator--(int)\
    \ {\n        mint result = *this;\n        --*this;\n        return result;\n\
    \    }\n\n    mint& operator+=(const mint& rhs) {\n        _v += rhs._v;\n   \
    \     if (_v >= umod()) _v -= umod();\n        return *this;\n    }\n    mint&\
    \ operator-=(const mint& rhs) {\n        _v += mod() - rhs._v;\n        if (_v\
    \ >= umod()) _v -= umod();\n        return *this;\n    }\n    mint& operator*=(const\
    \ mint& rhs) {\n        _v = bt.mul(_v, rhs._v);\n        return *this;\n    }\n\
    \    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }\n\
    \n    mint operator+() const { return *this; }\n    mint operator-() const { return\
    \ mint() - *this; }\n\n    mint pow(long long n) const {\n        assert(0 <=\
    \ n);\n        mint x = *this, r = 1;\n        while (n) {\n            if (n\
    \ & 1) r *= x;\n            x *= x;\n            n >>= 1;\n        }\n       \
    \ return r;\n    }\n    mint inv() const {\n        auto eg = internal::inv_gcd(_v,\
    \ mod());\n        assert(eg.first == 1);\n        return eg.second;\n    }\n\n\
    \    friend mint operator+(const mint& lhs, const mint& rhs) {\n        return\
    \ mint(lhs) += rhs;\n    }\n    friend mint operator-(const mint& lhs, const mint&\
    \ rhs) {\n        return mint(lhs) -= rhs;\n    }\n    friend mint operator*(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) *= rhs;\n    }\n   \
    \ friend mint operator/(const mint& lhs, const mint& rhs) {\n        return mint(lhs)\
    \ /= rhs;\n    }\n    friend bool operator==(const mint& lhs, const mint& rhs)\
    \ {\n        return lhs._v == rhs._v;\n    }\n    friend bool operator!=(const\
    \ mint& lhs, const mint& rhs) {\n        return lhs._v != rhs._v;\n    }\n\n \
    \ private:\n    unsigned int _v;\n    static internal::barrett bt;\n    static\
    \ unsigned int umod() { return bt.umod(); }\n};\ntemplate <int id> internal::barrett\
    \ dynamic_modint<id>::bt(998244353);\n\nusing modint998244353 = static_modint<998244353>;\n\
    using modint1000000007 = static_modint<1000000007>;\nusing modint = dynamic_modint<-1>;\n\
    \nnamespace internal {\n\ntemplate <class T>\nusing is_static_modint = std::is_base_of<internal::static_modint_base,\
    \ T>;\n\ntemplate <class T>\nusing is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;\n\
    \ntemplate <class> struct is_dynamic_modint : public std::false_type {};\ntemplate\
    \ <int id>\nstruct is_dynamic_modint<dynamic_modint<id>> : public std::true_type\
    \ {};\n\ntemplate <class T>\nusing is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;\n\
    \n}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 12 \"atcoder/convolution.hpp\"\
    \n\nnamespace atcoder {\n\nnamespace internal {\n\ntemplate <class mint, internal::is_static_modint_t<mint>*\
    \ = nullptr>\nvoid butterfly(std::vector<mint>& a) {\n    static constexpr int\
    \ g = internal::primitive_root<mint::mod()>;\n    int n = int(a.size());\n   \
    \ int h = internal::ceil_pow2(n);\n\n    static bool first = true;\n    static\
    \ mint sum_e[30];  // sum_e[i] = ies[0] * ... * ies[i - 1] * es[i]\n    if (first)\
    \ {\n        first = false;\n        mint es[30], ies[30];  // es[i]^(2^(2+i))\
    \ == 1\n        int cnt2 = bsf(mint::mod() - 1);\n        mint e = mint(g).pow((mint::mod()\
    \ - 1) >> cnt2), ie = e.inv();\n        for (int i = cnt2; i >= 2; i--) {\n  \
    \          // e^(2^i) == 1\n            es[i - 2] = e;\n            ies[i - 2]\
    \ = ie;\n            e *= e;\n            ie *= ie;\n        }\n        mint now\
    \ = 1;\n        for (int i = 0; i <= cnt2 - 2; i++) {\n            sum_e[i] =\
    \ es[i] * now;\n            now *= ies[i];\n        }\n    }\n    for (int ph\
    \ = 1; ph <= h; ph++) {\n        int w = 1 << (ph - 1), p = 1 << (h - ph);\n \
    \       mint now = 1;\n        for (int s = 0; s < w; s++) {\n            int\
    \ offset = s << (h - ph + 1);\n            for (int i = 0; i < p; i++) {\n   \
    \             auto l = a[i + offset];\n                auto r = a[i + offset +\
    \ p] * now;\n                a[i + offset] = l + r;\n                a[i + offset\
    \ + p] = l - r;\n            }\n            now *= sum_e[bsf(~(unsigned int)(s))];\n\
    \        }\n    }\n}\n\ntemplate <class mint, internal::is_static_modint_t<mint>*\
    \ = nullptr>\nvoid butterfly_inv(std::vector<mint>& a) {\n    static constexpr\
    \ int g = internal::primitive_root<mint::mod()>;\n    int n = int(a.size());\n\
    \    int h = internal::ceil_pow2(n);\n\n    static bool first = true;\n    static\
    \ mint sum_ie[30];  // sum_ie[i] = es[0] * ... * es[i - 1] * ies[i]\n    if (first)\
    \ {\n        first = false;\n        mint es[30], ies[30];  // es[i]^(2^(2+i))\
    \ == 1\n        int cnt2 = bsf(mint::mod() - 1);\n        mint e = mint(g).pow((mint::mod()\
    \ - 1) >> cnt2), ie = e.inv();\n        for (int i = cnt2; i >= 2; i--) {\n  \
    \          // e^(2^i) == 1\n            es[i - 2] = e;\n            ies[i - 2]\
    \ = ie;\n            e *= e;\n            ie *= ie;\n        }\n        mint now\
    \ = 1;\n        for (int i = 0; i <= cnt2 - 2; i++) {\n            sum_ie[i] =\
    \ ies[i] * now;\n            now *= es[i];\n        }\n    }\n\n    for (int ph\
    \ = h; ph >= 1; ph--) {\n        int w = 1 << (ph - 1), p = 1 << (h - ph);\n \
    \       mint inow = 1;\n        for (int s = 0; s < w; s++) {\n            int\
    \ offset = s << (h - ph + 1);\n            for (int i = 0; i < p; i++) {\n   \
    \             auto l = a[i + offset];\n                auto r = a[i + offset +\
    \ p];\n                a[i + offset] = l + r;\n                a[i + offset +\
    \ p] =\n                    (unsigned long long)(mint::mod() + l.val() - r.val())\
    \ *\n                    inow.val();\n            }\n            inow *= sum_ie[bsf(~(unsigned\
    \ int)(s))];\n        }\n    }\n}\n\ntemplate <class mint, internal::is_static_modint_t<mint>*\
    \ = nullptr>\nstd::vector<mint> convolution_naive(const std::vector<mint>& a,\
    \ const std::vector<mint>& b) {\n    int n = int(a.size()), m = int(b.size());\n\
    \    std::vector<mint> ans(n + m - 1);\n    if (n < m) {\n        for (int j =\
    \ 0; j < m; j++) {\n            for (int i = 0; i < n; i++) {\n              \
    \  ans[i + j] += a[i] * b[j];\n            }\n        }\n    } else {\n      \
    \  for (int i = 0; i < n; i++) {\n            for (int j = 0; j < m; j++) {\n\
    \                ans[i + j] += a[i] * b[j];\n            }\n        }\n    }\n\
    \    return ans;\n}\n\ntemplate <class mint, internal::is_static_modint_t<mint>*\
    \ = nullptr>\nstd::vector<mint> convolution_fft(std::vector<mint> a, std::vector<mint>\
    \ b) {\n    int n = int(a.size()), m = int(b.size());\n    int z = 1 << internal::ceil_pow2(n\
    \ + m - 1);\n    a.resize(z);\n    internal::butterfly(a);\n    b.resize(z);\n\
    \    internal::butterfly(b);\n    for (int i = 0; i < z; i++) {\n        a[i]\
    \ *= b[i];\n    }\n    internal::butterfly_inv(a);\n    a.resize(n + m - 1);\n\
    \    mint iz = mint(z).inv();\n    for (int i = 0; i < n + m - 1; i++) a[i] *=\
    \ iz;\n    return std::move(a);\n}\n\n}  // namespace internal\n\ntemplate <class\
    \ mint, internal::is_static_modint_t<mint>* = nullptr>\nstd::vector<mint> convolution(std::vector<mint>&&\
    \ a, std::vector<mint>&& b) {\n    int n = int(a.size()), m = int(b.size());\n\
    \    if (!n || !m) return {};\n    if (std::min(n, m) <= 60) return convolution_naive(a,\
    \ b);\n    return internal::convolution_fft(a, b);\n}\n\ntemplate <class mint,\
    \ internal::is_static_modint_t<mint>* = nullptr>\nstd::vector<mint> convolution(const\
    \ std::vector<mint>& a, const std::vector<mint>& b) {\n    int n = int(a.size()),\
    \ m = int(b.size());\n    if (!n || !m) return {};\n    if (std::min(n, m) <=\
    \ 60) return convolution_naive(a, b);\n    return internal::convolution_fft(a,\
    \ b);\n}\n\ntemplate <unsigned int mod = 998244353,\n          class T,\n    \
    \      std::enable_if_t<internal::is_integral<T>::value>* = nullptr>\nstd::vector<T>\
    \ convolution(const std::vector<T>& a, const std::vector<T>& b) {\n    int n =\
    \ int(a.size()), m = int(b.size());\n    if (!n || !m) return {};\n\n    using\
    \ mint = static_modint<mod>;\n    std::vector<mint> a2(n), b2(m);\n    for (int\
    \ i = 0; i < n; i++) {\n        a2[i] = mint(a[i]);\n    }\n    for (int i = 0;\
    \ i < m; i++) {\n        b2[i] = mint(b[i]);\n    }\n    auto c2 = convolution(move(a2),\
    \ move(b2));\n    std::vector<T> c(n + m - 1);\n    for (int i = 0; i < n + m\
    \ - 1; i++) {\n        c[i] = c2[i].val();\n    }\n    return c;\n}\n\nstd::vector<long\
    \ long> convolution_ll(const std::vector<long long>& a,\n                    \
    \                  const std::vector<long long>& b) {\n    int n = int(a.size()),\
    \ m = int(b.size());\n    if (!n || !m) return {};\n\n    static constexpr unsigned\
    \ long long MOD1 = 754974721;  // 2^24\n    static constexpr unsigned long long\
    \ MOD2 = 167772161;  // 2^25\n    static constexpr unsigned long long MOD3 = 469762049;\
    \  // 2^26\n    static constexpr unsigned long long M2M3 = MOD2 * MOD3;\n    static\
    \ constexpr unsigned long long M1M3 = MOD1 * MOD3;\n    static constexpr unsigned\
    \ long long M1M2 = MOD1 * MOD2;\n    static constexpr unsigned long long M1M2M3\
    \ = MOD1 * MOD2 * MOD3;\n\n    static constexpr unsigned long long i1 =\n    \
    \    internal::inv_gcd(MOD2 * MOD3, MOD1).second;\n    static constexpr unsigned\
    \ long long i2 =\n        internal::inv_gcd(MOD1 * MOD3, MOD2).second;\n    static\
    \ constexpr unsigned long long i3 =\n        internal::inv_gcd(MOD1 * MOD2, MOD3).second;\n\
    \n    auto c1 = convolution<MOD1>(a, b);\n    auto c2 = convolution<MOD2>(a, b);\n\
    \    auto c3 = convolution<MOD3>(a, b);\n\n    std::vector<long long> c(n + m\
    \ - 1);\n    for (int i = 0; i < n + m - 1; i++) {\n        unsigned long long\
    \ x = 0;\n        x += (c1[i] * i1) % MOD1 * M2M3;\n        x += (c2[i] * i2)\
    \ % MOD2 * M1M3;\n        x += (c3[i] * i3) % MOD3 * M1M2;\n        // B = 2^63,\
    \ -B <= x, r(real value) < B\n        // (x, x - M, x - 2M, or x - 3M) = r (mod\
    \ 2B)\n        // r = c1[i] (mod MOD1)\n        // focus on MOD1\n        // r\
    \ = x, x - M', x - 2M', x - 3M' (M' = M % 2^64) (mod 2B)\n        // r = x,\n\
    \        //     x - M' + (0 or 2B),\n        //     x - 2M' + (0, 2B or 4B),\n\
    \        //     x - 3M' + (0, 2B, 4B or 6B) (without mod!)\n        // (r - x)\
    \ = 0, (0)\n        //           - M' + (0 or 2B), (1)\n        //           -2M'\
    \ + (0 or 2B or 4B), (2)\n        //           -3M' + (0 or 2B or 4B or 6B) (3)\
    \ (mod MOD1)\n        // we checked that\n        //   ((1) mod MOD1) mod 5 =\
    \ 2\n        //   ((2) mod MOD1) mod 5 = 3\n        //   ((3) mod MOD1) mod 5\
    \ = 4\n        long long diff =\n            c1[i] - internal::safe_mod((long\
    \ long)(x), (long long)(MOD1));\n        if (diff < 0) diff += MOD1;\n       \
    \ static constexpr unsigned long long offset[5] = {\n            0, 0, M1M2M3,\
    \ 2 * M1M2M3, 3 * M1M2M3};\n        x -= offset[diff % 5];\n        c[i] = x;\n\
    \    }\n\n    return c;\n}\n\n}  // namespace atcoder\n\n\n#line 7 \"test/bigint/multipication.test.cpp\"\
    \n\nint main(){\n    bigint_convolution::set(atcoder::convolution_ll);\n    bint\
    \ a,b;\n    std::cin >> a >> b;\n    std::cout << a * b << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_C\"\
    \n\n#include <iostream>\n\n#include \"../../math/bigint.hpp\"\n#include \"../../atcoder/convolution.hpp\"\
    \n\nint main(){\n    bigint_convolution::set(atcoder::convolution_ll);\n    bint\
    \ a,b;\n    std::cin >> a >> b;\n    std::cout << a * b << \"\\n\";\n}"
  dependsOn: [math/bigint.hpp, atcoder/convolution.hpp, atcoder/internal_bit.hpp,
    atcoder/modint.hpp, atcoder/internal_math.hpp, atcoder/internal_type_traits.hpp]
  isVerificationFile: true
  path: test/bigint/multipication.test.cpp
  requiredBy: []
  timestamp: '2021-03-24 19:21:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/bigint/multipication.test.cpp
layout: document
redirect_from: [/verify/test/bigint/multipication.test.cpp, /verify/test/bigint/multipication.test.cpp.html]
title: test/bigint/multipication.test.cpp
---
