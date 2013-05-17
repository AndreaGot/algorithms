#include <iostream>
#include <fstream>
#include <vector>
#include <string>


using namespace std;
int prova;

// array contiene la serata e k  contiene il numero di travestimenti +1
//esempio se passo 0 vorrà dire che metterò un solo vestito
int calcolaMax(vector<int> array,int k,int i);

int main()
{
	ifstream in("input.txt");
   	ofstream out("output.txt");
	string store;

	int N,M,T;// N = #serate M = #sbalziumore T =#travestimenti
	vector<int>* valori = new vector<int>[N];
	
	
	in>>N>>M>>T;
	
	

	
	store = new char[M];
	//int prova = 0;
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

		delete store;

		if (k>0){
			valori[i].push_back(k);
			k = 1;
		}

	
		s = 0;
		cout<<" \n";
	
	}

	int j;

	for (int i = 0; i<N;i++)
		{

			j = 0;	
	
			cout<<"sono alla posizione"<<i<<" ";
			while (j < valori[i].size())
			{
				cout<<valori[i][j]<<" ";
			
				j++;
			}
			cout<<"\n";
		}

	
	prova=calcolaMax(valori[3],2,0);
	cout<<prova<<"\n";


	
}


int calcolaMax(vector<int> array,int k, int i)
{
	if(k<0)
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
