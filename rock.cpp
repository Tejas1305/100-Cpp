#include <iostream>
#include <unordered_map>
#include <string>
#include <random>

using namespace std;

int main()
{  
    unordered_map<string, string> map = {{"Rock","Scissor"},{"Paper","Rock"},{"Scissor", "Paper"}};
    string choices[]= {"Rock","Paper","Scissor"};
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, 2);
    
    string comp_choice = choices [dist(gen)];
    string player;
    
    while(true){

    cout << "Choose: Rock, Paper, or Scissor" << endl;
    cin >> player;

    player[0] = toupper(player[0]);
    for( int i = 1; player[i] != '\0'; i++ )
        player[i] = tolower(player[i]);

    if(map.find(player)==map.end()){
        cout<<"Invalid Choice"<<endl;
    }
    else {
        break;
    }
}

if(player == comp_choice)
cout<<"it's a tie";
else if(map[player]==comp_choice)
cout<<"You wins";
else
cout<<"Computer wins";

    

    return 0;
}