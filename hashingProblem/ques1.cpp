//check if a subarray has sum 0;
#include <iostream>
#include <unordered_set>
using namespace std;
bool checkZeroSum(int * arr, int n){
    unordered_set<int>s;
    int csum = 0;
    for(int i=0; i<n; i++){
        csum += arr[i];
        if(csum==0 || s.find(csum)!=s.end()){
            return true;
        }
        s.insert(csum);
    }
    return false;
}
int main(){
    int arr[] = {1, 2, 4, 1, 2, -4};
    int n = 6;
    if(checkZeroSum(arr, n)){
        cout<<"0";
    }else{
        cout<<"not 0";
    }
    return 0;
}