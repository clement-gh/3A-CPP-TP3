#include "application.h"

/**
 * Constructor
 */
Application::Application()
{
	this->controller = new Controller();
	this->viewMenu = new ViewMenu("Magasin", this->controller);
	this->viewClient = new ViewClient(*this->controller);
	this->viewOrder = new ViewOrder(*this->controller);
	this->viewStore = new ViewStore(*this->controller);

}

/**
 * Runs the application
 */
void Application::run()
{
	this->controller->notify();
}
