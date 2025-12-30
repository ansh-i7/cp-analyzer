#pragma once

#include <string>
using namespace std;

// This class represents the result of analyzing a file.
class AnalysisResult {

    public:                        
        int forCount;
        bool nestedLoop;
        bool recursion;
        string timeComplexity;

};

//This function analyzes a source file (const string &filePath) and returns the result

AnalysisResult analyzeFile(const string &filePath);


