#include <bits/stdc++.h>
#define ll long long int

using namespace std;


int main(){
    int n, q;       cin>>n>>q;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    while(q--){
        int d;        cin>>d;
        int ans = 1e9+7;
        deque<int> dq;
        for(int i=1;i<=d;i++){
            
            while(!dq.empty() && dq.back()<a[i]){
                dq.pop_back();
            }

            dq.push_back(a[i]);

        }

        ans = min(dq.front(), ans);

        int k=1;
        for(int i=d+1;i<=n;i++){
            if(!dq.empty() && dq.front() == a[k])dq.pop_front();

            while(!dq.empty() && dq.back()<a[i])dq.pop_back();

            dq.push_back(a[i]);
            ans = min(dq.front(), ans);
            k++;
        }


        cout << ans << "\n";


    }




    return 0;
}

//https://www.hackerrank.com/challenges/queries-with-fixed-length/problem