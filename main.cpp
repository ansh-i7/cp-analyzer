#include <iostream>
#include <fstream>
#include <string>

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

   bool inComment=false;  //For checking if inside a comment or not

   bool rec_detect=false;
   string recFunc_name = "";

   string timeComplexity = "O(1)";

   while(getline(file,line)){
            
                /* -----> Ignoring Comments <----- */

    //Handles Multi-line comments
    if(inComment){
        if(line.find("*/")!=string::npos){
            inComment=false;
        } 
        continue;
    }

    if(line.find("/*")!=string ::npos){
            inComment=true;
            continue;
    }

    //Handles Single-line comments
    size_t commentPos=line.find("//");
    if(commentPos!=string::npos){
        line=line.substr(0,commentPos);
    }

    if(line.empty()) continue;      //skips analyzing empty line

    cout<<line<<endl;

                /* ----> Recursion detection : stores the Function name <---- */

    if(recFunc_name.empty()){
        size_t pos_OpenBrac = line.find("(");

        if(pos_OpenBrac!=string::npos && line.find("for")==string::npos
            && line.find("if")==string::npos && line.find("while")==string::npos){
                string beforePar=line.substr(0,pos_OpenBrac);

                string Temp_recFunc="";
                string temp="";

                for (char c : beforePar) {
                    if (c==' '){
                        if(!temp.empty()) {
                            Temp_recFunc = temp;
                            temp.clear();
                            }
                        } 
                        else {
                            temp+=c;
                        }
                    }
                if(!temp.empty()) Temp_recFunc=temp;

            recFunc_name = Temp_recFunc;
        }
    }

                        /* ----> Recursion Detection <---- */

    if( !recFunc_name.empty() && line.find(recFunc_name+"(")!=string::npos){
        if(line.find("{")==string::npos){     //with this i'll avoid counting the definition line as "{" comes after defining a function. 
            rec_detect=true;            
        }     
    }

               /*  ----> Nested for loop detect and No. of for loops <---- */  

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

    if(line.find("}")!=string::npos && openBraces > 0){
        openBraces--;
    }
 }

    if(rec_detect){
        cout<<"Recursion detected"<<endl;
    }
    else {
        cout<<"No Recursion detected"<<endl;
    }

   cout<<"Total for loops detected : "<<forCount<<endl;

   if(nestedLoop){
    cout<<"Nested Loop detected"<<endl;
   }
   else cout<<"No Nested Loop detected"<<endl;

        //Estimated Time complexity 
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
