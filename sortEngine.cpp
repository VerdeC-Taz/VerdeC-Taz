// sortEngine
#include"classes.h"
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
    cout << "\n Enter 0 to exit"<<endl;
    
    
    cout << "Enter choice: ";
    cin >> choice;

    while(cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout<<"invalid input...please try again \n";
			cin>>choice;
		}
    
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
