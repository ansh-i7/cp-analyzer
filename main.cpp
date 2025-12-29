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
   int openBraces=0;        //For brace tracking
   bool nestedLoop = false;

   string timeComplexity = "O(1)";

   while(getline(file,line)){
    cout<<line<<endl;

    if(line.find("for")!= string::npos){    //detects key word "for" in every line.
       forCount++;

       //If a loop starts while another is already open -> nested loop = true
       if(openBraces>0){
        nestedLoop=true;
       }
    }
    
    if(line.find("{")!=string :: npos){
        openBraces++;
    }

    if(line.find("}")!=string :: npos){
        openBraces--;
    }
 }

   cout<<"Total for loops detected : "<<forCount<<endl;

   if(nestedLoop){
    cout<<"Nested Loop detected"<<endl;
   }
   else cout<<"No Nested Loop detected"<<endl;

   if(nestedLoop){
    timeComplexity= "O(n^2)";
   }
   else if(forCount==1){
    timeComplexity= "O(n)";
   }

   cout<<"Estimated Time Complexity : "<<timeComplexity<<endl;

   file.close();
   return 0;
}  
