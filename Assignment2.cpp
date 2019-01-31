#include<bits/stdc++.h>
using namespace std;
long long int inv=0;
void mergesort(long long int *a,long long int n)
{
    long long int b[n];
    long long int x;
    if((n==0)||(n==1))
        return;
    x=n/2;
    mergesort(a,x);
    mergesort(a+x,n-x);
    long long int i=0,j=x,k=0;
    while((i<x)&&(j<n))
    {
        if(a[i]>a[j])
        {
            b[k]=a[j];
            inv=inv+x-i;
            j++;
        }
        else
        {
            b[k]=a[i];
            i++;
        }
        k++;
    }
    if(i==x)
    {
        while(j<n)
        {
            b[k]=a[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<x)
        {
            b[k]=a[i];
            i++;
            k++;
        }
    }
    for(i=0;i<k;i++)
    {
        a[i]=b[i];
    }
}
int main()
{
    long long int n,t,i;
    cin>>t;
    while(t--)
    {
        inv=0;
        cin>>n;
        long long int a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        mergesort(a,n);
        cout<<inv<<"\n";
    }
    return 0;
}
