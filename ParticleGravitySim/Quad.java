public class Quad {
    private double xmid;
    private double ymid;
    private double length;
    //four sub quads
    //private Quad Northwest, Northeast, Southwest, Southeast;
    //the public methods below will probably return one of the sub quadrants to be inserted into the tree

    // create a new square with the given parameters (assume it is square)
    public Quad(double _xmid, double _ymid, double _length) {
	this.xmid = _xmid;
	this.ymid = _ymid;
	this.length = _length;
    }

    // return the length of one side of the square quadrant
    public double length() {
	return length;
    }

    // return a new object that represents the northwest quadrant
	// uses midpoint formula
    public Quad NW() {
		return new Quad(((-1*this.length)/4+this.xmid), (this.length/4+this.ymid), this.length/2);
    }

    // return a new object that represents the northeast quadrant
    public Quad NE() {
		return new Quad(((this.length)/4+this.xmid), (this.length/4+this.ymid), this.length/2);
    }

    // return a new object that represents the southwest quadrant
    public Quad SW() {
		return new Quad(((-1*this.length)/4+this.xmid), ((-1*this.length)/4+this.ymid), this.length/2);
    }

    // return a new object that represents the southeast quadrant
    public Quad SE() {
		return new Quad((this.length/4+this.xmid), ((-1*this.length)/4+this.ymid), this.length/2);
    }

    // draw an unfilled rectangle that represents the quadrant
    public void draw() {
		StdDraw.square(this.xmid, this.ymid, (this.length/2)); 
	}

	//StdDraw.setPenColor(color);
	//StdDraw.point()

    // return a string representation of the quadrant for debugging
    public String toString() {
		this.draw();
		return "Xmid: " + this.xmid + " Ymid: " + this.ymid + " Length: " + this.length;
    }
	
    public boolean contains(double x, double y) {
		
	//check if x is contained within quadrant (using geometry)
	if(x >= (this.xmid - (this.length)/2) && x <= (this.xmid + (this.length)/2) && y <= (this.ymid + (this.length)/2) && y >= (this.ymid - (this.length)/2))
	{
		return true;
	}
	
	else
	{
		return false;
	}
	 

    } 

}
