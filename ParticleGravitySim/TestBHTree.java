
public class TestBHTree {
    public static void main(String[] args){
	//functions that need to be tested:
	//BHTree for empty node
	//BHTree constructor
	//updateForce
	//insert		

	//toString method is no longer necessary
	//isExternal is called by update force

	double radius = 10.0;
	Quad universe = new Quad(0.0, 0.0, 2*radius);  //bhtree constructor already does this 
	System.out.print("Universe quadrant: " + universe + "\n\n");
	StdDraw.clear(StdDraw.BLACK);
	StdDraw.setPenColor(StdDraw.YELLOW);
	StdDraw.setXscale(-radius, +radius);
	StdDraw.setYscale(-radius, +radius);
	universe.draw();

	
	BHTree bhtree = new BHTree(universe); // equivilant to new BHTree(universe)
	
	// below simulates the bodies shown in the PDF example
	Body a = new Body(-5, 5, 0.0, 0.0, 1.0, StdDraw.YELLOW);
	Body b = new Body(3.5, 9.5, 0.0, 0.0, 1.0, StdDraw.YELLOW);
	Body c = new Body(1.5, 6.0, 0.0, 0.0, 1.0,  StdDraw.YELLOW);
	Body d = new Body(6, 4,0.0, 0.0, 1.0, StdDraw.YELLOW);
	Body e = new Body(-6, -4, 0.0, 0.0, 1.0,  StdDraw.YELLOW);
	Body f = new Body(-6, -6, 0.0, 0.0, 1.0, StdDraw.YELLOW);
	Body g = new Body(-2, -8, 0.0, 0.0, 1.0, StdDraw.YELLOW);
	Body h = new Body(4, -7, 0.0, 0.0, 1.0, StdDraw.YELLOW);
	
	/*if(a.in(quad)){
	    bhtree.insert(a);
	}
	if(b.in(quad)){
	    bhtree.insert(b);
	}
	if(c.in(quad)){
	    bhtree.insert(c);
	}
	if(d.in(quad)){
	    bhtree.insert(d);
	}
	if(e.in(quad)){
	    bhtree.insert(e);
	}
	bhtree.updateForce(b);

    }*/
	
	bhtree.insert(a);
	bhtree.insert(b);
	bhtree.insert(c);
	bhtree.insert(d);
	bhtree.insert(e);
	bhtree.insert(f);
	bhtree.insert(g);
	bhtree.insert(h);
	
	//bhtree.updateForce(a); // outputs really small numbers because the numbers we are using are very small
	
	//System.out.println(bhtree); // the toString method also draws the quads
	
	//also need to test update force
	}
}



