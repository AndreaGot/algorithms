using namespace std;

#include <iostream>
#include <fstream>
#include <vector>




int main()
{
	
	int N = 0;
	int m = 0;
	int max = 0;
	int i = 0;
	vector<int> parz;
	vector<int> valori;
	ifstream in("input.txt");
	ofstream out("output.txt");
	in>>N;
	while(! in.eof())
	{
	in>>m;
	valori.push_back(m);
	}
	
	parz.push_back(valori[0]);
	i=1;
	while(i<N)
	{
		max=0;
		int j = 0;
		while(j<i)
		{
			if(valori[j]<=valori[i])
			{
				if(parz[j]>max)
				{
					max=parz[j];
				}
			}
			j++;
		}
		parz.push_back(max + valori[i]);
		i++;
	}
	
	max = 0;
	for(i=0;i<parz.size();i++)
	{
		if(parz[i]>max)
		{
			max = parz[i];
		}
	}
	
	out<<max;
		
	

	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
