#include<iostream>
#include<string>
using namespace std;
struct Account{
    string accountNumber;
    string accountHolderName;
    string password;
    double balance = 1000;
};

bool createAccount(Account &account) 
{
    long accNum;
    cout<<"\n\n\n\t\t================Sign Up Portal================\n\n\n";
    cout<<"\nPlease wait...";
    accNum = rand() % 10000000000 + 10000000000;
    account.accountNumber = to_string(accNum);
    cout << "\nYour account number is: " << account.accountNumber << endl;
    cout << "\nEnter Name : ";
    cin.ignore();
    getline(cin, account.accountHolderName);
    cout << "\nEnter at least 4 digit password : ";
    cin >> account.password;
    if (account.password.length() < 4) 
    {
        cout << "\nPassword should be at least 4 digits : ";
        createAccount(account);
    }
    cout << "\nAccount Created Successfully." << endl;
    return true;
}

bool signIn(Account &account) 
{
    cout << "\n\n\t\t================Login Portal================\n\n\n";
    string accountNum;
    string pass;
    cout << "You have three attempts." << endl;
    for(int i = 0; i < 3; i++)
    {
        cout << "\nEnter Account Number: ";
        cin >> accountNum;
        cout << "\nEnter Password: ";
        cin >> pass;
        if(accountNum == account.accountNumber && pass == account.password)
        {
            return true;
        }
        else
        {
            if (i < 2)
            {
                cout << "\nIncorrect Account Number or Password. Try Again." << endl;
            }
        }
    }
    cout<<"You Cann't Login Yet Try Again Later.";
    return false;
}


void depositAmount(Account &account)
{
    double amount;
    cout << "\nEnter Amount to be added : ";
    cin >> amount;
    if(amount>0)
    {
    account.balance += amount;
    cout << "\nAmount Added Successfully.";
    cout<<"\n Your new balance is : " << account.balance << endl;
    }
    else
    {
        cout<<"\nNegatives are not allowed";
        depositAmount(account);
    }
}

void withdrawAmount(Account &account) 
{
    double amount;
    cout << "\nEnter Amount to withdraw: ";
    cin >> amount;
    if (amount < account.balance && amount>0) 
    {
        account.balance -= amount;
        cout << "\nAmount Withdrawn Successfully" << endl;
        cout << "\nYour new balance is: " << account.balance << endl;
    } 
    else 
    {
        cout << "\nInsufficient Balance or Negative Input";
        withdrawAmount(account); 
    }
}

void accountHolderDetail(Account &account) 
{
    cout<<"\nAccount Number  : "<<account.accountNumber;
    cout<<"\nAccount Holder  : "<<account.accountHolderName;
    cout<<"\nAccount Balance : "<<account.balance;
}

void balanceEnquiry(Account &account)
{
   cout<<"Your Balance is : "<<account.balance<<" Rs."<<endl;
}

void changePassword(Account &account) 
{
    string oldPass;
    cout << "\nEnter your old password: ";
    cin >> oldPass;

    if (oldPass == account.password)
    {
        cout << "You have three attempts." << endl;
        
        for(int i = 0; i < 3; i++)
        {
            string newPass, confirmPass;

            cout << "\nEnter new password: ";
            cin >> newPass;
            cout << "\nConfirm new password: ";
            cin >> confirmPass;

            if(newPass == confirmPass)
            {
                if(newPass.length() < 4)
                {
                    cout << "\nPassword should be at least 4 characters." << endl;
                    continue; 
                }
                else
                {
                    account.password = newPass;
                    cout << "\nPassword changed successfully." << endl;
                    return;
                }
            }
            else
            {
                cout << "\nPasswords do not match. Try again." << endl;
            }
        }
        cout << "\nYou have used all three attempts. Password change failed." << endl;
    }
    else
    {
        cout << "\nInvalid old password." << endl;
    }
}

int main() 
{
    Account account;
    if (createAccount(account)) 
    {
        bool log_in = signIn(account);
        if (log_in) 
        {
            int choice;
            do 
            {
                cout << "\n\n\tONLINE BANKING SYSTEM";
                cout << "\n\t01. DEPOSIT AMOUNT";
                cout << "\n\t02. WITHDRAW AMOUNT";
                cout << "\n\t03. ACCOUNT HOLDER DETAIL ";
                cout << "\n\t04. BALANCE ENQUIRY";
                cout << "\n\t05. CHANGE PASSWARD";
                cout << "\n\t06. EXIT";
                cout << "\n\n\tSelect Your Option (1-6): ";
                cin >> choice;
                cout<<"\n\n";
                switch (choice) 
                {
                    case 1:
                        depositAmount(account);
                        break;
                    case 2:
                        withdrawAmount(account);
                        break;
                    case 3:
                        accountHolderDetail(account);
                        break;
                    case 4:
                        balanceEnquiry(account);
                        break;
                    case 5:
                        changePassword(account);
                        break;
                    case 6:
                        cout << "Thank you for using the banking system.\n";
                        exit(0);
                    default:
                        cout << "\n\tInvalid Option";
                }
            } 
            while (choice != 6);
        }
    } 
    else 
    {
        cout << "Account Not Found.\n";
    }
    return 0;
}