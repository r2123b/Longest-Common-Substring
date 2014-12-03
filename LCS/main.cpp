//
//  main.cpp
//  LCS
//
//  Created by Lu Kuan-Yin on 11/7/14.
//  Copyright (c) 2014 NTU. All rights reserved.
//
//  Class : Design Strategies for Computer Algorithms 2014 fall

#include "Functions.h"

int main(int argc, const char * argv[]) {
    string X("ABCD"); X.insert(0, " ");
    string Y("ADDC"); Y.insert(0, " ");
    const int m = (int)X.length();
    const int n = (int)Y.length();
    vector<vector<int>> cost(m, vector<int>(n));    // save the cost of each choice
    vector<vector<int>> label(m, vector<int>(n));   // save where the choice is from, LEFT = 1, UP = 2, LEFTUP = 3, BOTH = 4
    
    
    initial_2Dvector(cost, m, n);
    initial_2Dvector(label, m, n);
    LCS(X, Y, cost, label, m, n);
    
//    Print_2Dvector(cost, X, Y); //the use of uni-testing
//    cout<<endl;
//    Print_2Dvector(label, X, Y); //the use of uni-testing

    
    Print_LCS_Result(X, Y, cost, label, m, n);
    
    return 0;
}
