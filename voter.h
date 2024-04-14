#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <iomanip>

const int MAX_Votings= 10;
using namespace std;
struct Voting {
    int NAno;
    int PAno;
    string NAME;
    string _CNIC;
    int AGE;
};

void addVoting(Voting Votings[], int &VotingCount) {
   
    if (VotingCount < MAX_Votings) {
        cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "\nEnter Your CNIC (13-digits): \n";
        cin >> Votings[VotingCount]._CNIC;
        if(Votings[VotingCount]._CNIC.length()!=13){
            cout<<"ERROR: CNIC must be exactly 13 digits\n";
            return;
        }
        
        cout<<"Enter Your Full Name: \n";
        cin.ignore();
        getline(cin,Votings[VotingCount].NAME);

        cout << "Enter your Age:\n";
        int AGE;
        do {
            if (!(cin >> AGE)) {
             cerr << "Error: Invalid input. Please enter a number.\n";
             cin.clear();
             cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else if (AGE < 18) {
            cout << "ERROR: Age must be at least 25. Please re-enter:\n";
            }
            } while (AGE < 18);

        int NAno,PAno;
        cout << "Enter your NA number: ";
        cout<<"NA-";
        cin >> NAno;

        cout << "Enter your PA Number: ";
        cout<<"PA-";
        cin >> PAno;
 
        Votings[VotingCount].NAno = NAno;
        Votings[VotingCount].PAno = PAno;
        Votings[VotingCount].AGE = AGE;
        VotingCount++;

        cout << "vote added successfully.\n";
        cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
    } else {
        cout << "Maximum vote capacity reached.\n";
    }
}

void searchvoting(const Voting Votings[], int VotingCount) {
    string testCNIC;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Enter your CNIC to search: ";
    cin >> testCNIC;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl <<endl;
    bool found = false; // Initialize found to false
    cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(10) << "NA NUMBER" << setw(15) << "PA NUMBER" << setw(20) << "CNIC" << setw(15) << "NAME" << setw(20) << "AGE" << setw(15) << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < VotingCount; ++i) {
        if (Votings[i]._CNIC == testCNIC){
            found = true; // Set found to true only when a matching CNIC is found
            cout << setw(10) << Votings[i].NAno << setw(15) << Votings[i].PAno << setw(20) << Votings[i]._CNIC << setw(15) << Votings[i].NAME << setw(20) << Votings[i].AGE << setw(20) << endl;
            cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
            break; // Exit the loop once a matching CNIC is found
        }
    }

    if (!found) {
        cout << "VOTER not found." << endl;
    }
}

void viewVoting(const Voting Votings[], int VotingCount) {
    cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "VOTER DETAILS" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl <<endl <<endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(10) << "NA NUMBER" << setw(15) << "PA NUMBER" << setw(20) << "CNIC" << setw(15) << "NAME" << setw(20) << "AGE" << setw(15) << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;

     for (int i = 0; i < VotingCount; ++i) {
        cout << setw(10) << Votings[i].NAno << setw(15) << Votings[i].PAno << setw(20) << Votings[i]._CNIC << setw(15) << Votings[i].NAME << setw(20) << Votings[i].AGE << setw(20) << endl;
        cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
    }
}

void saveVotingToFile(const Voting Votings[], int VotingCount)
{
    ofstream outFile("VOTER.txt");

    if (outFile.is_open()) 
    {
        cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
        outFile << setw(10) << "NA NUMBER" << setw(15) << "PA NUMBER" << setw(20) << "CNIC" << setw(15) << "NAME" << setw(20) << "AGE" << setw(15) << endl;
        cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
        for (int i = 0; i < VotingCount; ++i) 
        {

        outFile << setw(10) << Votings[i].NAno << setw(15) << Votings[i].PAno << setw(20) << Votings[i]._CNIC << setw(15) << Votings[i].NAME << setw(20) << Votings[i].AGE << setw(20) << endl;
        cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl <<endl;
        }
        outFile.close();
        cout << "Vote saved to file successfully.\n";
    }
    else {
        cout << "Unable to open file for saving votes.\n";
          }
}
void loadVotingFromFile(Voting Votings[], int &VotingCount) {
    ifstream inFile("Voting.txt");

    if (inFile.is_open()) {
        while (inFile >> Votings[VotingCount].NAno >> Votings[VotingCount].PAno >> Votings[VotingCount].PAno >> Votings[VotingCount]._CNIC >> Votings[VotingCount].NAME >> Votings[VotingCount].AGE  ) {
            VotingCount++;
            if (VotingCount >= MAX_Votings) {
                break;
            }
        }
        inFile.close();
        cout << "vote loaded from file successfully.\n";
    }
    else
    {
        cout << "Unable to open file for loading votes. Starting with an empty Voting list.\n";
    }
}

void VotingManagement(Voting Votings[], int &VotingCount) {
    loadVotingFromFile(Votings, VotingCount);
    int option;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "************************************************************ VOTER MANAGEMENT ************************************************************" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    do{
    cout << "Menu\n";
    cout << "1. Add Data \n";
    cout << "2. Search Data\n";
    cout << "3. View Data\n";
    cout << "4. Save Data\n";
    cout << "5. Exit\n";

    cout << "Enter option: ";
    cin >> option;
    switch (option) {
        case 1:
            addVoting(Votings, VotingCount);
            break;
        case 2:
            searchvoting(Votings, VotingCount);
            break;
        case 3:
            viewVoting(Votings, VotingCount);
            break;
        case 4:
            saveVotingToFile( Votings, VotingCount);
            break;
        case 5:
            break;
        default:
            cout << "Invalid option!\n";
    }
      }
    while(option!=5);
}
