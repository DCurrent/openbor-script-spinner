#include "data/scripts/dc_spinner/config.h"

// Which instance is in use?
int dc_spinner_get_instance()
{
	void result = getlocalvar(DC_SPINNER_VAR_KEY_INSTANCE);

	if (!result)
	{
		result = DC_SPINNER_DEFAULT_INSTANCE;
	}

	return result;
}

void dc_spinner_set_instance(int value)
{
	setlocalvar(DC_SPINNER_VAR_KEY_INSTANCE, value);
}