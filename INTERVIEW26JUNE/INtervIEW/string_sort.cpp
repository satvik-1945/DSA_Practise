#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin>> str;

    
    vector<int> v(200,0);
    for(int i = 0 ; i< str.size() ; i++)
    {
        v[str[i]-'a']++;
    }
    for(int i = 0 ; i<  26; i++)
    {
        if(v[i] > 0)
        {
            for(int j = 0;j< v[i];j++)
                cout<< char( 'a' + i  );
        }
    }
}