#include<iostream>
#include<algorithm>
#include<queue>
#define NMAX 1000
#define MMAX NMAX*(NMAX-1)/2
using namespace std;

int n, m, i, j, x, y;
vector<int> adj[NMAX+1];
void bfs(int node){
    bool visited[n+1];
    for(i=1; i<=n; i++) visited[i] = false;
    queue<int> the_queue;
    the_queue.push(node);
    visited[node] = true;

    while( !the_queue.empty() ){
        for( auto itr: adj[the_queue.front()] )
            if( !visited[itr] ){
                the_queue.push(itr);
                visited[itr] = true;
            }
        cout<<the_queue.front()<<" ";
        the_queue.pop();
    }
}
void dfs_wrapped(int node, bool visited[]){
    cout<<node<<" ";
    for(auto itr : adj[node])
        if( !visited[itr] ){
            visited[itr] = true;
            dfs_wrapped(itr, visited);
        }
}
void dfs(int node){
    bool visited[n+1];
    for(i=1; i<=n; i++) visited[i] = false;
    visited[node] = true;
    dfs_wrapped(node, visited);
}
int main()
{
    cin >> n >> m;
    for(i=1; i<=m; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(i=1; i<=n; i++) sort( adj[i].begin(), adj[i].end() );
    cout<<"LISTA DE ADIACENTA E:";
    for(i=1; i<=n; i++){
        cout<<"\n"<<i<<": ";
        for(auto itr:adj[i]) cout<<itr<<" ";
    }
    cout<<"\n";
    dfs(1);
    bfs(1);
}