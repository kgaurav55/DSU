// DSU    
// find and merge functionality 
// lets code it out okay 
#include<bits/stdc++.h>
using namespace std;
 int n=5;
 vector<int> parent(n);
 vector<int> sz(n);
int find(int u)
{
    // the parent of root node will the node itself
    if(parent[u]==u)
     return u;
     //this is a very intresting recursion 
     // it is actually modifienfg the parent array 
     //in a path only 
     else
        return parent[u]=find(parent[u]);
}
void merge(int u, int v)
{
   u=find(u);// representatve of node u
   v=find(v);// reperentative of node v
   // what if two nodes belongs to the same compo.
   if(u==v)
    return;
    else
    {  // u forest is greater in size 
       // and v is smaller in size 
        if(sz[u]>sz[v])
         {
        // add smaller size forest to the lager size forest
         parent[v]=u;
         sz[u]+=sz[v];
         } 
         else
         {
             parent[u]=v;
            
             sz[v]+=sz[u];
         }
    }
}
int main() {
// let's say we have 5 nods from 0,1,2,3,4,5;
  for(int i=0;i<n;i++)
    {
       parent[i]=i;
       sz[i]=1;
    }
    
  merge(0,1);
  merge(2,3);
  merge(0,2);
 
  for(int i=0;i<n;i++)
    {
      cout<<i<<":" <<parent[i]<<"\n";
      cout<<i<<":"<<sz[i]<<"\n";
    }
    
    merge(3,4);
    
    cout<<"after merge \n";
    for(int i=0;i<n;i++)
    {
      cout<<i<<":" <<parent[i]<<"\n";
      cout<<i<<":"<<sz[i]<<"\n";
    }
    
    cout<<"find"<<find(0);
    
    return 0;
    
}