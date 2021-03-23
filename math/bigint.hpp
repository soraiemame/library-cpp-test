#ifndef SORAIE_BIGINT
#define SORAIE_BIGINT

#include <vector>
#include <functional>
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <string>

namespace bigint_convolution{
    std::function<std::vector<long long>(std::vector<long long>,std::vector<long long>)> convolution;
    void set(const std::function<std::vector<long long>(std::vector<long long>,std::vector<long long>)>& f){convolution = f;}
    std::vector<long long> naive(const std::vector<long long>& a,const std::vector<long long>& b){
        int n = int(a.size()),m = int(b.size());
        std::vector<long long> res(n + m - 1);
        if(n < m)
            for(int j = 0;j < m;j++)for(int i = 0;i < n;i++)res[i + j] += a[i] * b[j];
        else
            for(int i = 0;i < n;i++)for(int j = 0;j < m;j++)res[i + j] += a[i] * b[j];
        return res;
    };
};

template<int d,int base>
struct bigint{
    using bint = bigint<d,base>;
    bigint(const std::string& _s){
        sign = 1;
        dat.clear();
        if(_s.empty())return;
        if(_s[0] == '-')sign = -1;
        std::string s = sign == 1 ? _s : _s.substr(1);
        int i;
        for(i = int(s.size()) - d;i >= 0;i -= d){
            assert('0' <= s[i] && s[i] <= '9');
            dat.push_back(std::stoll(s.substr(i,d)));
        }
        if(i + d)dat.push_back(std::stoll(s.substr(0,i + d)));
    }
    bigint(long long n = 0){
        sign = 1;
        dat.clear();
        if(n < 0)sign = -1,n = -n;
        while(n){
            dat.push_back(n % base);
            n /= base;
        }
    }
    int size()const{return int(dat.size());}
    int number_len()const{
        if(size() == 0)return 0;
        int res = (int(dat.size()) - 1) * d;
        int b = 1,p = 0;
        while(b <= dat.back())p++,b *= 10;
        return res + p;
    }
    std::string to_string()const{
        if(size() == 0)return "0";
        std::string res = "";
        if(sign == -1)res = "-";
        auto to_string_pad = [](long long m,int _d){
            std::string r = std::to_string(m);
            std::string ap(_d - int(r.size()),'0');
            return ap + r;
        };
        for(int i = size() - 1;i >= 0;i--){
            if(i != size() - 1)res += to_string_pad(dat[i],d);
            else res += std::to_string(dat[i]);
        }
        return res;
    }
    long long to_ll()const{
        long long res = 0;
        for(long long x : dat)res = res * base + x;
        return sign * res;
    }
    void norm(){
        if(dat.empty())return;
        for(int i = 0;i < size() - 1;i++){
            long long nex = dat[i] / base;
            if(nex * base > dat[i])nex--;
            dat[i] -= nex * base;
            dat[i + 1] += nex;
        }
        while(dat.back() >= base){
            long long nex = dat.back() / base;
            dat.back() -= nex * base;
            dat.push_back(nex);
        }
        while(!dat.empty() && dat.back() == 0)dat.pop_back();
    }

    inline constexpr bool operator<(const bint& a)const noexcept{
        if(a.dat.empty())return false;
        else if(sign != a.sign)return sign < a.sign;
        else if(sign == -1)return (-a) < (-bint(*this));
        else if(number_len() != a.number_len())return number_len() < a.number_len();
        else{
            for(int i = size() - 1;i >= 0;i--)if(dat[i] != a.dat[i])return dat[i] < a.dat[i];
            return false;
        }
    }
    inline constexpr bool operator>(const bint& a)const noexcept{return a < bint(*this);}
    inline constexpr bool operator<=(const bint& a)const noexcept{return !(a < bint(*this));}
    inline constexpr bool operator>=(const bint& a)const noexcept{return !(bint(*this) < a);}
    inline constexpr bool operator==(const bint& a)const noexcept{return dat == a.dat;}
    inline constexpr bool operator!=(const bint& a)const noexcept{return dat != a.dat;}

    inline constexpr bint operator-()const noexcept{
        bint res(*this);
        res.sign = -res.sign;
        return res;
    }
    friend bint abs(const bint& a){return a.sign == -1 ? -a : a;}

    inline constexpr bint &operator+=(const bint& a)noexcept{
        if(sign != a.sign)return *this -= (-a);
        else{
            if(size() < a.size())dat.resize(a.size());
            for(int i = 0;i < a.size();i++)dat[i] += a.dat[i];
            norm();
            return *this;
        }
    }
    inline constexpr bint &operator-=(const bint& a)noexcept{
        if(sign != a.sign)return *this += (-a);
        else if(abs(bint(*this)) < abs(a)){
            *this = a - *this;sign = -sign;
            return *this;
        }
        else{
            for(int i = 0;i < a.size();i++)dat[i] -= a.dat[i];
            norm();
            return *this;
        }
    }

    inline constexpr bint &operator++()noexcept{return *this += bint(1);}
    inline constexpr bint operator++(int)noexcept{operator++();return bint(*this);}
    inline constexpr bint &operator--()noexcept{return *this -= bint(1);}
    inline constexpr bint operator--(int)noexcept{operator--();return bint(*this);}

    inline constexpr bint &operator*=(const bint& a)noexcept{
        if(size() == 0 || a.size() == 0)return *this = bint(0);
        if(std::min(size(),a.size()) <= 60)dat = bigint_convolution::naive(dat,a.dat);
        else dat = bigint_convolution::convolution(dat,a.dat);
        norm();
        sign *= a.sign;
        return *this;
    }
    inline constexpr bint mul2()const noexcept{
        bint res(*this);
        for(auto& x : res.dat)x *= 2;
        res.norm();
        return res;
    }
    inline constexpr bint div2()const noexcept{
        bint res(*this);
        int nex = 0;
        for(int i = res.size() - 1;i >= 0;i--){
            long long cur = (res[i] + nex * base);
            res[i] = cur / 2;
            nex = cur % 2;
        }
        return res;
    }
    inline constexpr int rem2()const noexcept{
        if(dat.empty())return 0;
        else return dat[0] & 1;
    }
    inline constexpr bint &operator>>=(int k)noexcept{
        dat = std::vector<long long>(dat.begin() + std::min(k,int(size())),dat.end());
        return *this;
    }
    inline constexpr bint &operator<<=(int k)noexcept{
        if(!dat.empty()){
            std::vector<long long> add(k,0);
            dat.insert(dat.begin(),add.begin(),add.end());
        }
        return *this;
    }

    inline constexpr bint &operator/=(long long v)noexcept{
        if(v < 0)sign = -sign,v = -v;
        for(int i = size() - 1,rem = 0;i >= 0;i--){
            long long cur = dat[i] + rem * (long long)(base);
            dat[i] = (long long)(cur / v);
            rem = (long long)(cur % v);
        }
        norm();
        return *this;
    }
    friend std::pair<bint,bint> divmod_naive(const bint& _a,const bint& _b){
        bint zero,s,t;
        bint a = abs(_a),b = abs(_b);
        if(a < b)return std::make_pair(zero,a);
        bint ar = b;
        s.dat.resize(a.size()),t.dat.resize(b.size());
        int tx = a.size() - 1;
        for(;tx >= 0;--tx)if(a.dat[tx] > 0)break;
        for(int i = tx; i >= 0; --i){
            t <<= 1;
            t += a.dat[i];
            long long lo = 0,hi = base;
            if(t >= ar){
                while(hi - lo > 1){
                    int mid = (hi + lo) / 2;
                    if(ar * mid > t)hi = mid;
                    else lo = mid;
                }
                t -= ar * lo;
            }
            s.dat[i] = lo;
        }
        if(_a.sign == _b.sign)s.sign = 1,t.sign = 1;
        else s.sign = -1,t.sign = 1;
        s.norm();t.norm();
        return std::make_pair(s,t);
    }
    inline constexpr bint &operator/=(const bint& a)noexcept{
        if(size() - a.size() <= 10)return *this = divmod_naive(bint(*this),a).first;
        else return *this = this->div_fast(a);
    }
    
    inline constexpr bint &operator%=(const bint& a)noexcept{
        if(size() - a.size() <= 10)return *this = divmod_naive(bint(*this),a).second;
        else return *this = bint(*this) - this->div_fast(a) * a;
    }

    inline constexpr bint operator+(const bint& a)const noexcept{return bint(*this) += a;}
    inline constexpr bint operator-(const bint& a)const noexcept{return bint(*this) -= a;}
    inline constexpr bint operator*(const bint& a)const noexcept{return bint(*this) *= a;}
    inline constexpr bint operator>>(int k)const noexcept{return bint(*this) >>= k;}
    inline constexpr bint operator<<(int k)const noexcept{return bint(*this) <<= k;}
    inline constexpr bint operator/(long long v)const noexcept{return bint(*this) /= v;}
    inline constexpr bint operator/(const bint& a)const noexcept{return bint(*this) /= a;}
    inline constexpr bint operator%(const bint& a)const noexcept{return bint(*this) %= a;}

    friend std::ostream &operator<<(std::ostream& os,const bint& a){return os << a.to_string();}
    friend std::istream &operator>>(std::istream& is,bint& a){
        std::string s;
        is >> s;
        a = bint(s);
        return is;
    }

private:
    int sign;
    std::vector<long long> dat;
    bint div_fast(const bint& _a)const noexcept{
        bint a = abs(*this),b = abs(_a);
        if(a < b)return bint();
        int tar = a.size() - b.size() + 1,m = 1;
        while(b.dat.back() * m * 10 < base)m *= 10;
        bint inv(m * base),pre(0);
        const bint two(2);
        while(inv != pre){
            pre = inv;
            inv *= (two << 2) - inv * b.dat.back();
            inv >>= 2;
        }
        int cur = 2,bcur = 1;
        pre = bint(0);
        while(inv != pre){
            bint c;
            c.dat = std::vector<long long>(b.dat.end() - bcur,b.dat.end());
            pre = inv;
            inv *= (two << (cur + bcur - 1)) - inv * c;
            int nex = std::min(cur << 1,tar);
            inv.dat = std::vector<long long>(inv.dat.end() - nex,inv.dat.end());
            cur = nex;
            bcur = std::min(bcur << 1,b.size());
        }
        inv.dat = std::vector<long long>(inv.dat.end() - tar,inv.dat.end());
        bint res = a * inv;res.dat = std::vector<long long>(res.dat.begin() + a.size(),res.dat.end());
        bint mul = res * b;
        while(mul + b <= a){
            res++;
            mul += b;
        }
        res.sign = sign * _a.sign;
        return res;
    }
};
using bint = bigint<4,10000>;

#endif /*SORAIE_BIGINT*/