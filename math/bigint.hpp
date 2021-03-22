#ifndef SORAIE_BIGINT
#define SORAIE_BIGINT

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<int d,int base>
struct bigint{
    using bint = bigint<d,base>;
    int sign;
    vector<ll> dat;
    bigint(const string& _s){
        dat.clear();
        sign = 1;
        if(_s.size() == 0)return;
        if(_s[0] == '-')sign = -1;
        string s = sign == 1 ? _s : _s.substr(1);
        int i;
        for(i = int(s.size()) - d;i >= 0;i -= d){
            assert('0' <= s[i] && s[i] <= '9');
            dat.push_back(stoll(s.substr(i,d)));
        }
        if(i + d)dat.push_back(stoll(s.substr(0,i + d)));
    }
    int size()const{return int(dat.size());}
    int number_len()const{
        int res = (int(dat.size()) - 1) * d;
        int b = 1,p = 0;
        while(b <= dat.back())p++,b *= 10;
        return res + p;
    }
    string to_string(){
        if(size() == 0)return "0";
        string res = "";
        if(sign == -1)res = "-";
        auto to_string_pad = [](ll m,int _d){
            string r = std::to_string(m);
            string ap(_d - int(r.size()),'0');
            return ap + r;
        };
        for(int i = size() - 1;i >= 0;i--){
            if(i != size() - 1)res += to_string_pad(dat[i],d);
            else res += std::to_string(dat[i]);
        }
        return res;
    }
    void norm(){
        for(int i = 0;i < size() - 1;i++){
            ll nex = dat[i] / base;
            if(nex * base > dat[i])nex--;
            dat[i] -= nex * base;
            dat[i + 1] += nex;
        }
        while(dat.back() >= base){
            ll nex = dat.back() / base;
            dat.back() -= nex * base;
            dat.push_back(nex);
        }
        while(!dat.empty() && dat.back() == 0)dat.pop_back();
    }

    bool operator<(const bint& a)const noexcept{
        if(sign != a.sign)return sign < a.sign;
        else if(sign == -1)return (-a) < (-bint(*this));
        else if(number_len() != a.number_len())return number_len() < a.number_len();
        else{
            for(int i = size() - 1;i >= 0;i--)if(dat[i] != a.dat[i])return dat[i] < a.dat[i];
            return false;
        }
    }
    bool operator>(const bint& a)const noexcept{return a < bint(*this);}
    bool operator<=(const bint& a)const noexcept{return !(a < bint(*this));}
    bool operator>=(const bint& a)const noexcept{return !(bint(*this) < a);}

    bint operator-()const noexcept{
        bint res(*this);
        res.sign = -res.sign;
        return res;
    }
    friend bint abs(const bint& a){return a.sign == -1 ? -a : a;}

    bint &operator+=(const bint& a)noexcept{
        if(sign != a.sign)return *this -= (-a);
        else{
            if(size() < a.size())dat.resize(a.size());
            for(int i = 0;i < a.size();i++)dat[i] += a.dat[i];
            norm();
            return *this;
        }
    }
    bint &operator-=(const bint& a)noexcept{
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

    bint operator+(const bint& a)const noexcept{return bint(*this) += a;}
    bint operator-(const bint& a)const noexcept{return bint(*this) -= a;}
};
using bint = bigint<4,10000>;

#endif /*SORAIE_BIGINT*/