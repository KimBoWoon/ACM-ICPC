#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

double x, y, c;
double hx, hy;

/*
출처 : http://blog.naver.com/PostView.nhn?blogId=591923&logNo=220910770730
직선의 방정식을 사용한다는데 잘 모르겠다...
*/

int main() { 
    scanf("%lf %lf %lf", &x, &y, &c);

    double left = 0.0, right = min(x, y);
    
    while (right - left > 1e-6) {
        double d = (left + right) / 2.0;
        double hx = sqrt(x * x - d * d);
        double hy = sqrt(y * y - d * d);
        double k = d * c / hy;
        double f = (-hx * k / d) + hx;
        
        if (f > c) {
            left = d;
        } else {
            right = d;
        }
    }

    printf("%.3f\n", left);

    return 0;
}