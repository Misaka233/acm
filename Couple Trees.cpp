#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

using namespace std ;
const long long N = 100000000;
bool prime[N] ;
void initprime(){
    memset(prime, 1 , sizeof(prime)) ;
    prime[0] = prime[1] = 0 ;
    double t = sqrt(N) + 1 ;
    for(long long i = 2;i < t;i++){
        if(prime[i]){
            for(long long j = i + i;j < N;j += i)
                prime[j] = false ;
        }
    }
}

int main(){
    initprime();
    long long k , t ;
    while(cin >> k)
    {


        t = 0 ;
        for(long long i = 0;i < N;i++){
            if(prime[i]){
                t++;
                if(t == k){
                    cout << i << endl ;
                    break ;
                }
            }
        }
}
    return  0 ;
}
