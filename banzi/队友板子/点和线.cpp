struct point{
    double x,y;
    point(double _x=0,double _y=0){ x=_x,y=_y; }
    point operator+ (const point& a) const{ return point(x+a.x,y+a.y); }
    point operator- (const point& a) const{ return point(x-a.x,y-a.y); }
    point operator* (double a) const{ return point(x*a,y*a); }
}; // 点
struct line{
    point s,e;
    line(point a,point b){ s=a,e=b; }
    line(){}
}; // 线
double getdis(point a, point b){
    double xx=a.x-b.x,yy=a.y-b.y;
    return sqrt(xx*xx+yy*yy);
} // 两点距离
double multi(point a,point b,point c){
    double xa,ya,xb,yb;
    xa=b.x-a.x; ya=b.y-a.y;
    xb=c.x-b.x; yb=c.y-b.y;
    return xa*xb+ya*yb;
} // 点乘
double cross(point a,point b,point c){
    double xa,ya,xb,yb;
    xa=b.x-a.x; ya=b.y-a.y;
    xb=c.x-a.x; yb=c.y-a.y;
    return xa*yb-xb*ya;
} // 叉乘
int judgec(line a,line b){
    if (max(a.s.x,a.e.x)>=min(b.s.x,b.e.x) &&
        max(a.s.y,a.e.y)>=min(b.s.y,b.e.y) &&
        max(b.s.x,b.e.x)>=min(a.s.x,a.e.x) &&
        max(b.s.y,b.e.y)>=min(a.s.y,a.e.y) &&
        cross(a.s,b.s,b.e)*cross(a.e,b.s,b.e)<=0 
        && cross(b.s,a.s,a.e)*cross(b.e,a.s,a.e)<=0
        ) return 1;
    else return 0;
} // 判断线段是否相交
point getpoi(point a,point b,point c,point d){
    double u=cross(a,b,c),v=cross(b,a,d);
    return point((c.x*v+d.x*u)/(u+v),(c.y*v+d.y*u)/(u+v));
} // 求交点