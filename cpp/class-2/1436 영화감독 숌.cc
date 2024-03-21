#include <iostream>

using namespace std;

int main(){
    int N, cnt=1, snum=666;
    cin >> N;

    while(N!=cnt){
        snum++;
        int tnum = snum;
        while(tnum/100 > 1){
            if (tnum%1000 == 666){
                cnt++;
                break;
            }
            tnum /= 10;
        }
    }

    cout << snum;
}