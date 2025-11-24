#if 1
#pragma warning (disable : 4996)
//#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

vector<ll> v;
int N, C;
void dfs(int start, int end, vector<ll>& part, ll sum) {
	if (start > end) {
		part.push_back(sum);
		return;
	}
	else {
		dfs(start + 1, end, part, sum);
		dfs(start + 1, end, part, sum + v[start]);
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	cin >> N >> C;
	v.resize(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	vector<ll> part1;
	vector<ll> part2;
	dfs(0, N / 2, part1, 0);
	dfs(N / 2 + 1, N - 1, part2, 0);
	sort(part2.begin(), part2.end());
	int cnt = 0;
	for (int i = 0; i < part1.size(); i++) {
		//part1[i]에 대해서 part2와 합했을 때 C 이하인 경우를 모두 summation
		//part2를 sort했으므로 index만으로 경우의 수를 알 수 있음
		//part2 sort헀으므로 upper_bound, lower_bound 사용 가능
		//upper_bound는 x 초과하는 값이 처음 나오는 index return
		//lower_bound는 x 이상의 값이 처음 나오는 index return
		ll x = C - part1[i];
		cnt += upper_bound(part2.begin(), part2.end(), x) - part2.begin();
	}

	cout << cnt;
	return 0;
}
#endif