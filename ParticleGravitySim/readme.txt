# Particle Gravity Simulation
## Blake Capella

- Name(s):Ranen Liu and Blake Capella
- OS: Windows
- Text editor: vi, eclipse, textpad++

Uses Newton's law of universal gravitation to compute the forces acting on a single body (equivalent to a planet). These bodies are illustrated as a single pixel. In order to calculate the forces acting on massive numbers of particles, the Barnes Hut Algorithm is used to group together local bodies within a set distance. This occurs when a cluster of bodies is being referenced to calculate the force acting on a body in question. The algorithm averages their center of gravity and sums their mass and calculates the force generated as if it were a single massive planet centered around the shared center of mass.

