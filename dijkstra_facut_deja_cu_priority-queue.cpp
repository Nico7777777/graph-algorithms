#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dim = 1e6;
const long long inf = 1e6 + 1;

long long dist[dim];
int tata[dim];
bool viz[dim];
vector<int> traseu;
int x, y, cost, i, nod_start, nod_fin;
long long d;
int n, m; /// n noduri, m muchii
vector<pair<int, int>> G[dim];

inline int citeste_rapid()
{
    char lit;
    lit = getchar();
    while (lit == '\n' || lit == ' ')
        lit = getchar();

    int val = 0;
    while (lit >= '0' && lit <= '9')
    {
        val = (val << 1) + (val << 3) + (lit - '0');
        lit = getchar();
    }
    return val;
}

void afiseaza_graf()
{
    cout << "Lista de adiacenta, cu <nod, cost>:" << endl;
    int i, j;
    for (i = 1; i <= n; ++i)
    {
        cout << i << " :  ";
        for (j = 0; j < G[i].size(); ++j)
            cout << "(" << G[i][j].first << ", " << G[i][j].second << ")  ";
        cout << endl;
    }
}
void afiseaza_solutie(int nod_start, int nod_fin){
    if (tata[nod_fin] == 0)
        cout << "-1";
    else
    {
        int temp = nod_fin;
        while (temp != nod_start) /// cat timp inca nu am ajuns la nodul de start
        {
            traseu.push_back(temp);
            temp = tata[temp];
        }
        traseu.push_back(nod_start); /// Bag si nodul de start

        cout << "traseu: ";
        for (i = traseu.size() - 1; i >= 1; --i)
            cout << traseu[i] << "->"; cout << traseu[0];
    }
    cout << "\nDistanta totala: " << dist[n];
}
void init()
{
    cout << "n= "; n = citeste_rapid();
    cout << "m= "; m = citeste_rapid();
    cout<<"introdu nodul de start: "; nod_start = citeste_rapid();
    cout<<"introdu nodul de final: "; nod_fin = citeste_rapid();
    //-----------------------------------------------------------
    cout << "distante initiale: ";
    for (i = 1; i <= n; ++i)
        dist[i] = inf, cout << dist[i] << " ";
    cout << "\n";
    for (i = 0; i < m; ++i)
    {
        cout << "x, y, w= ";
        x = citeste_rapid();
        y = citeste_rapid();
        cost = citeste_rapid();
        G[x].push_back({y, cost});
        G[y].push_back({x, cost});
    }
}
int main()
{
    init();
    // afiseaza_graf();

    priority_queue<pair<long long, int>> q; /// <cost curent, celalalt nod al muchiei>

    /// Bag nodul de start, nodul 1 DE OBICEI. Are costul 0 pana la el. Trebuie sa ajung la nodul n.
    q.push({0, nod_start});
    while ( !q.empty() )
    {
        int nod = q.top().second;
        // cout << "Sunt la nodul " << nod << endl; cin.get();
        q.pop();

        if (viz[nod] == true) // daca e deja vizitat SARIM PESTE EL
            continue;

        viz[nod] = true;//daca nu e vizitat, ee il vizitam acuma
        if (nod == n) break;

        for (i = 0; i < G[nod].size(); ++i) /// Parcurg toti vecinii din lista de adiacenta
        {
            int vecin = G[nod][i].first;
            if (dist[nod] != inf)
                d = dist[nod] + G[nod][i].second; /// Distanta pana la tata + costul pana la fiu
            else
                d = G[nod][i].second;

            cout << "       Analizez fiul " << vecin << " al parintelui "<< nod << endl;
            cout << "       care aduce costul " << G[nod][i].second << endl;
            cin.get();

            cout << "           Distanta anterioara pana la " << vecin << " este: " << dist[vecin] << endl;
            cout << "           Distanta temporara  pana la " << vecin << " este: " << d << endl;
            cin.get();

            if (dist[vecin] > d) /// Daca obtin un cost mai mic
            {
                cout << "Bag fiul " << vecin << endl;
                dist[vecin] = d;
                tata[vecin] = nod;
                q.push({-d, vecin});
            }
        }
    }
    afiseaza_solutie(nod_start, nod_fin);
    return 0;
}