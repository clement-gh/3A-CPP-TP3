#pragma once
#include "view.h"
#include "controller.h"

class View4 : public View
{
private:
	// application controller
	Controller& controller;
public:
	/**
	 * Constructor
	 */
	View4(Controller& _controller);

	/**
	 * Notification function of the view
	 */
	virtual void notify();

	/**
	 * Displays the view
	 */
	virtual void display();
};

