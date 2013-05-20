#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

// array contiene la serata e k  contiene il numero di travestimenti +1
//esempio se passo 0 vorrà dire che metterò un solo vestito
int calcolaMax(vector<int> array,int k,int i);
//int zainoguerrieri(int c,int i);

int calcolaSomma(vector<int> array,int k);
int recursiva(int i, int j, int C);
int recursiveOneColumn(int i, int C);

//int morefrequent(vector<int> array);

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
	matr = new int* [N];
	
	int sumTeqN = 0;
	int k = 1;
	int s = 0;
	int numH = 0;
	int numJ = 0;

	for(int i = 0; i < N ; i++)
	{ 
		
		in>>store[0];
		
		cout<<store[0];
		
		matr[i] = new int[M/2+1];
		numH = 0;
		numJ = 0;	

		if(store[0]=='H')
				numH++;
		if(store[0]=='J')
				numJ++;	
		
		for(int j= 1; j<M;j++)
		{
			
			in>>store[j];
			
			cout<<store[j];

			if(store[j]=='H')
				numH++;
			else
				numJ++;
		
			if(j<=M/2)
				{matr[i][j] = -1;}
	
		
		
			if(store[j-1] == store[j])
				k++;
			else{
				valori[i].push_back(k);
				k = 1;	
				s++;
			}			
			
		}

		matr[i][0] = max(numH,numJ);
		sumTeqN += matr[i][0];
		
	
		if (k>0){
			valori[i].push_back(k);
			k = 1;
		}

		cout<< " con uno scambio : "<<matr[i][0]<<"\n";
		//cout<<" e con 2: " << calcolaSomma(valori[i],2)<<"\n";
		s = 0;
	}

	int res= 0;
	
	if(T==N)
	{
		out<<sumTeqN;
		cout<<sumTeqN;
	}else 
	{
		if (T<N)
		{
		res = recursiveOneColumn(0,T);
		}else
		{
		cout<<"sto entrando \n";
		res = recursiva(0,1,T-N);
		cout<<" sono uscito \n";
		}

		out<<res;
		cout<<"\n"<<res<<"\n";
	}
	//int j;
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
		else
		{
			primocambio = true;
			return calcolaMax(array,k,0);
	
		}
}


int recursiva(int i, int j, int C)
{

	int sum = 0;

	if(C<0){

		cout<<"minore di c";
		return -100000;
		
		}
	if(j>=M/2)
		{
		
		cout<<"maggiore di M/2";
		return -100000;

		}
	if(i>=N){
		
		cout<<"maggiore di N";
		return -100000;
		}
	if(matr[i][j]==-1)
		{
		
		
			matr[i][j] = calcolaSomma(valori[i],j+1);
	
	
		}


cout<<"Matrice ["<<i<<"]["<<j<<"]"<<" = "<<matr[i][j]<<"\n";
	
	
	return  max( max( matr[i][j] + recursiva(i,j+1,C-1) , matr[i][j] + recursiva(i-1,j,C-j) ),recursiva(i+1,j,C)) ;
	

}


int recursiveOneColumn(int i, int C){
	if(C<0)
		return -100000;
	if(i>=N)
		return -1;

	return max(matr[i][0] + recursiveOneColumn(i+1,C-1),recursiveOneColumn(i+1,C));


}
