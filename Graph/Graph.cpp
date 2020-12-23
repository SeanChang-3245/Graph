#include "Solution.h"
#include <iostream>

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	srand(time(NULL));

	//----test start----
	int num[4];
	for (int i = 0; i < 4; i++)
	{
		num[i] = rand() % 100 + 1;
	}


	vector<int> vec(num, num+4);
	graph G(vec);

	/*for (int i = 0; i < 4; i++)
	{
		cout << G.root->path[i].target->money << endl;
	}*/

	G.brute(15);
	G.greedy_cost(15);
	G.greedy_cp(15);
	G.greedy_money(15);



	//----test end----



}

