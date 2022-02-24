#include <bits/stdc++.h>
using std::cout;
using std::endl;
typedef std::pair<float, float> hexCord;
hexCord operator+(const hexCord& lhs, const hexCord& rhs)
{
	hexCord ou;
	ou.first = lhs.first + rhs.first;
	ou.second = lhs.second + rhs.second;
	return ou;
};
std::ostream& operator<<(std::ostream& out, const hexCord& pa)
{
	out << pa.first << "   \t" << pa.second;
	return out;
}
std::string l;
std::map<hexCord, bool> Hexes;
std::map<hexCord, bool> dupHexes;
std::map<hexCord, bool> dupdupHexes;


// std::string Path = "..//input.txt";
std::string Path = "..//example.txt"; // andra fil vägen

hexCord neighburs[] = {
	hexCord(-1.f, 1.f),
	hexCord(1.f, 1.f),
	hexCord(2.f, 0.f),
	hexCord(1.f, -1.f),
	hexCord(-1.f, -1.f),
	hexCord(-2.0f, 0.f) };


void flip(std::string location);

bool nextTo(hexCord pos)
{
	bool thisHex = Hexes[pos];
	int counter = 0;
	for (size_t i = 0; i < 6; i++)
	{
		auto f = dupdupHexes.find(pos + neighburs[i]);
		if (f != dupdupHexes.end() && dupdupHexes[pos + neighburs[i]] == true)
		{
			counter++;
		}
	}
	cout << thisHex << " " << counter << endl;
	if (thisHex && (counter == 0 || counter > 2))
	{
		cout << "flip to white\n";
		return true;

	}
	else if (!thisHex && counter == 2)
	{
		cout << "flip to black\n";
		return true;
	}
	else
	{
		cout << "stay\n";
		return false;
	}
}
int main()
{
	std::vector<std::vector<char>> printGrid;
	cout << std::boolalpha;
	std::ifstream input{ Path };
	std::string line;
	while (std::getline(input, line))
	{
		cout << line << endl;
		flip(line);
	}
	size_t counter = 0;
	for (auto&& i : Hexes)
	{
		counter += i.second;
	}
	cout << counter << endl;
	cout << Hexes.size() << endl;
	dupHexes = Hexes;
	dupdupHexes = Hexes;
	for (size_t i = 0; i < 1; i++)
	{
		/// Main Loop ///
		int j = 0;
		for (auto&& i : Hexes)
		{
			if (nextTo(i.first))
			{
				// cout << i.first << " = " << i.second << endl;

				dupHexes[i.first] = !i.second;
			}

			cout << ++j << endl;
		}
		Hexes = dupHexes;
		dupdupHexes = dupHexes;
	}

	counter = 0;
	for (auto&& i : dupHexes)
	{

		cout << i.first << " = " << i.second << endl;
		counter += i.second;
	}



	for (auto&& i : Hexes)
	{
		printGrid[i.first.second + 10][i.first.first + 10] = (i.second) ? '#' : '.';
	}
	printGrid[10][10] = 'O';

	for (size_t y = 0; y < 20; y++)
	{
		if (y % 2 == 1)
		{
			cout << "  ";
		}
		for (auto&& x : printGrid[y])
		{
			cout << x << "   ";
		}
		cout << endl;
	}

	cout << counter << endl;
}



void flip(std::string location)
{
	float x, y = 0;
	std::string::iterator it;
	int i = 0;
	for (it = location.begin(); it != location.end(); it++, i++)
	{

		if (*it == 'n' || *it == 's')
		{
			if (*it == 'n')
			{
				y += 1.0f;
			}
			else
			{
				y -= 1.f;
			}
			it++;
			switch (*it)
			{
			case 'e':
				x += 1.f;

				break;

			case 'w':
				x -= 1.f;
				break;
			default:
				cout << "default" << endl;
				break;
			}
		}
		else if (*it == 'e')
		{
			x += 2.f;
		}
		else if (*it == 'w')
		{
			x -= 2.f;
		}
	}

	Hexes[hexCord(x, y)] = (Hexes[hexCord(x, y)] == true) ? false : true;
}
