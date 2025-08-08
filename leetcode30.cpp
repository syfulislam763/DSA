#include <bits/stdc++.h>
using namespace std;

// Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]

// Output: [6,9,12]
int main(){

    vector<string> strArr = {"bar","foo","the"};
    string s = "barfoofoobarthefoobarman";

    vector<string> split_arr;

    map<string, bool> mp;
    vector<int> ans;

    int len = strArr[0].size();
    int arr_len = strArr.size();


    for(int i=0; i < s.size(); i = i+ len){
        string sub = s.substr(i, len);
        split_arr.push_back(sub);
    };

    for(auto w:strArr){
        mp[w] = true;
    }

    

    int split_arr_len = split_arr.size();
    for(int i=0; i<split_arr_len; i++){
         map<string, bool> visited;
         int c = 0;
        for(int j=i; (j<arr_len+i) && (split_arr_len-i) >= arr_len; j++){
            
            if(mp[split_arr[j]]){
                if(!visited[split_arr[j]]){
                    visited[split_arr[j]] = true;
                    c++;
                }
            }
        }

        if(c==arr_len){
            ans.push_back(i*len);
        }


        cout << endl;


    }


    for(auto idx: ans){
        cout << idx << " ";
    }
    cout << endl;





    return 0;
}