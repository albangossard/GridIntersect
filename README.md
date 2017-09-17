# GridIntersect
A library to compute the intersection of segments with an orthogonal mesh grid.

## Example
This library is easy to use. To compute mesh grid intersection with a segment, just declare a new grid :
<pre><code>
Grid Map(5,5);
</code></pre>
GridIntersect provide a Point structure to define segment ends. To compute intersection, define the ending points and call the intersect method :
<pre><code>
Point pt1;
Point pt2;
pt1.x=0.8/4.0; pt1.y=0.2/4.0;
pt2.x=2.1/4.0; pt2.y=3.7/4.0;
list<Point> intersectPt;
Map.intersect(&pt1,&pt2,intersectPt);
</code></pre>
The points in the intersectPt list are ranged from pt1 to pt2 order.

Printing the intersection gives the following result :
<pre><code>
list<Point>::iterator it;
for (it=intersectPt.begin(); it!=intersectPt.end(); ++it){
    cout << it->x << " " << it->y << endl;
}
</code></pre>
<pre><code>
0.2 0.05
0.25 0.184615
0.274286 0.25
0.367143 0.5
0.46 0.75
0.5 0.857692
0.525 0.925
</code></pre>