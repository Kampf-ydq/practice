#include <iostream>

using namespace std;

#define MAX 1000
int arr[MAX];

int main()
{
	int i, j, temp;
	int n;
	while (cin >> n)
	{
		for (int j = 0; j < n; j++)
			cin >> arr[j];

		for (i = 1; i < n; i++) {
			for (j = 0; j < n - i; j++) {
				if (arr[j] > arr[j + 1]) {
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}

		for (i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
