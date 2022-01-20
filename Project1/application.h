#pragma once
#include "controller.h"
#include "viewmenu.h"
#include "view-client.h"
#include "view-order.h"
#include"view-store.h"
#include "view4.h"

class Application
{
private:
	Controller* controller;
	ViewMenu* viewMenu;
	ViewClient* viewClient;
	ViewOrder* viewOrder;
	ViewStore* viewStore;
	View4* view4;
	
public:
	/**
	 * Constructor
	 */
	Application();

	/**
	 * Runs the application
	 */
	void run();
};

