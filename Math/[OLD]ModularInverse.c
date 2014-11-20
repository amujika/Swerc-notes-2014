/* a osoaren aurkakoa modular b kalkulatzen du
 * Ad: mod_inv(5, 7) = 3
 * 5*3 mod 7 = 15 mod 7 = 1 mod 7
 */

int mod_inv(int a, int b)
{   
    // assert(a > 0 && b > 1);
    int b0 = b, t, q;
    int x0 = 0, x1 = 1;
    if (a == 1) return b + 1;
    while (a > 1 && b != 0) {
        q = a / b;
        t = b, b = a % b, a = t;
        t = x0, x0 = x1 - q * x0, x1 = t;
    }
    
    if (a > 1 && b == 0) return 0;
    if (x1 < 0) x1 += b0;
    return x1;
}
