#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define MAX 1000001
using namespace std;


int main() {
    
    int t;
    cin >> t;
    
    for( int i=0; i<t; i++){
        int n;
        long long sol=0;
        cin >> n;
        int arr[MAX]={0};    
        for(int j=0; j<n; j++){
            int a;
            cin >> a;
            arr[a]++;
        }
        for(int j=0; j<MAX; j++){
            if(arr[j]>1)
                sol += (long long)(arr[j]*(long long)(arr[j]-1));
                
        }
        cout << sol << endl;
    }
    
    
    
    return 0;
}
