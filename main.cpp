#include <iostream>
#include <fstream>
using namespace std;

int main() {
   ifstream file("input/test.txt");  //opens the test.txt file 
    //file = variable name
   
    string line;

   if(!file.is_open()){
    cout<<"Error in opening the file"<<endl;
    return 0;
   }
   
   while(getline(file,line)){
    cout<<line<<endl;
   }

   file.close();
   return 0;
}  
