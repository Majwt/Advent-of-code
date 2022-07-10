#include <bits/stdc++.h>
#include "/home/majwt/kod/aoc/Aoc-2021/addons/Addons.hpp"
using namespace wase;

#define InputFile 1
/**
 * @brief w,x,y,z
 *
 */
std::map<std::tuple<int, int, int, int>, bool> hyperCube;
std::map<std::tuple<int, int, int, int>, bool> hyperCopy;
// std::vector<std::vector<std::vector<std::vector<int>>>> hyperCubeVec;

auto makeArray(std::vector<std::string> input) {

    std::vector<std::vector<std::vector<std::vector<int>>>> hyperCubeVec;
    for (int i = 0; i < 10; i++) {
        hyperCubeVec.push_back(std::vector<std::vector<std::vector<int>>>());
        for (int j = 0; j < 10; j++) {
        hyperCubeVec[i].push_back(std::vector<std::vector<int>>());
        for (int k = 0; k < 10; k++) {
            hyperCubeVec[i][j].push_back(std::vector<int>());
            for (int l = 0; l < 10; l++) {
            hyperCubeVec[i][j][k].push_back(0);
            }
        }
        }
    }
    int wMed = hyperCubeVec.size() / 2;
    int zMed = hyperCubeVec[wMed].size() / 2;
    for (int y = 0; y < input.size(); y++)
    {
        for (int x = 0; x < input[y].size(); x++) {
            hyperCubeVec[wMed][zMed][y][x] = input[y][x] - '0';
        }
    }
    
    return hyperCubeVec;
}

template <class T>
int count(const T t,std::vector<int> vec2,std::vector<int> vec3,int i) {

    printf("level: %d\nPosition: ",i);
    for (auto &&j : vec3)
    {
        printf("%d ",j);
    }
    puts("");
    int zeros = 0;
    for (auto &&j : vec2)
    {
        if (j == 0)
        {
            zeros++;
        }
    }
    if (zeros == i) {
        return 0;
    }
    

    return t;
}

template <class T>
int count(const std::vector<T> vec,std::vector<int> vec2,std::vector<int> pos,int i) {
    int count = 0;
    for (int i = -1; i != 2; i++)
    {
        vec2.push_back(i);
        count += count(vec[i+pos.at(i+1)],vec2,pos,i+1);
    }
    
    return count;
}
    

    


bool checkNeighburs ( std::tuple<int, int, int, int> t )
{

    int nearbyActive = 0;
    const bool current = hyperCopy[t];
    
    for (int dw = -1; dw != 2; dw++)
    {
        for (int dx = -1; dx != 2; dx++)
        {
            for (int dy = -1; dy != 2; dy++)
            {
                for (int dz = -1; dz != 2; dz++)
                {
                    // printf("aah\n");
                    if (dw != 0 && dx != 0 && dy != 0 && dz != 0)
                    {
                        
                        int w = std::get<0> ( t ) + dw;
                        int x = std::get<1> ( t ) + dx;
                        int y = std::get<2> ( t ) + dy;
                        int z = std::get<3> ( t ) + dz;

                        if (hyperCopy.contains(std::make_tuple(w,x,y,z))) {
                            nearbyActive += hyperCube[std::make_tuple ( w, x, y, z )];

                        }
                        else {

                            hyperCube[std::make_tuple ( w, x, y, z )] = false;
                        }
                    }
                }

            }

        }
    }
    // printf ( "nearbyActive: %d\n", nearbyActive );
    if (current == true) {
        // printf ( "currently on\tresult %s\n", (nearbyActive == 2 || nearbyActive == 3) ? "turn on" : "turn off" );
        return nearbyActive == 2 || nearbyActive == 3;
    }
    else {
        // printf ( "currently off\tresult %s\n", (nearbyActive == 3) ? "turn on" : "turn off" );
        return nearbyActive == 3;
    }
}







int main ( int argc, char const* argv[] )
{
#if InputFile == 2
    vecStr lines = get_input ( "../input.txt" );
#elif InputFile == 1
    vecStr lines = get_input ( "../example.txt", '\n', true );
#endif

    auto hyperCubeVec = makeArray(lines);
    
    
    
    exit(0);      




    for (size_t y = 0; y < lines.size (); y++)
    {
        for (size_t x = 0; x < lines.at ( y ).size (); x++)
        {

            hyperCube[std::make_tuple ( 0, x, y, 0 )] = (lines.at ( y ).at ( x ) == '#');

        }

    }
        hyperCopy = hyperCube;
    for (int i = 0; i < 6; i++)
    {

        hyperCopy = hyperCube;
        int sum = 0;
        
        for (auto [tup, val] : hyperCopy)
        {

            // printf ( "test %d\n", checkNeighburs ( tup ) );
            hyperCube[tup] = checkNeighburs ( tup );
        }
        printf("i: %d\n", i);
        for (auto [tup, val] : hyperCube)
        {
            // printf("w: %d, x: %d, y: %d, z: %d: %s\n", std::get<0> ( tup ), std::get<1> ( tup ), std::get<2> ( tup ), std::get<3> ( tup ), (val)? "on" : "off");
            sum += val;
        }
        printf("%d\n", sum);

        // printAnswer ( std::to_string ( sum ) );

    }
        hyperCopy = hyperCube;
        int sum = 0;
        // for (auto [tup, val] : hyperCube)
        for (auto [tup, val] : hyperCube)
        {
            // printf("w: %d, x: %d, y: %d, z: %d: %s\n", std::get<0> ( tup ), std::get<1> ( tup ), std::get<2> ( tup ), std::get<3> ( tup ), (val)? "on" : "off");
            sum += val;
        }
        printf("%d\n", sum);
        // {
        //     sum += val;
        // }
    

    
    
    // hyperCopy = hyperCube;

    return 0;
}

