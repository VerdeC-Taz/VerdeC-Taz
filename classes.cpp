
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
  			ifstream csvfile("world_population_data.csv");
  			
			string line;
			getline(csvfile,line);
	
			while(getline(csvfile,line))
			{
				stringstream word(line);
				
				string c,cod,cnt,gr,wp;
				string rank_s,area_s,density_s;
				string p23_s,p22_s,p20_s,p15_s,p10_s,p00_s,p90_s,p80_s,p70_s;
			
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
          		
          		int r=stoi(rank_s),d=stoi(density_s);
          		float a=stof(area_s);
				long int p23=stol(p23_s),p22=stol(p22_s),p20=stol(p20_s);
				long int p15=stol(p15_s),p10=stol(p10_s),p00=stol(p00_s);
				long int p90=stol(p90_s),p80=stol(p80_s),p70=stol(p70_s);
			
			
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

//statEngine
	
long double statEngine::findmean()
{
	long double mean;
	long int total_density=0;
	
	for(int indx=0;indx<countryCount;indx++)
	{
		total_density+=getdensity(indx);
	}
	mean=(long double)total_density/countryCount;
	
	return mean;
}

long int statEngine::findmedian() 
{    
    vector<int> densities;
    
    for (int i = 0; i < countryCount; i++) 
	{
        densities.push_back(getdensity(i));
    }
    
    sort(densities.begin(), densities.end());
    
    if (countryCount%2 == 0)
	{
        return (densities[countryCount / 2 - 1] + densities[countryCount / 2]) / 2;
    }
	else
	{
    	return densities[countryCount / 2];
    }
}

long long int statEngine::findminimum()
{
	long long int minimum =getdensity(0);
	
	for(int index=0;index<countryCount;index++)
	{
		if(getdensity(index)<minimum)
		{
			minimum =getdensity(index);
		}
	}
	return minimum;
}

long long int statEngine::findmaximum()
{
	long long int maximum =getdensity(0);
	for(int i = 0; i< countryCount;i++ )
	{
		if(getdensity(i)>maximum)
		{
		maximum =getdensity(i);
		}
	}
	return maximum;
}

long long int statEngine::findrange()
{
	long int maximum=findmaximum();//obtaining maximum density from findmaximum function
	long int minimum=findminimum();
	long int range = maximum-minimum;
	
	return range;
}

double statEngine::findstdD()
{
	double stdD;
	double variance;
	double value=0.0;
	double diff=0.0;
	
	double mean=findmean();
	
	for(int i=0;i<countryCount;i++)
	{		
	  	diff=getdensity(i)-mean;
		value+=(pow(diff,2));		
	}
	variance=value/countryCount;
	
	stdD=sqrt(variance);
	
	return stdD;
}

void statEngine::densityStatistics()
{	int input;
	do{
		
		enum Choice{ mean=1,median,maximum,minimum,range,stdD,all};
	
	
		cout<<"\n  ....Density Statistics.... "<<endl;
	
		cout<<"1.Mean "<<endl;
		cout<<"2.Median "<<endl;
		cout<<"3.Maximum "<<endl;
		cout<<"4.Minimum "<<endl;
		cout<<"5.Range"<<endl;
		cout<<"6.Standard Deviation"<<endl;
		cout<<"7.Dsplay All Operations \n"<<endl;
	
		cout<<"Choose an operation: ";
		cin>>input;
	
		switch(input)
		{
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
		         
			default:
				{
					if(input==0)
					{
						cout<<"******* \n"
							<<"  END \n"
							<<"******* \n"<<endl;
						break;
					}
					else
					{
					cout<<"Invalid Input!!! \n Retry...."<<endl;	
					break;
					}
				}
		}
	}while(input!=0);
}
	


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
								<<"........."
								<<gr
								<<endl;
							count++;
						}
						i++;
					}
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
	
	cout<<"enter number of countries you want to compare ";
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
		 
		 cout<<"*********************************************************** \n"
		 	 <<"The estimated population for "<<countryInput
		     <<" after 10 years is "<<fixed<<setprecision(2)<<estimatedpop
			 <<"\n**********************************************************"<<endl;
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
					manage.Number_of_countries();
					cout<<"press enter to proceed \n";
					cin.ignore();
					cin.get();
					break;
				}
			case 3:
				{
					search.search();
					cout<<"\n press enter to proceed \n";
					cin.ignore();
					cin.get();
					break;
					
				}
			case 5:
				{
					analyse.minMax();
					break;
				}
			case 6:
				{
					analyse.filterCountry();
					break;
				}
			case 7:
				{
					stats.densityStatistics();
				}
			case 10:
				{
					analyse.analyse_pop_growth();
					break;
				}
			case 11:
				{
					analyse.estimate_pop();
					break;
				}
			case 13:
				{
					manage.export_high_pop_countries();
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
