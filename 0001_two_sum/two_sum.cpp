#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // If change unordered_map to map, run speed is slow down. Since map is implemented with BBST
        unordered_map<int, int> record;

        vector<int> result;
        for(int i=0; i<nums.size(); i++){
            auto it = record.find(target-nums[i]);
            if (it != record.end()){
                result.push_back(it->second);
                result.push_back(i);
            }
            else{
                record[nums[i]] = i;
            } 
        }
        return result;
    }
};

int main(){
    Solution sol;
    int A[4] = {7, 2, 11, 15};
    vector<int> nums;
    for (int i=0; i<4; i++){
        nums.push_back(A[i]);
    }
    int target = 9;

    vector<int> result = sol.twoSum(nums, target);

    for (int i=0; i<result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}