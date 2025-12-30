#include "parser.h"
#include <fstream>
#include <iostream>

AnalysisResult analyzeFile(const string &filePath){

    AnalysisResult result;
    result.forCount=0;
    result.nestedLoop=false;
    result.recursion=false;
    result.timeComplexity = "O(1)";

    ifstream file(filePath);  //opens the test.txt file 
    //file = variable name
   
    string line;

   if(!file.is_open()){
    cout<<"Error in opening the file"<<endl;
    return result;
   }

   
    int openBraces=0;        //For brace tracking
    bool inComment=false;  //For checking if inside a comment or not
    string recFunc_name = "";

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
            result.recursion=true;            
        }     
    }

               /*  ----> Nested for loop detect and No. of for loops <---- */  

    if(line.find("for")!= string::npos){    //detects key word "for" in every line.
       result.forCount++;

       //If a loop starts while another is already open -> nested loop = true
       if(openBraces>0){
        result.nestedLoop=true;
       }
    }
    
    if(line.find("{")!=string :: npos){
        openBraces++;
    }

    if(line.find("}")!=string::npos && openBraces > 0){
        openBraces--;
    }
 }

file.close();

    if(result.nestedLoop) {
        result.timeComplexity = "O(n^2)";
    }
    else if (result.forCount == 1) {
        result.timeComplexity = "O(n)";
    }

    return result;

}



