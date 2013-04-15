#include <fstream>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
struct nodo{
  vector<int> adj;
  int diam;
  int danonvisitare;
  int visitato;
  
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
vector<int> percorso;
bool trovato = false;

int dammipercorso(vector<nodo>& grafo, int s,int e,int counter);

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
  while(!q.empty()){
    cur=q.front();
    q.pop();
    distatt = grafo[cur].diam;
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
  cout<<endl;
  return cur;
}
//
//-----------------------------------------------------------
//                           FINE BFS
//----------------------------------------------------------
//



int main(void)
{
  int contatore=1;
  int successivo=0;
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
    grafo[t].visitato = 0;
  }
  //
  // FINE LETTURA FILE DI INPUT
  //


        FST = bfs(0);
        SND = bfs(FST);

	//inizializzo gli elementi per ottenere il percorso
		percorso.clear();
   		percorso.push_back(FST);
   		dammipercorso(grafo,FST,SND,contatore);
   		trovato = false;
		contatore++;
		/*contanodi(grafo,FST,PERNO);*/
	// ora ho il percorso dal 

	
	//
	// divido l'array nel miglior modo a seconda della lunghezza percorso
	//
	if (percorso.size()%2==1)
	{
		CENTRALE = ((percorso.size()-1)/2);
			
	}else //il percorso è di lunghezza pari
	{
		if ((percorso.size()/2)%2 ==0)
		{
			CENTRALE = ((percorso.size()-1)/2)+1;
		}else
		{
			CENTRALE = ((percorso.size()-1)/2);
		}
	}
	//
	// ora l'array è diviso
	//
	
	    PERNO = percorso[CENTRALE];
		
	
		cout << FST << " primo estremo" << endl;
		cout << SND << " secondo estremo"<<endl;
		cout << PERNO << " perno"<<endl;

		// spezzo l'array
		successivo = percorso[CENTRALE+1];				
		grafo[PERNO].danonvisitare = successivo;
		grafo[successivo].danonvisitare = PERNO; 
		cout<<successivo<<endl;
		//trovo il più lontano da FST
		filler=bfs(FST);
		cout<<filler<<endl;
		//inizializzo gli elementi per ottenere il percorso di una metà
		percorso.clear();
   		percorso.push_back(FST);
   		dammipercorso(grafo,FST,filler,contatore);
   		trovato = false;
		contatore++;

		CENTRALE = ((percorso.size()-1)/2);
		
		FSTPERN = percorso[CENTRALE];
			
		//trovo il più lontano da SND
		filler=bfs(SND);

		//inizializzo gli elementi per ottenere il percorso di una metà
		percorso.clear();
   		percorso.push_back(FST);
   		dammipercorso(grafo,SND,filler,contatore);
   		trovato = false;
		contatore++;

		CENTRALE = ((percorso.size()-1)/2);
		
		SNDPERN = percorso[CENTRALE];
		

		ofstream out("output.txt"); 
		out<<PERNO<<" "<<successivo<<endl;
	    out<<FSTPERN<<" "<<SNDPERN;
	
	cout<<PERNO<<" "<<successivo<<endl;
	cout<<FSTPERN<<" "<<SNDPERN<<endl;

  return 0;
}





int dammipercorso(vector<nodo>& grafo, int s,int e,int counter)
{
   
   if (grafo[s].visitato==counter)          //se il nodo è già stato visitato..
	{										//
	   return 0;							//..esci   
	}
   grafo[s].visitato = counter;				//marca come visitato il nodo di partenza
   
   int nodo_passaggio;
  
   if (grafo[s].adj.size()>0)
	{
	
	
	   for(int i = 0; i<grafo[s].adj.size();i++)				
		{
			 nodo_passaggio=grafo[s].adj[i];
			if(nodo_passaggio==e)							// se il nodo dove andare corrisponde al nodo di arrivo..
			{												//
			grafo[nodo_passaggio].visitato=counter;			//..marcalo come visitato..
			percorso.push_back(nodo_passaggio);				//..e aggiungilo a un vettore che salverà il percorso..
			trovato = true;									//..infine esci dalla funzione
  			 	
			return 0;
			}else if(grafo[nodo_passaggio].visitato!=counter && grafo[s].danonvisitare!=nodo_passaggio)
			{
			    percorso.push_back(nodo_passaggio);						// aggiungi il nodo all'array del percorso (uno dei possibili)..
																		//
		            dammipercorso(grafo,nodo_passaggio,e,counter);		// e richiama la funzione (per espandere il percorso)
			
			if (trovato ==false)										// se la funzione arriva qui significa che il percorso non è quello giusto..
			{															// 
			    percorso.pop_back();									// quindi togli il nodo precedentemente inserito nell'array
			 } else														
			   {return 0;}												//se trovato è true, il nodo è stato trovato (finisce la funzione)
			}
			
		}
	
	}else
	{
	   return 0;
	}
    	
}



