#include<bits/stdc++.h>

using namespace std;
class player
{
	static int matchsticks;
	static int i;
	int n;
	public:
		player()
		{
			n=0;
		}
		void turn(int);
		static void set_matchsticks(int m)
		{
			matchsticks=m;
		}
};
int player::matchsticks=21;
int player::i=0;
void player::turn(int max)
{
	if(matchsticks<=0)
	{
		if(i%2==1)
		{
			cout<<"\n Match Lost by User ...";
		}
		else
		{
			cout<<"\n Match Lost by Computer ...";
		}
		exit(0);
	}
	srand(time(NULL)); 
	if(i%2==0)
	{
		cout<<"\n Users Turn \n Enter the no of matchstick you want to pick up : ";
		cin>>n;
		if(n>max)
		{
			cout<<"\n Invalid Move...\t Match Lost By User...";
			exit(0);
		}
		matchsticks-=n;
		if(n<=0)
		{
			cout<<"\n User Lost the Game ...";
			exit(0);
		}
		else
		{
			cout<<"\n Number of matchbox left = "<<matchsticks;
		}
		i++;
	}
	else
	{
		n=1+rand()%4;
		cout<<"\n computers Turn \n Number of matchsticks picked by computer = "<<n;
		matchsticks-=n;
		if(n<=0)
		{
			cout<<"\n Computer Lost the Game ...";
			exit(0);
		}
		else
		{
			cout<<"\n Number of matchbox left = "<<matchsticks;
		}
		i++;		
	}
	
}
int main()
{
	int max,n;
	cout<<"\n Enter Number of Matchsticks : ";
	cin>>n;
	player::set_matchsticks(n);
	cout<<"\n Enter predefined MAX matchsticks to be picked in one turn : ";
	cin>>max;
	player user,computer;
	while(1)
	{
		user.turn(max);
		computer.turn(max);	
	}	
	return 0;
}

