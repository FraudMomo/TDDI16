#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using std::cout;
using std::endl;
using std::map;
using std::queue;
using std::string;
using std::unordered_set;
using std::vector;

// Typ som används för ordlistan. Den definieras med en typedef här så att du
// enkelt kan ändra representationen av en ordlista utefter vad din
// implementation behöver. Funktionen "read_questions" skickar ordlistan till
// "find_shortest" och "find_longest" med hjälp av denna typen.
typedef unordered_set<string> Dictionary;

vector<string> find_neighbors(const Dictionary &dict, const string &from) {
    vector<string> neighbors;
    for (int i = 0; i < from.size(); ++i) {
        for (char c = 'a'; c <= 'z'; ++c) {
            string generated_string = from;
            generated_string[i] = c;
            if (dict.find(generated_string) != dict.end())
                neighbors.push_back(generated_string);
        }
    }
    return neighbors;
}

/**
 * Hitta den kortaste ordkedjan från 'first' till 'second' givet de ord som
 * finns i 'dict'. Returvärdet är den ordkedja som hittats, första elementet ska
 * vara 'from' och sista 'to'. Om ingen ordkedja hittas kan en tom vector
 * returneras.
 */
vector<string> find_shortest(const Dictionary &dict, const string &from,
                             const string &to, const bool find_longest = true) {
    vector<string> result;

    map<string, string> visited;
    queue<string> word_queue;
    word_queue.push(from);
    visited[from] = "";

    string current_word = from;

    while ((!find_longest || current_word != to) && !word_queue.empty()) {
        current_word = word_queue.front();
        word_queue.pop();
        vector<string> neighbors = find_neighbors(dict, current_word);
        for (auto current_neighbor : neighbors) {
            if (visited.find(current_neighbor) == visited.end()) {
                word_queue.push(current_neighbor);
                visited[current_neighbor] = current_word;
            }
        }
    }

    if (!find_longest || current_word == to) {
        while (current_word != "") {
            result.push_back(current_word);
            current_word = visited[current_word];
        }
    }

    return result;
}

/**
 * Hitta den längsta kortaste ordkedjan som slutar i 'word' i ordlistan 'dict'.
 * Returvärdet är den ordkedja som hittats. Det sista elementet ska vara 'word'.
 */
vector<string> find_longest(const Dictionary &dict, const string &word) {
    return find_shortest(dict, word, "", false);
}

/**
 * Läs in ordlistan och returnera den som en vector av orden. Funktionen läser
 * även bort raden med
 * #-tecknet så att resterande kod inte behöver hantera det.
 */
Dictionary read_dictionary() {
    string line;
    vector<string> result;
    while (std::getline(std::cin, line)) {
        if (line == "#") break;

        result.push_back(line);
    }

    return Dictionary(result.begin(), result.end());
}

/**
 * Skriv ut en ordkedja på en rad.
 */
void print_chain(const vector<string> &chain) {
    if (chain.empty()) return;

    vector<string>::const_iterator i = chain.begin();
    cout << *i;

    for (++i; i != chain.end(); ++i) cout << " -> " << *i;

    cout << endl;
}

/**
 * Skriv ut ": X ord" och sedan en ordkedja om det behövs. Om ordkedjan är tom,
 * skriv "ingen lösning".
 */
void print_answer(const vector<string> &chain) {
    if (chain.empty()) {
        cout << "ingen lösning" << endl;
    } else {
        cout << chain.size() << " ord" << endl;
        print_chain(chain);
    }
}

/**
 * Läs in alla frågor. Anropar funktionerna "find_shortest" eller "find_longest"
 * ovan när en fråga hittas.
 */
void read_questions(const Dictionary &dict) {
    string line;
    while (std::getline(std::cin, line)) {
        size_t space = line.find(' ');
        if (space != string::npos) {
            string first = line.substr(0, space);
            string second = line.substr(space + 1);
            vector<string> chain = find_shortest(dict, first, second);

            cout << first << " " << second << ": ";
            print_answer(chain);
        } else {
            vector<string> chain = find_longest(dict, line);

            cout << line << ": ";
            print_answer(chain);
        }
    }
}

int main() {
    Dictionary dict = read_dictionary();
    read_questions(dict);

    return 0;
}
