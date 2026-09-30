

country::country(){}
country::country(const int &r, const string&cd,const string &c,
		const string &cnt,const long int &p23,const long int &p22,
		const long int &p20,const long int &p15,const long int &p10,
		const long int &p00,const long int &p90,const long int &p80,
		const long int &p70, const float &a,const int &d,const string &gr,
		const string &wp)
{
			setrank(r);
			setcode(cd);
 		    Country = c; 
			continent= cnt;
			setpop(p23,p22,p20,p15,p10,p00,p90,p80,p70);
			setarea(a);
			setdens(d);
			growth_rate=gr;
			world_per=wp;			
		}
		 		
		
		//SETTERS
		void country::setrank(int r){
			if(r<=0){
				throw out_of_range("File Error @rank \n PLEASE CHECK YOUR FILE");
			} rank=r;
		}
        void country::setcode(string cd){
			if(cd.length() !=3){
				throw invalid_argument("File error @code \n PLEASE CHECK YOUR FILE");

				}
				cca3 = cd;
		}
		void country::setpop(long int p23,long int p22, long int p20, 
					long int p15,long int p10,long int p00,
					long int p90, long int p80,long int p70){
			if( p23 <0 && p22 < 0 && p20 < 0&& p15<0 && p10<0 && p00 < 0 && p90 < 0 && p80 <0 && p70 <0){
			 throw invalid_argument("File Error @ population \n PLEASE CHECK YOUR FILE");	
			}
			pop23= p23;
			pop22= p22;
			pop20= p20;
			pop15= p15;
			pop10= p10;
			pop00= p00;
			pop90= p90;
			pop80= p80;
			pop70= p70;
		}
		void country::setarea(float a){
			if(a<=0){
				throw invalid_argument("File Error @area \n PLEASE CHECK YOUR FILE");
			}
			area = a;
		}
		void country::setdens(int d){
			if(d<0){
				throw invalid_argument("File Error @density \n PLEASE CHECK YOUR FILE");
			}
			density = d;
		}
		
		
		// GETTERS...
		int country::getrank(int i)
		{
			return countries[i].rank;
		}
		string country::getcca3(int i)
		{
			return countries[i].cca3;
		}
		string country::getCountry(int i)
		{
			return countries[i].Country;
		}
		string country::getcontinet(int i)
		{
			return countries[i].continent;
		}
		long int country::getpop23(int i)
		{
			return countries[i].pop23;
		}
		long int country::getpop22(int i)
		{
			return countries[i].pop22;
		}
		long int country::getpop20(int i)
		{
			return countries[i].pop20;
		}
		long int country::getpop15(int i)
		{
			return countries[i].pop15;
		}
		long int country::getpop10(int i)
		{
			return countries[i].pop10;
		}
		long int country::getpop00(int i)
		{
			return countries[i].pop00;
		}
		long int country::getpop90(int i)
		{
			return countries[i].pop90;
		}
		long int country::getpop80(int i)
		{
			return countries[i].pop80;
		}
		long int country::getpop70(int i)
		{
			return countries[i].pop70;
		}
		float country::getarea(int i)
		{
			return countries[i].area;
		}
		int country::getdensity(int i)
		{
			return countries[i].density;
		}
		string country::getgrowth_rate(int i)
		{
			return countries[i].growth_rate;
		}
		string country::getwolrd_per(int i)
		{
			return countries[i].world_per;
		}

		
int country::countryCount=0;
vector<country> country::countries;
// DataManager
#include"classes.h"
		void DataManager::loadData()
		{
			//make sure the variable are empty........
			countries.clear();
			countryCount=0;
  			ifstream csvfile("world_population_data.csv");
  			
			string line;
			getline(csvfile,line); //reading the heading line separately
	
			while(getline(csvfile,line))// loop to load countries line by line 
			{
				stringstream word(line);//make the line splittable
				
				// 17 datasets variable...
				string c,cod,cnt,gr,wp;
				string rank_s,area_s,density_s;
				string p23_s,p22_s,p20_s,p15_s,p10_s,p00_s,p90_s,p80_s,p70_s;
				
				// splitting the line into differnt containers
				getline(word,rank_s,',');
				getline(word,cod,',');
				getline(word,c,',');
				getline(word,cnt,',');
				getline(word,p23_s, ',');
           		getline(word,p22_s, ',');
           		getline(word,p20_s, ',');
       		    getline(word,p15_s, ',');
          		getline(word,p10_s, ',');
          		getline(word,p00_s,',');
          		getline(word,p90_s,',');
           		getline(word,p80_s,',');
          		getline(word,p70_s,',');
          		getline(word,area_s,',');
          		getline(word,density_s,',');
          		getline(word,gr,',');
          		getline(word,wp,',');
          		
          		//converting the string data into different data types
          		int r=stoi(rank_s),d=stoi(density_s);
          		float a=stof(area_s);
				long int p23=stol(p23_s),p22=stol(p22_s),p20=stol(p20_s);
				long int p15=stol(p15_s),p10=stol(p10_s),p00=stol(p00_s);
				long int p90=stol(p90_s),p80=stol(p80_s),p70=stol(p70_s);
			
				// storing the objects into a vector
				countries.push_back(country(r,cod,c,cnt,p23,p22,p20,p15,p10,p00,p90,p80,p70,a,d,gr,wp));
				countryCount++;
			}
			
			csvfile.close();
			cout<<"********************************* \n"
				<<"Data is loaded successfully \n"
				<<"********************************* \n"<<endl;	 
		}
	void DataManager::display()
	{
		cout<<"********************** \n"
			<<countryCount
			<<" countries loaded \n"
			<<"********************** "<<endl;
	}
		
void DataManager::export_high_pop_countries()
{
	int i=0;
	int r=0;
	ofstream outfile("high_population_countries.csv");
	outfile<<"rank,cca3,country,continent,2023 population,area (kmÂ²),density (kmÂ²)"<<endl;

	while(i<countryCount)
	{
		int long pop=getpop23(i);
		if(pop>100000000)
		{
			r++;
			string code=getcca3(i);
			string c=getCountry(i);
			string cnt=getcontinet(i);
			long int p23=getpop23(i);
			float a=getarea(i);
			int d=getdensity(i);
			
			outfile<<r<<","
				   <<code<<","
				   <<c<<","
				   <<cnt<<","
				   <<p23<<","
				   <<a<<","
				   <<d<<","
				   <<endl;
			
		}
		i++;
		
	}
	outfile.close();
	
	cout<<"***************************** \n"
		<<r<<" coutries exported \n ";
}


//searchEngine  

	string searchEngine::toLower(string str)
 {
    transform(str.begin(), str.end(), str.begin(),
                   [](unsigned char c){ return tolower(c); });
    return str;
}

int searchEngine::countryindex(string country)
{
	string lowercountry= toLower(country);
	int i=0;
	while(i<countryCount)
	{	
		string NewCountry= getCountry(i);
		if(lowercountry==toLower(NewCountry))
		{
			return i;
		}
		i++;
	}
	return -1;
}	
       		//int choice;
       		
			   
       		void searchEngine::display(){
       			do{
				   
			   
       		cout<<"search country by : \n 1. Country code\n 2. Country Name \n 0. Exit"<<endl;
       		cout<<"Enter choice : "<<endl;
       		cin>>choice;
       		while(cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout<<"invalid input...please try again \n";
			cin>>choice;
		}
       		switch(choice){
       			case 1 :cout<<"Enter Country code of the country to be searched :";
       		            cin>>query;
       		            cca3Choice();
       		           	cout<<" \n press enter to proceed \n";
						cin.ignore();
						cin.get();
       		            break;
       		            
       		    case 2 :cout<<"Enter the name of the country to be searched :";
       		  			cin.ignore();
				        getline(cin,query);
				        countryChoice();
				       	cout<<"\n press enter to proceed \n";
						cin.ignore();
						cin.get();
				        break;
				case 0 :cout<<"Exit !!!";
				        break;
						        
				default: cout<<"Invalid entry!!";
				        break;	       
			   }
       	}while(choice !=0);
       }
       
       			
		void searchEngine::cca3Choice(){
			
				
				for(int i =0; i< countryCount;i++)
				{
					string code=toLower(query);
				
					if(code==toLower(getcca3(i)))
					{
					cout<<"*************************************** \n";
					cout<<"Rank               :"<<getrank(i)<<"\n";
				 	cout<<"CCA3               :"<<getcca3(i)<<"\n";
				 	cout<<"Country            :"<<getCountry(i)<<"\n";
				 	cout<<"Continent          :"<<getcontinet(i)<<"\n";
				 	cout<<"2023 Population    :"<<getpop23(i)<<"\n";
				 	cout<<"2022 Population    :"<<getpop22(i)<<"\n";
				 	cout<<"2020 Population    :"<<getpop20(i)<<"\n";
				 	cout<<"2015 Population    :"<<getpop15(i)<<"\n";
				 	cout<<"2010 Population    :"<<getpop10(i)<<"\n";
				 	cout<<"2000 Population    :"<<getpop00(i)<<"\n";
				 	cout<<"1990 Population    :"<<getpop90(i)<<"\n";
				 	cout<<"1980 Population    :"<<getpop80(i)<<"\n";
				 	cout<<"1970 Population    :"<<getpop70(i)<<"\n";
				 	cout<<"Area               :"<<getarea(i)<<"km^2 \n";
				 	cout<<"Density            :"<<getdensity(i)<<"/km^2 \n";
				 	cout<<"Growth Rate        :"<<getgrowth_rate(i)<<"\n";
				 	cout<<"World Percentage   :"<<getwolrd_per(i)<<"\n"; 
				 	cout<<"**************************************** \n";
				 	break;			 	
				}

			}				 
	}
 
  void searchEngine::countryChoice(){
	            for(int i=0;i<countryCount; i++){
	            	
	            	string country=toLower(query);
				
					if(country==toLower(getCountry(i))){
				
				 	cout<<"Rank               :"<<getrank(i)<<"\n";
				 	cout<<"CCA3               :"<<getcca3(i)<<"\n";
				 	cout<<"Country            :"<<getCountry(i)<<"\n";
				 	cout<<"Continent          :"<<getcontinet(i)<<"\n";
				 	cout<<"2023 Population    :"<<getpop23(i)<<"\n";
				 	cout<<"2022 Population    :"<<getpop22(i)<<"\n";
				 	cout<<"2020 Population    :"<<getpop20(i)<<"\n";
				 	cout<<"2015 Population    :"<<getpop15(i)<<"\n";
				 	cout<<"2010 Population    :"<<getpop10(i)<<"\n";
				 	cout<<"2000 Population    :"<<getpop00(i)<<"\n";
				 	cout<<"1990 Population    :"<<getpop90(i)<<"\n";
				 	cout<<"1980 Population    :"<<getpop80(i)<<"\n";
				 	cout<<"1970 Population    :"<<getpop70(i)<<"\n";
				 	cout<<"Area               :"<<getarea(i)<<"km^2 \n";
				 	cout<<"Density            :"<<getdensity(i)<<"/km^2 \n";
				 	cout<<"Growth Rate        :"<<getgrowth_rate(i)<<"\n";
				 	cout<<"World Percentage   :"<<getwolrd_per(i)<<"\n";
				 	break;
				 }		 
			}
}  	

// sortEngi
// Option 1: 2023 population - descending
void sortEngine::pop23_d(vector<int>& sorted)
{
    sort(sorted.begin(), sorted.end(),
        [this](int a, int b)
        {
            return this->getpop23(a)
                 > this->getpop23(b);
        });
}


// Option 2: 1970 population - descending
void sortEngine::pop70_d(vector<int>& sorted)
{
    sort(sorted.begin(), sorted.end(),
        [this](int a, int b)
        {
            return this->getpop70(a)
                 > this->getpop70(b);
        });
}


// Option 3: Population density - descending
void sortEngine::density_d(vector<int>& sorted)
{
    sort(sorted.begin(), sorted.end(),
        [this ](int a,int b)
        {
            return this->getdensity(a)
                 > this->getdensity(b);
        });
}


// Option 4: Growth rate - ascending
void sortEngine::growth_rate_a(vector<int>& sorted)
{
    sort(sorted.begin(), sorted.end(),
        [this ](int a,int b)
        {
            return this->getgrowth_rate(a)
                 < this->getgrowth_rate(b);
        });
}


void sortEngine::sortCountries()
{
	// store country indices
    vector<int> sorted;

    for (int i = 0; i < countryCount;i++)
    {
        sorted.push_back(i);
    }
    
    int choice;
  do{

    cout << "1. By 2023 population (Descending)" << endl;
    cout << "2. By 1970 population (Descending)" << endl;
    cout << "3. By population density (Descending)" << endl;
    cout << "4. By growth rate (Ascending)" << endl;
    cout << "5. Enter 0 to exit"<<endl;
    
    
    cout << "Enter choice: ";
    cin >> choice;

    while(cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout<<"invalid input...please try again \n";
			cin>>choice;
		}
    
    switch (choice)
    {
        case 1:
            pop23_d(sorted);
            cout<<"*********************************************************** \n";
            cout <<"\nSorted by: 2023 population (Descending)"<<endl;
            cout <<"----------------------------------------------------------\n";
            for (int i : sorted)
            {
                cout<<left<<setw(35)<<this->getCountry(i)<<" : "<<getpop23(i)<<endl;
                cout<<"------------------------------------------------------------ \n";
                
            }
            cout<<"************************************************************* \n";
            break;

        case 2:
            pop70_d(sorted);
            cout<<"*********************************************************** \n";
            cout <<"\nSorted by: 1970 population (Descending)"<<endl;
            cout <<"----------------------------------------------------------\n";
            for (int i : sorted)
            {
                cout <<left<<setw(35)<<this->getCountry(i)<<" : "<<getpop70(i)<<endl;
                cout<<"------------------------------------------------------------ \n";
            }
            cout<<"*********************************************************** \n";

            break;

        case 3:
            density_d(sorted);
            cout<<"*********************************************************** \n";
        	cout <<"\nSorted by: Population Density (Descending)"<<endl;
            cout <<"-----------------------------------------------------------\n";
            for (int i : sorted)
            {
                cout <<left<<setw(35)<<this->getCountry(i)<<" : "<<getdensity(i)<<endl;
            	cout<<"------------------------------------------------------------ \n";
			}
            cout<<"*********************************************************** \n";
            break;

        case 4:
            growth_rate_a(sorted);
            cout<<"*********************************************************** \n";
            cout <<"\nSorted by: Growth Rate (Ascending)"<<endl;
            cout <<"-----------------------------------------------------------\n";
            for (int i : sorted)
            {
                cout <<left<<setw(35)<<this->getCountry(i)<<" : "<<getgrowth_rate(i)<<endl;
                cout<<"------------------------------------------------------------ \n";
            }
            cout<<"*********************************************************** \n";
            break;
        default:
        	{
        		if(choice==0)
        		{
        			cout<<"****** \n"
			   			<<"END \n"
			   			<<"****** \n";
			   		break;
				}
				else
				{
					cout<<"**************** \n"
						<<"Invalid choice! \n"
						<<"****************"<< endl;
				}
			}
            
    }
}while(choice!=0);
}


// statEn

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




	void statEngine::group_by_continent(){
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





void populationSystem::DisplayMenu()
		{
			
			int choice;
			
			cout<<"=======================================================================================\n"
				<<"======================================================================================= \n"
				<<"                 WORLD POPULATION DATA ANALYSIS SYSTEM  \n"
				<<"======================================================================================= \n"
		    	<<"======================================================================================="<<endl;
		  
		    cout<<"\n press enter to load Data \n";
		    cin.get();
		    manage.loadData();	
			cout<<"\n press enter to proceed \n";
			cin.get();		
			
			do{
			cout<<"=======================================================================================\n"
				<<"======================================================================================= \n"
				<<"                 WORLD POPULATION DATA ANALYSIS SYSTEM  \n"
				<<"======================================================================================= \n"
		    	<<"======================================================================================="<<endl;
		    	
 			cout <<"1. Reload CSV data\n"
				 <<"2. Display number of countries\n"
	 			 <<"3. Search country\n"
	 			 <<"4. Sort countries\n"
	 			 <<"5. Find minimum or maximum values\n"
	 			 <<"6. Filter countries\n"
				 <<"7. Statistical analysis\n"
				 <<"8. Density classification\n"
				 <<"9. Analyse by continent\n"
				 <<"10. Population trend analysis\n"
				 <<"11. Estimate future population\n"
				 <<"12. Compare countries\n"
				 <<"13. Export high population countries\n"
				 <<"14. Generate report\n"
				 <<"0. Exit"<<endl;
		
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
					
					manage.loadData();
					cout<<"press enter to proceed \n";
					cin.ignore();
					cin.get();
					break;
				}
			case 2:
				{
					country* cc=&manage;
					cc->display();
					manage.display();
					cout<<"press enter to proceed \n";
					cin.ignore();
					cin.get();
					break;
				}
			case 3:
				{
					country* cc=&search;
					cc->display();
					search.display();
					cout<<"\n press enter to proceed \n";
					cin.ignore();
					cin.get();
					break;
					
				}
			case 4:
				{
					sort.sortCountries();
					cout<<"press enter to procced"<<endl;
					cin.ignore();
					cin.get();
					break;
				}
			case 5:
				{
					analyse.minMax();
					cout<<"press enter to procced"<<endl;
					cin.ignore();
					cin.get();
					break;
				}
			case 6:
				{
					analyse.filterCountry();
					cout<<"press enter to procced"<<endl;
					cin.ignore();
					cin.get();
					break;
				}
			case 7:
				{
					stats.statistics();
					cout<<"press enter to procced"<<endl;
					cin.ignore();
					cin.get();
					break;
				}
			case 8:
				{
					analyse.display();
					cout<<"press enter to procced"<<endl;
					cin.ignore();
					cin.get();
					break;
				}
			case 9:
				{
					stats.group_by_continent();
					cout<<"press enter to procced"<<endl;
					cin.ignore();
					cin.get();
					break;
				}
			case 10:
				{
					analyse.analyse_pop_growth();
					cout<<"press enter to procced"<<endl;
					cin.ignore();
					cin.get();
					break;
				}
			case 11:
				{
					analyse.estimate_pop();
					cout<<"press enter to proceed"<<endl;
					cin.ignore();
					cin.get();
					break;
				}
			case 12:
			{
				analyse.compare();
				cout<<"press enter to proceed"<<endl; 
				cin.ignore();
				cin.get();
				break;
			}
			case 13:
				{
					manage.export_high_pop_countries();
					cout<<"press enter to procced"<<endl;
					cin.ignore();
					cin.get();
					break;
				}
			case 14:
				{
					analyse.Generate_Report();
					cout<<"generated \n";
					cout<<"press enter to procced"<<endl;
					cin.ignore();
					cin.get();
					break;
				}
			default:
				{
					if(choice==0)
					{
						cout<<"******** \n"
							<<"END \n"
							<<"******** "<<endl;
						break;
					}
					else
					{
						cout<<"************** \n"
							<<"IVALID INPUT \n"
							<<"**************"<<endl;
						break;
					}
					
				}
		}	
		}while(choice!=0);
}
