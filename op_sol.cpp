#include<bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int N, M, X, Y, s;
		cin >> N >> M >> X >> Y >> s;
		// view the image in this repository for better understanding
		// create 'prev' and 'sum' variables for the horizontal row calculations
		int prev_x = 0;
		int sum_x = 0;
		for (int i = 0; i < X; i++) {
			int x;
			cin >> x;
			// if you viewed, the image in this repository, this is the Summation of (a[i] / s)
			// we need to subtract it to the 'x' value to the 'prev' variable to get the partition of spaces
			// we need to subtract 1 from it so it doesn't count the row with the water current
			sum_x += (x - prev_x - 1) / s;
			// store the current 'x' value for it to be used on the next iteration
			prev_x = x;
		}
		// if the loop didn't reach the end of the rows, then there is no water current in the last row,
		// so that's why we need to create an equation to get the space from the last row with the row
		// with the water current that is nearest to it
		sum_x += (N - prev_x) / s;
		// we do the same process on the y-axis
		int prev_y = 0;
		int sum_y = 0;
		for (int i = 0; i < Y; i++) {
			int y;
			cin >> y;
			sum_y += (y - prev_y - 1) / s;
			prev_y = y;
		}
		sum_y += (M - prev_y) / s;
		// multiply the total number of houses per row on the total number of houses per column
		// to the the total number of the houses that can be built on a n x m grid with water partitions
		cout << sum_x * sum_y << '\n';
	}
	return 0;
}
