#include <iostream>
#include <fstream>
using namespace std;

int main() {
   ifstream file("input/solution.cpp");  //opens the test.txt file 
    //file = variable name
   
    string line;

   if(!file.is_open()){
    cout<<"Error in opening the file"<<endl;
    return 0;
   }
   
   int forCount=0;
   while(getline(file,line)){
    cout<<line<<endl;

    if(line.find("for")!= string::npos){    //detects key word "for" in every line.
       forCount++;
    }
   }

   cout<<"Total for loops detected : "<<forCount<<endl;

   file.close();
   return 0;
}  
