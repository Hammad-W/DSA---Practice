#include <iostream>
using namespace std;
void printPermutation(string str, int index){
    //base case
  if(index >= str.length() ) {
   cout<< str << " ";
   return;
  } 
  for(int j = index; j < str.length(); j++) {
    swap(str[index], str[j]);
    printPermutation(str, index+1);
  }   
}
int main() {
    string str = "abc";  // Added missing semicolon
    int index = 0;
    printPermutation(str, index);  // Corrected function name
}