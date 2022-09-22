#include <chrono>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "key.h"

using namespace std;

struct myhash {
    size_t operator()(Key const& k) const {
        size_t result = 5381;
        for (int i = 0; i < C; i++) {
            result = ((result << 5) + result) + k.digit[i];
        }
        return result;
    }
};

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage:" << endl;
        cout << argv[0] << " <hashed password> < rand8.txt" << endl;
        return 1;
    }

    // Hashed password.
    Key hashed{argv[1]};

    // Table.
    Key table[N];

    // Read table.
    for (int i{0}; i < N; i++) {
        string buffer;
        if (!(cin >> buffer)) {
            cerr << "Too short table!" << endl;
            return 1;
        }
        table[i] = Key{buffer.c_str()};
    }

    auto begin = chrono::high_resolution_clock::now();

    // Find all possible passwords that hash to 'hashed' and print them.
    unordered_map<Key, vector<Key>, myhash> encrypted_table;
    Key firstHalfCandidate{};
    Key secondHalfCandidate{};
    Key zero{};

    // Loops through all possible combinations of the first half of the table.
    do {
        Key enc = subset_sum(firstHalfCandidate, table);
        // subset_sum(Pa, T) = H - subset_sum(Pb, T)
        encrypted_table[enc].push_back(firstHalfCandidate);
        ++firstHalfCandidate;
    } while (!firstHalfCandidate.bit(N / 2 - 1));
    cout << encrypted_table.size() << endl;
    // Try the other half of all possible subsets of the table.
    do {
        Key enc = subset_sum(secondHalfCandidate, table);
        // Find occurence of enc in the map.
        if (encrypted_table.find(hashed - enc) != encrypted_table.end()) {
            for (Key password : encrypted_table[hashed - enc]) {
                // P = Pa + Pb.
                cout << password + secondHalfCandidate << endl;
            }
        }
        secondHalfCandidate += firstHalfCandidate;
    } while (secondHalfCandidate != zero);

    auto end = chrono::high_resolution_clock::now();
    cout << "Decryption took "
         << std::chrono::duration_cast<chrono::seconds>(end - begin).count()
         << " seconds." << endl;

    return 0;
}
