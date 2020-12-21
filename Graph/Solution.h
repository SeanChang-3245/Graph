#pragma once

#include <bits/stdc++.h>
using namespace std;

struct edge;
struct Node;

struct Node
{
    bool used = false;
    int money;
    vector<edge> path;

    Node(int m)
    {
        this->money = m;
    }
};

struct edge
{
    int cost;
    Node* target;
};


class graph
{
public:

    Node* root;
    vector<int> ans;

    graph(vector<int> nodes_money)
    {
        srand(time(NULL));
        int rcost = rand() % 100 + 1;
        Node* p;
        edge tmp;

        for (int i : nodes_money)
        {
            p = new Node(i);
            tmp.target = p;
            tmp.cost = rcost;

            this->root->path.push_back(tmp);

            rcost = rand() % 100 + 1;
        }

        for (int i = 0; i < this->root->path.size()-1; i++)
        {
            for (int j = i + 1; j < this->root->path.size(); j++)
            {
                tmp.target = this->root->path[j].target;
                tmp.cost = rcost;
                this->root->path[i].target->path.push_back(tmp);

                tmp.target = this->root->path[i].target;
                this->root->path[j].target->path.push_back(tmp);

            }
        }
    }


    void brute(int remain_time);
    void brute(int remain_time, int current_money, Node* current_node);


    void greedy_cost(int remain_time);


    void greedy_money(int remain_time);


    void greedy_cp(int remain_time);
};

/*
graph::graph(vector<int>& nodes)
{
    srand(time(NULL));
    int rcost = rand() % 100 + 1;
    edge tmp;
    Node* p;
    Node* CurrnentNode = this->root;

    for(int i : nodes)
    {
        p = new Node(i);
        tmp.target = p;
        tmp.cost = rcost;

        this->root->path.push_back(tmp);
    }

    for(edge i : this->root->path)
    {

    }

}*/


void graph::brute(int remain_time)
{
    int tmp = -1;
    brute(remain_time, 0, this->root);

    for (int i : this->ans)
        if (i > tmp) tmp = i;

    this->ans.clear();
}

void graph::brute(int remain_time, int current_money, Node* current_node)
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
        if (i.target->used == false)
            brute(remain_time - i.cost, current_money + i.target->money, i.target);
    }
}



void graph::greedy_cost(int remain_time)
{
    Node* current_node = this->root;
    int current_money = 0;
    edge tmp;

    tmp.cost = INT_MAX;


    while (remain_time >= 0)
    {
        for (edge i : current_node->path)
        {
            if (i.cost < tmp.cost && i.target->used == false)
                tmp = i;
        }

        if (remain_time - tmp.cost >= 0)
        {
            remain_time -= tmp.cost;
            current_money += tmp.target->money;
        }
        else
        {
            break;
        }
    }
    cout << current_money;
}



void graph::greedy_money(int remain_time)
{
    Node* current_node = this->root;
    int current_money = 0;
    edge tmp;

    tmp.target->money = INT_MIN;


    while (remain_time >= 0)
    {
        for (edge i : current_node->path)
        {
            if (i.target->money > tmp.target->money && i.target->used == false)
                tmp = i;
        }

        if (remain_time - tmp.cost >= 0)
        {
            remain_time -= tmp.cost;
            current_money += tmp.target->money;
        }
        else
        {
            break;
        }
    }
    cout << current_money;
}



void graph::greedy_cp(int remain_time)
{
    Node* current_node = this->root;
    int current_money = 0;
    edge tmp;

    tmp.target->money = 0;
    tmp.cost = 1;


    while (remain_time >= 0)
    {
        for (edge i : current_node->path)
        {
            if ((double)i.target->money / i.cost > (double)tmp.target->money / tmp.cost && i.target->used == false)
                tmp = i;
        }

        if (remain_time - tmp.cost >= 0)
        {
            remain_time -= tmp.cost;
            current_money += tmp.target->money;
        }
        else
        {
            break;
        }
    }
    cout << current_money;
}
