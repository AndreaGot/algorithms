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

int zaino(vector< pair<int,int> > matrice, int C,int * x);

struct sort_pred {
    bool operator()(const std::pair<int,int> &left, const std::pair<int,int> &right) {
        return (left.first/left.second) > (right.first/right.second);
    }
};


//int morefrequent(vector<int> array);

int N,M,T;// N = #serate M = #sbalziumore T =#travestimenti

vector< pair<int,int> > matr;

int* vettoreGrande;
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


	
	int sumTeqN = 0;
	int k = 1;
	int s = 0;
	int numH = 0;
	int numJ = 0;

	for(int i = 0; i < N ; i++)
	{ 
		
		in>>store[0];
		
		cout<<store[0];
		
		
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
		
			
			if(store[j-1] == store[j])
				k++;
			else{
				valori[i].push_back(k);
				k = 1;	
				s++;
			}	

			
			
		}

		matr.push_back(std::make_pair(max(numH,numJ),1));

	

		

		sumTeqN += matr[i].first;
		
	
		if (k>0){
			valori[i].push_back(k);
			k = 1;
		}

		cout<< " con uno scambio : "<<matr[i].first<<"\n";
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
		cout<<"sto entrando \n";
			for(int i = N;i<N*15;i++)
			{
				matr.push_back(std::make_pair(calcolaSomma(valori[i%(N)],(i/(N))+1),i/(N)+1));
	
			
				cout<<"siamo serata "<<i%(N)<<" il valore è :"<<matr[i].first<<" e il peso è : "<<matr[i].second<<endl;
			}
		
	  std::sort(matr.begin(),matr.end(),sort_pred());

		
	
		int x[(N*15)-1];
		res = zaino(matr,T,x); //+ sumTeqN
	


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
				 
					return max(max(calcolaMax(array,k,i+2)+array[i],calcolaMax(array,k,i+1)),calcolaMax(array,k-1,i+1)+array[i]);
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


int zaino(vector< pair<int,int> > matrice, int C,int * x)
{
int w = C;
int i = 0;
int sum = 0;
for (int i = 0; i< matrice.size();i++)
	{
	x[i] = 0;

	}


	while(i<matrice.size() and w>0)
	{

	x[i] = min(w,matrice[i].second);
	w = w - x[i];
	
	sum += matrice[i].first;
		
	if(min(w,matrice[i].second) != w)
		{
		int diff = (N-(i));
		i+N;
		}
	else
	i++;
	}

	return sum;
}








