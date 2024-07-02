#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

class user
{
    string username;
    int age;
    vector<string> interests;
    vector<user*> friends;
    vector<string> posts;
    public:
    
    user(string username,int age)
    {
        this->username=username;
        this->age=age;
    }
    
    string get_username()
    {
        return this->username;
    }
    void set_username(string username)
    {
        this->username=username;
    }

    int get_age()
    {
        return this->age;
    }
    void set_age(int age)
    {
        this->age=age;
    }

    vector<string> get_interests()
    {
        return interests;
    }
    void set_interests(const string& interest)
    {
        interests.push_back(interest);
        ofstream file;
        file.open("Profiles.txt",ios::app|ios::out);
        file<<username<<","<<age;
        for(auto element: interests)
        {
            file<<","<<element;
        }
        file<<endl;
        file.close();
    }

    vector<user*> get_friends()
    {
        return friends;
    }
    void add_Friend(user* user)
    {
        friends.push_back(user);
        ofstream frnds;
        frnds.open("frnds.txt",ios::app|ios::out);
        frnds<<username<<"-";
        for(auto element: friends)
        {
            frnds<<element->username<<" ";
        }
        frnds<<endl;
        frnds.close();
    }

    void post_message(const string& message)
    {
        posts.push_back(message);
    }
    vector<string> get_messages()
    {
        return posts;
    }
};

class networking
{
    vector<user*> users;
    public:
    string logginginfo()
    {
        string username,password,user_id,pass;
        string ch;
        ifstream fin;
        cout<<"Enter Username: ";
        cin>>username;
        cout<<"Enter Password: ";
        cin>>password;
        fin.open("Registration.txt",ios::in);
       while(fin>>user_id>>pass)
       {
            if(username==user_id && password==pass)
            {
                cout<<"Login Successful"<<endl;
                return username;
            }
       }
       cout<<"Incorrect credentials. Please Try again."<<endl;
       fin.close();
       return "NULL";
    }
    void create_user(const string& name,const string& password,int age,const string& interest)
    {
        user* newuser=new user(name,age);
        newuser->set_interests(interest);
        users.push_back(newuser);
        ofstream fout;
        fout.open("Registration.txt",ios::app|ios::out);
        fout<<name<<" "<<password<<endl;
        fout.close();
        cout<<"User Created Successfully"<<endl;
    }
    user* find_user(const string& username)
    {
        for(user* user1:users)
        {
            if(user1->get_username()==username)
            {
                return user1;
            }
        }
        return nullptr;
    }
    void add_Friendship(user* user1,user* user2)
    {
        user1->add_Friend(user2);
        user2->add_Friend(user1);
    }

    void post_messsage(const string& from,const string& to,const string& message)
    {
        user* sender=find_user(from);
        user* receiver=find_user(to);
        if(sender && receiver)
        {
             receiver->post_message(message);
        }
        else
        cout<<"User not Found"<<endl;
    }
    
    void display_messages(const string& username) {
        user* user1 = find_user(username);
        if (user1) {
            vector<string> messages = user1->get_messages();
            cout << "Messages for " << user1->get_username() << ":" << endl;
            for (const string& msg : messages) {
                cout << "- " << msg << endl;
            }
        } else {
            cout << "User not found." << endl;
        }
    }

    void display_friends(const string& username)
    {
        user* user1=find_user(username);
        if(user1)
        {
            vector<user*> friends=user1->get_friends();
            cout<<"Friends of "<<user1->get_username()<<":"<<endl;
            for(user* userfriend: friends)
            {
                cout<<" "<<userfriend->get_username()<<endl;
            }
        }
        else
        cout<<"User not Found"<<endl;
    }
}; 
int main()
{
    networking profile;
    string check;
    int i;
    do
    {
        cout<<"Please Select an Option:"<<endl;
        cout<<"1.Create a new user"<<endl;
        cout<<"2.Login for existing user"<<endl;
        cout<<"3.Find a User"<<endl;
        cout<<"4.Add Friendship with a User"<<endl;
        cout<<"5.Post a message to the friend"<<endl;
        cout<<"6.Display the Messages"<<endl;
        cout<<"7.Display friends list"<<endl;
        cout<<"8.Logout"<<endl;
        cin>>i;

        switch(i)
        {
            case 1:
            {
                string name,password,interests;
                int age;
                cout<<"Enter Username: ";
                cin>>name;
                cout<<"Enter Age: ";
                cin>>age;
                cout<<"Enter Interests: ";
                cin>>interests;
                cout<<"Set Password: ";
                cin>>password;
                profile.create_user(name,password,age,interests);   
                break;
            }
            case 2:
            {
                check=profile.logginginfo();
                if(check=="NULL")
                {
                    cout<<"Please Create An Account First."<<endl;
                    break;
                }
                else
                cout<<"Logged In as: "<<check<<endl;
                break;
            }
            case 3:
            {
                user* user_XYZ=profile.find_user(check);  
                if(user_XYZ==nullptr)
                {
                    cout<<"Please Login First."<<endl;
                    break;
                } 
                else
                {
                    string name;
                    cout<<"Enter the Name of the user to find: ";
                    cin>>name;
                    user* name1=profile.find_user(name);
                    if(name1!=nullptr)
                    {
                        cout<<"User Found"<<endl;
                    }
                    else
                    cout<<"User does not exist."<<endl;
                }
                break;
            }
            case 4:
            {
                user* user_XYZ=profile.find_user(check);  
                if(user_XYZ==nullptr)
                {
                    cout<<"Please Login First."<<endl;
                    break;
                } 
                else
                {
                    string friend_name;
                    cout<<"Enter name of the user to add as a friend: ";
                    cin>>friend_name;
                    user* friend_name1=profile.find_user(friend_name);
                    if(user_XYZ && friend_name1)
                    {
                        profile.add_Friendship(user_XYZ,friend_name1);
                        cout<<"Friendship Added Successfully."<<endl;
                    }
                }
                break;
            }
            case 5:
            {
                user* user_XYZ=profile.find_user(check);  
                if(user_XYZ==nullptr)
                {
                    cout<<"Please Login First."<<endl;
                    break;
                }
                else
                {
                    string message,friend_name;
                    cout<<"Enter the Message to post: ";
                    cin.ignore();
                    getline(cin,message);
                    cout<<"Enter Friend's name to send this message to: ";
                    cin>>friend_name;
                    profile.post_messsage(check,friend_name,message);
                    cout<<"Message posted successfully."<<endl;
                }
                break;
            }
            case 6:
            {
                user* user_XYZ=profile.find_user(check);  
                if(user_XYZ==nullptr)
                {
                    cout<<"Please Login First."<<endl;
                    break;
                }
                else
                {
                    profile.display_messages(check);
                }
                break;
            }
            case 7:
            {
                user* user_XYZ=profile.find_user(check);  
                if(user_XYZ==nullptr)
                {
                    cout<<"Please Login First."<<endl;
                    break;
                }
                else
                {
                    profile.display_friends(check);
                }
                break;
            }
            case 8:
            {
                cout<<"Logged Out Successfully"<<endl;
                break;
            }
            default:
            cout<<"Invalid Input"<<endl;
        }
    }while(i!=8);
    return 0;
}    