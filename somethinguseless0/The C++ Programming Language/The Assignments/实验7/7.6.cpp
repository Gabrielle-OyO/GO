#include<iostream>
using namespace std;
int main()
{
	int x, y,temp,b,c;
	int (*p)[6];
	 p= new int[6][6];
	 for (x = 0; x < 6; x++) {
		 for (y = 0; y < 6; y++) {
			 cin >> p[x][y];
		 }
	 }
	 temp = p[0][0];
	 for (x = 0; x < 6; x++) {
		 for (y = 0; y < 6; y++) {
			 if (p[x][y] > temp) {
				 temp = p[x][y];
				 b = x;
				 c = y;
			}
		 }
	 }
	 cout << "���Ԫ�أ�" << temp << endl;
	 cout << "���꣺[" << b <<"]"<<"["<<c <<"]"<< endl;
	 delete[]p;
	 return 0;

}