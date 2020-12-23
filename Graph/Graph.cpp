#include "Solution.h"
#include <iostream>

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	for (int x = 0; x < 1000; x++)
	{
		srand(time(NULL) + x);

		int num[4];
		for (int i = 0; i < 4; i++)
		{
			num[i] = rand() % 10 + 1;
		}


		vector<int> vec(num, num + 4);
		graph G(vec);

		int a = G.brute(15);
		int b = G.greedy_cost(15);
		int c = G.greedy_cp(15);
		int d = G.greedy_money(15);

		if (a >= b)
			cout << x+1 << ": " << "true" << endl;
		else
			cout << x + 1 << ": " << "false" << endl;


		
	}



	/*G.brute(15);
	G.greedy_cost(15);
	G.greedy_cp(15);
	G.greedy_money(15);
	cout << endl << endl;*/
	





}

