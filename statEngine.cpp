// statEngine
#include"classes.h"

int statEngine::get_highest_pop(country& g,long int (country::*getter)(int), int i)// recieving an object and function as a parameter 
{
	long int hp= (g.*getter)(i);
	int index=0;		
	while(i<countryCount)
	{	
		long int new_pop=(g.*getter)(i);
		if(new_pop>hp)
		{
			hp=new_pop;
			index=i;
		}
		i++;
	}
	return index;
}

int statEngine::least_pop_index(country& g,long int (country::*getter)(int), int i)// recieving an object and function as a parameter 
{
	long int lp= (g.*getter)(i);
	int index=0;		
	while(i<countryCount)
	{	
		long int new_pop=(g.*getter)(i);
		if(new_pop<lp)
		{
			lp=new_pop;
			index=i;
		}
		i++;
	}
	return index;
}

long long int statEngine::sum_cont_pop(string cnt,country& g,long int (country::*getter)(int), int i)
{
	long long int pop;

	for(int a=0;a<continent_count;a++){

	if(cnt==continents[a])
	{
		
		while(i<countryCount)
		{
		
			if(getcontinet(i)==cnt)
			{
				pop+=(g.*getter)(i);
			}
			i++;
		}
		return pop;
		
	}
	
	}
	return 0;
}


float statEngine::Maximum_gr()
{
   	int i =0;
   	float  Hgr =stof(getgrowth_rate(i));
   	while(i< countryCount)
	{
   		float gr= stof(getgrowth_rate(i));
   		if(gr> Hgr)
		{
   			Hgr = gr;
		}
		i++;
	}
	return Hgr;   
}

float statEngine::Minimum_gr()
{
   	int i =0;
   	float  Lgr =stof(getgrowth_rate(i));
   	while(i< countryCount)
	{
   		float gr= stof(getgrowth_rate(i));
   		if(gr< Lgr)
		{
   			Lgr = gr;
		}
		i++;
	}
	return Lgr;   
}


bool statEngine::duplicate_checker(string cnt)
{
	int i=0;
	
	while(i<continent_count)
	{
		if(continents[i]==cnt)
		{
			return true;
		}
		i++;
	}
	return false;
}

void statEngine::loadcontinents()
{
	continent_count=0;
	continents.clear();
	
	int i=1;
	string new_cnt; // declaring a container to store new continent name in every iteration
	bool state;
	continents.push_back(getcontinet(0)); //initialising the vector's 1st continent from the vector countries
	continent_count++;// increamenting count with 1
	do
	{
		new_cnt=getcontinet(i); //get a new continent every iteration to be compared
		state=duplicate_checker(new_cnt);// checking if the continent is already loaded in the vector
		
		if(state==false)// load the continent if its not in the vector
		{
			continents.push_back(new_cnt);
			continent_count++;	
		}
	
		i++;
	}while(i<countryCount);
}




	void statEngine::group_by_continent(){// group_by_continent
		loadcontinents();
		
	//create nested loop with the outer one looping through continents while the inner one looping through countries
	for(int i=0;i<continent_count;i++){	
	int count=0;
    long long int tpop=0;
	long double avpop=0;
	int tdens=0;
	long double avdens=0;
	float tGrowthRate=0;
	float avGrowth_rate=0;
	for(int j=0;j<countryCount;j++){
		if(getcontinet(j)==continents[i])
		{
			 count++;
			 tpop+= getpop23(j);
			 tdens+=getdensity(j);
			 string c=getgrowth_rate(j);
			 string p;
			 float gr;
			 stringstream ss(c);
			 ss>>gr>>p;
			 tGrowthRate+= gr;//stof() converts string into float value
		}

	}
	avGrowth_rate=(float)tGrowthRate/count;
	avpop=(float)tpop/count;
	avdens=(float)tdens/count;
		
	cout<<"***************************************************** \n";
	cout<<"       ........"<<continents[i]<<"........"<<endl;
	cout<<endl;
	cout<<left<<setw(40)<<"Number Of Countries: "<<count<<endl;
	cout<<left<<setw(40)<<"Total Population: "<<tpop<<endl;
	cout<<left<<setw(40)<<"Average Population: "<<fixed<<setprecision(4)<<avpop<<endl;
	cout<<left<<setw(40)<<"Average Density: "<<avdens<<endl;
	cout<<left<<setw(40)<<"Average Growth-Rate: "<<avGrowth_rate<<"%"<<endl;
	cout<<left<<setw(40)<<"***************************************************** \n";
	
}
}

//##############################################################################################


// stats: population of 1970 
   
long long int statEngine::Median_p70()
{
	vector<int>sorted;
 	for(int i=0; i<countryCount; i++)
	{
 		sorted.push_back(i);
	}
	 
	sort(sorted.begin(), sorted.end(),
        [this](int a, int b)
        {
            return this->getpop70(a)
                 > this->getpop70(b);
        });

    long int  pop1;
    long int  pop2;
   	long long int median;
   	
   	if(countryCount % 2 ==0)
	{
   	    int index = countryCount /2;
   	    int index2 = (countryCount/2)-1;

   	    pop1=getpop70(sorted[index]);
   	    pop2=getpop70(sorted[index2]);
   	    median= (pop1 + pop2)/2;
   	    	
		return ceil(median);  
	}
	else
	{
		median= pop1;
		return ceil(median);
	} 		    
}
   	
long int  statEngine::Minimum_p70()
{
   		
   	int i =0;
   	long int lpop70 =getpop70(i);
   	
   	while(i<countryCount)
	{
   		long int p70= getpop70(i);
   		if(p70< lpop70)
		{
   			lpop70 = p70;
		}
		i++;
	}
	return lpop70;   
}
	
long int statEngine::Maximum_p70()
{
   	int i =0;
   	long int Hpop70 = getpop70(i);
   	while(i< countryCount)
	{
   		long int p70= getpop70(i);
   		if(p70> Hpop70)
		{
   			Hpop70 = p70;
		}
		i++;
	}
	return Hpop70;   
}
	   
long double statEngine::Mean_p70()
{	
	   
	long long int sum=0;
	int i=0;
	
	while (i<countryCount)
	{
		sum +=getpop70(i);
		i++;
	}
	long double mean = (double)sum/countryCount;
	return mean;
}
	
long double  statEngine::StandardDeviation_p70()
{
	double sumDiffSquered =0;
	double val=0.00;
	
	for(int i =0; i< countryCount; i++)
	{
		val= getpop70(i);
		sumDiffSquered += pow(val - Mean_p70(),2);
	}
	long double variance = sumDiffSquered / countryCount;
	long double stdDeviation = sqrt(variance);
		
	return stdDeviation;
	}
	 
long int statEngine::Range_p70()
{
	
	return Maximum_p70() -Minimum_p70();
		
} 

void statEngine::display_stats_p70()
{
	cout<<"************************************************************** \n";
	cout<<right<<setw(20)<<"			1970 STATS \n";
	cout<<"************************************************************** \n";
	cout<<left<<setw(30)<<"	MEAN  "<<fixed<<setprecision(4)<<Mean_p70()<<"\n";
	cout<<"-------------------------------------------------------------- \n";
	cout<<left<<setw(30)<<"	MEDIAN "<<Median_p70()<<"\n";
	cout<<"-------------------------------------------------------------- \n";
	cout<<left<<setw(30)<<"	MINIMUM "<<Minimum_p70()<<"\n";
	cout<<"-------------------------------------------------------------- \n";
	cout<<left<<setw(30)<<"	MAXIMUM "<<Maximum_p70()<<"\n";
	cout<<"-------------------------------------------------------------- \n";
	cout<<left<<setw(30)<<"	RANGE "<<Range_p70()<<"\n";
	cout<<"-------------------------------------------------------------- \n";
	cout<<left<<setw(30)<<"	STANDARD DEVIATION "<<StandardDeviation_p70()<<"\n";
	cout<<"************************************************************** \n";
}


// stats: population of 2015 
   
long long int statEngine::Median_p15()
{
	vector<int>sorted;
 	for(int i=0; i<countryCount; i++)
	{
 		sorted.push_back(i);
	}
	 
	sort(sorted.begin(), sorted.end(),
        [this](int a, int b)
        {
            return this->getpop15(a)
                 > this->getpop15(b);
        });

    long int  pop1;
    long int  pop2;
   	long long int median;
   	
   	if(countryCount % 2 ==0)
	{
   	    int index = countryCount /2;
   	    int index2 = (countryCount/2)-1;

   	    pop1=getpop15(sorted[index]);
   	    pop2=getpop15(sorted[index2]);
   	    median= (pop1 + pop2)/2;
   	    	
		return ceil(median);  
	}
	else
	{
		median= pop1;
		return ceil(median);
	} 		    
}
   	
long int  statEngine::Minimum_p15()
{
   		
   	int i =0;
   	long int lpop15 =getpop15(i);
   	
   	while(i<countryCount)
	{
   		long int p15= getpop15(i);
   		if(p15< lpop15)
		{
   			lpop15 = p15;
		}
		i++;
	}
	return lpop15;   
}
	
long int statEngine::Maximum_p15()
{
   	int i =0;
   	long int Hpop15 = getpop15(i);
   	while(i< countryCount)
	{
   		long int p15= getpop15(i);
   		if(p15> Hpop15)
		{
   			Hpop15 = p15;
		}
		i++;
	}
	return Hpop15;   
}
	   
long double statEngine::Mean_p15()
{	
	   
	long long int sum=0;
	int i=0;
	
	while (i<countryCount)
	{
		sum +=getpop15(i);
		i++;
	}
	long double mean = (double)sum/countryCount;
	return mean;
}
	
long double  statEngine::StandardDeviation_p15()
{
	double sumDiffSquered =0;
	double val=0.00;
	
	for(int i =0; i< countryCount; i++)
	{
		val= getpop15(i);
		sumDiffSquered += pow(val - Mean_p15(),2);
	}
	long double variance = sumDiffSquered / countryCount;
	long double stdDeviation = sqrt(variance);
		
	return stdDeviation;
	}
	 
long int statEngine::Range_p15()
{
	
	return Maximum_p15() -Minimum_p15();
		
} 



void statEngine::display_stats_p15()
{
	cout<<"************************************************************** \n";
	cout<<right<<setw(20)<<"			2015 STATS \n";
	cout<<"************************************************************** \n";
	cout<<left<<setw(30)<<"	MEAN  "<<fixed<<setprecision(4)<<Mean_p15()<<"\n";
	cout<<"-------------------------------------------------------------- \n";
	cout<<left<<setw(30)<<"	MEDIAN "<<Median_p15()<<"\n";
	cout<<"-------------------------------------------------------------- \n";
	cout<<left<<setw(30)<<"	MINIMUM "<<Minimum_p15()<<"\n";
	cout<<"-------------------------------------------------------------- \n";
	cout<<left<<setw(30)<<"	MAXIMUM "<<Maximum_p15()<<"\n";
	cout<<"-------------------------------------------------------------- \n";
	cout<<left<<setw(30)<<"	RANGE "<<Range_p15()<<"\n";
	cout<<"-------------------------------------------------------------- \n";
	cout<<left<<setw(30)<<"	STANDARD DEVIATION "<<StandardDeviation_p15()<<"\n";
	cout<<"************************************************************** \n";
}


// stats: population density
   
long long int statEngine::Median_pd()
{
	vector<int>sorted;
 	for(int i=0; i<countryCount; i++)
	{
 		sorted.push_back(i);
	}
	 
	sort(sorted.begin(), sorted.end(),
        [this](int a, int b)
        {
            return this->getdensity(a)
                 > this->getdensity(b);
        });

    long int  pop1;
    long int  pop2;
   	long long int median;
   	
   	if(countryCount % 2 ==0)
	{
   	    int index = countryCount /2;
   	    int index2 = (countryCount/2)-1;

   	    pop1=getdensity(sorted[index]);
   	    pop2=getdensity(sorted[index2]);
   	    median= (pop1 + pop2)/2;
   	    	
		return ceil(median);  
	}
	else
	{
		median= pop1;
		return ceil(median);
	} 		    
}
   	
long int  statEngine::Minimum_pd()
{
   		
   	int i =0;
   	long int lpopd =getdensity(i);
   	
   	while(i<countryCount)
	{
   		long int pd= getdensity(i);
   		if(pd< lpopd)
		{
   			lpopd = pd;
		}
		i++;
	}
	return lpopd;   
}
	
long int statEngine::Maximum_pd()
{
   	int i =0;
   	long int Hpopd = getdensity(i);
   	while(i< countryCount)
	{
   		long int pd= getdensity(i);
   		if(pd> Hpopd)
		{
   			Hpopd = pd;
		}
		i++;
	}
	return Hpopd;   
}
	   
long double statEngine::Mean_pd()
{	
	   
	long long int sum=0;
	int i=0;
	
	while (i<countryCount)
	{
		sum +=getdensity(i);
		i++;
	}
	long double mean =(double) sum/countryCount;
	return mean;
}
	
long double  statEngine::StandardDeviation_pd()
{
	double sumDiffSquered =0;
	double val=0.00;
	
	for(int i =0; i< countryCount; i++)
	{
		val= getdensity(i);
		sumDiffSquered += pow(val - Mean_pd(),2);
	}
	long double variance = sumDiffSquered / countryCount;
	long double stdDeviation = sqrt(variance);
		
	return stdDeviation;
	}
	 
long int statEngine::Range_pd()
{
	
	return Maximum_pd() -Minimum_pd();
		
} 

void statEngine::display_stats_pd()
{
	cout<<"************************************************************** \n";
	cout<<right<<setw(20)<<"			DENSITY STATS \n";
	cout<<"************************************************************** \n";
	cout<<left<<setw(30)<<"	MEAN  "<<fixed<<setprecision(4)<<Mean_pd()<<"\n";
	cout<<"-------------------------------------------------------------- \n";
	cout<<left<<setw(30)<<"	MEDIAN "<<Median_pd()<<"\n";
	cout<<"-------------------------------------------------------------- \n";
	cout<<left<<setw(30)<<"	MINIMUM "<<Minimum_pd()<<"\n";
	cout<<"-------------------------------------------------------------- \n";
	cout<<left<<setw(30)<<"	MAXIMUM "<<Maximum_pd()<<"\n";
	cout<<"-------------------------------------------------------------- \n";
	cout<<left<<setw(30)<<"	RANGE "<<Range_pd()<<"\n";
	cout<<"-------------------------------------------------------------- \n";
	cout<<left<<setw(30)<<"	STANDARD DEVIATION "<<StandardDeviation_pd()<<"\n";
	cout<<"************************************************************** \n";
}


void statEngine::statistics()
{
	int choice;
	
	do
	{
		cout<<"1. Statistics of 1970 \n"
			<<"2. Statistics of 2015 \n"
			<<"3. Statistics of density \n"
			<<"0. exit \n"<<endl;
		
		cin>>choice;
		
		while(cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout<<"invalid input...please try again \n";
			cin>>choice;
		}
		
		switch(choice)
		{
			case 1:
				{
					display_stats_p70();
					cin.ignore();
					cin.get();
					break;
				}
			case 2:
				{
					display_stats_p15();
					cin.ignore();
					cin.get();
					break;
				}
			case 3:
				{
					display_stats_pd();
					cin.ignore();
					cin.get();
					break;
				}
		}		
			
	}while(choice!=0);
}
