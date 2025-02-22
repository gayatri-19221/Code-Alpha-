#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void registeruser()
{
    string username,password;
    cout<<"Enter your valid username:";
    cin>>username;
    cout<<"Enter your valid password:";
    cin>>password;
    ofstream file(username +".txt");
    file<<username<<endl<<password;
    file.close();
    cout<<"Registration successful !\n";
}
bool loginuser()
{
    string username,password,u,p;
    cout<<"Enter your username:";
    cin>>username;
    cout<<"Enter your password:";
    cin>>password;
    ifstream file(username +".txt");
    if(file)
    {
        getline(file,u);
        getline(file,p);
        file.close();
        if (u==username && p==password)
        {
            cout<<"Login successful !\n";
            return false;
        }
    }
    cout<<"Invalid uername or password !\n";
    return false;
}
int main()
{
    int choice;
    do{
        cout<<"1.Register\n 2.Login\n 3.Exit\n Enter choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:registeruser();
            break;
            loginuser();
            break;
            case 3: 
            cout<<"Existing...\n";
            break;
            default :
            cout<<"Invalid choice!\n";
        }
    } 
    while (choice != 3);
    return 0;
}
