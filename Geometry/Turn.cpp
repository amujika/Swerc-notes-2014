int turn(point p, point q, point r) {
    int result = (r.x - q.x) * (p.y - q.y) - (r.y - q.y) * (p.x - q.x);
    if (result < 0) return -1; // P->Q->R is a right turn
    if (result > 0) return 1; // P->Q->R is a left turn
    return 0; // P->Q->R is a straight line, i.e. P, Q, R are collinear
}
// Note: sometimes, we change the ’> 0’ to ’>= 0’ to accept collinear points
bool ccw(point p, point q, point r) {
    return (turn(p, q, r) > 0);
}
