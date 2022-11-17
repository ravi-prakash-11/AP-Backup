#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "conio.h"

using namespace std;


class Data
{
    string ID;
    string FName;
    string LName;
    string Country;
    string Gender;

public:

    Data(string oID, string oFName, string oLName, string oCountry, string oGender)
    {
        ID=oID;
        FName=oFName;
        LName=oLName;
        Country=oCountry;
        Gender=oGender;
    }
    
    void update()
    {
        system("cls");
        cout<<"\n\tID\tFull Name\tCountry\tGender"<<endl;
        display();
        cout<<"\n\n\nUpdate Record..."<<endl;
        cout<<"\n1. Name.";
        cout<<"\n2. Country.";
        cout<<"\n3. Gender.";
        cout<<"\n0. Cancel.";

        cout<<"\n\nEnter Choice: ";

        int choice;
        cin>>choice;
        switch(choice)
        {
            case 1: 
            {
                cout<<"\n Enter Full Name: ";
                cin>>FName>>LName;
                break;
            }
            case 2:
            {
                cout<<"\n Enter Country: ";
                cin>>Country;
                break;
            }
            case 3:
            {
                cout<<"\n Enter Gender: "; 
                cin>>Gender;
                break;
            }
            case 0: return;
        } 
    }

    string getID()
    {
        return ID;
    }


    void display()
    {
        cout<<"\n\t"<<ID<<"\t"<<FName<<"\t"<<LName<<"\t"<<Country<<"\t"<<Gender;
    }

    void csv_entry()
    {
        ofstream fout("Database.csv", ios::app);
        fout<<ID<<","<<FName<<","<<LName<<","<<Country<<","<<Gender<<"\n";
        fout.close();
    }

};

vector<Data> base;

void record();
void save();
void fetch();
int match(string);
int search(string);
void deleterecord(int);

void driver()
{   
    fetch();
    while(1)
    {
        system("cls");
        cout<<"\n********************************\n";
        cout<<"\t1. Add Record\n";
        cout<<"\t2. Update Record\n";
        cout<<"\t3. Delete Record\n";
        cout<<"\t4. Display Database\n";
        cout<<"\t0. Save & Exit\n";
        cout<<"********************************\n";
        cout<<"\n\nEnter Choice: ";

        int choice;
        cin>>choice;

        switch(choice)
        {
            case 1:
            {
                record();
                save();
                break;   
            }
                

            case 2:
            {
                system("cls");
                if (base.empty())
                {
                    cout<<"\nNo data found."<<endl;
                    getch();
                    break;
                }
                cout<<"\n Enter ID: ";
                string check;
                cin>>check;

                int index;
                index = search(check);
                if(index == -1)
                {
                    cout<<"No match found."<<endl;
                    getch();
                    break;
                }
                    
                base[index].update();

                break;
       
            }    

            
            case 3:
            {
                system("cls");
                if (base.empty())
                {
                    cout<<"\nNo data found."<<endl;
                    getch();
                    break;
                }
                cout<<"\n Enter ID: ";
                string check;
                cin>>check;

                int index;
                index = search(check);
                if(index == -1)
                {
                    cout<<"No match found."<<endl;
                    getch();
                    break;
                }

                deleterecord(index);

                cout<<"Record Deleted..."<<endl;
                getch();
                break;
            }

            case 4:
            {
                system("cls");
                cout<<"\n\t**************** DATABASE ****************\n";
                cout<<"\n\tID\tFull Name\tCountry\tGender"<<endl;
                for (int i=0; i<base.size(); i++)
                    base[i].display();
                cout<<"\n\n\t**************** xxxxxxxx ****************\n";
                getch();
                break;
            }
            case 0: 
            {
                system("cls"); 
                cout<<"\n\n\nChanges Saved..."<<endl<<endl<<endl<<endl; 
                save(); getch(); return;
            }
        }
    }
}

main()
{
    driver();
}

void record()
{
        system("cls");
        cout<<"\n Enter ID: ";
        string check;
        
        cin>>check;

        int flag;
        flag = match(check);
        if(flag == 1)
        {
            cout<<"\n Entered ID already exists in Database...";
            getch();
            return;
        }
        
        string ID;
        string FName;
        string LName;
        string Country;
        string Gender;

        ID = check;
        cout<<"\n Enter Full Name: ";
        cin>>FName>>LName;

        cout<<"\n Enter Country: ";
        cin>>Country;

        cout<<"\n Enter Gender: "; 
        cin>>Gender;

        Data emp(ID,FName,LName,Country,Gender);
        base.push_back(emp);
}

void save()
{
    ofstream fout("Database.csv", ios::trunc);
    for (int i=0; i<base.size(); i++)
                    base[i].csv_entry();
    fout.close();
    getch();
}

void fetch()
{
    ifstream fin;
    fin.open("Database.csv", ios::in);
    if (!fin) 
    {
		cout << "Error 404: Could not open DataBase.csv"<<endl;
	}
	else 
    {
        string line = "";
        while (getline(fin, line)) 
        {

            stringstream inString(line);

            string ID;
            string FName;
            string LName;
            string Country;
            string Gender;

            getline(inString, ID, ',');
            getline(inString, FName, ',');
            getline(inString, LName, ',');
            getline(inString, Country, ',');
            getline(inString, Gender);

            Data emp(ID,FName,LName,Country,Gender);
            base.push_back(emp);
            line = "";
        }    
    }
    fin.close();
}
	
int match(string ID)
{   
    if (base.empty()) return 0;
    for (int i = 0; i<base.size(); i++)
    {
        if((ID == base[i].getID()) ==1) return 1;
    }

    return 0;
}

int search(string ID)
{
    int i=0;
    bool found = false;
    for (i = 0; i <base.size(); i++)
    {
        if((ID == base[i].getID()) == 1) 
        {
            found = true;
            return i;
        }
    }
    if(found == false) return -1;
}

void deleterecord(int index)
{
    base.erase(base.begin() + index);
}