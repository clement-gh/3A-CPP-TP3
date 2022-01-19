#pragma once
#include "view.h"
#include "controller.h";

class ViewOrder : public View
{
private:
	// application controller
	Controller& controller;
public:
	/**
	 * Constructor
	 */
	ViewOrder(Controller& _controller);

	/**
	 * Notification function of the view
	 */
	virtual void notify();

	/**
	 * Displays the view
	 */
	virtual void display();
};

