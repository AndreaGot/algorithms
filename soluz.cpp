#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

// array contiene la serata e k  contiene il numero di travestimenti +1
//esempio se passo 0 vorrà dire che metterò un solo vestito
int calcolaMax(vector<int> array,int k,int i);
int zainoguerrieri(int c,int i);
int calcolaSomma(vector<int> array,int k);
int morefrequent(vector<int> array);

int N,M,T;// N = #serate M = #sbalziumore T =#travestimenti
int** matr;
bool primocambio;

vector<int> * valori;

int main()
{
	ifstream in("input.txt");
   	ofstream out("output.txt");
	string store;

	
	
	
	
	in>>N>>M>>T;
	valori = new vector<int>[N];
	
	
	store = new char[M];
	matr = new int* [(N*7)-1];

	int k = 1;
	int s = 0;

	for(int i = 0; i < N ; i++)
	{ 
		
		in>>store[0];
		
	//	cout<<store[0];

		
		for(int j= 1; j<M;j++)
		{
			
			in>>store[j];
			
		//	cout<<store[j];
		
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
		//cout<<" \n";

		/*
		for(int e = 0;e<valori[i].size();e++)
		{

		cout<<" "<<valori[i][e];

		}	*/
		// struttura da rivedere.... Troppo sovradimensionata

		//cout<<"\n";
		for (int l = i*7;l<(i*7)+7;l++)
		{
		matr[l] = new int[T+1];
		
			for (int m = 0;m<=T;m++)
			{

			
			matr[l][m] = -1;
			//	cout<<l<<" "<<m<<":"<<matr[l][m]<<"\n";
			}
		}
	
	
	}

	int j;
	//cout<<" fin qui \n" ;

	//--------------------------- error checking
	/*	
	vector<int> tried;
	for (int i = 0; i<N;i++)
		{		
			tried.push_back(calcolaSomma(valori[i],3));
			cout<<tried[i]<<"\n ";
		}

	sort(tried.begin(),tried.end());
	int sum = 0;
	for(int i = 0; i< T;i++)
		{
		sum +=tried[i];
		
		}
	cout<<sum;*/
	//------------------------------end error checking
	
	int res=zainoguerrieri(T,0);
	
	cout<<res;
	out<<res;
}

// modificata
int calcolaMax(vector<int> array,int k, int i)
{
	if(k<=0)
		return 0;
	else
		{
			if(i<array.size())
				{
				if (!primocambio)
					return max(calcolaMax(array,k,i+2)+array[i],calcolaMax(array,k-1,i+1)+array[i]);
				else
					{
					primocambio  = false;
					return max(calcolaMax(array,k,i+2)+array[i],calcolaMax(array,k,i+1));
					
					}
				}
		}			
	return 0;
}

int calcolaSomma(vector<int> array,int k)
{
	if(array.size()==k)
		return M;
	else if (k>array.size())
		{
	    		return M;
		}else if ( k == 0)
		{ 	return 0;
		}
		else if(k==1)
		{
			return morefrequent(array);
		}
		{
			primocambio = true;
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
	if (i==N*7)
		{
		return 0 ;

		}
	if (matr[i][c] != -1)
		{
		return matr[i][c];
		}

	int p = i/7; 
	int v =(i%7);
	int diff = (7-v);
	
	matr[i][c] = max(calcolaSomma(valori[p],v)+zainoguerrieri(c-v,i+diff),zainoguerrieri(c,i+1));
	
	//cout<<"matri["<<i<<"]["<<c<<"] = "<<matr[i][c]<<"\n";
	//cout<<c<<" "<<i<<" "<<N*5<<"\n ";
	return matr[i][c];

}

int morefrequent(vector<int> array){
	int sumpari = 0;
	int sumdispari = 0;
	for(int i = 0;i<array.size();i++)
	{
		if(i%2==0)
		{
			sumpari += array[i];
		}else
		{
			sumdispari += array[i];
		}
	}

	return max(sumpari,sumdispari);
}
