#ifndef SETTINGS__H
#define SETTINGS__H

#define COLOR_STYLE(color) "\033["color "m"
#define RESET_COLOR COLOR_STYLE("0")
#define ERROR_COLOR COLOR_STYLE("31")
#define SUCCESS_COLOR COLOR_STYLE("32")


#define ERROR_IF(function, message) \
	if (function) { \
		std::cout << ERROR_COLOR message RESET_COLOR; \
		return 1; \
	} \

#endif // !SETTINGS__H
