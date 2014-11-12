int x, y, d;
// a*x + b*y = d
// Infinite solutions: 
// Xi = x + (b/d) * n
// Yi = y - (a/d) * n
// a*x + b*y = c can be solved iff d divides c, in such cases we multiply both sides with c/d
void extendedEuclid(int a, int b) {
	if (b == 0) { x = 1; y = 0; d = a; return; }
	extendedEuclid(b, a % b);
	int x1 = y;
	int y1 = x - (a / b) * y;
	x = x1;
	y = y1;
}
