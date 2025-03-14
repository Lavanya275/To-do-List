#include <iostream>
#include <string> 
#include <list>
#include <ctime>
//when using std::string, you have to include <string> header file, as otherwise the compliler doesn't know what std::string means
using namespace std;

//define a variable
int next_id=1;

class Todoitem{
private:
    int id;
    string description;
    bool completed;
public:
//make a constructor with empty to do item body: so when i first make an instance of the class then an empty to do item will be created
    Todoitem(): id(0), description(""), completed(false){};
//a default destructor implementation is generated automatically: does cleanup process
    ~Todoitem()=default;
    int getid(){
        return id;
    }

    string getdescription(){
        return description;
    }

    bool iscompleted(){
        return completed;
    }

    void set_completed(bool val){
        completed=val;
    }

    bool create(string new_description){
        id=next_id++; //increments and counts 
        description=new_description;
        return true;
    }

    
};

    


int main(){
    
//std::list creates a doubly linked list using the Standard Template Library
    list<Todoitem> tdm;
    list<Todoitem>::iterator it;
    int input_id;
    srand(time(NULL));
    tdm.clear();
    
    while (1){
        //clears the screen after every loop
        system("clear");
        cout<<"To-do list maker"<<endl;
        cout<<endl<<endl;

        //iterators are pointers so instead of (*ptr).method(), you would do ptr->method
        for (it=tdm.begin(); it!=tdm.end(); it++){

            //to make it userfriendly mark 0/1 as not done/done
            string completed;
            if (it->iscompleted()){
                completed="done";
            }
            else {
                completed="not done";
            }
            
            cout<<it->getid()<<" | "<<it->getdescription()<<" | "<<completed<<endl;
        }
        
        if (tdm.empty()){
            cout<<"Add your first todo!"<<endl;
        }

        cout<<endl;
        
        //Making the menu
        cout<<endl<<"1. Press [a] to add a new to-do item"<<endl;
        cout<<"2. Press [c] to complete a to-do item"<<endl;
        cout<<"3. Press [q] to quit"<<endl;
        cout<<"Enter your choice: ";
        
        string choice;
        cin>>choice;

        //What would each choice do?
        if (choice=="q"){
            cout<<endl<<"Have a great day!!"<<endl;
            break;
        } 
        else if(choice=="c"){
            cout<<"What task do you wish to complete? ";
            cin>>input_id;
            for (it=tdm.begin(); it!=tdm.end(); it++){
                if (input_id == it->getid()){
                    it->set_completed(true);
                }
            }
        }
        else if(choice=="a"){
            cout<<"Please add a new description: ";
            string input_description;
            cin.ignore();
            getline(cin, input_description);

            Todoitem newitem;
            newitem.create(input_description);
            tdm.push_back(newitem);
        }

    }
    
    return 0;
}