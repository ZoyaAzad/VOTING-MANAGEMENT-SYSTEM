#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

struct NA_candidate {
    string name;
    string party_name;
    int  age;
    string CNIC; 
};

const int MAX_CONSTITUENCIES = 10;
const int MAX_CANDIDATES = 100;
NA_candidate candidates[MAX_CANDIDATES][MAX_CONSTITUENCIES];
int num_constituencies = 0;
int num_candidates = 0;

void add_candidates(int constituency_number) {
    char add_Data;
    int num_candidates_in_constituency = 0;  // Keep track of the number of candidates added to this constituency

    // If the constituency number is greater than the current number of constituencies, add a new constituency
    if (constituency_number >= num_constituencies) {
        num_constituencies = constituency_number + 1;
    }

    do{

        if (num_candidates_in_constituency < MAX_CANDIDATES) {
            cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "\nEnter CNIC of the Candidate: \n";
            cin >> candidates[constituency_number][num_candidates_in_constituency].CNIC;
            if(candidates[constituency_number][num_candidates_in_constituency].CNIC.length()!=13){
                cout<<"ERROR: CNIC must be exactly 13 digits\n";
                return;
            }

            cout<<"Enter Candidates Name: \n";
            cin.ignore();
            getline(cin,candidates[constituency_number][num_candidates_in_constituency].name);

            cout << "Enter Age:\n";
            int age;
            do {
                if (!(cin >> age)) {
                    cerr << "Error: Invalid input. Please enter a number.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else if (age < 25) {
                    cout << "ERROR: Age must be at least 25. Please re-enter:\n";
                }
            } while (age < 25);
            candidates[constituency_number][num_candidates_in_constituency].age = age;

            cout<<"Enter party name: \n";
            cin.ignore();
            getline(cin,candidates[constituency_number][num_candidates_in_constituency].party_name);

            num_candidates_in_constituency++;
            cout << "Candidate added successfully!" << endl;
            cout<<"Enter Y or y if you want to add more data for the same constituency or press anything else to exit \n";
            cin>>add_Data;
            cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
        } 
    }
    while (add_Data=='y' || add_Data=='Y');
    num_candidates += num_candidates_in_constituency;  // Update the global variable
}
void addMenu(){
    int counter = 0;
    int constituency;
    do { 
        cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout<<"Select your Constituency Number to add data.\n";
        cout<<"1.   NA-11";
        cout<<"\n2.  NA-15";
        cout<<"\n3.  NA-45";
        cout<<"\n4.  NA-52";
        cout<<"\n5.  NA-59";
        cout<<"\n6.  NA-69";
        cout<<"\n7.  NA-45";
        cout<<"\n8.  NA-23";
        cout<<"\n9.  NA-67";
        cout<<"\n10. NA-76";
        cout<<"\n11. EXIT";
        cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cin>>constituency;

        switch(constituency){
            case 1:
               add_candidates(0);
                break;
            case 2:
               add_candidates(1);
                break;
            case 3:
                add_candidates(2);
                break;
            case 4:
                add_candidates(3);
                break;
            case 5:
                add_candidates(4);
                break;
            case 6:
                add_candidates(5);
                break;
            case 7:
                add_candidates(6);
                break;
            case 8:
                add_candidates(7);
                break;
            case 9:
                add_candidates(8);
                break;
            case 10:
                add_candidates(9);
                break;    
            case 11:     
                break;
            default:
                cout<<"Invalid option\n";
                break;
        }
        if (num_constituencies < MAX_CONSTITUENCIES) {
            num_constituencies++;
        }
    } while (constituency > 10 || constituency<1);
}
void view_candidates(int num_constituencies) {
    if (num_constituencies == 0) {
        cout << "No candidates added yet." << endl;
    } else {
        for (int i = 0; i < num_constituencies; i++) {
            cout << "Constituency " << i+1  << ":" << endl;
            for (int j = 0; j < num_candidates; j++) {
                if (candidates[i][j].age == 0) {
                    break;
                }
                cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
                cout << "\t\t\tName: " << candidates[i][j].name << endl;
                cout << "\t\t\tParty name: " << candidates[i][j].party_name << endl;
                cout << "\t\t\tAge: " << candidates[i][j].age << endl;
                cout << "\t\t\tCNIC: " << candidates[i][j].CNIC << endl;
                cout << endl;
                cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
            }
        }
    }
}

void save_to_file(const NA_candidate candidates[MAX_CANDIDATES][MAX_CONSTITUENCIES])
{
      ofstream fout;
      fout.open("NA.txt");
     
      if (fout.is_open()) 
    {

    for (int i = 0; i < MAX_CONSTITUENCIES; i++) 
    {
        for (int j = 0; j < MAX_CANDIDATES; j++) 
        {
            if (candidates[i][j].age == 0) 
            {
                break;
            }
            fout << candidates[i][j].name << endl;
            fout << candidates[i][j].party_name << endl;
            fout << candidates[i][j].age << endl;
            fout << candidates[i][j].CNIC << endl;
            if (j < MAX_CANDIDATES - 1) 
            {
                fout << endl;
            }
        }
    }
    fout.close();
        cout << " data saved to file.\n";
    }
    else 
    {
        cout << "Unable to open the file for writing.\n";
    }  
}

void Na_Management(){
    int Option;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "************************************************************ NATIONAL ASSEMBLY CANDIDATE ************************************************************" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    do{
        cout<<"Select which function do you want to perform.\n";
        cout<<"\n1. Add Data";
        cout<<"\n2. View Data";
        cout<<"\n3. Save Data ";
        cout<<"\n4. Exit\n";

        cin>>Option;
        switch (Option) {
            case 1:
            addMenu();
            break;

            case 2:
            view_candidates(num_constituencies);
            break;

            case 3:
            save_to_file(candidates);
            break;

            case 4:
            break;

            default:
            cout<<"Invalid option\n";
            break;
            }
        }
    while(Option!=4);
}