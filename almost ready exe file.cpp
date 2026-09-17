#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<ctype.h>
using namespace std;

ifstream openfile()
{
    ifstream csvfile("world_population_data.csv");
    return csvfile;
}


class country{
	private:
		int rank;
		string cca3;
		string Country;
		string continent;
		long int pop23,pop22,pop20,pop15,pop10,pop00,pop90,pop80,pop70;
		float area;
		int density;
		string growth_rate;
		string world_per;
   protected:
		static int countryCount;
		static vector<country> countries;
	public:
		country()
		{
			
		}
		country(const int &r, const string&cd,const string &c,
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
		void setrank(int r){
			if(r<=0){
				cout<<"File Error @rank"<<endl;
				return;
			} rank=r;
		}
        void setcode(string cd){
			if(cd.length() !=3){
				cout<<"File error @code"<<endl;
					return ;
				}
				cca3 = cd;
		}
		void setpop(long int p23,long int p22, long int p20, 
					long int p15,long int p10,long int p00,
					long int p90, long int p80,long int p70){
			if( p23 <0 && p22 < 0 && p20 < 0&& p15<0 && p10<0 && p00 < 0 && p90 < 0 && p80 <0 && p70 <0){
			 cout<<"File Error @ pop"<<endl;
			 return ;	
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
		void setarea(float a){
			if(a<=0){
				cout<<"File Error @area"<<endl;
				return;
			}
			area = a;
		}
		void setdens(int d){
			if(d<0){
				cout<<"File Error @density"<<endl;
				return;
			}
			density = d;
		}
		//GETTERS
		int getrank(int i)
		{
			return countries[i].rank;
		}
		string getcca3(int i)
		{
			return countries[i].cca3;
		}
		string getCountry(int i)
		{
			return countries[i].Country;
		}
		string getcontinet(int i)
		{
			return countries[i].continent;
		}
		long int getpop23(int i)
		{
			return countries[i].pop23;
		}
		long int getpop22(int i)
		{
			return countries[i].pop22;
		}
		long int getpop20(int i)
		{
			return countries[i].pop20;
		}
		long int getpop15(int i)
		{
			return countries[i].pop15;
		}
		long int getpop10(int i)
		{
			return countries[i].pop10;
		}
		long int getpop00(int i)
		{
			return countries[i].pop00;
		}
		long int getpop90(int i)
		{
			return countries[i].pop90;
		}
		long int getpop80(int i)
		{
			return countries[i].pop80;
		}
		long int getpop70(int i)
		{
			return countries[i].pop70;
		}
		float getarea(int i)
		{
			return countries[i].area;
		}
		int getdensity(int i)
		{
			return countries[i].density;
		}
		string getgrowth_rate(int i)
		{
			return countries[i].growth_rate;
		}
		string getwolrd_per(int i)
		{
			return countries[i].world_per;
		}		
};
int country::countryCount=0;
vector<country> country::countries;

class DataMananger:public country{
	private:
		
	public:
		
		void loadData()
		{
  			ifstream csvfile=openfile();//("world_population_data.csv");
			
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
			cout<<"Data is loaded successfully \n"
				<<countryCount<<" countries loaded \n";	 
		}
};

// ANALYSIS CLASS #########################################
class AnalysisEngine:public country{
	private:
		
	public:
		void minMax()
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
					long int hp23=getpop23(i);
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
						<<fixed<<setprecision(2)<<lla<<"(Km^2)"
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

void filterCountry()
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
							cout<<right<<setw(5)<<count
								<<". "
								<<left<<setw(15)<<cc
								<<"........... "
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
							cout<<right<<setw(5)<<count
								<<". "
								<<left<<setw(25)<<cc
								<<"........... "
								<<gr<<percent
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
							cout<<right<<setw(5)<<count
								<<". "
								<<left<<setw(15)<<cc
								<<".......... "
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
void pop_greater_100M()
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
								<<"__________"
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
								<<"__________"
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
								<<"__________"
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
								<<"__________"
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
								<<"__________"
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
								<<"__________"
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
								<<"__________"
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
								<<"__________"
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
								<<"__________"
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

void export_high_pop_countries()
{
	int i=0;
	ofstream outfile("high_population_countries.csv");
	outfile<<"rank,cca3,country,continent,2023 population,area (kmÃ‚Â²),density (kmÃ‚Â²)"<<endl;

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


//???????????????????????????????????????

void analyse_pop_growth()
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
			cout<<"invalid country name.......please check and retry \n"<<endl;
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
	cout<<"************************************************* \n"
		<<highest_abs_country
		<<" has the largest absolute increase of "
		<<highest_abs<<"\n"
		<<"************************************************* \n \n"<<endl;
		
	cout<<"************************************************* \n"
		<<lowest_abs_country
		<<" has the smallest absolute increase of "
		<<lowest_abs<<"\n"
		<<"************************************************* \n \n"<<endl;
		
	cout<<"************************************************* \n"
		<<largest_per_increase_country
		<<" has the largest percentage increase of "
		<<largest_per_increase<<"\n"
		<<"************************************************* \n \n"<<endl;	
}

string toLower(string str)
 {
    transform(str.begin(), str.end(), str.begin(),
                   [](unsigned char c){ return tolower(c); });
    return str;
}

int countryindex(string country)
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

};


int main()

   {	int i=0;
   		
   		DataMananger dm;
   		dm.loadData();
   		AnalysisEngine an;
   		an.analyse_pop_growth();
		//an.minMax();
   	//	an.export_high_pop_countries();
   		an.filterCountry();
     return 0;
      }