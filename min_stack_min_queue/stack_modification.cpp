#include<bits/stdc++.h>
using namespace std;


int main(){
    int q ;        cin>>q;
    stack<pair<int,int>> st;

    while(q--){
        int val ;       cin>>val;
        
        int new_val = st.empty()?val:min(st.top().second, val);

        st.push({val, new_val});
    }


    while(!st.empty()){
        cout << st.top().first << " " << st.top().second << "\n";
        st.pop();
    }

    return 0;
}