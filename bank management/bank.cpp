#include <iostream>
#include <string>
using namespace std;
class account{
    private:
    int accno;
    string name;
    string acctype;
    public:
    void getAccountDetails(){
        cout<<"Enter customer name"<<endl;
        cin.ignore();
        getline(cin,name);
        cout<<"Enter account number"<<endl;
        cin>>accno;
        cout<<"Enter account type"<<endl;
        cin.ignore();
        getline(cin,acctype);
    }
    public:
    void displayDetails(){
        cout<<"Name :"<<name<<endl;
        cout<<"Account number :"<<accno<<endl;
        cout<<"account type :"<<acctype<<endl;
    }
};
class current_account:public account{
    private:
    float balance=0.0f;
    public:
    float deposit;
    void c_deposit(){
        cout<<"Enter amount to Deposite"<<endl;
        cin>>deposit;
        balance=balance+deposit;

    }
    void displayBalance(){
        cout<<"\nBalance : "<<balance<<endl;
    }
    void c_withdraw(){
        float withdraw;
        cout<<"\n Balance : "<<balance<<endl;
        cout<<"\nEnter the account to Withdraw"<<endl;
        cin>>withdraw;
        if(balance>1000){
            balance=balance-withdraw;
            cout<<"\n Balance Amount After Withdraw :"<<balance<<endl;
        }
        else{
            cout<<"\n Insufficient Balance";
        }
    }
};
class saving_account:public account{
    private:
    float sav_balance=0.0f;
    public:
    float deposit,interest;
    void s_deposit(){
        cout<<"Enter amount to Deposite"<<endl;
        cin>>deposit;
        sav_balance=sav_balance+deposit;
        interest=(sav_balance*2)/100;
        sav_balance=sav_balance+interest;
    }
    void displaySav_Balance(){
        cout<<"\nBalance :"<<sav_balance<<endl;
    }
    void s_withdraw(){
    float withdraw;
        cout<<"\n Balance : "<<sav_balance<<endl;
        cout<<"\nEnter the account to Withdraw"<<endl;
        cin>>withdraw;
        if(sav_balance>500){
            sav_balance=sav_balance-withdraw;
            cout<<"\n Saving Amount Balance After Withdraw :"<<sav_balance<<endl;
        }
        else{
            cout<<"\n Insufficient Balance";
        }
    }
};
int main(){
    current_account c1;
    saving_account s1;
    char type;
    cout<<"Enter s or S for Saving account and for current account enter c or C "<<endl;
    cin>>type;
    int choice;
    if(type=='s' || type=='S'){
        s1.getAccountDetails();
        s1.displayDetails();
        while(1){
            cout<<"\n Chooose your Choice"<<endl;
            cout<<"(1)   Deposit"<<endl;
            cout<<"(2)   Withdraw"<<endl;
            cout<<"(3)   Display Balance"<<endl;
            cout<<"(4)   Display with Full Details"<<endl;
            cout<<"(5)   Exit"<<endl;
            cout<<"Enter Your Choice"<<endl;
            cin>>choice;
            switch (choice)
            {
            case 1:
                s1.s_deposit();
                break;
            case 2:
                s1.s_withdraw();
                break;
            case 3:
                s1.displaySav_Balance();
                break;
            case 4:
                s1.displayDetails();
                s1.displaySav_Balance();
                break;
            case 5:
                goto end;
            default:
                cout << "Invalid choice!" << endl;
                break;
            }
        }
    }
    if(type=='c' || type=='C'){
        c1.getAccountDetails();
        c1.displayDetails();
        while(1){
            cout<<"\n Chooose your Choice"<<endl;
            cout<<"(1)   Deposit"<<endl;
            cout<<"(2)   Withdraw"<<endl;
            cout<<"(3)   Display Balance"<<endl;
            cout<<"(4)   Display with Full Details"<<endl;
            cout<<"(5)   Exit"<<endl;
            cout<<"Enter Your Choice"<<endl;
            cin>>choice;
            switch (choice)
            {
            case 1:
                c1.c_deposit();
                break;
            case 2:
                c1.c_withdraw();
                break;
            case 3:
                c1.displayBalance();
                break;
            case 4:
                c1.displayDetails();
                c1.displayBalance();
                break;
            case 5:
                goto end;
            default:
                break;
            }
        }
    }
    else{
        cout<<"invalid commmand"<<endl;
    }
    end:
    cout<<"\n Thank You for Banking with us"<<endl;
    return 0;
}