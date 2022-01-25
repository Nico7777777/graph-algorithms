#include<iostream>
#include<queue>
#include<bitset>
#include<vector>
#include<cmath>
#define NODURI_MAX 500
#define MUCHII_MAX NMAX*(NMAX-1)/2
using namespace std;

int n, m, i, j;
struct muchie{ int x, y, w; };
vector<muchie> lista_muchii;
vector<muchie> MST;
int comp_con[NODURI_MAX];

void merge(){
    for(i=0; i<m; i++){
        int j=i-1, val=lista_muchii[i].w, xul = lista_muchii[i].x, yul = lista_muchii[i].y;
        while( j>=0 and val<lista_muchii[j].w ){
            lista_muchii[j+1].w = lista_muchii[j].w;/*        |       */lista_muchii[j].w = val;
            lista_muchii[j+1].x = lista_muchii[j].x;/*        |       */lista_muchii[j].x = xul;
            lista_muchii[j+1].y = lista_muchii[j].y;/*        |       */lista_muchii[j].y = yul;
            j--;
        }
    }

}
void citire_date_si_initializare(){
    cout<<"n= "; cin>>n;
    cout<<"m= "; cin>>m;
    for(i=1; i<=m; i++){
        comp_con[i] = i; //AICI FAC COMPONENTELE CONEXE
        int x, y, w;
        cout<<"x, y, w =";
        cin >> x >> y >> w;
        lista_muchii.push_back( {x, y, w} );
    }
    //-------------SORTEZ DATELE---------------------------------------------------
    merge();//SORTEZ MUCHIILE CRESCATOR
    for (muchie element : lista_muchii)
        cout << element.x << " " << element.y << " " << element.w << "\n";
}
inline void reconexare(int newer, int older){
    for(i=1; i<=n; i++)
        if( comp_con[i] == older ) comp_con[i] = newer;
}
inline void afisare(){
    cout<<"\n\nMST:\n";
    for(muchie itr: MST)
        cout<<itr.x<<"-"<<itr.y<<"="<<itr.w<<"\n";
}
int main(){
    citire_date_si_initializare();
    int nr_muchii_selectate = 0;
    for (muchie itr : lista_muchii)
    {
        if (nr_muchii_selectate == n - 1)  break;

        if (comp_con[itr.x] != comp_con[itr.y])
        {
            cout<<"\nAm selectat muchia "<<itr.x<<"-"<<itr.y<<"\n";
            MST.push_back(itr);
            reconexare( comp_con[ min(itr.x, itr.y) ], max(itr.x, itr.y) );
            cout<<"iar componentele conexe au devenit ";
            for(i=1; i<=n; i++) cout<<comp_con[i]<<" ";
            cout<<"\n-------------------------------------\n";
            nr_muchii_selectate++;
        }
    }
    
    for(i=1; i<=n; i++) cout<<comp_con[i]<<" ";
    afisare();
}