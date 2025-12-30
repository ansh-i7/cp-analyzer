#pragma once

#include <string>
using namespace std;

// This class represents the result of analyzing a file.
class AnalysisResult {

    public:                         //public -> very important for other files to access the data members
        int forCount;
        bool nestedLoop;
        bool recursion;
        string timeComplexity;

};

//This function analyzes a source file (const string &filePath) and returns the result
//Here I used const because i should not modify the file path passed to it.

AnalysisResult analyzeFile(const string &filePath);


