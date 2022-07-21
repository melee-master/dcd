//priority queue for custom class :
#include <iostream>
#include <queue>
#include <string>

using namespace std;

class person{
    public: 
    string name;
    int age;
    person(){

    }
    person(string n, int a){
        name = n;
        age = a;
    }
};

class personCompare {
    public:
    bool operator()(person a, person b){
        return a.age < b.age;
    }
};

int main(){
    int n;
    cin >> n;
    priority_queue<person , vector<person >, personCompare> pq;
    for(int i=0; i<n ;i++){
        string name;
        int age;
        cin>>name;
        cin>>age;
        person p(name, age);
        pq.push(p);
    }
    int k = 3;
    for(int i=0 ; i<k; i++){
        person atTop = pq.top();
        cout<<atTop.name<<" "<<atTop.age<<endl;
        pq.pop();
    }
}