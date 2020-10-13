#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:

    int solve1(string s) {
        int pos[256];
        for (int i=0; i<256; i++){
            pos[i] = -1;
        }
        int max_len = 0;
        int cur_len = 0;
        int cur_pos = 0;
        for (int i=0; i<s.length(); i++){
            if (pos[int(s[i])] == -1){
                cur_len += 1;
            }
            else{
                cur_len = i-pos[int(s[i])];
                for (int j=cur_pos; j<=pos[int(s[i])]; j++){
                    cur_pos = pos[int(s[i])]+1;
                    pos[int(s[j])] = -1;
                }
            }
            pos[int(s[i])] = i;
            max_len = max(max_len, cur_len);
        }
        return max_len;
    }

    int solve2(string s){
        int head=0, res=0;
        int loc[256];
        for(int i=0; i<256; i++) loc[i] = -1;
        for(int tail=0; tail<s.size(); tail++){
            int posi = int(s[tail]);
            if(loc[posi] >= head){
                head = loc[posi] + 1;
            }
            loc[s[tail]] = tail;
            res = max(tail-head+1, res);
        }
        return res;
    }

    int lengthOfLongestSubstring(string s) {
        return solve1(s);       
    }
};

int main(){
    Solution sol;
    string s = "abcabcbb";
    int res = sol.lengthOfLongestSubstring(s);
    cout << "res: " << res << "\n";
    return 0;
}