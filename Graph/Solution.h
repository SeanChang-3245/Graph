#pragma once

#include <bits/stdc++.h>
#define endl "\n"


using namespace std;


struct edge;
struct Node;
class graph;

struct Node
{
    bool used = false;
    int money=0;
    vector<edge> path;

    Node(int m)
    {
        this->money = m; 
    }
};

struct edge
{
public:
    int cost;
    Node* target;
};


class graph
{
public:
    Node* root = new Node(0);
    vector<int> ans;

    graph(vector<int> &nodes_money, int randseed)
    {
        srand(time(NULL) + randseed);
        int rcost = rand() % 10 + 1;
        Node* p = nullptr;
        this->ans.clear();



        for (int i : nodes_money)
        {
            p = new Node(i);
            edge tmp;
            tmp.target = p;
            tmp.cost = rcost;

            (this->root)->path.push_back(tmp);
            //this->testvec.push_back(tmp);

            rcost = rand() % 10 + 1;
        }

        for (int i = 0; i < this->root->path.size()-1; i++)
        {
            for (int j = i + 1; j < this->root->path.size(); j++)
            {
                edge tmp;
                tmp.target = this->root->path[j].target;
                tmp.cost = rcost;
                this->root->path[i].target->path.push_back(tmp);

                tmp.target = this->root->path[i].target;
                this->root->path[j].target->path.push_back(tmp);

                rcost = rand() % 10 + 1;
            }
        }
    }


    int brute(int remain_time);
    void brute(int remain_time, int current_money, Node* current_node, int lvl);


    int greedy_cost(int remain_time);


    int greedy_money(int remain_time);


    int greedy_cp(int remain_time);


    void reset();
};



int graph::brute(int remain_time)
{
    int tmp = INT_MIN;

    brute(remain_time, 0, this->root, 0);

    for (int i : this->ans)
        if (i > tmp) tmp = i;

    reset();
    return tmp;

}

void graph::brute(int remain_time, int current_money, Node* current_node, int lvl)
{
    if (remain_time <= 0 || lvl >= this->root->path.size())
    {
        if (remain_time < 0)
            current_money -= current_node->money;

        this->ans.push_back(current_money);
        return;
    }

    for (edge i : current_node->path)
    {
        if (i.target->used == false)
        {
            i.target->used = true;
            brute(remain_time - i.cost, current_money + i.target->money, i.target, lvl+1);
            i.target->used = false;
        }
    }
}



int graph::greedy_cost(int remain_time)
{
    int used_cnt = 0;
    Node* current_node = this->root;
    int current_money = 0;
    edge tmp;

    //tmp = this->root->path[0];

    while (remain_time >= 0)
    {
        if (used_cnt >= this->root->path.size())
        {
            break;
        }

        for (edge i : current_node->path)
        {
            if (i.target->used == false)
            {
                tmp = i;
                break;
            }
        }
        //tmp = current_node->path[0];
       

        for (edge i : current_node->path)
        {
            if (i.cost < tmp.cost && i.target->used == false && remain_time - i.cost >= 0)
                tmp = i;
        }

        if (remain_time - tmp.cost >= 0)
        {
            tmp.target->used = true;
            remain_time -= tmp.cost;
            current_money += tmp.target->money;
            current_node = tmp.target;
            used_cnt++;
        }
        else
        {
            break;
        }

        
    }
   // cout << current_money << endl;
    reset();
    return current_money;
}



int graph::greedy_money(int remain_time)
{
    int used_cnt = 0;
    Node* current_node = this->root;
    int current_money = 0;
    edge tmp;

    //tmp = this->root->path[0];

    while (remain_time >= 0)
    {
        if (used_cnt >= this->root->path.size())
        {
            break;
        }

        for (edge i : current_node->path)
        {
            if (i.target->used == false)
            {
                tmp = i;
                break;
            }
        }


        for (edge i : current_node->path)
        {
            if (i.target->money > tmp.target->money && i.target->used == false && remain_time - i.cost >= 0)
                tmp = i;
        }

        if (remain_time - tmp.cost >= 0)
        {
            tmp.target->used = true;
            remain_time -= tmp.cost;
            current_money += tmp.target->money;
            current_node = tmp.target;
            used_cnt++;
        }
        else
        {
            break;
        }
    }

    reset();
    return current_money;
}



int graph::greedy_cp(int remain_time)
{
    int used_cnt = 0;
    Node* current_node = this->root;
    int current_money = 0;
    edge tmp;

    //tmp = this->root->path[0];


    while (remain_time >= 0)
    {
        if(used_cnt >= this->root->path.size())
        {
            break;
        }

        for (edge i : current_node->path)
        {
            if (i.target->used == false)
            {
                tmp = i;
                break;
            }
        }
        //tmp = current_node->path[0];


        for (edge i : current_node->path)
        {
            if ((double)i.target->money / i.cost > (double)tmp.target->money / tmp.cost && i.target->used == false && remain_time - i.cost >= 0)
                tmp = i;
        }

        if (remain_time - tmp.cost >= 0)
        {
            tmp.target->used = true;
            remain_time -= tmp.cost;
            current_money += tmp.target->money;
            current_node = tmp.target;
            used_cnt++;
        }
        else
        {
            break;
        }
    }
    //cout << current_money << endl;
    reset();
    return current_money;
}


void graph::reset()
{
    this->root->used = false;
    for (edge i : this->root->path)
    {
        i.target->used = false;
    }

    this->ans.clear();
}


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

