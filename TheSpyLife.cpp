#include <iostream>

#include <bits/stdc++.h>

using namespace std;


int main()
{
   
	string s;

   	getline(cin,s);
   
	for(int i=s.length()-1;i>=0;i--)
   
	{
       
		if((s[i]>64 && s[i]<91)||(s[i]>96 && s[i]<123)||s[i]==' ')

       cout<<s[i];
   
	}
    
	return 0;
}