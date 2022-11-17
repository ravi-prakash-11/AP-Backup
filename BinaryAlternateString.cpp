#include<iostream>
using namespace std;

int main(){
	string str,s="";
	cout<<"\nEnter Binary String: ";
	cin>>str;
	int n=str.length();
    for(int i=0; i<n; i++)
    {
		if(str[i]!=str[i+1])
			s+=str[i];
	}

	cout<<"\nNew String : "<<s<<endl;
	cout<<"\nMinimum deletions required: "<<n - s.length()<<endl<<endl<<endl;

	return 0;
}