#include <bits/stdc++.h>
using namespace std;



int main(){
    int q;     cin>>q;
    deque<int> dq;

    while(q--){
        int k;      cin>>k;

        while(!dq.empty() && dq.back() > k){
            dq.pop_back();
        }

        dq.push_back(k);

    }


    while(!dq.empty()){
        cout << dq.front() << " ";
        dq.pop_front();
    }
    cout << "\n";



    return 0;
}