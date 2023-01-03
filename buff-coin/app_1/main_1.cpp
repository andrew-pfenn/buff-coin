#include <iostream>
#include <fstream>
#include "../code_1/Blockchain.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    Blockchain buffCUoin;

    buffCUoin.prettyPrint(); 

    cout << "ashutosh mining first block ... \n\n" << endl;
    buffCUoin.minePendingTransactions("ashutosh");
    buffCUoin.prettyPrint(); 
    
    cout << "ashutosh paid maciej 1 BFC ... " << endl;
    buffCUoin.addTransaction("ashutosh","maciej", 1);

    cout << "ashutosh paid asa 1 BFC ... " << endl;
    buffCUoin.addTransaction("ashutosh","asa", 1);
    cout << "asa mining second block ... \n\n" << endl;
    buffCUoin.minePendingTransactions("asa");
    buffCUoin.prettyPrint(); 
    
    cout << "asa paid ashutosh 1 BFC ... " << endl;
    buffCUoin.addTransaction("asa","ashutosh", 1);    
    cout << "ashutosh paid maciej 2 BFC ... " << endl;
    buffCUoin.addTransaction("asa","maciej", 2);
    
    cout << "maciej mining third block ... \n\n" << endl;
    buffCUoin.minePendingTransactions("maciej");
    buffCUoin.prettyPrint(); 
    
    cout << "ashutosh mining fourth block ... \n\n" << endl;
    buffCUoin.minePendingTransactions("ashutosh");
    buffCUoin.prettyPrint();

    bool quit = false;
    while(!quit){
        int option = 0;
        cout << "======Main Menu======" << endl;
        cout << "1. Add a transation" << endl;
        cout << "2. Verify Blockchain" << endl;
        cout << "3. Mine Pending Transactions" << endl;
        cout << "4. Print Blockchain" << endl;
        cout << "5. Quit\n";
        cin >> option;
        while(option < 1 || option > 5){
            cout << "ERROR invalid input \n";
            cin >> option;
        }
        string srx;
        string dsx;
        int coins;
        string mineAddress;

        switch(option){
            case 1:
                cout << "Enter the source \n";
                cin >> srx;
                cout << "Enter the destination \n";
                cin >> dsx;
                cout << "Enter the number of coins \n";
                cin >> coins;

                buffCUoin.addTransaction(srx, dsx, coins);
                break;
            case 2:
                if(buffCUoin.isChainValid() == true){
                    cout << "Blockchain verified. All blocks are valid. \n";
                }
                else{
                    cout << "Blockchain is not valid. Some test failed. \n";
                }
                break;
            case 3:
                cout << "Enter a mining adress. \n";
                cin >> mineAddress;
                buffCUoin.minePendingTransactions(mineAddress);
                break;
            case 4:
                buffCUoin.prettyPrint();
                cout << endl;
                break;
            case 5:
                cout << "\n Goodbye. \n";
                quit = true;
                break;
        }
    }
    return 0;
}
