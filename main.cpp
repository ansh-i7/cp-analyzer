#include <iostream>
#include "analyzer/parser.h"

using namespace std;

int main() {
   
    AnalysisResult res = analyzeFile("input/solution.cpp");

    cout<< "Total number of for loops : "<< res.forCount << endl;

    cout<<(res.nestedLoop ? "Nested Loop detected" : "No Nested Loop detected")<<endl;

    cout<<(res.recursion ? "Recursion detected" : " No recursion detected")<<endl;

    cout<<"Estimated Time Complexity : "<< res.timeComplexity << endl;

    return 0;
}  
