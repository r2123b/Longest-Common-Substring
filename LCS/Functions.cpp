//
//  Functions.cpp
//  LCS
//
//  Created by Lu Kuan-Yin on 12/3/14.
//  Copyright (c) 2014 NTU. All rights reserved.
//

#include "Functions.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <list>
using namespace std;

bool initial_2Dvector(vector<vector<int>> &matrix, const int m, const int n)
{
    if (matrix.empty())
        return false;
    
    for(int i=0; i<m; i++)
        matrix[i][0] = 0;
    for(int j=0; j<n; j++)
        matrix[0][j] = 0;
    return true;
}

void LCS(const string X, const string Y, vector<vector<int>> &cost, vector<vector<int>> &Label, const int m, const int n)
{
    for(int i=1; i<m; i++)
        for(int j=1; j<n; j++)
        {
            if (X[i] == Y[j]) {
                cost[i][j] = cost[i-1][j-1]+1;
                Label[i][j] = LEFTUP;
            }
            else {
                if(cost[i-1][j] > cost[i][j-1]) {
                    cost[i][j] = cost[i-1][j];
                    Label[i][j] = UP;
                }
                else if(cost[i-1][j] == cost[i][j-1]) {
                    cost[i][j] = cost[i-1][j];
                    Label[i][j] = BOTH;
                }
                else if(cost[i-1][j] < cost[i][j-1]){
                    cost[i][j] = cost[i][j-1];
                    Label[i][j] = LEFT;
                }
            }
        }
}



void Print_STKresult(const stack<pair<int,int>> &STK_result, const string X, const string Y)
{
    //    cout<<"size:"<<STK_result.size()<<endl;  //for testing
    stack<pair<int,int>>STK_temp(STK_result);
    pair<int, int> point;
    string resultX, resultY;
    string result_string;
    
    
    while (!STK_temp.empty()) {
        point = STK_temp.top();
        
        //-----------"int" convert to "string" using stringstream-----------------
        stringstream ss;
        ss << point.first;
        string intTOstringX = ss.str();
        ss.str(""); ss.clear(); //these two codes clear the stringstream
        ss << point.second;
        string intTOstringY = ss.str();
        //------------------------------------------------------------------------
        
        resultX.append(intTOstringX); resultX.push_back(' ');
        resultY.append(intTOstringY); resultY.push_back(' ');
        
        result_string.push_back( X[point.first] );
        
        
        STK_temp.pop();
    }
    
    cout<<result_string<<"; "
    <<"in X:"<<resultX<<"; "
    <<"in Y:"<<resultY
    <<endl;
}

void Find_Path(const vector<vector<int>> &label,
               pair<int, int> &nowPoint,
               const pair<int, int> &endPoint,
               stack<pair<int, int>> &STK_path,
               stack<pair<int, int>> &STK_result,
               stack<pair<int, int>> &STK_both)
{
    while (label[nowPoint.first][nowPoint.second]!=0) {
        STK_path.push(nowPoint);
        switch (label[nowPoint.first][nowPoint.second]) {
            case UP:
                nowPoint.first -= 1;
                break;
                
            case LEFT:
                nowPoint.second -= 1;
                break;
                
            case LEFTUP:
                STK_result.push(nowPoint);
                nowPoint.first -= 1;
                nowPoint.second -= 1;
                break;
                
            case BOTH:
                STK_both.push(nowPoint);
                //choose UP first
                nowPoint.first -= 1;
                break;
                
            default:
                break;
        }
    }
}

bool Print_LCS_Result(const string X, const string Y, const vector<vector<int>> &cost, const vector<vector<int>> &label, const int m, const int n)
{
    if(label.empty())
        return false;
    if (cost[m-1][n-1] == 0) {
        cout<<"No common substring!!\n";
        return true;
    }
    
    cout<< "String X:"<< X <<endl;
    cout <<"String Y:"<< Y <<endl;
    cout <<"Max Length = "<< cost[m-1][n-1] << endl;
    
    //用stack印出路徑
    stack<pair<int,int>> STK_both;
    stack<pair<int,int>> STK_result;
    stack<pair<int,int>> STK_path;
    vector<stack<pair<int,int>>> VEC_ResultList; //using to check duplicate result
    
    const pair<int, int>beginPoint(m-1, n-1);
    const pair<int, int>endPoint(1, 1);
    pair<int, int>nowPoint(beginPoint);
    
    Find_Path(label, nowPoint, endPoint, STK_path, STK_result, STK_both);
    Print_STKresult(STK_result, X, Y); //print the first path
    VEC_ResultList.push_back(STK_result);
    
    while ( !STK_both.empty() ) {
        nowPoint = STK_both.top(); //reuse "nowpoint"
        STK_both.pop();
        //path pop 到 aim
        while (STK_path.top() != nowPoint) {
            if ( !STK_result.empty() ) {
                if (STK_path.top() == STK_result.top())  //若result有跟path一樣的點要一併刪除
                    STK_result.pop();
            }
            STK_path.pop();
        }
        //先從both的點往左移動，因為
        nowPoint.second -= 1;
        //再找新的path
        Find_Path(label, nowPoint, endPoint, STK_path, STK_result, STK_both);
        
        //check whether there is duplicate
        bool check_dup = false;
        for(vector<stack<pair<int, int>>>::iterator it=VEC_ResultList.begin() ; it!=VEC_ResultList.end() ; it++) {
            if (*it == STK_result)
                check_dup = true;
        }
        
        if(!check_dup){
            Print_STKresult(STK_result, X, Y);
            VEC_ResultList.push_back(STK_result);
        }
    }
    return true;
}