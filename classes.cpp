
#include"classes.h"

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
	void DataManager::Number_of_countries()
	{
		cout<<"********************** \n"
			<<countryCount
			<<" countries loaded \n"
			<<"********************** "<<endl;
	}
		
		void DataManager::export_high_pop_countries()
{
	int i=0;
	ofstream outfile("high_population_countries.csv");
	outfile<<"rank,cca3,country,continent,2023 population,area (kmÂ²),density (kmÂ²)"<<endl;

	while(i<countryCount)
	{
		int long pop=getpop23(i);
		if(pop>100000000)
		{
			int r=getrank(i);
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
}

// soryEngine

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
    
    cin.clear();
    cin.ignore();
    
    cout << "Enter choice: ";
    cin >> choice;

    
    
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
       		
			   
       		void searchEngine::search(){
       			do{
				   
			   
       		cout<<"search country by : \n 1. Country code\n 2. Country Name \n 0. Exit"<<endl;
       		cout<<"Enter choice : "<<endl;
       		cin>>choice;
       		//to remove enter which is space so that get line can work
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


// statEngine

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
	int i=1;
	string new_cnt;
	bool state;
	continents.push_back(getcontinet(0));
	continent_count++;
	do
	{
		new_cnt=getcontinet(i);
		state=duplicate_checker(new_cnt);
		
		if(state==false)
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


//###################################
//##################################
//#################################
//#########
//##########
//###########
//############
//#############



   
long long int statEngine::Median()
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
   	
long int  statEngine::Minimum()
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
	
long int statEngine::Maximum()
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
	   
long double statEngine::Mean()
{	
	   
	long long int sum=0;
	int i=0;
	
	while (i<countryCount)
	{
		sum +=getpop70(i);
		i++;
	}
	long double mean = sum/countryCount;
	return mean;
}
	
long double  statEngine::StandardDeviation()
{
	double sumDiffSquered =0;
	long int val=0;
	
	for(int i =0; i< countryCount; i++)
	{
		val= getpop70(i);
		sumDiffSquered += pow(val - Mean(),2);
	}
	long double variance = sumDiffSquered / countryCount;
	long double stdDeviation = sqrt(variance);
		
	return stdDeviation;
	}
	 
long int statEngine::Range()
{
	
	return Maximum() -Minimum();
		
} 

void statEngine::display_stat70()
{
	cout<<"************************************************************** \n";
	cout<<right<<setw(20)<<"			1970 STATS \n";
	cout<<"************************************************************** \n";
	cout<<left<<setw(30)<<"	MEAN  "<<fixed<<setprecision(4)<<Mean()<<"\n";
	cout<<"-------------------------------------------------------------- \n";
	cout<<left<<setw(30)<<"	MEDIAN "<<Median()<<"\n";
	cout<<"-------------------------------------------------------------- \n";
	cout<<left<<setw(30)<<"	MINIMUM "<<Minimum()<<"\n";
	cout<<"-------------------------------------------------------------- \n";
	cout<<left<<setw(30)<<"	MAXIMUM "<<Maximum()<<"\n";
	cout<<"-------------------------------------------------------------- \n";
	cout<<left<<setw(30)<<"	RANGE "<<Range()<<"\n";
	cout<<"-------------------------------------------------------------- \n";
	cout<<left<<setw(30)<<"	STANDARD DEVIATION "<<StandardDeviation()<<"\n";
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
		
		switch(choice)
		{
			case 1:
				{
					display_stat70();
					cin.ignore();
					cin.get();
					break;
				}
		}		
			
	}while(choice!=0);
}


/*/statEngine
long  double statEngine::findmean()
{
	long double mean;
	long int total=0;
	for(int indx = 0; indx < countryCount ; indx++ )
	{
		total+=getdensity(indx);
	}
	mean = (long double)total/countryCount;
	return mean;
}

 int statEngine::findmedian()
{
	int median;
	int i=0;
	vector<int>densities;
	
	while(i<countryCount)
	{
		densities.push_back(getdensity(i));
		i++;
	}
	sort(densities.begin(),densities.end());
	
    median=densities[countryCount/2];//finding median
    return median;
}

long long int statEngine::findminimum()
{
	long long int minimum =getdensity(0) ;
	for(int index = 0 ; index < countryCount ; index++ ){
		if(getdensity(index)<minimum){
			minimum=getdensity(index);
		};
	}
	return minimum;
}
long long int statEngine::findmaximum(){
	long long int maximum =getdensity(0) ;
	for(int ind = 0; ind < countryCount ; ind++ ){
		if(getdensity(ind) > maximum)
		{maximum =getdensity(ind);
		};
	}
	return maximum;
}
long long int statEngine::findrange(){
	int maximum=findmaximum();//obtaining maximum density from findmaximum function
	int minimum=findminimum();
	int range = maximum-minimum;
	return range;
}
double statEngine::findstdD(){
	double stdD;
	double variance;
	double value=0.0;
	double diff=0.0;
	double mean=findmean();
	for(int i=0;i<countryCount;i++){		
	   diff	=getdensity(i)-mean;
		value+=(pow(diff,2));		
	}variance=value/countryCount;
	stdD=sqrt(variance);
	return stdD;
}
void statEngine::densityStatistics()
{
	cin.ignore();
	enum Choice{ mean=1,median,maximum,minimum,range,stdD,all
	};
	int input;
    cout<<endl;
	cout<<"  ....Density Statistics.... "<<endl;
	cout<<"1.Mean "<<endl;
	cout<<"2.Median "<<endl;
	cout<<"3.Maximum "<<endl;
	cout<<"4.Minimum "<<endl;
	cout<<"5.Range"<<endl;
	cout<<"6.Standard Deviation"<<endl;
	cout<<"7.Dsplay All Operations"<<endl;
	cout<<endl;
	cout<<"Choose an operation: ";
	cin>>input;
	cout<<endl;
	switch(input){
		case mean: cout<<"Mean: "<<findmean();
		
		break;
		
		case median: cout<<"Median: "<<findmedian();
		
		break;
		
		case maximum: cout<<"Maximum: "<<findmaximum();
		
		break;
		
		case minimum: cout<<"Minimum: "<<findminimum();
		
		break;
		case range: cout<<"Range: "<<findrange();
		
		break;
		
		case stdD: cout<<"Standard Deviation: "<<findstdD();
		
		break;
		case all: cout<<"   ...All Results..."<<endl;
		        cout<<endl;
		          cout<<"Mean: "<<findmean()<<endl;
		          cout<<"Median: "<<findmedian()<<endl;
		          cout<<"Maximum: "<<findmaximum()<<endl;
		          cout<<"Minimum: "<<findminimum()<<endl;
		          cout<<"Range: "<<findrange()<<endl;
		          cout<<"Standard Deviation: "<<findstdD();
		          break;
		         
		default:cout<<"Invalid Input!!! \n Retry...."<<endl;
			densityStatistics();
		
		break;
	}
}
*/

// analysisEngine
void  analysisEngine::minMax()
{
	
	int choice;
	do{
		int  i=0;
		cout<<"1. Country with the highest 2023 population. \n"
			<<"2. Country with the lowest 2023 population. \n"
			<<"3. Country with the highest population density. \n"
			<<"4. Country with the lowest population density. \n"
			<<"5. Country with the highest growth rate. \n"
			<<"6. Country with the lowest growth rate. \n"
			<<"7. Country with the largest land area. \n"
			<<"8. Country with the smallest land area. \n \n"
			<<"0. Exit.\n"<<endl;
		
		cout<<"PLEASE  SELECT A NUMBER..."<<endl;
		cin>>choice;
	
		switch(choice)
		{
			case 1:
				{
					long int hp23= getpop23(i);
					string hp23Country=getCountry(i);
					
					while(i<countryCount)
					{	
						long int p23=getpop23(i);
						if(p23>hp23)
						{
							hp23=p23;
							hp23Country=getCountry(i);
						}
						i++;
					}
					cout<<" *********************************************************************************************"
						<<"\n The country with the highest population in 2023 was "
						<<hp23Country
						<<" with net population of "
						<<hp23
						<<"\n ********************************************************************************************* \n \n "
						<<endl;
					break;
				}
			case 2:
				{
					long int lp23=getpop23(i);
					string lp23Country=getCountry(i);
					
					while(i<countryCount)
					{	
						long int p23=getpop23(i);
						if(p23<lp23)
						{
							lp23=p23;
							lp23Country=getCountry(i);
						}
						i++;
					}
					cout<<" *********************************************************************************************"
						<<"\n The country with the lowest population in 2023 was "
						<<lp23Country
						<<" with net population of "
						<<lp23
						<<"\n ********************************************************************************************* \n \n "
						<<endl;
					break;
				}
			case 3:
				{
					int hpd=getdensity(i);
					string hpdCountry=getCountry(i);
					
					while(i<countryCount)
					{	
						int pd=getdensity(i);
						if(pd>hpd)
						{
							hpd=pd;
							hpdCountry=getCountry(i);
						}
						i++;
					}
					cout<<" *********************************************************************************************"
						<<"\n The country with the highest population density is "
						<<hpdCountry
						<<" with population density of "
						<<hpd
						<<"\n ********************************************************************************************* \n \n "
						<<endl;
					break;
				}
			case 4:
				{
					int lpd=getdensity(i);
					string lpdCountry=getCountry(i);
					
					while(i<countryCount)
					{	
						int pd=getdensity(i);
						if(pd<lpd)
						{
							lpd=pd;
							lpdCountry=getCountry(i);
						}
						i++;
					}
					cout<<" *********************************************************************************************"
						<<"\n The country with the lowest population density is "
						<<lpdCountry
						<<" with population density of "
						<<lpd
						<<"\n ********************************************************************************************* \n \n "
						<<endl;
					break;
				}
			case 5:
				{
					string percent;
					float hgr;
					
					string shgr=getgrowth_rate(i);
					stringstream s_hgr(shgr);
					s_hgr>>hgr>>percent;
					
					string hgrCountry=getCountry(i);
					
					while(i<countryCount)
					{	
						float gr;
						string sgr=getgrowth_rate(i);
						stringstream s_gr(sgr);
						s_gr>>gr>>percent;
						
						if(gr>hgr)
						{
							hgr=gr;
							hgrCountry=getCountry(i);
						}
						i++;
					}
					cout<<" *********************************************************************************************"
						<<"\n The country with the highest growth rate is "
						<<hgrCountry
						<<" with the growth rate of "
						<<hgr<<percent
						<<"\n ********************************************************************************************* \n \n "
						<<endl;
					break;
				}
			case 6:
				{
					string percent;
					float lgr;
					
					string slgr=getgrowth_rate(i);
					stringstream s_lgr(slgr);
					s_lgr>>lgr>>percent;
					
					string lgrCountry=getCountry(i);
					
					while(i<countryCount)
					{	
						float gr;
						string sgr=getgrowth_rate(i);
						stringstream s_gr(sgr);
						s_gr>>gr>>percent;
						
						if(gr<lgr)
						{
							lgr=gr;
							lgrCountry=getCountry(i);
						}
						i++;
					}
					cout<<" *********************************************************************************************"
						<<"\n The country with the lowest growth rate is "
						<<lgrCountry
						<<" with the growth rate of "
						<<lgr<<percent
						<<"\n ********************************************************************************************* \n \n "
						<<endl;
					break;
				}
			case 7:
				{
					float lla=getarea(i);					
					string llaCountry=getCountry(i);
					
					while(i<countryCount)
					{	
						float la=getarea(i);						
						if(la>lla)
						{
							lla=la;
							llaCountry=getCountry(i);
						}
						i++;
					}
					cout<<" *********************************************************************************************"
						<<"\n The country with the largest land area is "
						<<llaCountry
						<<" with the land area of "
						<<fixed<<setprecision(2)<<lla<<"Km^2"
						<<"\n ********************************************************************************************* \n \n "
						<<endl;
					break;
				}
			case 8:
				{
					float sla=getarea(i);					
					string slaCountry=getCountry(i);
					
					while(i<countryCount)
					{	
						float la=getarea(i);						
						if(la<sla)
						{
							sla=la;
							slaCountry=getCountry(i);
						}
						i++;
					}
					cout<<" *********************************************************************************************"
						<<"\n The country with the smallest land area is "
						<<slaCountry
						<<" with the land area of "
						<<fixed<<setprecision(2)<<sla<<"Km^2"
						<<"\n ********************************************************************************************* \n \n "
						<<endl;
					break;
				}
			default:
				{	if(choice==0)
					{
						cout<<"******** \n"
							<<"  END \n"
							<<"********"<<endl;
					}
					else
					{		
						cout<<"***************************************** \n"
							<<"INVALID SELECTION.......PLEASE TRY AGAIN \n"
							<<"***************************************** \n"<<endl;
						break;
					}
				}
				
		}
	}while(choice!=0);
}

void  analysisEngine::filterCountry()
{
	
	int choice;
	do{
		int i=0;
		cout<<"1. Countries with population greater than 100 million \n"
			<<"2. Countries with population density greater than 500 \n"
			<<"3. Countries with growth rate greater than 2% \n"
			<<"4. Countries with area greater than 1,000,000km^2 \n \n"
			<<"0. Exit \n"<<endl;
		cout<<"SELECT A NUMBER...\n";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				{
					pop_greater_100M();
					break;	
				}
			case 2:
				{
					int count=1;
					while(i<countryCount)
					{
						int d=getdensity(i);
						if(d>500)
						{
							string cc=getCountry(i);
							cout<<count
								<<". "
								<<left<<setw(15)<<cc
								<<"........."
								<<d
								<<endl;
							count++;
						}
						i++;
					}
					break;
				}
			case 3:
				{
					int count=1;
					cout<<"*************************************************** \n";
					while(i<countryCount)
					{	float gr;
						string percent;
						
						string s_gr=getgrowth_rate(i);
						stringstream sgr(s_gr);
					
						sgr>>gr>>percent;
						
						if(gr>2.00)
						{
							string cc=getCountry(i);
							cout<<count
								<<". "
								<<left<<setw(25)<<cc
								<<"  "
								<<gr<<percent
								<<"\n --------------------------------------------------- \n"
								<<endl;
							count++;
						}
						i++;
					}
					cout<<"*************************************************** \n";
					cin.ignore();
					cin.get();
					break;
				}
			case 4:
				{
					int count=1;
					while(i<countryCount)
					{
						float area=getarea(i);
						if(area>1000000.00)
						{
							string cc=getCountry(i);
							cout<<count
								<<". "
								<<left<<setw(15)<<cc
								<<"........."
								<<fixed<<setprecision(2)<<area
								<<endl;
							count++;
						}
						i++;
					}
					break;
				}
			default:
				{	if(choice==0)
					{
						cout<<"******** \n"
							<<"  END \n"
							<<"********"<<endl;
					}
					else
					{		
						cout<<"***************************************** \n"
							<<"INVALID SELECTION.......PLEASE TRY AGAIN \n"
							<<"***************************************** \n"<<endl;
						break;
					}
				}
		}
	}while(choice!=0);
}

void  analysisEngine::pop_greater_100M()
{
	int choice;
	do{
		int i=0;
		cout<<"1. 2023 \n"
			<<"2. 2022 \n"
			<<"3. 2020 \n"
			<<"4. 2015 \n"
			<<"5. 2010 \n"
			<<"6. 2000 \n"
			<<"7. 1990 \n"
			<<"8. 1980 \n"
			<<"9. 1970 \n"
			<<"\n0. exit \n"<<endl;
			
		cout<<"SELECT YEAR...(1->9) \n 0 to exit \n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				{	int a=1;
					while(i<countryCount)
					{
						long int pop=getpop23(i);
						if(pop>100000000)
						{
							
							string cc=getCountry(i);
							cout<<a
								<<". "
								<<left<<setw(15)<<cc
								<<"........"
								<<pop
								<<"\n"<<endl;
							a++;
						}
						i++;
					}
					break;
				}
			case 2:
				{	int a=1;
					while(i<countryCount)
					{
						long int pop=getpop22(i);
						if(pop>100000000)
						{
							
							string cc=getCountry(i);
							cout<<a
								<<". "
								<<left<<setw(15)<<cc
								<<"........"
								<<pop
								<<"\n"<<endl;
							a++;
						}
						i++;
					}
					break;
				}
			case 3:
				{	int a=1;
					while(i<countryCount)
					{
						long int pop=getpop20(i);
						if(pop>100000000)
						{
							
							string cc=getCountry(i);
							cout<<a
								<<". "
								<<left<<setw(15)<<cc
								<<"........"
								<<pop
								<<"\n"<<endl;
							a++;
						}
						i++;
					}
					break;
				}
			case 4:
				{	int a=1;
					while(i<countryCount)
					{
						long int pop=getpop15(i);
						if(pop>100000000)
						{
							
							string cc=getCountry(i);
							cout<<a
								<<". "
								<<left<<setw(15)<<cc
								<<"........"
								<<pop
								<<"\n"<<endl;
							a++;
						}
						i++;
					}
					break;
				}
			case 5:
				{	int a=1;
					while(i<countryCount)
					{
						long int pop=getpop10(i);
						if(pop>100000000)
						{
							
							string cc=getCountry(i);
							cout<<a
								<<". "
								<<left<<setw(15)<<cc
								<<"........"
								<<pop
								<<"\n"<<endl;
							a++;
						}
						i++;
					}break;
				}
			case 6:
				{	int a=1;
					while(i<countryCount)
					{
						long int pop=getpop00(i);
						if(pop>100000000)
						{
							
							string cc=getCountry(i);
							cout<<a
								<<". "
								<<left<<setw(15)<<cc
								<<"........"
								<<pop
								<<"\n"<<endl;
							a++;
						}
						i++;
					}
					break;
				}
			case 7:
				{	int a=1;
					while(i<countryCount)
					{
						long int pop=getpop90(i);
						if(pop>100000000)
						{
							
							string cc=getCountry(i);
							cout<<a
								<<". "
								<<left<<setw(15)<<cc
								<<"........"
								<<pop
								<<"\n"<<endl;
							a++;
						}
						i++;
					}
					break;
				}
			case 8:
				{	int a=1;
					while(i<countryCount)
					{
						long int pop=getpop80(i);
						if(pop>100000000)
						{
							
							string cc=getCountry(i);
							cout<<a
								<<". "
								<<left<<setw(15)<<cc
								<<"........"
								<<pop
								<<"\n"<<endl;
							a++;
						}
						i++;
					}
					break;
				}
			case 9:
				{	int a=1;
					while(i<countryCount)
					{
						long int pop=getpop70(i);
						if(pop>100000000)
						{
							
							string cc=getCountry(i);
							cout<<a
								<<". "
								<<left<<setw(15)<<cc
								<<"........"
								<<pop
								<<"\n"<<endl;
							a++;
						}
						i++;
					}
					break;
				}
		}
	}while(choice!=0);
}

void analysisEngine::analyse_pop_growth()
{
	int n;
	
	int highest_abs=INT_MIN;
	string highest_abs_country;
	
	int lowest_abs=INT_MAX;
	string lowest_abs_country;
	
	float largest_per_increase=0.00;
	string largest_per_increase_country;
	
	string country;
	
	cout<<"Enter number of countries to analyse the population trends ";
	cin>>n;
	while(n<=0||n>countryCount)
		{
			cout<<"invalid selection \n";
			cin>>n;
		}
	cin.ignore();
	for(int a=1;a<=n;a++)
	{
		cout<<"COUNTRY "<<a<<": ";
	
		getline(cin,country);
		
		int index=countryindex(country);
		
		while(index==-1)
		{
			cout<<"COUNTRY "<<a<<": ";
			getline(cin,country);
			index=countryindex(country);
			
		}
		long int p23=getpop23(index);
		long int p70=getpop70(index);
		int new_abs=p23-p70;
		float new_per_increase=(static_cast<float>(new_abs)/p70)*100.00;
		
		if(new_abs>highest_abs)
		{
			highest_abs=new_abs;
			highest_abs_country=getCountry(index);
		}
		if(new_abs<lowest_abs)
		{
			lowest_abs=new_abs;
			lowest_abs_country=getCountry(index);
		}
		
		if(new_per_increase>largest_per_increase)
		{
			largest_per_increase=new_per_increase;
			largest_per_increase_country=getCountry(index);
		}		
	}
	cout<<"**************************************************************** \n"
		<<highest_abs_country
		<<" has the largest absolute increase of "
		<<highest_abs<<"\n"
		<<"****************************************************************\n \n"<<endl;
		
	cout<<"**************************************************************** \n"
		<<lowest_abs_country
		<<" has the smallest absolute increase of "
		<<lowest_abs<<"\n"
		<<"**************************************************************** \n \n"<<endl;
		
	cout<<"**************************************************************** \n"
		<<largest_per_increase_country
		<<" has the largest percentage increase of "
		<<largest_per_increase<<"% \n"
		<<"**************************************************************** \n \n"<<endl;	
	cout<<"press enter to proceed......";
	cin.get();
}

	 void  analysisEngine::estimate_pop(){
	 	string countryInput;
	 	cout<<"Enter country name : ";
	 	cin.ignore();
	 	getline(cin,countryInput);
		 
	 int index = countryindex(countryInput);
	 	
	 	while(index==-1){
	 		cout<<"Country not found in the database \n PLEASE TRY AGAIN: ";
	 		getline(cin,countryInput);
			index = countryindex(countryInput);
	 		
		 }
		 
		 double d_gr; //container for decimal value
		 string percent; // container for %
		 long int pop23= getpop23(index);
		 string growthRate = getgrowth_rate(index);
		 stringstream s_gr(growthRate);
		 
		 s_gr>>d_gr>>percent;
		 
		 double estimatedpop= pop23*pow((1+d_gr), 10);
		 
		 cout<<"******************************************************************** \n"
		 	 <<"The estimated population for "<<countryInput
		     <<" after 10 years is "<<fixed<<setprecision(2)<<estimatedpop
			 <<"\n*******************************************************************"<<endl;
	 }
	 
void analysisEngine::classifyDensity(){

int low=0;
int medium=0;
int high=0;
int density;
for(int i=0;i<countryCount;i++)
{
	density=getdensity(i);
	
	if(density<100)
	{
		low++;
	}
	else if(density>=100&&density<=499)
	{
		medium++;
	}
	else
	{
		high++;
	}

	
}
cout<<"************************************* \n";
cout<<left<<setw(20)<<"Low Density"<<"("<<low<<" Countries)"<<endl;
cout<<"------------------------------------- \n";
cout<<left<<setw(20)<<"Medium Density"<<"("<<medium<<" Countries)"<<endl;
cout<<"------------------------------------- \n";
cout<<left<<setw(20)<<"High Density"<<"("<<high<<" Countries)"<<endl;
cout<<"************************************* \n";
}
	 
	 
	void analysisEngine::compare()
		{	
			string country1, country2;
			
			cout<<" "<<endl;
			cout<<"Enter Two countries to compare there data"<<endl;
		
	    	cout<<"Enter first country "<<endl;
	    	cin.ignore();
	    	getline(cin, country1);
	   		int index1=countryindex(country1);
	   		
	    while(index1==-1)
	    {
	    	cout<<"invalid country please try again : ";
	    	getline(cin,country1);
	    	index1=countryindex(country1);
		}
		
	    
	    
	    cout<<"Enter second country"<<endl;
	    getline(cin,country2);
	     int index2=countryindex(country2);
	    while(index2==-1)
	    {
	    	cout<<"invalid country please try again \n";
	    	getline(cin,country2);
	    	index2=countryindex(country2);
		}

	  
		
		cout<<"*************************************************************************\n"
			<<left<<setw(30)<<"Demographic feature"<<left<<setw(15)<<getCountry(index1)<<getCountry(index2)<<"\n"
			<<"--------------------------------------------------------------------------\n"
			<<left<<setw(30)<<"Continent"<<left<<setw(15)<<getcontinet(index1)<<getcontinet(index2)<<"\n"
			<<left<<setw(30)<<"2023 population"<<left<<setw(15)<<getpop23(index1)<<getpop23(index2)<<"\n"
			<<left<<setw(30)<<"2022 population"<<left<<setw(15)<<getpop22(index1)<<getpop22(index2)<<"\n"
			<<left<<setw(30)<<"2020 population"<<left<<setw(15)<<getpop20(index1)<<getpop20(index2)<<"\n"
			<<left<<setw(30)<<"2015 population"<<left<<setw(15)<<getpop15(index1)<<getpop15(index2)<<"\n"
			<<left<<setw(30)<<"2010 population"<<left<<setw(15)<<getpop10(index1)<<getpop10(index2)<<"\n"
			<<left<<setw(30)<<"2000 population"<<left<<setw(15)<<getpop00(index1)<<getpop00(index2)<<"\n"
			<<left<<setw(30)<<"1990 population"<<left<<setw(15)<<getpop90(index1)<<getpop90(index2)<<"\n"
			<<left<<setw(30)<<"1980 population"<<left<<setw(15)<<getpop80(index1)<<getpop80(index2)<<"\n"
			<<left<<setw(30)<<"1970 population"<<left<<setw(15)<<getpop70(index1)<<getpop70(index2)<<"\n"
			<<left<<setw(30)<<"Area"<<left<<setw(15)<<getarea(index1)<<getarea(index2)<<"\n"
			<<left<<setw(30)<<"Growth Rate"<<left<<setw(15)<<getgrowth_rate(index1)<<getgrowth_rate(index2)<<"\n"  
			<<left<<setw(30)<<"World Population Percentage"<<left<<setw(15)<<getwolrd_per(index1)<<getwolrd_per(index2)<<"\n"  
			<<"************************************************************************* "<<endl;
			
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
		    
		    int steps=10;
			cout<<"Loading[";
			for(int i=0;i<steps;i++)
			{
		
				cout<<".."<<flush;
				sleep(10/steps);
			}
			cout<<"] \n" ;
			system("cls");
		    manage.loadData();	
			cout<<"\n press enter to proceed \n";
			cin.get();	
			
			system("cls");	
			
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
		switch(choice)
		{
			case 1:
				{
					system("cls");
					manage.loadData();
					cout<<"press enter to proceed \n";
					cin.ignore();
					cin.get();
					system("cls");
					break;
				}
			case 2:
				{
					system("cls");
					manage.Number_of_countries();
					cout<<"press enter to proceed \n";
					cin.ignore();
					cin.get();
					system("cls");
					break;
				}
			case 3:
				{
					system("cls");
					search.search();
					cout<<"\n press enter to proceed \n";
					cin.ignore();
					cin.get();
					system("cls");
					break;
					
				}
			case 4:
				{
					system("cls");
					sort.sortCountries();
					cout<<"press enter to procced"<<endl;
					cin.ignore();
					cin.get();
					system("cls");
					break;
				}
			case 5:
				{
					system("cls");
					analyse.minMax();
					cout<<"press enter to procced"<<endl;
					cin.ignore();
					cin.get();
					system("cls");
					break;
				}
			case 6:
				{
					system("cls");
					analyse.filterCountry();
					cout<<"press enter to procced"<<endl;
					cin.ignore();
					cin.get();
					system("cls");
					break;
				}
			case 7:
				{
					system("cls");
					stats.statistics();
					cout<<"press enter to procced"<<endl;
					cin.ignore();
					cin.get();
					system("cls");
					break;
				}
//			case 7:
//				{
//					cin.ignore();
//					stats.densityStatistics();

//					break;
//				}
			case 8:
				{
					system("cls");
					analyse.classifyDensity();
					cout<<"press enter to procced"<<endl;
					cin.ignore();
					cin.get();
					system("cls");
					break;
				}
			case 9:
				{
					//system("cls");
					stats.group_by_continent();
					cout<<"press enter to procced"<<endl;
					cin.ignore();
					cin.get();
				//	system("cls");
					break;
				}
			case 10:
				{
					system("cls");
					analyse.analyse_pop_growth();
					cout<<"press enter to procced"<<endl;
					cin.ignore();
					cin.get();
					system("cls");
					break;
				}
			case 11:
				{
					system("cls");
					analyse.estimate_pop();
					cout<<"press enter to proceed"<<endl;
					cin.ignore();
					cin.get();
					system("cls");
					break;
				}
			case 12:
			{
				system("cls");
				analyse.compare();
				cout<<"press enter to proceed"<<endl; 
				cin.ignore();
				cin.get();
				system("cls");
				break;
			}
			case 13:
				{
					system("cls");
					manage.export_high_pop_countries();
					cout<<"press enter to procced"<<endl;
					cin.ignore();
					cin.get();
					system("cls");
					break;
				}
			default:
				{
					system("cls");
					if(choice==0)
					{
					
						cout<<"******** \n"
							<<"END \n"
							<<"******** "<<endl;
						system("cls");
						break;
					}
					else
					{
						cout<<"************** \n"
							<<"IVALID INPUT \n"
							<<"**************"<<endl;
						system("cls");
						break;
					}
					
				}
		}	
		}while(choice!=0);
}
