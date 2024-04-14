#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

struct PA_candidate {
    string Name;
    string party_Name;
    int  Age;
    string CNIC_; 
};

const int MAx_CONSTITUENCIES = 10;
const int MAx_CANDIDATES = 100;
PA_candidate Candidates[MAx_CANDIDATES][MAx_CONSTITUENCIES];
int Num_constituencies = 0;
int Num_candidates = 0;

void Add_candidates(int Constituency_number) {
    char addData;
    int Num_candidates_in_constituency = 0; 
    if (Constituency_number >= Num_constituencies) {
        Num_constituencies = Constituency_number + 1;
    }

    do{

     if (Num_candidates_in_constituency < MAx_CANDIDATES){
        cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "\nEnter CNIC of the Candidate: \n";
        cin >> Candidates[Constituency_number][Num_candidates_in_constituency].CNIC_;
        if(Candidates[Constituency_number][Num_candidates_in_constituency].CNIC_.length()!=13){
            cout<<"ERROR: CNIC must be exactly 13 digits\n";
            return;
        }

        cout<<"Enter Candidates Name: \n";
        cin.ignore();
        getline(cin,Candidates[Constituency_number][Num_candidates_in_constituency].Name);
       
        cout << "Enter Age:\n";
        int Age;
        do {
            if (!(cin >> Age)) {
             cerr << "Error: Invalid input. Please enter a number.\n";
             cin.clear();
             cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else if (Age < 25) {
            cout << "ERROR: Age must be at least 25. Please re-enter:\n";
            }
            } while (Age < 25);
            Candidates[Constituency_number][Num_candidates_in_constituency].Age = Age;
        
        cout<<"Enter party name: \n";
        cin.ignore();
        getline(cin,Candidates[Constituency_number][Num_candidates_in_constituency].party_Name);
        
        Num_candidates_in_constituency++;
        cout << "Candidate added successfully!" << endl;
        cout<<"Enter Y or y if you want to add more data for the same constituency or type anything else to exit \n";
        cin>>addData;
        cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
    } 
}
    while (addData=='y' || addData=='Y');
    Num_candidates += Num_candidates_in_constituency;  // Update the global variable
    }
    
void AddMenu(){
    int Counter = 0;
    int Constituency;
    do { 
        cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout<<"Select your Constituency Number to add data.\n";
        cout<<"1.   PA-23";
        cout<<"\n2.  PA-25";
        cout<<"\n3.  PA-35";
        cout<<"\n4.  PA-40";
        cout<<"\n5.  PA-48";
        cout<<"\n6.  PA-56";
        cout<<"\n7.  PA-45";
        cout<<"\n8.  PA-23";
        cout<<"\n9.  PA-67";
        cout<<"\n10. PA-76";
        cout<<"\n11. EXIT";
        cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;

        cin>>Constituency;

        switch(Constituency){
            case 1:
               Add_candidates(0);
                break;
            case 2:
               Add_candidates(1);
                break;
            case 3:
                Add_candidates(2);
                break;
            case 4:
                Add_candidates(3);
                break;
            case 5:
                Add_candidates(4);
                break;
            case 6:
                Add_candidates(5);
                break;
            case 7:
                Add_candidates(6);
                break;
            case 8:
                Add_candidates(7);
                break;
            case 9:
                Add_candidates(8);
                break;
            case 10:
                Add_candidates(9);
                break;    
            case 11:     
                break;
            default:
                cout<<"Invalid option\n";
                break;
        }
    } while (Constituency > 10 || Constituency < 1);
}

void View_candidates(int Num_constituencies) {
    if (Num_constituencies == 0) {
        cout << "No candidates added yet." << endl;
    } else {
        for (int i = 0; i < Num_constituencies; i++) {
            cout << "Constituency " << i + 1 << ":" << endl;
            for (int j = 0; j < MAx_CANDIDATES; j++) {
                if (Candidates[i][j].Age == 0) {
                    break;
                }
                cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
                cout << "\t\t\tName: " << Candidates[i][j].Name << endl;
                cout << "\t\t\tParty name: " << Candidates[i][j].party_Name << endl;
                cout << "\t\t\tAge: " << Candidates[i][j].Age << endl;
                cout << "\t\t\tCNIC: " << Candidates[i][j].CNIC_ << endl;
                cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
                cout << endl;
            }
        }
    }
}

void Save_to_file(const PA_candidate Candidates[MAx_CANDIDATES][MAx_CONSTITUENCIES])
{
      ofstream outfile;
      outfile.open("PA.txt");
     
      if (outfile.is_open()) 
    {

    for (int i = 0; i < MAx_CONSTITUENCIES; i++) 
    {
        for (int j = 0; j < MAx_CANDIDATES; j++) 
        {
            if (Candidates[i][j].Age == 0) 
            {
                break;
            }
            outfile << Candidates[i][j].Name << endl;
            outfile << Candidates[i][j].party_Name << endl;
            outfile << Candidates[i][j].Age << endl;
            outfile << Candidates[i][j].CNIC_ << endl;
            if (j < MAx_CANDIDATES - 1) 
            {
                outfile << endl;
            }
        }
    }
    outfile.close();
        cout << " data saved to file.\n";
    }
    else 
    {
        cout << "Unable to open the file for writing.\n";
    }  
}

void Pa_Management(){
    int option;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "************************************************************ PROVINTIAL ASSEMBLY CANDIDATE ************************************************************" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    do{
        cout<<"Select which function do you want to perform.\n";
        cout<<"\n1. Add Data";
        cout<<"\n2. View Data";
        cout<<"\n3. Save Data ";
        cout<<"\n4. Exit\n";

        cin>>option;
        switch (option) {
            case 1:
            int Constituency_number;
            AddMenu();
            break;

            case 2:
            View_candidates(Num_constituencies);
            break;

            case 3:
            Save_to_file(Candidates);
            break;

            case 4:
            break;
            
            default:
            cout<<"Invalid option\n";
            break;
            }
        }
    while(option!=4);
}