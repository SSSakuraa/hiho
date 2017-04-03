#include <iostream>
#include <vector>
using namespace std;


//
//СHi�����׷��һ��ѧ��ѧ��Ů��СZ��СZ��ʵ����ܾ����ģ������Ҳ����õ�˵�ǣ����������������Ҫ��
//���ڸ���������������N��M��СHi���ѡȡһ��N��Լ��N'��СZ���ѡȡһ��M��Լ��M'�����N'��M'��ȣ����ʹ�ӦСHi��
//СZ��СHiȥ��д���������򣬵�ʱ����review��û�������˾Ϳ��Գ�ǩ�ˡ�����СHiд��д�ţ�ȴԽ��Խ���û�����ã��
//��ô�������ˣ�СHi�ܹ�׷��СZ�ļ����Ƕ����أ�
//����:
//ÿ�������ļ�����������������ݡ�
//ÿ��������ݵĵ�һ��Ϊ����������N��M��������ǰ��������
//����40%�����ݣ�����1 <= N, M <= 106
//����100%�����ݣ�����1 <= N, M <= 1012
//���:
//����ÿ��������ݣ�����������ʵ�������A��B����A��֮B��ʾСHi�ܹ�׷��СZ�ļ��ʣ���

long long int gcd(long long int x, long long int y) {
	if (x<y) {
		swap(x, y);
	}
	return x%y == 0 ? y : gcd(y, x%y);
}

////��nΪ����������ӵ�primeTable��
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