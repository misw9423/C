#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class node{
    private:
        string name;
        node* next;

    public:
        node(){
            name = "";
            next = NULL;
        }

        ~node(){
            name="";
            next=NULL;
        }

        string getName(){
            return name;
        }

        void setName(string s){
            name = s;
        }

        node* getNext(){
            return next;
        }

        void setNext(node* n){
            next = n;
        }
};

int h(string x, int M){
    int xlength = x.size()+1;
    char *ch = new char[xlength];
    ch[x.size()]=0;

    memcpy(ch, x.c_str(), x.size());
    int sum = 0;
    for(int i =0; i<x.length(); i++){
        sum+=ch[i];
    }
    return sum%M;
}

string getOption(){
    string opt;
    cout<<"Select an option:\n i(insert name if that name does not already exist)\n d(delete name)\n f(find name in the table)\n p(print table contents)\n e(exit program)"<<endl;
    cin>>opt;
    while(opt!="i"&&opt!="d"&&opt!="f"&&opt!="p"&&opt!="e"){
        cout<<"Invalid input!\n Please enter a valid option: "<<endl;
        cin>>opt;
    }
    return opt;
}
void insertName(node* hT[], string n){
    int index=h(n,50);
    node* temp = new node();
    node* addNode = new node();
    temp = hT[index];
    addNode -> setName(n);
    if(hT[index]->getName()==""){
        hT[index]->setName(n);
    }
    else{
        while(temp->getNext()!=NULL){
            temp=temp->getNext();
        }
        temp->setNext(addNode);
    }

}
int main(){
    int hashTableSize=50;
    string name;
    node* hashTable[hashTableSize];
    for(int i =0; i<hashTableSize;i++){
        hashTable[i]=new node();
    }
    string option;
    option = getOption();
    while(option!="e"){
        if(option=="i"){
            cout<<"Enter a name to insert: "<<endl;
            cin>>name;
            insertName(hashTable, name);
        }
        else if(option=="d"){
            cout<<"Enter a name to delete: "<<endl;
            cin>>name;
            deleteName(hashTable, name);
        }
        else if(option=="f"){
            cout<<"Enter a name to find: "<<endl;
            cin>>name;
            findName(hashTable, name);
        }
        else{ //Implicit that this will be print name
            printName(hashTable);
        }
        option=getOption();
    }
    return 0;
}