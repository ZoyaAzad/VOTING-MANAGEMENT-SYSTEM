#include <iostream>
#include "NA.h"
#include "PA.h"
#include "voter.h"
using namespace std;

int main() {

    NA_candidate candidates[MAX_CONSTITUENCIES][MAX_CANDIDATES];
    PA_candidate Candidates[MAx_CONSTITUENCIES][MAx_CANDIDATES];
    Voting Votings[MAX_Votings];
    int VotingCount = 0;

    loadVotingFromFile(Votings, VotingCount);

    while (true) {
        cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "****************************************************** VOTING MANAGEMENT SYSTEM ******************************************************" << endl;
        cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;

        cout << "Menu:\n";
        cout << "1. NA Candidates (National Assembly)\n";
        cout << "2. PA Candidates (Provintial Assembly)\n";
        cout << "3. Voting System\n";
        cout << "4. Save and Quit\n";
        cout << "Enter an option: ";
        int option;
        cin >> option;

        switch (option) {
            case 1:
                Na_Management();
                break;
            case 2:
                Pa_Management();
                break;
            case 3:
                VotingManagement(Votings, VotingCount);
                break;
            case 4:
                cout<<"\n";
                cout << "Program ends\n";
                return 0;
           
            default:
                cout << "Invalid option!\n";
        }
    }
    return 0;
}