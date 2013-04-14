 #include <fstream>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
struct nodo{
  vector<int> adj;
  int diam;
  int padre;
  bool danonvisitare;
  
};
vector<nodo> grafo;
int FST;
int SND;
int nodomax;
int nodomin;
int maxdist;
int mindist;
int PERNO;
int CENTRALE;
int N,M;
int PERNPREC;

vector<int> diametri;

//
//-----------------------------------------------------------
//                BFS CHE FUNZIONA SICURAMENTE
//----------------------------------------------------------
//
int bfs(int st){
  diametri.clear();
  //All'inizio ogni nodo ha distanza -1, a parte il nodo di partenza
  for(int i=0;i<N;i++)
    grafo[i].diam=-1;
  grafo[st].diam=0;
  //Coda per la visita
  queue<int> q;
  q.push(st);
  int cur;
  int distatt;
  while(!q.empty()){
    cur=q.front();
    q.pop();
    distatt = grafo[cur].diam;
    if(diametri.size()+1==distatt)
	  diametri.push_back(cur);
    for(int i=0;i<grafo[cur].adj.size();i++){
      int vic=grafo[cur].adj[i];
      if(grafo[vic].diam==-1 && grafo[vic].danonvisitare==false){
        //Se un vicino non é ancora stato visitato, imposto la sua distanza.
        grafo[vic].diam=grafo[cur].diam+1;
        q.push(vic);
		 
      }
    }
  }

  if(grafo[cur].diam>maxdist)
  {
  nodomax = st;
  maxdist = grafo[cur].diam;
  }
  if(grafo[cur].diam<mindist)
  {
  nodomin = st;
  mindist = grafo[cur].diam;
  }

  grafo[st].diam = grafo[cur].diam; //diametro del nodo
 //nodo più distante (uno dei tanti con il diametro maggiore)
  for(int i=0;i<diametri.size();i++)
    cout<<diametri[i];
  cout<<endl;
  return cur;
}
//
//-----------------------------------------------------------
//                           FINE BFS
//----------------------------------------------------------
//


int sali(int partenza, int arrivo);






int main(void)
{
  
  //
  // LETTURA FILE DI INPUT
  //
  ifstream in("input.txt");
  
  in>>N>>M;
  grafo.resize(N);
  mindist = M+1;
 
  //Lettura del grafo
  for(int i=0;i<M;i++){
    int f,t;
    in>>f>>t;
    grafo[f].adj.push_back(t);
    grafo[f].danonvisitare = false;
    grafo[t].adj.push_back(f);
  }
  //
  // FINE LETTURA FILE DI INPUT
  //


        FST = bfs(0);
        SND = bfs(FST);
        CENTRALE = (diametri.size())/2;
		PERNO = diametri[CENTRALE];
		
		for(int i =0;i<N;i++)
			cout<<grafo[i].danonvisitare;

		
  
  return 0;
}






