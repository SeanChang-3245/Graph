#include "Solution.h"
#include <iostream>
#include <windows.h>

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cout << "stand,brute,cost,money,cp" << endl;


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
	
	for (int x = 0; x < 500; x++) //　測資數
	{
		vector<int> ans(4); //4種作法
		srand(time(NULL) + x);
		int k = rand() % 9 + 4;  // k = 4 ~ 10 = 攤位數
		k = 11;

		vector<int> nodes(k);
		for (int i = 0; i < k; i++) // random 滿足度
		{
			nodes[i] = rand() % 100 + 1;
		} 

		graph G(nodes, rand() + 1);

		int rand_neg = 1;
		if (rand() & 1) rand_neg = -1;

		int time = rand();
		ans[0] = G.brute(k * 4 + rand_neg * (time % k));
		ans[1] = G.greedy_cost(k * 4 + rand_neg * (time % k));
		ans[2] = G.greedy_money(k * 4 + rand_neg * (time % k));
		ans[3] = G.greedy_cp(k * 4 + rand_neg * (time % k));


		/*cout << "stand: " << k << endl;
		cout << "brute: " << ans[0] << endl;
		cout << "cost: " << ans[1] << endl;
		cout << "money: " << ans[2] << endl;
		cout << "cp: " << ans[3] << endl;
		
		cout << endl << endl;*/

		cout << k << ',' << ans[0] << ',' << ans[1] << ',' << ans[2] << ',' << ans[3] << "   ";

		if (ans[0] < ans[1] || ans[0] < ans[2] || ans[0] < ans[3]) cout << "false";
		cout << endl;
		Sleep(5);


	}












}

