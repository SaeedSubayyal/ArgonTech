#include <iostream>
using namespace std;

int search1arr(int* arr, int input){

int size = sizeof(arr);

    for (int i=0;i<size;i++){
    if (arr[i]== input)
    return i;
    }
}

void delete1arr(int* arr, int input){


int size = sizeof(arr);

    for (int i=0;i<size;i++){
    if (arr[i]== input)
    arr[i] = '\0';
    break;
    }





}

void input1arr(int* arr,int input){


int size = sizeof(arr);
size+=2;

    for (int i=0;i<size;i++){
     
    if (arr[i]== -1){
        arr[i] = input;
    }
    if (arr[i]>input){
       
       swap(arr[i],input);
        
    }
       if (i <= size-1){
         if (arr[i+1] == -1)
            break;
        }
    }

}

void outputarr(int* arr){

    for (int i=0;i<10;i++)
    cout<<arr[i];

}

int main(){

int* arr;
arr = new int [10];
int choice = 0;

arr[0] = 0;
int number;

for (int i=0;i<10;i++)
    arr[i]= -1;

while(1){
    cout<<"\nPlease select from following menu: 1- Input, 2-Delete, 3-Search: ";
cin >>choice;

    if (choice == 1 ){
cout<<"Please Input integer number: ";
cin>>number;
input1arr(arr,number);
}

if (choice == 2){
    cout<<"Please Input number you want to delete: ";
    cin>>number;
delete1arr(arr,number);
}

if (choice ==3){
cout<<"Please Input number you want to search: ";
cin>>number;
cout<<"Index of array: "<<search1arr(arr,number);

}
cin.ignore();
cout<<"Do you want to continue? If NO, input -1 else 0: ";
cin>>choice;
if (choice == -1){
 break;
}
}
    return 0;
}