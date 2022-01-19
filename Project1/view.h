#pragma once

#include "observer.h"
#include <string>

//Generic view
class View: public Observer
{
private:
	//Title of the view
	std::string title;
public:

	/**
	 * Constructor
	 * @param _title: title of the view
	 */
	View(const std::string& _title);

	/**
	 * Clears console
	 */
	void clear() const;

	/**
	 * Displays generic dialog
	 */
	virtual void display() const;
};

