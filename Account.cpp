#include <iostream>

using namespace std;

class Account
{
private:
    string userData = "";
    string passData = "";

public:
    void setUserData(string userData)
    {
        this->userData = userData;
    }

    void setPassData(string passData)
    {
        this->passData = passData;
    }

    string getUserData()
    {
        return this->userData;
    }

    string getPassData()
    {
        return this->passData;
    }

    void drawScreen()
    {
        cout << "{<<========================>>}\n||    WELCOME TO NETBOOK    ||\n{<<========================>>}" << endl;
        cout << "1.) Log In Account\n2.) Create Account\n3.) Quit" << endl;
        cout << "Input: ";
    }

    void drawCreateAccount()
    {
        cout << "{<<========================>>}\n||      Create Account      ||\n{<<========================>>}" << endl;
    }

    void drawLogIn()
    {
        cout << "{<<========================>>}\n||      LOG IN ACCOUNT      ||\n{<<========================>>}" << endl;
    }

    void drawAccount()
    {
        cout << "{<<========================>>}\n||      ACCOUNT LOG IN      ||\n{<<========================>>}" << endl;
        cout << "Welcome " << this->userData << endl;
    }
};

int main()
{
    Account account;
    string username;
    string password;
    string button = "1.) Back in Menu (Y/N)";
    char btn;
    int input;
    bool check = false;
    do
    {

        account.drawScreen();
        cin >> input;

        cout << endl;
        if (input == 1)
        {
            do
            {
                if (account.getUserData() == "" && account.getPassData() == "")
                {
                    cout << "The user account has not been created yet" << endl;
                    break;
                }
                account.drawLogIn();
                cout << "Username: ";
                getline(cin >> ws, username);
                cout << "Password: ";
                getline(cin >> ws, password);
                if (username.compare(account.getUserData()) == 0 && password.compare(account.getPassData()) == 0)
                {
                    cout << "Login successful" << endl;
                    cout << endl;
                    account.drawAccount();
                    check = true;
                    break;
                }
                cout << "Invalid username or password" << endl;
                cout << button;
                cin >> btn;
                if (btn == 'y')
                {
                    break;
                }
                cout << endl;
            } while (true);
        }
        else if (input == 2)
        {
            do
            {
                account.drawCreateAccount();
                cout << "Input Username: ";
                getline(cin >> ws, username);
                cout << "Input Password: ";
                getline(cin >> ws, password);
                if (!(username.empty()) || !(password.empty()))
                {
                    cout << "Account Created" << endl;
                    account.setUserData(username);
                    account.setPassData(password);
                    cout << endl;
                    break;
                }
                cout << "Username & Password should not be empty" << endl;
                cout << button;
                cin >> btn;
                if (btn == 'y')
                {
                    break;
                }
                cout << endl;
            } while (true);
        }
        else if (input == 3)
        {
            cout << "Terminated" << endl;
            check = true;
        }

    } while (!check);
}