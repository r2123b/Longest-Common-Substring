//
//  main.cpp
//  LCS
//
//  Created by Lu Kuan-Yin on 11/7/14.
//  Copyright (c) 2014 NTU. All rights reserved.
//
//  Class : Design Strategies for Computer Algorithms 2014 fall

#include "Functions.h"

/*-------------the use of uni-testing-------------*/
void Print_2Dvector(vector<vector<int>> &v, const int m, const int n)
{
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++)
            cout<< v[i][j] << " ";
        cout<<endl;
    }
}

void Print_stack(const stack<pair<int, int>> & stk)
{
    stack<pair<int, int>> s = stk;
    while ( !s.empty() ) {
        pair<int, int>temp = s.top();
        cout<<"<"<<temp.first<<", "<<temp.second<<">"<<endl;
        s.pop();
    }
}
/*------------------------------------------------*/



int main(int argc, const char * argv[]) {
    string X("ABCD"); X.insert(0, " ");
    string Y("ADDC"); Y.insert(0, " ");
    const int m = (int)X.length();
    const int n = (int)Y.length();
    vector<vector<int>> cost(m, vector<int>(n));
    vector<vector<int>> label(m, vector<int>(n));
    
    
    initial_2Dvector(cost, m, n);
    initial_2Dvector(label, m, n);
    LCS(X, Y, cost, label, m, n);
    Print_2Dvector(label, m, n); //the use of uni-testing
    Print_LCS_Result(X, Y, cost, label, m, n);
    
    return 0;
}
