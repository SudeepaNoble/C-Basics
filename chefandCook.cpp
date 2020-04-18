
#include<iostream>
#include <bits/stdc++.h>
using namespace std;


int main() 
{
	    int t;
	    cin>>t;
	    while(t--)
	    {
	        long long int flag=1,i,j=0,n,sum1=0,sum2=0;
	        cin>>n;
	        long long int array[n];
	        long long int t=n-1;
	        for(i=0;i<n;i++)
	        {
	            cin>>array[i];
	        }
	        for(i=1;j!=t;i++)
	        {
	           if(flag==1)
	           {
	            if(array[j]>array[t])
	            {
	                sum1=sum1+array[j];
	                j++;
	            }
	            else if(array[j]==array[t])
	            {
	                sum1=sum1+array[j];
	                j++;
	            }
	            else
	            {
	                  sum1=sum1+array[t];
	                  t--;
	            }
           		flag=0;
	           	}
	           	else
	           	{
	               
	               if(array[j]>array[t])
	               {
	                   sum2+=array[j];
	                   j++;
	               }
	               else if(array[j]==array[t])
	               {
	                   sum2+=array[j];
	                   j++;
	               }
	               else
	               {
	                   sum2+=array[t];
	                   t--;
	               }
               	flag=1;
	           	}
	        }
	        if(sum1>sum2)
	         	cout<<"Chef is the winner"<<endl;
	        else 
	          	cout<<"Cook is the winner"<<endl;
	    }
}