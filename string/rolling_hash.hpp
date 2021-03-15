#ifndef SORAIE_ROLLING_HASH
#define SORAIE_ROLLING_HASH

#include <vector>
#include <string>
#include <random>
#include <chrono>

struct rolling_hash{
private:
    static const unsigned long long mod = (1ULL << 61ULL) - 1;
    const unsigned long long base;
    std::vector<unsigned long long> pows;

    static inline unsigned long long add(unsigned long long a,unsigned long long b){
        if((a += b) >= mod)a -= mod;
        return a;
    }
    static inline unsigned long long mul(unsigned long long a,unsigned long long b){
        __uint128_t c = (__uint128_t)a * b;
        return add(c >> 61,c & mod);
    }
    static inline unsigned long long gen_base(){
        std::mt19937_64 mt(std::chrono::steady_clock::now().time_since_epoch().count());
        std::uniform_int_distribution<unsigned long long> rand(1,rolling_hash::mod - 1);
        return rand(mt);
    }
    void expand(int n){
        if(n + 1 > int(pows.size())){
            int fr = pows.size();
            pows.resize(n + 1);
            for(int i = fr;i <= n;i++){
                pows[i] = mul(pows[i - 1],base);
            }
        }
    }
public:
    std::vector<unsigned long long> build(const std::string &S){
        int sz = S.size();
        std::vector<unsigned long long> res(sz + 1);
        for(int i = 0;i < sz;i++){
            res[i + 1] = add(mul(res[i],base),S[i]);
        }
        return res;
    }

    unsigned long long get(const std::vector<unsigned long long>& hashed,int l,int r){
        expand(r - l);
        return add(hashed[r],mod - mul(hashed[l],pows[r - l]));
    }
    rolling_hash(unsigned long long _base = gen_base()):base(_base),pows{1}{}
};

#endif/*SORAIE_ROLLING_HASH*/