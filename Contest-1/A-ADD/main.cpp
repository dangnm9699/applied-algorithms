#include <bits/stdc++.h>
using namespace std;
 
string add(string str1, string str2){
    string result = "";
    int carry = 0;
    
    if (str1.length() > str2.length()) swap(str1, str2); 
    int len1 = str1.length();
    int len2 = str2.length();
    int diff = len2 - len1;
    
    for (int i= len1 - 1; i >= 0; i --){
        int calc = (str2[i + diff] - '0') + (str1[i] - '0') + carry;
        result.push_back(calc%10 + '0');
        carry = calc/10;
    }
    
    for (int i = len2 - len1 - 1; i >= 0; i --){
        int calc = (str2[i] - '0') + carry;
        result.push_back(calc%10 + '0');
        carry = calc/10;
    }
    
    if (carry > 0) result.push_back(carry + '0');
    
    reverse(result.begin(), result.end());
    
    return result;
}
 
int main(){
    
    string str1, str2;
    cin >> str1 >> str2;
    cout << add(str1, str2);
    return 0;
}