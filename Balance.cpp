// Mina Moslehpour
// Section 2

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;


struct PERSON {
    char Name[20];
    float Balance;
};

void printmenu();
int gLine();
PERSON *readData (int N);
void Display(PERSON a[], int N);
void FindRichest(PERSON a[], int N);
void Deposit(PERSON a[], int N, string CustName, float amount);
void NewCopy(string fname, PERSON a[], int N);




int main()
{
    int N = gLine();
    int choice;
    float amount;
    PERSON *a = new PERSON[N];
    a = readData(N);
    
    char CustName[20];
    cin.getline(CustName, 20);
   

    do
    {
        printmenu();
        cin >> choice;
        switch(choice)
        {
            case 1:
                Display(a, N);
                break;

            case 2:
                 Deposit(a, N, CustName, amount);

                break;

            case 3:
                FindRichest(a, N);
                break;

            case 4:
                NewCopy("data.txt", a, N);
                break;

            case 5:
                Display(a, N);
                break;

            default:
                cout << "Invalid entry" << endl;
                break;
        }
        cout << endl;

   } while(choice != 5);

    return 0;
}


void printmenu() {
    cout << "Please enter a choice:" << endl;
    cout << "1. Display records"<< endl;
    cout << "2. Deposit funds"<< endl;
    cout << "3. Find Highest Balance" << endl;
    cout << "4. Update records" << endl;
    cout << "5. Exit the program" << endl;
}


// to get lines
int gLine() {
   
    int N = 0;
    ifstream file;
    file.open("data.txt");
    

    string line;
    if (file.fail()) {
        cout << "Sorry, file does not exsit." << endl;
        exit(1);
    }
    else {
        while (getline(file, line))  // read from file line by line
        N++;
    }

    file.close();
    return N;
}




PERSON *readData (int N) {

    PERSON *a = new PERSON[N];  //  person with size of n ; using new to allocates amout of memory needed
    string fname, lname;
    float amount;

    ifstream file;
    file.open("data.txt");

    for (int i = 0; i < N; i++) {
        file >> fname >> lname >> a[i].Balance;
        strcpy(a[i].Name, (fname + " " + lname).c_str());

    }
    file.close();
    return a;
}


//  Display all records in array
void Display(PERSON a[], int N) // void printArray (int myArray[], int size)
{

    cout << setprecision(2) << fixed;
    cout << setw(20) << left << endl << "Name" << " Balance" << endl;
    cout << "-------------------------------------" << endl;
    for (int i = 0; i < N; i++) {
        cout << setw(20) << a[i].Name << " " << a[i].Balance << endl ;
    }
}


// Display the name of customer with maximum balance
void FindRichest(PERSON a[], int N)
{
    int max = 0;
    for (int i = 0; i < N; i++) {
        if (a[max].Balance < a[i].Balance)
            max = i;
    }

    cout << endl << "The customer with maximum balance is " << a[max].Name << endl;
}

// Allow a customer to deposit money in his/her account
void Deposit(PERSON a[], int N, string CustName, float amount) 
{
    cout << "Enter name to deposit: " << endl;
    cin.ignore();
    getline (cin, CustName);

    for (int i = 0; i < N; i++) {
        if (strcmp(a[i].Name, CustName.c_str() ) == 0) {
            cout << "Amount to deposit: " << endl;

            float amount = 0;
            cin >> amount;
            cin.ignore();
            a[i].Balance += amount;
            cout << "New Balance: " << a[i].Balance << endl;
        }

        else if (strcmp(a[i].Name, CustName.c_str() ) == 1) {
            cout << "Record not found." << endl;
        }
    }

}



// turn in a copy of the file with the new updated records
void NewCopy(string fname, PERSON a[], int N)  
{

    ofstream outfile;
    outfile << setprecision(2) << fixed;
    outfile.open(fname.c_str());

    for (int i = 0; i < N; i++) {

        outfile << a[i].Name << " " << a[i].Balance << endl;

    }
    cout << "File Updated. . ." << endl;
    outfile.close();
}
