#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // Split the string s into words
        vector<string> words = splitString(s);
        
        // If the number of pattern characters doesn't match the number of words, return false
        if(pattern.length() != words.size()) {
            return false;
        }
        
        // Hash maps for bijection
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        
        // Iterate through the pattern and words simultaneously
        for(int i = 0; i < pattern.length(); ++i) {
            char c = pattern[i];
            string w = words[i];
            
            // Check forward mapping: character to word
            if(charToWord.find(c) != charToWord.end()) {
                if(charToWord[c] != w) {
                    return false; // Mismatch in mapping
                }
            } else {
                charToWord[c] = w;
            }
            
            // Check reverse mapping: word to character
            if(wordToChar.find(w) != wordToChar.end()) {
                if(wordToChar[w] != c) {
                    return false; // Mismatch in reverse mapping
                }
            } else {
                wordToChar[w] = c;
            }
        }
        
        // All mappings are consistent
        return true;
    }
    
private:
    // Helper function to split a string into words based on spaces
    vector<string> splitString(string s) {
        vector<string> words;
        string word;
        stringstream ss(s);
        
        while(ss >> word) {
            words.push_back(word);
        }
        
        return words;
    }
};

// Example Usage
int main() {
    Solution solution;
    
    // Example 1
    string pattern1 = "abba";
    string s1 = "dog cat cat dog";
    cout << boolalpha << solution.wordPattern(pattern1, s1) << endl; // Output: true
    
    // Example 2
    string pattern2 = "abba";
    string s2 = "dog cat cat fish";
    cout << boolalpha << solution.wordPattern(pattern2, s2) << endl; // Output: false
    
    // Example 3
    string pattern3 = "aaaa";
    string s3 = "dog cat cat dog";
    cout << boolalpha << solution.wordPattern(pattern3, s3) << endl; // Output: false
    
    return 0;
}
