#include "colormod.h"
#include <ostream>
namespace Color {
	std::ostream& operator<<(std::ostream& os, const Modifier& mod) {
		return os << "\033[0;" << mod.code << "m";
	}
}

