#include<iostream>
#include<string>
#include<fstream>
 
using namespace std;
const string DIRECTORY_PATH = "/Users/tejasdhawale/Desktop/WORK/100 cpp/Database_Login/"; 

struct User{
    string username;
    string password;
};

void Register(){
    User user;
    cout << "Enter your username: ";
    cin >> user.username;
    cout << "Enter your password: ";
    cin >> user.password;

    string filename = DIRECTORY_PATH + user.username + ".txt";
    //string filename = "users/" + user.username + ".txt"; 
    ifstream inFile(filename);

    if (inFile){
        cout<<"Username already exists, try logging in:  ";
        inFile.close();
        return;
    }

    ofstream outFile(filename);
    if(!outFile){
        cout<<"Error in creating the file";
        return;
    }
    outFile << user.username << "\n"<<user.password<<"\n";
    outFile.close();
    cout<<"Registration successful, you can now login:  ";
}

void Login(){
    string username, password;
    cout << "Enter your username: ";    
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;
    string filename = DIRECTORY_PATH + username + ".txt";
    ifstream inFile(filename);
    if(!inFile)
    {
        cout<<"username does not exist, try registering"<<endl;
        return;
    }

    string fileUsername, filePassword;
    inFile >> fileUsername >> filePassword;
    inFile.close();
    if(fileUsername == username && filePassword == password)
    {
        cout<<"Login successful"<<endl;
        }

    else
    {
        cout<<"Incorrect username or password"<<endl;
        }
}

int main(){
    int choice;
    cout << "1. Register\n2. Login\n";
    cin >> choice;
    switch (choice)
    {
        case 1:
        Register();
        break;
        case 2:
        Login();
        break;
        default:
        cout << "Invalid choice";
        break;
        }
        return 0;
}