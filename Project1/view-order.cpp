#include "view-order.h"

ViewOrder::ViewOrder(Controller& _controller) : View("Gestion des commandes"), controller(_controller)
{
	this->controller.addObserver(this);
}

void ViewOrder::notify()
{

	if (this->controller.getCurrentScreen() == 3)
		this->display();
}

void ViewOrder::display()
{
}

