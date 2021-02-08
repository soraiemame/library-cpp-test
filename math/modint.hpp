#ifndef SORAIE_MODINT
#define SORAIE_MODINT

#include <algorithm>

template<long long MOD = 1000000007>
struct modint {
    long long x;
    modint(long long a = 0):x((a % MOD + MOD) % MOD){}
    inline constexpr modint operator-()const noexcept{return modint(-x);}
    inline constexpr modint &operator+=(const modint &a)noexcept{
        if ((x += a.x) >= MOD) x -= MOD;
        return *this;
    }
    inline constexpr modint &operator-=(const modint &a)noexcept{
        if ((x -= a.x) < 0) x += MOD;
        return *this;
    }
    inline constexpr modint &operator*=(const modint &a)noexcept{
        (x *= a.x) %= MOD;
        return *this;
    }
    inline constexpr modint &operator++()noexcept{
        x++;
        if(x == MOD)x = 0;
        return *this;
    }
    inline constexpr modint operator++(int)noexcept{
        modint res(*this);
        operator++();
        return res;
    }
    inline constexpr modint &operator--()noexcept{
        x--;
        if(x == -1)x = MOD - 1;
        return *this;
    }
    inline constexpr modint operator--(int)noexcept{
        modint res(*this);
        operator--();
        return res;
    }
    inline constexpr modint operator+(const modint &a)const noexcept{
        modint res(*this);
        return res += a;
    }
    inline constexpr modint operator-(const modint &a)const noexcept{
        modint res(*this);
        return res -= a;
    }
    inline constexpr modint operator*(const modint &a)const noexcept{
        modint res(*this);
        return res *= a;
    }
    inline constexpr modint inv()const{
        long long a = x,b = MOD,u = 1,v = 0;
        while(b){
            long long t = a / b;
            a -= t * b;std::swap(a,b);
            u -= t * v;std::swap(u,v);
        }
        return u;
    }
    inline constexpr modint &operator/=(const modint &a)noexcept{return (*this) *= a.inv();}
    inline constexpr modint operator/(const modint &a)const noexcept{
        modint res(*this);
        return res /= a;
    }
    friend std::istream &operator>>(std::istream &is,modint &a) {
        is >> a.x;
        a.x = (a.x % MOD + MOD) % MOD;
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os,const modint &a){
        os << a.x;
        return os;
    }
    long long getmod(){return MOD;}
    friend modint<MOD> modpow(modint<MOD> a,long long b)noexcept{
        modint<MOD> res(1);
        while(b){
            if(b & 1)res *= a;
            a *= a;
            b >>= 1;
        }
        return res;
    }
};


#endif /*SORAIE_MODINT*/