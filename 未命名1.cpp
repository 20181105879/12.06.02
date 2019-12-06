#include  <iostream>
using namespace std;
struct node {
	long len;
	long wei;	
}s[510][510];
long nv,ne;
long qi,si;
int vis[550];
int dis[500];
int cost[550];
void builtgtaph() 
{
	long t1,t2,l,w;
	for(long i=0;i<nv;i++)
	{
		for(long j=0;j<nv;j++)
		{
			s[i][j].len=10000;
			s[i][j].wei=10000;
		}
		s[i][i].len=0;
		s[i][i].wei=0;
		dis[i]=10000;
		cost[i]=10000;
	}
	for(long i=0;i<ne;i++)
	{
		cin>>t1>>t2>>l>>w;
		s[t1][t2].len=l;
		s[t1][t2].wei=w;
		s[t2][t1].len=l;
		s[t2][t1].wei=w;
	}

} 
long findmist()
{
	long  minv=0;
	long  mindist=10000;
	for(long i=0;i<nv;i++)
	{
		if(vis[i]==0 &&  (dis[i]<=mindist))
		{
			mindist=dis[i];
			minv=i;
		}
	
	}
	if(mindist<1000)
	{
		return minv;
	}
	else
	{
		return -1;
	}
	
}
void diskstra()
{
	for(long i=0;i<nv;i++)
	{
		dis[i]=s[qi][i].len;
		cost[i]=s[qi][i].wei;

	}
	dis[qi]=cost[qi]=0;
	vis[qi]=1;
	while(1)
	{
		long v=findmist();
		if(v==-1)
		{
			break;
		}
		vis[v]=1;
		for(long i=0;i<nv;i++)
		{
		     if(!vis[i] && s[v][i].wei<10000)
		     {
		     	
		     	  if(dis[v]+s[v][i].len<dis[i])
		     	  {
		     	  	dis[i]=dis[v]+s[v][i].len;
		     	  	cost[i]=cost[v]+s[v][i].wei;
				  }
				  else if(dis[v]+s[v][i].len==dis[i])
				  {
					  	if(cost[v]+s[v][i].wei<cost[i])
					  	{
					  		cost[i]=cost[v]+s[v][i].wei;
						}
				  }
		     	
		     	
		     	
			 }
		
		
		
		}
		
		
		
		
		
		
	}
	
	
	
	
	
}

int main()
{
	
	cin>>nv>>ne>>qi>>si;
	builtgtaph();
	diskstra();
	cout<<dis[si]<<" "<<cost[si];
	
	
	
	
	
	
	
	
	return 0;
 } 
