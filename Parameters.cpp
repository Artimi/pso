#include <string>
#include <iostream>
#include <getopt.h>
#include "Parameters.hpp"

std::ostream &operator<<(std::ostream &out, Parameters p)
{
	out << "w: " << p.w << ", "
		<< "c: " << p.c << ", "
		<< "max-iterations: " << p.max_iterations << ", "
		<< "dimension: " << p.dimension << ", "
        << "population: " << p.population << ", "
		<< "dynamic: " << p.dynamic << ", "
		<< "dynamic-iterations: " << p.dynamic_iterations << ", "
		<< "dynamic-neighbours: " << p.dynamic_neighbours << ", "
		<< "fips: " << p.fips << ", "
		<< "gbest: " << p.gbest << ", "
		<< "lbest: " << p.lbest << ", "
		<< "problem: " << p.problem << ", "
		<< "file: " << p.file ;
	return out;
}

void printHelp()
{
	std::cout 
	<< "Usage: pso [FLAGS]" << std::endl
	<< "-w, --w\t\t\t\tinertia" << std::endl
	<< "-c, --c\t\t\t\tconstriction" << std::endl
	<< "-i, --max-iterations\t\tupper limit for iterations" << std::endl
	<< "-d, --dimension\t\t\tset dimension of the problem" << std::endl
	<< "-p, --problem\t\t\tproblem to solve: sphere, rosenbrock, rastrigin" << std::endl
                    <<"\t\t\t\tdimensionTest, iterationTest" << std::endl
    << "-P, --population\t\tnumber of particles, default 20 + 2 * dimension" << std::endl
	<< "-f, --file\t\t\trecord computing to file, JSON format" << std::endl
	<< "-F, --fips\t\t\tuse Fully Informed Particle Swarm" << std::endl
	<< "-h, --help\t\t\tshow this help" << std::endl
	<< std::endl
	<< "Topology settings:" << std::endl
	<< "-g, --gbest\t\t\tuse gbest topology" << std::endl
	<< "-l, --lbest\t\t\tuse lbest topology" << std::endl
    << "-D --dynamic\t\t\tuse dynamic topology" << std::endl
	<< "-I, --dynamic-iterations\tchange dynamic topology every value iterations" << std::endl
	<< "-n, --dynamic-neighbours\thave value neighbours in dynamic topology" << std::endl;
}

Parameters parse(int argc, char * argv[])
{	
	Parameters parameters;
    const struct option longopts[] =
    {
    {"w", required_argument, 0, 'w'},
    {"c", required_argument, 0, 'c'},
    {"max-iterations", required_argument, 0, 'i'},
    {"dimension", required_argument, 0, 'd'},
    {"population", required_argument, 0, 'P'},
    {"dynamic", no_argument, 0, 'D'},
    {"dynamic-iterations", required_argument, 0, 'I'},
    {"dynamic-neighbours", required_argument, 0, 'n'},
    {"file", required_argument, 0, 'f'},
    {"fips", no_argument, 0, 'F'},
    {"gbest", no_argument, 0, 'g'},
    {"lbest", required_argument, 0, 'l'},
    {"problem", required_argument, 0, 'p'},
    {"help", no_argument, 0, 'h'},
    {0,0,0,0},
    };

    int index;
    int iarg = 0;

    while(iarg != -1)
    {
    	iarg = getopt_long(argc, argv, "w:c:i:d:I:n:f:F:gl:p:P:hD", longopts, &index);

    	switch (iarg)
    	{
    		case 'w':
    			parameters.w = std::stod(optarg);
    			break;
    		case 'c':
    			parameters.c = std::stod(optarg);
    			break;
    		case 'i':
    			parameters.max_iterations = std::stoi(optarg);
    			break;
    		case 'd':
    			parameters.dimension = std::stoi(optarg);
    			break;
            case 'D':
                parameters.dynamic = true;
                break;
    		case 'I':
    			parameters.dynamic_iterations = std::stoi(optarg);
    			parameters.dynamic = true;
    			break;
    		case 'n':
    			parameters.dynamic_neighbours = std::stoi(optarg);
    			parameters.dynamic = true;
    			break;
    		case 'f':
    			parameters.file = optarg;
    			break;
  			case 'F':
  				parameters.fips = true;
  				break; 
  			case 'g':
  				parameters.gbest = true;
  				break; 
    		case 'l':
    			parameters.lbest = std::stoi(optarg);
    			break;
    		case 'p':
    			parameters.problem = optarg;
    			break;
            case 'P':
                parameters.population = std::stoi(optarg);
                break;
        	case 'h':
        		printHelp();
        		exit(0);
            	break;
           	case '?':
           		exit(1);
           		break; 
           	case ':':
           		exit(1);
           		break;
    	}
  	}
    	if((parameters.gbest and parameters.lbest > 0) or 
    		(parameters.gbest and parameters.dynamic) or
    		(parameters.lbest > 0 and parameters.dynamic))
    	{
    		std::cerr << "Only one topology parameter can be set!" << std::endl;
    		exit(1);
    	}
        if(parameters.lbest >= parameters.population / 2)
        {
            std::cerr << "Lbest parameter can be max half of population size!"<< std::endl;
            exit(1);
        }
    	if(parameters.lbest == 0 and not parameters.dynamic)
    		parameters.gbest = true;

  	return parameters; 
}
