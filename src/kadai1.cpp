#include <iostream>
using namespace std;
#define CPP2_PRIME_UPPER_LIMIT 1000000 //探索する値の上限値。

int nth_prime(unsigned int a, unsigned int d, unsigned int n){
	int i, j, y;
	int x = 0;
	int a1, d1;
	int aa = 1;
	//互いに素検索
	a1 = a; d1 = d;
	for (;;) {
		if (a1%d1 == 0)break;
		aa = a1%d1;
		a1 = d1;
		d1 = aa;
	}
	if (aa != 1)std::cout << a <<"と"<<d<< "は互いに素ではありません";
	//素数検索
	if (aa==1) {
		for (i = a; i <= CPP2_PRIME_UPPER_LIMIT; i += d) {
			y = 0;
			for (j = 1; j <= i; j++) {
				if (i%j == 0)y++;
			}
			if (y == 2)x++;
			if (x == n)return i;
		}
		std::cout << CPP2_PRIME_UPPER_LIMIT << "までの素数には存在しません";
	}
	return 0;
		}

void comp(unsigned int a, unsigned int d) {//比較
	std::cout <<d<< std::endl;
	if (a == d) {
		std::cout << "正解" << std::endl;
	}
	else
	{
		std::cout << "失敗" << std::endl;
	}
	std::cout << std::endl;
}

int main() {
	int a ;
	a = 92809;
	std::cout << "367, 186, 151= ";
	comp(a,nth_prime(367, 186, 151) );

	a = 6709;
	std::cout << "179, 10, 203= ";
	comp(a, nth_prime(179, 10, 203));
	
	a = 12037;
	std::cout << "271, 37, 39= ";
	comp(a, nth_prime(271, 37, 39));

	a = 103;
	std::cout << "103, 230, 1= ";
	comp(a, nth_prime(103, 230, 1) );

	a = 93523;
	std::cout << "27, 104, 185= ";
	comp(a, nth_prime(27, 104, 185));

	a = 14503;
	std::cout << "253, 50, 85= ";
	comp(a, nth_prime(253, 50, 85));

	a = 2;
	std::cout << "1, 1, 1= ";
	comp(a, nth_prime(1, 1, 1));

	a = 899429;
	std::cout << "9075, 337, 210= ";
	comp(a, nth_prime(9075, 337, 210));

	a = 5107;
	std::cout << "307, 24, 79= ";
	comp(a, nth_prime(307, 24, 79 ));

	a = 412717;
	std::cout << "331, 221, 177= ";
	comp(a, nth_prime(331, 221, 177));

	a = 22699;
	std::cout << "259, 170, 40= ";
	comp(a, nth_prime(259, 170, 40));

	a = 25673;
	std::cout << "269, 58, 102= ";
	comp(a, nth_prime(269, 58, 102));

	a = 100;
	std::cout << "465, 360, 100=";//比較が違う
	comp(a,nth_prime(465, 360, 100) );

	a = 1082027;
	std::cout << "269, 58, 3000= ";//素数が1000000を越えた
	comp(a, nth_prime(269, 58, 3000));

    return 0;
}