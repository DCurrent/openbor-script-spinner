#include "data/scripts/dc_spinner/config.h"
#import "data/scripts/dc_spinner/config.c"

// What to do when incrementing and already at range lower.
void dc_spinner_set_range_bound_lower(int value)
{
	int instance;
	instance = dc_spinner_get_instance();

	setlocalvar(instance + DC_SPINNER_VAR_KEY_RANGE_BOUND_LOWER, value);
}

int dc_spinner_get_range_bound_lower()
{
	int instance;
	instance = dc_spinner_get_instance();

	void result = getlocalvar(instance + DC_SPINNER_VAR_KEY_RANGE_BOUND_LOWER);

	if (!result)
	{
		result = DC_SPINNER_DEFAULT_RANGE_BOUND_LOWER;
	}

	return result;
}

// What to do when incrementing and already at range upper.
void dc_spinner_set_range_bound_upper(int value)
{
	int instance;
	instance = dc_spinner_get_instance();

	setlocalvar(instance + DC_SPINNER_VAR_KEY_RANGE_BOUND_UPPER, value);
}

int dc_spinner_get_range_bound_upper()
{
	int instance;
	instance = dc_spinner_get_instance();

	void result = getlocalvar(instance + DC_SPINNER_VAR_KEY_RANGE_BOUND_UPPER);

	if (!result)
	{
		result = DC_SPINNER_DEFAULT_RANGE_BOUND_UPPER;
	}

	return result;
}

// Current incremented value.
void dc_spinner_set_value(int value)
{
	int instance;
	instance = dc_spinner_get_instance();

	setlocalvar(instance + DC_SPINNER_VAR_KEY_VALUE, value);
}

int dc_spinner_get_value()
{
	int instance;
	instance = dc_spinner_get_instance();

	void result = getlocalvar(instance + DC_SPINNER_VAR_KEY_VALUE);

	if (!result)
	{
		result = DC_SPINNER_DEFAULT_VALUE;
	}

	return result;
}

// Amount to increment.
void dc_spinner_set_increment(int value)
{
	int instance;
	instance = dc_spinner_get_instance();

	setlocalvar(instance + DC_SPINNER_VAR_KEY_INCREMENT, value);
}

int dc_spinner_get_increment()
{
	int instance;
	instance = dc_spinner_get_instance();

	void result = getlocalvar(instance + DC_SPINNER_VAR_KEY_INCREMENT);

	if (!result)
	{
		result = DC_SPINNER_DEFAULT_INCREMENT;
	}

	return result;
}

// Final value we want to reach when incrementing/decrementing.
void dc_spinner_set_range_upper(int value)
{
	int instance;
	instance = dc_spinner_get_instance();

	setlocalvar(instance + DC_SPINNER_VAR_KEY_RANGE_UPPER, value);
}

int dc_spinner_get_range_upper()
{
	int instance;
	instance = dc_spinner_get_instance();

	void result = getlocalvar(instance + DC_SPINNER_VAR_KEY_RANGE_UPPER);

	if (!result)
	{
		result = DC_SPINNER_DEFAULT_RANGE_UPPER;
	}

	return result;
}

// Value we start from before begining to increment toward final
// value.
void dc_spinner_set_range_lower(int value)
{
	int instance;
	instance = dc_spinner_get_instance();

	setlocalvar(instance + DC_SPINNER_VAR_KEY_RANGE_LOWER, value);
}

int dc_spinner_get_range_lower()
{
	int instance;
	instance = dc_spinner_get_instance();

	void result = getlocalvar(instance + DC_SPINNER_VAR_KEY_RANGE_LOWER);

	if (!result)
	{
		result = DC_SPINNER_DEFAULT_RANGE_LOWER;
	}

	return result;
}

// Number of steps want want to take when incrementing between
// original RGB value and final value.
void dc_spinner_set_steps(int value)
{
	int instance;
	instance = dc_spinner_get_instance();

	setlocalvar(instance + DC_SPINNER_VAR_KEY_STEPS, value);
}

int dc_spinner_get_steps()
{
	int instance;
	instance = dc_spinner_get_instance();

	void result = getlocalvar(instance + DC_SPINNER_VAR_KEY_STEPS);

	if (!result)
	{
		result = DC_SPINNER_DEFAULT_STEPS;
	}

	return result;
}

// Caskey, Damon V.
// 2018-11-07
//
// Calculates, stores, and returns the size of an increment 
// from the start point, end point, and number of incremental
// steps we want to take.
int dc_spinner_increment_buid()
{
	int result;
	int start;
	int end;
	int diff;
	int steps;
	
	// Get start and end points.
	start = dc_spinner_get_range_lower();
	end = dc_spinner_get_range_upper();

	// Get the number of increment steps we want.
	steps = dc_spinner_get_steps();

	// What is the difference between start and end?
	diff = end - start;

	// Divide difference between start and end by the
	// number of steps we want to take, and that
	// gets us our increment size.
	result = diff / steps;

	dc_spinner_set_increment(result);

	return result;
}

// Increment the spinner. Stores and returns resulting
// spinner value.
int dc_spinner_increment_run()
{
	void target;
	int current;
	int increment;
	int range_bound;
	int range_lower;
	int range_upper;


	// Get current and increment values.
	current		= dc_spinner_get_value();
	increment	= dc_spinner_get_increment();
	
	// Get our min/max ranges.
	range_lower = dc_spinner_get_range_lower();
	range_upper = dc_spinner_get_range_upper();

	// Apply increment.
	current += increment;

	// Has current gone out of bounds?
	if (current < range_lower)
	{
		// Get set action.
		range_bound = dc_spinner_get_range_bound_lower();

		// Cap the value? Loop back? 
		if (range_bound == DC_SPINNER_RANGE_BOUND_LOOP)
		{
			current = range_upper;
		}
		else if (range_bound == DC_SPINNER_RANGE_BOUND_CAP)
		{
			current = range_lower;
		}
	}
	else if (current > range_upper)
	{
		// Get set action.
		range_bound = dc_spinner_get_range_bound_upper();

		// Cap the value? Loop back? 
		if (range_bound == DC_SPINNER_RANGE_BOUND_LOOP)
		{
			current = range_upper;
		}
		else if (range_bound == DC_SPINNER_RANGE_BOUND_CAP)
		{
			current = range_lower;
		}
	}

	// Store and return the spinner value.
	dc_spinner_set_value(current);
	return current;
}