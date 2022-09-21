#include <chrono>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "key.h"

using namespace std;

int main(int argc, char *argv[]) {
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
    map<Key, vector<Key>> encrypted_table;
    Key firstHalf{};
    Key firstHalfCandidate{};
    Key secondHalfCandidate{};
    Key zero{};

    /* Skip first key (aaaaa)*/
    firstHalf++;
    for (int i = 0; i <= N / 2; ++i) {
        firstHalf += firstHalf;
    }

    /* Loops through all possible combinations of the first half of the
    table.*/
    do {
        Key enc = subset_sum(firstHalfCandidate, table);
        /* subset_sum(Pa , T ) = H − subset_sum(Pb , T ) */
        encrypted_table[hashed - enc].push_back(firstHalfCandidate);
        firstHalfCandidate++;
    } while (firstHalfCandidate <= firstHalf);

    /* Try the other half of all possible subsets of the table. */
    do {
        Key enc = subset_sum(secondHalfCandidate, table);
        /* Find occurence of enc in the map. */
        if (encrypted_table.find(enc) != encrypted_table.end()) {
            for (Key Pa : encrypted_table[enc]) {
                /* P = Pa + Pb. */
                cout << Pa + secondHalfCandidate << endl;
            }
        }
        secondHalfCandidate += firstHalf;
    } while (secondHalfCandidate != zero);

    auto end = chrono::high_resolution_clock::now();
    cout << "Decryption took "
         << std::chrono::duration_cast<chrono::seconds>(end - begin).count()
         << " seconds." << endl;

    return 0;
}
