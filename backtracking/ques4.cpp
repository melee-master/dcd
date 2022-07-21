#include <iostream>
#include <string>
using namespace std;
void Mazepath_D(int n1, int n2, string ans, int i, int j, int *arr){
    if(i==n1-1 and j==n2-1){
        arr[0]++;
        ans+'\0';
        cout<<ans<<" ";
    }
    if(i>=n1 || j>=n2){
        return;
    }
    Mazepath_D(n1, n2, ans+"V", i+1, j, arr);
    Mazepath_D(n1, n2, ans+"H", i, j+1, arr);
    Mazepath_D(n1, n2, ans+"D", i+1, j+1, arr);
    return ;
}

int main(){
    int arr[1]={0};
    int n1;
    int n2;
    cin>>n1;
    cin>>n2;
    Mazepath_D(n1, n2, "", 0, 0, arr);
    cout<<"\n"<<arr[0];

}