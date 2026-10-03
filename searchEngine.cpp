//searchEngine  
#include"classes.h"		
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
       		try{
       			if(choice<0||choice>3)
       			{
				 throw "Invalid choice \n";
			   }
	     	}
			   catch (const char* message)
			   {
			   	cout<<message;
			   }
			   
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
       		            try{
						   
       		            cca3Choice();
       		            if(!query.empty())
       		            {
       		            	throw "Country not found ";
					   }
					   
       		     	   }
       		     	   catch(const char* m)
       		     	   {
       		     	   	cout<<m;
						   }
       		           	cout<<" \n press enter to proceed \n";
						cin.ignore();
						cin.get();
       		            break;
       		            
       		    case 2 :cout<<"Enter the name of the country to be searched :";
       		  			cin.ignore();
				        getline(cin,query);
				        try{
						
				        countryChoice();
				        if(!query.empty())
				        {
				        	throw "Country not found ";
						}
					}
						catch(const char*m)
						{
							cout<<m;
						}
				       	cout<<"\n press enter to proceed \n";
						cin.ignore();
						cin.get();
				        break;
				case 0 :cout<<"Exit !!! \n";
				        break;
						        
				default: cout<<"\n";
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
				 	query.clear();
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
				 	query.clear();
				 	break;
				 }		 
			}
}  	
