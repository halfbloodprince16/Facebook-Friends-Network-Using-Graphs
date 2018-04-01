#include"bits/stdc++.h"
using namespace std;
typedef  pair<int, int> iPair;
typedef  pair<string,int>jPair;
vector< pair<int, iPair> >v;
std::vector<pair<int,pair<int,int>>>::iterator itr,it,iit;

vector< pair<int, jPair> >u;
std::vector<pair<int,pair<string,int>>>::iterator t;

int rt1=0,rt2=0;
class Facebook
{
public:
	int a,b,x[100][100];//size of matrix;
	int weight;
	Facebook()
	{
		a = b = 0;
		x[100][100]={};
		weight=0;
	}
	void getmatrix()
	{
		cout<<endl<<"Enter the Number of People:";
		cin>>a;
		b = a;
		int i,j;
		cout<<endl<<"If one person is the friend on other then press 1 otherwise 0"<<endl;
		for(i=0;i<a;i++)
		{
			for(j=0;j<b;j++)
			{
				cout<<endl<<"Is "<<i<<"is a friend of "<<j<<" :";
				cin>>x[i][j];
			}
		}

		cout<<endl<<"The Friends Relation shown as"<<endl;
		for(i=0;i<a;i++)
		{
			for(j=0;j<b;j++)
			{
				cout<<i<<"-"<<j<<" "<<x[i][j]<<endl;
			}

		}

	}
	void maxfrnd();
	void dob();
	void maxcmt();
	void bday();
};
void Facebook :: maxfrnd()
{
	int i,j;
	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			if(x[i][j] != 0)
			{
				v.push_back({x[i][j],{i,j}});
			}
		}

	}
	
	sort(v.begin(),v.end());
	//sort successful
	cout<<endl<<"Graph After sorting turns out to be:"<<endl;
	for(itr = v.begin();itr != v.end() ; itr++)
	{
		cout<<itr->second.first<<"-"<<itr->second.second<<" "<<itr->first<<endl;
	}
	int hash[100]={};
	for(itr=v.begin();itr!=v.end();itr++)
	{
		hash[itr->second.first]++;
	}
	cout<<endl;
	for(int i = 0;i<100;i++)
	{
		if(hash[i]!=0)
			cout<<hash[i]<<endl;;
	}
	int max = *max_element(hash,hash+100);
	for(int i=0;i<100;i++)
	{
		if(max == hash[i])
		{
			cout<<"Maximum Friends are of this guy : "<<i<<endl;
		}
	}
	
}

void Facebook :: dob()
{
	string dob;
	int cmt;
	int i,j,k;

	for(i = 0 ; i < a ; i++)
	{
		cout<<"Enter the DOB as DD/MM/YYYY and No. of Comments of "<<i;
		cin>>dob>>cmt;
		u.push_back({i,{dob,cmt}});
	}
	/*
	for(t = u.begin() ; t != u.end() ; t++)
	{
		cout<<t->first<<" "<<t->second.first<<" "<<t->second.second<<endl;
	}*/
}

void Facebook :: maxcmt()
{
	int max;
	t = u.begin();
	max = t->second.second;
	for(t = u.begin()+1 ; t != u.end() ; t++)
	{
		if(t->second.second > max)
		{
			max = t->second.second;
		}
		else
		{
			continue;
		}
	}

	for(t = u.begin()+1 ; t != u.end() ; t++)
	{
		if(max == t->second.second)
		{
			cout<<endl<<"Maximum Comments is of this person : "<<t->first;
		}
	}

}

void Facebook :: bday()
{
	string s;
	cout<<"Enter The Todays Date to check the Birthday of Your Friends(dd/mm/yyyy)";
	cin>>s;
	for(t = u.begin()+1 ; t != u.end() ; t++)
	{
		if(s == t->second.first)
		{
			cout<<t->first<<"has his Birthday Today"<<endl;
		}
	}
}

int main(int argc, char const *argv[])
{
	Facebook f;
	int ch;
	int i,j,k;

	do
	{
		cout<<endl<<"1:Insert Graph\n2:Insert DOB and No. of Comments\n3:Maximum Friends\n4:Maximum Comments\n5:Birthday This Month\n";
		cin>>ch;
		switch(ch)
		{
			case 1: f.getmatrix();break;
			case 2: f.dob();break;
			case 3: f.maxfrnd();break;
			case 4: f.maxcmt();break;
			case 5: f.bday();break;

		}
	}
	while(ch!=6);
	return 0;
}