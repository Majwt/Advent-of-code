#include <bits/stdc++.h>
using std::cout; using std::endl;

std::string l;
std::string Path = "..//input.txt";
// std::string Path = "..//example.txt"; // andra fil vägen
int main()
{

	std::ifstream input;
	input.open(Path);
	if (!input.is_open())
	{
		cout << "not found or could not open\n";
		return 1;
	}

	while (getline(input, l))
	{
		cout << l << '\n';

	}
}