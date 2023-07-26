#include<bits/stdc++.h>
using namespace std;
bool palindrome(string str, int i ,int  j )
{
    if(i > j)
        return true;
        
    if(str[i] != str[j]) return false;
    
    return palindrome(str,i+1,j-1);
    
}
int main()
{
    string str;
    cin>> str;
    int i = 0; 
    int j = str.size()-1;
     cout<< palindrome(str, i , j)<<endl;
}