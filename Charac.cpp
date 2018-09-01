#include<stdio.h>
#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
	//TestCase
	int N;
	cin >> N;
	map <char, double> mymap;
	map <char, double>::iterator it;
	double total;
	string line;
	int len;
	while (N--) {
		total = 0;
		//주어진 문자 개수
		int K;
		cin >> K;
		//문자 개수 하나당의 가치
		for (int i = 1; i <= K; i++) {
			char c; double v;
			cin >> c >> v;
			mymap[c] = v;
		}
		int M;
		cin >> M;
		cin.ignore();
		while (M--) {
			line = "";
			getline(cin, line);
			len = line.size();
			for (int j = 0; j < len; j++) {
				it = mymap.find(line[j]);
				if (it != mymap.end()) {
					total += it->second;
				}
			}
		}
		total /= 100;
		printf("%0.2lf$\n", total);
		mymap.clear();

	}
    return 0;
}

