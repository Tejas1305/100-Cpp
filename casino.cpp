/*Program to guess a number and win or loose money
The number will be randomly generated 
if the user gueses correctly the prize will 10X 
random number between 1-11*/

#include <iostream>
#include <random>
#include <string>

using namespace std;

int main(){
    int wallet = 0, guess, number,bet;

    cout<<"Enter the amount in your wallet";
    cin>>wallet;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 11);

    while (true){
        
        number = dis(gen);

        while(true){
        cout<<"How much would you like to bet? "<<endl;
        cin>> bet;
        if(bet > wallet){
            cout<<"You don't have enough money to bet that much"<<endl;
            }
        else if(bet <= 0){
            cout<<"You can't bet 0 or less"<<endl;
            }
        else{
            break;
            }
        }

        cout << "Guess a number between 1 and 11: ";
        cin >> guess;
        if(guess < 1 || guess > 11){
            cout << "You can't guess a number outside the range"<<endl;

            }
            else if(guess == number){
                wallet = wallet + bet * 10;
                cout <<"Computer Guess: "<<number<<endl;
                cout << "You guessed it! You won " << bet * 10 << " rupees!"<<endl;
                cout << "Your wallet now has " << wallet << " rupees."<<endl;
                }
            else{
                wallet = wallet - bet;
                cout <<"Computer Guess: "<<number<<endl;
                cout << "You lost " << bet << " rupees!"<<endl;
                cout << "Your wallet now has " << wallet << " rupees."<<endl;
                }
            if(wallet <= 0){
                cout << "You ran out of money! Game over."<<endl;
                return 0;
                }
                }
    return 0;
                        
        

    }


