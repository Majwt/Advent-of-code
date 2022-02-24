#include <bits/stdc++.h>
using std::cout; using std::endl;



struct Edge {
	std::string str[4] = { "","","","" };
	int ints[4] = { 0,0,0,0 };
	bool locked = false;
	int id;
	int matched[4] = { 0,0,0,0 };
	int totalmatch = 0;
	Edge(int Id, std::string l, std::string r, std::string u, std::string d) {
		str[3] = l; // Left
		str[1] = r;	// Right
		str[0] = u; // Upp
		str[2] = d; // Down
		id = Id;
		update();
	}
	Edge(int Id) {
		id = Id;
	}
	Edge() {
	}
	bool dup(Edge e) {
		for (int k = 0; k < 3; k++) {

			for (size_t i = 0; i < 4; i++)
			{
				e.rotate(1);
				if (str == e.str) {
					cout << "false" << endl;
					return false;
				}
			}
			e.flip('Y');


		}
		return true;
	}
	void clear() {
		ints[0] = ints[1] = ints[2] = ints[3] = 0;
		str->clear();
		locked = false;
	}
	/**
	 * @brief Rotates the edge clockwise
	 *	1. Rotates the edge clockwise x amounts quarter
	 *	2. Updates the edge's coordinates
	 * @param x in 90 degrees increments upp to 270
	 */

	void rotate(int x) {
		if (locked) return;
		std::string tmp = str[3];
		switch (x) {
		case 0:
			break;
		case 1:
			// rotate right 90
			str[3] = str[2];
			str[2] = str[1];
			str[1] = str[0];
			str[0] = tmp;
			break;
		case 2:
			// rotate Right 180
			std::swap(str[3], str[1]);
			std::swap(str[0], str[2]);
			break;
		case 3:
			// rotate Right 270
			str[3] = str[0];
			str[0] = str[1];
			str[1] = str[2];
			str[2] = tmp;
			break;
		default:
			throw std::runtime_error("Invalid rotation");
			break;
		}

		update();
	}
	void flip(char d) {
		if (locked) return;
		std::reverse(str[0].begin(), str[0].end()); // Upp
		std::reverse(str[2].begin(), str[2].end()); // Down
		std::reverse(str[3].begin(), str[3].end()); // Left
		std::reverse(str[1].begin(), str[1].end());	// Right
		switch (d)
		{
		case 'X':
			std::swap(str[3], str[1]);

			break;
		case 'Y':

			std::swap(str[0], str[2]);
			break;
		default:
			throw std::runtime_error("Invalid direction");
			break;
		}
		update();


	}

	void print() {
		update();
		cout << "id: " << id << endl;
		cout << '\t' << ints[0] << endl;
		cout << ints[3] << "\t\t";
		cout << ints[1] << endl;
		cout << '\t' << ints[2] << endl << endl;

	}
	int Corners(Edge e) {
		for (size_t j = 0; j < 4; j++)
		{
			for (size_t i = 0; i < 8; i++)
			{

				if (e.id != id && ints[j] == e.ints[(j + 2) % 4]) {
					totalmatch++;
					matched[(j + 2) % 4]++;
					break;
				}
				e.rotate(1);
				if (i % 4 == 0) {
					e.flip('X');
				}
			}

		}
		return totalmatch;
	}
	void update() {


		std::string upp = str[0];
		ints[0] = strtoull(upp.c_str(), nullptr, 2);

		std::string right = str[1];
		ints[1] = strtoull(right.c_str(), nullptr, 2);

		std::string down = str[2];
		ints[2] = strtoull(down.c_str(), nullptr, 2);

		std::string left = str[3];
		ints[3] = strtoull(left.c_str(), nullptr, 2);



		// cout << endl;
		// for (auto&& i : ints) {
		// 	cout << i << " ";
		// }
		// cout << endl;
	}
};


std::vector<Edge> Corners(std::vector<Edge>& edges) {
	for (size_t i = 0; i < edges.size(); i++)
	{
		Edge out = edges[i];
		for (size_t j = 0; j < edges.size(); j++)
		{
			Edge in = edges[j];
			for (size_t k = 0; k < 7; k++)
			{
				if (in.id != out.id && out.ints[2] == in.ints[k % 4]) {
					out.totalmatch++;
					in.matched[k % 4]++;
				}
				if (k % 4 == 0) {
					in.flip('X');
				}
			}

		}

	}
	std::vector<Edge> a;
	for (auto&& i : edges)
	{
		cout << i.id << "\t" << i.totalmatch << endl;
		if (i.totalmatch == 2) {
			a.push_back(i);
		}
	}

	return a;
}

bool find(Edge edge, std::vector<Edge> used) {
	for (size_t k = 0; k < used.size(); k++)
	{
		if (edge.id == used.at(k).id) {
			return true;
		}
	}
	return false;
}
bool find(Edge edge, std::vector<std::vector<Edge>> used) {
	for (size_t k = 1; k < used.size() - 1; k++)
	{
		for (size_t i = 1; i < used[k].size() - 1; i++)
		{
			if (edge.id == used.at(k).at(i).id) {
				return true;
			}
		}
	}
	return false;
}
void vecRes(std::vector<std::vector<Edge>>& vec) {
	for (size_t i = 0; i < vec.size(); i++)
	{
		for (size_t j = 0; j < vec.at(j).size(); j++)
		{
			vec[i][j] = Edge(0);
		}

	}

}

void TryEdge(Edge e, int dir, std::vector<Edge>& edges, std::vector<Edge>& used) {
	for (size_t i = 0; i < edges.size(); i++)
	{
		Edge* ed = &edges.at(i);
		if (e.id != ed->id) {
			for (size_t j = 0; j < 7; j++)
			{
				if (e.ints[dir] == ed->ints[(dir + 2) % 4] && find(*ed, used) != true) {
					cout << std::boolalpha << find(*ed, used) << endl;
					used.push_back(*ed);
					cout << e.ints[dir] << " : " << ed->ints[(dir + 2) % 4] << endl;
					for (auto&& o : used)
					{
						cout << o.id << "\t";
					}
					cout << endl;
					TryEdge(*ed, 1, edges, used);
				}
				else {
					ed->rotate(1);
				}
				if (j % 4 == 0) {
					ed->flip('X');
				}
			}
		}
	}
}


void TryEdge(Edge prev, std::vector<Edge>& edges, std::vector<Edge>& lineAbove, int x, int y, int diag = 0) {
	const int size = (int)sqrt(edges.size());
	Edge edge = edges[0];
	bool matchedTop = false;
	if (y == diag && x < size) {
		x++;
		if (x == size) {
			x = diag;
			y++;
		}
	}
	else if (y < size) {
		y++;
		if (y == size) {
			diag++;
			x = y = diag;
		}
	}
	if (y) {
		Edge above = lineAbove[x];
		if (edge.ints[0] == above.ints[2]) {
			matchedTop = true;
		}
	}

}

// if y == diag and x < size:
//         x += 1
//         if x == size:
//             x = diag
//             y += 1
//     elif y < size:
//         y += 1
//         if y == size:
//             diag += 1
//             x = y = diag



int main(int argc, char const* argv[])
{

	std::vector<std::string> v;
	std::vector<int> ids;
	std::vector<std::vector<std::string>> vv;
	std::vector<Edge> edges;
	std::map<int, Edge> tiles;
	// std::vector<std::vector<Edge>> grid;

	int tilesCount = 0;
	// std::ifstream in("../example.txt");
	std::ifstream in("../input.txt");
	// std::ifstream in("../simple.txt");
	if (!in.is_open()) {
		return -1;
	}
	cout << "test" << endl;
	std::string line;
	while (std::getline(in, line)) {
		if (line.back() == ':') {
			tilesCount++;
			ids.push_back(stoi(line.substr(5, line.size() - 1), nullptr, 10));
			// std::cout << line << std::endl;
		}
		else if (!line.empty()) {
			v.push_back(line);
		}
		else {
			vv.push_back(v);
			v.clear();
		}
	}
	// std::cout << "Tiles: " << tilesCount << std::endl;
	for (int k = 0; k < vv.size(); k++) {
		int s = vv[0].size() - 1;
		int n = vv[0].size();
		Edge e(ids[k]);
		for (size_t i = 0; i < vv[k][0].size(); i++)
		{
			n--;
			e.str[0] += (vv[k][0][n] == '.') ? '0' : '1'; // Upp
			e.str[2] += (vv[k][s][n] == '.') ? '0' : '1'; // Down
			e.str[3] += (vv[k][i][0] == '.') ? '0' : '1'; // Left
			e.str[1] += (vv[k][i][s] == '.') ? '0' : '1'; // Right

		}
		e.update();
		edges.push_back(e);
		tiles.insert_or_assign(ids[k], e);
	}
	// for (auto&& i : tiles)
	// {
	// 	i.second.print();
	// }


	std::map<int, int> used;
	std::vector<Edge> test;
	std::vector<Edge> ed;
	for (size_t i = 0; i < edges.size(); i++)
	{
		ed.push_back(edges[i]);
	}
	Edge corner;
	for (auto&& i : edges)
	{
		for (auto&& j : edges)
		{
			int result = i.Corners(j);
			if (j.id != i.id) {
				auto m = tiles[i.id].matched;
				if (m[0] == 0 && m[3] == 0) {
					corner = tiles[i.id];
					// cout << i.id << "\t" << result << '\t';
					// cout << i.matched[3] << endl;
				}
				used[i.id] = result;
			}
		}

	}
	// cout << "loop" << endl;
	// for (auto&& i : used)
	// {
	// 	cout << i.first << "\t" << i.second << endl;
	// }
	// cout << endl;


	// if (edges[i].CornerTopLeft())

	cout << "loop" << endl;
	int n = 2;
	Edge t(0);
	std::vector<Edge> temp;

	// Edge test3 = edges[1];


	// for (size_t i = 0; i < 7; i++)
	// {
	// 	test3.print();
	// 	test3.rotate(1);
	// 	if (i % 4 == 0)
	// 		test3.flip('Y');
	// }
	// test3.print();
	// test.push_back(edges[n]);
	// for (size_t i = 0; i < 8; i++)
	// {
	// 	TryEdge(edges[n], 1, ed, test);
	// 	if (test.size() == 1 && test.size() < 3) {
	// 		edges[n].rotate(1);
	// 	}
	// 	else {
	// 		break;
	// 	}
	// }

	// TryEdge(corner, 1, ed, test);
	std::vector<Edge> tes;
	size_t out = 1;
	Corners(edges);
	for (auto&& i : edges)
	{
		if (i.totalmatch == 2) {
			tes.push_back(i);
			out *= i.id;
			cout << i.id << "\t";
		}
	}
	if (out != 23868687840666197) {

		cout << endl << out << endl;
	}


	// TryEdge(test.back(), ed, test);
	cout << "starting: " << tes[0].id << endl << "printing test" << endl;
	for (auto&& i : tes)
	{
		cout << i.id << " ";
	}
	cout << endl;



	std::cout << "Tiles count: " << tilesCount << std::endl;
	std::vector<Edge> test2;







	return 0;
}
