#include<bits/stdc++.h>
using namespace std;


int main()
{
	map< int , int > hm;
	int n,k;
	double maxentropychange,t,test;
	fstream f("database.txt",ios::in|ios::out);
	
	cout<<"\n***************** OUTLIER DETECTION USING GREEDY ALGORITHM *********************\n\n";
	cout<<"\t1.Enter the size of the database (number of vectors) : ";
	cin>>n;
	vector<int> database;
	int index,gg;
	for(int i=0;i<n;i++)
	{
		int temp;
		cout<<"\n\tEnter the enter the value of first attribute for vector "<<i+1<<" Of the database : ";
		cin>>temp;
		database.push_back(temp);
	}
	sort(database.begin(),database.end());
	
	int sum=0;
	vector<int> frequency;
	for(int i=0;i<n;i++)
	{
	     hm[database.at(i)]++;
		
	}
	
	vector<double> entropy;
	for(int i=0;i<n;i++)
	{
		entropy.push_back((-hm[database.at(i)]/n)*log(hm[database.at(i)]/n));
		
		
	}
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
		f<<entropy.at(i);
		f<<" ";
	} 
	
	double tentropy=0;
	for(int i=0;i<n;i++)
	{
		tentropy+=entropy.at(i);
	}
    int counter =0;
    //f.clear();
	//f.seekg(0);
    
    
    
	while(counter!=k)
	{
		
		f.clear();
		f.seekg(0);
		int ii=0;
		counter++;
		maxentropychange=0;
		while(ii!=n)
		{
	        test=entropy.at(ii);
			if(test>0)
			{
			 	if(fabs(tentropy-test)>maxentropychange)
			 	{
			 		maxentropychange=fabs(tentropy-test);
			 		t=test;
			 		
				 }
			}
			ii++;
		}
		
		for(int i=0;i<n;i++)
		{
			cout<<entropy.at(i)<<"\n";
			if(floor(entropy.at(i)-t)==0)
			{
				
				cout<<database.at(i);
				entropy.at(i)=-entropy.at(i);
			}
		}
		
		       //error..
		/*f.clear();
		f.seekg(0);
		
		ii=0;
		while(ii!=0)
		{
			test=entropy.at(ii)
			if(test==t)
			{
				entropy.at(ii)=-test;
				
				
				break;
			}
		}*/
		
	} 
	
	/*cout<<"\n\n";
	cout<<"\tOUTLIERS DETECTED ARE : ";
	for(int i=0;i<k;i++)
	{
		cout<<outlierset.at(i)<<" ";
	}
	
	 
	 f.close();
     cout<<"\n\n\n THE ABOVE PROGRAM CALCULATED OUTLIERS IN A TEXT FILE WITH HELP OF A FAST GREEDY ALGORITHM.. \n\n";
	*/return 0;
}
