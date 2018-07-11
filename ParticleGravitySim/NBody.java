//javac -cp . NBody.java
//java -cp . NBody 157788000.0 25000.0 < planets.txt
//NbodyBrute


import java.awt.Color;

public class NBody{

    public static void main(String[] args) {
        final double dt = 0.1;                     // time quantum
        int N = StdIn.readInt();                   // number of particles
        double radius = StdIn.readDouble();        // radius of universe

        // turn on animation mode and rescale coordinate system
        StdDraw.show();
        StdDraw.pause(10);
        StdDraw.enableDoubleBuffering();
        StdDraw.setXscale(-radius, +radius);
        StdDraw.setYscale(-radius, +radius);

        // read in and initialize bodies
        Body[] bodies = new Body[N];               // array of N bodies
        for (int i = 0; i < N; i++) {
            double px   = StdIn.readDouble();
            double py   = StdIn.readDouble();
            double vx   = StdIn.readDouble();
            double vy   = StdIn.readDouble();
            double mass = StdIn.readDouble();
            int red     = StdIn.readInt();
            int green   = StdIn.readInt();
            int blue    = StdIn.readInt();
            Color color = new Color(red, green, blue);
            bodies[i]   = new Body(px, py, vx, vy, mass, color);
        }

	Quad universe = new Quad(0,0,2*radius);
	BHTree bht = new BHTree(universe);
	for(int k = 0; k < N; k++) //insert the bodies into a new BHTree at each time step
	    {
		if(bodies[k].in(universe)) // check to make sure the body is within the universe
		    {
			bht.insert(bodies[k]);
		    }
	    }
			

        // simulate the universe
        for (double t = 0.0; true; t = t + dt) 
	    {
		for(int j=0; j < N; j++)
		    {
			bodies[j].resetForce();
		    }
					
		for(int j=0; j < N; j++)
		    {
			bht.updateForce(bodies[j]);
		    }

		for (int j=0; j < N; j++)
		    {
			bodies[j].update(dt);
		    }
				
		StdDraw.clear(StdDraw.BLACK);
		for (int i = 0; i < N; i++) 
		    {
		    bodies[i].draw();
		    }
		StdDraw.show(10);
	    }
    }
}

