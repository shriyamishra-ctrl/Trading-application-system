#include<iostream>
#include<string.h>
#include<conio.h>
#include<fstream>


using namespace std;

// Class created for binding
class Account
{
public:

    // Basic Variables declared
    int dogecoin=2000;
    int balance=50000;
    int bitcoin=1000;
    int my_dogecoin=0;
    int my_bitcoin=0;
    int no_stock=1000;
   float stock_value=150;
    int my_stock=0;
    int deposit, withdraw;
    float dogecoin_value=100;
    float bitcoin_value=200;

    // Deposit Cash
     Account operator +(int deposit)
    {
        cout<<"enter amount u want to deposit"<<endl;
        cin>>deposit;

        ofstream file("sdf4.txt");
        balance=balance+deposit;
        cout << "Deposit Amount = "<<deposit<<endl;
        cout<<"Current Balance is "<<balance<<endl;
        file<<"Current Balance = "<<balance<<"   "<<"Deposit Amount = "<<deposit<<"\n";
        file.close();

    }


    // Withdraw Cash
    Account operator - ( int  withdraw)
    {
        cout<<"Enter amount u want to withdraw"<<endl;
        cin>>withdraw;

        ofstream file("sdf4.txt");
        if (withdraw > balance) {
            cout<<"Insfficient Balance"<<endl;
        }

        balance=balance-withdraw;
        cout << "Withdrawn Amount = "<<withdraw<<endl;
        cout<<"Current Balance is "<<balance<<endl;
        file<<"Current Balance = "<<balance<<"   "<<"Withdraw Amount = "<<withdraw<<"\n";
        file.close();


    }

    // Buy Crypto function
     void buy()
    {
        int option;
        cout << "Want to purchase DOGECOIN press 1 else "
                "for BITCOIN press 2\n";
        cin >> option;

        if(option==1)
        {
            int no_dg;
            cout<<"enter no. of Dogecoin u want to buy"<<endl;
            cin>>no_dg;

            if(no_dg*dogecoin_value>balance)
            {
                cout<<"insufficient balance"<<endl;
            }

            else
            {
                my_dogecoin=my_dogecoin+no_dg;
                dogecoin=dogecoin-no_dg;
                balance=balance-no_dg*dogecoin_value;
                int x=rand();
                if(x%2==0){
                    dogecoin_value=dogecoin_value+0.02*dogecoin_value;
                }
                else{
                    dogecoin_value=dogecoin_value-0.02*dogecoin_value;

                }
                cout<<" current value of dogecoin is "<<dogecoin_value<<endl;
                cout<<"current a/c balance is "<<balance<<endl;
            }

        }

        if(option==2)
        {
            int no_bt;
            cout<<"enter no. of bitcoin u want to buy"<<endl;
            cin>>no_bt;

            if(no_bt*bitcoin_value>balance)
            {
                cout<<"insufficient balance"<<endl;
            }
            else
            {
                my_bitcoin=my_bitcoin+no_bt;
                bitcoin=bitcoin-no_bt;
                balance=balance-no_bt*bitcoin_value;
                cout<<"value of bitcoin is "<<bitcoin_value <<endl;
                cout<<"current a/c balance is "<<balance<<endl;
            }
        }
    }

    // Selling crypto function

     void sell()
    {
        int option;
        cout << "Want to sell dogecoin press 1 else for "
                "bitcoin press 2\n";
        cin >> option;

        if(option==1)
        {
            int no_dg;
            cout<<"enter no. of dogecoin u want to sell"<<endl;
            cin>>no_dg;

                my_dogecoin=my_dogecoin-no_dg;
                dogecoin=dogecoin+no_dg;
                balance=balance+(no_dg*dogecoin_value);
                int x=rand();
                if(x%2==0){
                    dogecoin_value=dogecoin_value+0.02*dogecoin_value;
                }
                else{
                    dogecoin_value=dogecoin_value-0.02*dogecoin_value;

                }
                cout<<"value of dogecoin is "<<dogecoin_value<<endl;
                cout<<"current a/c balance is "<<balance<<endl;


        }

        if(option==2)
        {
            int no_bt;
            cout<<"enter no. of bitcoin u want to sell"<<endl;
            cin>>no_bt;

                my_bitcoin=my_bitcoin-no_bt;
                bitcoin=bitcoin+no_bt;
                balance=balance+(no_bt*bitcoin_value);
                int x=rand();
                if(x%2==0){
                    bitcoin_value=bitcoin_value+0.02*bitcoin_value;
                }
                else{
                    bitcoin_value=bitcoin_value-0.02*bitcoin_value;

                }
                cout<<"value of bitcoin is "<<bitcoin_value <<endl;
                cout<<"current a/c balance is "<<balance<<endl;
        }


    }
    void Get_account_information()
    {
        ofstream file("sdf4.txt");

        cout << "Money Details:\n";
        cout << "Bank Balance:" << balance << endl;
        cout << "Dogecoin:" << my_dogecoin << endl;
        cout << "Bitcoin:" << my_bitcoin << endl;
        //cout << "Stocks:"<<my_stock<<endl;
        file<<"dogecoin = "<<my_dogecoin<<"   "<<" bitcoin = "<<my_bitcoin<<" current balance = "<<balance<<endl;
        file.close();
    }

    void check_crypto_value()
    {
        ofstream file("sdf4.txt");
         cout<<"value of dogecoin is "<<dogecoin_value<<endl;
         cout<<"value of bitcoin is "<<bitcoin_value <<endl;
        file<<"dogecoin value = "<<dogecoin_value<<"  "<<" bitcoin value = "<<bitcoin_value<<"  "<<endl;
        file.close();


    }
};

class stock : public Account
{

public:
   int no_stock=1000;
   float stock_value=150;
    int my_stock=0;

    void get_details2(){
    cout<<"stocks:"<<my_stock<<endl;
    }
    void buy()
    {
        int no_stock_b;
         cout<<"enter no. of stock u want to buy"<<endl;
            cin>>no_stock_b;

            if(no_stock_b*stock_value>balance)
            {
                cout<<"insufficient balance"<<endl;
            }
            else
            {
                my_stock=my_stock+no_stock_b;
                balance=balance-my_stock*stock_value;
                stock_value=stock_value;
                int x=rand();
                if(x%2==0){
                    stock_value=stock_value+0.02*stock_value;
                }
                else{
                    stock_value=stock_value-0.02*stock_value;

                }
                cout<<"value of stock is "<<stock_value <<endl;
                cout<<"current a/c balance is "<<balance<<endl;
            }

    }

    void sell()
    {
         int no_stock_s;
            cout<<"enter no. of stock u want to sell"<<endl;
            cin>>no_stock_s;

                my_stock=my_stock-no_stock_s;
                balance=balance+no_stock_s*stock_value;
                int x=rand();
                if(x%2==0){
                    stock_value=stock_value+0.02*stock_value;
                }
                else{
                    stock_value=stock_value-0.02*stock_value;

                }
                cout<<"value of stock is "<<stock_value <<endl;
                cout<<"current a/c balance is "<<balance<<endl;
    }
    void check_stock_value()
    {
        fstream file("sdf4.txt");
         cout<<" current value of stock is "<<stock_value<<endl;
        file<<"current stock value = "<<stock_value<<endl;
        file.close();

    }

};



int main()
{
    cout<<endl;
    cout<<"**************************"<<endl;
    cout<<"**************************"<<endl;
    cout<<"******WELCOME TO ONLINE TRADING SYSTEM -ACTIVE TRADER*****"<<endl;
    cout<<"**************************"<<endl;
    cout<<"**************************"<<endl;
    cout<<"______"<<endl;
    char password[11], username[] = "Admin", us[11], ch;
    int i = 0;
    bool isincorrect;
    while((isincorrect == false) )
    {
        cout << "ENTER USERNAME: ";
        cin >> us;
        if(strcmp(username, us) == 0)
        {
            cout << "ENTER PASSWORD: ";
            isincorrect = true;
            for(i = 0; i < 10; i++)
            {
                ch = getch();
                if(ch == 13)
                {
                    password[i] = '\0';
                    break;
                }
                else
                {
                    password[i] = ch;
                    cout << "*";
                }
            }
            if(strcmp(password, "Admin@123") == 0)
            {
                cout << "\nLogin successful\n";

    Account *person=new Account;
    stock *p1=new stock;
    Account obj;
    stock p;
    person=&p;
     p1=&p;
    int amount, choice;
    while (1) {

        cout <<"NOW MANAGE YOUR ACCOUNT AT YOUR OWN PACE"<<endl;
        cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;

        cout << endl;
        cout << "1.FOR ACCOUNT INFORMATION"
             << endl;
        cout << "2.TO DEPOSIT MONEY"
             << endl;
        cout << "3.TO WITHDRAW MONEY"
             << endl;
        cout << "4.TO BUY CRYPTO"
             << endl;
        cout<<  "5.TO BUY STOCK"<<endl;
        cout << "6.TO SELL CRYPTO"
             << endl;
        cout<<  "7.TO SELL STOCK"<<endl;
        cout<<  "8.TO KNOW ABOUT CURRENT CRYPTO MARKET"<<endl;
        cout<<  "9.TO KNOW ABOUT CURRENT STOCK MARKET"<<endl;
        cout << "PRESS ANY INVALID KEY TO EXIT \n"
             << endl;

        cout << "  "
                "**"
                "*  \n";

        cin >> choice;

        switch (choice) {
        case 1:
            person->Get_account_information();
            p1->get_details2();
            break;

        case 2:
             obj + (amount);

            break;

        case 3:
             obj - (amount);
            break;

        case 4:
              person->buy();
            break;

        case 5:
              p1->buy();
            break;
        case 6:
            person->sell();
            break;
        case 7:
            p1->sell();
            break;
        case 8:
            person->check_crypto_value();
            break;

        case 9:
            p.check_stock_value();
            break;

        default:
            exit(0);
            break;
        }

    }

            }
            else
            {
                cout << "\nWrong password\n";
            }
        }
        else
        {
            cout << "Wrong username\n";
        }
        i++;
    }



    return 0;
}
