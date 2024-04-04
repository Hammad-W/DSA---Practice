
#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int solve(vector<int>& nums, int s, int e) {
        if(s > e){
            return 0;

        }
        int option1 = nums[s] + solve(nums, s +2, e);
        int option2 = 0 + solve(nums,  s +1, e);
        int finalAns = max(option1, option2);
        return finalAns;
    }
    int rob(vector<int> & nums){
        int n = nums.size();
        // single element wala edge case - yaha maine galti kari thi
        if(n==1){
            return nums[0];
        }
        int option1 = solve(nums, 0,n-2);
        int option2 = solve(nums, 1, n-1);
        int ans = max(option1, option2);
        return ans;
    }
};
int main(){
vector<int> nums = {1,2,3,1};
Solution sol;
int maximumLoot = sol.rob(nums);
cout<< " Maximum loot that can be stolen :" << maximumLoot << endl;
return 0;
}