#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

void rotate(vector<string>& a) {
	int n = a.size();
	vector<string> b(n, string(n, '?'));
	for (int row = 0; row < n; ++row) {
		for (int col = 0; col < n; ++col) {
			b[row][col] = a[col][n - 1 - row];
		}
	}
	a = b;
}
void flip(vector<string>& a) {
	int n = a.size();
	for (int row = 0; row < n; ++row) {
		for (int col = 0; col < n / 2; ++col) {
			swap(a[row][col], a[row][n - 1 - col]);
		}
	}
}

const int S = 10; // TILE SIZE

struct Tile {
	int id;
	vector<string> cells; // cells[S][S]

	// returns false if End Of File
	bool read(ifstream& in) {
		string line;
		while (getline(in, line)) {
			// std::cout << line << endl;
			auto f = line.find(':');
			if (f != line.npos) {
				id = stoi(line.substr(f - 4, 4), nullptr, 10);
			}
			if (line.empty()) {
				return true;
			}
			else {
				cells.push_back(line);
			}

		}
		return true;
		// if (scanf(" Tile %d:", &id) == EOF) {
		// 	return false;
		// }
		// for (int row = 0; row < S; ++row) {
		// 	static char tmp[105];
		// 	scanf("%s", tmp);
		// 	cells.push_back(string(tmp));
		// }
		// return true;
	}
	bool can_below(const Tile& b) const {
		return cells[S - 1] == b.cells[0];
	}
	bool can_right(const Tile& b) const {
		for (int row = 0; row < S; ++row) {
			if (cells[row][S - 1] != b.cells[row][0]) {
				return false;
			}
		}
		return true;
	}
};

vector<Tile> tiles; // all 8*N available tiles
Tile grid[20][20];
int GRID_SIZE = 3;
void printA() {
	int coltrack = 0;
	printf("\033[2J\033[1;1H"); // reset terminal
	puts("");
	fflush(stdout);
	printf("\e[s");
	if (GRID_SIZE > 1) {
		for (size_t row = 0; row < GRID_SIZE * S; row++, coltrack++)
		{
			// for (size_t col = 0; col < S; col++)
			// {
			if (coltrack % GRID_SIZE == GRID_SIZE - 1) {
				printf("\e[%dD", 100000);


				// printf("\e[%d;%df", row * GRID_SIZE, 0);
				// cout << "\e[1D\e[10B";
			}
			for (size_t cellRow = 0; cellRow < 10; cellRow++)
			{

				printf("\e[%dC", 10 * (coltrack % GRID_SIZE));
				printf("%s", tiles[row * 8].cells[cellRow].c_str());
				puts("");
			}
			if (coltrack % GRID_SIZE != GRID_SIZE - 1) {
				printf("\e[10A");
			}
			fflush(stdout);
			// coltrack++;
			// printf("\e[%dA", 11 * row);


		// }

		}

	}
	printf("\e[B");
	sleep(2);
}

void print(pair<int, int> last_cell) {
	printf("\033[2J\033[1;1H"); // reset terminal
	// puts("");
	for (int row = 0; row <= (last_cell.first + 1) * S; ++row) {
		// if (row % S == 0 || row % S == S - 1) {
		// 	continue;
		// }
		printf(" ");
		for (int col = 0; col < GRID_SIZE * S; ++col) {
			if (make_pair(row / S, col / S) > last_cell) {
				continue;
			}
			char cell = grid[row / S][col / S].cells[row % S][col % S];
			// if (min(row % S, col % S) == 0 || max(row % S, col % S) == S - 1) {
			printf("\033[1;%dm", 31 + (grid[row / S][col / S].id) % 7); // start color
			printf("%c", cell);
			printf("\033[0m"); // end color
		// }
		// else {
		// 	printf(" ");
		// }
		}
		puts("");
	}
	puts("");
	fflush(stdout);
	if (GRID_SIZE == 3) {
		usleep(5012); // sample test
	}
	else {
		usleep(5212 * min(2, last_cell.first + 1));
	}
}

void rec(int row, int col, set<int>& visited) {
	static int operations = 0;
	++operations;
	if (row == GRID_SIZE) {
		printf("%d recursive calls\n", operations);
		printf("product = %lld\n", (long long)grid[0][0].id * grid[GRID_SIZE - 1][0].id
		* grid[0][GRID_SIZE - 1].id * grid[GRID_SIZE - 1][GRID_SIZE - 1].id);
		// printA();
		// exit(0);
		return;
	}
	for (const Tile& tile : tiles) {
		if (!visited.count(tile.id)) {
			if (row > 0 && !grid[row - 1][col].can_below(tile)) {
				continue;
			}
			if (col > 0 && !grid[row][col - 1].can_right(tile)) {
				continue;
			}
			grid[row][col] = tile;
			// print(make_pair(row, col));
			visited.insert(tile.id);
			if (col == GRID_SIZE - 1) {
				rec(row + 1, 0, visited);
			}
			else {
				rec(row, col + 1, visited);
			}
			visited.erase(tile.id);
		}
	}
}
int findMon(vector<string>& comGrid, vector<pair<int, int>> ops, int x, int y) {
	for (auto&& i : ops)
	{
		if (comGrid[i.first + y][i.second + x] != '#') {
			return 0;
		}
	}
	cout << "found" << endl;
	for (auto&& i : ops)
	{
		comGrid[i.first + y][i.second + x] = 'O';
	}
	return 15;

}
int main() {
	// ifstream input("../input.txt");
	ifstream input("example.txt");
	if (!input.is_open()) {
		return -1;
	}
	string line;
	vector<int> ids;
	vector<vector<string>> liness;
	vector<string> lines;

	while (getline(input, line)) {
		if (line[3] == 'e') {
			// std::cout << line.substr(5, 4) << endl;
			ids.push_back(stoi(line.substr(5, 4), nullptr, 10));
		}
		else if (line.empty()) {
			liness.push_back(lines);
			lines.clear();
		}
		else {
			lines.push_back(line);
			// std::cout << line << endl;
		}
	}
	int i = 0;
	// std::cout << lines.size() << endl;
	do
	{
		Tile tile;
		tile.id = ids[i];
		tile.cells = liness[i];
		// if (!tile.read(input)) { // EOF
		// 	break;
		// }
		for (int f = 0; f < 2; ++f) {
			for (int r = 0; r < 4; ++r) {
				tiles.push_back(tile);
				// std::cout << tile.id << endl;
				rotate(tile.cells);
			}
			flip(tile.cells);
		}

	} while (++i < liness.size());


	GRID_SIZE = llround(sqrt(tiles.size() / 8));
	set<int> visited;
	printf("\e[7l");
	rec(0, 0, visited);



	std::vector<string> fullgrid;
	std::vector<vector<string>> fullgrids;
	string l = "";
	string l2 = "";

	for (size_t outrow = 0; outrow < GRID_SIZE; outrow++)
	{
		/* code */

		for (size_t cellrow = 1; cellrow < S - 1; cellrow++)
		{

			for (size_t outcol = 0; outcol < GRID_SIZE; outcol++)
			{
				l += grid[outrow][outcol].cells[cellrow].substr(1, S - 2);
				l2 += grid[outrow][outcol].cells[cellrow].substr(1, S - 2);
			}
			fullgrid.push_back(l);
			l.clear();
			l2 += "\n";

		}
	}
	for (int f = 0; f < 2; ++f) {
		for (int r = 0; r < 4; ++r) {
			fullgrids.push_back(fullgrid);
			// std::cout << tile.id << endl;
			rotate(fullgrid);
		}
		flip(fullgrid);
	}

	const int first = 5;
	const int second = first + 4 + 1; // 4 + 4 + 1
	const int third = second + 4 + 1; // 4 + 4 + 1 + 4 + 1
	int y = 0;
	int x = 0;
	int Xmax = (4 + 1) + (4 + 1) + (4 + 2);
	int Ymax = 2;
	vector<pair<int, int>> monPos;
	monPos.push_back(pair(1, 0));
	monPos.push_back(pair(1, first));
	monPos.push_back(pair(1, first + 1));
	monPos.push_back(pair(1, second));
	monPos.push_back(pair(1, second + 1));
	monPos.push_back(pair(1, third));
	monPos.push_back(pair(1, third + 1));
	monPos.push_back(pair(1, third + 2));
	monPos.push_back(pair(2, 1));
	monPos.push_back(pair(2, 1 + 2 + 1));
	monPos.push_back(pair(2, 1 + 4 + 1));
	monPos.push_back(pair(2, 1 + 6 + 1));
	monPos.push_back(pair(2, 1 + 8 + 1));
	monPos.push_back(pair(2, 1 + 10 + 1));
	monPos.push_back(pair(0, third + 1));

	size_t hashes = 0;
	size_t redacted = 0;
	for (size_t i = 0; i < fullgrid.size(); i++)
	{
		for (size_t j = 0; j < fullgrid[i].size(); j++)
		{
			if (fullgrid[i][j] == '#') {
				hashes++;
			}
		}

	}
	int chosen = 0;
	for (size_t i = 0; i < fullgrids.size(); i++)
	{

		for (size_t row = 0; row < GRID_SIZE; row++)
		{
			for (size_t col = 0; col < GRID_SIZE; col++)
			{

				if (row + Ymax < GRID_SIZE && col + Xmax < GRID_SIZE) {
					redacted += findMon(fullgrids[i], monPos, col, row);
				}
			}

		}
		if (redacted != 0) {
			chosen = i;
			cout << "tes" << endl;
			break;
		}
		else {
			redacted = 0;
		}
		cout << i << endl;
	}
	// cout << endl;
	// printA();
	// cout << endl;
	chosen = 7;

	for (size_t i = 0; i < fullgrids[chosen].size(); i++)
	{
		cout << fullgrids[chosen][i] << endl;

	}
	cout << hashes - redacted << endl;


	/**
	 *                   #
	   #    ##    ##    ###
		#  #  #  #  #  #
	 *
	 */
	 // cout << tiles.size();
	 // cout << "          ";
	 // for (size_t i = 0; i < 15; i++)
	 // {

	 // 	cout << "\e[A";
	 // }
	 // cout << "hfjek";
	 // for (size_t i = 0; i < 10; i++)
	 // {
	 // 	cout << endl;
	 // }
	 // printf("\033[2J\033[1;1H");
	 // cout << GRID_SIZE << endl;
	 // printA();
}