/* Bi zuzenen arteko ebakidura */

#include <algorithm>

using namespace std;

typedef struct { bool exists; int x; int y;} point;

point intersection(
		int x1,int y1,int x2,int y2, 
		int x3, int y3, int x4, int y4
	) {
    point p;
    p.exists = false;
    
    int d = (x1-x2)*(y3-y4) - (y1-y2)*(x3-x4);
    if (d == 0) return p;
    
    int xi = ((x3-x4)*(x1*y2-y1*x2)-(x1-x2)*(x3*y4-y3*x4))/d;
    int yi = ((y3-y4)*(x1*y2-y1*x2)-(y1-y2)*(x3*y4-y3*x4))/d;
    
    p.x = xi; p.y = yi;
    //return p;  //hemen ez bada zuzenkian dagoen egiaztatu behar
    
    if (xi < min(x1,x2) || xi > max(x1,x2)) return p;
    if (xi < min(x3,x4) || xi > max(x3,x4)) return p;
    p.exists = true;
    return p;
}
