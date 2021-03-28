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
  bundledCode: "#line 1 \"math/fraction.hpp\"\n\n\n\n#include <numeric>\n#include\
    \ <iostream>\n\ntemplate<class T = long long>\nstruct rationary{\n    using D\
    \ = long double;\n    T den,num;\n    rationary(T num_ = T(0),T den_ = T(1)):den(den_),num(num_){\n\
    \        norm();\n    }\n    void norm(){\n        assert(den != 0);\n       \
    \ if(den < 0)den = -den,num = -num;\n        T g = std::gcd(den,num);\n      \
    \  den /= g;num /= g;\n    }\n    inline rationary operator-(){(*this).num *=\
    \ -1;return (*this);}\n    inline const rationary& operator+=(const rationary&\
    \ a)noexcept{\n        num = num * a.den + a.num * den;\n        den = den * a.den;\n\
    \        norm();\n        return *this;\n    }\n    inline const rationary& operator-=(const\
    \ rationary& a)noexcept{\n        num = num * a.den - a.num * den;\n        den\
    \ = den * a.den;\n        norm();\n        return *this;\n    }\n    inline const\
    \ rationary& operator*=(const rationary& a)noexcept{\n        num *= a.num;\n\
    \        den *= a.den;\n        norm();\n        return *this;\n    }\n    inline\
    \ const rationary& operator/=(const rationary& a)noexcept{\n        num *= a.den;\n\
    \        den *= a.num;\n        norm();\n        return *this;\n    }\n    inline\
    \ constexpr const rationary operator+(const rationary& a)const noexcept{return\
    \ rationary(*this) += a;}\n    inline constexpr const rationary operator-(const\
    \ rationary& a)const noexcept{return rationary(*this) -= a;}\n    inline constexpr\
    \ const rationary operator*(const rationary& a)const noexcept{return rationary(*this)\
    \ *= a;}\n    inline constexpr const rationary operator/(const rationary& a)const\
    \ noexcept{return rationary(*this) /= a;}\n    inline rationary inv()const{return\
    \ rationary(den,num);}\n    inline bool operator==(const rationary& a)const noexcept{return\
    \ num == a.num && den == a.den;}\n    inline bool operator!=(const rationary&\
    \ a)const noexcept{return !(rationary(*this) == a);}\n    inline bool operator<(const\
    \ rationary& a)const noexcept{return __int128_t(num) * a.den < __int128_t(a.num)\
    \ * den;}\n    inline bool operator>(const rationary& a)const noexcept{return\
    \ a < rationary(*this);}\n    inline bool operator<=(const rationary& a)const\
    \ \n    noexcept{return !(a > rationary(*this));}\n    inline bool operator>=(const\
    \ rationary& a)const noexcept{return !(a < rationary(*this));}\n    inline D to_D()const{return\
    \ D(num) / den;}\n\n    inline friend std::ostream& operator<<(std::ostream& os,const\
    \ rationary& a){\n        if(a.den == 1)return os << a.num;\n        else return\
    \ os << a.num << \" / \" << a.den;\n    }\n    inline friend const rationary abs(const\
    \ rationary& a){return (a.num < 0 ? rationary(-a.num,a.den) : rationary(a.num,a.den));}\n\
    };\nusing frac = rationary<long long>;\n\n\n"
  code: "#ifndef SORAIE_FRACTION\n#define SORAIE_FRACTION\n\n#include <numeric>\n\
    #include <iostream>\n\ntemplate<class T = long long>\nstruct rationary{\n    using\
    \ D = long double;\n    T den,num;\n    rationary(T num_ = T(0),T den_ = T(1)):den(den_),num(num_){\n\
    \        norm();\n    }\n    void norm(){\n        assert(den != 0);\n       \
    \ if(den < 0)den = -den,num = -num;\n        T g = std::gcd(den,num);\n      \
    \  den /= g;num /= g;\n    }\n    inline rationary operator-(){(*this).num *=\
    \ -1;return (*this);}\n    inline const rationary& operator+=(const rationary&\
    \ a)noexcept{\n        num = num * a.den + a.num * den;\n        den = den * a.den;\n\
    \        norm();\n        return *this;\n    }\n    inline const rationary& operator-=(const\
    \ rationary& a)noexcept{\n        num = num * a.den - a.num * den;\n        den\
    \ = den * a.den;\n        norm();\n        return *this;\n    }\n    inline const\
    \ rationary& operator*=(const rationary& a)noexcept{\n        num *= a.num;\n\
    \        den *= a.den;\n        norm();\n        return *this;\n    }\n    inline\
    \ const rationary& operator/=(const rationary& a)noexcept{\n        num *= a.den;\n\
    \        den *= a.num;\n        norm();\n        return *this;\n    }\n    inline\
    \ constexpr const rationary operator+(const rationary& a)const noexcept{return\
    \ rationary(*this) += a;}\n    inline constexpr const rationary operator-(const\
    \ rationary& a)const noexcept{return rationary(*this) -= a;}\n    inline constexpr\
    \ const rationary operator*(const rationary& a)const noexcept{return rationary(*this)\
    \ *= a;}\n    inline constexpr const rationary operator/(const rationary& a)const\
    \ noexcept{return rationary(*this) /= a;}\n    inline rationary inv()const{return\
    \ rationary(den,num);}\n    inline bool operator==(const rationary& a)const noexcept{return\
    \ num == a.num && den == a.den;}\n    inline bool operator!=(const rationary&\
    \ a)const noexcept{return !(rationary(*this) == a);}\n    inline bool operator<(const\
    \ rationary& a)const noexcept{return __int128_t(num) * a.den < __int128_t(a.num)\
    \ * den;}\n    inline bool operator>(const rationary& a)const noexcept{return\
    \ a < rationary(*this);}\n    inline bool operator<=(const rationary& a)const\
    \ \n    noexcept{return !(a > rationary(*this));}\n    inline bool operator>=(const\
    \ rationary& a)const noexcept{return !(a < rationary(*this));}\n    inline D to_D()const{return\
    \ D(num) / den;}\n\n    inline friend std::ostream& operator<<(std::ostream& os,const\
    \ rationary& a){\n        if(a.den == 1)return os << a.num;\n        else return\
    \ os << a.num << \" / \" << a.den;\n    }\n    inline friend const rationary abs(const\
    \ rationary& a){return (a.num < 0 ? rationary(-a.num,a.den) : rationary(a.num,a.den));}\n\
    };\nusing frac = rationary<long long>;\n\n#endif /*SORAIE_FRACTION*/"
  dependsOn: []
  isVerificationFile: false
  path: math/fraction.hpp
  requiredBy: []
  timestamp: '2021-03-21 13:18:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/fraction.hpp
layout: document
redirect_from: [/library/math/fraction.hpp, /library/math/fraction.hpp.html]
title: math/fraction.hpp
---
