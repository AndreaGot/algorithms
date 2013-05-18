#include <iostream>
#include <fstream>
#include <vector>
#include <string>


using namespace std;

// array contiene la serata e k  contiene il numero di travestimenti +1
//esempio se passo 0 vorrà dire che metterò un solo vestito
int calcolaMax(vector<int> array,int k,int i);
int zainoguerrieri(int c,int i);

int N,M,T;// N = #serate M = #sbalziumore T =#travestimenti
int** matr;

vector<int> * valori;

int main()
{
	ifstream in("input.txt");
   	ofstream out("output.txt");
	string store;

	
	
	
	
	in>>N>>M>>T;
	valori = new vector<int>[N];
	
	
	store = new char[M];
	matr = new int* [(N*6)-1];

	int k = 1;
	int s = 0;

	for(int i = 0; i < N ; i++)
	{ 
		
		in>>store[0];
		
		cout<<store[0];

		
		for(int j= 1; j<M;j++)
		{
			
			in>>store[j];
			
			cout<<store[j];
		
			if(store[j-1] == store[j])
				k++;
			else{
				valori[i].push_back(k);
				k = 1;	
				s++;
			}			

		}

	

		if (k>0){
			valori[i].push_back(k);
			k = 1;
		}

	
		s = 0;
		cout<<" \n";

		/*for (int l = i*6;l<(i*6)+6;l++)
		{
		matr[l] = new int[T];
		
			for (int m = 0;m<T;m++)
			{

			
			matr[l][m] = -1;
				cout<<l<<" "<<m<<":"<<matr[l][m]<<"\n";
			}
		}
		*/
	
	}

	cout<<"Caricata matrice \n";

	int j;

	
	
	int prova=calcolaMax(valori[3],2,0);
	//cout<<prova<<"\n";

	int res=zainoguerrieri(T-1,0);
	
	cout<<res;
}


int calcolaMax(vector<int> array,int k, int i)
{
	if(k<=0)
		return 0;
	else
		{
			if(i<array.size())
				{
				 return max(calcolaMax(array,k,i+2)+array[i],calcolaMax(array,k-1,i+1)+array[i]);
				}
		}			
	return 0;
}

int calcolaSomma(vector<int> array,int k)
{
	if(array.size()==k)
		{
		return M;
		}
	else if (k>array.size())
		{
	    		return -100;
		}else
		{
			return calcolaMax(array,k,0);
		}

}

int zainoguerrieri(int c,int i)
{
	//cout<<c<<" \n";
	//cout<<i<<" "<<N*6<<"\n";
	
	if (c<0){
		return -100000;
		}
	if (i==N*6)
		{
		return 0 ;
		}
	if (matr[i][c] != -1)
		{
		return matr[i][c];
		}

	int p = i/6; 
	int v =i%6;
	int diff = 6-v;
	
	matr[i][c] = max(calcolaSomma(valori[p],v)+zainoguerrieri(c-v,i+diff),zainoguerrieri(c,i+1));
	
	cout<<"matri["<<i<<"]["<<c<<"] = "<<matr[i][c]<<"\n";
	cout<<c<<" "<<i<<" "<<N*6<<"\n ";
	return matr[i][c];

}
