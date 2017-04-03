#include <iostream>
#include <vector>
using namespace std;


//
//小Hi最近在追求一名学数学的女生小Z。小Z其实是想拒绝他的，但是找不到好的说辞，于是提出了这样的要求：
//对于给定的两个正整数N和M，小Hi随机选取一个N的约数N'，小Z随机选取一个M的约数M'，如果N'和M'相等，她就答应小Hi。
//小Z让小Hi去编写这个随机程序，到时候她review过没有问题了就可以抽签了。但是小Hi写着写着，却越来越觉得机会渺茫。
//那么问题来了，小Hi能够追到小Z的几率是多少呢？
//输入:
//每个输入文件仅包含单组测试数据。
//每组测试数据的第一行为两个正整数N和M，意义如前文所述。
//对于40%的数据，满足1 <= N, M <= 106
//对于100%的数据，满足1 <= N, M <= 1012
//输出:
//对于每组测试数据，输出两个互质的正整数A和B（以A分之B表示小Hi能够追到小Z的几率）。

long long int gcd(long long int x, long long int y) {
	if (x<y) {
		swap(x, y);
	}
	return x%y == 0 ? y : gcd(y, x%y);
}

////若n为新质数，添加到primeTable中
//bool addPrime(long long int n, vector<long long int> &primeTable) {
//	if (n <2) {
//		return false;
//	}
//	for (long long int i = 0; i<primeTable.size() && primeTable[i] <= sqrt(n); i++) {
//		if (n%primeTable[i] == 0) {
//			return false;
//		}
//	}
//	primeTable.push_back(n);
//	return true;
//}


//void primeCount(long long int n, vector<long long int>&prime, vector<long long int>&count) {
//	if (n < 2) {
//		return;
//	}
//	for (long long int i = 2; i <= n; i++) {
//		if (addPrime(i, prime)) {
//			count.push_back(0);
//			while (n%i == 0) {
//				n = n / i;
//				count[count.size() - 1]++;
//			}
//		}
//	}
//}


void primeCount(long long int n, vector<long long int> &prime, vector<long long int> &count) {
	if (n < 2) {
		return;
	}
	if (n % 2 == 0) {
		prime.push_back(2);
		count.push_back(0);
		while (n % 2 == 0) {
			count[count.size() - 1]++;
			n = n / 2;
		}
	}
	for (long long int i = 3; i <= n; i += 2) {
		if (n % i == 0) {
			prime.push_back(i);
			count.push_back(0);
			while (n % i == 0) {
				count[count.size() - 1]++;
				n = n / i;
			}
		}
	}
}


int W144() {
	vector<long long int> primeTable;
	long long int N, M;
	cin >> N >> M;
	//long long int M = 4;
	//long long int N = 6;
	long long int C = gcd(M, N);
	vector<long long int> primeC, countC;
	primeCount(C, primeC, countC);
	vector<long long int> primeM, countM;
	vector<long long int> primeN, countN;
	primeCount(M, primeM, countM);
	primeCount(N, primeN, countN);
	long long int sumC = 1, sumM = 1, sumN = 1;
	for (long long int i = 0; i < primeC.size(); i++) {
		sumC *= (countC[i] + 1);
	}
	//cout << sumC << endl;
	for (long long int i = 0; i < primeM.size(); i++) {
		sumM *= (countM[i] + 1);
	}
	//cout << sumM << endl;
	for (long long int i = 0; i < primeN.size(); i++) {
		sumN *= (countN[i] + 1);
	}
	//cout << sumN << endl;
	long long int X = gcd(sumC, sumM*sumN);
	cout << sumM*sumN / X << " " << sumC / X << endl;

	return 0;
}