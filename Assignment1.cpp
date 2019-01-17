#include<bits/stdc++.h>
#include <string>
using namespace std;
string add(string n1,string n2)
{
	int l1=n1.length(),l2=n2.length(),a1,a2,c=0,n;
	string ans="";
	while(1)
	{
		if(l1==0&&l2==0)
			break;
		if(l1==0)
			a1=0;
		else
		{
			a1=n1[l1-1]-'0';
			l1--;
		}
		if(l2==0)
			a2=0;
		else
		{
			a2=n2[l2-1]-'0';
			l2--;
		}
		n=a1+a2+c;
		c=n/10;
		n=n%10;
		ostringstream str1;
		str1<<n;
		ans=ans+str1.str();
	}
	ostringstream str2;
	str2<<c;
	ans=ans+str2.str();
	reverse(ans.begin(),ans.end());
	return ans;
}
string Karatsuba_multiplication(string n1,string n2)
{
	int l1=n1.length(),l2=n2.length(),i;
	if(l1==1&&l2==1)
	{
		ostringstream str1;
		str1<<(n1[0]-'0')*(n2[0]-'0');
		return str1.str();
	}
	if(l1==0||l2==0)
		return "0";
	string a=n1.substr(0,l1/2),b=n1.substr(l1/2,l1-(l1/2));
	string c=n2.substr(0,l2/2),d=n2.substr(l2/2,l2-(l2/2));
	string p,q,r,s,t="",u="",x,y,z;
	p=Karatsuba_multiplication(a,c);
	q=Karatsuba_multiplication(a,d);
	r=Karatsuba_multiplication(b,c);
	s=Karatsuba_multiplication(b,d);
	for(i=0;i<l1-l1/2;i++)
		t=t+"0";
	for(i=0;i<l2-l2/2;i++)
		u=u+"0";
	p.append(t+u);
	q.append(t);
	r.append(u);
	x=add(p,q);
	y=add(r,s);
	z=add(x,y);
	return z;
}
int main()
{
	string n1,n2;
	cin>>n1>>n2;
	string res=Karatsuba_multiplication(n1,n2);
	int i=0,l=res.length();
	while(1)
	{
		if(i==l||res[i]!='0')
			break;
		i++;
	}
	if(i==l)
		cout<<"0\n";
	else
		cout<<res.substr(i,l-i)<<endl;
	return 0;
}

// 3141592653589793238462643383279502884197169399375105820974944592 * 2718281828459045235360287471352662497757247093699959574966967627 = 8539734222673567065463550869546574495034888535765114961879601127067743044893204848617875072216249073013374895871952806582723184
