#ifndef DEBUG_HPP
# define DEBUG_HPP

# include <iostream>

# define RESET	"\033[0m"
# define ORANGE	"\033[38;5;208m"
# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"
# define GREY	"\033[90m"

# ifdef DEBUG
#  define DEBUG_LOG(msg, color) \
  std::cout << color << "[DEBUG] " << msg << RESET << std::endl
# else
#  define DEBUG_LOG(msg, color)
# endif

#endif
