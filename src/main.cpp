#include "chain_o_r/interface_cook.h"
#include "chain_o_r/crust_cook.h"
#include "chain_o_r/fill_cook.h"
#include "chain_o_r/whipped_cream_cook.h"


#include "cake/cake_delivery.h"


#include "iterators/interface_cake_iterator.h"
#include "iterators/cake_chocolate_iterator.h"
#include "iterators/cake_strawberry_vanilla_iterator.h"
#include "iterators/cake_iterator.h"


#include "helpers/nutrition_meter.h"
#include "adapter/cake_adapter.h"


#include "cake/slice.h"



#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

 int main() {
	 
	 
    srand(time(NULL));
	
	
	
    interface_cook* chief = new crust_cook(100.0);
    chief->addCook(new fill_cook(40.0));
    chief->addCook(new whipped_cream_cook(120.0));
	
	
	
    cake_delivery client_cake_delivery(2, 50000, chief);
	
	
	
    interface_cake_iterator *it = client_cake_delivery.getIterator();
	
    for (; it->hasNext(); ) {
		
		std::cout << " --------------------------------- \n";
		std::cout << " 			NEW CAKE				 \n";
		std::cout << " --------------------------------- \n";
		
        cake* client_cake = it->next();
		
        sequence *adapted_cake = new cake_adapter(client_cake);
		
        std::cout << *client_cake << std::endl;
        std::cout << "Cake's nutrition: " << nutrition_meter::calc(adapted_cake) << std::endl << std::endl;
		
		
        slice client_slice = client_cake->getSlice(0.2);
        std::cout << client_slice << std::endl;
		
		
        std::cout << *client_cake << std::endl;
        std::cout << "Cake's nutrition: " << nutrition_meter::calc(adapted_cake) << std::endl << std::endl;
		
		
		
        slice client_slice_1 = client_cake->getSlice(0.5);
        std::cout << client_slice_1 << std::endl;
		
		
        std::cout << *client_cake << std::endl;
        std::cout << "Cake's nutrition: " << nutrition_meter::calc(adapted_cake) << std::endl << std::endl;
		
		
        delete adapted_cake;
		
		
    }
	
    delete it;



	return 0;
 }
