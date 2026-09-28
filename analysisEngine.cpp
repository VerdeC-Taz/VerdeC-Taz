// analysisEngine
#include"classes.h"
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
		
		cout<<"Enter choice..."<<endl;
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
			cout<<"invalid input please try again.... \n (q. to exit) \n";
			cout<<"COUNTRY "<<a<<": ";
			getline(cin,country);
			index=countryindex(country);
			
			if(country=="q");
			{
				return;
				
			}
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

void analysisEngine::Generate_Report()
{
	long long int t_pop=0;
	ofstream report("population_analysis_report.txt");
	
	report<<"POPULATION ANALYSIS REPORT \n \n";
	report<<" The total number of countries is "<<countryCount<<endl; 
	
	for(int i = 0; i< countryCount; i++)
	{
		t_pop+=getpop70(i);
	}
	report<<"The total population of 1970 was "<<t_pop<<endl;
	t_pop=0;
	
	for(int i = 0; i< countryCount; i++)
	{
		t_pop+=getpop80(i);
	}
	report<<"The total population of 1980 was "<<t_pop<<endl;
	t_pop=0;
	
	for(int i = 0; i< countryCount; i++)
	{
		t_pop+=getpop90(i);
	}
	report<<"The total population of 1980 was "<<t_pop<<endl;
	t_pop=0;
	
	for(int i = 0; i< countryCount; i++)
	{
		t_pop+=getpop90(i);
	}
	report<<"The total population of 1990 was "<<t_pop<<endl;
	t_pop=0;
	
	for(int i = 0; i< countryCount; i++)
	{
		t_pop+=getpop00(i);
	}
	report<<"The total population of 2000 was "<<t_pop<<endl;
	t_pop=0;
	
	for(int i = 0; i< countryCount; i++)
	{
		t_pop+=getpop10(i);
	}
	report<<"The total population of 2010 was "<<t_pop<<endl;
	t_pop=0;
	
	for(int i = 0; i< countryCount; i++)
	{
		t_pop+=getpop15(i);
	}
	report<<"The total population of 2015 was "<<t_pop<<endl;
	t_pop=0;
	
	for(int i = 0; i< countryCount; i++)
	{
		t_pop+=getpop20(i);
	}
	report<<"The total population of 2020 was "<<t_pop<<endl;
	t_pop=0;
	
    for(int i = 0; i< countryCount; i++)
	{
		t_pop+=getpop22(i);
	}
	report<<"The total population of 2022 was "<<t_pop<<endl;
	t_pop=0;	
	
	for(int i = 0; i< countryCount; i++)
	{
		t_pop+=getpop23(i);
	}
	report<<"The total population of 2023 was "<<t_pop<<endl;
	

int i=0;


//
//	long int lp23= getpop23(i);
//	string lp23Country=getCountry(i);
//					
//	for(int i=0;i<countryCount;i++)
//	{	
//		long int p23=getpop23(i);
//		if(p23<lp23)
//		{
//			lp23=p23;
//			lp23Country=getCountry(i);
//		}
//			i++;
//	}


// finding the most populated country registered through all the countries

int h_pop_index[8];


// calling a function to get an index of  a country with the highest population n that year
// sending (c) an object of country class, a name of a getter(getpop23) and the index(i) seperately
h_pop_index[0]=get_highest_pop(c,&country::getpop23,i);//storing the index in an array

i=0;
h_pop_index[1]=get_highest_pop(c,&country::getpop22,i);

i=0;
h_pop_index[2]=get_highest_pop(c,&country::getpop20,i);

i=0;
h_pop_index[3]=get_highest_pop(c,&country::getpop15,i);

i=0;
h_pop_index[4]=get_highest_pop(c,&country::getpop10,i);

i=0;
h_pop_index[5]=get_highest_pop(c,&country::getpop00,i);

i=0;
h_pop_index[6]=get_highest_pop(c,&country::getpop90,i);

i=0;
h_pop_index[7]=get_highest_pop(c,&country::getpop80,i);

i=0;
h_pop_index[8]=get_highest_pop(c,&country::getpop70,i);

i=h_pop_index[0];// setting i with the first index in the arrry(index of highest population in 2023)

long int highest_pop=getpop23(i);//initialising the highest pop to the pop23 highest population
string highest_pop_country=getCountry(i);

i=h_pop_index[1];
if(getpop22(i)>highest_pop)//comparing the highest pop (2023) with highest pop 2022
{
	highest_pop=getpop22(i);
	highest_pop_country=getCountry(i);
}

if(getpop20(h_pop_index[2])>highest_pop)
{
	highest_pop=getpop20(h_pop_index[2]);
	highest_pop_country=getCountry(h_pop_index[2]);
}

if(getpop15(h_pop_index[3])>highest_pop)
{
	highest_pop=getpop15(h_pop_index[3]);
	highest_pop_country=getCountry(h_pop_index[3]);
}

if(getpop10(h_pop_index[4])>highest_pop)
{
	highest_pop=getpop10(h_pop_index[4]);
	highest_pop_country=getCountry(h_pop_index[4]);
}

if(getpop00(h_pop_index[5])>highest_pop)
{
	highest_pop=getpop00(h_pop_index[5]);
	highest_pop_country=getCountry(h_pop_index[5]);
}

if(getpop90(h_pop_index[6])>highest_pop)
{
	highest_pop=getpop90(h_pop_index[6]);
	highest_pop_country=getCountry(h_pop_index[6]);
}

if(getpop80(h_pop_index[7])>highest_pop)
{
	highest_pop=getpop80(h_pop_index[7]);
	highest_pop_country=getCountry(h_pop_index[7]);
}

if(getpop70(h_pop_index[8])>highest_pop)
{
	highest_pop=getpop70(h_pop_index[8]);
	highest_pop_country=getCountry(h_pop_index[8]);
}

// after comparing all the pops ...we finally have the h_pop, h_pop_country registered since 1970

//write into the file

//report<<"The most populated country registered since 1970 is ";
report<<highest_pop_country;
report<<" with the net population of ";
report<<highest_pop<<endl;


cout<<"step "<<endl;
 i=0;

int l_pop_index[8];


l_pop_index[0]=least_pop_index(c,&country::getpop23,i);//storing the index in an array

i=0;
l_pop_index[1]=least_pop_index(c,&country::getpop22,i);

i=0;
l_pop_index[2]=least_pop_index(c,&country::getpop20,i);

i=0;
l_pop_index[3]=least_pop_index(c,&country::getpop15,i);

i=0;
l_pop_index[4]=least_pop_index(c,&country::getpop10,i);

i=0;
l_pop_index[5]=least_pop_index(c,&country::getpop00,i);

i=0;
l_pop_index[6]=least_pop_index(c,&country::getpop90,i);

i=0;
l_pop_index[7]=least_pop_index(c,&country::getpop80,i);

i=0;
l_pop_index[8]=least_pop_index(c,&country::getpop70,i);

i=l_pop_index[0];

long int least_pop=getpop23(i);
string least_pop_country=getCountry(i);

i=l_pop_index[1];
if(getpop22(i)<least_pop)
{
	least_pop=getpop22(i);
	least_pop_country=getCountry(i);
}

if(getpop20(l_pop_index[2])<least_pop)
{
	least_pop=getpop20(l_pop_index[2]);
	least_pop_country=getCountry(l_pop_index[2]);
}

if(getpop15(l_pop_index[3])<least_pop)
{
	least_pop=getpop15(l_pop_index[3]);
	least_pop_country=getCountry(l_pop_index[3]);
}

if(getpop10(l_pop_index[4])<least_pop)
{
	least_pop=getpop10(l_pop_index[4]);
	least_pop_country=getCountry(l_pop_index[4]);
}

if(getpop00(l_pop_index[5])>least_pop)
{
	least_pop=getpop00(l_pop_index[5]);
	least_pop_country=getCountry(l_pop_index[5]);
}

if(getpop90(l_pop_index[6])>least_pop)
{
	least_pop=getpop90(l_pop_index[6]);
	least_pop_country=getCountry(l_pop_index[6]);
}

if(getpop80(l_pop_index[7])>least_pop)
{
	least_pop=getpop80(l_pop_index[7]);
	least_pop_country=getCountry(l_pop_index[7]);
}

if(getpop70(l_pop_index[8])>least_pop)
{
	least_pop=getpop70(l_pop_index[8]);
	least_pop_country=getCountry(l_pop_index[8]);
}

// after comparing all the pops ...we finally have the l_pop, l_pop_country registered since 1970

//write into the file
report<<"The most populated country registered since 1970 is "
	  <<least_pop_country
	  <<" with the net population of "
	  <<least_pop
	  <<"\n ";
	  
	  
	  
loadcontinents();
	  
long long int  total_continental_pop[continent_count];

for(int a=0;a<continent_count;a++)
{
	i=0;
	total_continental_pop[a]=sum_cont_pop(continents[a],c,&country::getpop23,i)+
						  sum_cont_pop(continents[a],c,&country::getpop22,i)+
						  sum_cont_pop(continents[a],c,&country::getpop20,i)+
						  sum_cont_pop(continents[a],c,&country::getpop15,i)+
						  sum_cont_pop(continents[a],c,&country::getpop10,i)+
						  sum_cont_pop(continents[a],c,&country::getpop00,i)+
						  sum_cont_pop(continents[a],c,&country::getpop90,i)+
						  sum_cont_pop(continents[a],c,&country::getpop80,i)+
						  sum_cont_pop(continents[a],c,&country::getpop70,i);
						  
}

i=0;
long long int h_pop_continent=total_continental_pop[i];
string h_pop_continent_name=continents[i];

for(int b=1;b<continent_count;b++)
{
	if(total_continental_pop[b]>h_pop_continent)
	{
		h_pop_continent=total_continental_pop[b];
		h_pop_continent_name=continents[b];
		
	}
}

report<<"The most populated continent since 1970 is "
	  <<h_pop_continent_name
	  <<" with the total sum of population from 1970  of "
	  <<h_pop_continent
	  <<"\n "<<endl;


i=0;
long long int l_pop_continent=total_continental_pop[i];
string l_pop_continent_name=continents[i];

for(int b=1;b<continent_count;b++)
{
	if(total_continental_pop[b]<l_pop_continent)
	{
		l_pop_continent=total_continental_pop[b];
		l_pop_continent_name=continents[b];
		
	}
}

report<<"The least populated continent since 1970 is "
	  <<l_pop_continent_name
	  <<" with the total sum of population from 1970  of "
	  <<l_pop_continent
	  <<"\n "<<endl;


}



