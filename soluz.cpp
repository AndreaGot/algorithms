#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


// array contiene la serata e k contiene il numero di travestimenti
int calcolaMax(string array,int k);

int main()
{
	ifstream in("input.txt");
   	ofstream out("output.txt");
	string* store;

	int N,M,T;// N = #serate M = #sbalziumore T =#travestimenti
	vector<int>* valori = new vector<int>[N];
	
	
	in>>N>>M>>T;
	store = new string [N];

	


	int k = 1;
	int s = 0;
	for(int i = 0; i < N ; i++)
	{ 
		store[i] = new char[M];
		in>>store[i][0];

		for(int j= 1; j<M;j++)
		{
			
			in>>store[i][j];
			
			cout<<store[i][j];
		
			if(store[i][j-1] == store[i][j])
				k++;
			else{
				valori[i].push_back(k);
				k = 1;	
				s++;
			}
			
		}

		if (k>0){
			valori[i].push_back(k);
			k = 0;
		}

	
		s = 0;
		cout<<" \n";
	
	}

	

	for (int i = 0; i<N;i++)
		{

			int j = 0;	
	
			cout<<"sono alla posizione"<<i<<" ";
			while (j < valori[i].size())
			{
				cout<<valori[i][j]<<" ";
			
				j++;
			}
			cout<<"\n";
		}

	calcolaMax(store[2],2);

}

int calcolaMax(string array,int k )
{
	if(k<0)
		return -20;
	else
		{
			



	}


}
