#include "Solution.h"
#include <iostream>

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//----test start----
	int num[4] = { 5,3,12,10 };
	vector<int> vec(num, num+4);

	cout << "test" << endl;
	//for (int i : vec) cout << i << ' ';
	graph G(vec);

	for (int i = 0; i < 4; i++)
	{
		cout << G.root->path[i].target->money << endl;
	}



	//----test end----



}

