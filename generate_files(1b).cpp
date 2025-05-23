#include<iostream>
#include<string>
#include<sstream>
#include <fstream>
using namespace std;
int digitsOfNumber(int n){
	if( n == 0)
		return 1;
	int count = 0;
	while(n != 0){
		n /= 10;
		count++;
	}
	return count;
}
void writeToFile(string link, int cluster, int sizeOfCluster, int k){
	int digits = digitsOfNumber(k);
	ofstream ofs(link.c_str());
	if(cluster == 1){
		ofs << k;
		ofs.close();
		return;
	}
	for(int i = 0; i < sizeOfCluster*cluster/(digits + 2)/2 + 1; i++){
		ofs << k << "\n";
	}
	ofs.close();
}
int main(){
	int n = 0;
	cout << "Nhap n: ";
	cin >> n;
	for(int i = 0; i < n; i++){
		
		stringstream ss;
		ss << i;
		string str = ss.str();
		str = "F" + str + ".dat";
		
		writeToFile(str, 2 - i%2, 512*8, i);
	}
	return 0;
}
