#pragma once

#include <bits/stdc++.h>
using namespace std;

struct edge;
struct Node;

struct Node
{
    int money;
    vector<edge> path;
};

struct edge
{
    int cost;
    Node* target;
};


class graph
{
    Node* root;
    vector<int> ans;

    void brute(int remain_time)
    {
        int tmp = -1;
        brute(remain_time, 0, this->root);

        for (int i : this->ans)
            if (i > tmp) tmp = i;

        this->ans.clear();
    }
    void brute(int remain_time, int current_money, Node* current_node)
    {
        if (remain_time <= 0)
        {
            if (remain_time < 0)
                current_money -= current_node->money;

            this->ans.push_back(current_money);
            return;
        }

        for (edge i : current_node->path)
        {
            brute(remain_time - i.cost, current_money + i.target->money, i.target);
        }
    }


    void greedy_cost(int remain_time)
    {
        Node* current_node = this->root;
        int current_money = 0;

        while (remain_time >= 0)
        {
            for (edge i : current_node->path)
            {


            }

        }

    }




};
