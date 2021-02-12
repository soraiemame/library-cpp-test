#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_1_C"

#include "../../geometory/main.hpp"

int main(){
    Point p1 = inputP(),p2 = inputP();
    int Q;
    std::cin >> Q;
    for(int i = 0;i < Q;i++){
        Point q = inputP();
        int r = dir(q,p1,p2);
        if(r == 1)std::cout << "COUNTER_CLOCKWISE\n";
        else if(r == -1)std::cout << "CLOCKWISE\n";
        else if(q == p1 || q == p2 || r == 2)std::cout << "ON_SEGMENT\n";
        else if(r == -2)std::cout << "ONLINE_BACK\n";
        else std::cout << "ONLINE_FRONT\n";
    }
}