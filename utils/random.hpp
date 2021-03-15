#ifndef SORAIE_RANDOM
#define SORAIE_RANDOM

#include <random>

unsigned long long xor128(){
    static unsigned long long tx = 123456789, ty=362436069, tz=521288629, tw=88675123;
    unsigned long long tt = (tx^(tx<<11));
    tx = ty; ty = tz; tz = tw;
    return (tw=(tw^(tw>>19))^(tt^(tt>>8)));
}

unsigned long long xor128(unsigned long long a){
    return xor128() % (a + 1);
}

unsigned long long xor128(unsigned long long a,unsigned long long b){
    return xor128(b - a + 1) + a;
}

long long xor128(long long a,long long b){
    return xor128(b - a - 1) + a;
}

std::random_device randomd;
std::mt19937_64 mt(randomd());
long long randint(){
    std::uniform_int_distribution<long long> uni;
    return uni(mt);
}

long long randint(long long a){
    std::uniform_int_distribution<long long> uni(0,a);
    return uni(mt);
}

long long randint(long long a,long long b){
    std::uniform_int_distribution<long long> uni(a,b);
    return uni(mt);
}

long long randfloat(){
    std::uniform_real_distribution<long double> uni;
    return uni(mt);
}

long long randfloat(long long a){
    std::uniform_real_distribution<long double> uni(0,a);
    return uni(mt);
}

long double randfloat(long double a,long double b){
    std::uniform_real_distribution<long double> uni(a,b);
    return uni(mt);
}



#endif /*SORAIE_RANDOM*/