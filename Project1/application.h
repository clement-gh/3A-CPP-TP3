#pragma once
#include "controller.h"
#include "viewmenu.h"
#include "view-client.h"
#include "view-order.h"
#include"view-store.h"


class Application
{
private:
	Controller* controller;
	ViewMenu* viewMenu;
	ViewClient* viewClient;
	ViewOrder* viewOrder;
	ViewStore* viewStore;
	
	
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

