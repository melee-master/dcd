#include <iostream>
using namespace std;

int abs(int n1, int n2){
    if(n1>n2){
        return n1-n2;
    }
    return n2-n1;
}


int main(){
    int arr[1000] = {0};
    memset(arr, 0 ,sizeof (arr));
    string name;
    int n, rank;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>name>>rank;
        arr[rank]++;
    }
    int actualRank=1;
    int sum =0;
    for(int i=1; i<=n; i++){
        while(arr[i]){
            sum += abs(actualRank, i);
            actualRank++;
            arr[i]--;
        }
    }
    cout<<sum;
    return 0;
}