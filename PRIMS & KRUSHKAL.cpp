/*
BY:ADITYA KUMAR  
Topic: PRIMS & KRUSHKAL
*/

#include<bits/stdc++.h>
using namespace std;
// prims 
void prims(int &v,int &e,vector<vector<int>> &cost){
	
	int mst=0;
	
	vector<int> visited(v+1,0);
	vector<int> dist(v+1,1e9);
	vector<int> from(v+1,0);
	
	int source=0;
	int cntvisited=0;
	dist[source]=0;
	while(cntvisited<v){
		visited[source]=1;
		cntvisited++;
		for(int i=0;i<v;i++){
			if(visited[i]==0 && cost[source][i]!=-1 && dist[i]>cost[source][i]){
				dist[i]=cost[source][i];
				from[i]=source;
			}
		}
		int mn=1e9;
		for(int i=1;i<=v;i++){
			if(visited[i]==0 && dist[i]<mn){
				source=i;
				mn=dist[i];
			}
		}
	}
	
	cout<<"Minimum Spanning Tree Adj Matrix\n";
	vector<vector<int>> minspantree(v+1,vector<int>(v+1,0));
	for(int i=1;i<v;i++){
		minspantree[from[i]][i]=dist[i];
		minspantree[i][from[i]]=dist[i];
		mst+=dist[i];
	}
	cout<<"Total Length : "<<mst<<"\n";
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			cout<<minspantree[i][j]<<" ";
		}
		cout<<"\n";
	}
}


// kruskal

int find_parent(int x,vector<int> &parent){
	if(parent[x]==-1){
		return x;
	}
	return parent[x]=find_parent(parent[x],parent);
}
void union_(int x,int y,vector<int> &parent){
	int px=find_parent(x,parent);
	int py=find_parent(y,parent);
	
	if(px!=py){
		parent[px]=py;
	}
}

void kruskal(int &v,int &e,vector<vector<int>> cost,vector<pair<int,pair<int,int>>> &edges){
	int mst=0;
	sort(edges.begin(),edges.end());
	
	vector<int> parent(v+1,-1);
	
	
	vector<vector<int>> minspantree(v+1,vector<int>(v+1,0));
	int i=0;
	while(i<e){
		int U,V,X;
		X=edges[i].first;
		U=edges[i].second.first;
		V=edges[i].second.second;
		
		if(find_parent(U,parent)!=find_parent(V,parent)){
			minspantree[U][V]=X;
			minspantree[V][U]=X;
			mst+=X;
			union_(U,V,parent);
		}
		
		i++;
	}
	cout<<"Minimum Spanning Tree Adj Matrix\n";
	cout<<"Total Length : "<<mst<<"\n";
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			cout<<minspantree[i][j]<<" ";
		}
		cout<<"\n";
	}
}
void menu()
{
	    cout<<"1.MST using Prims algorithm"<<endl;
		cout<<"2.MST using Kruskals algorithm"<<endl;
		cout<<"3.Exit"<<endl;
}
int main()
{
	cout<<"Enter Vertices : ";
	int v;cin>>v;
	vector<vector<int>> cost(v+1,vector<int>(v+1,-1));
	cout<<"Enter edges : ";
	int e;cin>>e;
	vector<pair<int,pair<int,int>>> edges;
	cout<<"Enter U,V,X:"<<endl;
	for(int i=0;i<e;i++){
		int U,V,X;
		
		cin>>U>>V>>X;
		cost[U][V]=X;
		cost[V][U]=X;
		edges.push_back({X,{U,V}});
	}
	
	while(true)
	{
		menu();
		int choice;
		cin>>choice;
		if(choice==1){
			prims(v,e,cost);
		}
		else if(choice==2){
			kruskal(v,e,cost,edges);
		}
		else if(choice==3){
			cout<<"Exit\n";
			
		}
		else
	    {
	    	cout << "Invalid Choice. Try again." ;
	    }
	}
	
}
