#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<int> vec{ 1000,999,88,777, 11,9,2,1,4,3,7,6,8,15,10 };
	nth_element(vec.begin(), vec.begin(), vec.end());    //ֻ��֤��nλ�Ŷ�Ԫ�أ�
	for (auto v : vec)
		cout << v << " ";
	return 0;
}