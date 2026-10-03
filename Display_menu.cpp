#include"classes.h"

void populationSystem::DisplayMenu()
		{
			Displayable* cc;
			
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
					cc=&manage;
					cc->display();
					
					cout<<"press enter to proceed \n";
					cin.ignore();
					cin.get();
					break;
				}
			case 3:
				{
					Search.search();
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
					cc=&analyse;
					cc->display();
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
