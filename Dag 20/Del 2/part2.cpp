#include <bits/stdc++.h>
#include <unistd.h>
// #include "../colormod.h"


namespace Color {
	enum Code {
		BG_RED = 41,
		BG_GREEN = 42,
		BG_BLUE = 44,
		BG_DEFAULT = 49,
		FG_DEFAULT = 39,
		FG_BLACK = 30,
		FG_RED = 31,
		FG_GREEN = 32,
		FG_YELLOW = 33,
		FG_BLUE = 34,
		FG_MAGENTA = 35,
		FG_CYAN = 36,
		FG_LIGHT_GRAY = 37,
		FG_DARK_GRAY = 90,
		FG_LIGHT_RED = 91,
		FG_LIGHT_GREEN = 92,
		FG_LIGHT_YELLOW = 93,
		FG_LIGHT_BLUE = 94,
		FG_LIGHT_MAGENTA = 95,
		FG_LIGHT_CYAN = 96
	};
	class Modifier {
		Code code;
	public:
		Modifier(Code pCode) : code(pCode) {}
		friend std::ostream&
			operator<<(std::ostream& os, const Modifier& mod) {
			return os << "\033[1;" << mod.code << "m";
		}
	};
}

using std::cout; using std::endl;

void rotate(std::vector<std::string>& a) {
	int n = a.size();
	std::vector<std::string> b(n, std::string(n, '?'));
	for (int row = 0; row < n; ++row) {
		for (int col = 0; col < n; ++col) {
			b[row][col] = a[col][n - 1 - row];
		}
	}
	a = b;
}
void flip(std::vector<std::string>& a) {
	int n = a.size();
	for (int row = 0; row < n; ++row) {
		for (int col = 0; col < n / 2; ++col) {
			std::swap(a[row][col], a[row][n - 1 - col]);
		}
	}
}
const int S = 10;
struct Edge {
	std::vector<std::string> cells;
	std::vector<std::string> str;
	bool locked = false;
	int id;
	int matched[4] = { 0,0,0,0 };
	int totalmatch = 0;
	Edge(int Id, std::string l, std::string r, std::string u, std::string d) {
		str.push_back(u); // Upp
		str.push_back(r);	// Right
		str.push_back(l); // Left
		str.push_back(d); // Down
		id = Id;
	}
	Edge(int Id) {
		id = Id;
		str.push_back("");
		str.push_back("");
		str.push_back("");
		str.push_back("");
	}
	Edge() {
	}
	Edge(int Id, std::vector<std::string> c) {
		id = Id;
		cells = c;
	}
	bool can_below(const Edge& b) const {
		return cells[S - 1] == b.cells[0];
	}
	bool can_right(const Edge& b) const {
		for (int row = 0; row < S; ++row) {
			if (cells[row][S - 1] != b.cells[row][0]) {
				return false;
			}
		}
		return true;
	}
	void print() {
		cout << id << endl;
		for (auto&& i : cells)
		{
			for (auto&& j : i)
			{
				cout << j << " ";
			}
			cout << endl;
		}

	}

	// void clear() {
	// 	str[0] = str[1] = str[2] = str[3] = "";
	// 	locked = false;
	// }

	/**
	 * @brief Rotates the edge clockwise
	 *	1. Rotates the edge clockwise x amounts quarter
	 *	2. Updates the edge's coordinates
	 * @param x in 90 degrees increments upp to 270
	 */

	 // void rotate(int x) {
	 // 	if (locked) return;
	 // 	std::string tmp = str[3];
	 // 	switch (x) {
	 // 	case 0:
	 // 		break;
	 // 	case 1:
	 // 		// rotate right 90
	 // 		str[3] = str[2];
	 // 		str[2] = str[1];
	 // 		str[1] = str[0];
	 // 		str[0] = tmp;
	 // 		break;
	 // 	case 2:
	 // 		// rotate Right 180
	 // 		std::swap(str[3], str[1]);
	 // 		std::swap(str[0], str[2]);
	 // 		break;
	 // 	case 3:
	 // 		// rotate Right 270
	 // 		str[3] = str[0];
	 // 		str[0] = str[1];
	 // 		str[1] = str[2];
	 // 		str[2] = tmp;
	 // 		break;
	 // 	default:
	 // 		throw std::runtime_error("Invalid rotation");
	 // 		break;
	 // 	}
	 // }

	 // void flip(char d) {
	 // 	if (locked) return;
	 // 	std::reverse(str[0].begin(), str[0].end()); // Upp
	 // 	std::reverse(str[2].begin(), str[2].end()); // Down
	 // 	std::reverse(str[3].begin(), str[3].end()); // Left
	 // 	std::reverse(str[1].begin(), str[1].end());	// Right
	 // 	switch (d)
	 // 	{
	 // 	case 'X':
	 // 		std::swap(str[3], str[1]);
	 // 		break;
	 // 	case 'Y':
	 // 		std::swap(str[0], str[2]);
	 // 		break;
	 // 	default:
	 // 		throw std::runtime_error("Invalid direction");
	 // 		break;
	 // 	}
	 // }




};


// std::vector<Edge> Corners(std::vector<Edge>& edges) {
// 	for (size_t i = 0; i < edges.size(); i++)
// 	{
// 		for (size_t j = 0; j < edges.size(); j++)
// 		{
// 			for (size_t k = 0; k < 8; k++)
// 			{
// 				for (size_t p = 0; p < 4; p++)
// 				{
// 					if (edges[j].id != edges[i].id && edges[i].ints[p] == edges[j].ints[k % 4]) {
// 						edges[i].totalmatch++;
// 						edges[i].matched[p]++;
// 						cout << "hit id: " << edges[i].id << " with " << edges[j].id << endl;
// 					}
// 				}
// 				if (k % 4 == 0) {
// 					edges[j].flip('X');
// 				}
// 			}
// 		}
// 	}
// 	std::vector<Edge> a;
// 	for (auto&& i : edges)
// 	{
// 		cout << i.id << "\t" << i.totalmatch << endl;
// 		if (i.totalmatch == 2) {
// 			a.push_back(i);
// 		}
// 	}
// 	return a;
// }

bool find(Edge edge, std::vector<Edge> used) {
	for (size_t k = 0; k < used.size(); k++)
	{
		if (edge.id == used.at(k).id) {
			return true;
		}
	}
	return false;
}



std::vector<Edge> parse(std::ifstream& in)
{
	std::vector<std::string> v;
	std::vector<std::vector<std::string>> vv;
	std::vector<int> ids;
	std::vector<Edge> edges;
	int tilesCount = 0;
	std::string line;
	while (std::getline(in, line)) {
		if (line.back() == ':') {
			tilesCount++;
			ids.push_back(stoi(line.substr(5, line.size() - 1), nullptr, 10));
		}
		else if (!line.empty()) {
			v.push_back(line);

		}
		else {
			vv.push_back(v);
			v.clear();
		}
	}
	for (int k = 0; k < vv.size(); k++) {
		for (size_t i = 0; i < 2; i++)
		{

			for (size_t j = 0; j < 4; j++)
			{

				Edge e(ids[k], vv[k]);
				// e.print();
				edges.push_back(e);
				rotate(vv[k]);
			}
			flip(vv[k]);
		}

	}
	return edges;

}

std::vector<Edge> edges;
Edge grid[20][20];
int gridSize = -1;
const char reset[] = "\x1B[2J\x1B[1H";

void print(std::pair<int, int> last_cell) {
	// std::printf("\033[2J\033[1;1H"); // reset terminal
	// std::puts("");
	cout << reset << endl;
	for (int row = 0; row <= (last_cell.first + 1) * S; ++row) {
		if (row % S == 0 || row % S == S - 1) {
			continue;
		}
		// std::printf(" ");
		cout << "-";
		for (int col = 0; col < gridSize * S; ++col) {
			if (std::make_pair(row / S, col / S) > last_cell) {
				continue;
			}
			char cell = grid[row / S][col / S].cells[row % S][col % S];
			if (std::min(row % S, col % S) == 0 || std::max(row % S, col % S) == S - 1) {
				// std::printf("\033[1;%dm", 31 + (row / S + col / S) % 7); // start color
				auto red = Color::Modifier(Color::FG_BLUE);
				cout << red << cell;
				// std::printf("%c", cell);
				// std::printf("\033[0m"); // end color
			}
			else {
				// std::printf(" ");
				cout << "-";
			}
		}
		cout << endl;
	}
	cout << endl;
	// std::puts("");

	// if (gridSize == 3) {
	// 	usleep(200123); // sample test
	// }
	// else {
	// 	usleep(12123 * std::min(2, last_cell.first + 1));
	// }
	printf("product = %lld\n", (long long)grid[0][0].id * grid[gridSize - 1][0].id
			* grid[0][gridSize - 1].id * grid[gridSize - 1][gridSize - 1].id);
}

void rec(int row, int col, std::set<int>& visited) {
	if (row == gridSize) {
		exit(1);
		return;
	}
	for (const Edge& edge : edges) {
		if (!visited.count(edge.id)) {
			if (row > 0 && !grid[row - 1][col].can_below(edge)) {
				continue;
			}
			if (row > 0 && !grid[row][col - 1].can_right(edge)) {
				continue;
			}
			grid[row][col] = edge;
			print(std::make_pair(row, col));
			visited.insert(edge.id);
			if (col == gridSize - 1) {
				rec(row + 1, 0, visited);
			}
			else {
				rec(row, col + 1, visited);
			}
			// visited.erase(edge.id);
		}
	}
}


int main(int argc, char const* argv[])
{

	std::ifstream in("../example.txt");
	// std::ifstream in("../input.txt");
	// std::ifstream in("../simple.txt");

	if (!in.is_open()) {
		return -1;
	}
	// std::vector<std::string> v;
	// std::vector<std::vector<std::string>> vv;

	// std::vector<int> ids;
	// int tilesCount = 0;

	// std::string line;
	// while (std::getline(in, line)) {
	// 	if (line.back() == ':') {
	// 		tilesCount++;
	// 		ids.push_back(stoi(line.substr(5, line.size() - 1), nullptr, 10));
	// 	}
	// 	else if (!line.empty()) {
	// 		v.push_back(line);
	// 	}
	// 	else {
	// 		vv.push_back(v);
	// 		v.clear();
	// 	}
	// }
	// for (int k = 0; k < vv.size(); k++) {
	// 	int s = vv[0].size() - 1;
	// 	int n = vv[0].size();
	// 	Edge e(ids[k]), vv[k];

	// 	edges.push_back(e);
	// }
	std::vector<Edge> edges = parse(in);

	edges[0].print();
	gridSize = llround(sqrt(edges.size() / 8));
	size_t out = 1;
	// Corners(edges);

	// std::cout << reset << endl;
	auto red = Color::Modifier(Color::FG_RED);
	cout << red;
	cout << out;
	cout << "\033[0m";
	// std::puts(" ");
	std::set<int> visited;
	rec(0, 0, visited);
	// print(std::make_pair(0, 0));
	return 0;
}
