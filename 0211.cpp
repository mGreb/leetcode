/*
 * 211. Design Add and Search Words Data Structure
 * Design a data structure that supports adding new words and
 * finding if a string matches any previously added string.
 * Implement the WordDictionary class:
 *  WordDictionary() Initializes the object.
 *  void addWord(word) Adds word to the data structure, it can be matched later.
 *  bool search(word) Returns true if there is any string in the data structure
 *  that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
 * */

#include <string>
#include <vector>
#include <set>
#include <map>

class WordDictionary {
private:
    std::map<size_t, std::set<std::string>> dict;
    
    bool compare(const std::string& w1, const std::string& w2) {
        const size_t n = w1.size();
        for (size_t i = 0; i < n; ++i)
            if (w1[i] != '.' && w1[i] != w2[i])
                return false;
        return true;
    }
public:
    WordDictionary() {}

    void addWord(std::string word) {
        dict[word.size()].insert(word);
    }

    bool search(std::string word) {
        const size_t n = word.size();
        if (dict.count(n) != 0) {
            const auto &set = dict[n];
            auto it = set.begin();
            while (it != set.end()) {
                if (compare(word, *it))
                    return true;
                it = std::next(it);
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main() {
    WordDictionary obj;
    obj.addWord("deaf");
    obj.addWord("bad");
    obj.addWord("dad");
    obj.addWord("mad");

    const bool b1 = obj.search("de.f") == true;
    const bool b2 = obj.search("de.c") == false;
    const bool b3 = obj.search("pad") == false;
    const bool b4 = obj.search("bad") == true;
    const bool b5 = obj.search(".ad") == true;
    const bool b6 = obj.search("b..") == true;
    
    return 0;
}
