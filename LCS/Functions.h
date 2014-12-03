//
//  Functions.h
//  LCS
//
//  Created by Lu Kuan-Yin on 12/3/14.
//  Copyright (c) 2014 NTU. All rights reserved.
//

#ifndef __LCS__Functions__
#define __LCS__Functions__

#include <stdio.h>
#include "Functions.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <list>
using namespace std;

enum direct {
    LEFT = 1,
    UP = 2,
    LEFTUP = 3,
    BOTH = 4
};

bool initial_2Dvector(vector<vector<int>> &matrix,
                      const int m,
                      const int n);

void LCS(const string X,
         const string Y,
         vector<vector<int>> &cost,
         vector<vector<int>> &Label,
         const int m,
         const int n);

bool Print_LCS_Result(const string X,
                      const string Y,
                      const vector<vector<int>> &cost,
                      const vector<vector<int>> &label,
                      const int m,
                      const int n);

#endif /* defined(__LCS__Functions__) */