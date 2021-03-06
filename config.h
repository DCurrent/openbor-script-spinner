#ifndef DC_SPINNER_CONFIG
#define DC_SPINNER_CONFIG 1

// Name of library. Used mainly as a base for variable IDs. Must
// be unique vs all other libraries. Try to keep it short.
#define DC_SPINNER_BASE_ID		"dcspin"

#define DC_SPINNER_RANGE_BOUND_CAP				0
#define DC_SPINNER_RANGE_BOUND_LOOP				1

#define DC_SPINNER_DEFAULT_INSTANCE				0
#define DC_SPINNER_DEFAULT_RANGE_BOUND_MIN		DC_SPINNER_RANGE_BOUND_LOOP
#define DC_SPINNER_DEFAULT_RANGE_BOUND_MAX		DC_SPINNER_RANGE_BOUND_LOOP
#define DC_SPINNER_DEFAULT_VALUE				0
#define DC_SPINNER_DEFAULT_INCREMENT			1
#define DC_SPINNER_DEFAULT_RANGE_MIN			0 
#define DC_SPINNER_DEFAULT_RANGE_MAX			100 
#define DC_SPINNER_DEFAULT_STEPS				100

#define DC_SPINNER_MEMBER_INSTANCE			DC_SPINNER_BASE_ID + 0
#define DC_SPINNER_MEMBER_INCREMENT			DC_SPINNER_BASE_ID + 1
#define DC_SPINNER_MEMBER_RANGE_BOUND_MAX	DC_SPINNER_BASE_ID + 2
#define DC_SPINNER_MEMBER_RANGE_BOUND_MIN	DC_SPINNER_BASE_ID + 3
#define DC_SPINNER_MEMBER_RANGE_MAX			DC_SPINNER_BASE_ID + 4
#define DC_SPINNER_MEMBER_RANGE_MIN			DC_SPINNER_BASE_ID + 5	
#define DC_SPINNER_MEMBER_STEPS				DC_SPINNER_BASE_ID + 6
#define DC_SPINNER_MEMBER_VALUE				DC_SPINNER_BASE_ID + 7
#define DC_SPINNER_MEMBER_THE_END			8			// Should always last, with a value one higher than previous key ID.
	

#endif // !DC_SPINNER_CONFIG
