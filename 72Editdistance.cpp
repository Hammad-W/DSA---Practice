#include <iostream>
using namespace std;
class Solution {
public:
    int solve(string& a, string& b, int i, int j){
        if(i>= a.length()){
            //word wali string end hogayi
            //yani word2 ki length may be word 2 se choti hai
            return b.length() -j;
        }
        if(j>= b.length()){
            //word 2 end hogya
            //yani word 1 ki length may be greater than word2 hai
            return a.length() - i;
        }
        int ans = 0;

        if(a[i] == b[j]){
            //match
             ans = 0 + solve(a, b, i+1, j+1);
        }
        else{
            //match
           int option1 = 1+ solve(a, b, i, j+1);
           //remove
           int option2 = 1+ solve(a,b, i+1,j);
           //replace9
           int option3 = 1+ solve(a,b,i+1, j+1);
           ans = min(option1, min(option2, option3));

        }
        return ans;
        

        }
        int minDistance(string word1, string word2){

      
        int i = 0;
        int j = 0;
        int ans = solve(word1, word2,i, j);
        return ans;
    }
};
int main(){
 string   word1 = "horse";
 string word2 = "ros";

Solution sol;
 int minDistance = sol.minDistance(word1, word2);
cout<< " Minimum distance :" << minDistance << endl;
return 0;
}