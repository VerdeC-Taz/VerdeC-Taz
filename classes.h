#ifndef CLASSES_H
#define CLASSES_H

#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<cctype>
#include<climits>
#include<limits>
#include<cmath>
#include<string>
using namespace std;

	class Displayable {
		public:
  		virtual void display() = 0; // Pure virtual function for polymorphism
        virtual ~Displayable() = default;
};

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
			//constructors
			country();
			country(const int &r, const string&cd,const string &c,
				const string &cnt,const long int &p23,const long int &p22,
				const long int &p20,const long int &p15,const long int &p10,
				const long int &p00,const long int &p90,const long int &p80,
				const long int &p70, const float &a,const int &d,const string &gr,
				const string &wp);
			~country(){
			};
				
			//setters
			void setrank(int r);
			void setcode(string cd);
			void setpop(long int p23,long int p22, long int p20, 
					long int p15,long int p10,long int p00,
					long int p90, long int p80,long int p70);
			void setarea(float a);
			void setdens(int d);
			
			//getters
			int getrank(int i);
			string getcca3(int i);
			string getCountry(int i);
 			string getcontinet(int i);
 			long int getpop23(int i);
 			long int getpop22(int i);
 			long int getpop20(int i);
 			long int getpop15(int i);
 			long int getpop10(int i);
 			long int getpop00(int i);
 			long int getpop90(int i);
 			long int getpop80(int i);
 			long int getpop70(int i);
 			float getarea(int i);
			int getdensity(int i);
			string getgrowth_rate(int i);
			string getwolrd_per(int i);
			
			
};
	
	
	class DataManager:virtual public country,public Displayable {
		public:
			void loadData();
			void display() override;
			void export_high_pop_countries();
	};
	
	
	class searchEngine:virtual public country {
		private:
			int choice;
       		string query;
       	public:
       		string toLower(string str);
       		int countryindex(string country);
       		void search();
       		void cca3Choice();
       		void countryChoice();		
	};
	
	class sortEngine:virtual public country{
		public:
			void pop23_d(vector<int>& sorted);
			void pop70_d(vector<int>& sorted);
			void density_d(vector<int>& sorted);
			void growth_rate_a(vector<int>& sorted);
			void sortCountries();
	};
	
	
	class statEngine:virtual public country{
		private:
			
		protected:
			country c;			
			vector<string> continents;
			int continent_count;
		public:
			int get_highest_pop(country& g,long int (country::*getter) (int), int i);// recieving an object and function as a parameter 	
			int least_pop_index(country& g,long int (country::*getter)(int), int i);// recieving an object and function as a parameter 
			
			float Maximum_gr();
			float Minimum_gr();
			
			bool duplicate_checker(string cnt);
			void loadcontinents();
			long long int sum_cont_pop(string cnt,country& g,long int (country::*getter)(int), int i);
			void group_by_continent();

			//stats p_1970
			long long int Median_p70();
			long int Minimum_p70();
			long int Maximum_p70();
			long double Mean_p70();
			long double StandardDeviation_p70();
			long int Range_p70();
			void display_stats_p70();
			
			//stats p_2015
			long long int Median_p15();
			long int Minimum_p15();
			long int Maximum_p15();
			long double Mean_p15();
			long double StandardDeviation_p15();
			long int Range_p15();
			void display_stats_p15();
			
			//stats pd
			long long int Median_pd();
			long int Minimum_pd();
			long int Maximum_pd();
			long double Mean_pd();
			long double StandardDeviation_pd();
			long int Range_pd();
			void display_stats_pd();
			
			void statistics();
			
	};



	class analysisEngine:public searchEngine,public statEngine,public Displayable{
		public:
			void minMax();
			void filterCountry();
			void pop_greater_100M();
			void analyse_pop_growth();
			void estimate_pop();
			int Low();
			int Medium();
			int High();
			void display() override;
			void compare();
			void Generate_Report();

		
	};
	
	
	class populationSystem{
		private:
			sortEngine sort;
			searchEngine Search;
			DataManager manage;
			analysisEngine analyse;
			statEngine stats;
		public:
			void DisplayMenu();
	};
#endif