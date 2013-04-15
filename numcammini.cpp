#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct nodo{
  vector<int> vic;
  bool visitato;
};

vector<nodo> grafo;

int globalVal=1;
int result=500;
int howmany=0;
int precedente = 0;

void contanodi(vector<nodo>& grafo, int s,int e);

int main()
{
   ifstream in("input.txt");
   ofstream out("output.txt");
   int N,M,S,E;
   int nodo_part;
   int nodo_arr;
   int minimo=0;
   int numcammini=0;


   in>>N>>M>>S>>E;
   grafo.resize(N);
   for(int i=0;i<M;i++)
      {
     in>>nodo_part;
	 in>>nodo_arr;
	 grafo[nodo_part].vic.push_back(nodo_arr);
	 grafo[nodo_part].visitato=false;
   }
   
    contanodi(grafo,S,E);

    out<<result<<" "<<howmany;
	cout<<precedente<<" "; //qui stampa il nodo precedente all'arrivo ;)
   return 0;

}

void contanodi(vector<nodo>& grafo, int s,int e)
{
	vector<int> couldBeLinked;   

    if (s==e){globalVal=0;}
    if (globalVal<=result)
    {
	for (int i=0; i<grafo[s].vic.size();i++)
		{
			int nodo= grafo[s].vic[i];
			if (nodo == e)
				{
					if (globalVal<result)
						{
						result=globalVal;
						howmany=1;
						precedente = s;
						}else if(globalVal==result)
						{
						howmany++;
						}
				}
			else
				{
					couldBeLinked.push_back(nodo);
				}
		}

    
	    for (int i=0;i<couldBeLinked.size();i++)
		    {
		    globalVal++;
		    contanodi(grafo,couldBeLinked[i],e);
		    globalVal--;
		    }
    }
}





