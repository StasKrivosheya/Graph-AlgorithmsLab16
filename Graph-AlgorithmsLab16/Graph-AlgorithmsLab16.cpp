#include <iostream>
#include "Graph.h"

int main()
{
	Graph gr(100);
	gr.add_adge(0, 1);
	gr.add_adge(0, 2);
	gr.add_adge(0, 8);
	gr.add_adge(1, 2);
	gr.add_adge(1, 4);
	gr.add_adge(2, 0);
	gr.add_adge(2, 3);
	gr.add_adge(3, 5);
	gr.add_adge(3, 4);
	gr.add_adge(3, 7);
	gr.add_adge(4, 6);
	gr.add_adge(4, 7);

	std::cout << "Tried to add \'bad\' vertex. It returned:\t"
			<< gr.add_adge(173, 228) << std::endl;

	std::cout << gr << std::endl;
	
	gr.depth_first_search(2);
	std::cout << std::endl;

	gr.breadth_first_search(2);

	return 0;
}