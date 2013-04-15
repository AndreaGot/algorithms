#include <fstream>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
struct nodo{
  vector<int> adj;
  int diam;
  int danonvisitare;
  int seen;
  
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
int FSTPERN;
int SNDPERN;
int filler;

vector<int> diametri;


int globalVal=1;
int result=500;
int howmany=0;
int precedente = 0;

void contanodi(vector<nodo>& grafo, int s,int e);

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
  bool primogiro = true;
  while(!q.empty()){
    cur=q.front();
    q.pop();
    distatt = grafo[cur].diam;
    if(distatt==diametri.size())
	if(primogiro){
	    diametri.push_back(cur);
	    primogiro = false;}
	else
	  {
		if(grafo[diametri[distatt-1]].adj.size()==1)
		{
			diametri.pop_back();
			diametri.push_back(cur);
		}

 	  }

    if(diametri.size()+1==distatt)
	  diametri.push_back(cur);
    

    for(int i=0;i<grafo[cur].adj.size();i++){
      int vic=grafo[cur].adj[i];
      if(grafo[vic].diam==-1 && grafo[cur].danonvisitare!=vic){
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
  
  return cur;
}
//
//-----------------------------------------------------------
//                           FINE BFS
//----------------------------------------------------------
//



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
    grafo[f].danonvisitare = -1;
    grafo[t].adj.push_back(f);
    grafo[t].danonvisitare = -1;
    grafo[t].seen = false;
  }
  //
  // FINE LETTURA FILE DI INPUT
  //


        FST = bfs(0);
        SND = bfs(FST);
        CENTRALE = ((diametri.size()-1)/2);
		PERNO = diametri[CENTRALE];

		contanodi(grafo,FST,PERNO);
		
	cout << FST << " primo estremo" << endl;
		cout << SND << " secondo estremo"<<endl;
		cout << PERNO << " perno"<<endl;



		grafo[PERNO].danonvisitare = precedente;
		grafo[precedente].danonvisitare = PERNO; 

		filler=bfs(FST);
		 CENTRALE = ((diametri.size()-1)/2);
		
		FSTPERN = diametri[CENTRALE];
			

		filler=bfs(SND);
		CENTRALE = ((diametri.size()-1)/2);
		SNDPERN = diametri[CENTRALE];

		ofstream out("output.txt"); 
		out<<PERNO<<" "<<precedente<<endl;
	    out<<FSTPERN<<" "<<SNDPERN;
	
	cout<<PERNO<<" "<<precedente<<endl;
	cout<<FSTPERN<<" "<<SNDPERN<<endl;

  return 0;
}










void contanodi(vector<nodo>& grafo, int s,int e)
{
	vector<int> couldBeLinked;   

    if (s==e){}
	
	grafo[s].seen=true;
	for (int i=0; i<grafo[s].adj.size();i++)
		{
			int nodo= grafo[s].adj[i];
			if (nodo == e)
				{

						result=globalVal;
						howmany=1;
						
						precedente=s;
							

				}
			else
				{
					if(grafo[nodo].seen==false)
					{
					couldBeLinked.push_back(nodo);
					}
				}
		}
    	
	    for (int i=0;i<couldBeLinked.size();i++)
		    {
		    contanodi(grafo,couldBeLinked[i],e);
		
		    }
    


}





