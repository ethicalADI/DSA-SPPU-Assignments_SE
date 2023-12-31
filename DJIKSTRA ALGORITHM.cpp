/*
BY:ADITYA KUMAR  
Topic: DJIKSTRA ALGORITHM
*/

#include<bits/stdc++.h>
using namespace std;


int main(){
	cout<<"Enter Vertices : ";
	int v;cin>>v;
	vector<vector<int>> cost(v+1,vector<int>(v+1,-1));
	cout<<"Enter edges : ";
	int e;cin>>e;
	
	for(int i=0;i<e;i++)
	{
		int U,V,X;
		cin>>U>>V>>X;
		cost[U][V]=X;
		cost[V][U]=X;
	}
	vector<int> visited(v+1,0);
	vector<int> dist(v+1,1e9);
	int source=0;
	int cntvisited=0;
    dist[0]=0;
	
	while(cntvisited!=v)
	{
		visited[source]=1;
		cntvisited++;
		for(int i=0;i<v;i++)
		{
			if(i!=source && cost[source][i]!=-1 && visited[i]==0)
			{
				dist[i]=min(dist[i],dist[source]+cost[source][i]);
			}
		}
		int mn=1e9;
		for(int i=0;i<v;i++)
		{
			if(visited[i]==0 && dist[i]<mn)
			{
				source=i;
				mn=dist[i];
			}
		}
	}
	cout<<"Visited\n";
	for(int i=0;i<v;i++){
		cout<<visited[i]<<" ";
	}
	cout<<"\n";
	cout<<"Distances\n";
	for(int i=0;i<v;i++){
		cout<<dist[i]<<" ";
	}
	cout<<"\n";
}
