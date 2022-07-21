#include <iostream>
#include <vector>
#include <string>
using namespace std;

void permutationSrtrings(int i, string ch, vector<string>& outputt){

    if(ch[i]=='\0'){
        outputt.push_back(ch);
        return;
    }
    //Recursive Case:
    for(int j=i; ch[j]!='\0'; j++){
        swap(ch[i], ch[j]);
        permutationSrtrings(i+1, ch, outputt);
        swap(ch[i], ch[j]);
    }
}

int main(){
    string ch;
    cin>>ch;
    vector<string>outputt;
    permutationSrtrings(0, ch, outputt);
    sort(outputt.begin(), outputt.end());
    int count =0;
    for(int i=0; i<outputt.size(); i++){
        if(count!=0){
            cout<<outputt[i]<<" ";
        }
        if(outputt[i]==ch){
            count++;
        }
    }


}