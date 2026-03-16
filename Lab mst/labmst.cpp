#include<bits/stdc++.h>
using namespace std;
int solve(vector<string>&words){
    int ans=0;
    int n=words.size();
    vector<int>mask(n,0);
    for(int i=0;i<n;i++){
        for(auto c:words[i]){
            mask[i]|=(1<<(c-'a'));
        }
    }
    for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((mask[i] & mask[j]) == 0) {
                    ans = max(ans, (int)words[i].size() * (int)words[j].size());
                }
            }
        }
    return ans;
}
int main() {
    vector<string>arr={"abcw","baz","foo","xtfn","abcdef"};
    cout<<solve(arr);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>>& tasks) {
    sort(tasks.begin(), tasks.end(), [](vector<int>& a, vector<int>& b) {
        return (a[1] - a[0]) > (b[1] - b[0]);
    });
    int energy = 0;
    int current = 0;
    for (auto &t : tasks) {
        int actual = t[0];
        int minimum = t[1];
        if (current < minimum) {
            energy += minimum - current;
            current = minimum;
        }
        current -= actual;
    }
    return energy;
}
int main() {
    
    vector<vector<int>> tasks = {{1,2},{2,4},{10,11},{10,12},{8,9}};
    cout << solve(tasks);

}