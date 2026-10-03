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
