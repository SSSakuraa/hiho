#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//小Hi、小Ho还有被小Hi强拉来的小Z，准备组队参加一个智力竞赛。竞赛采用过关制，共计N个关卡。
//在第i个关卡中，小Hi他们需要获得Ai点分数才能够进入下一关。
//每一关的分数都是独立计算的，即使在一关当中获得超过需要的分数，也不会对后面的关卡产生影响。
//小Hi他们可以通过答题获得分数。答对一道题获得S点分数，答错一道题获得T点分数。
//在所有的N个关卡中，小Hi他们一共有M次答题机会。在每个关卡中，都可以在累计答题次数不超过M的情况下使用任意次的答题机会。
//那么现在问题来了，对于给定的N、M、S、T和A，小Hi他们至少需要答对多少道题目才能够完成所有的关卡呢？
//输入
//  每个输入文件包含多组测试数据，在每个输入文件的第一行为一个整数Q，表示测试数据的组数。
//  每组测试数据的第一行为四个正整数N、M、S和T，意义如前文所述。
//  第二行为N个正整数，分别表示A1~AN。
//  对于40%的数据，满足1 <= N, M <= 100
//  对于100%的数据，满足1 <= N, M <= 1000, 1 <= T<S <= 10, 1 <= Ai <= 50
//	对于100%的数据，满足1 <= Q <= 100
//输出
//	对于每组测试数据，如果小Hi他们能够顺利完成关卡，则输出一个整数Ans，表示小Hi他们至少需要答对的题目数量，否则输出No。
//样例输入
//1
//2 10 9 1
//12 35
//样例输出
//5
const int INF = 1 << 30;

int main()
{
	int q;
	cin >> q;
	while (q--)
	{
		int n, m, s, t;
		cin >> n >> m >> s >> t;
		vector<int> arr(n+1);
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
		}
		vector<vector<int>> dp(n+1,vector<int>(m+1));
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= m; j++)
			{
				dp[i][j] = INF;
			}
		}
		dp[0][0] = 0;
		for (int i = 1; i <= n; i++)//当前准备通关i关卡
		{
			for (int j = 0; j <= m; j++)//当前剩余j次答题机会
			{
				for (int k = ceil((double)arr[i] / s); k >= 0; k--)//第i关卡答对k道题目
				{
					int rem = arr[i] - k*s, p = 0;
					if (rem > 0)
						p = ceil((double)rem / t);
					if (j >= k + p&&dp[i - 1][j - k - p]<INF)
						dp[i][j] = min(dp[i][j], dp[i - 1][j - k - p] + k);
				}
			}
		}
		int res = INF;
		for (int j = 0; j <= m; j++)
			res = min(res, dp[n][j]);
		if (res == INF) cout << "No" << endl;
		else cout << res << endl;

	}
	return 0;
}