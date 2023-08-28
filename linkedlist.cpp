#include <iostream>
using namespace std;

int counter = 0;

template <typename T>
class Node {
public:
    int age;
    T name;
    Node* next;

    //constructor
    Node(){
        next = NULL;
    }
};


template <typename T>
class Lists {
    Node<T>* head;
public:


    Lists(int age = 5, T const Name = "comp"){
        head = NULL;
    }

    void Insert_start(int const Age, T const Name){
        Node<T>* NewNode = new Node<T>;
        NewNode->age = Age;
        NewNode->name = Name;
        NewNode->next = head;
        head = NewNode;
    }

    void Insert_end(int const Age, T const Name)
    {
        Node<T>* NewNode = new Node<T>;
        NewNode->age = Age;
        NewNode->name = Name;
        Node<T>* temp = head;
        if (head == NULL)
        {
            NewNode->next = head;
            head = NewNode;
        }
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = NewNode;
    }

    void Insert_index(int Age, T Name, int index)
    {
        Node<T>* NewNode = new Node<T>;
        NewNode->age = Age;
        NewNode->name = Name;
        Node<T>* temp1 = head;
        int itr = 0;
        while (itr < index - 1)
        {
            temp1 = temp1->next;
            itr++;
        }
        Node<T>* temp2 = temp1->next;
        temp1->next = NewNode;
        NewNode->next = temp2;
    }


    void Print() const
    {
        Node<T>* temp = head;
        while (temp)
        {
            cout << "Age: ";
            cout << temp->age << "\nName: " << temp->name << endl;
            temp = temp->next;
        }
    }


    bool Search(T const element){
        bool flag = false;
        Node<T>* temp = head;
        while (temp){
            if (temp->name == element){
                return true;
            }
            else
            {
                temp = temp->next;
            }
        }
        return flag;
    }


    void deleteAll(T const Name){
        Node<T>* temp = head;
        while (temp->next){
            if (temp->next->name == Name){
                Node<T>* Del = temp->next;
                temp->next = temp->next->next;
                delete Del;
            }
            else {
                temp = temp->next;
            }
        }
    }


    void Delete_Start(){
        Node<T>* Del = head;
        head = head->next;

        delete Del;
    }


    bool Insert_After(T const v1, T const v2){
        Node<T>* NewNode = new Node<T>;
        NewNode->name = v2;
        NewNode->age = 5;
        Node<T>* temp = head;
        while (temp){
            if (temp->name == v1){
                NewNode->next = temp->next;
                temp->next = NewNode;
                return true;
            }
            temp = temp->next;
        }
        return false;
    }


    bool Insert_Before(T const v1, T const v2){
        Node<T>* NewNode = new Node<T>;
        NewNode->name = v1;
        NewNode->age = 5;
        Node<T>* temp = head;
        while (temp){
            if (temp->next->name == v2){
                NewNode->next = temp->next;
                temp->next = NewNode;
                return true;
            }
            temp = temp->next;
        }
        return false;
    }


    int Size_Getter(){
        Node<T>* temp = head;
        int count = 0;
        while (temp){
            temp = temp->next;
            count++;
        }
        return count;
    }
   
    ~Lists(){

        cout << "\n\n Calling Destructor\n\n";
        while (head){
            Delete_Start();
        }
    }

};
int main(){
    Lists<string> list;
    list.Insert_start(20, "Subayyal");
    list.Insert_start(19, "Argon");

    list.Insert_index(31, "Ali", 1);
    list.Print();

    cout << "\n\nChecking search : (Searching Subayyal)" << endl;
    cout<<list.Search("Subayyal");
    

    
    cout << "\n\nChecking Insert After :    (Inserting after Subayyal)" << endl;
    bool check = list.Insert_After("Subayyal", "Hajra");

    list.Print();

    
    cout << "\n\nChecking Delete at start :" << endl;
    list.Delete_Start();
    list.Print();

    
    cout << "\n\nChecking Delete all :    (Deleting all Subayyal)" << endl;
    list.deleteAll("Subayyal");
    list.Print();

    return 0;
}