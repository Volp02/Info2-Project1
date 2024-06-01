#pragma once

#include "readFile.h"       //for Passenger struct
#include "CARTalgo.h"       //for TreeNode struct
struct Passenger;
struct TreeNode;

Passenger *usrInputPassenger();

bool getPrediction(Passenger *passenger, TreeNode &root);
