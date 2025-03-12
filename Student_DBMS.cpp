#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <vector>
#include <sstream>

using namespace std;

class Student {
    public:
    string name, email, password, course, parent_name;
    int age,computer_code;
    long int number;

    void new_entry(const string& filename){

        cout<<"Enter FullName: ";
        cin.ignore();
        getline(cin, name);

        name[0] = toupper(name[0]);
        for(int i = 1; i < name.length(); i++){
            if(name[i-1]!= ' '){

                name[i] = tolower(name[i]);
            }
            else{
                name[i] = toupper(name[i]);
            }
        }
        
        label:
        cout << "Enter Email: ";
        cin >> email;

        if (email.find('@') == string::npos) {  
            cout << "Invalid email! '@' missing." << endl;
            goto label;
        }
    

        cout<<"Enter Password: ";
        cin>>password;


        cout<<"Enter Course: ";
        cin>>course;
        cout<<"Enter Parent Name: ";
        cin>>parent_name;
        cout<<"Enter Age: ";
        cin>>age;
        cout<<"Enter Computer Code: ";
        cin>>computer_code;
        
        label1:
        cout<<"Enter Number: ";
        cin>>number;
        if (number <= 0) {
            cout << "Invalid number! Please enter a positive number." << endl;
            goto label1;
        }

        ofstream file(filename, ios::app); 
        if (!file) {
            cerr << "Error opening file!" << endl;
            return;
        }

        file<<computer_code<<","<<name<<","<<number<<","<<email<<","<<age<<","<<course<<","<<password<<endl;

        file.close();
        cout << " Entry added successfully!!"<<endl;
    }

    void login(const string& filename){
            string input_computer_code, input_password;
            
            cout << "Enter computer code: ";
            cin >> input_computer_code;
            cout << "Enter password: ";
            cin >> input_password;
            
            ifstream file(filename);
            if (!file) {
                cout << "Error opening file!" << endl;
                return;
            }
        
            string line, storedCode, storedName, storedNumber, storedEmail, storedAge, storedCourse, storedPassword;

    
        while (getline(file, line)) {
            istringstream ss(line); // Convert line to string stream for parsing

        // Read values separated by commas
            getline(ss, storedCode, ',');      // Extract stored computer code
            getline(ss, storedName, ',');      // Extract stored name
            getline(ss, storedNumber, ',');    // Extract stored phone number
            getline(ss, storedEmail, ',');     // Extract stored email
            getline(ss, storedAge, ',');       // Extract stored age
            getline(ss, storedCourse, ',');    // Extract stored course
            getline(ss, storedPassword, ',');  // Extract stored password

            // Check if the entered credentials match stored credentials
            if (storedCode == input_computer_code && storedPassword == input_password) {
                cout << "Login successful!!" << endl;
            
                // Display student details
                cout << "\nStudent Info:\n";
                cout << "Computer Code: " << storedCode << endl;
                cout << "Name: " << storedName << endl;
                cout << "Phone Number: " << storedNumber << endl;
                cout << "Email: " << storedEmail << endl;
                cout << "Age: " << storedAge << endl;
                cout << "Course: " << storedCourse << endl;
            
                file.close();  // Close the file and return
                return;
            }
        }

        // If the loop completes without finding a match, login failed
        cout << "Invalid login credentials!" << endl;
        file.close();  // Close the file
    }
        
    
    /*void displayStudentInfo(){
        cout << "\nStudent Info:\n";
        cout << "Computer Code: " << computer_code << endl;
        cout << "Name: " << name << endl;
        cout << "Phone Number: " << number << endl;
        cout << "Email: " << email << endl;
        cout << "Age: " << age << endl;
        cout << "Course: " << course << endl;

        cout << "Student information not found!" << endl;
        file.close();
    }*/

    
};
        

    int main(){
        Student s;
        string filename = "students.csv";

        ifstream testFile(filename);
        bool fileExists = testFile.good();
        testFile.close();
        
        ofstream file(filename,ios::app);
        if(!file){
            cout << "Error creating file";
            return 1;
        }

        if(!fileExists){
        file<<"computer_code,name,number,email,age,course,password\n";
        }
        file.close();

        int choice;
        cout << "Welcome to the student management system" << endl;
    

    while(true){
        cout<<"1.New Entry\n 2.Login\n3.Exit\n";
        cin>>choice;
        switch (choice) {
            case 1:
                s.new_entry(filename);
                break;
            case 2:
                s.login(filename);
                break;
            case 3:
                cout << "Exiting program..." << endl;
                exit(0);
            default:
                cout << "Invalid choice! Please try again.\n";
                return 0;
        }
    }
}

