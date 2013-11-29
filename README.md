pso - Particle Swarm Optimization
=================================

My experiment with this wonderfull stochastic optimisation method. You can find more information about it on [wikipedia][http://en.wikipedia.org/wiki/Particle_swarm_optimization] or in [this paper][ftp://emci.udg.edu/amade/mms/OME/treballs/articles_PSO/Particle-swarm-optimization-SI-Vol-1.pdf].

Installation
============
```
make
````

Usage
=====
```
Usage: ./pso [FLAGS]
-w, --w				inertia
-c, --c				constriction
-i, --max-iterations		upper limit for iterations
-d, --dimension			set dimension of the problem
-p, --problem			problem to solve: sphere, rosenbrock, rastrigin, test
-P, --population		number of particles, default 20 + dimension
-f, --file			record computing to file, JSON format
-F, --fips			use Fully Informed Particle Swarm
-h, --help			show this help

Topology settings:
-g, --gbest			use gbest topology
-l, --lbest			use lbest topology
-I, --dynamic-iterations	change dynamic topology every value iterations
-n, --dynamic-neighbours	have value neighbours in dynamic topology
```

Example
======
```
$./pso --problem sphere --lbest 2 --file sphere.json --dimension 4
sphere:
Success: 1
iterations: 203
Best x: [ -4.78121e-06 -3.89934e-06 4.67562e-06 5.73368e-07 ]
Best x fitness: 6.0255e-11
```
