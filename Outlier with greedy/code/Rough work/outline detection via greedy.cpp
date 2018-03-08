#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n,k;
	int maxentropychange,test,median=0,t;
	fstream f("database.txt",ios::in|ios::out);
	
	cout<<"\n***************** OUTLIER DETECTION USING GREEDY ALGORITHM *********************\n\n";
	cout<<"\t1.Enter the size of the database : ";
	cin>>n;
	vector<int> database;
	for(int i=0;i<n;i++)
	{
		int temp;
		cout<<"\n\tEnter the enter the value number "<<i+1<<" Of the database : ";
		cin>>temp;
		database.push_back(temp);
	}
	sort(database.begin(),database.end());
	if(n%2==0)
	median=floor((database.at((n/2)-1)+database.at((n/2)))/2);
	else
	median=database.at(((n+1)/2)-1);
	//after sorting the result we will enter it in the database.
	cout<<"\n\tEnter the number of Outliers to be detected : ";
	cin>>k;
	if(k>n)
	{
		cout<<"\n\tOutliers cant be more than the number of elemnts itself.....abort";
		exit(0);
	}
	vector<int> outlierset;        //initially all the values in the database are considered as non ouliers and the oulier set is empty..
	//now we will feed the values in a text file which will act as our database ...
	for(int i=0;i<n;i++)
	{
		f<<database.at(i);
		f<<" ";
	} 
    int counter =0;
    //f.clear();
	//f.seekg(0);
    
    
    
	while(counter!=k)
	{
		
		f.clear();
		f.seekg(0);
		
		counter++;
		maxentropychange=0;
		while(f>>test)
		{
			
			if(test>0)
			{
			 	if(fabs(median-test)>maxentropychange)
			 	{
			 		maxentropychange=fabs(median-test);
			 		t=test;
			 		
				 }
			}
		}
		
		
		outlierset.push_back(t);
		f.clear();
		f.seekg(0);
		
		
		while(f>>test)
		{
			
			if(test==t)
			{
				test=-test;
				f.seekg(-1,ios::cur);
				f<<test;
				break;
			}
		}
		
	} 
	cout<<"\n\n";
	cout<<"\tOUTLIERS DETECTED ARE : ";
	for(int i=0;i<k;i++)
	{
		cout<<outlierset.at(i)<<" ";
	}
	
	 
	 f.close();
     cout<<"\n\n\n THE ABOVE PROGRAM CALCULATED OUTLIERS IN A TEXT FILE WITH HELP OF A FAST GREEDY ALGORITHM.. \n\n";
	return 0;
}
