//Barnes-Hut Tree Class
import java.awt.Color;

public class BHTree{
   private Body body;
   private Quad quad;
   private BHTree NW;
   private BHTree NE;
   private BHTree SW;
   private BHTree SE;
   
//create initialization for root/empty node
/*public BHTree(double r)
{
	this.body = null;
	this.quad = new Quad(0,0,2*r);
	this.NW = null;
	this.NE = null;
	this.SW = null;
	this.SE = null;
	//this.centerOfMassX = 0.0;
	//this.centerOfMassY = 0.0;
	//this.totalMass = 0.0;

}*/

public BHTree(Quad q)// creates new node with no children
{
	//this.body remains null untl insert
	this.quad = q; //define new quad for subdivision
	this.body = null;
	//initialize the fact that there are currently no children for this node
	this.NW = null;
	this.NE = null;
	this.SW = null;
	this.SE = null;
}

public boolean isExternal(BHTree bht) //checks if node is external
{
	//if there is a child, then return false
	if(bht.NW != null || bht.NE != null || bht.SW != null || bht.SE != null)
	{
		return false;
	}
	
	//if there are no children it is external therefore return true
	else
	{
		return true;
	}
		
}


public void updateForce(Body b)
{
	double phi = 0.5;
	//Approximate the net force acting on b from !!!!ALL!!!! the bodies in the invoking BHTree and update b's force accordingly
	
	if(this.body == null)//exits the recursive algorithm if the body passed in is null or it reaches a null leaf node
	{
		return;
	}
	
	else if(this.isExternal(this)) // base case.. if it is external perform the calculation
	{
		if(this.body != b){
			b.addForce(this.body);
		}
	}

	else //INTERNAL NODES -- recursively call update force for children nodes
	{
		//if node to be updated isnt within and is far enough away
		if((this.quad.length()/(this.body.distanceTo(b))) < phi) 
		{
			b.addForce(this.body); // use the internal node to calculate the updated force
		}
		else //otherwise continue traversing the tree
		{
			if(this.NE != null)
			{
				this.NE.updateForce(b);
			}
			
			if(this.NW != null){
				this.NW.updateForce(b);
			}
			if(this.SE != null)
			{
				this.SE.updateForce(b);
			}
			if(this.SW != null)
			{			
				this.SW.updateForce(b);
			}
		}
	}
}


public String toString() //also draws the tree
{
	if(this == null) //base case
	{
		return "NULL";
	}
	
	return new String(" -- Body: " + this.body + " -- " + "Quad: " + this.quad + "\n" + "			NW: " + this.NW + "\n" + "			NE: " + this.NE + "\n" +"			SW: " + this.SW + "\n" +"			SE: " + this.SE + "\n");
}


//function for inserting nodes into the BH tree
public void insert(Body b)
{
 	if(this.body == null) // if the node does not contain a body and has no children
 	{
		this.body = b; //insert b into the node
	}
	
	else if (!this.isExternal(this)) //if the node has children AKA it is an internal node
	{
		this.body = this.body.plus(b); //updates the COM of the current node by adding in the new body b to the COM.. body b will be inserted recursively below
		//recursively add in b
		if(b.in(this.NW.quad)){
			this.NW.insert(b);
		}
		else if(b.in(this.NE.quad)){
			this.NE.insert(b);
		}
		else if(b.in(this.SW.quad)){
			this.SW.insert(b);
		}
		else if(b.in(this.SE.quad)){
			this.SE.insert(b);
		}
		
	}
	
	else  //if the node has no children but contains a body AKA external node
	{
		//let B be the orignal body and C be the new body b
		//recursively input B and C by creating four children and inserting B and C in the appropriate quad
		
		this.body = this.body.plus(b);
		//create a new node based off of each quad -- tie each new node to the original node
		this.NE = new BHTree(this.quad.NE());
		this.NW = new BHTree(this.quad.NW());
		this.SE = new BHTree(this.quad.SE());
		this.SW = new BHTree(this.quad.SW());
		
		//sort new body into proper location
		if(b.in(this.NW.quad)){
			this.NW.insert(b);
		}
		else if(b.in(this.NE.quad)){
			this.NE.insert(b);
		}
		else if(b.in(this.SW.quad)){
			this.SW.insert(b);
		}
		else if(b.in(this.SE.quad)){
			this.SE.insert(b);
		}
		
		//sort original body into correct location

		if(this.body.in(this.NW.quad)){
			this.NW.insert(this.body);
		}
		else if(this.body.in(this.NE.quad)){
			
			this.NE.insert(this.body);
		}
		else if(this.body.in(this.SW.quad)){
			this.SW.insert(this.body);
		}
		else if(this.body.in(this.SE.quad)){
			this.SE.insert(this.body);
		}
		
	}
		
}

}
