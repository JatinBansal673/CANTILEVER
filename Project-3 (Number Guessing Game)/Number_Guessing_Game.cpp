#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main()
{
    int guess_num,system_num,level;
    cout<<"Welcome To The Number Guessing Game"<<endl;
    cout<<"Guess the Right number between 1 to 100 to WIN the game."<<endl;
    cout<<"Enter The difficulty level (Number of chances decreases with increase in difficulty): "<<endl;
    cout<<"Press 1 for Easy"<<endl;
    cout<<"      2 for Moderate"<<endl;
    cout<<"      3 for Difficult"<<endl;
    cout<<"      0 to EXIT"<<endl;
    cin>>level;
    srand(time(0));
    system_num=1+(rand()%100);
    switch(level)
    {
        case 1:
        {
            int chances=0;
            cout<<"EASY LEVEL"<<endl;
            cout<<"Number of chances=7"<<endl;
            do
            {
                cout<<"Enter the number between 1 to 100: ";
                cin>>guess_num;
                chances++;
                if(guess_num<system_num)
                {
                    cout<<"The Number you entered is LESS than the system generated number."<<endl;
                }
                else
                {
                    if(guess_num>system_num)
                    {
                        cout<<"The Number you entered is GREATER than the system generated number."<<endl;
                    }
                    else
                    {
                        cout<<"Congratulations! You guessed the right number."<<endl;
                        break;
                    }
                }
                if(chances==7)
                {
                    cout<<"You Lose!!"<<endl;
                    cout<<"The System Generated Number was "<<system_num<<endl;
                }
            } while (chances!=7);
            break;
        }
        case 2:
        {
            int chances=0;
            cout<<"MODERATE LEVEL"<<endl;
            cout<<"Number of chances=5"<<endl;
            do
            {
                cout<<"Enter the number between 1 to 100: ";
                cin>>guess_num;
                chances++;
                if(guess_num<system_num)
                {
                    cout<<"The Number you entered is LESS than the system generated number."<<endl;
                }
                else
                {
                    if(guess_num>system_num)
                    {
                        cout<<"The Number you entered is GREATER than the system generated number."<<endl;
                    }
                    else
                    {
                        cout<<"Congratulations! You guessed the right number."<<endl;
                        break;
                    }
                }
                if(chances==5)
                {
                    cout<<"You Lose!!"<<endl;
                    cout<<"The System Generated Number was "<<system_num<<endl;
                }
            } while (chances!=5);
            break;
        }
        case 3:
        {
            int chances=0;
            cout<<"DIFFICULT LEVEL"<<endl;
            cout<<"Number of chances=3"<<endl;
            do
            {
                cout<<"Enter the number between 1 to 100: ";
                cin>>guess_num;
                chances++;
                if(guess_num<system_num)
                {
                    cout<<"The Number you entered is LESS than the system generated number."<<endl;
                }
                else
                {
                    if(guess_num>system_num)
                    {
                        cout<<"The Number you entered is GREATER than the system generated number."<<endl;
                    }
                    else
                    {
                        cout<<"Congratulations! You guessed the right number."<<endl;
                        break;
                    }
                }
                if(chances==3)
                {
                    cout<<"You Lose!!"<<endl;
                    cout<<"The System Generated Number was "<<system_num<<endl;
                }
            } while (chances!=3);
            break;
        }
        case 0:
        {
            cout<<"Game Exited Succesfully."<<endl;
            break;
        }
        default:
        {
            cout<<"Invalid Input."<<endl;
        }
    }
    return 0;
}
