package main;

import main.Planet;

public class Planet {
	//define all class fields (characterstics of the planet class)

	private double xPos;
	private double yPos;
	private double xVel;
	private double yVel;
	private double mass;
	private String imgFileName;

	// Define Get class methods for each variable (due to their description as private)

	public double getxPos()
	{
		return xPos;
	}

	public double getyPos()
	{
		return yPos;
	}

	public double getxVel()
	{
		return xVel;
	}

	public double getyVel()
	{
		return yVel;
	}

	public double getMass()
	{
		return mass;
	}

	public String getImgFileName()
	{
		return imgFileName;
	}

	//Define Set class method

	public void setxPos(double newXPos)
	{
		xPos = newXPos;
		return;
	}

	public void setyPos(double newYPos)
	{
		yPos = newYPos;
		return;
	}

	public void setxVel(double newXVel)
	{
		xVel = newXVel;
		return;
	}

	public void setyVel(double newYVel)
	{
		yVel = newYVel;
		return;
	}

	public void setMass(double newMass)
	{
		mass = newMass;
		return;
	}

	public void setImgFileName(String newImgFileName)
	{
		imgFileName = newImgFileName;
		return;
	}

	//Created two different constructors
	public Planet(double xP, double yP, double xV, double yV, double m, String img)
	{
		xPos = xP;
		yPos = yP;
		xVel = xV;
		yVel = yV;
		mass = m;
		imgFileName = img;
	} // end primary planet constructor

	//create copy constructor, uses predefined planet p as base for new stats
	public Planet(Planet p)
	{
		xPos = p.getxPos();
		yPos = p.getyPos();
		xVel = p.getxVel();
		yVel = p.getyVel();
		mass = p.getMass();
		imgFileName = p.getImgFileName();

	} // end planet copy

	// calculates the distance from the planet invoking the method and P
	public double calcDistance(Planet p)
	{
		double xPosHome = this.getxPos();
		double yPosHome = this.getyPos();
		double xPosAlien = p.getxPos();
		double yPosAlien = p.getyPos();
		double dist = 0;
		
		dist = Math.sqrt(((xPosAlien - xPosHome)*(xPosAlien - xPosHome))+((yPosAlien - yPosHome)*(yPosAlien - yPosHome)));
		
		return dist;
	}// end calc distance
		
	// calculates force of P exerted on invoking planet
	public double calcForceExertedBy(Planet p)
	{
		final double G = 6.67*(Math.pow(10.0,-11));
		double dist = this.calcDistance(p);
		double m1 = this.getMass();
		double m2 = p.getMass();
		double force = 0;
		
		force = (G*m1*m2)/(dist*dist);
		
		return force;// return the force value
	} // end calcForceExertedBy
	
	//calculates the x component of the force P exerted on the invoking planet
	public double calcForceExertedByX(Planet p)
	{
		double netForce = this.calcForceExertedBy(p);
		double dist = this.calcDistance(p);
		double fX = 0;
		double xPosHome = this.getxPos();
		double xPosAlien = p.getxPos();
		
		fX = netForce*((xPosAlien - xPosHome)/dist);
		return fX;
	}// end calcForceExertedByX
		
	// calculates the y component of the force P exerts on the invoked planet
	public double calcForceExertedByY(Planet p)
	{
		double netForce = this.calcForceExertedBy(p);
		double dist = this.calcDistance(p);
		double fY = 0;
		double yPosHome = this.getyPos();
		double yPosAlien = p.getyPos();
		
		// according to the equations statement below is true
		fY = netForce*((yPosAlien - yPosHome)/dist);
		return fY; // return this value
	} // end calcForceExertedByY
		
	/* 
	 * Takes an array of planets "p" and calculates the net X and net Y forces exerted by all planets in array p on the invoking planet 
	 */
	public double calcNetForceExertedByX(Planet[] p)
	{
		int numPlanets = p.length;
		int j;
		int i;
		double[] fX = new double[numPlanets];
		double netFX = 0;
		
		
		for (j=0; j<numPlanets; j++)
		{
			if(p[j] == this) // check if planet is trying to exert force upon itself
			{
				fX[j] = 0; // if so the force is zero
			}
			else // otherwise calc as normal
			{
				fX[j] = this.calcForceExertedByX(p[j]);
			}
		}// end addition for
		
		
		for(i=0; i<fX.length; i++) // sum the values for Fx into a single var
		{
			
			netFX += fX[i];
		}
		
		return netFX; // return the net force
		
	
	}// end net force x
	
	public double calcNetForceExertedByY(Planet[] p)
	{
		int numPlanets = p.length;
		int j;
		int i;
		double[] fY = new double[numPlanets];
		double netFY = 0;

		for (j=0; j<numPlanets; j++)
		{
			if(p[j] == this) // check if the planet being calculated is the same planet that invoked the call
			{
				fY[j] = 0; // if so force is zero
			} // end if
			else // otherwise calculate force as usual
			{
				fY[j] = this.calcForceExertedByY(p[j]);
			} // end else
		}// end calculation for
	
		for(i=0; i<fY.length; i++) // for loop to sum the net force from the array into a single variable
		{
			
			netFY += fY[i];
		}// end sum for
				
		return netFY;// return value
	
	}// end net force Y
	
	public void update(double time, double forceX, double forceY)
	{
		double accelX;
		double accelY;
		double vXO;
		double vYO;
		double pXO;
		double pYO;
		
		vXO = this.getxVel();
		vYO = this.getyVel();
		pXO = this.getxPos();
		pYO = this.getyPos();
		
		// calc accel to be used in calcs below
		accelX = (forceX/this.getMass());
		accelY = (forceY/this.getMass());
		
		
		// calc new velocity and update obj using get function
		this.setxVel(vXO + (accelX*time));
		this.setyVel(vYO + (accelY*time));
		
		// calc new pos and update obj using get function
		this.setxPos(pXO + (this.getxVel()*time));
		this.setyPos(pYO + (this.getyVel()*time));
		
		
		return;
		
	}// end update
	
	public void draw()
	{
		StdDraw.picture(this.getxPos(), this.getyPos(), this.getImgFileName());
	}

	
} // end planet class