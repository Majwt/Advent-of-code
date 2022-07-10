#include <bits/stdc++.h>
#include "/home/majwt/kod/aoc/Aoc-2021/addons/Addons.hpp"
using namespace wase;

#define InputFile 1
#define Dim 3

vecStr get_lines ()
{
    vecStr lines = get_input ( "../example.txt", '\n', true );
#if InputFile == 2
    lines = get_input ( "../input.txt" );
#endif
    return lines;
}
std::map<int, char> level = {
    {1,'W'},
    {0,'Z'}

};
int check ( int obj, std::vector<int> pos, std::vector<int> diff, int depth )
{
    // printf("here?\n");
    int zeros = 0;
    for (auto&& i : diff)
    {
        if (i == 0)
            zeros++;
    }
    if (zeros == diff.size () && diff.size () == pos.size ()) {
        // printf ( "all zeros\n" );
        return 0;
    }
    else {
        // for (size_t i = 0; i < pos.size(); i++)
        // {
        //     printf("%d ", pos.at(i)+diff.at(i));
        // }

        // puts("");
        return obj;
    }
}

template<class T>
int check ( std::vector<T> obj, std::vector<int> pos, std::vector<int> diff, int depth )
{
    int count = 0;


    for (int d = -1; d != 2; d++)
    {
        if (pos.at ( depth ) + d > 0 && pos.at ( depth ) + d < obj.size ()) {
            diff.push_back ( d );

            count += check ( obj.at ( pos.at ( depth ) + d ), pos, diff, depth + 1 );
            diff.pop_back ();
            if (count > 4)
                return count;
        }
    }

    return count;

}
template<int D, typename T>
struct Vec : public std::vector<Vec<D - 1, T>>
{
    static_assert(D >= 1, "Vector dimension must be greater than zero!");
    template<typename... Args>
    Vec ( int n = 0, Args... args ) : std::vector<Vec<D - 1, T>> ( n, Vec<D - 1, T> ( args... ) )
    {
    }
};
template<typename T>
struct Vec<1, T> : public std::vector<T>
{
    Vec ( int n = 0, const T& val = T () ) : std::vector<T> ( n, val )
    {
    }
};



int print ( const std::vector<std::vector<int>> plane, int index )
{
    int active = 0;
    for (auto i : plane)
    {
        for (auto j : i)
        {
            printf ( "%c ", j ? '#' : '.' );
            active += j;
        }
        puts ( "" );

    }
    puts ( "" );
    return active;
}
int print ( const Vec<2, int> plane, int index )
{
    int active = 0;
    for (auto i : plane)
    {
        for (auto j : i)
        {
            printf ( "%c ", j ? '#' : '.' );
            active += j;
        }
        puts ( "" );

    }
    puts ( "" );
    return active;
}

template<class T>
int print ( const std::vector<T> nVec, int index )
{
    int active = 0;
    // int a = nVec.size () ;
    int a = 0;
    // a = -a;
    for (auto&& i : nVec)
    {
        printf ( "%c = %d\n", level[index], a++ );

        active += print ( i, index - 1 );
    }

    return active;
}

void expand_2d ( Vec<2, int> plane )
{

    for (auto&& i : plane)
    {
        i.insert ( i.begin (), 0 );
        i.push_back ( 0 );
    }
    Vec<1, int> ny ( plane[0].size () );
    plane.insert ( plane.begin (), ny );
    plane.push_back ( ny );
}
template<int D>
void expand ( Vec<D, int>& plane )
{
    printf ( "D = %d\n", D );
        for (Vec<D-1,int> &dim : plane)
        {
            expand<D-1> ( dim );
        }
        Vec<D-1, int> ny ( plane.size () );
        plane.insert(plane.begin(), ny);
        plane.push_back(ny);
    
    // else if (D > 3) {
    //     for (auto&& dimDown : plane)
    //     {
    //         expand<D - 1> ( dimDown );

    //     }
    //     Vec<D - 1, int> ny ( plane[0].size () );

    //     plane.insert ( plane.begin (), ny );
    //     plane.push_back ( ny );

    // }

}


// template<int D>
// void expand(Vec<D,int>& cube) {
//     int two = 2;

//     Vec<D-1,int>ny (cube[0].size(),Vec<two,int>(cube[0].size()));

// }


// void expand ( std::vector<std::vector<int>>& plane )
// {
//     for (auto&& line : plane)
//     {
//         line.insert ( line.begin (), 0 );
//         line.push_back ( 0 );
//     }

//     std::vector<int> newRow ( plane[0].size (), 0 );
//     plane.insert ( plane.begin (), newRow );
//     plane.push_back ( newRow );

// }
// void expand ( std::vector<std::vector<std::vector<int>>>& cube )
// {
//     for (auto&& layer : cube)
//     {
//         expand ( layer );
//     }

//     std::vector<int> newRow ( cube[0].size (), 0 );
//     std::vector<std::vector<int>> newPlane ( cube[0].size (), newRow );


//     cube.insert ( cube.begin (), newPlane );
//     cube.push_back ( newPlane );
//     // if (cube.at(0).size() != cube.at(0).at(0).size())
//     //     printf( "something worng\n");
// }
// void expand ( std::vector<std::vector<std::vector<std::vector<int>>>>& hyperCube )
// {
//     for (auto&& cube : hyperCube) {
//         expand ( cube );
//     }

//     std::vector<int> newRow ( hyperCube[0][0][0].size (), 0 );
//     std::vector<std::vector<int>> newPlane ( hyperCube[0][0].size (), newRow );
//     std::vector<std::vector<std::vector<int>>> newCube ( hyperCube[0].size (), newPlane );

//     hyperCube.insert ( hyperCube.begin (), newCube );
//     hyperCube.push_back ( newCube );


// }

int& get_value ( int& obj, std::vector<int> pos, int index )
{
    return obj;
}

template<class T>
int& get_value ( std::vector<T>& nVec, std::vector<int> pos, int index = 0 )
{
    return get_value ( nVec.at ( pos.at ( index ) ), pos, index + 1 );
}

void update ( int nVec, std::vector<int> pos, auto full, auto& copy, size_t cycle )
{
    const int count = check ( full, pos, {}, 0 );
    if ((count == 3 || count == 2) && cycle == 0) {
        pos[1]--;
    }
    int& changing = get_value ( copy, pos );
    if (nVec == 1) {
        changing = (count == 2 || count == 3) ? 1 : 0;
    }
    else {
        changing = (count == 3) ? 1 : 0;
    }
}
template<class T>
void update ( std::vector<T> nVec, std::vector<int> pos, auto full, auto& copy, size_t cycle )
{
    for (size_t i = 0; i < nVec.size (); i++)
    {
        pos.push_back ( i );
        update ( nVec.at ( i ), pos, full, copy, cycle );
        pos.pop_back ();
    }
}
void test ( std::vector<int> v, int index, int max )
{
    std::vector<std::vector<int>> d ( v.size (), std::vector<int> () );


}
template<class T>
void test ( std::vector<T> v, int index, int max )
{

    auto d = std::vector<std::vector<T>> ( v.size (), std::vector<T> ( v[0].size () ) );
    d.push_back ( v );


}
int main ( int argc, char const* argv[] )
{

    auto input = get_lines ();


    std::vector<std::vector<int>> plane;
    std::vector<std::vector<std::vector<int>>> hyperCube;
    // std::vector<std::vector<std::vector<std::vector<int>>>> hyperCube;
    // (1,std::vector<std::vector<std::vector<int>>>(1,std::vector<std::vector<int>>(1,std::vector<int>())));
    Vec<3, int> a ( 1, 3, 3 );
    for (int i = 0; i < input.size (); i++)
    {
        // a.push_back(Vec<2,int>());
        for (int j = 0; j < input[i].size (); j++)
        {
            get_value ( a, { 0,i,j } ) = input[i][j] == '#';
            // hyperCube[0][0][i].push_back ( input[i][j] == '#' );
        }
    }
    // hyperCube.push_back ( plane );
    // hyperCube.push_back ( cube );
    print ( a, 1 );
    expand<3> ( a );
    print ( a, 1 );
    exit ( 0 );

    print ( hyperCube, 0 );
    // expand ( hyperCube );
    print ( hyperCube, 0 );
    int max = 6;
    for (size_t i = 0; i < max; i++)
    {
        // expand ( hyperCube );
        auto hyper2 = hyperCube;
        progressBar ( i, max + 1 );
        puts ( "" );
        Runtime rt;
        // printf("%ld/6\n",i);
        // expand ( hyper2 );

        update ( hyperCube, {}, hyperCube, hyper2, i );

        // for (int w = 0; w < hyperCube.size (); w++)
        // {
        //     for (int z = 0; z < hyperCube.at ( w ).size (); z++)
        //     {
        //         for (int y = 0; y < hyperCube.at ( w ).at ( z ).size (); y++)
        //         {
        //             for (int x = 0; x < hyperCube.at ( w ).at ( z ).at ( y ).size (); x++)
        //             {
        //                 const int count = check ( hyperCube, { w,z,y,x }, {}, 0 );
        //                 int& changing = hyper2.at ( w ).at ( z ).at ( y ).at ( x );
        //                 if (hyperCube.at ( w ).at ( z ).at ( y ).at ( x ) == 1) {
        //                     changing = (count == 2 || count == 3) ? 1 : 0;
        //                 }
        //                 else {
        //                     changing = (count == 3) ? 1 : 0;
        //                 }
        //             }

        //         }

        //     }

        // }

        hyperCube = hyper2;
        // hyper2.clear();
    }

    // int out = check ( hyperCube, { 1,1,3,1 }, {}, 0 );
    puts ( "" );

    progressBar ( max, max );
    puts ( "" );
    puts ( "" );
    puts ( "" );
    printAnswer ( std::to_string ( print ( hyperCube, 0 ) ) );


    return 0;
}
