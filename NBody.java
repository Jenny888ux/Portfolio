package main;


import main.In;
import main.NBody;
import main.Planet;
import main.StdDraw;

public class NBody {
	
	// reads from the text file the radius of the univers to use in the drawing
	public static double readRadius(String filename)
	{
		In in = new In(filename);
		@SuppressWarnings("unused")
		int numPlanets = in.readInt();
		double radius = in.readDouble();
		numPlanets = 0;
		
		return radius; // returns the radius
	} // end readRadius

	// reads the information about the solar system from the text file using the In.java file
	public static Planet[] readPlanets(String filename)
	{
		In in = new In(filename); // construct new in object
		int i = 0;
		int numberPlanets = in.readInt();
		
		@SuppressWarnings("unused") // get rid of radius warning of it not being used
		double radius = in.readDouble();
		double xPos = 0;
		double yPos = 0;
		double xVel = 0;
		double yVel = 0;
		double mass = 0;
		String imgFileName = "";
		String extens = "./images/";
		Planet[] planetsInFile = new Planet[numberPlanets]; // creates array of planets for output
		
		//for loop to go through the file and construct each planet at a different spot in the array
		for (i=0; i < numberPlanets; i++) 
		{
			
			xPos = in.readDouble(); // each read command moves down the text line
			yPos = in.readDouble(); //  order coded by order given in the data files
			xVel = in.readDouble();
			yVel = in.readDouble();
			mass = in.readDouble();
			imgFileName = extens.concat(in.readString());
			
			planetsInFile[i] = new Planet(xPos, yPos, xVel, yVel, mass, imgFileName); 
			
		}// end planet creation for loop

		
		return planetsInFile; // returns array of created planets
	}// end readPlanets
	
	public static void main (String[] args)
	{
		double radius;
		double T = 0.0;
		double dt = 0.0;
		int i = 0;
		int time = 0;
		T = Double.parseDouble(args[0]);
		dt = Double.parseDouble(args[1]); 
		Planet[] bodies;
		int j = 0;
		int k = 0; 
		int l = 0;
		
		radius = NBody.readRadius(args[2]);//determine the radius of the universe
		bodies = NBody.readPlanets(args[2]);// construct the planets
		
		// define two arrays based off of the length of bodies
		double[] xForces = new double[bodies.length];
		double[] yForces = new double[bodies.length];
		
		StdDraw.setScale(-radius, radius);
		StdDraw.picture(0, 0, "./images/starfield.jpg");
		

		for (i = 0; i< bodies.length; i++)
		{
			bodies[i].draw();
		}
		
		while(time != T)
		{
			for (k = 0; k< bodies.length; k++) // calculate the x and y forces being exerted on each planet in turn
			{
						xForces[k] = bodies[k].calcNetForceExertedByX(bodies);
						yForces[k] = bodies[k].calcNetForceExertedByY(bodies);	
			}// end calc for
			
			for(j=0; j<bodies.length; j++) //update the stats on each planet in turn
			{
				bodies[j].update(dt, xForces[j], yForces[j]);
			}// end update for
			
			StdDraw.picture(0, 0, "./images/starfield.jpg"); // redraw background
			
			for (l = 0; l< bodies.length; l++) // redraw each planet with new position
			{
				bodies[l].draw();
			}
			
			StdDraw.show(10); // turn on animation mode for 1 ms
			
			time += dt; // increment time by dt
		}// end while loop
		
		System.out.print("Finished");
		
		//Outputting file similar to the one inputted
		StdOut.printf("%d\n", bodies.length);
		StdOut.printf("%.2e\n",  radius);
		for(int m = 0; m < bodies.length; m++)
		{
			StdOut.printf("%11.4e %11.4e %11.4e %11.4e %11.4e %12s\n", 
							bodies[i].getxPos(),
							bodies[i].getyPos(),
							bodies[i].getxVel(),
							bodies[i].getyVel(),
							bodies[i].getMass(),
							bodies[i].getImgFileName());
		}
					
	}// end main
}
