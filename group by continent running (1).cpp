#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>

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
		long int getpo23(int i)
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
class statEngine:public country{
public:
long  double findmean()
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

 int findmedian()
{
	int median;
	int i=0;
	vector<int>densities;
	
	while(i<countryCount)
	{
		densities[i]=getdensity(i);
	}
	sort(densities.begin(),densities.end());
	
    median=densities[countryCount/2];//finding median
    return median;
}

long long int findminimum()
{
	long long int minimum =getdensity(0) ;
	for(int index = 0 ; index < countryCount ; index++ ){
		if(getdensity(index)<minimum){
			minimum=getdensity(index);
		};
	}
	return minimum;
}
long long int findmaximum(){
	long long int maximum =getdensity(0) ;
	for(int ind = 0; ind < countryCount ; ind++ ){
		if(getdensity(ind) > maximum)
		{maximum =getdensity(ind);
		};
	}
	return maximum;
}
long long int findrange(){
	int maximum=findmaximum();//obtaining maximum density from findmaximum function
	int minimum=findminimum();
	int range = maximum-minimum;
	return range;
}
double findstdD(){
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
void densityStatistics(){
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

};
	





	

int main()
   {	
   		DataMananger dm;
   		statEngine se;
   		dm.loadData();
   		se.densityStatistics();
     return 0;
      }