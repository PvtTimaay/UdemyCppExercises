#pragma once

#include <cstddef>

/** START PREV FUNCS **/

bool is_numeric(const char character);

bool is_alpha(const char character);

bool is_alpha_numeric(const char character);

bool is_upper_case(const char character);

bool is_lower_case(const char character);

char to_upper_case(const char character);

char to_lower_case(const char character);

/** END PREV FUNCS **/

char *to_upper_case(char *text);

char *to_lower_case(char *text);

std::size_t string_length(char *text);

bool string_equal(char *string1, char *string2);
