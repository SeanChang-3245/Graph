﻿#include "Solution.h"
#include <iostream>
#include <windows.h>

int main()     
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cout << "stand,brute,cost,money,cp" << endl;


	for (int x = 0; x < 10000; x++) //　測資數
	{
		vector<int> ans(4); //4種作法
		srand(time(NULL) + x);
		int k = rand() % 7 + 4;  // k = 4 ~ 10 = 攤位數
		

		vector<int> nodes(k);
		for (int i = 0; i < k; i++) // random 滿足度
		{
			nodes[i] = rand() % 100 + 1;
			Sleep(5);
		} 

		graph G(nodes, rand() + 1);

		int rand_neg = 1;
		
		if (rand() & 1) 
			rand_neg = -1;

		int time = rand();
		int t = k * 4 + rand_neg * (time % k);
		ans[0] = G.brute(t);
		ans[1] = G.greedy_cost(t);
		ans[2] = G.greedy_money(t);
		ans[3] = G.greedy_cp(t);

		

		cout << k << ',' << ans[0] << ',' << ans[1] << ',' << ans[2] << ',' << ans[3] << "   " << endl;

		
		Sleep(5);


	}
	
	return 0;
}







//for (int x = 0; x < 500000; x++)
	//{
	//	srand(time(NULL) + x);

	//	int num[6];
	//	for (int i = 0; i < 5; i++)
	//	{
	//		num[i] = rand() % 10 + 1;
	//	}


	//	vector<int> vec(num, num + 5);
	//	graph G(vec);

	//	int a = G.brute(20);
	//	int b = G.greedy_cost(20);
	//	int c = G.greedy_cp(20);
	//	int d = G.greedy_money(20);

	//	/*if (a < b || a < c || a < d)
	//		cout << x << ": false" << endl;*/

	//	//cout << a << endl << b << endl << c << endl << d;



	//	
	//	
	//	cout << "a: " << a << endl;
	//	cout << "b: " << b << endl;
	//	cout << "c: " << c << endl;
	//	cout << "d: " << d << endl;

	//	for (int i = 0; i < 4; i++)
	//	{
	//		cout << G.root->path[i].target->money << ' ';
	//	}

	//	cout << endl << "root: ";

	//	for (edge i : G.root->path)
	//	{
	//		cout << i.cost << ' ';
	//	}

	//	cout << endl;

	//	for (edge i : G.root->path)
	//	{
	//		Node* current = i.target;

	//		for (edge j : current->path)
	//		{
	//			cout << j.cost << ' ';
	//		}
	//		cout << endl;
	//	}

	//	cout << endl << endl;
	//	
	//		
	//	

	//	
	//}



	/*G.brute(15);
	G.greedy_cost(15);
	G.greedy_cp(15);
	G.greedy_money(15);
	cout << endl << endl;*/


	