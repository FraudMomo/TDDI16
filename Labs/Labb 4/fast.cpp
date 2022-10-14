/*
 * fast < input.txt
 *
 * Compute and plot all line segments involving 4 points in input.txt
 */

#include <algorithm>
#include <chrono>
#include <iostream>
#include <map>
#include <vector>

#include "point.h"
#include "window.h"

using namespace std;

int main(int argc, const char* argv[]) {
    WindowPtr window = create_window(argc, argv);

    // The array of points
    vector<Point> points;

    // Read points from cin
    int N{};
    cin >> N;

    for (int i{0}; i < N; ++i) {
        unsigned int x, y;
        cin >> x >> y;
        points.push_back(Point{x, y});
    }

    // draw points to screen all at once
    window->draw(points);

    auto begin = chrono::high_resolution_clock::now();

    /////////////////////////////////////////////////////////////////////////////
    // Draw any lines that you find in 'points' using the function
    // 'window->draw'.
    /////////////////////////////////////////////////////////////////////////////

    // Välj en punkt p av alla punkterna i datamängden.
    // Sortera alla andra punkter efter lutningen de har gentemot p.
    for (int i{0}; i < N; ++i) {
        const Point origin{points[i]};
        const PolarSorter ps{points[i]};

        // Possbile points map
        map<double, vector<Point>> possible_points;

        for (int j{0}; j < N; ++j) {
            const double slope{origin.slopeTo(points[j])};
            possible_points[slope].push_back(points[j]);
        }

        // Find all possible points
        for (auto& p : possible_points) {
            if (p.second.size() >= 3) {
                p.second.push_back(points[i]);
                // Sort the points
                sort(p.second.begin(), p.second.end(), ps);

                // Draw line
                window->draw(p.second.front(), p.second.back());
            }
        }
    }

    auto end = chrono::high_resolution_clock::now();
    cout
        << "Computing line segments took "
        << std::chrono::duration_cast<chrono::milliseconds>(end - begin).count()
        << " milliseconds." << endl;

    // wait for user to terminate program
    window->run();

    return 0;
}
