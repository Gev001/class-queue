#include"Queue.h"

int main()
{
	Queue<int>x;
	int x2[] = { 1,2,3,45 };
	Queue<int>y(x2);
	Queue<int>z(x);
	cout << endl;
	x.push_back(1);
	x.push_back(2);
	x.push_back(3);
	x.pop_front();
	cout << "\n";
	Queue<int>p(move(x));
	cout << p.front() << endl;
	Queue<int>N;
	N = move(p);
	cout << N.top() << "\n";
	N.clear();
	cout << N.top() << "\n";
	z.push_back(1);
	z.push_back(12);
	z.push_back(4);
	z.push_back(123);
	z.push_back(0);
	cout << "z-i size= " << z.size() << endl;
	system("pause");
}