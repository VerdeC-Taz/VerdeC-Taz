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
		<<r<<" countries exported \n ";
}
