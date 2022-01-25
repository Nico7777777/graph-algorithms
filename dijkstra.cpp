#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define INFINITE (int)2e32
#define NMAX 10000
#define edge pair<int, int>
using namespace std;

int distances[NMAX], parent[NMAX]; //presupunem ca ponderea maxima este de 500 => distanta maxima posibila
//este NMAX*PONDMAX = 5*10^6 => INTRA IN INT
int i, j, n, m, x, y, w, commence, fin;
vector< edge >adjacency[NMAX]; // primul element e varful adiacent, iar al doilea e ponderea
edge element;
bool visited[NMAX];

void init();
void Dijkstra(int start, int stop);
void showGraph();
void showSolution(int start, int stop);

int main(){
    init();
    cout<< "start:"; cin >>commence;
    cout<< "stop:"; cin >>fin;
    //showGraph();
    Dijkstra(commence, fin);
    showSolution(commence, fin);
}

void Dijkstra(int start, int stop){

    queue< pair<int, int> >q;
    int temp_dist;
    q.push( {start, 0} );
    while( !q.empty() ){
        int nod_curent = q.front().first;
        q.pop();
        if( !visited[nod_curent] ){
            visited[nod_curent] = true;
            if(nod_curent == stop) break;
            for(auto vecin: adjacency[nod_curent] ){
                if( distances[ vecin.first ] != INFINITE ) // primul element e varful adiacent, iar cel de al doilea e ponderea
                    temp_dist = distances[ nod_curent ] + vecin.second;
                else temp_dist = vecin.second;
            
                if( distances[ vecin.first ] > temp_dist ){
                    distances[ vecin.first ] = temp_dist;
                    parent[ vecin.first ] = nod_curent;
                    q.push( {vecin.first, -temp_dist} );
                }
            }
        }
    }
    for(i=1; i<=n; i++)cout<<"parent["<<i<<"]="<<parent[i]<<"\n";
    
}
void showSolution(int start, int stop){
    if( !parent[stop] ) cout<<"NU EXISTA";
    else{
        vector<int> traseu;
        int nod = stop;
        while(nod != start){
            traseu.push_back(nod);
            nod = parent[ nod ];
        }
        traseu.push_back(start);

        while( traseu.size() > 1 ){
            cout<< traseu.back() <<"->";
            traseu.pop_back();
        }
        cout<<traseu[0];    traseu.pop_back();
    }
}
void init(){
    cout<<"n= "; cin >> n;
    cout<<"m= "; cin >> m;
    for(i=1; i<=m; i++){
        cout<<"\nx, y, w= "; cin >> x >> y >> w;
        adjacency[x].push_back( {y, w} );
        adjacency[y].push_back( {x, w} );
    }
    for(i=1; i<=n; i++){
        distances[i] = INFINITE;
        parent[i] = 0;
    }
}
void showGraph(){
    for(i=1; i<=n; i++){
        cout<<"\n"<< i <<": ";
        for( auto element: adjacency[i] )
            cout<<element.first<<" ";

    }
}