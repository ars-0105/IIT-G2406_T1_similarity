#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <unordered_map>
#include <set>

using namespace std;

string stop_words[] = {"a", "and", "an", "of", "in", "the"};
int num_stop_words = 6;

string to_uppercase(string &s) {
    for (char &c : s) {
        c = toupper(c);
    }
    return s;
}

bool is_stop_word(const string &word) {
    for (int i = 0; i < num_stop_words; ++i) {
        if (word == stop_words[i]) {
            return true;
        }
    }
    return false;
}

vector<string> get_words_from_text(string &text) {
    stringstream ss(text);
    vector<string> words;
    string word;

    while (ss >> word) {
        word.erase(remove_if(word.begin(), word.end(), [](char c) {
            return !isalnum(c);
        }), word.end());

        if (!word.empty()) {
            word = to_uppercase(word);
            words.push_back(word);
        }
    }
    return words;
}

unordered_map<string, int> compute_word_frequencies(const vector<string> &words) {
    unordered_map<string, int> word_count;

    for (const string &word : words) {
        if (!is_stop_word(word)) {
            word_count[word]++;
        }
    }

    return word_count;
}

vector<pair<string, double>> compute_normalized_frequencies(const unordered_map<string, int> &word_count, int total_words) {
    vector<pair<string, double>> normalized_frequencies;

    for (const auto &entry : word_count) {
        double normalized_frequency = static_cast<double>(entry.second) / total_words;
        normalized_frequencies.push_back({entry.first, normalized_frequency});
    }

    return normalized_frequencies;
}

double calculate_similarity(const vector<pair<string, double>> &freq1, const vector<pair<string, double>> &freq2) {
    double similarity = 0.0;

    unordered_map<string, double> freq_map1, freq_map2;

    for (const auto &entry : freq1) {
        freq_map1[entry.first] = entry.second;
    }
    for (const auto &entry : freq2) {
        freq_map2[entry.first] = entry.second;
    }

    for (const auto &entry : freq_map1) {
        if (freq_map2.find(entry.first) != freq_map2.end()) {
            similarity += entry.second * freq_map2[entry.first];
        }
    }

    return similarity;
}

vector<pair<string, double>> process_file(const string &filename) {
    ifstream file(filename);
    string line;
    vector<string> all_words;

    while (getline(file, line)) {
        vector<string> words = get_words_from_text(line);
        all_words.insert(all_words.end(), words.begin(), words.end());
    }

    unordered_map<string, int> word_count = compute_word_frequencies(all_words);

    int total_words = all_words.size();
    return compute_normalized_frequencies(word_count, total_words);
}

int main() {
    int num_books = 64;
    vector<string> filenames(num_books);

    string folder_path = "C:\\Users\\aaditya\\desktop\\book-Txt";

    for (int i = 0; i < num_books; ++i) {
        filenames[i] = folder_path + "\\book" + to_string(i + 1) + ".txt";
    }

    vector<vector<pair<string, double>>> word_frequencies(num_books);
    for (int i = 0; i < num_books; ++i) {
        word_frequencies[i] = process_file(filenames[i]);
    }

    vector<vector<double>> similarity_matrix(num_books, vector<double>(num_books, 0.0));

    for (int i = 0; i < num_books; ++i) {
        for (int j = i + 1; j < num_books; ++j) {
            double similarity = calculate_similarity(word_frequencies[i], word_frequencies[j]);
            similarity_matrix[i][j] = similarity;
            similarity_matrix[j][i] = similarity;
        }
    }

    vector<pair<double, pair<int, int>>> similarities;

    for (int i = 0; i < num_books; ++i) {
        for (int j = i + 1; j < num_books; ++j) {
            similarities.push_back({similarity_matrix[i][j], {i, j}});
        }
    }

    sort(similarities.rbegin(), similarities.rend());

    cout << "Top 10 similar pairs of textbooks:\n";
    for (int i = 0; i < 10; ++i) {
        const auto &pair = similarities[i];
        cout << "Book " << pair.second.first + 1 << " and Book " << pair.second.second + 1 << endl;
    }

    return 0;
}
